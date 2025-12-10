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
    
    Info<< "Creating field RsMean_time" << endl;
    volSymmTensorField RsMean_time
    (
        IOobject
        (
            "RsMean_time",
            runTime.timeName(),
            mesh,
            IOobject::NO_READ,
            IOobject::NO_WRITE
        ),
        symm( (U-UMean)*(U-UMean) )*0
    );

    Info<< "Creating field tauMean_time" << endl;
    volSymmTensorField tauMean_time
    (
        IOobject
        (
            "tauMean_time",
            runTime.timeName(),
            mesh,
            IOobject::NO_READ,
            IOobject::NO_WRITE
        ),
        -0*nut*symm(fvc::grad(U))
    );

    Info<< "Creating field RsXYMean_time" << endl;
    volScalarField RsXYMean_time
    (
        IOobject
        (
            "RsXYMean_time",
            runTime.timeName(),
            mesh,
            IOobject::NO_READ,
            IOobject::NO_WRITE
        ),
        RsMean_time.component(tensor::XY)
    ); 
    
    Info<< "Creating field tauXYMean_time" << endl;
    volScalarField tauXYMean_time
    (
        IOobject
        (
            "tauXYMean_time",
            runTime.timeName(),
            mesh,
            IOobject::NO_READ,
            IOobject::NO_WRITE
        ),
        tauMean_time.component(tensor::XY)
    );
    
    Info<< "Creating field RsPlusTauMean_time" << endl;
    volScalarField RsPlusTauMean_time
    (
        IOobject
        (
            "RsPlusTauMean_time",
            runTime.timeName(),
            mesh,
            IOobject::NO_READ,
            IOobject::NO_WRITE
        ),
        RsMean_time.component(tensor::XY) + tauMean_time.component(tensor::XY)
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

