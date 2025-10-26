#include "alice.h"
#include <TObject.h>
#include <TTree.h>
#include <TFile.h>
#include <TRandom.h>
#include <TMath.h>
#include <fstream>

int nEvents{100000};

void write()
{
    // Initialize your object e.g. as a pointer
    alice *event{nullptr};
    // Create your root file here
    TFile f("tree_file.root", "RECREATE");

    // Create your TTree here
    TTree *T = new TTree("tree", "Tree of alice events");
    // And the associated branches underneath
    // for example a branch with your personal object type
    T->Branch("event", &event);
    // Now we create our loop for filling the tree with some random data
    // For loop here
    Double_t p1;
    Double_t p2;
    Double_t p3;
    for (Int_t i{0}; i < nEvents; i++)
    {
        // define how many events you want
        // Initialize your new object below
        gRandom->Rannor(p1, p2);
        p1 = gRandom->Gaus(0, 0.5);
        p2 = gRandom->Gaus(0, 0.5);
        p3 = gRandom->Gaus(0.2, 0.2);
        // Now fill tree
        event = new alice(p1, p2, p3);
        T->Fill();
        delete event;
        // Remember to delete it again otherwise you will have memory leak!
    }
    // save the tree/file
    T->AutoSave();
}