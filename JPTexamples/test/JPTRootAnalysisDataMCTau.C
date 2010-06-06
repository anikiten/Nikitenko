#define JPTRootAnalysisDataMCTau_cxx
#include "JPTRootAnalysisDataMCTau.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

Float_t JPTRootAnalysisDataMCTau::deltaPhi(Float_t phi1, Float_t phi2)
{
  Float_t pi = 3.1415927;
  Float_t dphi = fabs(phi1 - phi2);
  if(dphi >= pi) dphi = 2. * pi - dphi; 
  return dphi;
}

void JPTRootAnalysisDataMCTau::setTDRStyle(Int_t ylog) {

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
  tdrStyle->SetOptLogx(0);
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

void JPTRootAnalysisDataMCTau::Loop()
{
//   In a ROOT session, you can do:
//      Root > .L JPTRootAnalysisDataMCTau.C
//      Root > JPTRootAnalysisDataMCTau t
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

   Long64_t nentries = fChain->GetEntriesFast();

   // histos

   TH1F * hEtRaw     = new TH1F( "hEtRaw", "EtRaw", 100, 0., 100.);
   TH1F * hEtaRaw    = new TH1F( "hEtaRaw", "EtaRaw", 20, -2.0, 2.0);

   TH1F * hDRjettrk  = new TH1F( "hDRjettrk", "DRjettrk", 30, 0., 0.6);
   TH1F * hd0ltr     = new TH1F( "hd0ltr", "d0ltr", 25, 0., 0.05);
   TH1F * hptltr     = new TH1F( "hptltr", "ptltr", 100, 0., 20);
   TH1F * hntrsign   = new TH1F( "hntrsign", "ntrsign", 20, 0., 20);
   TH1F * hntrisol   = new TH1F( "hntrisol", "ntrisol", 20, 0., 20);
   TH1F * hptminsign = new TH1F( "hptminsign", "ptminsign", 100, 0., 20);
   TH1F * hptminisol = new TH1F( "hptminisol", "ptminisol", 100, 0., 20);
   TH1F * hdzmaxltr  = new TH1F( "hdzmaxltr", "dzmaxltr", 50, 0., 0.5);
   TH1F * hpisol     = new TH1F( "hpisol", "pisol", 20, 0., 10.);

   const Int_t netbins = 6;
   const Int_t netcuts = netbins+1;
   Double_t et[netcuts]={10., 15., 20., 25., 30., 40., 60.};
   TH1F * hetraw            = new TH1F( "hetraw","etraw",netbins, et);
   TH1F * hetrawLeadtrk     = new TH1F( "hetrawLeadtrk", "etrawLeadtrk",netbins, et); 
   TH1F * hetrawTrkisol     = new TH1F( "hetrawTrkisol", "etrawTrkisol",netbins, et); 
   TH1F * hetrawElrejec     = new TH1F( "hetrawElrejec", "etrawElrejec",netbins, et); 


   TH1F * hetaraw           = new TH1F( "hetaraw", "etaraw", 5, 0., 2.0);
   TH1F * hetarawLeadtrk    = new TH1F( "hetarawLeadtrk", "etarawLeadtrk", 5, 0., 2.0);
   TH1F * hetarawTrkisol    = new TH1F( "hetarawTrkisol", "etarawTrkisol", 5, 0., 2.0);
   TH1F * hetarawElrejec    = new TH1F( "hetarawElrejec", "etarawElrejec", 5, 0., 2.0);

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;

      if(jtau >= 2) {
	Float_t dphi = deltaPhi( (*PhiRaw)[0] , (*PhiRaw)[1] );
	if(dphi > 2.14) {
	  if( fabs((*EtaRaw)[0]) < 2.0 && fabs((*EtaRaw)[1]) < 2.0 ) {
	    if( (*tcEt)[0] > 10. && (*tcEt)[1] > 10. ) {
	      // et , eta raw
	      for (unsigned int i = 0; i < 2; i++) {
		hEtRaw->Fill((*tcEt)[i]);
		hEtaRaw->Fill((*tcEta)[i]);
	      }
	      // DR jet track 
	      for (unsigned int i = 0; i < 2; i++) {
		hDRjettrk->Fill((*drltrjet)[i]);
	      }
	      
	      // ip of tracks
	      for (unsigned int i = 0; i < 2; i++) {
		hd0ltr->Fill((*d0ltr)[i]);
	      }
	      
	      // pt of ltr
	      for (unsigned int i = 0; i < 2; i++) {
		hptltr->Fill((*ptltr)[i]);
	      }
	      
	      // ntr in signal cone
	      for (unsigned int i = 0; i < 2; i++) {
		hntrsign->Fill((*ntrsign)[i]);
	      }
	      
	      // ntr in isol cone
	      for (unsigned int i = 0; i < 2; i++) {
		hntrisol->Fill( (*ntrisol)[i] - (*ntrsign)[i] );
	      }
	      
	      // pt min in signal cone
	      for (unsigned int i = 0; i < 2; i++) {
		hptminsign->Fill( (*ptminsign)[i]);
	      }
	      
	      // pt min in isol cone
	      for (unsigned int i = 0; i < 2; i++) {
		hptminisol->Fill( (*ptminisol)[i]);
	      }
	      
	      // dz max ltr-tr
	      for (unsigned int i = 0; i < 2; i++) {
		hdzmaxltr->Fill( (*dzmaxltr)[i]);
	      }
	    
	      // e.m. isolation
	      for (unsigned int i = 0; i < 2; i++) {
		hpisol->Fill( (*emisolat)[i]);
	      }
	    
	      //
	      for (unsigned int i = 0; i < 2; i++) {
		hetraw->Fill( (*tcEt)[i] );
		hetaraw->Fill( fabs((*tcEta)[i]) );     
		if( (*dByLeadingTrackPtCut)[i] == 1) {
		  hetrawLeadtrk->Fill( (*tcEt)[i] );
		  hetarawLeadtrk->Fill( fabs((*tcEta)[i]) );     
		}	
		if( (*dByIsolation)[i] == 1 ) {
		  hetrawTrkisol->Fill( (*tcEt)[i] );
		  hetarawTrkisol->Fill( fabs((*tcEta)[i]) );     
		}
		if( ((*dAgainstElectron)[i] == 1)  &&  ((*dByIsolation)[i] == 1) ) {
		  hetrawElrejec->Fill( (*tcEt)[i] );
		  hetarawElrejec->Fill( fabs((*tcEta)[i]) );     
		}
	      }
	    }
	  }
	}
      }
   }

   setTDRStyle(0);
   gStyle->SetOptFit();

   TFile efile("mctau7TeV.root","recreate");
   //   TFile efile("datatau7TeV.root","recreate");
   hEtRaw->Write();
   hEtaRaw->Write();
   hDRjettrk->Write();
   hd0ltr->Write();
   hptltr->Write();
   hntrsign->Write();
   hntrisol->Write();
   hptminsign->Write();
   hptminisol->Write();
   hdzmaxltr->Write();
   hpisol->Write();
   hetraw->Write();
   hetaraw->Write();     

   hetrawLeadtrk->Write();
   hetrawTrkisol->Write();
   hetrawElrejec->Write();

   hetarawLeadtrk->Write();
   hetarawTrkisol->Write();
   hetarawElrejec->Write();

   efile.Close();

   TCanvas* c1 = new TCanvas("X","Y",1);
   hDRjettrk->GetXaxis()->SetTitle("DR jet tracks");
   hDRjettrk->GetYaxis()->SetTitle("Nev");
   hDRjettrk->Draw("hist");

   TCanvas* c2 = new TCanvas("X","Y",1);
   hd0ltr->GetXaxis()->SetTitle("track ip");
   hd0ltr->GetYaxis()->SetTitle("Nev");
   hd0ltr->Draw("hist");

   TCanvas* c3 = new TCanvas("X","Y",1);
   hptltr->GetXaxis()->SetTitle("pt ltr");
   hptltr->GetYaxis()->SetTitle("Nev");
   hptltr->Draw("hist");

   TCanvas* c4 = new TCanvas("X","Y",1);
   hntrsign->GetXaxis()->SetTitle("Ntrk in signal cone");
   hntrsign->GetYaxis()->SetTitle("Nev");
   hntrsign->Draw("hist");

   TCanvas* c5 = new TCanvas("X","Y",1);
   hntrisol->GetXaxis()->SetTitle("Ntrk in isolation annulus");
   hntrisol->GetYaxis()->SetTitle("Nev");
   hntrisol->Draw("hist");

   TCanvas* c6 = new TCanvas("X","Y",1);
   hptminsign->GetXaxis()->SetTitle("pt min in sign cone");
   hptminsign->GetYaxis()->SetTitle("Nev");
   hptminsign->Draw("hist");

   TCanvas* c7 = new TCanvas("X","Y",1);
   hptminisol->GetXaxis()->SetTitle("pt min in isol cone");
   hptminisol->GetYaxis()->SetTitle("Nev");
   hptminisol->Draw("hist");

   TCanvas* c8 = new TCanvas("X","Y",1);
   hdzmaxltr->GetXaxis()->SetTitle("dz max ltr");
   hdzmaxltr->GetYaxis()->SetTitle("Nev");
   hdzmaxltr->Draw("hist");

   TCanvas* c9 = new TCanvas("X","Y",1);
   hpisol->GetXaxis()->SetTitle("e.m. isolation");
   hpisol->GetYaxis()->SetTitle("Nev");
   hpisol->Draw("hist");

   TCanvas* c10 = new TCanvas("X","Y",1);
   hetraw->GetXaxis()->SetTitle("Et raw");
   hetraw->GetYaxis()->SetTitle("Nev");
   hetraw->Draw("hist");
   //   hetraw->SetMaximum(200.0);
   hetraw->SetMinimum(0.5);
   //   hetrawLeadtrk->Draw("same");
   hetrawTrkisol->Draw("same");

   TCanvas* c11 = new TCanvas("X","Y",1);
   hEtRaw->GetXaxis()->SetTitle("Et raw");
   hEtRaw->GetYaxis()->SetTitle("Nev");
   hEtRaw->Draw("hist");
}
