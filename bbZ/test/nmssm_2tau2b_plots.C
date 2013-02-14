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
  // mh = 20 GeV
  TFile* file = new TFile("nmssm_20_histos.root");
  TH1F *hPtMu20    = (TH1F*)hPtMu->Clone();
  TH1F *hEtaMu20   = (TH1F*)hEtaMu->Clone();
  TH1F *hPtB20     = (TH1F*)hPtB->Clone();
  TH1F *hEtaB20    = (TH1F*)hEtaB->Clone();
  TH1F *hPtTauH20  = (TH1F*)hPtTauH->Clone();
  TH1F *hEtaTauH20 = (TH1F*)hEtaTauH->Clone();

  // mh = 40 GeV
  TFile* file = new TFile("nmssm_40_histos.root");
  TH1F *hPtMu40    = (TH1F*)hPtMu->Clone();
  TH1F *hEtaMu40   = (TH1F*)hEtaMu->Clone();
  TH1F *hPtB40     = (TH1F*)hPtB->Clone();
  TH1F *hEtaB40    = (TH1F*)hEtaB->Clone();
  TH1F *hPtTauH40  = (TH1F*)hPtTauH->Clone();
  TH1F *hEtaTauH40 = (TH1F*)hEtaTauH->Clone();

  // mh = 60 GeV
  TFile* file = new TFile("nmssm_60_histos.root");
  TH1F *hPtMu60    = (TH1F*)hPtMu->Clone();
  TH1F *hEtaMu60   = (TH1F*)hEtaMu->Clone();
  TH1F *hPtB60     = (TH1F*)hPtB->Clone();
  TH1F *hEtaB60    = (TH1F*)hEtaB->Clone();
  TH1F *hPtTauH60  = (TH1F*)hPtTauH->Clone();
  TH1F *hEtaTauH60 = (TH1F*)hEtaTauH->Clone();

  // pT mu
  setTDRStyle(0,1,0);
  TCanvas* c1 = new TCanvas("X","Y",1);
  Double_t scale = 1./ hPtMu20->Integral();
  hPtMu20->Scale(scale);
  scale = 1./ hPtMu40->Integral();
  hPtMu40->Scale(scale);
  scale = 1./ hPtMu60->Integral();
  hPtMu60->Scale(scale);

  hPtMu20->GetXaxis()->SetTitle("p_{T}^{#mu}, GeV");
  hPtMu20->SetMaximum(1.0);
  hPtMu20->SetMinimum(0.001);
  hPtMu20->SetLineStyle(1);
  hPtMu20->SetLineWidth(2);
  hPtMu20->Draw("hist");
  hPtMu40->SetLineStyle(2);
  hPtMu40->SetLineWidth(2);
  hPtMu40->Draw("same");
  hPtMu60->SetLineStyle(3);
  hPtMu60->SetLineWidth(2);
  hPtMu60->Draw("same");

  TLegend *leg = new TLegend(0.5,0.7,0.9,0.9,NULL,"brNDC");
  leg->SetFillColor(10);
  leg->AddEntry(hPtMu20,"m_{H2}=20 GeV","L");
  leg->AddEntry(hPtMu40,"m_{H2}=40 GeV","L");
  leg->AddEntry(hPtMu60,"m_{H2}=60 GeV","L");
  leg->Draw();

  TLatex *t = new TLatex();
  t->SetTextSize(0.05);
  t->DrawLatex(30, 0.06,"gg#rightarrowH1, H1#rightarrowH2H2#rightarrow#tau_{#mu}#tau_{h}bb");
  t->DrawLatex(50, 0.03,"m_{H1}=125 GeV");

  TLatex *tex = new TLatex(0.65,0.96,"CMS Simulation");
  tex->SetNDC();
  tex->SetTextFont(43);
  tex->SetTextSize(27);
  tex->SetLineWidth(2);
  tex->Draw();
  tex = new TLatex(0.2,0.96,"#sqrt{s} = 8 TeV");
  tex->SetNDC();
  tex->SetTextFont(43);
  tex->SetTextSize(27);
  tex->SetLineWidth(2);
  tex->Draw();
  //  TLatex *t = new TLatex();
  //  t->SetTextSize(0.040);
  //  t->DrawLatex(600.0,3000.0,"Z+2jets, Z#rightarrow l^{+}l^{-} MadGraph");
  c1->SaveAs("ptmu_nmssm_2tau2b.png");

  /*
  // eta mu
  setTDRStyle(0,1,0);
  TCanvas* c2 = new TCanvas("X","Y",1);
  scale = 1./ hEtaMu20->Integral();
  hEtaMu20->Scale(scale);
  scale = 1./ hEtaMu40->Integral();
  hEtaMu40->Scale(scale);
  scale = 1./ hEtaMu60->Integral();
  hEtaMu60->Scale(scale);

  hEtaMu20->GetXaxis()->SetTitle("p_{T}^{#mu}, GeV");
  hEtaMu20->SetMaximum(1.0);
  hEtaMu20->SetMinimum(0.001);
  hEtaMu20->SetLineStyle(1);
  hEtaMu20->SetLineWidth(2);
  hEtaMu20->Draw("hist");
  hEtaMu40->SetLineStyle(2);
  hEtaMu40->SetLineWidth(2);
  hEtaMu40->Draw("same");
  hEtaMu60->SetLineStyle(3);
  hEtaMu60->SetLineWidth(2);
  hEtaMu60->Draw("same");

  TLegend *leg = new TLegend(0.5,0.7,0.9,0.9,NULL,"brNDC");
  leg->SetFillColor(10);
  leg->AddEntry(hEtaMu20,"m_{H2}=20 GeV","L");
  leg->AddEntry(hEtaMu40,"m_{H2}=40 GeV","L");
  leg->AddEntry(hEtaMu60,"m_{H2}=60 GeV","L");
  leg->Draw();
  TLatex *tex = new TLatex(0.65,0.96,"CMS Simulation");
  tex->SetNDC();
  tex->SetTextFont(43);
  tex->SetTextSize(27);
  tex->SetLineWidth(2);
  tex->Draw();
  tex = new TLatex(0.2,0.96,"#sqrt{s} = 8 TeV");
  //  tex = new TLatex(0.1,0.96,"H2->H1H2, m_{H1}=125 GeV");
  tex->SetNDC();
  tex->SetTextFont(43);
  tex->SetTextSize(27);
  tex->SetLineWidth(2);
  tex->Draw();
  //  TLatex *t = new TLatex();
  //  t->SetTextSize(0.040);
  //  t->DrawLatex(600.0,3000.0,"Z+2jets, Z#rightarrow l^{+}l^{-} MadGraph");
  c2->SaveAs("etamu_nmssm_2tau2b.png");
  */
}

