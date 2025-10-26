#pragma once
#include <iostream>
#include <TObject.h>

class alice : public TObject
{
public:
    alice();                                      // default constructor
    alice(Double_t Px, Double_t Py, Double_t Pz); // some other constructor
    virtual ~alice();                             // destructor
    Double_t momentum_mag();
    Double_t getPx() { return px; };
    Double_t getPy() { return py; };
    Double_t getPz() { return pz; };

private:
    // some private members
    ClassDef(alice, 1); // your_class
    Double_t px;
    Double_t py;
    Double_t pz;
};