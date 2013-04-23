//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Jan 28 16:43:38 2013 by ROOT version 5.34/04
// from TTree t1/analysis tree
// found on file: VBFHinvisQCD.root
//////////////////////////////////////////////////////////

#ifndef VBFHinvisQCD_h
#define VBFHinvisQCD_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

#include <iostream>

// Header file for the classes stored in the TTree if any.
#include <vector>
#include <vector>
#include <vector>

// Fixed size dimensions of array or collections stored in the TTree if any.

class VBFHinvisQCD {
public :

  Double_t deltaR(Double_t eta1, Double_t phi1, Double_t eta2, Double_t phi2);
  Double_t deltaEta(Double_t eta1, Double_t eta2);
  Double_t deltaPhi(Double_t phi1, Double_t phi2);

   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Int_t           run;
   Int_t           event;
   Int_t           nvertex;
   Int_t           nsimvertex;
   Int_t           f1;
   Int_t           f2;
   Int_t           f3;
   Int_t           f4;
   Int_t           f5;
   Int_t           L1ETM40;
   Int_t           VBF_AllJets;
   Int_t           DoubleMu7;
   Int_t           Mu13_Mu8;
   Int_t           Mu17_Mu8;
   Int_t           Mu17_TkMu8;
   Double_t        DZmin;
   Double_t        PVx;
   Double_t        PVy;
   Double_t        PVz;
   Double_t        pfmet;
   Double_t        pfmetType1;
   Double_t        mass_mumu;
   vector<double>  *EtaMu;
   vector<double>  *PhiMu;
   vector<double>  *PtMu;
   vector<double>  *dzmuon;
   vector<double>  *mutrkisol;
   vector<double>  *mupfisol;
   vector<int>     *mucharge;
   vector<int>     *muid;
   Double_t        mass_ee;
   vector<double>  *EtaEl;
   vector<double>  *PhiEl;
   vector<double>  *PtEl;
   vector<double>  *eltrkisol;
   vector<int>     *elcharge;
   vector<int>     *elid;
   vector<double>  *EtaRaw;
   vector<double>  *PhiRaw;
   vector<double>  *EtRaw;
   vector<double>  *EtaJPT;
   vector<double>  *PhiJPT;
   vector<double>  *EtJPT;
   vector<float>   *MVAJPT;
   vector<int>     *Ntrk;
   vector<double>  *jesunc;
   vector<double>  *beta;
   Int_t           n_trk1GeV;
   Int_t           n_trk2GeV;
   Int_t           n_trk3GeV;
   vector<double>  *EtaPF;
   vector<double>  *PhiPF;
   vector<double>  *EtPF;
   vector<float>   *MVAPF;
   vector<int>     *IDPF;
   vector<int>     *JTypePF;

   // List of branches
   TBranch        *b_run;   //!
   TBranch        *b_event;   //!
   TBranch        *b_nvertex;   //!
   TBranch        *b_nsimvertex;   //!
   TBranch        *b_f1;   //!
   TBranch        *b_f2;   //!
   TBranch        *b_f3;   //!
   TBranch        *b_f4;   //!
   TBranch        *b_f5;   //!
   TBranch        *b_L1ETM40;   //!
   TBranch        *b_VBF_AllJets;   //!
   TBranch        *b_DoubleMu7;   //!
   TBranch        *b_Mu13_Mu8;   //!
   TBranch        *b_Mu17_Mu8;   //!
   TBranch        *b_Mu17_TkMu8;   //!
   TBranch        *b_DZmin;   //!
   TBranch        *b_PVx;   //!
   TBranch        *b_PVy;   //!
   TBranch        *b_PVz;   //!
   TBranch        *b_pfmet;   //!
   TBranch        *b_pfmetType1;   //!
   TBranch        *b_mass_mumu;   //!
   TBranch        *b_EtaMu;   //!
   TBranch        *b_PhiMu;   //!
   TBranch        *b_PtMu;   //!
   TBranch        *b_dzmuon;   //!
   TBranch        *b_mutrkisol;   //!
   TBranch        *b_mupfisol;   //!
   TBranch        *b_mucharge;   //!
   TBranch        *b_muid;   //!
   TBranch        *b_mass_ee;   //!
   TBranch        *b_EtaEl;   //!
   TBranch        *b_PhiEl;   //!
   TBranch        *b_PtEl;   //!
   TBranch        *b_eltrkisol;   //!
   TBranch        *b_elcharge;   //!
   TBranch        *b_elid;   //!
   TBranch        *b_EtaRaw;   //!
   TBranch        *b_PhiRaw;   //!
   TBranch        *b_EtRaw;   //!
   TBranch        *b_EtaJPT;   //!
   TBranch        *b_PhiJPT;   //!
   TBranch        *b_EtJPT;   //!
   TBranch        *b_MVAJPT;   //!
   TBranch        *b_Ntrk;   //!
   TBranch        *b_jesunc;   //!
   TBranch        *b_beta;   //!
   TBranch        *b_n_trk1GeV;   //!
   TBranch        *b_n_trk2GeV;   //!
   TBranch        *b_n_trk3GeV;   //!
   TBranch        *b_EtaPF;   //!
   TBranch        *b_PhiPF;   //!
   TBranch        *b_EtPF;   //!
   TBranch        *b_MVAPF;   //!
   TBranch        *b_IDPF;   //!
   TBranch        *b_JTypePF;   //!

