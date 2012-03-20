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

   TFile fd("MyDataPileupHistogramA.root");
   //   TFile fd("MyDataPileupHistogramB.root");
   TH1D *pileup = (TH1D*)fd.Get("pileup");
   pileup->Draw();
   Double_t nvtx_data[100];
   Double_t nvtx_mc[100];
   Double_t puweight[100];
   for (Int_t id = 0; id < 100; id++) {
     if(id < 50) {
       nvtx_data[id] = pileup->GetBinContent(id+1);
     } else {
       nvtx_data[id] = 0.;
     }
     std::cout <<" data bin id = " << id <<"  bin content = " << nvtx_data[id] << endl; 
   }

   TFile fm("MCPileupHistogram.root");
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
   /*
   for (Int_t idm = 0; idm < 100; idm++) {
     if(nvtx_mc[idm] != 0) {
       puweight[idm] =  nvtx_data[idm] /  nvtx_mc[idm]; 
     } else {
       puweight[idm] = 0.;
     }
     std::cout <<" bin idm = " << idm <<"  data = " << nvtx_data[idm] <<" mc = " << nvtx_mc[idm] <<" ratio = " << puweight[idm] << endl; 
   }
   */

   // for data
   for (Int_t idm = 0; idm < 100; idm++) {
     puweight[idm] = 1.0;
     std::cout <<" Weights for data analysis (1)" << puweight[idm] << endl; 
   }

   TH1F * hnvtx0   = new TH1F( "hnvtx0", "nvtx0", 40, 0., 40.);
   TH1F * pileupMC   = new TH1F( "pileupMC", "pileupMC", 50, 0., 50.);

   TH1F * hM2mu0   = new TH1F( "hM2mu0", "M2mu0", 60, 20., 140.);
   TH1F * hM2mu1   = new TH1F( "hM2mu1", "M2mu1", 60, 20., 140.);
   TH1F * hDeta0   = new TH1F( "hDeta0", "Deta0", 25, 0., 10.);
   TH1F * hDeta1   = new TH1F( "hDeta1", "Deta1", 25, 0., 10.);
   TH1F * hMjj     = new TH1F( "hMjj", "Mjj", 40, 0., 2000.);

   //   TH1F * hPtZ1              = new TH1F( "hPtZ1", "PtZ1", 25, 0., 100.);
   //   TH1F * hPtZ12J            = new TH1F( "hPtZ12J", "PtZ12J", 25, 0., 100.);
   //   TH1F * hPtZ12JDeta        = new TH1F( "hPtZ12JDeta", "PtZ12JDeta", 25, 0., 100.);
   //   TH1F * hPtZ12JDetaMjj     = new TH1F( "hPtZ12JDetaMjj", "PtZ12JDetaMjj", 25, 0., 100.);
   //   TH1F * hPtZ12JDetaMjjCJV  = new TH1F( "hPtZ12JDetaMjjCJV", "PtZ12JDetaMjjCJV", 25, 0., 100.);
   
   TH1F * hZY              = new TH1F( "hZY", "ZY", 30, -3., 3.);
   TH1F * hPtZ             = new TH1F( "hPtZ", "PtZ", 28, 0., 140.);
   //
   TH1F * hPtZ1J           = new TH1F( "hPtZ1J", "PtZ1J", 28, 0., 140.);
   TH1F * hZY1J            = new TH1F( "hZY1J", "ZY1J", 30, -3., 3.);
   //
   TH1F * hPtZ2J           = new TH1F( "hPtZ2J", "PtZ2J", 28, 0., 140.);
   TH1F * hZY2J            = new TH1F( "hZY2J", "ZY2J", 30, -3., 3.);
   //
   TH1F * hZY2JDeta        = new TH1F( "hZY2JDeta", "ZY2JDeta", 30, -3., 3.);
   TH1F * hZY2JDetaCJV     = new TH1F( "hZY2JDetaCJV", "ZY2JDetaCJV", 30, -3., 3.);
   TH1F * hZY2JDetaCJVMjj  = new TH1F( "hZY2JDetaCJVMjj", "ZY2JDetaCJVMjj", 30, -3., 3.);

   TH1F * hPtJ      = new TH1F( "hPtJ", "PtJ", 30, 0., 150.);
   TH1F * hEtaJ     = new TH1F( "hEtaJ", "EtaJ", 50, -5.0, 5.0);
   TH1F * hNjets    = new TH1F( "hNjets", "Njets", 6, 0., 6.);
   TH1F * hMjjnoVBF = new TH1F( "hMjjnoVBF", "MjjnoVBF", 40, 0., 2000.);

   TH1F * hPtJ3tag25      = new TH1F( "hPtJ3tag25", "PtJ3tag25", 20, 0., 100.);
   TH1F * hEtaJ3tag25     = new TH1F( "hEtaJ3tag25", "EtaJ3tag25", 25, -5.0, 5.0);

   TH1F * hZY2JDeta35      = new TH1F( "hZY2JDeta35", "ZY2JDeta35", 30, -3., 3.);
   TH1F * hPtJ3tag35      = new TH1F( "hPtJ3tag35", "PtJ3tag35", 20, 0., 100.);
   TH1F * hEtaJ3tag35     = new TH1F( "hEtaJ3tag35", "EtaJ3tag35", 25, -5.0, 5.0);

   TH1F * hZY2JDeta45      = new TH1F( "hZY2JDeta45", "ZY2JDeta45", 30, -3., 3.);
   TH1F * hPtJ3tag45      = new TH1F( "hPtJ3tag45", "PtJ3tag45", 20, 0., 100.);
   TH1F * hEtaJ3tag45     = new TH1F( "hEtaJ3tag45", "EtaJ3tag45", 25, -5.0, 5.0);


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

   Int_t nev = 0;

   Double_t MZ = 91.2;

   // even selection counters
   //
   //  total number of events processed
   Double_t N_total = 0;
   // 1. pT mu > 20 GeV, eta < 2.4
   Double_t N_muons = 0;
   // 2. mumu mass window 85-97
   Double_t N_mass2mu = 0;
   // 3. two jets pT > 25 GeV, eta < 4.7
   Double_t N_jets = 0;
   // 4. Deta j1j2 > 3.5
   Double_t N_deta = 0;
   // 5. Mj1j2 > 700 GeV
   Double_t N_massjj = 0;
   // 6. CJV
   Double_t N_cjv = 0;
   // scale
   Double_t jescale = 1.;

   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      //      break;
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;

      //      cout <<" run number = " << run << endl;

      nev++;

      N_total++;

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

      // pT mu > 20 GeV, |eta| < 2.1

      if( ((*PtMu)[0] < 20.) || ((*PtMu)[1] < 20.) || (fabs((*EtaMu)[0]) > 2.4) || (fabs((*EtaMu)[1]) > 2.4) ) {continue;}
      if( ((*muisol)[0]/(*PtMu)[0] > 0.1) || ((*muisol)[1]/(*PtMu)[1] > 0.1)) {continue;}
      if( DoubleMu7 == 0 && Mu13_Mu8 == 0 && Mu17_Mu8 == 0) {continue;}
      if(nvertex > 2) {continue;}

      N_muons++;

      hM2mu0->Fill(mass_mumu,puweight[nsimvertex]);
      hnvtx0->Fill(1.*nvertex,puweight[nsimvertex]);


      // M_mumu 85-97 GeV
      if( fabs(MZ-mass_mumu) > 15.0) {continue;}
      N_mass2mu++;

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

	if( pTj >= 25. && fabs((*EtaJPT)[i]) < 4.7 ) {
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

      if( ( pTj1 < 25.0 ) || 
          ( pTj2 < 25.0 ) || 
	  ( fabs((*EtaJPT)[0]) > 4.7) || 
	  ( fabs((*EtaJPT)[1]) > 4.7) ) {continue;}

      N_jets++;
      hPtZ2J->Fill(PtZ,puweight[nsimvertex]);
      hZY2J->Fill(ZY,puweight[nsimvertex]);

      // Mj1j2 caclulations
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

      hMjjnoVBF->Fill(Mj1j2,puweight[nsimvertex]); 
      //
      Double_t DetaJJ = fabs((*EtaJPT)[0]-(*EtaJPT)[1]);
      hDeta0->Fill(DetaJJ,puweight[nsimvertex]);
      if( ( (*EtaJPT)[0] * (*EtaJPT)[1] > 0.0 ) ) {continue;} 
      hDeta1->Fill(DetaJJ,puweight[nsimvertex]);

      if( DetaJJ < 3.5 ) {continue;}
      N_deta++;
      hZY2JDeta->Fill(ZY,puweight[nsimvertex]);

      // VBF jets with max and min rapidity
      Double_t eta_jmin = (*EtaJPT)[0]; 
      Double_t eta_jmax = (*EtaJPT)[1]; 
      if( (*EtaJPT)[0] > (*EtaJPT)[1] ) {
	eta_jmin = (*EtaJPT)[1]; 
	eta_jmax = (*EtaJPT)[0]; 
      }

      // CJV part
      Int_t ncj = 0;
      for (unsigned int i = 0; i < njets; i++) {
	if(i < 2 ) {continue;}
	if( (fabs((*EtaJPT)[i]) < 2.0) && ((*beta)[i] > 0.2) ) {
	  if( ((eta_jmin+0.5) < (*EtaJPT)[i]) && ( (*EtaJPT)[i]) < (eta_jmax-0.5) ) {
	    ncj++;
	    if(ncj == 1) {
	      hPtJ3tag25->Fill((*EtJPT)[i],puweight[nsimvertex]);
	      hEtaJ3tag25->Fill((*EtaJPT)[i],puweight[nsimvertex]);
	    }
	  }
	}
      }

      // check with cut on tagging jets 35, 45 GeV
      if( ( pTj1 > 35.0 ) &&  ( pTj2 > 35.0 ) ) {
	hZY2JDeta35->Fill(ZY,puweight[nsimvertex]);
	// CJV part
	Int_t ncj35 = 0;
	for (unsigned int i = 0; i < njets; i++) {
	  if(i < 2 ) {continue;}
	  if( (fabs((*EtaJPT)[i]) < 2.0) && ((*beta)[i] > 0.2) ) {
	    if( ((eta_jmin+0.5) < (*EtaJPT)[i]) && ( (*EtaJPT)[i]) < (eta_jmax-0.5) ) {
	      ncj35++;
	      if(ncj35 == 1) {
		hPtJ3tag35->Fill((*EtJPT)[i],puweight[nsimvertex]);
		hEtaJ3tag35->Fill((*EtaJPT)[i],puweight[nsimvertex]);
	      }
	    }
	  }
	}
      }

      if( ( pTj1 > 45.0 ) &&  ( pTj2 > 45.0 ) ) {
	hZY2JDeta45->Fill(ZY,puweight[nsimvertex]);
	// CJV part
	Int_t ncj45 = 0;
	for (unsigned int i = 0; i < njets; i++) {
	  if(i < 2 ) {continue;}
	  if( (fabs((*EtaJPT)[i]) < 2.0) && ((*beta)[i] > 0.2) ) {
	    if( ((eta_jmin+0.5) < (*EtaJPT)[i]) && ( (*EtaJPT)[i]) < (eta_jmax-0.5) ) {
	      ncj45++;
	      if(ncj45 == 1) {
		hPtJ3tag45->Fill((*EtJPT)[i],puweight[nsimvertex]);
		hEtaJ3tag45->Fill((*EtaJPT)[i],puweight[nsimvertex]);
	      }
	    }
	  }
	}
      }


      if(ncj != 0) {continue;}
      N_cjv++;
      hZY2JDetaCJV->Fill(ZY,puweight[nsimvertex]);
      hMjj->Fill(Mj1j2,puweight[nsimvertex]);

      if(Mj1j2 < 700.) {continue;}
      N_massjj++;
      hZY2JDetaCJVMjj->Fill(ZY,puweight[nsimvertex]);

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
   std::cout <<"===--> passed Detaj1j2 cut           - " << N_deta << endl;
   std::cout <<"===--> passed CVJ                    - " << N_cjv << endl;
   std::cout <<"===--> passed Mj1j2 cut              - " << N_massjj << endl;

   TFile efile("DYhistosMCA1vtx+jes.root","recreate");

   hnvtx0->Write();   
   pileupMC->Write();   
   hM2mu0->Write();
   hM2mu1->Write();
   hDeta0->Write();
   hDeta1->Write();
   hMjj->Write();

   hPtZ->Write();
   hPtZ1J->Write();
   hZY1J->Write();
   hPtZ2J->Write();
   hNjets->Write();
   hPtJ->Write();
   hEtaJ->Write();
   hMjjnoVBF->Write();

   hZY->Write();
   hZY2J->Write();
   hZY2JDeta->Write();
   hZY2JDetaCJV->Write();
   hZY2JDetaCJVMjj->Write();


   hPtJ3tag25->Write();
   hEtaJ3tag25->Write();

   hZY2JDeta35->Write();
   hPtJ3tag35->Write(); 
   hEtaJ3tag35->Write();

   hZY2JDeta45->Write();
   hPtJ3tag45->Write(); 
   hEtaJ3tag45->Write();

   efile.Close();

   //   setTDRStyle(0,1,0);
   TCanvas* c1 = new TCanvas("X","Y",1);
   hPtZ->Draw();
   hPtZ1J->Draw("same");
   hPtZ2J->Draw("same");
   hNjets->Draw("");
   hPtJ->Draw("");
   hEtaJ->Draw("");
   hMjjnoVBF->Draw("");
   hDeta0->Draw("");
   hDeta1->Draw("");
}
