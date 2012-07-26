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
  TFile* file = new TFile("QCDZ_histos.root");
  TH1F *hMjjQCDZ     = (TH1F*)hMjj->Clone();
  TH1F *hDetaJJQCDZ  = (TH1F*)hDetaJJ->Clone();
  TH1F *hEtaJminQCDZ = (TH1F*)hEtaJmin->Clone();
  TH1F *hEtaJmaxQCDZ = (TH1F*)hEtaJmax->Clone();
  TH1F *hPtTagJQCDZ  = (TH1F*)hPtTagJ->Clone();


  TFile* file = new TFile("EWKZ_histos.root");
  TH1F *hMjjEWKZ     = (TH1F*)hMjj->Clone();
  TH1F *hDetaJJEWKZ  = (TH1F*)hDetaJJ->Clone();
  TH1F *hEtaJminEWKZ = (TH1F*)hEtaJmin->Clone();
  TH1F *hEtaJmaxEWKZ = (TH1F*)hEtaJmax->Clone();
  TH1F *hPtTagJEWKZ  = (TH1F*)hPtTagJ->Clone();

  TFile* file = new TFile("VBFH_histos.root");
  TH1F *hMjjVBFH     = (TH1F*)hMjj->Clone();
  TH1F *hDetaJJVBFH  = (TH1F*)hDetaJJ->Clone();
  TH1F *hEtaJminVBFH = (TH1F*)hEtaJmin->Clone();
  TH1F *hEtaJmaxVBFH = (TH1F*)hEtaJmax->Clone();
  TH1F *hPtTagJVBFH  = (TH1F*)hPtTagJ->Clone();

  // Mjj
  setTDRStyle(0,1,0);
  TCanvas* c1 = new TCanvas("X","Y",1);
  Double_t scale = 1./ hMjjQCDZ->Integral();
  hMjjQCDZ->Scale(scale);
  scale = 1./ hMjjEWKZ->Integral();
  hMjjEWKZ->Scale(scale);
  scale = 1./ hMjjVBFH->Integral();
  hMjjVBFH->Scale(scale);
  //  hMjjQCDZ->GetYaxis()->SetTitle("dp/dM_{j1j2}");
  hMjjQCDZ->GetXaxis()->SetTitle("M_{j1j2}, GeV");
  hMjjQCDZ->SetMaximum(1.0);
  hMjjQCDZ->SetMinimum(0.0001);
  hMjjQCDZ->SetLineStyle(1);
  hMjjQCDZ->SetLineWidth(2);
  hMjjQCDZ->Draw("hist");
  hMjjEWKZ->SetLineStyle(2);
  hMjjEWKZ->SetLineWidth(2);
  hMjjEWKZ->Draw("same");
  hMjjVBFH->SetLineStyle(3);
  hMjjVBFH->SetLineWidth(2);
  hMjjVBFH->Draw("same");

  TLegend *leg = new TLegend(0.5,0.7,0.9,0.9,NULL,"brNDC");
  leg->SetFillColor(10);
  leg->AddEntry(hMjjQCDZ,"QCD Z+2jets","L");
  leg->AddEntry(hMjjEWKZ,"EWK Z+2jets","L");
  leg->AddEntry(hMjjVBFH,"VBF H, m_{H}=120 GeV","L");
  leg->Draw();
  TLatex *tex = new TLatex(0.65,0.96,"CMS Simulation");
  tex->SetNDC();
  tex->SetTextFont(43);
  tex->SetTextSize(27);
  tex->SetLineWidth(2);
  tex->Draw();
  tex = new TLatex(0.2,0.96,"#sqrt{s} = 7 TeV");
  tex->SetNDC();
  tex->SetTextFont(43);
  tex->SetTextSize(27);
  tex->SetLineWidth(2);
  tex->Draw();
  //  TLatex *t = new TLatex();
  //  t->SetTextSize(0.040);
  //  t->DrawLatex(600.0,3000.0,"Z+2jets, Z#rightarrow l^{+}l^{-} MadGraph");
  c1->SaveAs("mjj.eps");

  // DetaJJ
  setTDRStyle(0,0,0);
  TCanvas* c2 = new TCanvas("X","Y",1);
  scale = 1./ hDetaJJQCDZ->Integral();
  hDetaJJQCDZ->Scale(scale);
  scale = 1./ hDetaJJEWKZ->Integral();
  hDetaJJEWKZ->Scale(scale);
  scale = 1./ hDetaJJVBFH->Integral();
  hDetaJJVBFH->Scale(scale);
  //  hDetaJJQCDZ->GetYaxis()->SetTitle("dp/#Delta#eta_{j1j2}");
  hDetaJJQCDZ->GetXaxis()->SetTitle("#Delta#eta_{j1j2}");
  hDetaJJQCDZ->SetMaximum(0.2);
  hDetaJJQCDZ->SetLineStyle(1);
  hDetaJJQCDZ->SetLineWidth(2);
  hDetaJJQCDZ->Draw("hist");
  hDetaJJEWKZ->SetLineStyle(2);
  hDetaJJEWKZ->SetLineWidth(2);
  hDetaJJEWKZ->Draw("same");
  hDetaJJVBFH->SetLineStyle(3);
  hDetaJJVBFH->SetLineWidth(2);
  hDetaJJVBFH->Draw("same");

  TLegend *leg = new TLegend(0.5,0.7,0.9,0.9,NULL,"brNDC");
  leg->SetFillColor(10);
  leg->AddEntry(hDetaJJQCDZ,"QCD Z+2jets","L");
  leg->AddEntry(hDetaJJEWKZ,"EWK Z+2jets","L");
  leg->AddEntry(hDetaJJVBFH,"VBF H, m_{H}=120 GeV","L");
  leg->Draw();
  TLatex *tex = new TLatex(0.65,0.96,"CMS Simulation");
  tex->SetNDC();
  tex->SetTextFont(43);
  tex->SetTextSize(27);
  tex->SetLineWidth(2);
  tex->Draw();
  tex = new TLatex(0.2,0.96,"#sqrt{s} = 7 TeV");
  tex->SetNDC();
  tex->SetTextFont(43);
  tex->SetTextSize(27);
  tex->SetLineWidth(2);
  tex->Draw();
  c2->SaveAs("detajj.eps");

  // Eta J1, j2
  setTDRStyle(0,0,0);
  TCanvas* c3 = new TCanvas("X","Y",1);
  scale = 1./ hEtaJmaxQCDZ->Integral();
  hEtaJmaxQCDZ->Scale(scale);
  scale = 1./ hEtaJmaxEWKZ->Integral();
  hEtaJmaxEWKZ->Scale(scale);
  scale = 1./ hEtaJmaxVBFH->Integral();
  hEtaJmaxVBFH->Scale(scale);
  //  hEtaJmaxQCDZ->GetYaxis()->SetTitle("dp/#eta_{j} max");
  hEtaJmaxQCDZ->GetXaxis()->SetTitle("#eta_{j} max");
  hEtaJmaxQCDZ->SetMaximum(0.15);
  hEtaJmaxQCDZ->SetLineStyle(1);
  hEtaJmaxQCDZ->SetLineWidth(2);
  hEtaJmaxQCDZ->Draw("hist");
  hEtaJmaxEWKZ->SetLineStyle(2);
  hEtaJmaxEWKZ->SetLineWidth(2);
  hEtaJmaxEWKZ->Draw("same");
  hEtaJmaxVBFH->SetLineStyle(3);
  hEtaJmaxVBFH->SetLineWidth(2);
  hEtaJmaxVBFH->Draw("same");

  TLegend *leg = new TLegend(0.15,0.75,0.55,0.95,NULL,"brNDC");
  leg->SetFillColor(10);
  leg->AddEntry(hEtaJmaxQCDZ,"QCD Z+2jets","L");
  leg->AddEntry(hEtaJmaxEWKZ,"EWK Z+2jets","L");
  leg->AddEntry(hEtaJmaxVBFH,"VBF H, m_{H}=120 GeV","L");
  leg->Draw();
  TLatex *tex = new TLatex(0.65,0.96,"CMS Simulation");
  tex->SetNDC();
  tex->SetTextFont(43);
  tex->SetTextSize(27);
  tex->SetLineWidth(2);
  tex->Draw();
  tex = new TLatex(0.2,0.96,"#sqrt{s} = 7 TeV");
  tex->SetNDC();
  tex->SetTextFont(43);
  tex->SetTextSize(27);
  tex->SetLineWidth(2);
  tex->Draw();
  c3->SaveAs("etaj.eps");

  // pT jet
  setTDRStyle(0,0,0);
  TCanvas* c4 = new TCanvas("X","Y",1);
  scale = 1./ hPtTagJQCDZ->Integral();
  hPtTagJQCDZ->Scale(scale);
  scale = 1./ hPtTagJEWKZ->Integral();
  hPtTagJEWKZ->Scale(scale);
  scale = 1./ hPtTagJVBFH->Integral();
  hPtTagJVBFH->Scale(scale);
  //  hPtTagJQCDZ->GetYaxis()->SetTitle("dp/p_{T,j}");
  hPtTagJQCDZ->GetXaxis()->SetTitle("p_{T,j}, GeV");
  //  hPtTagJQCDZ->SetMaximum(0.15);
  hPtTagJQCDZ->SetLineStyle(1);
  hPtTagJQCDZ->SetLineWidth(2);
  hPtTagJQCDZ->Draw("hist");
  hPtTagJEWKZ->SetLineStyle(2);
  hPtTagJEWKZ->SetLineWidth(2);
  hPtTagJEWKZ->Draw("same");
  hPtTagJVBFH->SetLineStyle(3);
  hPtTagJVBFH->SetLineWidth(2);
  hPtTagJVBFH->Draw("same");

  TLegend *leg = new TLegend(0.5,0.7,0.9,0.9,NULL,"brNDC");
  leg->SetFillColor(10);
  leg->AddEntry(hPtTagJQCDZ,"QCD Z+2jets","L");
  leg->AddEntry(hPtTagJEWKZ,"EWK Z+2jets","L");
  leg->AddEntry(hPtTagJVBFH,"VBF H, m_{H}=120 GeV","L");
  leg->Draw();
  TLatex *tex = new TLatex(0.65,0.96,"CMS Simulation");
  tex->SetNDC();
  tex->SetTextFont(43);
  tex->SetTextSize(27);
  tex->SetLineWidth(2);
  tex->Draw();
  tex = new TLatex(0.2,0.96,"#sqrt{s} = 7 TeV");
  tex->SetNDC();
  tex->SetTextFont(43);
  tex->SetTextSize(27);
  tex->SetLineWidth(2);
  tex->Draw();
  c4->SaveAs("ptj.eps");
}

