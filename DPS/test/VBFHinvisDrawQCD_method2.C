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

  //  TFile* file = new TFile("EW_AM_withTrgWeights.root");
  //  TFile* file = new TFile("BkgForQCDEstimation_new_cjv.root");
  TFile* file = new TFile("BkgForQCDEstimation_method2.root");
  TH1F * hEWS = (TH1F*)metRangeTotal_DPhiSIGNAL_noCJV->Clone();
  TH1F * hEWB = (TH1F*)metRangeTotal_DPhiQCD_noCJV->Clone();

  TH1F * hEWSPhi = (TH1F*)metRangeTotal_DPhiSIGNAL_noCJV->Clone();
  TH1F * hEWBPhi = (TH1F*)metRangeTotal_DPhiQCD_noCJV->Clone();


  TFile* file = new TFile("VBFHinvisQCDAnalysisV10_Type01MET.root");
  TH1F * hDphiJJMET70RatioToCJV = (TH1F*)hDphiJJmJJ1200DetaJJ42MET70->Clone();
  TH1F * hDphiJJMET70RatioToCJV24 = (TH1F*)hDphiJJmJJ1200DetaJJ42MET70->Clone();
  TH1F * hDphiJJRatioToCJV = (TH1F*)hDphiJJmJJ1200DetaJJ42->Clone();
  TH1F * hDphiJJRatioToCJVM24 = (TH1F*)hDphiJJmJJ1200DetaJJ42->Clone();
  TH1F * hDphiJJRatioToCJV24 = (TH1F*)hDphiJJmJJ1200DetaJJ42->Clone();
  TH1F * hEtaJ3RatioSovB = (TH1F*)hEtaJ3S->Clone();

  TH1F * hPFMET1mJJ1200DetaJJ42QCDB = (TH1F*)hPFMET1mJJ1200DetaJJ42B->Clone(); 
  TH1F * hPFMET1mJJ1200DetaJJ42QCDBnorm = (TH1F*)hPFMET1mJJ1200DetaJJ42B->Clone(); 
  TH1F * hPFMET1mJJ1200DetaJJ42QCDBshifted = (TH1F*)hPFMET1mJJ1200DetaJJ42B->Clone(); 
  TH1F * hPFMET1mJJ1200DetaJJ42QCDS = (TH1F*)hPFMET1mJJ1200DetaJJ42S->Clone(); 
  TH1F * hPFMET1mJJ1200DetaJJ42QCDSnorm = (TH1F*)hPFMET1mJJ1200DetaJJ42S->Clone(); 
  TH1F * hPFMET1mJJ1200DetaJJ42SovBshifted = (TH1F*)hPFMET1mJJ1200DetaJJ42B->Clone(); 

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

  Double_t data_c_metle120 = 0.;
  Double_t ew_c_metle120 = 0.;
  Double_t qcd_c_metle120 = 0.;

  Double_t data_c_metge120 = 0.;
  Double_t ew_c_metge120 = 0.;
  Double_t qcd_c_metge120 = 0.;

  Double_t data_s_metle130 = 0.;
  Double_t ew_s_metle130 = 0.;
  Double_t qcd_s_metle130 = 0.;

  for (Int_t im = 1; im <= 60; im++) {

    if( im <= 22) {
      Float_t data_c_metle120_im = hPFMET1mJJ1200DetaJJ42B->GetBinContent(im);
      data_c_metle120 += data_c_metle120_im;
      Float_t ew_c_metle120_im = hEWB->GetBinContent(im);
      ew_c_metle120 += ew_c_metle120_im;
    }

    if( im > 22) {
      Float_t data_c_metge120_im = hPFMET1mJJ1200DetaJJ42B->GetBinContent(im);
      data_c_metge120 += data_c_metge120_im;
      Float_t ew_c_metge120_im = hEWB->GetBinContent(im);
      ew_c_metge120 += ew_c_metge120_im;
    }
    
    if( im <= 25) {
      Float_t data_s_metle130_im = hPFMET1mJJ1200DetaJJ42S->GetBinContent(im);
      data_s_metle130 += data_s_metle130_im;
      Float_t ew_s_metle130_im = hEWS->GetBinContent(im);
      ew_s_metle130 += ew_s_metle130_im;
    }
  }

  qcd_c_metle120 = data_c_metle120 - ew_c_metle120;
  qcd_c_metge120 = data_c_metge120 - ew_c_metge120;
  qcd_s_metle130 = data_s_metle130 - ew_s_metle130;

  cout <<"  =====>  Method 2 for QCD measurement ==== " << endl;
  cout <<"               Control region  MET < 120 GeV" << endl;
  cout <<"    data " << data_c_metle120 
       <<" ew = " << ew_c_metle120 
       <<" QCD = " << qcd_c_metle120 << endl;
  cout <<"               Control region  MET > 120 GeV" << endl;
  cout <<"    data " << data_c_metge120 
       <<" ew = " << ew_c_metge120 
       <<" QCD = " << qcd_c_metge120 << endl;
  cout <<"               Signal region  MET < 130 GeV" << endl;
  cout <<"    data " << data_s_metle130 
       <<" ew = " << ew_s_metle130 
       <<" QCD = " << qcd_s_metle130 << endl;
  cout <<"               Predicted QCD in signal region MET > 130 GeV " << endl;
  cout <<"                 " << qcd_s_metle130*(qcd_c_metge120/qcd_c_metle120) << endl;

  c33->SaveAs("qcdmet_in_s_and_b.gif");
  c33->SaveAs("qcdmet_in_s_and_b.pdf");

  setTDRStyle(0,1,0);
  TCanvas* c34 = new TCanvas("X","Y",1);
  hPFMET1mJJ1200DetaJJ42QCDB->GetXaxis()->SetTitle("E_{T}^{miss}, GeV");
  hPFMET1mJJ1200DetaJJ42QCDB->GetYaxis()->SetTitle("Nev");
  Double_t scale = 1./hPFMET1mJJ1200DetaJJ42QCDB->Integral();
  hPFMET1mJJ1200DetaJJ42QCDB->Scale(scale);
  hPFMET1mJJ1200DetaJJ42QCDB->SetMinimum(0.00001);
  hPFMET1mJJ1200DetaJJ42QCDB->SetMaximum(0.5);
  hPFMET1mJJ1200DetaJJ42QCDB->SetMarkerStyle(20);

  TF1 *f2 = new TF1("f2","[0]*0.5*(TMath::Erf([1]*(x-[2]))+1)*(1/([3]*[3]))*x*exp(-x*x/(2*[3]*[3]))",0.,150.);
  Double_t par[4];
  f2->SetParameter(0,100);
  f2->SetParameter(1,0.03);
  f2->SetParameter(2,80);
  f2->SetParameter(3,32);
  hPFMET1mJJ1200DetaJJ42QCDB->Draw("E1P");
  f2->SetLineWidth(2);
  f2->SetLineStyle(1);
  hPFMET1mJJ1200DetaJJ42QCDB->Fit("f2","R","same",30.,130.);
  f2->GetParameters(&par[0]);
  cout <<" ===========> Parameters from Control Region Fit <============"<< endl;
  cout <<" Parameters " << par[0] <<" "<< par[1] <<" "<< par[2] <<" " << par[3] << endl;

  TF1 *fsh = new TF1("f3","[0]*0.5*(TMath::Erf([1]*(x-[2]-13))+1)*(1/([3]*[3]))*(x-13)*exp(-(x-13)*(x-13)/(2*[3]*[3]))",30.,130.);

  fsh->SetParameter(0,par[0]);
  fsh->SetParameter(1,par[1]);
  fsh->SetParameter(2,par[2]);
  fsh->SetParameter(3,par[3]);
  fsh->Draw("same");

  hPFMET1mJJ1200DetaJJ42QCDS->Scale(1./qcd_s_metle130);
  hPFMET1mJJ1200DetaJJ42QCDS->SetMarkerStyle(24);
  hPFMET1mJJ1200DetaJJ42QCDS->SetAxisRange(0.,125.,"X");
  hPFMET1mJJ1200DetaJJ42QCDS->Draw("sameE1P");
  f2->SetLineStyle(1);
  //  hPFMET1mJJ1200DetaJJ42QCDS->Fit("f2","R","same",30.,130.);

  f2->GetParameters(&par[0]);

  cout <<" ===========> Parameters from Signal Region Fit <============"<< endl;
  cout <<" Parameters " << par[0] <<" "<< par[1] <<" "<< par[2] <<" " << par[3] << endl;

  c34->SaveAs("qcd_s_b_fitmet.pdf");

  /*
  setTDRStyle(0,0,0);
  TCanvas* c35 = new TCanvas("X","Y",1);
  TF1 *fb = new TF1("fb","0.5*(TMath::Erf(3.51863e-02*(x-5.93622e+01))+1)",0.,150.);
  fb->GetXaxis()->SetTitle("E_{T}^{miss}, GeV");
  fb->GetYaxis()->SetTitle("trigger efficiency");
  fb->SetMaximum(1.2);
  fb->Draw();

  TF1 *fs = new TF1("fs","0.5*(TMath::Erf(3.89045e-02*(x-7.36295e+01))+1)",0.,150.);
  fs->Draw("same");
  c35->SaveAs("trigger_turnon.pdf");
  */

  /*
  setTDRStyle(0,1,0);
  TCanvas* c36 = new TCanvas("X","Y",1);
  TF1 *fb = new TF1("fb","(1/(3.86005e+01*3.86005e+01))*x*exp(-x*x/(2*3.86005e+01*3.86005e+01))",0.,130.);

  fb->GetXaxis()->SetTitle("E_{T}^{miss}, GeV");
  fb->GetYaxis()->SetTitle("probability");
  fb->SetMinimum(0.0001);
  fb->SetMaximum(0.05);
  fb->Draw();

  TF1 *fs = new TF1("fs","(1/(4.06876e+01*4.06876e+01))*x*exp(-x*x/(2*4.06876e+01*4.06876e+01))",0.,130.);
  fs->Draw("same");
  c36->SaveAs("met_shape.pdf");
  */
}
