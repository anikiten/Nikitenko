void setTDRStyle(Int_t xlog, Int_t ylog) {

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

void Draw()
{

  // Data
   setTDRStyle(0,0);
   TFile* file = new TFile("DataA+B_betaCJV_1stMay.root");
   TCanvas* c1 = new TCanvas("X","Y",1);
   
   TH1F *hcjveff = (TH1F*)hNvtxAcjv->Clone();
   hcjveff->GetYaxis()->SetTitle("CJV efficiency");
   hcjveff->GetXaxis()->SetTitle("Nvtx");
   hNvtxAcjv->Sumw2();
   Int_t nbins = hNvtxBcjv->GetNbinsX();
   for (Int_t ib = 1; ib <= nbins; ib++) {
     hNvtxBcjv->SetBinError(ib,0.1);
   }
   hcjveff->Divide(hNvtxAcjv,hNvtxBcjv,1.,1.,"");
   //   hcjveff->TGraphAsymmErrors::BayesDivide(hNvtxAcjv,hNvtxBcjv,1.,1.,"");
   hcjveff->SetMaximum(1.0);
   hcjveff->SetMinimum(0.);
   hcjveff->SetLineStyle(1);
   hcjveff->SetLineWidth(3);
   hcjveff->SetMarkerStyle(24);
   hcjveff->SetMarkerSize(1.2);
   hcjveff->Draw("PE");
   TLegend *leg = new TLegend(0.6,0.8,0.9,0.9,NULL,"brNDC");
   leg->SetFillColor(10);
   leg->AddEntry(hcjveff,"#beta > 0.2","P");

   TFile* file = new TFile("DataA+B_nobetaCJV_1stMay.root");
   TH1F *hcjveff1 = (TH1F*)hNvtxAcjv->Clone();
   hcjveff1->GetYaxis()->SetTitle("CJV efficiency");
   hcjveff1->GetXaxis()->SetTitle("Nvtx");
   hNvtxAcjv->Sumw2();
   Int_t nbins = hNvtxBcjv->GetNbinsX();
   for (Int_t ib = 1; ib <= nbins; ib++) {
     hNvtxBcjv->SetBinError(ib,0.1);
   }
   hcjveff1->Divide(hNvtxAcjv,hNvtxBcjv,1.,1.,"");
   hcjveff1->SetMarkerStyle(20);
   hcjveff1->SetMarkerSize(1.2);
   hcjveff1->SetLineStyle(2);
   hcjveff1->SetLineWidth(3);
   hcjveff1->Draw("samePE");

   leg->AddEntry(hcjveff1,"no beta cut","P");
   leg->Draw();

   TLatex *t = new TLatex();

   t->DrawLatex(1.0,0.85,"Z+jets, data 2011");

   t->SetTextSize(0.042);
   t->DrawLatex(0.5,0.30,"VBF selections:");
   t->DrawLatex(1.0,0.22,"p_{T}^{j1,j2} > 30 GeV, #Delta#eta_{j1,j2} > 3.5, M_{j1j2} > 700 GeV");
   t->DrawLatex(0.5,0.14,"Central jet veto:");
   t->DrawLatex(1.0,0.06,"no jets p_{T}^{j3} > 20 GeV, #eta_{min}<#eta_{j3}<#eta_{max}, |#eta_{j3}| < 2.0");

   c1->SaveAs("cjvData.png");

   //  Signal MC

   setTDRStyle(0,0);
   TFile* file = new TFile("Signal_betaCJV.root");
   TCanvas* c2 = new TCanvas("X","Y",1);
   
   TH1F *hcjveff = (TH1F*)hNvtxAcjv->Clone();
   hcjveff->GetYaxis()->SetTitle("CJV efficiency");
   hcjveff->GetXaxis()->SetTitle("Nvtx");
   hNvtxAcjv->Sumw2();
   Int_t nbins = hNvtxBcjv->GetNbinsX();
   for (Int_t ib = 1; ib <= nbins; ib++) {
     hNvtxBcjv->SetBinError(ib,0.1);
   }
   hcjveff->Divide(hNvtxAcjv,hNvtxBcjv,1.,1.,"");
   //   hcjveff->TGraphAsymmErrors::BayesDivide(hNvtxAcjv,hNvtxBcjv,1.,1.,"");
   hcjveff->SetMaximum(1.0);
   hcjveff->SetMinimum(0.);
   hcjveff->SetLineStyle(1);
   hcjveff->SetLineWidth(3);
   hcjveff->SetMarkerStyle(24);
   hcjveff->SetMarkerSize(1.2);
   hcjveff->Draw("PE");
   TLegend *leg = new TLegend(0.6,0.8,0.9,0.9,NULL,"brNDC");
   leg->SetFillColor(10);
   leg->AddEntry(hcjveff,"#beta > 0.2","P");

   TFile* file = new TFile("Signal_nobetaCJV.root");
   TH1F *hcjveff1 = (TH1F*)hNvtxAcjv->Clone();
   hcjveff1->GetYaxis()->SetTitle("CJV efficiency");
   hcjveff1->GetXaxis()->SetTitle("Nvtx");
   hNvtxAcjv->Sumw2();
   Int_t nbins = hNvtxBcjv->GetNbinsX();
   for (Int_t ib = 1; ib <= nbins; ib++) {
     hNvtxBcjv->SetBinError(ib,0.1);
   }
   hcjveff1->Divide(hNvtxAcjv,hNvtxBcjv,1.,1.,"");
   hcjveff1->SetMarkerStyle(20);
   hcjveff1->SetMarkerSize(1.2);
   hcjveff1->SetLineStyle(2);
   hcjveff1->SetLineWidth(3);
   hcjveff1->Draw("samePE");

   leg->AddEntry(hcjveff1,"no beta cut","P");
   leg->Draw();

   TLatex *t = new TLatex();

   t->DrawLatex(1.0,0.85,"EWK Z+jj");

   t->SetTextSize(0.042);
   t->DrawLatex(0.5,0.30,"VBF selections:");
   t->DrawLatex(1.0,0.22,"p_{T}^{j1,j2} > 30 GeV, #Delta#eta_{j1,j2} > 3.5, M_{j1j2} > 700 GeV");
   t->DrawLatex(0.5,0.14,"Central jet veto:");
   t->DrawLatex(1.0,0.06,"no jets p_{T}^{j3} > 20 GeV, #eta_{min}<#eta_{j3}<#eta_{max}, |#eta_{j3}| < 2.0");

   c2->SaveAs("cjvSignal.png");

  setTDRStyle(0,0);
  TFile* file = new TFile("DataB.root");
  TCanvas* c3 = new TCanvas("X","Y",1);
  Double_t scale = 1.0/hNTrk2GeV->Integral();
  cout <<" Integral data = " << hNTrk2GeV->Integral() << endl;
  for (Int_t im = 1; im <= 30; im++) {
    Double_t eff = hNTrk2GeV->GetBinContent(im);
    cout <<"   Nev in bin = " << im <<" " << eff << endl;
  }

  Double_t eff = 0.;
  Double_t bkgeff[30], sigeff[30];
  Double_t bkgeffCJV[1], sigeffCJV[1];
  bkgeffCJV[0] = 0.58;
  sigeffCJV[0] = 0.76;

  hNTrk2GeV->Scale(scale);
  for (Int_t im = 1; im <= 30; im++) {
    eff += hNTrk2GeV->GetBinContent(im);
    bkgeff[im-1] = eff;
    cout <<"   data eff in bin = " << im <<" " << eff << endl;
  }


  TFile* file = new TFile("SignalB.root");
  TCanvas* c3 = new TCanvas("X","Y",1);
  Double_t scale = 1.0/hNTrk2GeV->Integral();
  cout <<" Integral MC = " << hNTrk2GeV->Integral() << endl;
  for (Int_t im = 1; im <= 30; im++) {
    Double_t eff = hNTrk2GeV->GetBinContent(im);
    cout <<"   Nev in bin = " << im <<" " << eff << endl;
  }
  eff = 0.;
  hNTrk2GeV->Scale(scale);
  for (Int_t im = 1; im <= 30; im++) {
    eff += hNTrk2GeV->GetBinContent(im);
    sigeff[im-1] = eff;
    cout <<"   Signal eff in bin = " << im <<" " << eff << endl;
  }

  TGraph *grTrk2 = new TGraph(30,bkgeff,sigeff);
  TGraph *grCJV  = new TGraph(1,bkgeffCJV,sigeffCJV);

  grTrk2->SetMarkerStyle(20);
  grTrk2->SetMarkerSize(1.2);
  grTrk2->GetXaxis()->SetTitle("TCV eff. on DY 2011 B data");
  grTrk2->GetYaxis()->SetTitle("TCV eff. on EWK Z+2jets");
  grTrk2->Draw("AP");

  grCJV->SetMarkerStyle(28);
  grCJV->SetMarkerSize(2.0);
  grCJV->SetLineWidth(3);
  grCJV->Draw("sameP");
  TLegend *leg = new TLegend(0.4,0.20,0.9,0.35,NULL,"brNDC");
  leg->SetFillColor(10);
  leg->AddEntry(grTrk2,"TCV with tracks p_{T} > 2 GeV","P");
  leg->AddEntry(grCJV,"CJV","P");
  leg->Draw();

  c2->SaveAs("Trk2GeV.png");
}
