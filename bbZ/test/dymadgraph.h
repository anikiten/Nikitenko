//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Dec  6 18:20:36 2011 by ROOT version 5.27/06b
// from TTree t1/analysis tree
// found on file: dymadgraph.root
//////////////////////////////////////////////////////////

#ifndef dymadgraph_h
#define dymadgraph_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

class dymadgraph {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Double_t        event_w;
   Double_t        pTZ;
   Double_t        yZ;
   vector<double>  *EtaMu;
   vector<double>  *PhiMu;
   vector<double>  *PtMu;
   vector<double>  *EtaJ;
   vector<double>  *PhiJ;
   vector<double>  *pTJ;

   // List of branches
   TBranch        *b_event_w;   //!
   TBranch        *b_pTZ;   //!
   TBranch        *b_yZ;   //!
   TBranch        *b_EtaMu;   //!
   TBranch        *b_PhiMu;   //!
   TBranch        *b_PtMu;   //!
   TBranch        *b_EtaJ;   //!
   TBranch        *b_PhiJ;   //!
   TBranch        *b_pTJ;   //!

   dymadgraph(TTree *tree=0);
   virtual ~dymadgraph();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef dymadgraph_cxx
dymadgraph::dymadgraph(TTree *tree)
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
     //     TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("dymadgraph.root");
     TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("dysherpa.root");
      if (!f) {
	//	f = new TFile("dymadgraph.root");
	f = new TFile("dysherpa.root");
      }
      tree = (TTree*)gDirectory->Get("t1");

   }
   Init(tree);
}

dymadgraph::~dymadgraph()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t dymadgraph::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t dymadgraph::LoadTree(Long64_t entry)
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

void dymadgraph::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   EtaMu = 0;
   PhiMu = 0;
   PtMu = 0;
   EtaJ = 0;
   PhiJ = 0;
   pTJ = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("event_w", &event_w, &b_event_w);
   fChain->SetBranchAddress("pTZ", &pTZ, &b_pTZ);
   fChain->SetBranchAddress("yZ", &yZ, &b_yZ);
   fChain->SetBranchAddress("EtaMu", &EtaMu, &b_EtaMu);
   fChain->SetBranchAddress("PhiMu", &PhiMu, &b_PhiMu);
   fChain->SetBranchAddress("PtMu", &PtMu, &b_PtMu);
   fChain->SetBranchAddress("EtaJ", &EtaJ, &b_EtaJ);
   fChain->SetBranchAddress("PhiJ", &PhiJ, &b_PhiJ);
   fChain->SetBranchAddress("pTJ", &pTJ, &b_pTJ);
   Notify();
}

Bool_t dymadgraph::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void dymadgraph::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t dymadgraph::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef dymadgraph_cxx
