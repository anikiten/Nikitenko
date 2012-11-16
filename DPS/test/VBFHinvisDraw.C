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
  TFile* file = new TFile("VBFHinvisAnalysis.root");

  TCanvas* c1 = new TCanvas("X","Y",1);
  hDphiJJ->GetXaxis()->SetTitle("#Delta#phi_{jj}, rad");
  hDphiJJ->GetYaxis()->SetTitle("Nev");
  hDphiJJ->SetMaximum(500000.);
  hDphiJJ->SetMinimum(5.);
  hDphiJJ->SetLineStyle(1);
  hDphiJJ->SetLineWidth(2);
  hDphiJJ->Draw("hist");

  hDphiJJmJJ300->SetLineStyle(2);
  hDphiJJmJJ300->SetLineWidth(2);
  hDphiJJmJJ300->Draw("histsame");

  hDphiJJmJJ500->SetLineStyle(3);
  hDphiJJmJJ500->SetLineWidth(2);
  hDphiJJmJJ500->Draw("histsame");

  TLegend *leg = new TLegend(0.60,0.15,0.95,0.35,NULL,"brNDC");
  leg->SetFillColor(10);
  leg->AddEntry(hDphiJJ,"no selections","L");
  leg->AddEntry(hDphiJJmJJ300,"m_{jj} > 300 GeV","L");
  leg->AddEntry(hDphiJJmJJ500,"m_{jj} > 500 GeV","L");
  leg->Draw();
  
  TLatex *t = new TLatex();
  t->SetTextSize(0.040);
  t->DrawLatex(0.5, 200000.,"/MET/Run2012B-13Jul2012");
  t->DrawLatex(0.5, 100000.,"trigger: HLT_L1ETM40");
  t->DrawLatex(0.5, 50000.,"two leading p_{T} jets, p_{T}>50 GeV");
  t->DrawLatex(0.5, 25000.,"no PU jet removal yet");

  c1->SaveAs("dphi_jjmjj.gif");

  TCanvas* c2 = new TCanvas("X","Y",1);
  hDphiJJ->GetXaxis()->SetTitle("#Delta#phi_{jj}, rad");
  hDphiJJ->GetYaxis()->SetTitle("Nev");
  hDphiJJ->SetMaximum(500000.);
  hDphiJJ->SetMinimum(5.);
  hDphiJJ->SetLineStyle(1);
  hDphiJJ->SetLineWidth(2);
  hDphiJJ->Draw("hist");

  hDphiJJDetaJJ2->SetLineStyle(2);
  hDphiJJDetaJJ2->SetLineWidth(2);
  hDphiJJDetaJJ2->Draw("histsame");

  hDphiJJDetaJJ3->SetLineStyle(3);
  hDphiJJDetaJJ3->SetLineWidth(2);
  hDphiJJDetaJJ3->Draw("histsame");

  TLegend *leg = new TLegend(0.60,0.15,0.95,0.35,NULL,"brNDC");
  leg->SetFillColor(10);
  leg->AddEntry(hDphiJJ,"no selections","L");
  leg->AddEntry(hDphiJJDetaJJ2,"#Delta#eta_{jj} > 2.0","L");
  leg->AddEntry(hDphiJJDetaJJ3,"2#Delta#eta_{jj} > 3.0","L");
  leg->Draw();
  
  TLatex *t = new TLatex();
  t->SetTextSize(0.040);
  t->DrawLatex(0.5, 200000.,"/MET/Run2012B-13Jul2012");
  t->DrawLatex(0.5, 100000.,"trigger: HLT_L1ETM40");
  t->DrawLatex(0.5, 50000.,"two leading p_{T} jets, p_{T}>50 GeV");
  t->DrawLatex(0.5, 25000.,"no PU jet removal yet");

  c2->SaveAs("dphi_jjdetajj.gif");

  TCanvas* c3 = new TCanvas("X","Y",1);
  hDphiJJDetaJJ2->GetXaxis()->SetTitle("#Delta#phi_{jj}, rad");
  hDphiJJDetaJJ2->GetYaxis()->SetTitle("probability");
  Double_t scale = 1./ hDphiJJDetaJJ2->Integral();
  hDphiJJDetaJJ2->Scale(scale);
  hDphiJJDetaJJ2->SetMaximum(0.5);
  hDphiJJDetaJJ2->SetMinimum(0.0005);
  hDphiJJDetaJJ2->SetLineStyle(2);
  hDphiJJDetaJJ2->SetLineWidth(2);
  hDphiJJDetaJJ2->Draw("hist");

  Double_t scale = 1./ hDphiJJDetaJJ3->Integral();
  hDphiJJDetaJJ3->Scale(scale);
  hDphiJJDetaJJ3->SetLineStyle(3);
  hDphiJJDetaJJ3->SetLineWidth(2);
  hDphiJJDetaJJ3->Draw("samehist");

  TLegend *leg = new TLegend(0.50,0.15,0.85,0.25,NULL,"brNDC");
  leg->SetFillColor(10);
  leg->AddEntry(hDphiJJDetaJJ2,"#Delta#eta_{jj} > 2.0","L");
  leg->AddEntry(hDphiJJDetaJJ3,"#Delta#eta_{jj} > 3.0","L");
  leg->Draw();
  
  TLatex *t = new TLatex();
  t->SetTextSize(0.040);
  t->DrawLatex(0.2, 0.200,"/MET/Run2012B-13Jul2012");
  t->DrawLatex(0.2, 0.100,"trigger: HLT_L1ETM40");
  t->DrawLatex(0.2, 0.050,"two leading p_{T} jets, p_{T}>50 GeV");
  t->DrawLatex(0.2, 0.025,"no PU jet removal yet");

  c3->SaveAs("dphi_jjdetajj_prob.gif");

  TCanvas* c4 = new TCanvas("X","Y",1);
  hDphiJJmJJ300->GetXaxis()->SetTitle("#Delta#phi_{jj}, rad");
  hDphiJJmJJ300->GetYaxis()->SetTitle("probability");
  Double_t scale = 1./ hDphiJJmJJ300->Integral();
  hDphiJJmJJ300->Scale(scale);
  hDphiJJmJJ300->SetMaximum(0.5);
  hDphiJJmJJ300->SetMinimum(0.0001);
  hDphiJJmJJ300->SetLineStyle(2);
  hDphiJJmJJ300->SetLineWidth(2);
  hDphiJJmJJ300->Draw("hist");

  Double_t scale = 1./ hDphiJJmJJ500->Integral();
  hDphiJJmJJ500->Scale(scale);
  hDphiJJmJJ500->SetLineStyle(3);
  hDphiJJmJJ500->SetLineWidth(2);
  hDphiJJmJJ500->Draw("samehist");

  TLegend *leg = new TLegend(0.50,0.15,0.85,0.25,NULL,"brNDC");
  leg->SetFillColor(10);
  leg->AddEntry(hDphiJJmJJ300,"m_{jj} > 300 GeV","L");
  leg->AddEntry(hDphiJJmJJ500,"m_{jj} > 500 GeV","L");
  leg->Draw();
  
  TLatex *t = new TLatex();
  t->SetTextSize(0.040);
  t->DrawLatex(0.2, 0.200,"/MET/Run2012B-13Jul2012");
  t->DrawLatex(0.2, 0.100,"trigger: HLT_L1ETM40");
  t->DrawLatex(0.2, 0.050,"two leading p_{T} jets, p_{T}>50 GeV");
  t->DrawLatex(0.2, 0.025,"no PU jet removal yet");

  c4->SaveAs("dphi_jjmjj_prob.gif");
}