   VBFHinvisQCD(TTree *tree=0);
   virtual ~VBFHinvisQCD();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef VBFHinvisQCD_cxx
VBFHinvisQCD::VBFHinvisQCD(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
/*
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("VBFHinvisQCD.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("VBFHinvisQCD.root");
      }
      f->GetObject("t1",tree);

   }
*/
  if (tree == 0) {
    TChain * chain = new TChain("t1","");

    /*
    chain->Add("/vols/cms02/anikiten/MET_Run2012A-13Jul2012/VBFHinvis_*.root");
    chain->Add("/vols/cms02/anikiten/MET_Run2012A-06Aug2012/VBFHinvis_*.root");
    chain->Add("/vols/cms02/anikiten/MET_Run2012B-13Jul2012/VBFHinvis_*.root");
    chain->Add("/vols/cms02/anikiten/MET_Run2012C-24Aug2012/VBFHinvis_*.root");
    chain->Add("/vols/cms02/anikiten/MET_Run2012C-PromptReco-v2/VBFHinvis_*.root");
    chain->Add("/vols/cms02/anikiten/MET_Run2012C-11Dec2012/VBFHinvis_*.root");
    chain->Add("/vols/cms02/anikiten/MET_Run2012D-PromptReco-v1/VBFHinvis_*.root");
    */

    chain->Add("/vols/cms02/anikiten/MET_Run2012A-13Jul2012_Type1/VBFHinvis_*.root");
    chain->Add("/vols/cms02/anikiten/MET_Run2012A-06Aug2012_Type1/VBFHinvis_*.root");
    chain->Add("/vols/cms02/anikiten/MET_Run2012B-13Jul2012_Type1/VBFHinvis_*.root");
    chain->Add("/vols/cms02/anikiten/MET_Run2012C-24Aug2012_Type1/VBFHinvis_*.root");
    chain->Add("/vols/cms02/anikiten/MET_Run2012C-PromptReco-v2_Type1/VBFHinvis_*.root");
    chain->Add("/vols/cms02/anikiten/MET_Run2012C-11Dec2012_Type1/VBFHinvis_*.root");
    chain->Add("/vols/cms02/anikiten/MET_Run2012D-PromptReco-v1_Type1/VBFHinvis_*.root");

    //    chain->Add("/vols/cms02/anikiten/MET_Run2012D-PromptReco-v1_MCMET/VBFHinvis_*.root");

    //    chain->Add("/vols/cms02/anikiten/MET_Run2012D-PromptReco-v1_Synch/VBFHinvis_*.root");

    tree = chain;
  }

   Init(tree);
}

VBFHinvisQCD::~VBFHinvisQCD()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t VBFHinvisQCD::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t VBFHinvisQCD::LoadTree(Long64_t entry)
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

void VBFHinvisQCD::Init(TTree *tree)
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
   mutrkisol = 0;
   mupfisol = 0;
   mucharge = 0;
   muid = 0;
   EtaEl = 0;
   PhiEl = 0;
   PtEl = 0;
   eltrkisol = 0;
   elcharge = 0;
   elid = 0;
   EtaRaw = 0;
   PhiRaw = 0;
   EtRaw = 0;
   EtaJPT = 0;
   PhiJPT = 0;
   EtJPT = 0;
   MVAJPT = 0;
   Ntrk = 0;
   jesunc = 0;
   beta = 0;
   EtaPF = 0;
   PhiPF = 0;
   EtPF = 0;
   MVAPF = 0;
   IDPF = 0;
   JTypePF = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("event", &event, &b_event);
   fChain->SetBranchAddress("nvertex", &nvertex, &b_nvertex);
   fChain->SetBranchAddress("nsimvertex", &nsimvertex, &b_nsimvertex);
   fChain->SetBranchAddress("f1", &f1, &b_f1);
   fChain->SetBranchAddress("f2", &f2, &b_f2);
   fChain->SetBranchAddress("f3", &f3, &b_f3);
   fChain->SetBranchAddress("f4", &f4, &b_f4);
   fChain->SetBranchAddress("f5", &f5, &b_f5);
   fChain->SetBranchAddress("L1ETM40", &L1ETM40, &b_L1ETM40);
   fChain->SetBranchAddress("VBF_AllJets", &VBF_AllJets, &b_VBF_AllJets);
   fChain->SetBranchAddress("DoubleMu7", &DoubleMu7, &b_DoubleMu7);
   fChain->SetBranchAddress("Mu13_Mu8", &Mu13_Mu8, &b_Mu13_Mu8);
   fChain->SetBranchAddress("Mu17_Mu8", &Mu17_Mu8, &b_Mu17_Mu8);
   fChain->SetBranchAddress("Mu17_TkMu8", &Mu17_TkMu8, &b_Mu17_TkMu8);
   fChain->SetBranchAddress("DZmin", &DZmin, &b_DZmin);
   fChain->SetBranchAddress("PVx", &PVx, &b_PVx);
   fChain->SetBranchAddress("PVy", &PVy, &b_PVy);
   fChain->SetBranchAddress("PVz", &PVz, &b_PVz);
   fChain->SetBranchAddress("pfmet", &pfmet, &b_pfmet);
   fChain->SetBranchAddress("pfmetType1", &pfmetType1, &b_pfmetType1);
   fChain->SetBranchAddress("mass_mumu", &mass_mumu, &b_mass_mumu);
   fChain->SetBranchAddress("EtaMu", &EtaMu, &b_EtaMu);
   fChain->SetBranchAddress("PhiMu", &PhiMu, &b_PhiMu);
   fChain->SetBranchAddress("PtMu", &PtMu, &b_PtMu);
   fChain->SetBranchAddress("dzmuon", &dzmuon, &b_dzmuon);
   fChain->SetBranchAddress("mutrkisol", &mutrkisol, &b_mutrkisol);
   fChain->SetBranchAddress("mupfisol", &mupfisol, &b_mupfisol);
   fChain->SetBranchAddress("mucharge", &mucharge, &b_mucharge);
   fChain->SetBranchAddress("muid", &muid, &b_muid);
   fChain->SetBranchAddress("mass_ee", &mass_ee, &b_mass_ee);
   fChain->SetBranchAddress("EtaEl", &EtaEl, &b_EtaEl);
   fChain->SetBranchAddress("PhiEl", &PhiEl, &b_PhiEl);
   fChain->SetBranchAddress("PtEl", &PtEl, &b_PtEl);
   fChain->SetBranchAddress("eltrkisol", &eltrkisol, &b_eltrkisol);
   fChain->SetBranchAddress("elcharge", &elcharge, &b_elcharge);
   fChain->SetBranchAddress("elid", &elid, &b_elid);
   fChain->SetBranchAddress("EtaRaw", &EtaRaw, &b_EtaRaw);
   fChain->SetBranchAddress("PhiRaw", &PhiRaw, &b_PhiRaw);
   fChain->SetBranchAddress("EtRaw", &EtRaw, &b_EtRaw);
   fChain->SetBranchAddress("EtaJPT", &EtaJPT, &b_EtaJPT);
   fChain->SetBranchAddress("PhiJPT", &PhiJPT, &b_PhiJPT);
   fChain->SetBranchAddress("EtJPT", &EtJPT, &b_EtJPT);
   fChain->SetBranchAddress("MVAJPT", &MVAJPT, &b_MVAJPT);
   fChain->SetBranchAddress("Ntrk", &Ntrk, &b_Ntrk);
   fChain->SetBranchAddress("jesunc", &jesunc, &b_jesunc);
   fChain->SetBranchAddress("beta", &beta, &b_beta);
   fChain->SetBranchAddress("n_trk1GeV", &n_trk1GeV, &b_n_trk1GeV);
   fChain->SetBranchAddress("n_trk2GeV", &n_trk2GeV, &b_n_trk2GeV);
   fChain->SetBranchAddress("n_trk3GeV", &n_trk3GeV, &b_n_trk3GeV);
   fChain->SetBranchAddress("EtaPF", &EtaPF, &b_EtaPF);
   fChain->SetBranchAddress("PhiPF", &PhiPF, &b_PhiPF);
   fChain->SetBranchAddress("EtPF", &EtPF, &b_EtPF);
   fChain->SetBranchAddress("MVAPF", &MVAPF, &b_MVAPF);
   fChain->SetBranchAddress("IDPF", &IDPF, &b_IDPF);
   fChain->SetBranchAddress("JTypePF", &JTypePF, &b_JTypePF);
   Notify();
}

Bool_t VBFHinvisQCD::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void VBFHinvisQCD::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t VBFHinvisQCD::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef VBFHinvisQCD_cxx
