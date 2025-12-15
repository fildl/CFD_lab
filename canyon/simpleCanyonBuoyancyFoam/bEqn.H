{
  alphat = turbulence->nut()/Prt;
  alphat.correctBoundaryConditions();

  volScalarField alphaEff("alphaEff", turbulence->nu()/Pr + alphat);
  volScalarField source("source", N2*(U & l) );

  fvScalarMatrix bEqn
  (
      fvm::ddt(b)
    + fvm::div(phi, b)
    - fvm::laplacian(alphaEff, b)
    ==
    //fvc::div(phi, N2gh)             // explicit source term with div
    //source                          // explicit source term
      fvm::Sp(quattro*source,b)       // explicit-implicit source term
    + source*(1.0-quattro*b)
//    + fvOptions(b)
  );

  bEqn.relax();

  //fvOptions.constrain(bEqn);

  bEqn.solve();

  //radiation->correct();

//  fvOptions.correct(b);
}