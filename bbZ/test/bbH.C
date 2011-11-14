#define bbH_cxx
#include "bbH.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream.h>

void bbH::setTDRStyle(Int_t xlog, Int_t ylog, Int_t zlog) {

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

void bbH::Loop()
{
//   In a ROOT session, you can do:
//      Root > .L bbH.C
//      Root > bbH t
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

   TH1F * hpTH140   = new TH1F( "hpTH140", "pTH140", 28, 0., 140.);
   TH1F * hyH140    = new TH1F( "hyH140 ", "yH140  ", 12, 0., 2.4);

   TH1F * hpTb140    = new TH1F( "hpTb140", "pTb140", 24, 20., 140.);
   TH1F * hpTb140NLO = new TH1F( "hpTb140NLO", "pTb140NLO", 24, 20., 140.);
   TH1F * hyb140     = new TH1F( "hyb140 ", "yb140  ", 12, 0., 2.4);
   TH1F * hyb140NLO  = new TH1F( "hyb140NLO", "yb140NLO", 12, 0., 2.4);

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      hpTH140->Fill(pTH);
      hyH140->Fill(fabs(yH));
      if(nbjets != 0) {
	hpTb140->Fill(pTb);
	hyb140->Fill(fabs(yb));
      }
      
   }

   // read y-b
   std::ifstream in20("y-bjet_numbers.dat");
   std::string line;
   while( std::getline( in20, line)){
     istringstream linestream(line);
     Double_t y, xslo, xsnlo, kf;
     linestream>>y>>xslo>>xsnlo>>kf;
     cout <<" y = " << y <<" xslo " << xslo <<" xsnlo " << xsnlo <<" kf " << kf << endl;
     hyb140NLO->Fill(y,xsnlo);
   }
   Double_t scale = 1./ hyb140NLO->Integral(); 
   hyb140NLO->Scale(scale);
   

   // read pT-b
   std::ifstream in20("pT-bjet_numbers.dat");
   line;
   while( std::getline( in20, line)){
     istringstream linestream(line);
     Double_t pT, xslo, xsnlo, kf;
     linestream>>pT>>xslo>>xsnlo>>kf;
     cout <<" pT = " << pT <<" xslo " << xslo <<" xsnlo " << xsnlo <<" kf " << kf << endl;
     hpTb140NLO->Fill(pT,xsnlo);
   }
   Double_t scale = 1./ hpTb140NLO->Integral(); 
   hpTb140NLO->Scale(scale);


   setTDRStyle(0,1,0);
   TCanvas* c1 = new TCanvas("X","Y",1);
   hpTH140->GetXaxis()->SetTitle("p_{T}^{H}, GeV");
   hpTH140->GetYaxis()->SetTitle("");
   scale = 1./ hpTH140->Integral();
   hpTH140->Scale(scale);
   hpTH140->Draw("hist");
   c1->SaveAs("pTH140.eps");

   setTDRStyle(0,0,0);
   TCanvas* c2 = new TCanvas("X","Y",1);
   hyH140->GetXaxis()->SetTitle("y^{H}, GeV");
   hyH140->GetYaxis()->SetTitle("");
   scale = 1./ hyH140->Integral();
   hyH140->Scale(scale);
   hyH140->Draw("hist");
   c2->SaveAs("yH140.eps");

   // pTb
   setTDRStyle(0,1,0);
   TCanvas* c3 = new TCanvas("X","Y",1);
   hpTb140->GetXaxis()->SetTitle("p_{T}^{b}, GeV");
   hpTb140->GetYaxis()->SetTitle("");
   scale = 1./ hpTb140->Integral();
   hpTb140->Scale(scale);
   hpTb140->SetMaximum(0.500);
   hpTb140->SetMinimum(0.001);
   hpTb140->SetLineStyle(1);
   hpTb140->SetLineWidth(3);
   hpTb140->Draw("hist");

   hpTb140NLO->SetLineStyle(2);
   hpTb140NLO->SetLineWidth(3);
   hpTb140NLO->Draw("same");

   TLegend *leg = new TLegend(0.5,0.8,0.9,0.9,NULL,"brNDC");
   leg->SetFillColor(10);
   leg->AddEntry(hpTb140,"PYTHIA","L");
   leg->AddEntry(hpTb140NLO,"NLO","L");
   leg->Draw();

   c3->SaveAs("pTb140.eps");

   /*
   // y b
   setTDRStyle(0,0,0);
   TCanvas* c4 = new TCanvas("X","Y",1);
   hyb140->GetXaxis()->SetTitle("y^{b}");
   hyb140->GetYaxis()->SetTitle("");
   scale = 1./ hyb140->Integral();
   hyb140->Scale(scale);
   hyb140->SetMaximum(0.16);
   hyb140->SetMinimum(0.00);
   hyb140->SetLineStyle(1);
   hyb140->SetLineWidth(3);
   hyb140->Draw("hist");

   hyb140NLO->SetLineStyle(2);
   hyb140NLO->SetLineWidth(3);
   hyb140NLO->Draw("same");

   TLegend *leg = new TLegend(0.5,0.8,0.9,0.9,NULL,"brNDC");
   leg->SetFillColor(10);
   leg->AddEntry(hyb140,"PYTHIA","L");
   leg->AddEntry(hyb140NLO,"NLO","L");
   leg->Draw();

   c4->SaveAs("yb140.eps");
   */
}
