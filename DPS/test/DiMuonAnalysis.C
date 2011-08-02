#define DiMuonAnalysis_cxx
#include "DiMuonAnalysis.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void DiMuonAnalysis::setTDRStyle(Int_t xlog, Int_t ylog) {

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
  tdrStyle->SetOptLogz(0);

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

   TH1F * hPtZ    = new TH1F( "hPtZ", "PtZ", 50, 0., 100.);
   TH1F * hNvtx0  = new TH1F( "hNvtx0", "Nvtx0", 60, 0., 16.);
   TH1F * hNvtx   = new TH1F( "hNvtx", "Nvtx", 60, 0., 16.);

   TH1F * hEtJ   = new TH1F( "hEtJ", "EtJ", 30, 0., 150.);
   TH1F * hEtaJ  = new TH1F( "hEtaJ", "EtaJ", 50, -5.0, 5.0);
   TH1F * hbeta  = new TH1F( "hbeta", "beta", 50, 0., 1.0);

   Long64_t nentries = fChain->GetEntriesFast();
   Long64_t nbytes = 0, nb = 0;

   Int_t nev = 0;

   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      nev++;
      Int_t smallbeta = 0;
      Int_t njets = EtJPT->size();
      Int_t nmuon = PtMu->size();
      // muons
      Double_t PtZx = 0.;
      Double_t PtZy = 0.;
      for (unsigned int j = 0; j < nmuon; j++) {
	if(j < 2) {
	  PtZx += (*PtMu)[j] * cos((*PhiMu)[j]); 
	  PtZy += (*PtMu)[j] * sin((*PhiMu)[j]); 
	}
      }
      Double_t PtZ = sqrt(PtZx*PtZx + PtZy*PtZy);
      // jets
      for (unsigned int i = 0; i < njets; i++) {
	Int_t muonmatch = 0;
	// remove jets from muons
	for (unsigned int j = 0; j < nmuon; j++) {
	  // DR muon-jet
	  Double_t DR = deltaR((*EtaJPT)[i], (*PhiJPT)[i], (*EtaMu)[j], (*PhiMu)[j]);
	  if(DR < 0.5) {
	    muonmatch = 1;
	  }
	}
	if(muonmatch == 0 && fabs((*EtaJPT)[i]) < 2.0 ) {
	  if(nvertex <=  200) {
	  //	  if(PtZ < 5.) {
	    hEtJ->Fill((*EtJPT)[i]); 
	    hEtaJ->Fill((*EtaJPT)[i]); 
	    hbeta->Fill((*beta)[i]);
	    /*
	    if((*beta)[i] < 0.02) cout <<" run " << run 
				       <<" event " << event 
				       <<" beta = " << (*beta)[i]
				       <<" etaj = " << (*EtaJPT)[i]
				       <<" ntrk = " << (*Ntrk)[i] << endl;
	    */
	    if( (*beta)[i] < 0.2) smallbeta = 1;
	  } 
	}
      }
      hPtZ->Fill(PtZ);
      hNvtx0->Fill(1.*nvertex);
      if( smallbeta == 1) hNvtx->Fill(1.*nvertex);
   }
   setTDRStyle(0,0);
   // ===> jets: 
   // Et
   TCanvas* c1 = new TCanvas("X","Y",1);
   hEtJ->GetXaxis()->SetTitle("ET jet, GeV");
   hEtJ->GetYaxis()->SetTitle("Nev");
   hEtJ->Draw("hist");
   // eta
   TCanvas* c2 = new TCanvas("X","Y",1);
   hEtaJ->GetXaxis()->SetTitle("eta jet, GeV");
   hEtaJ->GetYaxis()->SetTitle("Nev");
   hEtaJ->Draw("hist");
   // beta
   TCanvas* c3 = new TCanvas("X","Y",1);
   hbeta->GetXaxis()->SetTitle("beta");
   hbeta->GetYaxis()->SetTitle("Nev");
   hbeta->Draw("hist");

   // Nvtx
   setTDRStyle(0,1);
   TCanvas* c4 = new TCanvas("X","Y",1);
   hNvtx0->GetXaxis()->SetTitle("beta");
   hNvtx0->GetYaxis()->SetTitle("Nev");
   hNvtx->Sumw2();
   hNvtx->Divide(hNvtx,hNvtx0,1.,1.,"B");
   hNvtx->SetMaximum(0.500);
   hNvtx->SetMinimum(0.005);
   //   hDZnv2->SetLineStyle(2);
   //   hDZnv2->SetLineWidth(3);
   hNvtx->Draw("PE");

   //pTz
   /*
   TCanvas* c2 = new TCanvas("X","Y",1);
   hPtZ->GetXaxis()->SetTitle("PtZ, GeV");
   hPtZ->GetYaxis()->SetTitle("Nev");
   hPtZ->Draw("hist");
   */
}
