#!/bin/sh
#----------------------------------------------------------------------------
#   University    |   DIFA - Dept of Physics and Astrophysics 
#       of        |   Research group in Atmospheric Physics
#    Bologna      |   (https://physics-astronomy.unibo.it)
#----------------------------------------------------------------------------
# Modified version: Python engine + Robust Header/Boundary Handling
# Replaces Octave dependency
#----------------------------------------------------------------------------

# -----------------------------------------------------------------------------
# >>>>>>>>>>>>>>>>>>>>>>>>>>>> !!!!! SETTINGS !!!!! <<<<<<<<<<<<<<<<<<<<<<<<<<<
# -----------------------------------------------------------------------------
# Variables for the name of the input/output files
    inputFile='U'
    
    # ATTENZIONE: Scegli il file medio corretto (es. 'UMean_time' o 'UMean')
    # Deve esistere nella cartella specificata in 'tempoFine'
    averageFile='UMean'
    
    outputFile=$inputFile'_RS_fluct'
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
echo 'Reynolds Stresses - Robust Python Version'
echo '--------------------------------------------------'
echo ''
echo 'INIZIO - '`date`
echo ''
echo 'Lettura dati (Istantanei): '$inputFile
echo 'Lettura dati (Media):      '$averageFile
echo 'Scrittura dati (RS):       '$outputFile
echo 'Tempo fine (Sorgente Media): '$tempoFine
echo 'Cartesian grid:   '"$nx x $ny x $nz"
echo ''

# Total points calculation
totalPoints=$(( nx * ny * nz ))

# Prepare the environment
cd ..

# Check if the average file exists in the reference folder
if [ ! -f "$tempoFine/$averageFile" ]; then
    echo "ERROR: Average file '$averageFile' not found in folder '$tempoFine'!"
    exit 1
fi

echo "Using average file from: $tempoFine/$averageFile"

for h in $timeInterval
  do
  if [ -e $h/$inputFile ]; then
    echo '                                   Processing time data folder '$h
    echo '                                   ----------------------------------'
    
    # Copia il file medio nella cartella corrente (necessario per lo script Python locale)
    cp $tempoFine/$averageFile $h/averaged_temp_file

    cd $h
    
    # -------------------------------------------------------------------------
    # PYTHON SCRIPT GENERATION
    # -------------------------------------------------------------------------
    pythonScript=calcRS.py
    
    cat > $pythonScript << EOF
import sys

def calculate_rs(inst_file, avg_file, output_raw, n_points):
    n_points = int(n_points)
    print(f"   -> Computing RS = (U_inst - U_avg)^2 for {n_points} points...")
    
    # 1. READ AVERAGE FIELD INTO MEMORY
    # We load the average field into a list first to make processing faster
    avg_data = []
    try:
        count = 0
        with open(avg_file, 'r') as f_avg:
            for line in f_avg:
                if count >= n_points: break
                
                line = line.strip()
                if line.startswith('(') and line.endswith(')'):
                    clean = line.replace('(', '').replace(')', '')
                    parts = clean.split()
                    if len(parts) == 3:
                        try:
                            vals = [float(p) for p in parts]
                            avg_data.append(vals)
                            count += 1
                        except ValueError:
                            continue
        
        if len(avg_data) != n_points:
            print(f"   ERROR: Average file has {len(avg_data)} valid vectors, expected {n_points}.")
            return

    except FileNotFoundError:
        print(f"   ERROR: Average file {avg_file} not found.")
        return

    # 2. PROCESS INSTANTANEOUS FILE AND COMPUTE RS
    # We read inst file line by line, subtract corresponding avg, square, and write.
    
    processed_count = 0
    
    try:
        with open(inst_file, 'r') as f_inst, open(output_raw, 'w') as f_out:
            for line in f_inst:
                if processed_count >= n_points: break
                
                line = line.strip()
                if line.startswith('(') and line.endswith(')'):
                    clean = line.replace('(', '').replace(')', '')
                    parts = clean.split()
                    if len(parts) == 3:
                        try:
                            # Parse instantaneous
                            u_inst = float(parts[0])
                            v_inst = float(parts[1])
                            w_inst = float(parts[2])
                            
                            # Retrieve average
                            u_avg = avg_data[processed_count][0]
                            v_avg = avg_data[processed_count][1]
                            w_avg = avg_data[processed_count][2]

                            # Compute (u' u') -> technically (u_inst - u_avg)
                            # The original script does (A-B).^2 which is element-wise squared diff.
                            rs_u = (u_inst - u_avg)
                            rs_v = (v_inst - v_avg)
                            rs_w = (w_inst - w_avg)
                            
                            # Write
                            f_out.write(f"({rs_u:.6g} {rs_v:.6g} {rs_w:.6g})\n")
                            
                            processed_count += 1
                        except ValueError:
                            continue

        if processed_count == n_points:
            print("   -> Calculation complete.")
        else:
             print(f"   WARNING: Processed {processed_count} vectors (expected {n_points}). Input file might be short.")
             
    except FileNotFoundError:
        print(f"   ERROR: Instantaneous file {inst_file} not found.")

