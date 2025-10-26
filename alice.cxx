#include <alice.h>
#include <cmath>

ClassImp(alice);

// default constructor - ROOT needs the default one where everything is set to 0
alice::alice()
{
    px = 0;
    py = 0;
    pz = 0;
};
// another constructor
alice::alice(Double_t Px, Double_t Py, Double_t Pz)
{
    px = Px;
    py = Py;
    pz = Pz;
};
// destructor
alice::~alice() {
    // right now I’m empty
};
Double_t alice::momentum_mag()
{
    return std::sqrt(px * px + py * py + pz * pz);
};
