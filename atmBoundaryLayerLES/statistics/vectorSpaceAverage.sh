#!/bin/sh
#----------------------------------------------------------------------------
#   University    |   DIFA - Dept of Physics and Astrophysics 
#       of        |   Research group in Atmospheric Physics
#    Bologna      |   (https://physics-astronomy.unibo.it)
#----------------------------------------------------------------------------
# ROBUST PYTHON VERSION - SKIPS HEADERS AUTOMATICALLY
#----------------------------------------------------------------------------

# -----------------------------------------------------------------------------
# >>>>>>>>>>>>>>>>>>>>>>>>>>>> !!!!! SETTINGS !!!!! <<<<<<<<<<<<<<<<<<<<<<<<<<<
# -----------------------------------------------------------------------------
# Variables for the name of the input/output files
    inputFile='U_RSMean_time'
    outputFile='U_RSMean'
    tempoFine=200 
# Domain discretisation:
     nx=96 
     ny=48 
     nz=96  
# ---------------------------------------------------------------- end-settings

# Print info
echo ''
echo 'Vector Space Average - Robust Python Version'
echo '---------------------------------------------------'
echo ''
echo 'INIZIO - '`date`
echo ''
echo 'Lettura dati:     '$inputFile
echo 'Scrittura dati:   '$outputFile
echo 'Tempo fine:       '$tempoFine
echo 'Cartesian grid:   '"$nx x $ny x $nz"
echo ''

# Number of line containing data: used only for header/footer extraction
# We calculate where data likely ends to grab the footer safely
grid=$(( nx * ny * nz + 23 ))

# Prepare the environment
# -----------------------
cd ..

for h in $tempoFine
  do
  if [ -e $h/$inputFile ]; then
  echo '                                   Processing time data folder '$h
  echo '                                   ----------------------------------'
  echo ''
  cd $h

# - extract the header of OpenFoam's file 
echo 'Header extraction: incipit'
head -22 $inputFile > incipit

# - extract the ending of OpenFoam's file
echo 'Ending extraction: terminus'
# We grab the last few lines safely
tail -n 5 $inputFile > terminus

# - print the Python program
echo 'Creating Python script: spaceAverage.py'
pythonScript=spaceAverage.py

cat > $pythonScript << EOF
import sys

def space_average(nx, ny, nz, input_filename):
    nx, ny, nz = int(nx), int(ny), int(nz)
    output_file = "meanQuantities"
    total_points = nx * ny * nz
    
    print(f"RUNNING: spaceAverage.py (Grid: {nx}x{ny}x{nz})")
    print(f"Looking for {total_points} vectors in {input_filename}...")

    y_profile = [[0.0, 0.0, 0.0] for _ in range(ny)]
    
    try:
        current_j = 0
        count_in_x = 0
        vectors_read = 0
        
        with open(input_filename, 'r') as f:
            for line in f:
                # Stop reading if we found all points (ignores footer)
                if vectors_read >= total_points:
                    break
                
                # Robust parsing: check if line looks like a vector
                # Expected format: (1.23 -4.56 7.89)
                line = line.strip()
                if not line.startswith('(') or not line.endswith(')'):
                    continue
                
                # Clean and split
                clean_line = line.replace('(', '').replace(')', '')
                parts = clean_line.split()
                
                # Check if we have exactly 3 numbers
                if len(parts) != 3:
                    continue
                
                try:
                    vals = [float(p) for p in parts]
                except ValueError:
                    # Line had parenthesis but not numbers? Skip.
                    continue

                # --- IF WE ARE HERE, WE HAVE A VALID VECTOR ---
                
                # Accumulate
                y_profile[current_j][0] += vals[0]
                y_profile[current_j][1] += vals[1]
                y_profile[current_j][2] += vals[2]
                
                vectors_read += 1
                
                # Logic update (x -> y -> z)
                count_in_x += 1
                if count_in_x == nx:
                    count_in_x = 0
                    current_j += 1
                    if current_j == ny:
                        current_j = 0
        
        print(f"Vectors successfully read: {vectors_read}")
        
        if vectors_read != total_points:
            print(f"ERROR: Expected {total_points} vectors, but found {vectors_read}.")
            print("Please check mesh dimensions (nx, ny, nz) or input file integrity.")
            # We create an empty file to avoid partial corrupt data
            open(output_file, 'w').close()
            return

        # Calculate Averages
        divisor = nx * nz
        for j in range(ny):
            y_profile[j][0] /= divisor
            y_profile[j][1] /= divisor
            y_profile[j][2] /= divisor
            
        print("Writing averaged data...")
        
        with open(output_file, 'w') as f_out:
            # Reconstruct 3D field: Loop k(z), j(y), i(x)
            for k in range(nz):
                for j in range(ny):
                    vec_str = f"({y_profile[j][0]:.6g} {y_profile[j][1]:.6g} {y_profile[j][2]:.6g})\n"
                    for i in range(nx):
                        f_out.write(vec_str)
                        
        print("Done.")

    except FileNotFoundError:
        print(f"Error: {input_filename} not found.")
    except Exception as e:
        print(f"An error occurred: {e}")

