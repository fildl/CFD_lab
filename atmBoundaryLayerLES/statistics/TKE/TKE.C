/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 2011-2013 OpenFOAM Foundation
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

Application
    yPlusLES

Description
    Calculates and reports yPlus for all wall patches, for the specified times
    when using LES turbulence models.

\*---------------------------------------------------------------------------*/

#include "fvCFD.H"
//#include "incompressible/singlePhaseTransportModel/singlePhaseTransportModel.H" // for OF6
//#include "LESModel.H"
#include "nearWallDist.H"
#include "wallDist.H"
#include "wallFvPatch.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

int main(int argc, char *argv[])
{
    timeSelector::addOptions();
    #include "setRootCase.H"
    #include "createTime.H"
    instantList timeDirs = timeSelector::select0(runTime, args);
    #include "createMesh.H"
    #include "createFields.H"
    
    //faces counters initialization
    scalar counter(0.0);

    forAll(timeDirs, timeI)
    {
        runTime.setTime(timeDirs[timeI], timeI);
        Info<< "Time = " << runTime.timeName() << endl;

        //- reading input files
        Info<< "Reading field U" << endl;
        volVectorField U
        (
            IOobject
            (
                "U",
                runTime.timeName(),
                mesh,
                IOobject::MUST_READ,
                IOobject::NO_WRITE
            ),
            mesh
        );

        Info<< "Reading field nut" << endl;
        volScalarField nut
        (
            IOobject
            (
                "nut",
                runTime.timeName(),
                mesh,
                IOobject::MUST_READ,
                IOobject::NO_WRITE
            ),
            mesh
        );

        #include "createPhi.H"
        
        // TKE 
        Info<< "> Adding field k\n" << endl;
        kMean_time  += 0.5*magSqr(U-UMean);; 
        counter+= 1.0;

/*
        // DISSIPATION

        volTensorField      gradu( fvc::grad(U - UMean) );

        Info<< "Computing field DISturb" << endl;
        volScalarField DISturb
        (
            IOobject
            (
                "DISturb",
                runTime.timeName(),
                mesh,
                IOobject::NO_READ,
                IOobject::AUTO_WRITE
            ),
            -1.0*( ( (nu+nut) * tensor::I ) && ( gradu.T() & fvc::grad(U - UMean) ) )
        );

        // PRODUCTION

        Info<< "Computing field PRO" << endl;
        volScalarField PRO
        (
            IOobject
            (
                "PRO",
                runTime.timeName(),
                mesh,
                IOobject::NO_READ,
                IOobject::AUTO_WRITE
            ),
            -1*( ( U - UMean ) * ( (U - UMean) ) ) && fvc::grad( UMean )
        );


        //- Writing data
        Info<< "Writing data\n" << endl;

        DISturb.write();
        PRO.write();
*/
    }

    Info<< "Average over "<< counter << " time folder \n"<<endl;

    Info<< "Computing field kMean\n" << endl;
    kMean_time/= counter;

    //- Writing data
    Info<< "Writing data\n" << endl;
    kMean_time.write();

    Info<< "End\n" << endl;

    return 0;
}


// ************************************************************************* //
