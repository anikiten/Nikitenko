//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Jul 29 18:05:38 2011 by ROOT version 5.27/06b
// from TTree t1/analysis tree
// found on file: JPTAnalysis_Data.root
//////////////////////////////////////////////////////////

#ifndef DiMuonAnalysis_h
#define DiMuonAnalysis_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

class DiMuonAnalysis {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Int_t           run;
   Int_t           event;
   Int_t           nvertex;
   Int_t           nsimvertex;
   Int_t           DoubleMu7;
   Int_t           Mu13_Mu8;
   Int_t           Mu17_Mu8;
   Int_t           Mu17_TkMu8;
   Double_t        DZmin;
   Double_t        PVx;
   Double_t        PVy;
   Double_t        PVz;
   Double_t        mass_mumu;
   vector<double>  *EtaMu;
   vector<double>  *PhiMu;
   vector<double>  *PtMu;
   vector<double>  *dzmuon;
   vector<double>  *muisol;
   vector<double>  *EtaRaw;
   vector<double>  *PhiRaw;
   vector<double>  *EtRaw;
   vector<double>  *EtaJPT;
   vector<double>  *PhiJPT;
   vector<double>  *EtJPT;
   vector<int>     *Ntrk;
   vector<double>  *jesunc;
   vector<double>  *beta;

   // List of branches
   TBranch        *b_run;   //!
   TBranch        *b_event;   //!
   TBranch        *b_nvertex;   //!
   TBranch        *b_nsimvertex;   //!
   TBranch        *b_DoubleMu7;   //!
   TBranch        *b_Mu13_Mu8;   //!
   TBranch        *b_Mu17_Mu8;   //!
   TBranch        *b_Mu17_TkMu8;   //!
   TBranch        *b_DZmin;   //!
   TBranch        *b_PVx;   //!
   TBranch        *b_PVy;   //!
   TBranch        *b_PVz;   //!
   TBranch        *b_mass_mumu;   //!
   TBranch        *b_EtaMu;   //!
   TBranch        *b_PhiMu;   //!
   TBranch        *b_PtMu;   //!
   TBranch        *b_dzmuon;   //!
   TBranch        *b_muisol;   //!
   TBranch        *b_EtaRaw;   //!
   TBranch        *b_PhiRaw;   //!
   TBranch        *b_EtRaw;   //!
   TBranch        *b_EtaJPT;   //!
   TBranch        *b_PhiJPT;   //!
   TBranch        *b_EtJPT;   //!
   TBranch        *b_Ntrk;   //!
   TBranch        *b_jesunc;   //!
   TBranch        *b_beta;   //!

   DiMuonAnalysis(TTree *tree=0);
   virtual ~DiMuonAnalysis();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef DiMuonAnalysis_cxx
DiMuonAnalysis::DiMuonAnalysis(TTree *tree)
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
/*
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("DiMuAnalysis_Data.root");
      if (!f) {
         f = new TFile("DiMuAnalysis_Data.root");
      }
      tree = (TTree*)gDirectory->Get("t1");

   }
*/
  if (tree == 0) {
    TChain * chain = new TChain("t1","");
    chain->Add("/tmp/anikiten/SignalMCFall11/DiMuAnalysis_MC_*.root");
    //    chain->Add("/tmp/anikiten/DiMuonMCFall11/DiMuAnalysis_MC_*.root");
    //    chain->Add("/tmp/anikiten/Run2011A-08Nov2011/DiMuAnalysis_Data_*.root");
    tree = chain;
  }
   Init(tree);
}

DiMuonAnalysis::~DiMuonAnalysis()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t DiMuonAnalysis::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t DiMuonAnalysis::LoadTree(Long64_t entry)
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

void DiMuonAnalysis::Init(TTree *tree)
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
   dzmuon = 0;
   muisol = 0;
   EtaRaw = 0;
   PhiRaw = 0;
   EtRaw = 0;
   EtaJPT = 0;
   PhiJPT = 0;
   EtJPT = 0;
   Ntrk = 0;
   jesunc = 0;
   beta = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("event", &event, &b_event);
   fChain->SetBranchAddress("nvertex", &nvertex, &b_nvertex);
   fChain->SetBranchAddress("nsimvertex", &nsimvertex, &b_nsimvertex);
   fChain->SetBranchAddress("DoubleMu7", &DoubleMu7, &b_DoubleMu7);
   fChain->SetBranchAddress("Mu13_Mu8", &Mu13_Mu8, &b_Mu13_Mu8);
   fChain->SetBranchAddress("Mu17_Mu8", &Mu17_Mu8, &b_Mu17_Mu8);
   fChain->SetBranchAddress("Mu17_TkMu8", &Mu17_TkMu8, &b_Mu17_TkMu8);
   fChain->SetBranchAddress("DZmin", &DZmin, &b_DZmin);
   fChain->SetBranchAddress("PVx", &PVx, &b_PVx);
   fChain->SetBranchAddress("PVy", &PVy, &b_PVy);
   fChain->SetBranchAddress("PVz", &PVz, &b_PVz);
   fChain->SetBranchAddress("mass_mumu", &mass_mumu, &b_mass_mumu);
   fChain->SetBranchAddress("EtaMu", &EtaMu, &b_EtaMu);
   fChain->SetBranchAddress("PhiMu", &PhiMu, &b_PhiMu);
   fChain->SetBranchAddress("PtMu", &PtMu, &b_PtMu);
   fChain->SetBranchAddress("dzmuon", &dzmuon, &b_dzmuon);
   fChain->SetBranchAddress("muisol", &muisol, &b_muisol);
   fChain->SetBranchAddress("EtaRaw", &EtaRaw, &b_EtaRaw);
   fChain->SetBranchAddress("PhiRaw", &PhiRaw, &b_PhiRaw);
   fChain->SetBranchAddress("EtRaw", &EtRaw, &b_EtRaw);
   fChain->SetBranchAddress("EtaJPT", &EtaJPT, &b_EtaJPT);
   fChain->SetBranchAddress("PhiJPT", &PhiJPT, &b_PhiJPT);
   fChain->SetBranchAddress("EtJPT", &EtJPT, &b_EtJPT);
   fChain->SetBranchAddress("Ntrk", &Ntrk, &b_Ntrk);
   fChain->SetBranchAddress("jesunc", &jesunc, &b_jesunc);
   fChain->SetBranchAddress("beta", &beta, &b_beta);
   Notify();
}

Bool_t DiMuonAnalysis::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void DiMuonAnalysis::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t DiMuonAnalysis::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef DiMuonAnalysis_cxx
