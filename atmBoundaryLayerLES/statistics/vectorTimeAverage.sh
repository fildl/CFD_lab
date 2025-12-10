#!/bin/sh
#----------------------------------------------------------------------------
#   University    |   DIFA - Dept of Physics and Astrophysics 
#       of        |   Research group in Atmospheric Physics
#    Bologna      |   (https://physics-astronomy.unibo.it)
#----------------------------------------------------------------------------
# Modified version: Python engine + Robust Header/Boundary Handling
#----------------------------------------------------------------------------

# -----------------------------------------------------------------------------
# >>>>>>>>>>>>>>>>>>>>>>>>>>>> !!!!! SETTINGS !!!!! <<<<<<<<<<<<<<<<<<<<<<<<<<<
# -----------------------------------------------------------------------------
# Variables for the name of the input/output files
    inputFile='U_RS'
    outputFile=$inputFile'Mean_time'
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
    # Copiamo il file intero, il parsing lo farà Python
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
pythonScript=timeAverage.py

cat > $pythonScript << EOF
import sys
import os

def time_average(num_files, input_prefix, nx, ny, nz):
    num_files = int(num_files)
    nx, ny, nz = int(nx), int(ny), int(nz)
    total_points = nx * ny * nz
    output_data = "meanQuantities_time"
    
    print(f"RUNNING: timeAverage.py processing {num_files} files for {total_points} points...")
    
    sum_data = [[0.0, 0.0, 0.0] for _ in range(total_points)]
    count_valid_files = 0

    for j in range(1, num_files + 1):
        filename = f"{input_prefix}{j}"
        try:
            vectors_read = 0
            with open(filename, 'r') as f:
                for line in f:
                    if vectors_read >= total_points:
                        break
                    
                    line = line.strip()
                    # Cerca vettori validi (1.2 3.4 5.6)
                    if not line.startswith('(') or not line.endswith(')'):
                        continue
                    
                    clean_line = line.replace('(', '').replace(')', '')
                    parts = clean_line.split()
                    
                    if len(parts) == 3:
                        try:
                            vals = [float(p) for p in parts]
                            sum_data[vectors_read][0] += vals[0]
                            sum_data[vectors_read][1] += vals[1]
                            sum_data[vectors_read][2] += vals[2]
                            vectors_read += 1
                        except ValueError:
                            continue
            
            if vectors_read == total_points:
                count_valid_files += 1
                if j % 5 == 0:
                    print(f"Processed file {filename}")
            else:
                print(f"Warning: File {filename} had {vectors_read} vectors (expected {total_points}). Skipped.")

        except FileNotFoundError:
            print(f"Warning: File {filename} not found.")

    if count_valid_files > 0:
        print(f"\nTotal valid time steps: {count_valid_files}")
        print(f"Writing data to {output_data}...")
        
        with open(output_data, 'w') as f_out:
            for vec in sum_data:
                avg_x = vec[0] / count_valid_files
                avg_y = vec[1] / count_valid_files
                avg_z = vec[2] / count_valid_files
                f_out.write(f"({avg_x:.6g} {avg_y:.6g} {avg_z:.6g})\n")
        print("Done.")
    else:
        print("No valid files processed!")

if __name__ == "__main__":
    time_average(sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4], sys.argv[5])
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

# Usiamo l'ultimo file validato ($inputFile"$n") come template per boundary e dimensioni
templateFile=$inputFile"$n"

# 1. HEADER
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
echo "    class       volVectorField;" >> $outputFile
echo "    location    \"$tempoFine\";" >> $outputFile
echo "    object      $outputFile;" >> $outputFile
echo "}" >> $outputFile
echo "// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //" >> $outputFile
echo "" >> $outputFile

# 2. DIMENSIONI E DATI
# Copia le dimensioni dal file template
grep "dimensions" $templateFile >> $outputFile || echo "dimensions      [0 1 -1 0 0 0 0];" >> $outputFile

echo "" >> $outputFile
echo "internalField   nonuniform List<vector>" >> $outputFile
echo "$gridPoints" >> $outputFile
echo "(" >> $outputFile
cat meanQuantities_time >> $outputFile
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