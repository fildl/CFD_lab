#!/bin/sh
#----------------------------------------------------------------------------
#   University    |   Doctoral School in
#       of        |   Environmental and Industrial Fluid Mechanics
#    Trieste      |   (http://phdfluidmechanics.appspot.com/)
#---------------------------------------------------------------------------- 
# Modified version: Python engine + Robust Header/Boundary Handling
# For SCALAR Space Average (collapses X-Z planes)
# FIX: Prevents reading the point count as data
#----------------------------------------------------------------------------

# -----------------------------------------------------------------------------
# >>>>>>>>>>>>>>>>>>>>>>>>>>>> !!!!! SETTINGS !!!!! <<<<<<<<<<<<<<<<<<<<<<<<<<<
# -----------------------------------------------------------------------------
# Variables for the name of the input/output files
    inputFile='epsilonMean_time'
    outputFile='epsilonMean'
    tempoFine=200 
# Domain discretisation:
     nx=96 
     ny=48 
     nz=96 
# ---------------------------------------------------------------- end-settings

# Print info
echo ''
echo 'Scalar Space Average - Robust Python Version (Fixed)'
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

# Prepare the environment
cd ..

for h in $tempoFine
  do
  if [ -e $h/$inputFile ]; then
  echo '                                   Processing time data folder '$h
  echo '                                   ----------------------------------'
  echo ''
  cd $h

# - print the Python program
echo 'Creating Python script: scalarSpaceAverage.py'
pythonScript=scalarSpaceAverage.py

cat > $pythonScript << EOF
import sys

def scalar_space_average(nx, ny, nz, input_filename):
    nx, ny, nz = int(nx), int(ny), int(nz)
    output_file = "meanQuantities_scalar_space"
    total_points = nx * ny * nz
    
    print(f"RUNNING: scalarSpaceAverage.py (Grid: {nx}x{ny}x{nz})")
    print(f"Reading from {input_filename}...")

    # Array per accumulare le somme per ogni livello Y
    y_profile = [0.0] * ny
    
    try:
        count_in_x = 0
        current_j = 0 # Indice Y corrente
        values_read = 0
        reading_data = False # FLAG DI SICUREZZA
        
        with open(input_filename, 'r') as f:
            for line in f:
                if values_read >= total_points:
                    break
                
                line = line.strip()
                if not line: continue
                
                # --- LOGICA DI SICUREZZA ---
                # Aspettiamo la parentesi aperta prima di leggere i numeri.
                # Questo evita di leggere "442368" (conteggio punti) come se fosse un dato.
                if not reading_data:
                    if line.startswith('('):
                        reading_data = True
                        # Se la linea è solo "(", continua alla prossima.
                        # Se è "( 0.1 0.2 ...", bisogna parsare il resto (raro nei file scalari standard)
                        if line == '(':
                            continue
                        else:
                            # Rimuove la parentesi iniziale per parsare i numeri sulla stessa riga
                            line = line.replace('(', '')
                    else:
                        # Se non stiamo leggendo i dati e non è '(', è header o conteggio punti -> IGNORA
                        continue
                
                # Se arriviamo qui, reading_data è True
                if line == ')':
                    break
                
                # Tenta di leggere un numero
                try:
                    val = float(line)
                    
                    # Accumula
                    y_profile[current_j] += val
                    
                    values_read += 1
                    
                    # Logica indici (OpenFOAM loop: k(z) -> j(y) -> i(x))
                    count_in_x += 1
                    if count_in_x == nx:
                        # Finita una riga X
                        count_in_x = 0
                        current_j += 1
                        
                        # Se finito blocco Y, resetta J (inizia nuovo Z)
                        if current_j == ny:
                            current_j = 0
                            
                except ValueError:
                    continue
        
        print(f"Values successfully read: {values_read}")
        
        if values_read != total_points:
            print(f"ERROR: Expected {total_points} values, found {values_read}.")
            return

        # Calcolo Media (sommato su X e Z -> divido per nx*nz)
        divisor = nx * nz
        for j in range(ny):
            y_profile[j] /= divisor
            
        print("Writing averaged 3D field...")
        
        with open(output_file, 'w') as f_out:
            # Ricostruzione campo 3D
            for k in range(nz):
                for j in range(ny):
                    val_str = f"{y_profile[j]:.6g}\n"
                    for i in range(nx):
                        f_out.write(val_str)
                        
        print("Done.")

    except FileNotFoundError:
        print(f"Error: {input_filename} not found.")
    except Exception as e:
        print(f"An error occurred: {e}")

if __name__ == "__main__":
    scalar_space_average(sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4])
EOF

# Run Python
echo 'Run Python program'
if command -v python3 &> /dev/null; then
    python3 $pythonScript $nx $ny $nz $inputFile
else
    python $pythonScript $nx $ny $nz $inputFile
fi
wait

# Write the result in a OpenFoam format
# -------------------------------------
echo ''
echo 'Write result'

if [ -s meanQuantities_scalar_space ]; then
    
    # 1. HEADER (class volScalarField)
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
    # Cerca dimensioni nel file originale
    grep "dimensions" $inputFile >> $outputFile || echo "dimensions      [0 0 0 0 0 0 0];" >> $outputFile
    
    echo "" >> $outputFile
    echo "internalField   nonuniform List<scalar>" >> $outputFile
    echo "$gridPoints" >> $outputFile
    echo "(" >> $outputFile
    cat meanQuantities_scalar_space >> $outputFile
    echo ")" >> $outputFile
    echo ";" >> $outputFile
    
    # 3. BOUNDARY FIELD (Copia dall'input originale)
    echo "" >> $outputFile
    echo "Coping boundaryField from original file..."
    boundLine=$(grep -n "boundaryField" $inputFile | head -n 1 | cut -d: -f1)
    
    if [ ! -z "$boundLine" ]; then
        tail -n +$boundLine $inputFile >> $outputFile
    else
        echo "boundaryField { }" >> $outputFile
    fi
    
    echo "// ************************************************************************* //" >> $outputFile
    echo "File $outputFile created successfully."

else
    echo "ERROR: Output from Python is empty."
fi

# - delete auxiliary files
echo 'Delete auxiliary files'
rm $pythonScript meanQuantities_scalar_space

echo '                                   ----------------------------------'
cd ..;
fi
done

echo ''
echo 'END! - '`date`
echo ''