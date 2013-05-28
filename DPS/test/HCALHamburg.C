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
    
  setTDRStyle(0,0,0);

  // eta = 0.25
  TCanvas* c1 = new TCanvas("X","Y",1);

  Float_t pt[6]  = {20., 25., 30., 35., 40., 45.};
  Float_t rms_st_eta025[6] = {0.30,0.28,0.27,0.25,0.24,0.24};
  Float_t rms_up_eta025[6] = {0.26,0.22,0.21,0.19,0.18,0.17};

  TGraph *graph_st = new TGraph(6,pt,rms_st_eta025);
  TGraph *graph_up = new TGraph(6,pt,rms_up_eta025);

  graph_st->GetXaxis()->SetTitle("p_{T}^{b-quark}, GeV");
  graph_st->GetYaxis()->SetTitle("RMS[(p_{T}^{rec}-p_{T}^{gen})/p_{T}^{gen}]");
  graph_st->SetMinimum(0.10);
  graph_st->SetMaximum(0.40);
  graph_st->SetMarkerStyle(20);
  graph_st->GetXaxis()->SetRangeUser(0.,60.);
  graph_st->GetYaxis()->SetTitleSize(0.05);
  graph_st->GetYaxis()->SetLabelSize(0.04);
  graph_st->Draw("AP");

  graph_up->SetMarkerStyle(24);
  graph_up->Draw("sameP");

  TLegend *leg = new TLegend(0.40,0.80,0.80,0.90,NULL,"brNDC");
  leg->SetFillColor(10);
  leg->AddEntry(graph_st,"present HCAL","P");
  leg->AddEntry(graph_up,"segmented HCAL","P");
  leg->Draw();

  TLatex *t = new TLatex();
  t->SetTextSize(0.050);
  t->DrawLatex(25.,0.12,"#eta = 0.25");

  c1->SaveAs("rms_ptb_quark_025.gif");

  // eta = 2.25
  TCanvas* c2 = new TCanvas("X","Y",1);

  Float_t pt[6]  = {20., 25., 30., 35., 40., 45.};
  Float_t rms_st_eta025[6] = {0.28,0.26,0.25,0.24,0.23,0.23};
  Float_t rms_up_eta025[6] = {0.21,0.17,0.16,0.15,0.14,0.14};

  TGraph *graph_st = new TGraph(6,pt,rms_st_eta025);
  TGraph *graph_up = new TGraph(6,pt,rms_up_eta025);

  graph_st->GetXaxis()->SetTitle("p_{T}^{b-quark}, GeV");
  graph_st->GetYaxis()->SetTitle("RMS[(p_{T}^{rec}-p_{T}^{gen})/p_{T}^{gen}]");
  graph_st->SetMinimum(0.10);
  graph_st->SetMaximum(0.40);
  graph_st->SetMarkerStyle(20);
  graph_st->GetXaxis()->SetRangeUser(0.,60.);
  graph_st->GetYaxis()->SetTitleSize(0.05);
  graph_st->GetYaxis()->SetLabelSize(0.04);
  graph_st->Draw("AP");

  graph_up->SetMarkerStyle(24);
  graph_up->Draw("sameP");

  TLegend *leg = new TLegend(0.40,0.80,0.80,0.90,NULL,"brNDC");
  leg->SetFillColor(10);
  leg->AddEntry(graph_st,"present HCAL","P");
  leg->AddEntry(graph_up,"segmented HCAL","P");
  leg->Draw();

  TLatex *t = new TLatex();
  t->SetTextSize(0.050);
  t->DrawLatex(25.,0.12,"#eta = 2.25");

  c2->SaveAs("rms_ptb_quark_225.gif");
}