if __name__ == "__main__":
    # Args: inst_filename, avg_filename, output_filename, n_points
    calculate_rs(sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4])
EOF

    # Esecuzione Python
    # Input: inputFile (U), averaged_temp_file (UMean), output intermedio (RSQuantities)
    echo "Running Python Engine..."
    if command -v python3 &> /dev/null; then
        python3 $pythonScript $inputFile averaged_temp_file RSQuantities $totalPoints
    else
        python $pythonScript $inputFile averaged_temp_file RSQuantities $totalPoints
    fi
    wait

    # -------------------------------------------------------------------------
    # RECONSTRUCT OPENFOAM FILE
    # -------------------------------------------------------------------------
    echo "Writing OpenFOAM formatted file: $outputFile"
    
    if [ -s RSQuantities ]; then
        # 1. HEADER STANDARD
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
        echo "    location    \"$h\";" >> $outputFile
        echo "    object      $outputFile;" >> $outputFile
        echo "}" >> $outputFile
        echo "// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //" >> $outputFile
        echo "" >> $outputFile
        
        # 2. DIMENSIONI E DATI
        # Tentiamo di copiare le dimensioni dal file input, altrimenti usiamo quelle della velocità al quadrato
        # Velocità [0 1 -1 0 0 0 0] -> RS [0 2 -2 0 0 0 0]
        # Cerchiamo nel file input
        grep "dimensions" $inputFile >> $outputFile || echo "dimensions      [0 2 -2 0 0 0 0];" >> $outputFile
        
        echo "" >> $outputFile
        echo "internalField   nonuniform List<vector>" >> $outputFile
        echo "$totalPoints" >> $outputFile
        echo "(" >> $outputFile
        cat RSQuantities >> $outputFile
        echo ")" >> $outputFile
        echo ";" >> $outputFile
        
        # 3. BOUNDARY FIELD (Copia dal file istantaneo originale)
        echo "" >> $outputFile
        echo "Coping boundaryField from original file..."
        boundLine=$(grep -n "boundaryField" $inputFile | head -n 1 | cut -d: -f1)
        
        if [ ! -z "$boundLine" ]; then
            # Copiamo dal boundaryField fino alla fine
            tail -n +$boundLine $inputFile >> $outputFile
        else
            echo "boundaryField { }" >> $outputFile
        fi
        
        echo "// ************************************************************************* //" >> $outputFile
        
    else
        echo "ERROR: Calculation failed. RSQuantities empty."
    fi

    # Pulizia locale
    rm $pythonScript averaged_temp_file RSQuantities
    
    cd .. # Torna alla root
  fi
done

echo ''
echo 'FINE! - '`date`
echo '------------------------------------'
echo ''