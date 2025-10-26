#include "alice.h"
#include <TObject.h>
#include <TTree.h>
#include <TFile.h>
#include <TRandom.h>
#include <TMath.h>
#include <fstream>
#include <TH1F.h>
#include <TH2.h>

void read()
{
    // initialize your object
    alice *event{nullptr};
    // open your file
    auto file = TFile::Open("tree_file.root");
    TTree *T = static_cast<TTree *>(file->Get("tree"));

    T->SetBranchAddress("event", &event);
    Long64_t N = T->GetEntries();
    // get your tree
    // remember to set the branch address
    TH1F *h1 = new TH1F("h1", "Momentum Magnitude Distribution; P; Counts", 100, 0, 2);

    for (Int_t i{0}; i < N; i++)
    { // loop over the whole tree
        T->GetEntry(i);
        // do something
        h1->Fill(event->momentum_mag());
    }
    // h1->Draw();

    TH2D *h2 = new TH2D("h2", "Px vs Py; P; Counts", 100, -1.5, 1.5, 100, -1.5, 1.5);

    for (Int_t i{0}; i < N; i++)
    { // loop over the whole tree
        T->GetEntry(i);
        // do something
        h2->Fill(event->getPx(), event->getPz());
    }
    h2->Draw();
}

void read2()
{
    // initialize your object
    alice *event{nullptr};
    // open your file
    auto file = TFile::Open("tree_file.root");
    TTree *T = static_cast<TTree *>(file->Get("tree"));

    T->SetBranchAddress("event", &event);
    Long64_t N = T->GetEntries();
    // get your tree
    // remember to set the branch address

    TH2D *h2 = new TH2D("h2", "Px*Py vs Py; P; Counts", 100, -2, 2, 100, -1, 1);

    for (Int_t i{0}; i < N; i++)
    { // loop over the whole tree
        T->GetEntry(i);
        // do something
        if (event->momentum_mag() > 3 * event->getPz())
        {
            h2->Fill(event->getPx() * event->getPy(), event->getPz());
        }
    }
    h2->Draw();
}