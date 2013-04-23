#include <TCanvas.h>
#include <TH1.h>
#include <TROOT.h>
#include <TStyle.h>
#include <TFile.h>
#include <TColor.h>
#include <THStack.h>
#include <TMath.h>
#include <TLatex.h>

#include <iostream>
#include <iomanip>
#include <sstream>

void setTDRStyle(Int_t xlog, Int_t ylog, Int_t zlog) {

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

void Draw()
{
    
  setTDRStyle(0,1,0);

  // Type 1 MET. Signal area
  TCanvas* c1 = new TCanvas("X","Y",1);

  TLegend *leg = new TLegend(0.20,0.80,0.50,0.90,NULL,"brNDC");

  // data in signal region
  TFile* file = new TFile("VBFHinvisQCDAnalysisMy_Type1MET.root");

  TH1F * hPfMetDphiJJSDataClone = (TH1F*)hPfMetDphiJJSData->Clone();
  hPfMetDphiJJSDataClone->Sumw2();

  TH1F *hrD = (TH1F*)hPfMetDphiJJSData->Clone();
  TH1F *hD_EW_S = (TH1F*)hPfMetDphiJJSData->Clone();
  TH1F *hD_EW_B = (TH1F*)hPfMetDphiJJSData->Clone();
  TH1F *hrD_EW = (TH1F*)hPfMetDphiJJSData->Clone();


  hPfMetDphiJJSData->GetXaxis()->SetTitle("E_{T}^{miss}, GeV");
  hPfMetDphiJJSData->GetYaxis()->SetTitle("Nev");
  hPfMetDphiJJSData->SetMinimum(1.);
  hPfMetDphiJJSData->SetMaximum(10000.);
  hPfMetDphiJJSData->SetMarkerStyle(20);
  hPfMetDphiJJSData->Draw("E1P");
  leg->SetFillColor(10);
  leg->AddEntry(hPfMetDphiJJSData,"Data","PL");

  // EW MC in signal region
  TFile* file = new TFile("AnneMarieEWK_METType1_My.root");

  TH1F *metRangeTotal_DPhiSIGNALClone = (TH1F*)metRangeTotal_DPhiSIGNAL->Clone();
  metRangeTotal_DPhiSIGNALClone->Sumw2();

  metRangeTotal_DPhiSIGNAL->SetLineWidth(2);
  metRangeTotal_DPhiSIGNAL->SetLineStyle(1);
  metRangeTotal_DPhiSIGNAL->Draw("SAMEE1");
  leg->AddEntry(metRangeTotal_DPhiSIGNAL,"EW MC","PL");
  leg->Draw();

  TLatex *t = new TLatex();
  t->SetTextSize(0.042);
  t->DrawLatex(80.,10.,"#Delta#phi_{jj} < 1.0");
  t->DrawLatex(80.,4.,"Type 1 MET");
  t->DrawLatex(60.,2.,"tag.jets with no #mu's");

  c1->SaveAs("met_type1_s_my.gif");

  // Type 1 MET. Bkg area
  TCanvas* c2 = new TCanvas("X","Y",1);

  TLegend *leg = new TLegend(0.60,0.40,0.90,0.50,NULL,"brNDC");

  // data in Bkg region
  TFile* file = new TFile("VBFHinvisQCDAnalysisMy_Type1MET.root");

  TH1F * hPfMetDphiJJBDataClone = (TH1F*)hPfMetDphiJJBData->Clone();
  hPfMetDphiJJBDataClone->Sumw2();

  hPfMetDphiJJBData->GetXaxis()->SetTitle("E_{T}^{miss}, GeV");
  hPfMetDphiJJBData->GetYaxis()->SetTitle("Nev");
  hPfMetDphiJJBData->SetMinimum(1.);
  //  hPfMetDphiJJBData->SetMaximum(100000.);
  hPfMetDphiJJBData->SetMarkerStyle(20);
  hPfMetDphiJJBData->Draw("E1P");
  leg->SetFillColor(10);
  leg->AddEntry(hPfMetDphiJJBData,"Data","PL");

  // EW MC in signal region
  TFile* file = new TFile("AnneMarieEWK_METType1_My.root");

  TH1F *metRangeTotal_DPhiQCDClone = (TH1F*)metRangeTotal_DPhiQCD->Clone();
  metRangeTotal_DPhiQCDClone->Sumw2();

  metRangeTotal_DPhiQCD->SetLineWidth(2);
  metRangeTotal_DPhiQCD->SetLineStyle(1);
  metRangeTotal_DPhiQCD->Draw("SAMEE1");
  leg->AddEntry(metRangeTotal_DPhiQCD,"EW MC","PL");
  leg->Draw();

  TLatex *t = new TLatex();
  t->SetTextSize(0.042);
  t->DrawLatex(80.,10.,"#Delta#phi_{jj} > 2.6");
  t->DrawLatex(80.,4.,"Type 1 MET");
  t->DrawLatex(60.,2.,"tag.jets with no #mu's");

  c2->SaveAs("met_type1_b_my.gif");

  setTDRStyle(0,0,0);

  TCanvas* c3 = new TCanvas("X","Y",1);

  TLegend *leg = new TLegend(0.20,0.80,0.80,0.90,NULL,"brNDC");

  hrD->GetXaxis()->SetTitle("E_{T}^{miss}, GeV");
  hrD->GetYaxis()->SetTitle("multijet extrapolation factor r");
  hrD->Divide(hPfMetDphiJJSDataClone,hPfMetDphiJJBDataClone,1.,1.,"");
  hrD->SetMinimum(0.);
  hrD->SetMaximum(0.07);
  hrD->SetMarkerStyle(24);
  hrD->SetAxisRange(20.,120.,"X");
  hrD->SetTitleOffset(1.5, "Y");
  hrD->Draw("EP");

  hD_EW_S->Add(hPfMetDphiJJSDataClone,metRangeTotal_DPhiSIGNALClone,1.,-1.); 
  hD_EW_B->Add(hPfMetDphiJJBDataClone,metRangeTotal_DPhiQCDClone,1.,-1.);
  hrD_EW->Divide(hD_EW_S,hD_EW_B,1.,1.,"");
  hrD_EW->SetMarkerStyle(20);
  hrD_EW->Draw("SAMEEP");

  leg->AddEntry(hrD,"Data with no EW subtraction","PL");
  leg->AddEntry(hrD_EW,"Data with MC EW subtraction","PL");
  leg->Draw();

  TLatex *t = new TLatex();
  t->SetTextSize(0.042);
  t->DrawLatex(80.,0.015,"Type 1 MET");
  t->DrawLatex(60.,0.010,"tag.jets with no #mu's");


  c3->SaveAs("rD_type1_my.gif");

}

