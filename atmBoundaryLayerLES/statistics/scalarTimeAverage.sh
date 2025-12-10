#!/bin/sh
#----------------------------------------------------------------------------
#   University    |   Doctoral School in
#       of        |   Environmental and Industrial Fluid Mechanics
#    Trieste      |   (http://phdfluidmechanics.appspot.com/)
#---------------------------------------------------------------------------- 
# Modified version: Python engine + Robust Header/Boundary Handling
# For SCALAR fields (p, T, k, SCLR, etc.)
#----------------------------------------------------------------------------

# -----------------------------------------------------------------------------
# >>>>>>>>>>>>>>>>>>>>>>>>>>>> !!!!! SETTINGS !!!!! <<<<<<<<<<<<<<<<<<<<<<<<<<<
# -----------------------------------------------------------------------------
# Variables for the name of the input/output files
    inputFile='SCLR'
    outputFile=$inputFile'_TimeAverage'
    tempoFine=200 
# Domain discretisation:
     nx=96 
     ny=48 
     nz=96 
# Intervall on which average: 
    timeInterval='*/'
# ---------------------------------------------------------------- end-settings

# Print info
echo ''
echo 'Scalar Time Average - Robust Python Version'
echo '--------------------------------------------------'
echo ''
echo 'INIZIO - '`date`
echo ''
echo 'Lettura dati:     '$inputFile
echo 'Scrittura dati:   '$outputFile
echo 'Tempo fine:       '$tempoFine
echo 'Cartesian grid:   '"$nx x $ny x $nz"
echo ''

# Total points
gridPoints=$(( nx * ny * nz ))

# Creazione cartella di lavoro
mkdir -p $inputFile'_TimeAverage'
cd .. 

echo '1. Trasferimento file in /statistics/'$inputFile'_TimeAverage'
echo '------------------------------------------------'
echo ''

# Controlla tutte le cartelle presenti
n=0
lastValidFile=""

for h in $timeInterval
  do
  if [ -e $h/$inputFile ]; then
    echo 'Trasferimento dati tempo '$h
    ((n++))
    cd $h
    # Copiamo il file intero per Python
    cp $inputFile ../statistics/$inputFile'_TimeAverage'/$inputFile"$n"
    lastValidFile="../statistics/$inputFile'_TimeAverage'/$inputFile$n"
    cd ..
  fi
done

if [ -z "$lastValidFile" ]; then
    echo "Errore: Nessun file trovato!"
    exit 1
fi

# Ritorna nella cartella statistics
cd statistics/$inputFile'_TimeAverage'

echo ''
echo '2. Media nel tempo dei file (Python engine)'
echo '------------------------'
echo ''

# Crea lo script Python
pythonScript=scalarTimeAverage.py

cat > $pythonScript << EOF
import sys
import os

def scalar_time_average(num_files, input_prefix, nx, ny, nz):
    num_files = int(num_files)
    nx, ny, nz = int(nx), int(ny), int(nz)
    total_points = nx * ny * nz
    output_data = "meanQuantities_scalar"
    
    print(f"RUNNING: scalarTimeAverage.py processing {num_files} files for {total_points} points...")
    
    # Init array (1D list for scalars)
    sum_data = [0.0] * total_points
    count_valid_files = 0

    for j in range(1, num_files + 1):
        filename = f"{input_prefix}{j}"
        try:
            values_read = 0
            inside_data_block = False
            
            with open(filename, 'r') as f:
                for line in f:
                    if values_read >= total_points:
                        break
                    
                    line = line.strip()
                    
                    # Logic to find where data starts
                    # Typically inside a parenthesis block
                    if not inside_data_block:
                        if line == '(':
                            inside_data_block = True
                        continue
                    
                    if line == ')':
                        inside_data_block = False
                        break
                    
                    # Parse Scalar
                    try:
                        val = float(line)
                        sum_data[values_read] += val
                        values_read += 1
                    except ValueError:
                        continue
            
            if values_read == total_points:
                count_valid_files += 1
                if j % 5 == 0:
                    print(f"Processed file {filename}")
            else:
                print(f"Warning: File {filename} had {values_read} values (expected {total_points}). Skipped.")

        except FileNotFoundError:
            print(f"Warning: File {filename} not found.")

    if count_valid_files > 0:
        print(f"\nTotal valid time steps: {count_valid_files}")
        print(f"Writing data to {output_data}...")
        
        with open(output_data, 'w') as f_out:
            for val in sum_data:
                avg = val / count_valid_files
                f_out.write(f"{avg:.6g}\n")
        print("Done.")
    else:
        print("No valid files processed!")

if __name__ == "__main__":
    scalar_time_average(sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4], sys.argv[5])
EOF

# Lancia Python
nFine=$n
echo 'Run Programma Python'
if command -v python3 &> /dev/null; then
    python3 $pythonScript $nFine $inputFile $nx $ny $nz
else
    python $pythonScript $nFine $inputFile $nx $ny $nz
fi
wait

echo '3. Creazione file OpenFOAM Finale'
echo '--------------------------'

# Usiamo l'ultimo file validato come template per boundary e dimensioni
templateFile=$inputFile"$n"

# 1. HEADER (Nota: class volScalarField)
echo "/*--------------------------------*- C++ -*----------------------------------*\\" > $outputFile
echo "| =========                 |                                                 |" >> $outputFile
echo "| \\\\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox           |" >> $outputFile
echo "|  \\\\    /   O peration     | Version:  9                                     |" >> $outputFile
echo "|   \\\\  /    A nd           | Website:  www.openfoam.org                      |" >> $outputFile
echo "|    \\\\/     M anipulation  |                                                 |" >> $outputFile
echo "\*---------------------------------------------------------------------------*/" >> $outputFile
echo "FoamFile" >> $outputFile
echo "{" >> $outputFile
echo "    version     2.0;" >> $outputFile
echo "    format      ascii;" >> $outputFile
echo "    class       volScalarField;" >> $outputFile
echo "    location    \"$tempoFine\";" >> $outputFile
echo "    object      $outputFile;" >> $outputFile
echo "}" >> $outputFile
echo "// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //" >> $outputFile
echo "" >> $outputFile

# 2. DIMENSIONI E DATI
grep "dimensions" $templateFile >> $outputFile || echo "dimensions      [0 0 0 0 0 0 0];" >> $outputFile

echo "" >> $outputFile
echo "internalField   nonuniform List<scalar>" >> $outputFile
echo "$gridPoints" >> $outputFile
echo "(" >> $outputFile
cat meanQuantities_scalar >> $outputFile
echo ")" >> $outputFile
echo ";" >> $outputFile

# 3. BOUNDARY FIELD
echo "" >> $outputFile
echo "Coping boundaryField from original file..."
boundLine=$(grep -n "boundaryField" $templateFile | head -n 1 | cut -d: -f1)

if [ ! -z "$boundLine" ]; then
    tail -n +$boundLine $templateFile >> $outputFile
else
    echo "boundaryField { }" >> $outputFile
fi

echo "// ************************************************************************* //" >> $outputFile

# Sposta il file finale
cp $outputFile ../../$tempoFine

# Pulizia
echo ''
echo 'Cancella cartella ausiliaria'
cd ..
rm -r $inputFile'_TimeAverage'

echo ''
echo 'FINE! - '`date`
echo '------------------------------------'
echo ''