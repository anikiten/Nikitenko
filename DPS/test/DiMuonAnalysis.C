#define DiMuonAnalysis_cxx
#include "DiMuonAnalysis.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

Double_t DiMuonAnalysis::deltaPhi(Double_t phi1, Double_t phi2)
{
  Double_t pi = 3.1415927;
  Double_t dphi = fabs(phi1 - phi2);
  if(dphi >= pi) dphi = 2. * pi - dphi; 
  return dphi;
}

Double_t DiMuonAnalysis::deltaEta(Double_t eta1, Double_t eta2)
{
  Double_t deta = fabs(eta1 - eta2);
  return deta;
}

Double_t DiMuonAnalysis::deltaR(Double_t eta1, Double_t phi1, Double_t eta2, Double_t phi2)
{
  Double_t deta = deltaEta(eta1, eta2);
  Double_t dphi = deltaPhi(phi1, phi2);
  Double_t dr = sqrt(deta*deta + dphi*dphi);
  return dr;
}

void DiMuonAnalysis::Loop()
{
//   In a ROOT session, you can do:
//      Root > .L DiMuonAnalysis.C
//      Root > DiMuonAnalysis t
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

   // vertex reweighting

   Double_t puweight[100];

   //   TFile fd("MyDataPileupHistogramA.root");
   TFile fd("MyDataPileupHistogramB.root");
   TH1D *pileup = (TH1D*)fd.Get("pileup");
   pileup->Draw();
   Double_t nvtx_data[100];
   Double_t nvtx_mc[100];
   for (Int_t id = 0; id < 100; id++) {
     if(id < 50) {
       nvtx_data[id] = pileup->GetBinContent(id+1);
     } else {
       nvtx_data[id] = 0.;
     }
     std::cout <<" data bin id = " << id <<"  bin content = " << nvtx_data[id] << endl; 
   }

   //   TFile fm("MCPileupHistogram.root");
   TFile fm("MCSignalPileuHistogram.root");
   pileup = (TH1D*)fm.Get("pileup");
   pileup->Draw();
   for (Int_t im = 0; im < 100; im++) {
     if(im < 50) {
       nvtx_mc[im] = pileup->GetBinContent(im+1);
     } else {
       nvtx_mc[im] = 0.;
     }
     std::cout <<" MC bin im = " << im <<"  bin content = " << nvtx_mc[im] << endl; 
   }

   // for MC
   for (Int_t idm = 0; idm < 100; idm++) {
     if(nvtx_mc[idm] != 0) {
       puweight[idm] =  nvtx_data[idm] /  nvtx_mc[idm]; 
     } else {
       puweight[idm] = 0.;
     }
     std::cout <<" bin idm = " << idm <<"  data = " << nvtx_data[idm] <<" mc = " << nvtx_mc[idm] <<" ratio = " << puweight[idm] << endl; 
   }

   /*
   // for data
   for (Int_t idm = 0; idm < 100; idm++) {
     puweight[idm] = 1.0;
     std::cout <<" Weights for data analysis (1)" << puweight[idm] << endl; 
   }
   */

   // selections
   TH1F * hZY              = new TH1F( "hZY", "ZY", 30, -3., 3.);
   TH1F * hZY2J            = new TH1F( "hZY2J", "ZY2J", 30, -3., 3.);
   TH1F * hZY2JDeta0       = new TH1F( "hZY2JDeta0", "ZY2JDeta0", 30, -3., 3.);
   TH1F * hZY2JDeta1       = new TH1F( "hZY2JDeta1", "ZY2JDeta1", 30, -3., 3.);
   TH1F * hZY2JDetaMjj     = new TH1F( "hZY2JDetaMjj", "ZY2JDetaMjj", 30, -3., 3.);
   TH1F * hZY2JDetaMjjCJV  = new TH1F( "hZY2JDetaMjjCJV", "ZY2JDetaMjjCJV", 30, -3., 3.);
   //

   TH1F * hnvtx0   = new TH1F( "hnvtx0", "nvtx0", 40, 0., 40.);
   TH1F * pileupMC   = new TH1F( "pileupMC", "pileupMC", 50, 0., 50.);

   // two tight muons, no Z mass window
   TH1F * hM2mu0   = new TH1F( "hM2mu0", "M2mu0", 60, 20., 140.);
   // two tight muons, inside Z mass window
   TH1F * hM2mu1   = new TH1F( "hM2mu1", "M2mu1", 60, 20., 140.);
   TH1F * hDeta0   = new TH1F( "hDeta0", "Deta0", 25, 0., 10.);
   TH1F * hDeta1   = new TH1F( "hDeta1", "Deta1", 25, 0., 10.);
   TH1F * hMjj     = new TH1F( "hMjj", "Mjj", 40, 0., 2000.);
   TH1F * hMjj4    = new TH1F( "hMjj4", "Mjj4", 40, 0., 2000.);

   TH2F * hMjjDeta     = new TH2F( "hMjjDeta", "MjjDeta", 40, 0., 2000., 25, 0., 10.);
   TH1F * hDetaMjj300500     = new TH1F( "hDetaMjj300500", "DetaMjj300500", 25, 0., 10.);
   TH1F * hDetaMjj500800     = new TH1F( "hDetaMjj500800", "DetaMjj500800", 25, 0., 10.);
   TH1F * hDetaMjjGT800       = new TH1F( "hDetaMjjGT800", "DetaMjjGT800", 25, 0., 10.);

   TH2F * hMjjEta1Eta2 = new TH2F( "hMjjEta1Eta2", "MjjEta1Eta2", 40, 0., 2000., 4, -2., 2.);

   // CJV analysis
   TH1F * hNvtxBcjv     = new TH1F( "hNvtxBcjv", "hNvtxBcjv", 10, 0., 30.);
   TH1F * hNvtxAcjv     = new TH1F( "hNvtxAcjv", "hNvtxAcjv", 10, 0., 30.);
   TH1F * hPtTagJ_25    = new TH1F( "hPtTagJ_25", "PtTagJ_25", 60, 0., 300.);
   TH1F * hPtTagJ_25_45 = new TH1F( "hPtTagJ_25_45", "PtTagJ_25_45", 60, 0., 300.);
   TH1F * hPtTagJ_45    = new TH1F( "hPtTagJ_45", "PtTagJ_45", 60, 0., 300.);
   TH1F * hEtaJmin      = new TH1F( "hEtaJmin", "EtaJmin", 25, -5.0, 5.0);
   TH1F * hEtaJmax      = new TH1F( "hEtaJmax", "EtaJmax", 25, -5.0, 5.0);
   TH1F * hPtJ3         = new TH1F( "hPtJ3", "PtJ3", 20, 0., 100.);
   TH1F * hEtaJ3        = new TH1F( "hEtaJ3", "EtaJ3", 25, -5.0, 5.0);
   TH1F * hNTrk1GeV     = new TH1F( "hNTrk1GeV", "NTrk1GeV", 30, 0.0, 30.0);
   TH1F * hNTrk2GeV     = new TH1F( "hNTrk2GeV", "NTrk2GeV", 30, 0.0, 30.0);
   TH1F * hNTrk3GeV     = new TH1F( "hNTrk3GeV", "NTrk3GeV", 30, 0.0, 30.0);


   // general stuff
   TH1F * hPtZ             = new TH1F( "hPtZ", "PtZ", 28, 0., 140.);
   TH1F * hPtZ1J           = new TH1F( "hPtZ1J", "PtZ1J", 28, 0., 140.);
   TH1F * hPtZ2J           = new TH1F( "hPtZ2J", "PtZ2J", 28, 0., 140.);
   TH1F * hZY1J            = new TH1F( "hZY1J", "ZY1J", 30, -3., 3.);
   //
   TH1F * hPtJ      = new TH1F( "hPtJ", "PtJ", 30, 0., 150.);
   TH1F * hEtaJ     = new TH1F( "hEtaJ", "EtaJ", 50, -5.0, 5.0);
   TH1F * hNjets    = new TH1F( "hNjets", "Njets", 6, 0., 6.);

   /*
   TH1F * hbeta1  = new TH1F( "hbeta1", "beta1", 25, 0., 1.0);
   TH1F * hbeta2  = new TH1F( "hbeta2", "beta2", 25, 0., 1.0);
   TH1F * hbeta3  = new TH1F( "hbeta3", "beta3", 25, 0., 1.0);

   TH1F * hNvtx01   = new TH1F( "hNvtx01", "Nvtx01", 16, 0., 16.);
   TH1F * hEtJ01    = new TH1F( "hEtJ01", "EtJ01", 30, 0., 150.);
   TH1F * hEtaJ01   = new TH1F( "hEtaJ01", "EtaJ01", 24, -2.4, 2.4);
   TH1F * hNjets01  = new TH1F( "hNjets01", "Njets01", 6, 0., 6.);
   TH1F * hPtZ01    = new TH1F( "hPtZ01", "PtZ01", 25, 0., 100.);
   TH1F * hPtZ0     = new TH1F( "hPtZ0", "PtZ0", 25, 0., 100.);

   TH1F * hDphiZJ   = new TH1F( "hDphiZJ", "DphiZJ", 16, 0., 3.2);
   TH1F * hDphiZJ01 = new TH1F( "hDphiZJ01", "DphiZJ01", 32, 0., 3.2);

   TH1F * hNtrk1    = new TH1F( "hNtrk1", "Ntrk1", 15, 0., 15);
   TH1F * hNtrk101  = new TH1F( "hNtrk101", "Ntrk101", 15, 0., 15);
   TH1F * hNtrk1g   = new TH1F( "hNtrk1g", "Ntrk1g", 15, 0., 15);
   TH1F * hNtrk3    = new TH1F( "hNtrk3", "Ntrk3", 15, 0., 15);
   TH1F * hNtrk301  = new TH1F( "hNtrk301", "Ntrk301", 15, 0., 15);
   TH1F * hNtrk3g   = new TH1F( "hNtrk3g", "Ntrk3g", 15, 0., 15);

   TH1F * hNtrkVtxG2 = new TH1F( "hNtrkVtxG2", "NtrkVtxG2", 15, 0., 15);
   TH1F * hNtrkVtxL2 = new TH1F( "hNtrkVtxL2", "NtrkVtxL2", 15, 0., 15);

   TH2F * hDzmuon1  = new TH2F( "hDzmuon1", "Dzmuon1", 200, 0., 2., 200, 0., 2.);
   TH1F * hDZmin1   = new TH1F( "hDZmin1", "DZmin1", 80, 0., 2.);
   TH1F * hDZmin2   = new TH1F( "hDZmin2", "DZmin2", 80, 0., 2.);
   TH1F * hDZmin3   = new TH1F( "hDZmin3", "DZmin3", 80, 0., 2.);

   TH1F * hNvtxL2      = new TH1F( "hNvtxL2", "NvtxL2", 16, 0., 16.);

   TH1F * hNvtxjet20   = new TH1F( "hNvtxjet20", "Nvtxjet20", 16, 0., 16.);
   TH1F * hNvtxjet25   = new TH1F( "hNvtxjet25", "Nvtxjet25", 16, 0., 16.);
   */

   Long64_t nentries = fChain->GetEntriesFast();
   Long64_t nbytes = 0, nb = 0;
   // MZ
   Double_t MZ = 91.2;
   // cuts
   Double_t pTj1cut = 30.0;
   Double_t pTj2cut = 30.0;
   Double_t Detaj1j2cut_1 = 2.5;
   Double_t Detaj1j2cut_2 = 3.5;
   Double_t Detaj1j2cut_3 = 4.0;
   Double_t Mjjcut = 600.;
   //   Double_t Mjjcut = 0.0;
   Double_t eta3_cut = 2.0;
   Double_t beta_cut = 0.2;
   //   Double_t eta3_cut = 10.0;
   //   Double_t beta_cut = -10.0;

   // muon data / mc correction factors
   // Double_t x_eta_mu[16] = {-2.4, -2.1, -1.6, -1.2, -0.9, -0.6, -0.3, -0.2, 0.2, 0.3, 0.6, 0.9, 1.2, 1.6, 2.1, 2.4};
   // Double_t corr_mu[15] = {0.977607, 0.961587, 0.964097, 0.980235, 0.997457, 1., 0.978457, 0.995915,  0.98683, 1.001, 0.99583, 0.992862, 0.97847, 0.980215, 0.987352}; 
   // even selection counters
   //
   //  total number of events processed
   Double_t N_total = 0;
   // 1. pT mu > 20 GeV, eta < 2.4
   Double_t N_muons = 0;
   // 2. mumu mass window +/- 15 GeV
   Double_t N_mass2mu = 0;
   // 3. two jets pT > 30 GeV, eta < 4.7
   Double_t N_jets = 0;
   // 4. eta_j1 x eta_j2 < 0
   Double_t N_deta0 = 0;
   // 5. Deta j1j2 > 2.5, 3.5, 4.5
   Double_t N_deta1_1 = 0;
   Double_t N_deta1_2 = 0;
   Double_t N_deta1_3 = 0;
   // 6. Mj1j2 > 700 GeV
   Double_t N_massjj_1 = 0;
   Double_t N_massjj_2 = 0;
   Double_t N_massjj_3 = 0;
   // 7. CJV
   Double_t N_cjv_1 = 0;
   Double_t N_cjv_2 = 0;
   Double_t N_cjv_3 = 0;
   // scale 0 - no error, 1 or -1 : +1/-1 sigma error
   Double_t jescale = 0.;

   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      //      break;
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;

      //      cout <<" run number = " << run << endl;

      N_total += puweight[nsimvertex];

      Int_t ngoodjets = 0;
      Int_t nalljets = 0;
      Int_t izmin = 0;
      if(DZmin < 0.2) izmin = 1;
      // di muon mass
      Int_t nmuon = PtMu->size();

      pileupMC->Fill(1.*nsimvertex,puweight[nsimvertex]);

      // Selections

      // 1. two muons
      if(nmuon < 2) {continue;}

      // pT mu > 20 GeV, |eta| < 2.4

      if( ((*PtMu)[0] < 20.) || ((*PtMu)[1] < 20.) || (fabs((*EtaMu)[0]) > 2.4) || (fabs((*EtaMu)[1]) > 2.4) ) {continue;}
      if( ((*muisol)[0]/(*PtMu)[0] > 0.1) || ((*muisol)[1]/(*PtMu)[1] > 0.1)) {continue;}
      if( DoubleMu7 == 0 && Mu13_Mu8 == 0 && Mu17_Mu8 == 0) {continue;}
      //      if(nvertex > 2) {continue;}

      N_muons += puweight[nsimvertex];

      hM2mu0->Fill(mass_mumu,puweight[nsimvertex]);
      hnvtx0->Fill(1.*nvertex,puweight[nsimvertex]);


      // M_mumu MZ +- 15 GeV
      if( fabs(MZ-mass_mumu) > 15.0) {continue;}
      N_mass2mu += puweight[nsimvertex];

      Int_t smallbeta = 0;
      Int_t jet25 = 0;
      Int_t njets = EtJPT->size();
      // muons
      Double_t PtZx = 0.;
      Double_t PtZy = 0.;
      Double_t PZz  = 0.;
      Double_t DphiZJ = 0.;
      //      hDzmuon1->Fill((*dzmuon)[0],(*dzmuon)[1]);  
      for (unsigned int j = 0; j < nmuon; j++) {
	if(j < 2) {
	  PtZx += (*PtMu)[j] * cos((*PhiMu)[j]); 
	  PtZy += (*PtMu)[j] * sin((*PhiMu)[j]);
	  Double_t Eta = (*EtaMu)[j];
	  Double_t theta = 2. * atan(exp(-Eta));
	  PZz  += (*PtMu)[j] / tan(theta);
	}
      }

      Double_t PtZ  = sqrt(PtZx*PtZx + PtZy*PtZy);
      Double_t PhiZ = atan2(PtZy, PtZx);
      Double_t EZ = sqrt(MZ*MZ + PtZ*PtZ + PZz*PZz);
      Double_t ZY   = 0.5 * log( (EZ+PZz) / (EZ-PZz));

      hM2mu1->Fill(mass_mumu,puweight[nsimvertex]);
      hZY->Fill(ZY,puweight[nsimvertex]);
      hPtZ->Fill(PtZ,puweight[nsimvertex]); 

      // jet
      for (unsigned int i = 0; i < njets; i++) {

	Double_t pTj = (*EtJPT)[i] + jescale*(*jesunc)[i]*(*EtJPT)[i];

	if( pTj >= pTj2cut && fabs((*EtaJPT)[i]) < 4.7 ) {
	  nalljets = nalljets + 1;
	  hPtJ->Fill(pTj,puweight[nsimvertex]);
	  hEtaJ->Fill((*EtaJPT)[i],puweight[nsimvertex]);
	}
      }
      
      hNjets->Fill(1.*nalljets,puweight[nsimvertex]);

      if(nalljets >= 1) {
	
	hPtZ1J->Fill(PtZ,puweight[nsimvertex]);
	hZY1J->Fill(ZY,puweight[nsimvertex]);

      }

      // VBF part
      double pTj1 = 0.;
      double pTj2 = 0.;

      if(njets < 2) {continue;}
      
      pTj1 = (*EtJPT)[0] + jescale*(*jesunc)[0]*(*EtJPT)[0];
      pTj2 = (*EtJPT)[1] + jescale*(*jesunc)[1]*(*EtJPT)[1];

      //      cout <<"  Etj1 = " << (*EtJPT)[0] <<" jesunc1 = " << (*jesunc)[0] <<" pTj1 = " << pTj1 << endl;
      //      cout <<"  Etj2 = " << (*EtJPT)[1] <<" jesunc2 = " << (*jesunc)[1] <<" pTj2 = " << pTj2 << endl;

      if( ( pTj1 < pTj1cut ) || 
          ( pTj2 < pTj2cut ) || 
	  ( fabs((*EtaJPT)[0]) > 4.7 ) || 
	  ( fabs((*EtaJPT)[1]) > 4.7 ) ) {continue;}

      N_jets += puweight[nsimvertex];
      hPtZ2J->Fill(PtZ,puweight[nsimvertex]);
      hZY2J->Fill(ZY,puweight[nsimvertex]);

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
      Double_t Mj1j2 = sqrt( (EJ1+EJ2)*(EJ1+EJ2) - (PJ1x+PJ2x)*(PJ1x+PJ2x) - (PJ1y+PJ2y)*(PJ1y+PJ2y) - (PJ1z+PJ2z)*(PJ1z+PJ2z) ); 

      // VBF jets with max and min rapidity
      Double_t eta_jmin = (*EtaJPT)[0]; 
      Double_t eta_jmax = (*EtaJPT)[1]; 
      if( (*EtaJPT)[0] > (*EtaJPT)[1] ) {
	eta_jmin = (*EtaJPT)[1]; 
	eta_jmax = (*EtaJPT)[0]; 
      }
      //
      Double_t signEta1Eta2 = -1.;
      if( ( (*EtaJPT)[0] * (*EtaJPT)[1] > 0.0 ) ) {signEta1Eta2 = 1.;} 
      Double_t DetaJJ = fabs((*EtaJPT)[0]-(*EtaJPT)[1]);
      hDeta0->Fill(DetaJJ,puweight[nsimvertex]);
      hMjjDeta->Fill(Mj1j2,DetaJJ,puweight[nsimvertex]);

      if(Mj1j2 > 300. && Mj1j2 <= 500.) {hDetaMjj300500->Fill(DetaJJ,puweight[nsimvertex]);}
      if(Mj1j2 > 500. && Mj1j2 <= 800.) {hDetaMjj500800->Fill(DetaJJ,puweight[nsimvertex]);}
      if(Mj1j2 > 800.)                  {hDetaMjjGT800->Fill(DetaJJ,puweight[nsimvertex]);}

      hMjjEta1Eta2->Fill(Mj1j2,signEta1Eta2,puweight[nsimvertex]);

      if( ( (*EtaJPT)[0] * (*EtaJPT)[1] > 0.0 ) ) {continue;} 
      N_deta0 += puweight[nsimvertex];
      hDeta1->Fill(DetaJJ,puweight[nsimvertex]);
      hZY2JDeta0->Fill(ZY,puweight[nsimvertex]);

      if( DetaJJ < Detaj1j2cut_1 ) {continue;}
      N_deta1_1 += puweight[nsimvertex];
      hZY2JDeta1->Fill(ZY,puweight[nsimvertex]);
      hMjj->Fill(Mj1j2,puweight[nsimvertex]);

      if(Mj1j2 > Mjjcut) {

	hPtTagJ_25->Fill(pTj1,puweight[nsimvertex]);
	hPtTagJ_25->Fill(pTj2,puweight[nsimvertex]);

	if(DetaJJ < Detaj1j2cut_3) {
	  hPtTagJ_25_45->Fill(pTj1,puweight[nsimvertex]);
	  hPtTagJ_25_45->Fill(pTj2,puweight[nsimvertex]);
	}

	N_massjj_1 += puweight[nsimvertex];
	hZY2JDetaMjj->Fill(ZY,puweight[nsimvertex]);
	
	// CJV part
	Int_t ncj = 0;
	for (unsigned int i = 0; i < njets; i++) {
	  if(i < 2 ) {continue;}
	  if( (fabs((*EtaJPT)[i]) < eta3_cut) && ((*beta)[i] > beta_cut) ) {
	    if( eta_jmin < (*EtaJPT)[i]  && (*EtaJPT)[i] < eta_jmax ) {
	      ncj++;
	      if(ncj == 1) {
	      }
	    }
	  }
	}
	
	if(ncj == 0) {
	  N_cjv_1 += puweight[nsimvertex];
	  hZY2JDetaMjjCJV->Fill(ZY,puweight[nsimvertex]);
	}
      }

      // Deta > 3.5
      if( DetaJJ < Detaj1j2cut_2 ) {continue;}
      N_deta1_2 += puweight[nsimvertex];
     
      if(Mj1j2 > Mjjcut) {
	N_massjj_2 += puweight[nsimvertex];
	hNvtxBcjv->Fill(1.*nvertex,puweight[nsimvertex]);
	hNTrk1GeV->Fill(n_trk1GeV, puweight[nsimvertex]);
	hNTrk2GeV->Fill(n_trk2GeV, puweight[nsimvertex]);
	hNTrk3GeV->Fill(n_trk3GeV, puweight[nsimvertex]);
	
	// CJV part
	Int_t ncj = 0;
	for (unsigned int i = 0; i < njets; i++) {
	  if(i < 2 ) {continue;}
	  if( (fabs((*EtaJPT)[i]) < eta3_cut) && ((*beta)[i] > beta_cut) ) {
	    if( eta_jmin < (*EtaJPT)[i]  && (*EtaJPT)[i] < eta_jmax ) {
	      ncj++;
	      if(ncj == 1) {
	      }
	    }
	  }
	}

	if(ncj == 0) {
	  hNvtxAcjv->Fill(1.*nvertex,puweight[nsimvertex]);
	  N_cjv_2 += puweight[nsimvertex];
	}
      }

      // Deta > 4.5 
      if( DetaJJ < Detaj1j2cut_3 ) {continue;}

      hMjj4->Fill(Mj1j2,puweight[nsimvertex]);

      N_deta1_3 += puweight[nsimvertex];

      if(Mj1j2 > Mjjcut) {

	hPtTagJ_45->Fill(pTj1,puweight[nsimvertex]);
	hPtTagJ_45->Fill(pTj2,puweight[nsimvertex]);

	N_massjj_3 += puweight[nsimvertex];

	// CJV part
	hEtaJmin->Fill(eta_jmin,puweight[nsimvertex]);
	hEtaJmax->Fill(eta_jmax,puweight[nsimvertex]);
	Int_t ncj = 0;
	for (unsigned int i = 0; i < njets; i++) {
	  if(i < 2 ) {continue;}
	  if( (fabs((*EtaJPT)[i]) < eta3_cut) && ((*beta)[i] > beta_cut) ) {
	    if( eta_jmin < (*EtaJPT)[i]  && (*EtaJPT)[i] < eta_jmax ) {
	      ncj++;
	      if(ncj == 1) {
		hPtJ3->Fill((*EtJPT)[i],puweight[nsimvertex]);
		hEtaJ3->Fill((*EtaJPT)[i],puweight[nsimvertex]);
	      }
	    }
	  }
	}
	
	if(ncj == 0) {
	  N_cjv_3 += puweight[nsimvertex];
	}
      }

      /*
      // 
      if(nalljets == 0 && ngoodjets == 0) {hPtZ0->Fill(PtZ);}

      if(ngoodjets != 0) {

	hNjets->Fill(1.*ngoodjets);
	hNvtx->Fill(1.*nvertex);

	if(smallbeta == 0) {
	  hNvtxjet20->Fill(1.*nvertex);
	  if(jet25 == 1) {hNvtxjet25->Fill(1.*nvertex);}
	}

	if(izmin == 1) {hNvtxL2->Fill(1.*nvertex);}

	if(nalljets == 1 && ngoodjets == 1) {
	  hPtZ->Fill(PtZ);
	  hDphiZJ->Fill(DphiZJ);
	}

	if( smallbeta == 1) {

	  hNvtx01->Fill(1.*nvertex);
	  hNjets01->Fill(1.*ngoodjets);

	  if(nalljets == 1 && ngoodjets == 1) {
	    hPtZ01->Fill(PtZ);
	    hDphiZJ01->Fill(DphiZJ);
	  }
	}

	if(nvertex == 2) {
	  hDZmin1->Fill(DZmin);
	}  
	if (nvertex == 5 || nvertex == 6) {
	  hDZmin2->Fill(DZmin);
	} 
	if (nvertex > 7) {
	  hDZmin3->Fill(DZmin);
	} 

      }
      */
   }
   // selections summary
   std::cout <<"===> Total number of events analysed - " << N_total << endl;
   std::cout <<"===--> passed muon pT/eta selections - " << N_muons << endl;
   std::cout <<"===--> passed di-muon mass window    - " << N_mass2mu << endl;
   std::cout <<"===--> passed two jet selections     - " << N_jets << endl;  
   std::cout <<"===--> passed eta_j1 x eta_j2 cut    - " << N_deta0 << endl;
   std::cout <<"===--> passed Detaj1j2 cut           - " << N_deta1_1 <<" "<< N_deta1_2 <<" "<< N_deta1_3 << endl;
   std::cout <<"===--> passed Mj1j2 cut              - " << N_massjj_1 <<" "<< N_massjj_2 <<" "<< N_massjj_3 << endl;
   std::cout <<"===--> passed CVJ                    - " << N_cjv_1 <<" "<< N_cjv_2 <<" "<< N_cjv_3 << endl;

   std::cout <<"----------------------------------" << endl;
   std::cout <<" efficiency of CJV " << endl;
   std::cout <<" Deta > " << Detaj1j2cut_1 <<" CJV eff = " << N_cjv_1/N_massjj_1 << endl;
   std::cout <<" Deta > " << Detaj1j2cut_2 <<" CJV eff = " << N_cjv_2/N_massjj_2 << endl;
   std::cout <<" Deta > " << Detaj1j2cut_3 <<" CJV eff = " << N_cjv_3/N_massjj_3 << endl;

   std::cout <<"----------------------------------" << endl;
   std::cout <<" cuts used: " << endl;
   std::cout <<" pTj1cut, pTj2cut  > " << pTj1cut <<"  " << pTj2cut << endl;
   std::cout <<" Detaj1j2cut_1, Detaj1j2cut_2, Detaj1j2cut_3  > " 
	     << Detaj1j2cut_1 <<"  " << Detaj1j2cut_2 <<" " << Detaj1j2cut_3 << endl;
   std::cout <<" Mjjcut > " << Mjjcut << endl;
   std::cout <<" eta3 < " << eta3_cut <<" beta > " << beta_cut << endl;
  
   TFile efile("DYhistos.root","recreate");

   hnvtx0->Write();   
   pileupMC->Write();   
   hM2mu0->Write();
   hM2mu1->Write();
   hDeta0->Write();
   hDeta1->Write();
   hMjj->Write();
   hMjj4->Write();

   hMjjDeta->Write();
   hDetaMjj300500->Write();
   hDetaMjj500800->Write();
   hDetaMjjGT800->Write();

   hMjjEta1Eta2->Write();

   hPtZ->Write();
   hPtZ1J->Write();
   hZY1J->Write();
   hPtZ2J->Write();
   hNjets->Write();
   hPtJ->Write();
   hEtaJ->Write();
   // event selections
   hZY->Write();
   hZY2J->Write();
   hZY2JDeta0->Write();
   hZY2JDeta1->Write();
   hZY2JDetaMjj->Write();
   hZY2JDetaMjjCJV->Write();

   // CJV
   hEtaJmin->Write();
   hEtaJmax->Write();
   hPtJ3->Write();
   hEtaJ3->Write();
   hNvtxAcjv->Write();
   hNvtxBcjv->Write();
   hPtTagJ_25->Write();
   hPtTagJ_25_45->Write();
   hPtTagJ_45->Write();
   hNTrk1GeV->Write();
   hNTrk2GeV->Write();
   hNTrk3GeV->Write();

   efile.Close();

   //   setTDRStyle(0,1,0);
   /*
   TCanvas* c1 = new TCanvas("X","Y",1);
   hPtZ->Draw();
   hPtZ1J->Draw("same");
   hPtZ2J->Draw("same");
   hNjets->Draw("");
   hPtJ->Draw("");
   hEtaJ->Draw("");
   hDeta0->Draw("");
   hDeta1->Draw("");
   */
}
