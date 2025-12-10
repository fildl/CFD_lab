# CFD Lab - University Course

Repository for the Computational Fluid Dynamics (CFD) university course.
This project focuses on learning and applying **OpenFOAM** and **ParaView** for fluid dynamics simulations.

## Course Topics
*   **RANS** (Reynolds-Averaged Navier–Stokes) simulations
*   **LES** (Large Eddy Simulation)
*   Atmospheric Boundary Layer (ABL) flows

## Directory Structure
*   **`atmBoundaryLayerLES/`**: Setup for Large Eddy Simulations of the atmospheric boundary layer.
*   **`atmBoundaryLayerRANS/`**: Setup for RANS simulations of the atmospheric boundary layer.

## Tools
*   [OpenFOAM](https://www.openfoam.com/) - CFD Solver
*   [ParaView](https://www.paraview.org/) - Post-processing and visualization

## Notes
*   Mesh files (`polyMesh`) are excluded to save space. Generate them using `blockMesh`.
*   Simulation results (time directories) and post-processing data are ignored.