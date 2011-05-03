#define JPTAnalysis_Data_cxx
#include "JPTAnalysis_Data.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

Float_t JPTAnalysis_Data::deltaPhi(Float_t phi1, Float_t phi2)
{
  Float_t pi = 3.1415927;
  Float_t dphi = fabs(phi1 - phi2);
  if(dphi >= pi) dphi = 2. * pi - dphi; 
  return dphi;
}

void JPTAnalysis_Data::setTDRStyle(Int_t xlog, Int_t ylog) {

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

void JPTAnalysis_Data::Loop()
{
//   In a ROOT session, you can do:
//      Root > .L JPTAnalysis_Data.C
//      Root > JPTAnalysis_Data t
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

   TH1F * hNV      = new TH1F( "hNV", "NV", 10, 0., 10);

   TH1F * hNtrkV1  = new TH1F( "hNtrkV1", "NtrkV1", 30, 0., 30);
   TH1F * hNtrkV2  = new TH1F( "hNtrkV2", "NtrkV2", 30, 0., 30);
   TH1F * hNtrkV3  = new TH1F( "hNtrkV3", "NtrkV3", 30, 0., 30);
   TH1F * hNtrkV4  = new TH1F( "hNtrkV4", "NtrkV4", 30, 0., 30);
   TH1F * hNtrkV5  = new TH1F( "hNtrkV5", "NtrkV5", 30, 0., 30);
   TH1F * hNtrkV6  = new TH1F( "hNtrkV6", "NtrkV6", 30, 0., 30);
   TH1F * hNtrkV7  = new TH1F( "hNtrkV7", "NtrkV7", 30, 0., 30);

   TH1F * hDZnv2      = new TH1F( "hDZnv2", "DZnv2", 400, 0., 20);
   TH1F * hDZnv5      = new TH1F( "hDZnv5", "DZnv5", 400, 0., 20);
   TH1F * hDZnv8      = new TH1F( "hDZnv8", "DZnv8", 400, 0., 20);

   TH1F * hpTj      = new TH1F( "hpTj", "pTj", 30, 0., 150);

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;

      hNV->Fill(nvertex);  
      if(nvertex == 2) hDZnv2->Fill(DZmin);
      if(nvertex == 5) hDZnv5->Fill(DZmin);
      if(nvertex == 8) hDZnv8->Fill(DZmin);
    
	for(unsigned int i = 0; i < (*EtJPT).size(); i++) {
	if( (fabs((*EtaJPT)[i]) < 2.0) && ((*EtJPT)[i] > 20.) && ((*EtJPT)[i] < 100.) ) {
	  hpTj->Fill((*EtJPT)[i]);
	  if(nvertex == 1) {
	    hNtrkV1->Fill((*Ntrk)[i]);
	  }
	  if(nvertex == 4) {
	    hNtrkV4->Fill((*Ntrk)[i]);
	  }
	  if(nvertex == 7) {
	    hNtrkV7->Fill((*Ntrk)[i]);
	  }
	}
      }
      // if (Cut(ientry) < 0) continue;
   }

   Double_t scale = 1./hNtrkV1->Integral();
   hNtrkV1->Scale(scale);

   scale = 1./hNtrkV4->Integral();
   hNtrkV4->Scale(scale);

   scale = 1./hNtrkV7->Integral();
   hNtrkV7->Scale(scale);

   setTDRStyle(0,0);
   gStyle->SetOptFit();
   TCanvas* c0 = new TCanvas("X","Y",1);
   hNV->GetXaxis()->SetTitle("N primary off-line vertices");
   hNV->GetYaxis()->SetTitle("Nev");
   hNV->SetLineWidth(3);
   hNV->SetMaximum(3000.0);
   hNV->Draw("hist");
   TLatex *t = new TLatex();
   t->SetTextSize(0.04);
   t->DrawLatex(0.5,2500,"/Run2011A/Jet/AOD/PromptReco-v1. Run 161312");
   c0->SaveAs("NV.gif");

   TCanvas* c1 = new TCanvas("X","Y",1);
   hNtrkV1->GetXaxis()->SetTitle("N tracks");
   hNtrkV1->GetYaxis()->SetTitle("Nev");
   hNtrkV1->SetLineWidth(3);
   hNtrkV1->SetMaximum(0.16);
   hNtrkV1->Draw("hist");

   hNtrkV4->SetLineWidth(3);
   hNtrkV4->SetLineStyle(2);
   hNtrkV4->Draw("same");

   hNtrkV7->SetLineWidth(3);
   hNtrkV7->SetLineStyle(3);
   hNtrkV7->Draw("same");

   TLegend *leg = new TLegend(0.5,0.4,0.9,0.6,NULL,"brNDC");
   leg->SetFillColor(10);
   leg->AddEntry(hNtrkV1,"Npvtx = 1","L");
   leg->AddEntry(hNtrkV4,"Npvtx = 4","L");
   leg->AddEntry(hNtrkV7,"Npvtx = 7","L");
   leg->Draw();

   TLatex *t = new TLatex();
   t->SetTextSize(0.045);
   t->DrawLatex(1.0,0.15,"/Run2011A/Jet/AOD/PromptReco-v1");
   t->DrawLatex(13.0,0.14,"Run 161312");
   t->DrawLatex(13.0,0.12,"20 < p_{T}^{JPT raw} < 100 GeV");
   t->DrawLatex(13.0,0.11,"| #eta | < 2.0");
   c1->SaveAs("Ntrk20.gif");

   setTDRStyle(1,1);
   gStyle->SetOptFit();
   TCanvas* c2 = new TCanvas("X","Y",1);
   hDZnv2->GetXaxis()->SetTitle("#Delta Z_{min}(signal PV - PU PV), cm");
   hDZnv2->SetAxisRange(0.05, 20., "X");
   hDZnv2->GetYaxis()->SetTitle("Nev / 0.05 cm");
   hDZnv2->SetLineStyle(2);
   hDZnv2->SetLineWidth(3);
   hDZnv2->SetMaximum(100.0);
   hDZnv2->Draw("hist");

   hDZnv5->SetLineStyle(3);
   hDZnv5->SetLineWidth(3);
   hDZnv5->Draw("same");


   hDZnv8->SetLineStyle(1);
   hDZnv8->SetLineWidth(3);
   hDZnv8->Draw("same");

   TLegend *leg = new TLegend(0.15,0.6,0.4,0.8,NULL,"brNDC");
   leg->SetFillColor(10);
   leg->AddEntry(hDZnv2,"Npvtx = 2","L");
   leg->AddEntry(hDZnv5,"Npvtx = 5","L");
   leg->AddEntry(hDZnv8,"Npvtx = 8","L");
   leg->Draw();

   TLatex *t = new TLatex();
   t->SetTextSize(0.04);
   t->DrawLatex(0.1,70,"/Run2011A/Jet/AOD/PromptReco-v1");
   t->DrawLatex(1.0,50,"Run 161312");
   c2->SaveAs("DZmin.gif");

   setTDRStyle(0,0);
   gStyle->SetOptFit();
   TCanvas* c3 = new TCanvas("X","Y",1);
   hpTj->GetXaxis()->SetTitle("p_{T}^{JPT raw}, GeV");
   hpTj->GetYaxis()->SetTitle("Nev / 5 GeV");
   hpTj->SetLineWidth(3);
   //   hpTj->SetMaximum(100.0);
   hpTj->Draw("hist");
   TLatex *t = new TLatex();
   t->SetTextSize(0.04);
   t->DrawLatex(30,2400,"/Run2011A/Jet/AOD/PromptReco-v1");
   t->DrawLatex(60,2200,"Run 161312");
   t->SetTextSize(0.05);
   t->DrawLatex(60,1500,"| #eta | < 2.0");
   c3->SaveAs("pTj.gif");
}
