//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Feb 14 12:53:01 2013 by ROOT version 5.32/00
// from TTree t1/analysis tree
// found on file: nmssm_mh20.root
//////////////////////////////////////////////////////////

#ifndef nmssm_2tau2b_h
#define nmssm_2tau2b_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class nmssm_2tau2b {
public :

  Double_t deltaR(Double_t eta1, Double_t phi1, Double_t eta2, Double_t phi2);
  Double_t deltaEta(Double_t eta1, Double_t eta2);
  Double_t deltaPhi(Double_t phi1, Double_t phi2);

   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Double_t        ptb1;
   Double_t        etab1;
   Double_t        phib1;
   Double_t        ptb2;
   Double_t        etab2;
   Double_t        phib2;
   Double_t        ptmu;
   Double_t        etamu;
   Double_t        phimu;
   Double_t        pttauh;
   Double_t        etatauh;
   Double_t        phitauh;

   // List of branches
   TBranch        *b_ptb1;   //!
   TBranch        *b_etab1;   //!
   TBranch        *b_phib1;   //!
   TBranch        *b_ptb2;   //!
   TBranch        *b_etab2;   //!
   TBranch        *b_phib2;   //!
   TBranch        *b_ptmu;   //!
   TBranch        *b_etamu;   //!
   TBranch        *b_phimu;   //!
   TBranch        *b_pttauh;   //!
   TBranch        *b_etatauh;   //!
   TBranch        *b_phitauh;   //!

   nmssm_2tau2b(TTree *tree=0);
   virtual ~nmssm_2tau2b();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef nmssm_2tau2b_cxx
nmssm_2tau2b::nmssm_2tau2b(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
     TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("nmssm_mh20.root");
      if (!f || !f->IsOpen()) {
	//         f = new TFile("nmssm_mh20.root");
	f = new TFile("nmssm_mh20.root");
      }
      f->GetObject("t1",tree);

   }
   Init(tree);
}

nmssm_2tau2b::~nmssm_2tau2b()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t nmssm_2tau2b::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t nmssm_2tau2b::LoadTree(Long64_t entry)
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

void nmssm_2tau2b::Init(TTree *tree)
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

   fChain->SetBranchAddress("ptb1", &ptb1, &b_ptb1);
   fChain->SetBranchAddress("etab1", &etab1, &b_etab1);
   fChain->SetBranchAddress("phib1", &phib1, &b_phib1);
   fChain->SetBranchAddress("ptb2", &ptb2, &b_ptb2);
   fChain->SetBranchAddress("etab2", &etab2, &b_etab2);
   fChain->SetBranchAddress("phib2", &phib2, &b_phib2);
   fChain->SetBranchAddress("ptmu", &ptmu, &b_ptmu);
   fChain->SetBranchAddress("etamu", &etamu, &b_etamu);
   fChain->SetBranchAddress("phimu", &phimu, &b_phimu);
   fChain->SetBranchAddress("pttauh", &pttauh, &b_pttauh);
   fChain->SetBranchAddress("etatauh", &etatauh, &b_etatauh);
   fChain->SetBranchAddress("phitauh", &phitauh, &b_phitauh);
   Notify();
}

Bool_t nmssm_2tau2b::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void nmssm_2tau2b::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t nmssm_2tau2b::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef nmssm_2tau2b_cxx
