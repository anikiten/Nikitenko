//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Feb  5 10:50:06 2010 by ROOT version 5.22/00d
// from TTree t1/analysis tree
// found on file: analysisDataTau_6.root
//////////////////////////////////////////////////////////

#ifndef JPTRootAnalysisDataMCTau_h
#define JPTRootAnalysisDataMCTau_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

class JPTRootAnalysisDataMCTau {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Int_t           jtau;
   Int_t           run;
   Int_t           event;
   Double_t        PVx;
   Double_t        PVy;
   Double_t        PVz;
   vector<double>  *EtaRaw;
   vector<double>  *PhiRaw;
   vector<double>  *EtRaw;
   vector<double>  *tcEta;
   vector<double>  *tcPhi;
   vector<double>  *tcEt;
   vector<int>     *ltrexists;
   vector<double>  *d0ltr;
   vector<double>  *ptltr;
   vector<double>  *drltrjet;
   vector<int>     *ntrsign;
   vector<double>  *ptminsign;
   vector<int>     *ntrisol;
   vector<double>  *ptminisol;
   vector<double>  *dzmaxltr;
   vector<float>   *emisolat;
   vector<float>   *dByLeadingTrackFinding;
   vector<float>   *dByLeadingTrackPtCut;
   vector<float>   *dByIsolation;
   vector<float>   *dAgainstElectron;

   // List of branches
   TBranch        *b_jtau;   //!
   TBranch        *b_run;   //!
   TBranch        *b_event;   //!
   TBranch        *b_PVx;   //!
   TBranch        *b_PVy;   //!
   TBranch        *b_PVz;   //!
   TBranch        *b_EtaRaw;   //!
   TBranch        *b_PhiRaw;   //!
   TBranch        *b_EtRaw;   //!
   TBranch        *b_tcEta;   //!
   TBranch        *b_tcPhi;   //!
   TBranch        *b_tcEt;   //!
   TBranch        *b_ltrexists;   //!
   TBranch        *b_d0ltr;   //!
   TBranch        *b_ptltr;   //!
   TBranch        *b_drltrjet;   //!
   TBranch        *b_ntrsign;   //!
   TBranch        *b_ptminsign;   //!
   TBranch        *b_ntrisol;   //!
   TBranch        *b_ptminisol;   //!
   TBranch        *b_dzmaxltr;   //!
   TBranch        *b_emisolat;   //!
   TBranch        *b_dByLeadingTrackFinding;   //!
   TBranch        *b_dByLeadingTrackPtCut;   //!
   TBranch        *b_dByIsolation;   //!
   TBranch        *b_dAgainstElectron;   //!

   JPTRootAnalysisDataMCTau(TTree *tree=0);
   virtual ~JPTRootAnalysisDataMCTau();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef JPTRootAnalysisDataMCTau_cxx
JPTRootAnalysisDataMCTau::JPTRootAnalysisDataMCTau(TTree *tree)
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
/*
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("analysisDataTau_6.root");
      if (!f) {
         f = new TFile("analysisDataTau_6.root");
      }
      tree = (TTree*)gDirectory->Get("t1");
   }
*/
  if (tree == 0) {
    TChain * chain = new TChain("t1","");
    chain->Add("analysisMCTau_*.root");
    //    chain->Add("analysisDataTau_*.root");
    tree = chain;
  }
  Init(tree);
}

JPTRootAnalysisDataMCTau::~JPTRootAnalysisDataMCTau()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t JPTRootAnalysisDataMCTau::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t JPTRootAnalysisDataMCTau::LoadTree(Long64_t entry)
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

void JPTRootAnalysisDataMCTau::Init(TTree *tree)
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
   tcEta = 0;
   tcPhi = 0;
   tcEt = 0;
   ltrexists = 0;
   d0ltr = 0;
   ptltr = 0;
   drltrjet = 0;
   ntrsign = 0;
   ptminsign = 0;
   ntrisol = 0;
   ptminisol = 0;
   dzmaxltr = 0;
   emisolat = 0;
   dByLeadingTrackFinding = 0;
   dByLeadingTrackPtCut = 0;
   dByIsolation = 0;
   dAgainstElectron = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("jtau", &jtau, &b_jtau);
   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("event", &event, &b_event);
   fChain->SetBranchAddress("PVx", &PVx, &b_PVx);
   fChain->SetBranchAddress("PVy", &PVy, &b_PVy);
   fChain->SetBranchAddress("PVz", &PVz, &b_PVz);
   fChain->SetBranchAddress("EtaRaw", &EtaRaw, &b_EtaRaw);
   fChain->SetBranchAddress("PhiRaw", &PhiRaw, &b_PhiRaw);
   fChain->SetBranchAddress("EtRaw", &EtRaw, &b_EtRaw);
   fChain->SetBranchAddress("tcEta", &tcEta, &b_tcEta);
   fChain->SetBranchAddress("tcPhi", &tcPhi, &b_tcPhi);
   fChain->SetBranchAddress("tcEt", &tcEt, &b_tcEt);
   fChain->SetBranchAddress("ltrexists", &ltrexists, &b_ltrexists);
   fChain->SetBranchAddress("d0ltr", &d0ltr, &b_d0ltr);
   fChain->SetBranchAddress("ptltr", &ptltr, &b_ptltr);
   fChain->SetBranchAddress("drltrjet", &drltrjet, &b_drltrjet);
   fChain->SetBranchAddress("ntrsign", &ntrsign, &b_ntrsign);
   fChain->SetBranchAddress("ptminsign", &ptminsign, &b_ptminsign);
   fChain->SetBranchAddress("ntrisol", &ntrisol, &b_ntrisol);
   fChain->SetBranchAddress("ptminisol", &ptminisol, &b_ptminisol);
   fChain->SetBranchAddress("dzmaxltr", &dzmaxltr, &b_dzmaxltr);
   fChain->SetBranchAddress("emisolat", &emisolat, &b_emisolat);
   fChain->SetBranchAddress("dByLeadingTrackFinding", &dByLeadingTrackFinding, &b_dByLeadingTrackFinding);
   fChain->SetBranchAddress("dByLeadingTrackPtCut", &dByLeadingTrackPtCut, &b_dByLeadingTrackPtCut);
   fChain->SetBranchAddress("dByIsolation", &dByIsolation, &b_dByIsolation);
   fChain->SetBranchAddress("dAgainstElectron", &dAgainstElectron, &b_dAgainstElectron);

   Notify();
}

Bool_t JPTRootAnalysisDataMCTau::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void JPTRootAnalysisDataMCTau::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t JPTRootAnalysisDataMCTau::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef JPTRootAnalysisDataMCTau_cxx
