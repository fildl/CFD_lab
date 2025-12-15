Info<< "Reading field p\n" << endl;
volScalarField p
(
    IOobject
    (
        "p",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

Info<< "Reading field U\n" << endl;
volVectorField U
(
    IOobject
    (
        "U",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

Info<< "Reading field b\n" << endl;
volScalarField b
(
    IOobject
    (
        "b",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

Info<< "Reading field c\n" << endl;
volScalarField c
(
    IOobject
    (
        "c",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

Info<< "Reading field lambdat\n" << endl;
volScalarField lambdat
(
    IOobject
    (
        "lambdat",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

// kinematic turbulent thermal thermal conductivity m2/s
Info<< "Reading field alphat\n" << endl;
volScalarField alphat
(
    IOobject
    (
        "alphat",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

Info<< "\nReading gravity versor l = g/|g|" << endl;
volVectorField l
(
    IOobject
    (
        "l",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

#include "createPhi.H"


pressureReference pressureReference(p, simple.dict());

mesh.setFluxRequired(p.name());


singlePhaseTransportModel laminarTransport(U, phi);

autoPtr<incompressible::momentumTransportModel> turbulence
(
    incompressible::momentumTransportModel::New(U, phi, laminarTransport)
);

// Laminar Schmidt number
dimensionedScalar Sc("Sc", dimless, laminarTransport);

// Turbulent Schmidt number
dimensionedScalar Sct("Sct", dimless, laminarTransport);

// Brunt-Vaisala frequency squared [1/s^2]
dimensionedScalar N2("N2",dimless/(dimTime*dimTime),laminarTransport);

// Gravity
dimensionedScalar g("g", dimLength/(dimTime*dimTime), laminarTransport);

// Laminar Prandtl number
dimensionedScalar Pr("Pr", dimless, laminarTransport);

// Turbulent Prandtl number
dimensionedScalar Prt("Prt", dimless, laminarTransport);

// carlo - dummy variable for b source term
    dimensionedScalar quattro
    (
        "quattro",
        dimensionSet(0, -1, 2, 0, 0, 0, 0),
        4.0
    );


#include "createMRF.H"
#include "createFvModels.H"
#include "createFvConstraints.H"
