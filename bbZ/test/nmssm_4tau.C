#define nmssm_4tau_cxx
#include "nmssm_4tau.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

Double_t nmssm_4tau::deltaPhi(Double_t phi1, Double_t phi2)
{
  Double_t pi = 3.1415927;
  Double_t dphi = fabs(phi1 - phi2);
  if(dphi >= pi) dphi = 2. * pi - dphi; 
  return dphi;
}

Double_t nmssm_4tau::deltaEta(Double_t eta1, Double_t eta2)
{
  Double_t deta = fabs(eta1 - eta2);
  return deta;
}

Double_t nmssm_4tau::deltaR(Double_t eta1, Double_t phi1, Double_t eta2, Double_t phi2)
{
  Double_t deta = deltaEta(eta1, eta2);
  Double_t dphi = deltaPhi(phi1, phi2);
  Double_t dr = sqrt(deta*deta + dphi*dphi);
  return dr;
}


void nmssm_4tau::Loop()
{
//   In a ROOT session, you can do:
//      Root > .L nmssm_4tau.C
//      Root > nmssm_4tau t
//      Root > t.GetEntry(12); // Fill t data members with entry number 12
//      Root > t.Show();       // Show values of entry 12
//      Root > t.Show(16);     // Read and show values of entry 16
//      Root > t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

   TH1F * hPtMu1   = new TH1F( "hPtMu1", "PtMu1", 50, 0., 100.);
   TH1F * hEtaMu1  = new TH1F( "hEtaMu1", "EtaMu1", 50, -5.0, 5.0);
   TH1F * hPtMu2   = new TH1F( "hPtMu2", "PtMu2", 50, 0., 100.);
   TH1F * hEtaMu2  = new TH1F( "hEtaMu2", "EtaMu2", 50, -5.0, 5.0);
   TH1F * hPtTauH  = new TH1F( "hPtTauH", "PtTauH", 50, 0., 100.);
   TH1F * hEtaTauH = new TH1F( "hEtaTauH", "EtaTauH", 50, -5.0, 5.0);

   TH2F * hDrMuMuTauHTauH = new TH2F( "hDrMuMuTauHTauH", "DrMuMuTauHTauH",
				      50, 0., 5.0, 50, 0.,5.0);
   TH2F * hDrMuTauHMuTauH = new TH2F( "hDrMuTauHMuTauH", "DrMuTauHMuTauH",
				      50, 0., 5.0, 50, 0.,5.0);

   TH1F * hDrMuTau1st  = new TH1F( "hDrMuTau1st", "DrMuTau1st", 50, 0., 5.0);
   TH1F * hDrMuTau2nd  = new TH1F( "hDrMuTau2nd", "DrMuTau2nd", 50, 0., 5.0);

   int ntot        = 0;
   int nsel_mu     = 0;
   int nsel_tau    = 0;
   int nsel_drmumu = 0;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      
      ntot += 1;

      double pt1  = 0.;
      double eta1 = 0.;
      double pt2  = 0.;
      double eta2 = 0;
      if(ptmu1 > ptmu2 ) {
	pt1  = ptmu1;
	eta1 = etamu1;
	pt2  = ptmu2;
	eta2 = etamu2;
      } else {
	pt1  = ptmu2;
	eta1 = etamu2;
	pt2  = ptmu1;
	eta2 = etamu1;
      }

      /*
      cout <<" ptmu1 = " << ptmu1
	   <<" etamu1 = " << etamu1
	   <<" ptmu2 = " << ptmu2
	   <<" etamu2 = " << etamu2
	   <<" pt1 = " << pt1
	   <<" eta1 = " << eta1
	   <<" pt2 = " << pt2
	   <<" eta2 = " << eta2 << endl;
      */

      hPtMu1->Fill(pt1);
      hEtaMu1->Fill(eta1);
      hPtMu2->Fill(pt2);
      hEtaMu2->Fill(eta2);

      hPtTauH->Fill(pttauh1);
      hEtaTauH->Fill(etatauh1);
      hPtTauH->Fill(pttauh2);
      hEtaTauH->Fill(etatauh2);

      double DrMu1Mu2 = deltaR(etamu1,phimu1,etamu2,phimu2);
      double DrTauH1TauH2 = deltaR(etatauh1,phitauh1,etatauh2,phitauh2);

      double DrMu1TauH1  = deltaR(etamu1,phimu1,etatauh1,phitauh1);
      double DrMu1TauH2  = deltaR(etamu1,phimu1,etatauh2,phitauh2);
      double DrMuTauH1st = 0;
      double DrMuTauH2nd = 0;
      if(DrMu1TauH1 < DrMu1TauH2) {
	DrMuTauH1st = DrMu1TauH1;
	DrMuTauH2nd = deltaR(etamu2,phimu2,etatauh2,phitauh2);
      } else {
	DrMuTauH1st = DrMu1TauH2;
	DrMuTauH2nd = deltaR(etamu2,phimu2,etatauh1,phitauh1);
      }

      if(pt1 < 17 || fabs(eta1) > 2.1 || pt2 < 10 || fabs(eta2) > 2.4) {continue;}
      //      if(pt1 < 8 || fabs(eta1) > 2.1 || pt2 < 8 || fabs(eta2) > 2.4) {continue;}
      nsel_mu += 1;
      if(pttauh1 < 10 || fabs(etatauh1) > 2.4 || pttauh2 < 10 || fabs(etatauh2) > 2.4) {continue;}
      nsel_tau += 1;

      hDrMuMuTauHTauH->Fill(DrMu1Mu2,DrTauH1TauH2);
      hDrMuTauHMuTauH->Fill(DrMuTauH1st,DrMuTauH2nd);

      if(DrMu1Mu2 < 1.0) {continue;}
      nsel_drmumu += 1;

      hDrMuTau1st->Fill(DrMuTauH1st);
      hDrMuTau2nd->Fill(DrMuTauH2nd);

   }

   double eff = 1.*nsel_drmumu/ntot;

   cout <<" ntot = " << ntot << endl;
   cout <<" nsel_mu = " << nsel_mu << endl;
   cout <<" nsel_tau = " << nsel_tau << endl;
   cout <<" nsel_drmumu = " << nsel_drmumu << endl;
   cout <<" ===> eff = " << eff << endl;

   TFile efile("nmssm_4tau_mh8_histos.root","recreate");

   hPtMu1->Write();
   hEtaMu1->Write();
   hPtMu2->Write();
   hEtaMu2->Write();
   hPtTauH->Write();
   hEtaTauH->Write();
   
   hDrMuMuTauHTauH->Write();
   hDrMuTauHMuTauH->Write();

   hDrMuTau1st->Write();
   hDrMuTau2nd->Write();

   efile.Close();

}
