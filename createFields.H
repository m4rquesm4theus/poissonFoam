Info<< "Reading field T\n" << endl;

volScalarField T
(
    IOobject
    (
        "T",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

Info<< "Creating source term\n" << endl;
dimensionedScalar oneST("oneST", dimensionSet(0,0,-1,0,0,0,0), scalar(1.0)); //criado para manter a unidade do source term como [1/s]
//dimensionedScalar ST("ST", dimensionSet(0,0,-1,0,0,0,0), Zero); //indicando qual é a unidade do termo fonte

//O PROBLEMA ACREDITO QUE ESTEJA NO ST, POIS ELE PRECISA SER ATUALIZADO COM T E NÃO SER UM SCALAR(1.0)

volScalarField ST
(
    IOobject
    (
        "ST",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);


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


Info<< "Reading diffusivity DT\n" << endl;
dimensionedScalar oneDT("oneDT", dimensionSet(0,2,-1,0,0,0,0), scalar(1.0)); //criada para manter a unidade de DT ao final [m²/s]
//dimensionedScalar DT("DT", dimViscosity, scalar(1.0));

volScalarField DT
(
    IOobject
    (
        "DT",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
     
);
//DT = oneDT*(0.2+exp(-4*T)); 


//volScalarField ST("ST", oneST*500*exp(-(0.3/(T+0.1))));

#include "createFvOptions.H"
