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

  TFile* file = new TFile("EW_AM_withTrgWeights.root");
  //  TFile* file = new TFile("BkgForQCDEstimation_new_cjv.root");
  TH1F * hEWS = (TH1F*)metRangeTotal_DPhiSIGNAL->Clone();
  TH1F * hEWB = (TH1F*)metRangeTotal_DPhiQCD->Clone();

  TFile* file = new TFile("VBFHinvisQCDAnalysisV10_Type01MET.root");
  TH1F * hDphiJJMET70RatioToCJV = (TH1F*)hDphiJJmJJ1200DetaJJ42MET70->Clone();
  TH1F * hDphiJJMET70RatioToCJV24 = (TH1F*)hDphiJJmJJ1200DetaJJ42MET70->Clone();
  TH1F * hDphiJJRatioToCJV = (TH1F*)hDphiJJmJJ1200DetaJJ42->Clone();
  TH1F * hDphiJJRatioToCJVM24 = (TH1F*)hDphiJJmJJ1200DetaJJ42->Clone();
  TH1F * hDphiJJRatioToCJV24 = (TH1F*)hDphiJJmJJ1200DetaJJ42->Clone();
  TH1F * hEtaJ3RatioSovB = (TH1F*)hEtaJ3S->Clone();

  TH1F * hPFMET1mJJ1200DetaJJ42QCDB = (TH1F*)hPFMET1mJJ1200DetaJJ42B->Clone(); 
  TH1F * hPFMET1mJJ1200DetaJJ42QCDBshifted = (TH1F*)hPFMET1mJJ1200DetaJJ42B->Clone(); 
  TH1F * hPFMET1mJJ1200DetaJJ42QCDS = (TH1F*)hPFMET1mJJ1200DetaJJ42S->Clone(); 
  TH1F * hPFMET1mJJ1200DetaJJ42SovBshifted = (TH1F*)hPFMET1mJJ1200DetaJJ42B->Clone(); 

  // all about CJV and tagging jets

  setTDRStyle(0,1,0);
  TCanvas* c1 = new TCanvas("X","Y",1);
  TLegend *leg = new TLegend(0.2,0.80,0.50,0.90,NULL,"brNDC");

  /*
  // data in signal region
  hDphiJJmJJ1200DetaJJ42MET70->Sumw2(); 
  hDphiJJmJJ1200DetaJJ42MET70->GetXaxis()->SetTitle("#Delta#phi_{jj}, rad");
  hDphiJJmJJ1200DetaJJ42MET70->GetYaxis()->SetTitle("Nev");
  hDphiJJmJJ1200DetaJJ42MET70->SetMinimum(10.);
  hDphiJJmJJ1200DetaJJ42MET70->SetMaximum(500000.);
  hDphiJJmJJ1200DetaJJ42MET70->SetMarkerStyle(20);
  hDphiJJmJJ1200DetaJJ42MET70->Draw("E1P");

  hDphiJJmJJ1200DetaJJ42MET70cjveto->SetMarkerStyle(24);
  hDphiJJmJJ1200DetaJJ42MET70cjveto->Draw("sameE1P");

  leg->SetFillColor(10);
  leg->AddEntry(hDphiJJmJJ1200DetaJJ42MET70,"no CJV","PL");
  leg->AddEntry(hDphiJJmJJ1200DetaJJ42MET70cjveto,"CJV p_{T}^{j3}>30 GeV","PL");
  leg->Draw();

  TLatex *t = new TLatex();
  t->SetTextSize(0.042);
  t->DrawLatex(2.0,30.,"E_{T}^{miss}>70 GeV");
  c1->SaveAs("dphi_jj_met70.gif");
  c1->SaveAs("dphi_jj_met70.pdf");

  setTDRStyle(0,1,0);
  TCanvas* c11 = new TCanvas("X","Y",1);
  TLegend *leg = new TLegend(0.20,0.70,0.50,0.80,NULL,"brNDC");
  hDphiJJmJJ1200DetaJJ42->Sumw2(); 
  hDphiJJmJJ1200DetaJJ42->GetXaxis()->SetTitle("#Delta#phi_{jj}, rad");
  hDphiJJmJJ1200DetaJJ42->GetYaxis()->SetTitle("Nev");
  hDphiJJmJJ1200DetaJJ42->SetMinimum(10.);
  hDphiJJmJJ1200DetaJJ42->SetMaximum(500000.);
  hDphiJJmJJ1200DetaJJ42->SetMarkerStyle(20);
  hDphiJJmJJ1200DetaJJ42->Draw("E1P");

  hDphiJJmJJ1200DetaJJ42cjveto->SetMarkerStyle(24);
  hDphiJJmJJ1200DetaJJ42cjveto->Draw("sameE1P");

  leg->SetFillColor(10);
  leg->AddEntry(hDphiJJmJJ1200DetaJJ42,"no CJV","PL");
  leg->AddEntry(hDphiJJmJJ1200DetaJJ42cjveto,"CJV p_{T}^{j3}>30 GeV","PL");
  leg->Draw();

  TLatex *t = new TLatex();
  t->SetTextSize(0.042);
  t->DrawLatex(2.0,30.,"no E_{T}^{miss} cut");
  c11->SaveAs("dphi_jj.gif");
  c11->SaveAs("dphi_jj.pdf");
*/

  setTDRStyle(0,1,0);
  TCanvas* c2 = new TCanvas("X","Y",1);
  TLegend *leg = new TLegend(0.15,0.75,0.80,0.90,NULL,"brNDC");
  hDphiJJMET70RatioToCJV->GetXaxis()->SetTitle("#Delta#phi_{jj}, rad");
  hDphiJJMET70RatioToCJV->GetYaxis()->SetTitle("#Delta#phi_{jj} after CJV/#Delta#phi_{jj}");

  hDphiJJmJJ1200DetaJJ42->Sumw2(); 
  hDphiJJmJJ1200DetaJJ42MET70->Sumw2(); 

  hDphiJJMET70RatioToCJV->Divide(hDphiJJmJJ1200DetaJJ42MET70cjveto,
				 hDphiJJmJJ1200DetaJJ42MET70,1.,1.,"");
  hDphiJJMET70RatioToCJV->SetMinimum(0.05);
  hDphiJJMET70RatioToCJV->SetMaximum(2.00);
  hDphiJJMET70RatioToCJV->SetMarkerStyle(20);
  hDphiJJMET70RatioToCJV->SetTitleOffset(1.5, "Y");
  hDphiJJMET70RatioToCJV->Draw("E1P");

  hDphiJJRatioToCJV->Divide(hDphiJJmJJ1200DetaJJ42cjveto,
			    hDphiJJmJJ1200DetaJJ42,1.,1.,"");
  hDphiJJRatioToCJV->SetMarkerStyle(24);
  hDphiJJRatioToCJV->Draw("sameE1P");
  //////////////////////////////////////////////////////////////////////////////

  Double_t sum_phisb = 0.;
  Double_t sum_phisa = 0.;

  for (Int_t iphi = 1; iphi <= 17; iphi++) {
    if(iphi <= 5) {
      Double_t sb = hDphiJJmJJ1200DetaJJ42->GetBinContent(iphi);
      Double_t sa = hDphiJJmJJ1200DetaJJ42cjveto->GetBinContent(iphi);
      sum_phisb += sb;
      sum_phisa += sa;
    }
  }

  cout <<" sum_phisb = " << sum_phisb
       <<" sum_phisa = " << sum_phisa
       <<" ev with jet3 = " << sum_phisb-sum_phisa
       <<" eff cjv = " << sum_phisa/sum_phisb << endl;

  leg->SetFillColor(10);
  leg->AddEntry(hDphiJJMET70RatioToCJV,"E_{T}^{miss}>70 GeV, CJV p_{T}^{j3}>30 GeV","PL");
  leg->AddEntry(hDphiJJRatioToCJV,"no E_{T}^{miss}, CJV p_{T}^{j3}>30 GeV","PL");
  leg->Draw();

  c2->SaveAs("cjv_eff_vs_dphi.gif");
  c2->SaveAs("cjv_eff_vs_dphi.pdf");

  /*
  setTDRStyle(0,0,0);
  TCanvas* c200 = new TCanvas("X","Y",1);
  TLegend *leg = new TLegend(0.45,0.75,0.65,0.90,NULL,"brNDC");
  hDphiJJRatioToCJVM24->GetXaxis()->SetTitle("#Delta#phi_{jj}, rad");
  hDphiJJRatioToCJVM24->GetYaxis()->SetTitle("veto efficiency");
  hDphiJJRatioToCJVM24->Divide(hDphiJJmJJ1200DetaJJ42jveto24,
			      hDphiJJmJJ1200DetaJJ42,1.,1.,"");

  hDphiJJRatioToCJVM24->SetMinimum(0.0);
  hDphiJJRatioToCJVM24->SetMaximum(0.6);
  hDphiJJRatioToCJVM24->SetMarkerStyle(20);
  hDphiJJRatioToCJVM24->SetTitleOffset(1.5, "Y");
  hDphiJJRatioToCJVM24->Draw("E1P");

  hDphiJJRatioToCJV24->Divide(hDphiJJmJJ1200DetaJJ42cjveto24,
			    hDphiJJmJJ1200DetaJJ42,1.,1.,"");
  hDphiJJRatioToCJV24->SetMarkerStyle(24);
  hDphiJJRatioToCJV24->Draw("sameE1P");

  leg->SetFillColor(10);
  leg->AddEntry(hDphiJJRatioToCJVM24,"data, CJVM","PL");
  leg->AddEntry(hDphiJJRatioToCJV24,"data, CJV","PL");
  leg->Draw();

  c200->SaveAs("cjvm_cjv_eff_vs_dphi.gif");
  */

  /*
  setTDRStyle(0,0,0);
  TCanvas* c1000 = new TCanvas("X","Y",1);
  c1000->Divide(1,2);

  c1000->cd(1);
  hDphiJ3JTmJJ1200DetaJJ42B->GetXaxis()->SetTitle("min. #Delta#phi^{j3,jtag} in QCD control region");
  hDphiJ3JTmJJ1200DetaJJ42B->GetYaxis()->SetTitle("Nev");
  hDphiJ3JTmJJ1200DetaJJ42B->SetLineStyle(1);
  hDphiJ3JTmJJ1200DetaJJ42B->SetLineWidth(3);
  hDphiJ3JTmJJ1200DetaJJ42B->SetTitleSize(0.055, "X");
  hDphiJ3JTmJJ1200DetaJJ42B->SetLabelSize(0.06, "X");
  hDphiJ3JTmJJ1200DetaJJ42B->Draw("hist");

  c1000->cd(2);
  hDphiJ3JTmJJ1200DetaJJ42S->GetXaxis()->SetTitle("min. #Delta#phi^{j3,jtag} in signal region");
  hDphiJ3JTmJJ1200DetaJJ42S->GetYaxis()->SetTitle("Nev");
  hDphiJ3JTmJJ1200DetaJJ42S->SetLineStyle(1);
  hDphiJ3JTmJJ1200DetaJJ42S->SetLineWidth(3);
  hDphiJ3JTmJJ1200DetaJJ42S->SetTitleSize(0.06, "X");
  hDphiJ3JTmJJ1200DetaJJ42S->SetLabelSize(0.06, "X");
  hDphiJ3JTmJJ1200DetaJJ42S->Draw("hist");

  c1000->SaveAs("dphi_j3jtag_min.gif");
  */

  /*
  setTDRStyle(0,1,0);
  TCanvas* c22 = new TCanvas("X","Y",1);
  TLegend *leg = new TLegend(0.20,0.80,0.70,0.90,NULL,"brNDC");
  hDphiJJmJJ1200DetaJJ42->GetXaxis()->SetTitle("E_{T}^{miss}, GeV");
  hDphiJJmJJ1200DetaJJ42->GetYaxis()->SetTitle("Nev");
  hDphiJJmJJ1200DetaJJ42->SetMinimum(100.);
  hDphiJJmJJ1200DetaJJ42->SetMaximum(200000.);
  hDphiJJmJJ1200DetaJJ42->SetMarkerStyle(20);
  hDphiJJmJJ1200DetaJJ42->Draw("E1P");

  leg->SetFillColor(10);
  leg->AddEntry(hDphiJJmJJ1200DetaJJ42,"data, no cut on E_{T}^{miss}","PL");
  leg->Draw();

  c22->SaveAs("dphi_example.gif");
  */


  setTDRStyle(0,1,0);
  TCanvas* c5 = new TCanvas("X","Y",1);
  c5->SetGrid();
  TLegend *leg = new TLegend(0.60,0.80,0.80,0.90,NULL,"brNDC");
  TH1F * hCJVS   = new TH1F( "hCJVS", "CJVS", 25, 0.0, 5.0);
  TH1F * hCJVB   = new TH1F( "hCJVB", "CJVB", 25, 0.0, 5.0);

  Double_t sum_s = 0;
  Double_t sum_b = 0;
  Double_t norms = hEtaJ1S->Integral();
  Double_t normb = hEtaJ1B->Integral();

  for (Int_t ieta = 1; ieta <= 25; ieta++) {
    Int_t ip = ieta+25;
    Int_t im = 26-ieta;
    Double_t s1 = hEtaJ3Scjv->GetBinContent(ip) + hEtaJ3Scjv->GetBinContent(im);
    Double_t b1 = hEtaJ3Bcjv->GetBinContent(ip) + hEtaJ3Bcjv->GetBinContent(im);
    sum_s += s1;
    sum_b += b1;
    Double_t sbin = (norms - sum_s)/norms; 
    Double_t err_sbin = sqrt(norms - sum_s)/norms; 
    Double_t bbin = (normb - sum_b)/normb;
    Double_t err_bbin = sqrt(normb - sum_b)/normb;

    hCJVS->SetBinContent(ieta,sbin);
    hCJVS->SetBinError(ieta,err_sbin);
    hCJVB->SetBinContent(ieta,bbin);
    hCJVB->SetBinError(ieta,err_bbin);
  }

  cout <<" norms = " << norms
       <<" sum_s = " << sum_s <<" eff cjv = " << (norms-sum_s)/norms
       <<" normb = " << normb
       <<" sum_b = " << sum_b <<" eff cjv = " << (normb-sum_b)/normb << endl; 

  hCJVB->GetXaxis()->SetTitle("|#eta^{j3}| coverage for CJV");
  hCJVB->GetYaxis()->SetTitle("efficiency of jet veto, p_{T}^{j3}>30 GeV");
  hCJVB->SetMinimum(0.05);
  hCJVB->SetMaximum(2.00);
  hCJVB->SetMarkerStyle(20);
  hCJVB->SetTitleOffset(1.0, "Y");
  hCJVB->SetTitleSize(0.05, "X");
  hCJVB->SetTitleSize(0.05, "Y");
  hCJVB->Draw("E1P");

  hCJVS->SetMarkerStyle(24);
  hCJVS->Draw("sameE1P");

  leg->SetFillColor(10);
  leg->AddEntry(hCJVB,"#Delta#phi_{jj}>2.6","PL");
  leg->AddEntry(hCJVS,"#Delta#phi_{jj}<1.0","PL");
  leg->Draw();

  c5->SaveAs("cjv_eff_vs_eta.gif");
  c5->SaveAs("cjv_eff_vs_eta.pdf");


  /*
  setTDRStyle(0,0,0);
  TCanvas* c6 = new TCanvas("X","Y",1);
  TLegend *leg = new TLegend(0.30,0.75,0.80,0.90,NULL,"brNDC");

  hPtJ1B->GetXaxis()->SetTitle("p_{T}^{j} in region #Delta#phi_{jj}>2.6, GeV");
  hPtJ1B->GetYaxis()->SetTitle("Nev");
  //  hPtJ1B->SetMinimum(10.);
  hPtJ1B->SetMaximum(30000.);
  hPtJ1B->SetMarkerStyle(20);
  hPtJ1B->SetTitleOffset(1.7, "Y");
  //  hPtJ1B->SetTitleSize(0.05, "X");
  //  hPtJ1B->SetTitleSize(0.05, "Y");
  hPtJ1B->SetLineStyle(1);
  hPtJ1B->SetLineWidth(3);
  hPtJ1B->Draw("hist");

  hPtJ2B->SetLineStyle(2);
  hPtJ2B->SetLineWidth(2);
  hPtJ2B->Draw("same");

  hPtJ3B->SetLineStyle(1);
  hPtJ3B->SetLineWidth(1);
  hPtJ3B->Draw("same");

  leg->SetFillColor(10);
  leg->AddEntry(hPtJ1B,"leading p_{T} tagging jet","L");
  leg->AddEntry(hPtJ2B,"sub-leading p_{T} tagging jet","L");
  leg->AddEntry(hPtJ3B,"leading p_{T} non tagging jet","L");
  leg->Draw();

  c6->SaveAs("ptjb.gif");
  c6->SaveAs("ptjb.pdf");

  setTDRStyle(0,0,0);
  TCanvas* c7 = new TCanvas("X","Y",1);
  TLegend *leg = new TLegend(0.30,0.75,0.80,0.90,NULL,"brNDC");

  hEtaJ1B->GetXaxis()->SetTitle("#eta^{j} in region #Delta#phi_{jj}>2.6");
  hEtaJ1B->GetYaxis()->SetTitle("Nev");
  //  hEtaJ1B->SetMinimum(10.);
  hEtaJ1B->SetMaximum(40000.);
  hEtaJ1B->SetMarkerStyle(20);
  hEtaJ1B->SetTitleOffset(1.7, "Y");
  //  hEtaJ1B->SetTitleSize(0.05, "X");
  //  hEtaJ1B->SetTitleSize(0.05, "Y");
  hEtaJ1B->SetLineStyle(1);
  hEtaJ1B->SetLineWidth(3);
  hEtaJ1B->Draw("hist");

  hEtaJ2B->SetLineStyle(2);
  hEtaJ2B->SetLineWidth(2);
  hEtaJ2B->Draw("same");

  hEtaJ3B->SetLineStyle(1);
  hEtaJ3B->SetLineWidth(1);
  hEtaJ3B->Draw("same");

  leg->SetFillColor(10);
  leg->AddEntry(hEtaJ1B,"leading p_{T} tagging jet","L");
  leg->AddEntry(hEtaJ2B,"sub-leading p_{T} tagging jet","L");
  leg->AddEntry(hEtaJ3B,"leading p_{T} non tagging jet","L");
  leg->Draw();

  c7->SaveAs("etajb.gif");
  c7->SaveAs("etajb.pdf");

  setTDRStyle(0,0,0);
  TCanvas* c8 = new TCanvas("X","Y",1);
  TLegend *leg = new TLegend(0.30,0.75,0.80,0.90,NULL,"brNDC");

  hPtJ1S->GetXaxis()->SetTitle("p_{T}^{j} in region #Delta#phi_{jj}<1.0, GeV");
  hPtJ1S->GetYaxis()->SetTitle("Nev");
  //  hPtJ1S->SetMinimum(10.);
  hPtJ1S->SetMaximum(1000.);
  hPtJ1S->SetMarkerStyle(20);
  hPtJ1S->SetTitleOffset(1.7, "Y");
  //  hPtJ1S->SetTitleSize(0.05, "X");
  //  hPtJ1S->SetTitleSize(0.05, "Y");
  hPtJ1S->SetLineStyle(1);
  hPtJ1S->SetLineWidth(3);
  hPtJ1S->Draw("hist");

  hPtJ2S->SetLineStyle(2);
  hPtJ2S->SetLineWidth(2);
  hPtJ2S->Draw("same");

  hPtJ3S->SetLineStyle(1);
  hPtJ3S->SetLineWidth(1);
  hPtJ3S->Draw("same");

  leg->SetFillColor(10);
  leg->AddEntry(hPtJ1S,"leading p_{T} tagging jet","L");
  leg->AddEntry(hPtJ2S,"sub-leading p_{T} tagging jet","L");
  leg->AddEntry(hPtJ3S,"leading p_{T} non tagging jet","L");
  leg->Draw();

  c8->SaveAs("ptjs.gif");
  c8->SaveAs("ptjs.pdf");

  setTDRStyle(0,0,0);
  TCanvas* c9 = new TCanvas("X","Y",1);
  TLegend *leg = new TLegend(0.30,0.75,0.80,0.90,NULL,"brNDC");

  hEtaJ1S->GetXaxis()->SetTitle("#eta^{j} in region #Delta#phi_{jj}<1.0");
  hEtaJ1S->GetYaxis()->SetTitle("Nev");
  //  hEtaJ1S->SetMinimum(10.);
  hEtaJ1S->SetMaximum(800.);
  hEtaJ1S->SetMarkerStyle(20);
  hEtaJ1S->SetTitleOffset(1.7, "Y");
  //  hEtaJ1S->SetTitleSize(0.05, "X");
  //  hEtaJ1S->SetTitleSize(0.05, "Y");
  hEtaJ1S->SetLineStyle(1);
  hEtaJ1S->SetLineWidth(3);
  hEtaJ1S->Draw("hist");

  hEtaJ2S->SetLineStyle(2);
  hEtaJ2S->SetLineWidth(2);
  hEtaJ2S->Draw("same");

  hEtaJ3S->SetLineStyle(1);
  hEtaJ3S->SetLineWidth(1);
  hEtaJ3S->Draw("same");

  leg->SetFillColor(10);
  leg->AddEntry(hEtaJ1S,"leading p_{T} tagging jet","L");
  leg->AddEntry(hEtaJ2S,"sub-leading p_{T} tagging jet","L");
  leg->AddEntry(hEtaJ3S,"leading p_{T} non tagging jet","L");
  leg->Draw();

  c9->SaveAs("etajs.gif");
  c9->SaveAs("etajs.pdf");
  */

  /*
  setTDRStyle(0,0,0);
  TCanvas* c100 = new TCanvas("X","Y",1);
  c100->Divide(1,2);

  TLegend *leg = new TLegend(0.50,0.75,0.95,0.95,NULL,"brNDC");

  c100->cd(1);
  hNAddJetsB->GetXaxis()->SetTitle("N not tag.jets with p_{T}>30 GeV, |#eta|<4.7 in QCD control region");
  hNAddJetsB->GetYaxis()->SetTitle("Nev");
  //  hNAddJetsB->SetMinimum(10.);
  //  hNAddJetsB->SetMaximum(500000.);
  hNAddJetsB->SetLineStyle(1);
  hNAddJetsB->SetLineWidth(3);
  hNAddJetsB->SetTitleSize(0.06, "X");
  hNAddJetsB->SetLabelSize(0.06, "X");
  hNAddJetsB->Draw("hist");

  c100->cd(2);
  hNAddJetsS->GetXaxis()->SetTitle("N not tag.jets with p_{T}>30 GeV, |#eta|<4.7 in signal region");
  hNAddJetsS->GetYaxis()->SetTitle("Nev");
  hNAddJetsS->SetLineStyle(1);
  hNAddJetsS->SetLineWidth(3);
  hNAddJetsS->SetTitleSize(0.06, "X");
  hNAddJetsS->SetLabelSize(0.06, "X");
  hNAddJetsS->Draw("hist");

  c100->SaveAs("n_add_jets.gif");
  c100->SaveAs("n_add_jets.pdf");
  */

  /*
  setTDRStyle(0,0,0);
  TCanvas* c10 = new TCanvas("X","Y",1);
  TLegend *leg = new TLegend(0.30,0.75,0.80,0.90,NULL,"brNDC");

  hEtaJ3S->Sumw2();
  hEtaJ3B->Sumw2();

  hEtaJ3RatioSovB->Divide(hEtaJ3S, hEtaJ3B, 1., 1.,"");
  hEtaJ3RatioSovB->GetXaxis()->SetTitle("#eta^{j3}");
  hEtaJ3RatioSovB->GetYaxis()->SetTitle("Nev(#Delta#phi_{jj}<1.0)/Nev(#Delta#phi_{jj}>2.6)");
  hEtaJ3RatioSovB->SetMinimum(0.00);
  hEtaJ3RatioSovB->SetMaximum(0.06);
  hEtaJ3RatioSovB->SetMarkerStyle(24);
  hEtaJ3RatioSovB->SetTitleOffset(1.5, "Y");
  //  hEtaJ3RatioSovB->SetTitleSize(0.05, "X");
  //  hEtaJ3RatioSovB->SetTitleSize(0.05, "Y");
  hEtaJ3RatioSovB->Draw("E1P");

  c10->SaveAs("etaj3s_ov_j3b.gif");
  */

  /*
  // all about QCD method 2
  setTDRStyle(0,1,0);
  TCanvas* c3 = new TCanvas("X","Y",1);
  TLegend *leg = new TLegend(0.50,0.70,0.80,0.90,NULL,"brNDC");

  hPFMET1mJJ1200DetaJJ42B->GetXaxis()->SetTitle("E_{T}^{miss}, GeV");
  hPFMET1mJJ1200DetaJJ42B->GetYaxis()->SetTitle("Nev");
  hPFMET1mJJ1200DetaJJ42B->SetMinimum(1.);
  hPFMET1mJJ1200DetaJJ42B->SetMaximum(100000.);
  hPFMET1mJJ1200DetaJJ42B->SetMarkerStyle(20);
  hPFMET1mJJ1200DetaJJ42B->Draw("E1P");

  hPFMET1mJJ1200DetaJJ42S->SetMarkerStyle(24);
  //  hPFMET1mJJ1200DetaJJ42S->SetAxisRange(0.,95.,"X");
  hPFMET1mJJ1200DetaJJ42S->SetAxisRange(0.,125.,"X");
  hPFMET1mJJ1200DetaJJ42S->Draw("sameE1P");
  // EW
  hEWS->SetLineStyle(2);
  hEWS->SetLineWidth(3);
  hEWS->Draw("samehist");

  hEWB->SetLineStyle(1);
  hEWB->SetLineWidth(3);
  hEWB->Draw("samehist");

  leg->SetFillColor(10);
  leg->AddEntry(hPFMET1mJJ1200DetaJJ42B,"data: #Delta#phi_{jj}>2.6","PL");
  leg->AddEntry(hPFMET1mJJ1200DetaJJ42S,"data: #Delta#phi_{jj}<1.0","PL");
  leg->AddEntry(hEWS,"EW bkg: #Delta#phi_{jj}<1.0","L");
  leg->AddEntry(hEWB,"EW bkg: #Delta#phi_{jj}>2.6","L");
  leg->Draw();

  cout <<" ==> S data = " << hPFMET1mJJ1200DetaJJ42S->Integral()
       <<" S EW = " << hEWS->Integral()
       <<" B data = " << hPFMET1mJJ1200DetaJJ42B->Integral()
       <<" B EW = " << hEWB->Integral() << endl;

  c3->SaveAs("met_in_s_and_b.gif");
  c3->SaveAs("met_in_s_and_b.pdf");


  setTDRStyle(0,1,0);
  TCanvas* c33 = new TCanvas("X","Y",1);
  TLegend *leg = new TLegend(0.50,0.80,0.80,0.90,NULL,"brNDC");

  hPFMET1mJJ1200DetaJJ42QCDB->GetXaxis()->SetTitle("E_{T}^{miss}, GeV");
  hPFMET1mJJ1200DetaJJ42QCDB->GetYaxis()->SetTitle("Nev");
  hPFMET1mJJ1200DetaJJ42QCDB->Add(hPFMET1mJJ1200DetaJJ42B, hEWB, 1.,-1.);
  hPFMET1mJJ1200DetaJJ42QCDB->SetMinimum(1.);
  hPFMET1mJJ1200DetaJJ42QCDB->SetMaximum(100000.);
  hPFMET1mJJ1200DetaJJ42QCDB->SetMarkerStyle(20);
  hPFMET1mJJ1200DetaJJ42QCDB->Draw("E1P");

  hPFMET1mJJ1200DetaJJ42QCDS->Add(hPFMET1mJJ1200DetaJJ42S, hEWS, 1.,-1.);
  hPFMET1mJJ1200DetaJJ42QCDS->SetMarkerStyle(24);
  //  hPFMET1mJJ1200DetaJJ42S->SetAxisRange(0.,95.,"X");
  hPFMET1mJJ1200DetaJJ42QCDS->SetAxisRange(0.,125.,"X");
  hPFMET1mJJ1200DetaJJ42QCDS->Draw("sameE1P");

  leg->SetFillColor(10);
  leg->AddEntry(hPFMET1mJJ1200DetaJJ42QCDB,"data-EW: #Delta#phi_{jj}>2.6","PL");
  leg->AddEntry(hPFMET1mJJ1200DetaJJ42QCDS,"data-EW: #Delta#phi_{jj}<1.0","PL");
  leg->Draw();

  c33->SaveAs("qcdmet_in_s_and_b.gif");
  c33->SaveAs("qcdmet_in_s_and_b.pdf");

  setTDRStyle(0,1,0);
  TCanvas* c4 = new TCanvas("X","Y",1);
  TLegend *leg = new TLegend(0.45,0.80,0.95,0.95,NULL,"brNDC");
  Float_t sums = 0;
  Float_t sumb = 0;
  for (Int_t im = 1; im <= 25; im++) {
    Float_t s = hPFMET1mJJ1200DetaJJ42QCDS->GetBinContent(im);
    Float_t b = hPFMET1mJJ1200DetaJJ42QCDB->GetBinContent(im);
    sums += s;
    if(im <= 23) {sumb += b;}
  }
  cout <<" s = " << sums <<" sumb = " << sumb 
       <<" total b = " << hPFMET1mJJ1200DetaJJ42QCDB->Integral() << endl;
  Double_t scale = sums/sumb;

  hPFMET1mJJ1200DetaJJ42QCDB->Scale(scale);

  hPFMET1mJJ1200DetaJJ42QCDBshifted->SetBinContent(1,0.5);
  hPFMET1mJJ1200DetaJJ42QCDBshifted->SetBinContent(2,0.5);
  for (Int_t im = 1; im <= 58; im++) {
    Float_t bc = hPFMET1mJJ1200DetaJJ42QCDB->GetBinContent(im);
    hPFMET1mJJ1200DetaJJ42QCDBshifted->SetBinContent(im+2,bc);
  }

  Float_t sumbshifted = 0;
  Float_t sumscheck = 0.;
  for(Int_t im = 1; im <= 25; im++) {
    Float_t bcheck = hPFMET1mJJ1200DetaJJ42QCDBshifted->GetBinContent(im);
    Float_t scheck = hPFMET1mJJ1200DetaJJ42QCDS->GetBinContent(im);
    sumbshifted += bcheck;
    sumscheck += scheck;
  }

  cout <<" ===> check of shifted histogram " << endl;
  cout <<" sumbshifted = " << sumbshifted <<" sumscheck = " << sumscheck << endl;

  hPFMET1mJJ1200DetaJJ42QCDB->GetXaxis()->SetTitle("E_{T}^{miss}, GeV");
  hPFMET1mJJ1200DetaJJ42QCDB->GetYaxis()->SetTitle("Nev");
  hPFMET1mJJ1200DetaJJ42QCDB->SetMinimum(1.);
  hPFMET1mJJ1200DetaJJ42QCDB->SetMaximum(1000.);
  hPFMET1mJJ1200DetaJJ42QCDB->SetMarkerStyle(20);
  hPFMET1mJJ1200DetaJJ42QCDB->Draw("E1P");

  hPFMET1mJJ1200DetaJJ42QCDS->SetMarkerStyle(24);
  //  hPFMET1mJJ1200DetaJJ42S->SetAxisRange(0.,95.,"X");
  hPFMET1mJJ1200DetaJJ42QCDS->SetAxisRange(0.,125.,"X");
  hPFMET1mJJ1200DetaJJ42QCDS->Draw("sameE1P");

  leg->SetFillColor(10);
  leg->AddEntry(hPFMET1mJJ1200DetaJJ42QCDB,"data-EW normalized: #Delta#phi_{jj}>2.6","PL");
  leg->AddEntry(hPFMET1mJJ1200DetaJJ42QCDS,"data-EW: #Delta#phi_{jj}<1.0","PL");
  leg->Draw();

  c4->SaveAs("qcdmet_in_s_and_b_norm.gif");
  c4->SaveAs("qcdmet_in_s_and_b_norm.pdf");

  setTDRStyle(0,1,0);
  TCanvas* c44 = new TCanvas("X","Y",1);
  TLegend *leg = new TLegend(0.20,0.85,0.90,0.95,NULL,"brNDC");

  hPFMET1mJJ1200DetaJJ42QCDBshifted->GetXaxis()->SetTitle("E_{T}^{miss}, GeV");
  hPFMET1mJJ1200DetaJJ42QCDBshifted->GetYaxis()->SetTitle("Nev");
  hPFMET1mJJ1200DetaJJ42QCDBshifted->SetMinimum(1.);
  hPFMET1mJJ1200DetaJJ42QCDBshifted->SetMaximum(5000.);
  hPFMET1mJJ1200DetaJJ42QCDBshifted->SetMarkerStyle(20);
  hPFMET1mJJ1200DetaJJ42QCDBshifted->Draw("hist");

  hPFMET1mJJ1200DetaJJ42QCDS->SetMarkerStyle(24);
  //  hPFMET1mJJ1200DetaJJ42S->SetAxisRange(0.,95.,"X");
  hPFMET1mJJ1200DetaJJ42QCDS->SetAxisRange(0.,125.,"X");
  hPFMET1mJJ1200DetaJJ42QCDS->Draw("sameE1P");

  leg->SetFillColor(10);
  leg->AddEntry(hPFMET1mJJ1200DetaJJ42QCDBshifted,"data-EW normalized and shifted: #Delta#phi_{jj}>2.6","L");
  leg->AddEntry(hPFMET1mJJ1200DetaJJ42QCDS,"data-EW: #Delta#phi_{jj}<1.0","PL");
  leg->Draw();

  c44->SaveAs("qcdmet_in_s_and_b_norm_shifted.gif");
  c44->SaveAs("qcdmet_in_s_and_b_norm_shifted.pdf");

  cout <<" =============> QCD calculations using MET shapes =========" << endl;

  Float_t sumb_gt120 = 0;
  Float_t sumb_le120 = 0;
  Float_t sums_le130 = 0;
  // MET < 130
  for (Int_t im = 1; im <= 25; im++) {
    Float_t s = hPFMET1mJJ1200DetaJJ42QCDS->GetBinContent(im);
    Float_t b = hPFMET1mJJ1200DetaJJ42QCDB->GetBinContent(im);
    sums_le130 += s;
    if(im <= 23) {sumb_le120 += b;}
  }

  for (Int_t im = 24; im <= 60; im++) {
    Float_t b = hPFMET1mJJ1200DetaJJ42QCDB->GetBinContent(im);
    sumb_gt120 += b;
  }

  Double_t qcd = (sumb_gt120/sumb_le120)*sums_le130;
  cout <<" sumb_le120 = " << sumb_le120
       <<" sumb_gt120 = " << sumb_gt120
       <<" sums_le130 = " << sums_le130 
       <<" ==> qcd = " << qcd << endl;

  setTDRStyle(0,0,0);
  TCanvas* c55 = new TCanvas("X","Y",1);
  hPFMET1mJJ1200DetaJJ42SovBshifted->GetXaxis()->SetTitle("E_{T}^{miss}, GeV");
  hPFMET1mJJ1200DetaJJ42SovBshifted->GetYaxis()->SetTitle("signal E_{T}^{miss} / control E_{T}^{miss} shifted");
  hPFMET1mJJ1200DetaJJ42SovBshifted->SetMarkerStyle(24);
  hPFMET1mJJ1200DetaJJ42SovBshifted->Sumw2();
  hPFMET1mJJ1200DetaJJ42SovBshifted->Divide(hPFMET1mJJ1200DetaJJ42QCDS,
					    hPFMET1mJJ1200DetaJJ42QCDBshifted, 1., 1., "");
  hPFMET1mJJ1200DetaJJ42SovBshifted->SetMinimum(0.0);
  hPFMET1mJJ1200DetaJJ42SovBshifted->SetMaximum(2.0);
  hPFMET1mJJ1200DetaJJ42SovBshifted->SetAxisRange(20.,125.,"X");
  hPFMET1mJJ1200DetaJJ42SovBshifted->Draw("E1P");
  ln = new TLine(20.,1.,130.,1.);
  ln->SetLineWidth(1);
  ln->Draw();
  c55->SaveAs("mets_ov_metb_shifted.gif");
  c55->SaveAs("mets_ov_metb_shifted.pdf");
  */
}
