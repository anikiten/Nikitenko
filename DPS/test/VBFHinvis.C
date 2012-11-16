#define VBFHinvis_cxx
#include "VBFHinvis.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

Double_t VBFHinvis::deltaPhi(Double_t phi1, Double_t phi2)
{
  Double_t pi = 3.1415927;
  Double_t dphi = fabs(phi1 - phi2);
  if(dphi >= pi) dphi = 2. * pi - dphi; 
  return dphi;
}

Double_t VBFHinvis::deltaEta(Double_t eta1, Double_t eta2)
{
  Double_t deta = fabs(eta1 - eta2);
  return deta;
}

Double_t VBFHinvis::deltaR(Double_t eta1, Double_t phi1, Double_t eta2, Double_t phi2)
{
  Double_t deta = deltaEta(eta1, eta2);
  Double_t dphi = deltaPhi(phi1, phi2);
  Double_t dr = sqrt(deta*deta + dphi*dphi);
  return dr;
}

void VBFHinvis::Loop()
{
//   In a ROOT session, you can do:
//      Root > .L VBFHinvis.C
//      Root > VBFHinvis t
//      Root > t.GetEntry(12); // Fill t data members with entry number 12
//      Root > t.Show();       // Show values of entry 12
//      Root > t.Show(16);     // Read and show values of entry 16
//      Root > t.Loop();       // Loop on all entries
//

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

   // selections

   TH1F * hPtJ1   = new TH1F( "hPtJ1", "PtJ1", 30, 0., 150.);
   TH1F * hPtJ2   = new TH1F( "hPtJ2", "PtJ2", 30, 0., 150.);
   TH1F * hEtaJ1  = new TH1F( "hEtaJ1", "EtaJ1", 50, -5.0, 5.0);
   TH1F * hEtaJ2  = new TH1F( "hEtaJ2", "EtaJ2", 50, -5.0, 5.0);
   TH1F * hmJJ    = new TH1F( "hmJJ", "mJJ", 40, 0., 2000.);

   TH2F * hDetaJJmJJ = new TH2F( "hDetaJJmJJ", "DetaJJmJJ", 50, 0., 10.,40,0.,2000.);

   TH1F * hDphiJJ        = new TH1F( "hDphiJJ", "DphiJJ", 17, 0., 3.4);
   TH1F * hDphiJJmJJ300  = new TH1F( "hDphiJJmJJ300", "DphiJJmJJ300", 17, 0., 3.4);
   TH1F * hDphiJJmJJ500  = new TH1F( "hDphiJJmJJ500", "DphiJJmJJ500", 17, 0., 3.4);
   TH1F * hDphiJJDetaJJ2 = new TH1F( "hDphiJJDetaJJ2", "DphiJJDetaJJ2", 17, 0., 3.4);
   TH1F * hDphiJJDetaJJ3 = new TH1F( "hDphiJJDetaJJ3", "DphiJJDetaJJ3", 17, 0., 3.4);

   Long64_t nentries = fChain->GetEntriesFast();
   Long64_t nbytes = 0, nb = 0;

   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      //      break;
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;

      // if (Cut(ientry) < 0) continue;

      //      cout <<" run number = " << run << endl;

      // jet
      Int_t njets = EtJPT->size();
      if(njets < 2) {continue;}
      
      Double_t pTj1 = (*EtJPT)[0];
      Double_t pTj2 = (*EtJPT)[1];

      if(pTj1 <= 50. || pTj2 <= 50.) {continue;}

      Double_t DphiJJ = deltaPhi((*PhiJPT)[0],(*PhiJPT)[1]);
      Double_t DetaJJ = deltaEta((*EtaJPT)[0],(*EtaJPT)[1]);

      // Mj1j2 calculations
      Double_t PJ1x = pTj1 * cos((*PhiJPT)[0]); 
      Double_t PJ1y = pTj1 * sin((*PhiJPT)[0]);
      Double_t Eta = (*EtaJPT)[0];
      Double_t theta = 2. * atan(exp(-Eta));
      Double_t PJ1z = pTj1 / tan(theta);
      Double_t EJ1  = pTj1 / sin(theta);

      Double_t PJ2x = pTj2 * cos((*PhiJPT)[1]); 
      Double_t PJ2y = pTj2 * sin((*PhiJPT)[1]);
      Eta = (*EtaJPT)[1];
      theta = 2. * atan(exp(-Eta));
      Double_t PJ2z = pTj2 / tan(theta);
      Double_t EJ2  = pTj2 / sin(theta);
      Double_t mJJ  = sqrt( (EJ1+EJ2)*(EJ1+EJ2) 
                           - (PJ1x+PJ2x)*(PJ1x+PJ2x) 
                           - (PJ1y+PJ2y)*(PJ1y+PJ2y) 
			   - (PJ1z+PJ2z)*(PJ1z+PJ2z) ); 
      if(L1ETM40 == 1) {
	hPtJ1->Fill(pTj1);
	hPtJ2->Fill(pTj2);
	hEtaJ1->Fill((*EtaJPT)[0]); 
	hEtaJ2->Fill((*EtaJPT)[1]); 
	hmJJ->Fill(mJJ);
        hDphiJJ->Fill(DphiJJ);
        hDetaJJmJJ->Fill(DetaJJ,mJJ);
	
	if(mJJ > 300.)   {hDphiJJmJJ300->Fill(DphiJJ);}
	if(mJJ > 500.)   {hDphiJJmJJ500->Fill(DphiJJ);}

	if(DetaJJ > 2.0) {hDphiJJDetaJJ2->Fill(DphiJJ);}
	if(DetaJJ > 3.0) {hDphiJJDetaJJ3->Fill(DphiJJ);}

      }
   }

   TFile efile("VBFHinvisAnalysis.root","recreate");

   hmJJ->Write();
   hPtJ1->Write();
   hPtJ2->Write();
   hEtaJ1->Write();
   hEtaJ2->Write();
   hDphiJJ->Write();
   hDetaJJmJJ->Write();

   hDphiJJmJJ300->Write();
   hDphiJJmJJ500->Write();
   hDphiJJDetaJJ2->Write();
   hDphiJJDetaJJ3->Write();

   efile.Close();
}
