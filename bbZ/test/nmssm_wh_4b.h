//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Oct 23 11:35:27 2013 by ROOT version 5.32/00
// from TTree t1/analysis tree
// found on file: nmssm_wh_4b_mh20.root
//////////////////////////////////////////////////////////

#ifndef nmssm_wh_4b_h
#define nmssm_wh_4b_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include <vector>

// Fixed size dimensions of array or collections stored in the TTree if any.

class nmssm_wh_4b {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Int_t           idl;
   Double_t        ptl;
   Double_t        etal;
   Double_t        phil;
   vector<double>  *ptb;
   vector<double>  *etab;
   vector<double>  *phib;

   // List of branches
   TBranch        *b_idl;   //!
   TBranch        *b_ptl;   //!
   TBranch        *b_etal;   //!
   TBranch        *b_phil;   //!
   TBranch        *b_ptb;   //!
   TBranch        *b_etab;   //!
   TBranch        *b_phib;   //!

   nmssm_wh_4b(TTree *tree=0);
   virtual ~nmssm_wh_4b();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef nmssm_wh_4b_cxx
nmssm_wh_4b::nmssm_wh_4b(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("nmssm_wh_4b_mh60.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("nmssm_wh_4b_mh60.root");
      }
      f->GetObject("t1",tree);

   }
   Init(tree);
}

nmssm_wh_4b::~nmssm_wh_4b()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t nmssm_wh_4b::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t nmssm_wh_4b::LoadTree(Long64_t entry)
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

void nmssm_wh_4b::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   ptb = 0;
   etab = 0;
   phib = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("idl", &idl, &b_idl);
   fChain->SetBranchAddress("ptl", &ptl, &b_ptl);
   fChain->SetBranchAddress("etal", &etal, &b_etal);
   fChain->SetBranchAddress("phil", &phil, &b_phil);
   fChain->SetBranchAddress("ptb", &ptb, &b_ptb);
   fChain->SetBranchAddress("etab", &etab, &b_etab);
   fChain->SetBranchAddress("phib", &phib, &b_phib);
   Notify();
}

Bool_t nmssm_wh_4b::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void nmssm_wh_4b::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t nmssm_wh_4b::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef nmssm_wh_4b_cxx
