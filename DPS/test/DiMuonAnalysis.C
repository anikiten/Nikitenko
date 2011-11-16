#define DiMuonAnalysis_cxx
#include "DiMuonAnalysis.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void DiMuonAnalysis::setTDRStyle(Int_t xlog, Int_t ylog, Int_t zlog) {

  TStyle *tdrStyle = new TStyle("tdrStyle","Style for P-TDR");

// For the canvas:
  tdrStyle->SetCanvasBorderMode(0);
  tdrStyle->SetCanvasColor(kWhite);
  tdrStyle->SetCanvasDefH(600); //Height of canvas
  tdrStyle->SetCanvasDefW(600); //Width of canvas
  tdrStyle->SetCanvasDefX(0);   //POsition on screen
  tdrStyle->SetCanvasDefY(0);

// For the Pad:
  tdrStyle->SetPadBorderMode(0);
  // tdrStyle->SetPadBorderSize(Width_t size = 1);
  tdrStyle->SetPadColor(kWhite);
  tdrStyle->SetPadGridX(false);
  tdrStyle->SetPadGridY(false);
  tdrStyle->SetGridColor(0);
  tdrStyle->SetGridStyle(3);
  tdrStyle->SetGridWidth(1);

// For the frame:
  tdrStyle->SetFrameBorderMode(0);
  tdrStyle->SetFrameBorderSize(1);
  tdrStyle->SetFrameFillColor(0);
  tdrStyle->SetFrameFillStyle(0);
  tdrStyle->SetFrameLineColor(1);
  tdrStyle->SetFrameLineStyle(1);
  tdrStyle->SetFrameLineWidth(1);

// For the histo:
  // tdrStyle->SetHistFillColor(1);
  // tdrStyle->SetHistFillStyle(0);
  tdrStyle->SetHistLineColor(1);
  tdrStyle->SetHistLineStyle(0);
  tdrStyle->SetHistLineWidth(2);
  // tdrStyle->SetLegoInnerR(Float_t rad = 0.5);
  // tdrStyle->SetNumberContours(Int_t number = 20);

  tdrStyle->SetEndErrorSize(4);
  //  tdrStyle->SetErrorMarker(20);
  //  tdrStyle->SetErrorX(0.);
  
  tdrStyle->SetMarkerStyle(20);

//For the fit/function:
  tdrStyle->SetOptFit(1);
  tdrStyle->SetFitFormat("5.4g");
  tdrStyle->SetFuncColor(1);
  tdrStyle->SetFuncStyle(1);
  tdrStyle->SetFuncWidth(1);

//For the date:
  tdrStyle->SetOptDate(0);
  // tdrStyle->SetDateX(Float_t x = 0.01);
  // tdrStyle->SetDateY(Float_t y = 0.01);

// For the statistics box:
  tdrStyle->SetOptFile(0);
  tdrStyle->SetOptStat(0); // To display the mean and RMS:   SetOptStat("mr");
  tdrStyle->SetStatColor(kWhite);
  tdrStyle->SetStatFont(42);
  tdrStyle->SetStatFontSize(0.025);
  tdrStyle->SetStatTextColor(1);
  tdrStyle->SetStatFormat("6.4g");
  tdrStyle->SetStatBorderSize(1);
  tdrStyle->SetStatH(0.1);
  tdrStyle->SetStatW(0.15);
  // tdrStyle->SetStatStyle(Style_t style = 1001);
  // tdrStyle->SetStatX(Float_t x = 0);
  // tdrStyle->SetStatY(Float_t y = 0);

// Margins:
  tdrStyle->SetPadTopMargin(0.05);
  tdrStyle->SetPadBottomMargin(0.13);
  tdrStyle->SetPadLeftMargin(0.13);
  tdrStyle->SetPadRightMargin(0.05);

// For the Global title:

  tdrStyle->SetOptTitle(0);
  tdrStyle->SetTitleFont(42);
  tdrStyle->SetTitleColor(1);
  tdrStyle->SetTitleTextColor(1);
  tdrStyle->SetTitleFillColor(10);
  tdrStyle->SetTitleFontSize(0.05);
  // tdrStyle->SetTitleH(0); // Set the height of the title box
  // tdrStyle->SetTitleW(0); // Set the width of the title box
  // tdrStyle->SetTitleX(0); // Set the position of the title box
  // tdrStyle->SetTitleY(0.985); // Set the position of the title box
  // tdrStyle->SetTitleStyle(Style_t style = 1001);
  // tdrStyle->SetTitleBorderSize(2);