if __name__ == "__main__":
    # Pass arguments: nx, ny, nz, filename
    space_average(sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4])
EOF

# Run the Python script
# ----------------------------------------------
echo 'Run Python program'
echo ''
# Passiamo direttamente il file originale $inputFile, senza pre-processarlo con sed
if command -v python3 &> /dev/null; then
    python3 $pythonScript $nx $ny $nz $inputFile
else
    python $pythonScript $nx $ny $nz $inputFile
fi
wait

# Write the result in a OpenFoam format and clean from auxiliary files
# --------------------------------------------------------------------
echo ''
echo 'Write result'

# Check if meanQuantities was created and has size
if [ -s meanQuantities ]; then
    
    # 1. SCRITTURA HEADER PULITO
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
    # Cerchiamo le dimensioni nel file originale
    grep "dimensions" incipit >> $outputFile || echo "dimensions      [0 1 -1 0 0 0 0];" >> $outputFile
    
    echo "" >> $outputFile
    echo "internalField   nonuniform List<vector>" >> $outputFile
    echo "$((nx*ny*nz))" >> $outputFile  # Numero punti
    echo "(" >> $outputFile              # Parentesi apertura
    cat meanQuantities >> $outputFile    # Dati Python
    echo ")" >> $outputFile              # Parentesi chiusura
    echo ";" >> $outputFile
    
    # 3. BOUNDARY FIELD (CORREZIONE CRITICA)
    # Invece di scriverli a mano, li estraiamo dal file di input originale.
    # Cerchiamo la riga dove inizia "boundaryField"
    
    echo "" >> $outputFile
    echo "Coping boundaryField from original file..."
    
    # Trova il numero di riga dove inizia la parola "boundaryField"
    boundLine=$(grep -n "boundaryField" $inputFile | head -n 1 | cut -d: -f1)
    
    if [ ! -z "$boundLine" ]; then
        # Copia dal 'boundaryField' fino alla fine del file originale
        tail -n +$boundLine $inputFile >> $outputFile
    else
        # Fallback di emergenza se non trova i boundary (ma fallirà con cyclic)
        echo "boundaryField { }" >> $outputFile
        echo "// ************************************************************************* //" >> $outputFile
    fi

    echo "File $outputFile created successfully with ORIGINAL boundaries."
else
    echo "ERROR: meanQuantities file is empty. Something went wrong in Python."
fi

# - delete auxiliary files
echo 'Delete auxiliary files'
rm $pythonScript incipit terminus meanQuantities

echo '                                   ----------------------------------'
cd ..;
fi
done

echo ''
echo 'END! - '`date`
echo ''