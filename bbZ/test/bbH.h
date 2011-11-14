//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Nov 11 14:49:53 2011 by ROOT version 5.27/06b
// from TTree t1/analysis tree
// found on file: bbH140.root
//////////////////////////////////////////////////////////

#ifndef bbH_h
#define bbH_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

class bbH {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Int_t           nbjets;
   Double_t        pTH;
   Double_t        yH;
   Double_t        pTb;
   Double_t        yb;

   // List of branches
   TBranch        *b_nbjets;   //!
   TBranch        *b_pTH;   //!
   TBranch        *b_yH;   //!
   TBranch        *b_pTb;   //!
   TBranch        *b_yb;   //!

   bbH(TTree *tree=0);
   virtual ~bbH();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef bbH_cxx
bbH::bbH(TTree *tree)
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("bbH400.root");
      if (!f) {
         f = new TFile("bbH140.root");
      }
      tree = (TTree*)gDirectory->Get("t1");

   }
   Init(tree);
}

bbH::~bbH()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t bbH::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t bbH::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (!fChain->InheritsFrom(TChain::Class()))  return centry;
   TChain *chain = (TChain*)fChain;
   if (chain->GetTreeNumber() != fCurrent) {
      fCurrent = chain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void bbH::Init(TTree *tree)
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

   fChain->SetBranchAddress("nbjets", &nbjets, &b_nbjets);
   fChain->SetBranchAddress("pTH", &pTH, &b_pTH);
   fChain->SetBranchAddress("yH", &yH, &b_yH);
   fChain->SetBranchAddress("pTb", &pTb, &b_pTb);
   fChain->SetBranchAddress("yb", &yb, &b_yb);
   Notify();
}

Bool_t bbH::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void bbH::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t bbH::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef bbH_cxx
