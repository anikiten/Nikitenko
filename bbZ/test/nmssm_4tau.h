//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Feb 20 09:56:54 2013 by ROOT version 5.32/00
// from TTree t1/analysis tree
// found on file: nmssm_4tau_mh8.root
//////////////////////////////////////////////////////////

#ifndef nmssm_4tau_h
#define nmssm_4tau_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

#include <iostream>

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class nmssm_4tau {
public :

  Double_t deltaR(Double_t eta1, Double_t phi1, Double_t eta2, Double_t phi2);
  Double_t deltaEta(Double_t eta1, Double_t eta2);
  Double_t deltaPhi(Double_t phi1, Double_t phi2);

   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Double_t        ptmu1;
   Double_t        etamu1;
   Double_t        phimu1;
   Double_t        ptmu2;
   Double_t        etamu2;
   Double_t        phimu2;

   // List of branches
   TBranch        *b_ptmu1;   //!
   TBranch        *b_etamu1;   //!
   TBranch        *b_phimu1;   //!
   TBranch        *b_ptmu2;   //!
   TBranch        *b_etamu2;   //!
   TBranch        *b_phimu2;   //!

   nmssm_4tau(TTree *tree=0);
   virtual ~nmssm_4tau();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef nmssm_4tau_cxx
nmssm_4tau::nmssm_4tau(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("nmssm_4tau_mh8.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("nmssm_4tau_mh8.root");
      }
      f->GetObject("t1",tree);

   }
   Init(tree);
}

nmssm_4tau::~nmssm_4tau()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t nmssm_4tau::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t nmssm_4tau::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void nmssm_4tau::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("ptmu1", &ptmu1, &b_ptmu1);
   fChain->SetBranchAddress("etamu1", &etamu1, &b_etamu1);
   fChain->SetBranchAddress("phimu1", &phimu1, &b_phimu1);
   fChain->SetBranchAddress("ptmu2", &ptmu2, &b_ptmu2);
   fChain->SetBranchAddress("etamu2", &etamu2, &b_etamu2);
   fChain->SetBranchAddress("phimu2", &phimu2, &b_phimu2);
   Notify();
}

Bool_t nmssm_4tau::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void nmssm_4tau::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t nmssm_4tau::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef nmssm_4tau_cxx
