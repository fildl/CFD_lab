# CFD Lab - University Course

Repository for Computational Fluid Dynamics (CFD) course.
This project focuses on **OpenFOAM** and **ParaView** for fluid dynamics simulations.

## Course Topics
*   **RANS** (Reynolds-Averaged Navier–Stokes) simulations
*   **LES** (Large Eddy Simulation)
*   Atmospheric Boundary Layer (ABL) flows

## Directory Structure
*   **`atmBoundaryLayerLES/`**: Setup for Large Eddy Simulations of the atmospheric boundary layer.
*   **`atmBoundaryLayerRANS/`**: Setup for RANS simulations of the atmospheric boundary layer.
*   **`canyon/`**: Urban canyon simulation project, including:
    *   **`simpleCanyonBuoyancyFoam`**: Custom solver code.
    *   **`canyonBack_1.5`**: Canyon background flow case.
    *   **`canyonCT_neutral`**: Canyon case with neutral stratification.

## Tools
*   [OpenFOAM](https://www.openfoam.com/) - CFD Solver
*   [ParaView](https://www.paraview.org/) - Post-processing and visualization

## Notes
*   Mesh files (`polyMesh`) are excluded to save space. Generate them using `blockMesh`.
*   Simulation results (time directories) and post-processing data are ignored.