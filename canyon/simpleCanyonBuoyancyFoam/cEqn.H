    // Concentration equation
    lambdat = turbulence->nut()/Sct;
    lambdat.correctBoundaryConditions();

    volScalarField lambdaEff("lambdaEff", turbulence->nu()/Sc + lambdat);

    fvScalarMatrix cEqn
    (
        fvm::div(phi, c)
//      + turbulence->divDevReff(c)
     ==
        fvm::laplacian(lambdaEff,c)
//        fvOptions(U)
    );

//  fvVectorMatrix& UEqn = tUEqn.ref();

    cEqn.relax();
    cEqn.solve();

// clipping
    scalar n=0.0;
    
    forAll(c,pIt)
    if(c[pIt]<0)
    {
        c[pIt] = scalar(0.0);
        n=n+1;
    }

    Info << "           Number of clipped cells: "<< n <<endl;

// end clipping

/*        
    fvOptions.constrain(UEqn);

    if (simple.momentumPredictor())
    {
        solve(UEqn == -fvc::grad(p));

        fvOptions.correct(U);
    }
*/
