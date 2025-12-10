    Info<< "Reading field U\n" << endl;
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

    Info<< "Reading field UMean\n" << endl;
    volVectorField UMean
    (
        IOobject
        (
            "UMean",
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
    
    // carlo: reading physical constants
    Info<< "Reading transportProperties\n" << endl;

    IOdictionary transportProperties
    (
        IOobject
        (
            "transportProperties",
            runTime.constant(),
            mesh,
            IOobject::MUST_READ_IF_MODIFIED,
            IOobject::NO_WRITE
        )
    );

    //- upload dynamic viscosity 
    dimensionedScalar nu
    (
        transportProperties.lookup("nu")
    );

    
    // DISSIPATION

    volTensorField      gradu( fvc::grad(U - UMean) );

    Info<< "Computing field epsilonMean_time" << endl;
    volScalarField epsilonMean_time
    (
        IOobject
        (
            "epsilonMean_time",
            runTime.timeName(),
            mesh,
            IOobject::NO_READ,
            IOobject::AUTO_WRITE
        ),
        -1.0*(nu+nut)*magSqr(fvc::grad(U - UMean))
    );

    // PRODUCTION

    Info<< "Computing field PMean_time" << endl;
    volScalarField PMean_time
    (
        IOobject
        (
            "PMean_time",
            runTime.timeName(),
            mesh,
            IOobject::NO_READ,
            IOobject::AUTO_WRITE
        ),
        -1*( ( U - UMean ) * (U - UMean) ) && fvc::grad( UMean )
    );



