#define mssm_2tau2b_cxx
#include "mssm_2tau2b.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

Double_t mssm_2tau2b::deltaPhi(Double_t phi1, Double_t phi2)
{
  Double_t pi = 3.1415927;
  Double_t dphi = fabs(phi1 - phi2);
  if(dphi >= pi) dphi = 2. * pi - dphi; 
  return dphi;
}

Double_t mssm_2tau2b::deltaEta(Double_t eta1, Double_t eta2)
{
  Double_t deta = fabs(eta1 - eta2);
  return deta;
}

Double_t mssm_2tau2b::deltaR(Double_t eta1, Double_t phi1, Double_t eta2, Double_t phi2)
{
  Double_t deta = deltaEta(eta1, eta2);
  Double_t dphi = deltaPhi(phi1, phi2);
  Double_t dr = sqrt(deta*deta + dphi*dphi);
  return dr;
}


void mssm_2tau2b::Loop()
{
//   In a ROOT session, you can do:
//      Root > .L mssm_2tau2b.C
//      Root > mssm_2tau2b t
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

   TH1F * hPtMu  = new TH1F( "hPtMu", "PtMu", 20, 0., 100.);
   TH1F * hEtaMu = new TH1F( "hEtaMu", "EtaMu", 50, -5.0, 5.0);

   TH1F * hPtB   = new TH1F( "hPtB", "PtB", 20, 0., 100.);
   TH1F * hEtaB  = new TH1F( "hEtaB", "EtaB", 50, -5.0, 5.0);

   TH1F * hPtTauH   = new TH1F( "hPtTauH", "PtTauH", 20, 0., 100.);
   TH1F * hEtaTauH  = new TH1F( "hEtaTauH", "EtaTauH", 50, -5.0, 5.0);

   TH1F * hDrMuTauH  = new TH1F( "hDrMuTauH", "DrMuTauH", 25, 0., 5.0);
   TH1F * hDrBBbar   = new TH1F( "hDrBBbar", "DrBBbar", 25, 0., 5.0);

   TH1F * hDrMuTauHS  = new TH1F( "hDrMuTauHS", "DrMuTauHS", 25, 0., 5.0);
   TH1F * hDrBBbarS   = new TH1F( "hDrBBbarS", "DrBBbarS", 25, 0., 5.0);

   Int_t ntot      = 0;
   Int_t nsel_mu   = 0;
   Int_t nsel_tauh = 0;
   Int_t nsel_b    = 0;

   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;

      ntot += 1;

      hPtMu->Fill(ptmu);
      hEtaMu->Fill(etamu);
      
      hPtB->Fill(ptb1);
      hEtaB->Fill(etab1);

      //      hPtB->Fill(ptb2);
      //      hEtaB->Fill(etab2);

      hPtTauH->Fill(pttauh);
      hEtaTauH->Fill(etatauh);

      double DrMuTauH = deltaR(etamu,phimu,etatauh,phitauh);
      double DrBBbar  = deltaR(etab1,phib1,etab2,phib2);

      hDrMuTauH->Fill(DrMuTauH);
      hDrBBbar->Fill(DrBBbar);

      if(ptmu < 20. || fabs(etamu) > 2.1) {continue;}
      nsel_mu += 1;
      if(pttauh < 20. || fabs(etatauh) > 2.3) {continue;}
      nsel_tauh += 1;
      if(ptb1 < 25 || fabs(etab1) > 2.4 || ptb2 < 25 || fabs(etab2) > 2.4) {continue;}
      nsel_b += 1;

      hDrMuTauHS->Fill(DrMuTauH);
      hDrBBbarS->Fill(DrBBbar);

   }

   Double_t sigma_x_br = 60.;
   Double_t luminosity = 20.;
   Double_t tau_br = 2.*0.17*0.65;

   cout <<" ====== Selections and efficiency ============" << endl;
   cout <<"  ntot = " << ntot << endl;
   cout <<"  nsel_mu = " << nsel_mu <<" eff = " << 1.*nsel_mu/ntot << endl;
   cout <<"  nsel_tauh = " << nsel_tauh <<" eff = " << 1.*nsel_tauh/nsel_mu <<  endl;
   cout <<"  nsel_b = " << nsel_b <<" eff = " << 1.*nsel_b/nsel_tauh << endl;
   double eff = 1.*nsel_b/ntot;
   cout <<" total eff = " << eff << endl;

   cout <<"  " << endl;
   cout <<" ====== Predictions ============" << endl;
   cout <<"  ntot gg->H->hh->2tau2b = " << sigma_x_br*luminosity  << endl;
   cout <<" tau->mu, tau->hadr = " << sigma_x_br*luminosity*tau_br << endl;
   cout <<"  nsel_mu = " << (1.*nsel_mu/ntot)*sigma_x_br*luminosity*tau_br << endl;
   cout <<"  nsel_tauh = " << (1.*nsel_tauh/ntot)*sigma_x_br*luminosity*tau_br <<  endl;
   cout <<"  nsel_b = " << (1.*nsel_b/ntot)*sigma_x_br*luminosity*tau_br << endl;

   


   TFile efile("mssm_2tau2b_mH300_histos.root","recreate");

   hPtMu->Write();
   hEtaMu->Write();
   
   hPtB->Write();
   hEtaB->Write();
   
   hPtTauH->Write();
   hEtaTauH->Write();
   
   hDrMuTauH->Write();
   hDrBBbar->Write();

   hDrMuTauHS->Write();
   hDrBBbarS->Write();

   efile.Close();
}
