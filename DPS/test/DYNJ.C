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

   /*
   TLatex *t = new TLatex();
   t->SetTextSize(0.042);
   t->DrawLatex(1.5,0.80,"CMSSW_1_6_12, |#eta|< 1.3");
   t->DrawLatex(1.5,0.75,"no ZSP in HCAL");
   t->DrawLatex(1.5,0.70,"no SR in ECAL");
   */

  /*
   setTDRStyle(0,1);
   TCanvas* c0 = new TCanvas("X","Y",1);
   // data
   TFile* file = new TFile("DYDataA_29Feb.root");
   hnvtx0->GetXaxis()->SetTitle("N reco vertices");
   hnvtx0->GetYaxis()->SetTitle("");
   hnvtx0->SetLineStyle(1);
   hnvtx0->SetLineWidth(3);
   hnvtx0->SetMarkerStyle(24);
   hnvtx0->SetMarkerSize(1.0);
   hnvtx0->SetMaximum(200000.);
   hnvtx0->SetMinimum(0.5);
   hnvtx0->Draw("PE");
   TLegend *leg = new TLegend(0.35,0.75,0.9,0.85,NULL,"brNDC");
   leg->SetFillColor(10);
   leg->AddEntry(hnvtx0,"data: p_{T}^{#mu}> 20 GeV, |#eta|<2.4","P");
   // MC
   TFile* file = new TFile("DYMC18novPUW.root");
   hnvtx0->SetLineStyle(1);
   hnvtx0->SetLineWidth(3);
   hnvtx0->Draw("same");
   leg->AddEntry(hnvtx0,"MC, DY#rightarrowll","L");
   leg->Draw();
   c0->SaveAs("nvtx0.png");
  */

  // normalization
  //
  Double_t xsection=3048.;
  Double_t luminosity=5061;
  Double_t nmcevents=15000000.;
  Double_t datamcratio=2925.44;
  Double_t normalization=(xsection*luminosity)/(nmcevents*datamcratio);

  setTDRStyle(0,1);
  // data
  TFile* file = new TFile("DataAB.root");
  cout <<" ============= Data =============================" << endl;
  cout <<" ===> Zmumu = " << hZY->Integral() << endl;
  cout <<" ===> 2jets = " << hZY2J->Integral() << endl;
  cout <<" ===> y*    = " << hZY2JY->Integral() << endl;
  cout <<" ===> Mjj   = " << hZY2JYMjj->Integral() << endl;
  TCanvas* c1 = new TCanvas("X","Y",1);
  TH1F *hNjetsData = (TH1F*)hNjets->Clone();
  // MC events
  TFile* file = new TFile("DYMCAB.root");
  cout <<" ============= MC =============================" << endl;
  cout <<" ===> Zmumu = " << hZY->Integral()*normalization << endl;
  cout <<" ===> 2jets = " << hZY2J->Integral()*normalization << endl;
  cout <<" ===> y*    = " << hZY2JY->Integral()*normalization << endl;
  cout <<" ===> Mjj   = " << hZY2JYMjj->Integral()*normalization << endl;
  TH1F *hNjetsMC = (TH1F*)hNjets->Clone();
  TH1F *hNjetsRatio = (TH1F*)hNjets->Clone();
  TH1F *hNjetsRatio_JESUP = (TH1F*)hNjets->Clone();
  TH1F *hNjetsRatio_JESDN = (TH1F*)hNjets->Clone();
  //
  // MC events JESUP
  TFile* file = new TFile("DYMCAB_JESUP.root");
  TH1F *hNjetsMC_JESUP = (TH1F*)hNjets->Clone();
  // MC events JESDN
  TFile* file = new TFile("DYMCAB_JESDN.root");
  TH1F *hNjetsMC_JESDN = (TH1F*)hNjets->Clone();
  //
  hNjetsData->GetXaxis()->SetTitle("N jets");
  hNjetsData->GetYaxis()->SetTitle("N events");
  hNjetsData->SetMaximum(5000000.);
  hNjetsData->SetMinimum(100.);
  hNjetsData->SetLineStyle(1.);
  hNjetsData->SetLineWidth(2);
  hNjetsData->SetMarkerStyle(24);
  hNjetsData->SetMarkerSize(0.7);
  hNjetsData->Draw("PE");
  //  Double_t mcevents= hNjetsMC->Integral();
  //  Double_t dataevents=hNjetsData->Integral();
  //  Double_t expected=mcevents*normalization;
  hNjetsMC->Scale(normalization);
  hNjetsMC_JESUP->Scale(normalization);
  hNjetsMC_JESDN->Scale(normalization);
  hNjetsMC->SetLineStyle(1);
  hNjetsMC->SetLineWidth(2);
  hNjetsMC->Draw("same");

  TLegend *leg = new TLegend(0.5,0.8,0.9,0.9,NULL,"brNDC");
  leg->SetFillColor(10);
  leg->AddEntry(hNjetsData,"Data 2011, L=5.06 fb^{-1} ","P");
  leg->AddEntry(hNjetsMC,"Z+jets MC","L");
  leg->Draw();

  TLatex *t = new TLatex();
  t->SetTextSize(0.042);
  t->DrawLatex(3.0,200000,"Z#rightarrow#mu#mu + jets");
  t->DrawLatex(3.0,80000,"p_{T}^{j}>50 GeV, |#eta|<2.5");
  c1->SaveAs("dy_njets.png");

  setTDRStyle(0,0);
  TCanvas* c2 = new TCanvas("X","Y",1);
  hNjetsData->Sumw2();
  Int_t nbins = hNjetsMC->GetNbinsX();
  for (Int_t ib = 1; ib <= nbins; ib++) {
    hNjetsMC->SetBinError(ib,0.1);
    hNjetsMC->SetBinError(ib,0.1);
  }
  hNjetsRatio->Divide(hNjetsData,hNjetsMC,1.,1.,"");
  hNjetsRatio->GetXaxis()->SetTitle("N jets");
  hNjetsRatio->GetYaxis()->SetTitle("Data / MC");
  hNjetsRatio->SetMaximum(1.3);
  hNjetsRatio->SetMinimum(0.7);
  hNjetsRatio->SetLineStyle(1.);
  hNjetsRatio->SetLineWidth(2);
  hNjetsRatio->SetMarkerStyle(24);
  hNjetsRatio->SetMarkerSize(1.0);
  hNjetsRatio->SetAxisRange(0,3,"X");
  hNjetsRatio->Draw("PE");
  hNjetsRatio_JESUP->Divide(hNjetsMC_JESUP,hNjetsMC,1.,1.,"");
  hNjetsRatio_JESUP->SetLineStyle(2);
  hNjetsRatio_JESUP->SetLineWidth(2);
  hNjetsRatio_JESUP->Draw("histsame");
  hNjetsRatio_JESDN->Divide(hNjetsMC_JESDN,hNjetsMC,1.,1.,"");
  hNjetsRatio_JESDN->SetLineStyle(3);
  hNjetsRatio_JESDN->SetLineWidth(2);
  hNjetsRatio_JESDN->Draw("histsame");
  TLatex *t = new TLatex();
  t->SetTextSize(0.042);
  t->DrawLatex(1.0,1.20,"Z#rightarrow#mu#mu + jets");
  t->DrawLatex(1.0,1.14,"p_{T}^{j}>50 GeV, |#eta|<2.5");

  TLegend *leg = new TLegend(0.2,0.2,0.6,0.35,NULL,"brNDC");
  leg->SetFillColor(10);
  leg->AddEntry(hNjetsRatio,"Data 2011, L=5.06 fb^{-1} ","P");
  leg->AddEntry(hNjetsRatio_JESUP,"Z+jets MC, JES +1#sigma","L");
  leg->AddEntry(hNjetsRatio_JESDN,"Z+jets MC, JES -1#sigma","L");
  leg->Draw();

  c2->SaveAs("dy_ratio_njets_jes.png");
}