// For the axis titles:

  tdrStyle->SetTitleColor(1, "XYZ");
  tdrStyle->SetTitleFont(42, "XYZ");
  tdrStyle->SetTitleSize(0.06, "XYZ");
  // tdrStyle->SetTitleXSize(Float_t size = 0.02); // Another way to set the size?
  // tdrStyle->SetTitleYSize(Float_t size = 0.02);
  tdrStyle->SetTitleXOffset(0.9);
  tdrStyle->SetTitleYOffset(1.05);
  // tdrStyle->SetTitleOffset(1.1, "Y"); // Another way to set the Offset

// For the axis labels:

  tdrStyle->SetLabelColor(1, "XYZ");
  tdrStyle->SetLabelFont(42, "XYZ");
  tdrStyle->SetLabelOffset(0.007, "XYZ");
  tdrStyle->SetLabelSize(0.05, "XYZ");

// For the axis:

  tdrStyle->SetAxisColor(1, "XYZ");
  tdrStyle->SetStripDecimals(kTRUE);
  tdrStyle->SetTickLength(0.03, "XYZ");
  tdrStyle->SetNdivisions(510, "XYZ");
  tdrStyle->SetPadTickX(1);  // To get tick marks on the opposite side of the frame
  tdrStyle->SetPadTickY(1);

// Change for log plots:
  tdrStyle->SetOptLogx(xlog);
  tdrStyle->SetOptLogy(ylog);
  tdrStyle->SetOptLogz(zlog);

// Postscript options:

//  tdrStyle->SetPaperSize(7.5,7.5);

  tdrStyle->SetPaperSize(15.,15.);

