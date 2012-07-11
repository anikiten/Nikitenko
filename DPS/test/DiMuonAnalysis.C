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
   //   TFile fd("MyDataPileupHistogramB.root");
   TFile fd("MyDataPileupHistogram.root");
   TH1D *pileup = (TH1D*)fd.Get("pileup");
   pileup->Draw();
   Double_t nvtx_data[100];
   Double_t nvtx_mc[100];
   cout <<" Integral of Data PU histo = " << pileup->Integral() << endl;
   Double_t sumdata = 0.;
   for (Int_t id = 0; id < 100; id++) {
     if(id < 50) {
       nvtx_data[id] = pileup->GetBinContent(id+1);
       sumdata = sumdata + nvtx_data[id];
     } else {
       nvtx_data[id] = 0.;
     }
     std::cout <<" data bin id = " << id <<"  bin content = " << nvtx_data[id] << endl; 
   }

   TFile fm("MCPileupHistogram.root");
   //   TFile fm("MCSignalPileuHistogram.root");
   pileup = (TH1D*)fm.Get("pileup");
   cout <<" Integral of MC PU histo = " << pileup->Integral() << endl;
   pileup->Draw();
   Double_t summc = 0.;
   for (Int_t im = 0; im < 100; im++) {
     if(im < 50) {
       nvtx_mc[im] = pileup->GetBinContent(im+1);
       summc = summc + nvtx_mc[im];
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
   cout <<" Sum Data PU histo = " << sumdata <<" Sum MC PU Histo = " << summc << endl;
   Double_t ratioPU = sumdata/summc;
   cout <<"        ===> ratio PU data / PU MC histos = " << ratioPU << endl; 

   // muon data / mc correction factors
   Double_t x_eta_mu[16] = {-2.4, -2.1, -1.6, -1.2, -0.9, -0.6, -0.3, -0.2,
                             0.2,  0.3,  0.6,  0.9,  1.2,  1.6,  2.1,  2.4};
   // MC
   Double_t corr_mu[15] = {0.977607, 0.961587, 0.964097, 0.980235, 0.997457, 1., 0.978457, 
                           0.995915, 0.98683, 1.001, 0.99583, 0.992862, 0.97847, 0.980215,
                           0.987352};
   // data
   //   Double_t corr_mu[15] = {1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.};

   // selections
   TH1F * hZY          = new TH1F( "hZY", "ZY", 30, -3., 3.);
   TH1F * hZY2J        = new TH1F( "hZY2J", "ZY2J", 30, -3., 3.);
   TH1F * hZY2JY       = new TH1F( "hZY2JY", "ZY2JY", 30, -3., 3.);
   TH1F * hZY2JYMjj    = new TH1F( "hZY2JYMjj", "ZY2JYMjj", 30, -3., 3.);
   //

   TH1F * hnvtx0   = new TH1F( "hnvtx0", "nvtx0", 40, 0., 40.);
   TH1F * pileupMC   = new TH1F( "pileupMC", "pileupMC", 50, 0., 50.);
   // two tight muons, no Z mass window
   TH1F * hM2mu0   = new TH1F( "hM2mu0", "M2mu0", 60, 20., 140.);
   // two tight muons, inside Z mass window
   TH1F * hM2mu1   = new TH1F( "hM2mu1", "M2mu1", 60, 20., 140.);
   TH1F * hMjj     = new TH1F( "hMjj", "Mjj", 40, 0., 2000.);

   // general stuff
   TH1F * hPtZ             = new TH1F( "hPtZ", "PtZ", 28, 0., 140.);
   TH1F * hPtZ1J           = new TH1F( "hPtZ1J", "PtZ1J", 28, 0., 140.);
   TH1F * hPtZ2J           = new TH1F( "hPtZ2J", "PtZ2J", 28, 0., 140.);
   TH1F * hZY1J            = new TH1F( "hZY1J", "ZY1J", 30, -3., 3.);
   //
   TH1F * hPtJ      = new TH1F( "hPtJ", "PtJ", 30, 0., 150.);
   TH1F * hEtaJ     = new TH1F( "hEtaJ", "EtaJ", 50, -5.0, 5.0);
   TH1F * hNjets    = new TH1F( "hNjets", "Njets", 6, 0., 6.);

   Long64_t nentries = fChain->GetEntriesFast();
   Long64_t nbytes = 0, nb = 0;
   // MZ
   Double_t MZ = 91.2;
   // cuts
   Double_t pTj1cut = 65.0;
   Double_t pTj2cut = 40.0;
   Double_t YZ_cut   = 1.2;
   Double_t Mjjcut  = 600.;

   // even selection counters
   //
   //  total number of events processed
   Double_t N_total = 0;
   // 1. pT mu > 20 GeV, eta < 2.4
   Double_t N_muons = 0;
   // 2. mumu mass window +/- 15 GeV
   Double_t N_mass2mu = 0;
   // 3. two jets pT > 40, 65 GeV, eta < 3.6
   Double_t N_jets = 0;
   // 4. Y < 1.2 
   Double_t N_Y = 0;
   // 5. Mj1j2 > 600 GeV
   Double_t N_massjj = 0;

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

      Int_t nalljets = 0;
      Int_t izmin = 0;
      if(DZmin < 0.2) izmin = 1;
      // di muon mass
      Int_t nmuon = PtMu->size();

      pileupMC->Fill(1.*nsimvertex,puweight[nsimvertex]);

      // Selections

      // 1. two muons
      if(nmuon < 2) {continue;}

      // muon pT/eta
      if( ((*PtMu)[0] < 20.) || ((*PtMu)[1] < 20.) || 
          (fabs((*EtaMu)[0]) > 2.4) || (fabs((*EtaMu)[1]) > 2.4) ) {continue;}
      // muon isolation
      if( ((*muisol)[0]/(*PtMu)[0] > 0.1) || ((*muisol)[1]/(*PtMu)[1] > 0.1)) {continue;}
      // muon trigger
      if( DoubleMu7 == 0 && Mu13_Mu8 == 0 && Mu17_Mu8 == 0) {continue;}

      Double_t mu_data_mc_scaling = 1.;
      Double_t mu1_data_mc_scaling = 1.;
      Double_t mu2_data_mc_scaling = 1.;
      for (unsigned int i = 0; i < 15; i++) {
	if( (*EtaMu)[0] >= x_eta_mu[i] && 
            (*EtaMu)[0] <  x_eta_mu[i+1] ) {mu1_data_mc_scaling = corr_mu[i];}
	if( (*EtaMu)[1] >= x_eta_mu[i] && 
            (*EtaMu)[1] <  x_eta_mu[i+1] ) {mu2_data_mc_scaling = corr_mu[i];}
      }
      mu_data_mc_scaling = mu1_data_mc_scaling*mu2_data_mc_scaling;

      Double_t event_weight = puweight[nsimvertex] * mu_data_mc_scaling; 
	  
      N_muons += event_weight;

      hM2mu0->Fill(mass_mumu,event_weight);
      hnvtx0->Fill(1.*nvertex,event_weight);


      // M_mumu MZ +- 15 GeV
      if( fabs(MZ-mass_mumu) > 15.0) {continue;}
      N_mass2mu += event_weight;

      Int_t njets = EtJPT->size();
      // muons
      Double_t PtZx = 0.;
      Double_t PtZy = 0.;
      Double_t PZz  = 0.;
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
      Double_t EZ = sqrt(MZ*MZ + PtZ*PtZ + PZz*PZz);
      Double_t ZY   = 0.5 * log( (EZ+PZz) / (EZ-PZz));

      hM2mu1->Fill(mass_mumu,event_weight);
      hZY->Fill(ZY,event_weight);
      hPtZ->Fill(PtZ,event_weight); 

      // jet
      for (unsigned int i = 0; i < njets; i++) {

	Double_t pTj = (*EtJPT)[i] + jescale*(*jesunc)[i]*(*EtJPT)[i];

	if( pTj >= 50. && fabs((*EtaJPT)[i]) < 2.5 ) {
	  nalljets = nalljets + 1;
	  hPtJ->Fill(pTj,event_weight);
	  hEtaJ->Fill((*EtaJPT)[i],event_weight);
	}
      }
      
      hNjets->Fill(1.*nalljets,event_weight);

      if(nalljets >= 1) {
	
	hPtZ1J->Fill(PtZ,event_weight);
	hZY1J->Fill(ZY,event_weight);

      }

      // VBF part
      double pTj1 = 0.;
      double pTj2 = 0.;

      if(njets < 2) {continue;}
      
      pTj1 = (*EtJPT)[0] + jescale*(*jesunc)[0]*(*EtJPT)[0];
      pTj2 = (*EtJPT)[1] + jescale*(*jesunc)[1]*(*EtJPT)[1];

      if( ( pTj1 < pTj1cut ) || 
          ( pTj2 < pTj2cut ) || 
	  ( fabs((*EtaJPT)[0]) > 3.6 ) || 
	  ( fabs((*EtaJPT)[1]) > 3.6 ) ) {continue;}

      N_jets += event_weight;
      hPtZ2J->Fill(PtZ,event_weight);
      hZY2J->Fill(ZY,event_weight);

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
      Double_t Mj1j2 = sqrt( (EJ1+EJ2)*(EJ1+EJ2) 
                           - (PJ1x+PJ2x)*(PJ1x+PJ2x) 
                           - (PJ1y+PJ2y)*(PJ1y+PJ2y) 
                           - (PJ1z+PJ2z)*(PJ1z+PJ2z) ); 

      Double_t YZstar = fabs(ZY-0.5*((*EtaJPT)[0]+(*EtaJPT)[1]));

      if(YZstar > YZ_cut) {continue;}

      N_Y += event_weight;

      hZY2JY->Fill(ZY,event_weight);
      hMjj->Fill(Mj1j2,event_weight);
      
      if(Mj1j2 < Mjjcut) {continue;}
           
	N_massjj += event_weight;
	hZY2JYMjj->Fill(ZY,event_weight);

   }
   // selections summary

   std::cout <<"===> ratio PU data/MC histo = " << ratioPU << endl;

   std::cout <<"===> Total number of events analysed - " << N_total << endl;
   std::cout <<"===--> passed muon pT/eta selections - " << N_muons << endl;
   std::cout <<"===--> passed di-muon mass window    - " << N_mass2mu << endl;
   std::cout <<"===--> passed two jet selections     - " << N_jets << endl;  
   std::cout <<"===--> passed y* cut                 - " << N_Y << endl;  
   std::cout <<"===--> passed Mj1j2 cut              - " << N_massjj << endl;

   std::cout <<"----------------------------------" << endl;
   std::cout <<" cuts used: " << endl;
   std::cout <<" pTj1cut, pTj2cut  > " << pTj1cut <<"  " << pTj2cut << endl;
   std::cout <<" y* < " << YZ_cut << endl;
   std::cout <<" Mjjcut > " << Mjjcut << endl;
  
   TFile efile("DYhistos.root","recreate");


   hZY->Write();
   hZY2J->Write();
   hZY2JY->Write();
   hZY2JYMjj->Write();

   hnvtx0->Write();   
   pileupMC->Write();   
   hM2mu0->Write();
   hM2mu1->Write();
   hMjj->Write();

   hPtZ->Write();
   hPtZ1J->Write();
   hZY1J->Write();
   hPtZ2J->Write();
   hNjets->Write();
   hPtJ->Write();
   hEtaJ->Write();

   // event selections

   efile.Close();
}
