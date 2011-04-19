//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Apr 18 14:09:39 2011 by ROOT version 5.27/06b
// from TTree t1/analysis tree
// found on file: JPTAnalysis_Data.root
//////////////////////////////////////////////////////////

#ifndef JPTAnalysis_Data_h
#define JPTAnalysis_Data_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

class JPTAnalysis_Data {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Int_t           jjpt;
   Int_t           run;
   Int_t           event;
   Int_t           nvertex;
   Double_t        PVx;
   Double_t        PVy;
   Double_t        PVz;
   vector<double>  *EtaRaw;
   vector<double>  *PhiRaw;
   vector<double>  *EtRaw;
   vector<double>  *EtaJPT;
   vector<double>  *PhiJPT;
   vector<double>  *EtJPT;
   vector<double>  *pTtrkMax;
   vector<int>     *Ntrk;
   vector<int>     *NPxlMaxPtTrk;
   vector<int>     *NSiIMaxPtTrk;
   vector<int>     *NSiOMaxPtTrk;

   // List of branches
   TBranch        *b_jjpt;   //!
   TBranch        *b_run;   //!
   TBranch        *b_event;   //!
   TBranch        *b_nvertex;   //!
   TBranch        *b_PVx;   //!
   TBranch        *b_PVy;   //!
   TBranch        *b_PVz;   //!
   TBranch        *b_EtaRaw;   //!
   TBranch        *b_PhiRaw;   //!
   TBranch        *b_EtRaw;   //!
   TBranch        *b_EtaJPT;   //!
   TBranch        *b_PhiJPT;   //!
   TBranch        *b_EtJPT;   //!
   TBranch        *b_pTtrkMax;   //!
   TBranch        *b_Ntrk;   //!
   TBranch        *b_NPxlMaxPtTrk;   //!
   TBranch        *b_NSiIMaxPtTrk;   //!
   TBranch        *b_NSiOMaxPtTrk;   //!

   JPTAnalysis_Data(TTree *tree=0);
   virtual ~JPTAnalysis_Data();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef JPTAnalysis_Data_cxx
JPTAnalysis_Data::JPTAnalysis_Data(TTree *tree)
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("rfio:///castor/cern.ch/user/a/anikiten/Data2011/JPTAnalysis_Data.root");
      if (!f) {
         f = new TFile("JPTAnalysis_Data.root");
      }
      tree = (TTree*)gDirectory->Get("t1");

   }
   Init(tree);
}

JPTAnalysis_Data::~JPTAnalysis_Data()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t JPTAnalysis_Data::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t JPTAnalysis_Data::LoadTree(Long64_t entry)
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

void JPTAnalysis_Data::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   EtaRaw = 0;
   PhiRaw = 0;
   EtRaw = 0;
   EtaJPT = 0;
   PhiJPT = 0;
   EtJPT = 0;
   pTtrkMax = 0;
   Ntrk = 0;
   NPxlMaxPtTrk = 0;
   NSiIMaxPtTrk = 0;
   NSiOMaxPtTrk = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("jjpt", &jjpt, &b_jjpt);
   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("event", &event, &b_event);
   fChain->SetBranchAddress("nvertex", &nvertex, &b_nvertex);
   fChain->SetBranchAddress("PVx", &PVx, &b_PVx);
   fChain->SetBranchAddress("PVy", &PVy, &b_PVy);
   fChain->SetBranchAddress("PVz", &PVz, &b_PVz);
   fChain->SetBranchAddress("EtaRaw", &EtaRaw, &b_EtaRaw);
   fChain->SetBranchAddress("PhiRaw", &PhiRaw, &b_PhiRaw);
   fChain->SetBranchAddress("EtRaw", &EtRaw, &b_EtRaw);
   fChain->SetBranchAddress("EtaJPT", &EtaJPT, &b_EtaJPT);
   fChain->SetBranchAddress("PhiJPT", &PhiJPT, &b_PhiJPT);
   fChain->SetBranchAddress("EtJPT", &EtJPT, &b_EtJPT);
   fChain->SetBranchAddress("pTtrkMax", &pTtrkMax, &b_pTtrkMax);
   fChain->SetBranchAddress("Ntrk", &Ntrk, &b_Ntrk);
   fChain->SetBranchAddress("NPxlMaxPtTrk", &NPxlMaxPtTrk, &b_NPxlMaxPtTrk);
   fChain->SetBranchAddress("NSiIMaxPtTrk", &NSiIMaxPtTrk, &b_NSiIMaxPtTrk);
   fChain->SetBranchAddress("NSiOMaxPtTrk", &NSiOMaxPtTrk, &b_NSiOMaxPtTrk);
   Notify();
}

Bool_t JPTAnalysis_Data::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void JPTAnalysis_Data::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t JPTAnalysis_Data::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef JPTAnalysis_Data_cxx