//  tdrStyle->SetPaperSize(20.,20.);

  // tdrStyle->SetLineScalePS(Float_t scale = 3);
  // tdrStyle->SetLineStyleString(Int_t i, const char* text);
  // tdrStyle->SetHeaderPS(const char* header);
  // tdrStyle->SetTitlePS(const char* pstitle);

  // tdrStyle->SetBarOffset(Float_t baroff = 0.5);
  // tdrStyle->SetBarWidth(Float_t barwidth = 0.5);
  // tdrStyle->SetPaintTextFormat(const char* format = "g");
  // tdrStyle->SetPalette(Int_t ncolors = 0, Int_t* colors = 0);
  // tdrStyle->SetTimeOffset(Double_t toffset);
  // tdrStyle->SetHistMinimumZero(kTRUE);

  tdrStyle->cd();
}

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

   //   Double_t GetBinContent(Int_t bin) 

   TFile* file = new TFile("DYData15nov.root");
   hnvtx0->Draw();
   Double_t nvtx_data[40];
   Double_t nvtx_mc[40];
   Double_t puweight[40];
   for (Int_t id = 0; id < 40; id++) {
     nvtx_data[id] = hnvtx0->GetBinContent(id+1);
     cout <<" bin id = " << id <<"  bin content = " << nvtx_data[id] << endl; 
   }

   TFile* file = new TFile("DYMC15nov.root");
   hnvtx0->Draw();
   for (Int_t im = 0; im < 40; im++) {
     nvtx_mc[im] = hnvtx0->GetBinContent(im+1);
     cout <<" bin im = " << im <<"  bin content = " << nvtx_mc[im] << endl; 
   }

   for (Int_t idm = 0; idm < 40; idm++) {
     if(nvtx_mc[idm] != 0) {
       puweight[idm] =  nvtx_data[idm] /  nvtx_mc[idm]; 
     } else {
       puweight[idm] = 0.;
     }
     cout <<" bin idm = " << idm <<"  data = " << nvtx_data[idm] <<" mc = " << nvtx_mc[idm] <<" ratio = " << puweight[idm] << endl; 
   }

  
   TH1F * hnvtx0   = new TH1F( "hnvtx0", "nvtx0", 40, 0., 40.);

   TH1F * hM2mu0   = new TH1F( "hM2mu0", "M2mu0", 60, 20., 140.);
   TH1F * hM2mu1   = new TH1F( "hM2mu1", "M2mu1", 60, 20., 140.);
   TH1F * hDeta0   = new TH1F( "hDeta0", "Deta0", 50, 0., 10.);
   TH1F * hDeta1   = new TH1F( "hDeta1", "Deta1", 50, 0., 10.);
   TH1F * hMjj     = new TH1F( "hMjj", "Mjj", 40, 0., 2000.);

   TH1F * hPtZ     = new TH1F( "hPtZ", "PtZ", 25, 0., 100.);

   TH1F * hPtZ1              = new TH1F( "hPtZ1", "PtZ1", 25, 0., 100.);
   TH1F * hPtZ12J            = new TH1F( "hPtZ12J", "PtZ12J", 25, 0., 100.);
   TH1F * hPtZ12JDeta        = new TH1F( "hPtZ12JDeta", "PtZ12JDeta", 25, 0., 100.);
   TH1F * hPtZ12JDetaMjj     = new TH1F( "hPtZ12JDetaMjj", "PtZ12JDetaMjj", 25, 0., 100.);
   TH1F * hPtZ12JDetaMjjCJV  = new TH1F( "hPtZ12JDetaMjjCJV", "PtZ12JDetaMjjCJV", 25, 0., 100.);
   
   TH1F * hZY              = new TH1F( "hZY", "ZY", 50, -5., 5.);
   TH1F * hZY2J            = new TH1F( "hZY2J", "ZY2J", 50, -5., 5.);
   TH1F * hZY2JDeta        = new TH1F( "hZY2JDeta", "ZY2JDeta", 25, -5., 5.);
   TH1F * hZY2JDetaMjj     = new TH1F( "hZY2JDetaMjj", "ZY2JDetaMjj", 25, -5., 5.);
   TH1F * hZY2JDetaMjjCJV  = new TH1F( "hZY2JDetaMjjCJV", "ZY2JDetaMjjCJV", 25, -5., 5.);

   TH1F * hEtJ    = new TH1F( "hEtJ", "EtJ", 30, 0., 150.);
   TH1F * hEtaJ   = new TH1F( "hEtaJ", "EtaJ", 24, -2.4, 2.4);
   TH1F * hNvtx   = new TH1F( "hNvtx", "Nvtx", 16, 0., 16.);
   TH1F * hNjets  = new TH1F( "hNjets", "Njets", 6, 0., 6.);

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
      // Selections

      // 1. two muons
      if(nmuon < 2) {continue;}

      // pT mu > 20 GeV, |eta| < 2.1
      if( ((*PtMu)[0] < 20.) || ((*PtMu)[1] < 20.) || (fabs((*EtaMu)[0]) > 2.4) || (fabs((*EtaMu)[1]) > 2.4) ) {continue;}
      N_muons++;
      hM2mu0->Fill(mass_mumu,puweight[nvertex]);
      hnvtx0->Fill(1.*nvertex,puweight[nvertex]);
      //	if( ((*muisol)[0] < 0.1) && ((*muisol)[1] < 0.1) ) 

      // M_mumu 85-97 GeV
      if(mass_mumu < 85. || mass_mumu > 97.) {continue;}
      N_mass2mu++;
      hM2mu1->Fill(mass_mumu,puweight[nvertex]);


      Int_t smallbeta = 0;
      Int_t jet25 = 0;
      Int_t njets = EtJPT->size();
      // muons
      Double_t PtZx = 0.;
      Double_t PtZy = 0.;
      Double_t PZz  = 0.;
      Double_t DphiZJ = 0.;
      hDzmuon1->Fill((*dzmuon)[0],(*dzmuon)[1]);  
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

      hZY->Fill(ZY,puweight[nvertex]);

      // jets
      for (unsigned int i = 0; i < njets; i++) {

	/*
	Int_t muonmatch = 0;
	// remove jets from muons
	for (unsigned int j = 0; j < nmuon; j++) {
	  // DR muon-jet
	  Double_t DR = deltaR((*EtaJPT)[i], (*PhiJPT)[i], (*EtaMu)[j], (*PhiMu)[j]);
	  if(DR < 0.5) {
	    muonmatch = 1;
	  }
	}
	if(muonmatch == 0) {
*/
	nalljets = nalljets + 1;
	if(fabs((*EtaJPT)[i]) < 2.0) {
	  ngoodjets = ngoodjets + 1;
	  hEtaJ->Fill((*EtaJPT)[i]);
	  hEtJ->Fill((*EtJPT)[i]); 
	  DphiZJ = deltaPhi(PhiZ, (*PhiJPT)[i]);
	  
	  if( (*beta)[i] > 0.1 && nvertex > 7) {
	    if(izmin == 1) {hNtrkVtxL2->Fill((*Ntrk)[i]);} else {hNtrkVtxG2->Fill((*Ntrk)[i]);}
	  }
	  /*
	    if(run == 163301) {
	    if((*beta)[i] < 0.1) cout <<" run " << run 
	    <<" event " << event 
	    <<" beta = " << (*beta)[i]
	    <<" etaj = " << (*EtaJPT)[i]
	    <<" phij = " << (*PhiJPT)[i]
	    <<" et jpt = " << (*EtJPT)[i]
	    <<" ntrk = " << (*Ntrk)[i] 
	    <<" nvertex = " << nvertex << endl;
	    }
	  */
	  if( (*EtJPT)[i] > 25.) {
	    jet25 = 1;
	  }
	  
	  if( (*beta)[i] < 0.1) {
	    smallbeta = 1;
	    hEtJ01->Fill((*EtJPT)[i]); 
	    hEtaJ01->Fill((*EtaJPT)[i]);
	  }
	  if(nvertex == 1 || nvertex == 2) {
	    hbeta1->Fill((*beta)[i]);
	    hNtrk1->Fill((*Ntrk)[i]);
	    if((*beta)[i] < 0.1)  {hNtrk101->Fill((*Ntrk)[i]);} else {hNtrk1g->Fill((*Ntrk)[i]);}
	  }
	  if(nvertex == 5 || nvertex == 6) {
	    hbeta2->Fill((*beta)[i]);
	  }
	  if(nvertex > 7) {
	    hbeta3->Fill((*beta)[i]);
	    hNtrk3->Fill((*Ntrk)[i]);
	    if((*beta)[i] < 0.1) {hNtrk301->Fill((*Ntrk)[i]);} else {hNtrk3g->Fill((*Ntrk)[i]);}
	  }
	}
      }
   
      // VBF part
      if(nalljets < 2) {continue;}
      if( ( (*EtJPT)[0] < 25.0 ) || 
          ( (*EtJPT)[1] < 25.0 ) || 
	  ( fabs((*EtaJPT)[0]) > 4.7) || 
	  ( fabs((*EtaJPT)[1]) > 4.7) ) {continue;}
      N_jets++;
      hZY2J->Fill(ZY,puweight[nvertex]);
      Double_t DetaJJ = fabs((*EtaJPT)[0]-(*EtaJPT)[1]);
      hDeta0->Fill(DetaJJ,puweight[nvertex]);

      if( ( (*EtaJPT)[0] * (*EtaJPT)[1] > 0.0 ) ) {continue;} 
      hDeta1->Fill(DetaJJ,puweight[nvertex]);

      if( DetaJJ < 3.5 ) {continue;}
      N_deta++;
      hZY2JDeta->Fill(ZY,puweight[nvertex]);

      Double_t PJ1x = (*EtJPT)[0] * cos((*PhiJPT)[0]); 
      Double_t PJ1y = (*EtJPT)[0] * sin((*PhiJPT)[0]);
      Double_t Eta = (*EtaJPT)[0];
      Double_t theta = 2. * atan(exp(-Eta));
      Double_t PJ1z = (*EtJPT)[0] / tan(theta);
      Double_t EJ1  = (*EtJPT)[0] / sin(theta);

      Double_t PJ2x = (*EtJPT)[1] * cos((*PhiJPT)[1]); 
      Double_t PJ2y = (*EtJPT)[1] * sin((*PhiJPT)[1]);
      Eta = (*EtaJPT)[1];
      theta = 2. * atan(exp(-Eta));
      Double_t PJ2z = (*EtJPT)[1] / tan(theta);
      Double_t EJ2  = (*EtJPT)[1] / sin(theta);

      Double_t Mj1j2 = sqrt( (EJ1+EJ2)*(EJ1+EJ2) - (PJ1x+PJ2x)*(PJ1x+PJ2x) - (PJ1y+PJ2y)*(PJ1y+PJ2y) - (PJ1z+PJ2z)*(PJ1z+PJ2z) ); 
      hMjj->Fill(Mj1j2,puweight[nvertex]);
      if(Mj1j2 < 700.) {continue;}
      N_massjj++;
      hZY2JDetaMjj->Fill(ZY,puweight[nvertex]);
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
	  }
	}
      }
      if(ncj != 0) {continue;}
      N_cjv++;
      hZY2JDetaMjjCJV->Fill(ZY,puweight[nvertex]);

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
   }

   // selections summary
   cout <<"===> Total number of events analysed - " << N_total << endl;
   cout <<"===--> passed muon pT/eta selections - " << N_muons << endl;
   cout <<"===--> passed di-muon mass window    - " << N_mass2mu << endl;
   cout <<"===--> passed two jet selections     - " << N_jets << endl;
   cout <<"===--> passed Detaj1j2 cut           - " << N_deta << endl;
   cout <<"===--> passed Mj1j2 cut              - " << N_massjj << endl;
   cout <<"===--> passed CVJ                    - " << N_cjv << endl;

   TFile efile("DYhistos.root","recreate");

   setTDRStyle(0,0,0);
   // ===> di muon mass: 
   TCanvas* c1 = new TCanvas("X","Y",1);

   hM2mu0->Write();
   hM2mu1->Write();
   hDeta0->Write();
   hDeta1->Write();
   hnvtx0->Write();   
   hMjj->Write();

   hZY->Write();
   hZY2J->Write();
   hZY2JDeta->Write();
   hZY2JDetaMjj->Write();
   hZY2JDetaMjjCJV->Write();



   hM2mu0->GetXaxis()->SetTitle("M_{#mu #mu}, GeV");
   hM2mu0->GetYaxis()->SetTitle("Nev/2 GeV");
   hM2mu0->Draw("hist");
   hM2mu1->Draw("same");
   c1->SaveAs("M2mu.png");

   /*

   // Et jet
   setTDRStyle(0,0,0);
   TCanvas* c2 = new TCanvas("X","Y",1);

   hEtJ->Write();

   hEtJ->GetXaxis()->SetTitle("p_{T} of jets with |#eta|<2.0, GeV");
   hEtJ->GetYaxis()->SetTitle("Nev/5 GeV");
   hEtJ->Draw("hist");
   c2->SaveAs("EtJ.png");

   // Et jet
   setTDRStyle(0,1,0);
   TCanvas* c21 = new TCanvas("X","Y",1);

   hEtJ01->Write();

   hEtJ->GetXaxis()->SetTitle("p_{T} of jets with |#eta|<2.0, GeV");
   hEtJ->GetYaxis()->SetTitle("Nev/5 GeV");
   hEtJ->SetMaximum(5000);
   hEtJ->SetMinimum(1.0);
   hEtJ->Draw("hist");
   hEtJ01->SetLineWidth(3);
   hEtJ01->SetLineStyle(2);
   hEtJ01->Draw("same");
   TLegend *leg = new TLegend(0.45,0.75,0.9,0.9,NULL,"brNDC");
   leg->SetFillColor(10);
   leg->AddEntry(hEtJ,"all jets","L");
   leg->AddEntry(hEtJ01,"jets with #beta < 0.1","L");
   leg->Draw();
   c21->SaveAs("EtJ01.png");

   // Eta jet
   setTDRStyle(0,0,0);
   TCanvas* c3 = new TCanvas("X","Y",1);

   hEtaJ->Write();

   hEtaJ->GetXaxis()->SetTitle("#eta of jets with p_{T}>20 GeV");
   hEtaJ->GetYaxis()->SetTitle("Nev/0.2");
   hEtaJ->Draw("hist");
   c3->SaveAs("EtaJ.png");

   // Eta jet
   setTDRStyle(0,0,0);
   TCanvas* c31 = new TCanvas("X","Y",1);

   hEtaJ01->Write();

   hEtaJ->GetXaxis()->SetTitle("#eta of jets with p_{T}>20 GeV");
   hEtaJ->GetYaxis()->SetTitle("Nev/0.2");
   hEtaJ->SetMaximum(450);
   hEtaJ->Draw("hist");
   hEtaJ01->SetLineStyle(2);
   hEtaJ01->SetLineWidth(3);
   hEtaJ01->Draw("same");
   TLegend *leg = new TLegend(0.45,0.8,0.9,0.9,NULL,"brNDC");
   leg->SetFillColor(10);
   leg->AddEntry(hEtaJ,"all jets","L");
   leg->AddEntry(hEtaJ01,"jets with #beta < 0.1","L");
   leg->Draw();
   c31->SaveAs("EtaJ01.png");

   // N jets
   setTDRStyle(0,0,0);
   TCanvas* c4 = new TCanvas("X","Y",1);

   hNjets->Write();

   hNjets->GetXaxis()->SetTitle("N jets p_{T}> 20 GeV, |#eta| < 2.0");
   hNjets->GetYaxis()->SetTitle("Nev");
   hNjets->Draw("hist");
   c4->SaveAs("Njets.png");

   // N jets
   setTDRStyle(0,1,0);
   TCanvas* c41 = new TCanvas("X","Y",1);

   hNjets01->Write();

   hNjets->GetXaxis()->SetTitle("N jets p_{T}> 20 GeV, |#eta| < 2.0");
   hNjets->GetYaxis()->SetTitle("Nev");
   hNjets->SetMaximum(10000);
   hNjets->SetMinimum(1.0);
   hNjets->Draw("hist");
   hNjets01->SetLineWidth(3);
   hNjets01->SetLineStyle(2);
   hNjets01->Draw("same");
   TLegend *leg = new TLegend(0.45,0.75,0.9,0.9,NULL,"brNDC");
   leg->SetFillColor(10);
   leg->AddEntry(hNjets,"all jets","L");
   leg->AddEntry(hNjets01,"at least one with #beta < 0.1","L");
   leg->Draw();
   c41->SaveAs("Njets01.png");

   // Nvtx
   setTDRStyle(0,0,0);
   TCanvas* c5 = new TCanvas("X","Y",1);

   hNvtx->Write();

   hNvtx->GetXaxis()->SetTitle("N reco vtx (ev.with p_{T}^{j}>20 GeV, |#eta^{j}|<2.0)");
   hNvtx->GetYaxis()->SetTitle("Nev");
   hNvtx->Draw("hist");
   c5->SaveAs("Nvtx.png");

   // beta 1 or 2 vtx
   setTDRStyle(0,0,0);
   TCanvas* c6 = new TCanvas("X","Y",1);

   hbeta1->Write();

   hbeta1->GetXaxis()->SetTitle("#beta for Nvtx = 1 or 2");
   hbeta1->GetYaxis()->SetTitle("Nev");
   hbeta1->Draw("hist");
   c6->SaveAs("beta1.png");

   // beta 5 or 6 vtx
   setTDRStyle(0,0,0);
   TCanvas* c7 = new TCanvas("X","Y",1);

   hbeta2->Write();

   hbeta2->GetXaxis()->SetTitle("#beta for Nvtx = 5 or 6");
   hbeta2->GetYaxis()->SetTitle("Nev");
   hbeta2->Draw("hist");
   c7->SaveAs("beta2.png");

   // beta 5 or 6 vtx
   setTDRStyle(0,0,0);
   TCanvas* c8 = new TCanvas("X","Y",1);

   hbeta3->Write();

   hbeta3->GetXaxis()->SetTitle("#beta for Nvtx > 7");
   hbeta3->GetYaxis()->SetTitle("Nev");
   hbeta3->Draw("hist");
   c8->SaveAs("beta3.png");

   // Nvtx
   setTDRStyle(0,1,0);
   TCanvas* c9 = new TCanvas("X","Y",1);

   hNvtx01->Write();

   hNvtx01->GetXaxis()->SetTitle("N reco vtx");
   hNvtx01->GetYaxis()->SetTitle("At least one jet with #beta < 0.1");
   hNvtx01->Sumw2();
   hNvtx01->Divide(hNvtx01,hNvtx,1.,1.,"B");
   hNvtx01->SetMaximum(0.600);
   hNvtx01->SetMinimum(0.005);
   hNvtx01->SetMarkerStyle(24);
   hNvtx01->Draw("PE1");
   c9->SaveAs("eff_smallbeta.png");

   //pTz
   setTDRStyle(0,1,0);
   TCanvas* c10 = new TCanvas("X","Y",1);

   hPtZ->Write();
   hPtZ01->Write();

   hPtZ->GetXaxis()->SetTitle("p_{T}^{#mu #mu}, GeV");
   hPtZ->GetYaxis()->SetTitle("Nev");
   hPtZ->SetMaximum(1000.);
   hPtZ->SetMinimum(0.1);
   hPtZ->Draw("hist"); 
   hPtZ01->SetLineStyle(1);
   hPtZ01->SetLineWidth(3);
   hPtZ01->Draw("samePE");
   Double_t scale = hPtZ01->Integral()/hPtZ0->Integral();
   hPtZ0->Scale(scale);
   hPtZ0->SetLineStyle(2);
   hPtZ0->SetLineWidth(3);
   hPtZ0->Draw("same");
   TLegend *leg = new TLegend(0.45,0.8,0.9,0.95,NULL,"brNDC");
   leg->SetFillColor(10);
   leg->AddEntry(hPtZ,"Z + 1 jet","L");
   leg->AddEntry(hPtZ01,"Z + 1 jet #beta < 0.1","P");
   leg->AddEntry(hPtZ0,"Z + no jets (scaled)","L");
   leg->Draw();
   c10->SaveAs("PtZ01.png");

   //
   setTDRStyle(0,1,0);
   TCanvas* c11 = new TCanvas("X","Y",1);

   hDphiZJ->Write();
   hDphiZJ01->Write();

   hDphiZJ->GetXaxis()->SetTitle("#Deta #phi (Z-jet), rad");
   hDphiZJ->GetYaxis()->SetTitle("Nev");
   hDphiZJ->SetMaximum(2000);
   hDphiZJ->SetMinimum(0.5);
   hDphiZJ->Draw("hist");
   hDphiZJ01->SetLineWidth(3);
   hDphiZJ01->SetLineStyle(2);
   hDphiZJ01->Draw("same");
   TLegend *leg = new TLegend(0.2,0.75,0.65,0.9,NULL,"brNDC");
   leg->SetFillColor(10);
   leg->AddEntry(hDphiZJ,"Z + 1 jet","L");
   leg->AddEntry(hDphiZJ01,"Z + 1 jet #beta < 0.1","L");
   leg->Draw();
   c11->SaveAs("DphiZJ01.png");

   //Ntrk1
   setTDRStyle(0,0,0);
   TCanvas* c12 = new TCanvas("X","Y",1);

   hNtrk1->Write();
   hNtrk101->Write();

   hNtrk1->GetXaxis()->SetTitle("N tracks in jet for Nvtx = 1 or 2");
   hNtrk1->GetYaxis()->SetTitle("Nev");
   hNtrk1->SetMaximum(100.);
   hNtrk1->SetMinimum(0.0);
   hNtrk1->Draw("hist"); 
   hNtrk101->SetLineStyle(2);
   hNtrk101->SetLineWidth(3);
   hNtrk101->Draw("same");
   TLegend *leg = new TLegend(0.45,0.8,0.9,0.95,NULL,"brNDC");
   leg->SetFillColor(10);
   leg->AddEntry(hNtrk1,"all jets","L");
   leg->AddEntry(hNtrk101,"jets with #beta < 0.1","L");
   leg->Draw();
   c12->SaveAs("Ntrk101.png");

   //Ntrk3
   setTDRStyle(0,0,0);
   TCanvas* c13 = new TCanvas("X","Y",1);

   hNtrk3->Write();
   hNtrk301->Write();

   hNtrk3->GetXaxis()->SetTitle("N tracks in jet for Nvtx > 7");
   hNtrk3->GetYaxis()->SetTitle("Nev");
   hNtrk3->SetMaximum(100.);
   hNtrk3->SetMinimum(0.0);
   hNtrk3->Draw("hist"); 
   hNtrk301->SetLineStyle(2);
   hNtrk301->SetLineWidth(3);
   hNtrk301->Draw("same");
   TLegend *leg = new TLegend(0.45,0.8,0.9,0.95,NULL,"brNDC");
   leg->SetFillColor(10);
   leg->AddEntry(hNtrk1,"all jets","L");
   leg->AddEntry(hNtrk101,"jets with #beta < 0.1","L");
   leg->Draw();
   c13->SaveAs("Ntrk301.png");

   //Ntrk13g
   setTDRStyle(0,0,0);
   TCanvas* c14 = new TCanvas("X","Y",1);

   hNtrk1g->Write();
   hNtrk3g->Write();

   hNtrk1g->GetXaxis()->SetTitle("N tracks in jets with #beta > 0.1");
   hNtrk1g->GetYaxis()->SetTitle("Nev");
   Double_t scale = 1/hNtrk1g->Integral();
   hNtrk1g->Scale(scale);
   hNtrk1g->SetMaximum(0.2);
   hNtrk1g->SetMinimum(0.0);
   hNtrk1g->Draw("hist"); 
   scale = 1/hNtrk3g->Integral();
   hNtrk3g->Scale(scale);
   hNtrk3g->SetLineStyle(2);
   hNtrk3g->SetLineWidth(3);
   hNtrk3g->Draw("same");
   TLegend *leg = new TLegend(0.45,0.8,0.9,0.95,NULL,"brNDC");
   leg->SetFillColor(10);
   leg->AddEntry(hNtrk1g,"Nvtx 1 or 2","L");
   leg->AddEntry(hNtrk3g,"Nvtx > 7","L");
   leg->Draw();
   c14->SaveAs("Ntrk13g.png");

   //Dzmuon
   setTDRStyle(1,1,1);
   TCanvas* c15 = new TCanvas("X","Y",1);

   hDzmuon1->Write();

   hDzmuon1->GetXaxis()->SetTitle("#Delta Z_{#mu 1} - SPV, cm");
   hDzmuon1->GetYaxis()->SetTitle("#Delta Z_{#mu 2} - SPV, cm");
   //   hDzmuon1->SetMaximum(100.);
   //   hDzmuon1->SetMinimum(0.0);
   hDzmuon1->Draw("LEGO1"); 
   c15->SaveAs("Dzmuon1.png");

   //DZmin1
   setTDRStyle(1,0,0);
   TCanvas* c16 = new TCanvas("X","Y",1);

   hDZmin1->Write();

   hDZmin1->GetXaxis()->SetTitle("#Delta Z_{min}^{vtx-vtx} for Nvtx = 2, cm");
   hDZmin1->GetYaxis()->SetTitle("Nev / 250 #mu m");
   hDZmin1->SetAxisRange(0.025, 2., "X");
   hDZmin1->Draw("hist"); 
   c16->SaveAs("DZmin1.png");

   //DZmin2
   setTDRStyle(1,0,0);
   TCanvas* c17 = new TCanvas("X","Y",1);

   hDZmin2->Write();

   hDZmin2->GetXaxis()->SetTitle("#Delta Z_{min}^{vtx-vtx} for Nvtx = 5 or 6, cm");
   hDZmin2->GetYaxis()->SetTitle("Nev / 250 #mu m");
   hDZmin2->SetAxisRange(0.025, 2., "X");
   hDZmin2->Draw("hist"); 
   c17->SaveAs("DZmin2.png");

   //DZmin3
   setTDRStyle(1,0,0);
   TCanvas* c18 = new TCanvas("X","Y",1);

   hDZmin3->Write();

   hDZmin3->GetXaxis()->SetTitle("#Delta Z_{min}^{vtx-vtx} for Nvtx > 7, cm");
   hDZmin3->GetYaxis()->SetTitle("Nev / 250 #mu m");
   hDZmin3->SetAxisRange(0.025, 2., "X");
   hDZmin3->Draw("hist"); 
   c18->SaveAs("DZmin3.png");

   //Ntrk
   setTDRStyle(0,0,0);
   TCanvas* c19 = new TCanvas("X","Y",1);

   hNtrkVtxG2->Write();
   hNtrkVtxL2->Write();

   hNtrkVtxG2->GetXaxis()->SetTitle("N tracks in jets with #beta > 0.1");
   hNtrkVtxG2->GetYaxis()->SetTitle("Nev");
   Double_t scale = 1/hNtrkVtxG2->Integral();
   hNtrkVtxG2->Scale(scale);
   hNtrkVtxG2->SetMaximum(0.25);
   hNtrkVtxG2->SetMinimum(0.00);
   hNtrkVtxG2->Draw("hist"); 
   scale = 1/hNtrkVtxL2->Integral();
   hNtrkVtxL2->Scale(scale);
   hNtrkVtxL2->SetLineStyle(2);
   hNtrkVtxL2->SetLineWidth(3);
   hNtrkVtxL2->Draw("same");
   TLegend *leg = new TLegend(0.45,0.75,0.9,0.9,NULL,"brNDC");
   leg->SetFillColor(10);
   leg->AddEntry(hNtrkVtxG2,"#Delta Z_{min}^{vtx-vtx} > 2 mm","L");
   leg->AddEntry(hNtrkVtxL2,"#Delta Z_{min}^{vtx-vtx} < 2 mm","L");
   leg->Draw();
   c19->SaveAs("NtrkVtxGL2.png");

   // NvtxL2
   setTDRStyle(0,1,0);
   TCanvas* c20 = new TCanvas("X","Y",1);

   hNvtxL2->Write();

   hNvtxL2->GetXaxis()->SetTitle("N reco vtx");
   hNvtxL2->GetYaxis()->SetTitle("fraction #Delta Z_{min}^{vtx-vtx} < 2 mm");
   hNvtxL2->Sumw2();
   hNvtxL2->Divide(hNvtxL2,hNvtx,1.,1.,"B");
   hNvtxL2->SetMaximum(0.600);
   hNvtxL2->SetMinimum(0.005);
   hNvtxL2->SetMarkerStyle(24);
   hNvtxL2->Draw("PE1");
   c20->SaveAs("NvtxL2.png");

   // NvtxL2
   setTDRStyle(0,0,0);
   TCanvas* c21 = new TCanvas("X","Y",1);

   hNvtxjet25->Write();

   hNvtxjet25->GetXaxis()->SetTitle("N reco vtx");
   hNvtxjet25->GetYaxis()->SetTitle("fract. of ev. p_{T jet} > 25 GeV, #beta > 0.1");
   hNvtxjet25->Sumw2();
   hNvtxjet25->Divide(hNvtxjet25,hNvtxjet20,1.,1.,"B");
   hNvtxjet25->SetMaximum(1.1);
   hNvtxjet25->SetMinimum(0.4);
   hNvtxjet25->SetMarkerStyle(24);
   hNvtxjet25->Draw("PE1");
   c21->SaveAs("Nvtxjet25.png");

   */

   // NvtxL2
   setTDRStyle(0,1,0);
   TCanvas* c22 = new TCanvas("X","Y",1);

   hZY->GetXaxis()->SetTitle("Z rapidity");
   hZY->GetYaxis()->SetTitle("Nev / 0.2");

   //   hZY->SetMaximum(50000.);
   hZY->SetMinimum(0.5);
   hZY->SetLineStyle(1);
   hZY->SetLineWidth(3);
   hZY->Draw();

   hZY2J->SetLineStyle(2);
   hZY2J->SetLineWidth(3);
   hZY2J->Draw("same");

   hZY2JDeta->SetLineStyle(3);
   hZY2JDeta->SetLineWidth(3);
   hZY2JDeta->Draw("same");

   TLegend *leg = new TLegend(0.2,0.75,0.9,0.9,NULL,"brNDC");
   leg->SetFillColor(10);
   leg->AddEntry(hZY,"MC Z inclusive","L");
   leg->AddEntry(hZY2J,"MC Z+2jets, p_{T} > 25 GeV","L");
   leg->AddEntry(hZY2JDeta,"MC Z+2jets, p_{T} > 25 GeV, #Delta #eta _{j1j2} > 3.5","L");
   leg->Draw();

   c22->SaveAs("ZY.png");

   efile.Close();
}
