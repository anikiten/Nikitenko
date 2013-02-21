void setTDRStyle(Int_t xlog, Int_t ylog, Int_t zlog) {

  TStyle *tdrStyle = new TStyle("tdrStyle","Style for P-TDR");

// For the canvas:
  tdrStyle->SetCanvasBorderMode(0);
  tdrStyle->SetCanvasColor(kWhite);
  tdrStyle->SetCanvasDefH(500); //Height of canvas
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
  TFile* file = new TFile("nmssm_4tau_mh8_histos.root");

  // pT mu
  setTDRStyle(0,1,0);
  TCanvas* c1 = new TCanvas("X","Y",1);
  Double_t scale = 1./ hPtMu1->Integral();
  hPtMu1->Scale(scale);
  hPtMu2->Scale(scale);
  hPtMu1->GetXaxis()->SetTitle("p_{T}^{#mu}, GeV");
  hPtMu1->SetMaximum(1.0);
  hPtMu1->SetMinimum(0.001);
  hPtMu1->SetLineStyle(1);
  hPtMu1->SetLineWidth(2);
  hPtMu1->Draw("hist");
  hPtMu2->SetLineStyle(2);
  hPtMu2->SetLineWidth(2);
  hPtMu2->Draw("same");

  TLegend *leg = new TLegend(0.5,0.75,0.9,0.9,NULL,"brNDC");
  leg->SetFillColor(10);
  leg->AddEntry(hPtMu1,"1st leading p_{T} muon","L");
  leg->AddEntry(hPtMu2,"2nd leading p_{T} muon","L");
  leg->Draw();

  TLatex *t = new TLatex();
  t->SetTextSize(0.045);
  t->DrawLatex(30, 0.06,"gg#rightarrowH1, H1#rightarrowH2H2#rightarrow#tau_{#mu}#tau_{h}#tau_{#mu}#tau_{h}");
  t->DrawLatex(40, 0.03,"m_{H1}=125 GeV, m_{H2}=8 GeV");

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
  c1->SaveAs("ptmu_nmssm_4tau.png");

  // eta mu
  setTDRStyle(0,0,0);
  TCanvas* c2 = new TCanvas("X","Y",1);
  Double_t scale = 1./ hEtaMu1->Integral();
  hEtaMu1->Scale(scale);
  hEtaMu2->Scale(scale);
  hEtaMu1->GetXaxis()->SetTitle("#eta^{#mu}");
  hEtaMu1->SetMaximum(0.10);
  hEtaMu1->SetMinimum(0.0);
  hEtaMu1->SetLineStyle(1);
  hEtaMu1->SetLineWidth(2);
  hEtaMu1->Draw("hist");
  hEtaMu2->SetLineStyle(2);
  hEtaMu2->SetLineWidth(2);
  hEtaMu2->Draw("same");

  TLegend *leg = new TLegend(0.5,0.75,0.9,0.9,NULL,"brNDC");
  leg->SetFillColor(10);
  leg->AddEntry(hEtaMu1,"1st leading p_{T} muon","L");
  leg->AddEntry(hEtaMu2,"2nd leading p_{T} muon","L");
  leg->Draw();

  TLatex *t = new TLatex();
  t->SetTextSize(0.045);
  t->DrawLatex(-4.5, 0.07,"gg#rightarrowH1, H1#rightarrowH2H2#rightarrow#tau_{#mu}#tau_{h}#tau_{#mu}#tau_{h}");
  t->DrawLatex(-4.5, 0.06,"m_{H1}=125 GeV, m_{H2}=8 GeV");

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
  c2->SaveAs("etamu_nmssm_4tau.png");

  // pT tau
  setTDRStyle(0,1,0);
  TCanvas* c3 = new TCanvas("X","Y",1);
  Double_t scale = 1./ hPtTauH->Integral();
  hPtTauH->Scale(scale);
  hPtTauH->GetXaxis()->SetTitle("p_{T}^{#tau_{h}}, GeV");
  hPtTauH->SetMaximum(0.20);
  hPtTauH->SetMinimum(0.001);
  hPtTauH->SetLineStyle(1);
  hPtTauH->SetLineWidth(2);
  hPtTauH->Draw("hist");

  TLatex *t = new TLatex();
  t->SetTextSize(0.045);
  t->DrawLatex(30, 0.10,"gg#rightarrowH1, H1#rightarrowH2H2#rightarrow#tau_{#mu}#tau_{h}#tau_{#mu}#tau_{h}");
  t->DrawLatex(30, 0.06,"m_{H1}=125 GeV, m_{H2}=8 GeV");

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
  c3->SaveAs("pttauh_nmssm_4tau.png");

  // eta tau
  setTDRStyle(0,0,0);
  TCanvas* c4 = new TCanvas("X","Y",1);
  Double_t scale = 1./ hEtaTauH->Integral();
  hEtaTauH->Scale(scale);
  hEtaTauH->GetXaxis()->SetTitle("#eta^{#tau_{h}}");
  hEtaTauH->SetMaximum(0.08);
  hEtaTauH->SetMinimum(0.0);
  hEtaTauH->SetLineStyle(1);
  hEtaTauH->SetLineWidth(2);
  hEtaTauH->Draw("hist");
  TLatex *t = new TLatex();
  t->SetTextSize(0.045);
  t->DrawLatex(-3.0, 0.07,"gg#rightarrowH1, H1#rightarrowH2H2#rightarrow#tau_{#mu}#tau_{h}#tau_{#mu}#tau_{h}");
  t->DrawLatex(-3.0, 0.06,"m_{H1}=125 GeV, m_{H2}=8 GeV");

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
  c4->SaveAs("etatauh_nmssm_4tau.png");


  // Dr mumu tautau
  setTDRStyle(0,0,0);
  TCanvas* c5 = new TCanvas("X","Y",1);
  hDrMuMuTauHTauH->GetXaxis()->SetTitle("#DeltaR(#mu-#mu)");
  hDrMuMuTauHTauH->GetYaxis()->SetTitle("#DeltaR(#tau_{h}-#tau_{h})");
  hDrMuMuTauHTauH->Draw("scat");
  TLatex *t = new TLatex();
  t->SetTextSize(0.045);
  t->DrawLatex(0.5, 4.5,"gg#rightarrowH1, H1#rightarrowH2H2#rightarrow#tau_{#mu}#tau_{h}#tau_{#mu}#tau_{h}");
  t->DrawLatex(0.5, 4.0,"m_{H1}=125 GeV, m_{H2}=8 GeV");

  t->DrawLatex(3.6, 2.8,"p_{T}^{#mu1}>17 GeV");
  t->DrawLatex(3.6, 2.4,"|#eta^{#mu1}|<2.1");
  t->DrawLatex(3.6, 2.0,"p_{T}^{#mu2}>10 GeV");
  t->DrawLatex(3.6, 1.6,"|#eta^{#mu1}|<2.4");
  t->DrawLatex(3.6, 1.2,"p_{T}^{#tau_{h}}>10 GeV");
  t->DrawLatex(3.6, 0.8,"|#eta^{#tau_{h}}|<2.4");

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
  c5->SaveAs("drmumutauhtauh_nmssm_4tau.png");

  // Dr mumu tautau
  setTDRStyle(0,0,0);
  TCanvas* c6 = new TCanvas("X","Y",1);
  hDrMuTauHMuTauH->GetXaxis()->SetTitle("#DeltaR(#mu_{1}-#tau_{h1,2}) min.");
  hDrMuTauHMuTauH->GetYaxis()->SetTitle("#DeltaR(#mu_{2}-#tau_{h2,1})");
  hDrMuTauHMuTauH->Draw("scat");
  TLatex *t = new TLatex();
  t->SetTextSize(0.045);
  t->DrawLatex(0.5, 4.5,"gg#rightarrowH1, H1#rightarrowH2H2#rightarrow#tau_{#mu}#tau_{h}#tau_{#mu}#tau_{h}");
  t->DrawLatex(0.5, 4.0,"m_{H1}=125 GeV, m_{H2}=8 GeV");

  t->DrawLatex(3.6, 2.8,"p_{T}^{#mu1}>17 GeV");
  t->DrawLatex(3.6, 2.4,"|#eta^{#mu1}|<2.1");
  t->DrawLatex(3.6, 2.0,"p_{T}^{#mu2}>10 GeV");
  t->DrawLatex(3.6, 1.6,"|#eta^{#mu1}|<2.4");
  t->DrawLatex(3.6, 1.2,"p_{T}^{#tau_{h}}>10 GeV");
  t->DrawLatex(3.6, 0.8,"|#eta^{#tau_{h}}|<2.4");

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
  c6->SaveAs("drmutauhmutauh_nmssm_4tau.png");

  // Dr mumu tautau
  setTDRStyle(0,0,0);
  TCanvas* c7 = new TCanvas("X","Y",1);
  Double_t scale = 1./ hDrMuTau1st->Integral();
  hDrMuTau1st->Scale(scale);
  hDrMuTau2nd->Scale(scale);
  hDrMuTau1st->GetXaxis()->SetTitle("#DeltaR(#mu_{1}-#tau_{h1,2}) min. and #DeltaR(#mu_{1}-#tau_{h2,1})");
  hDrMuTau1st->SetMaximum(0.6);
  hDrMuTau1st->SetMinimum(0.0);
  hDrMuTau1st->SetLineStyle(1);
  hDrMuTau1st->SetLineWidth(2);
  hDrMuTau1st->Draw("hist");
  hDrMuTau2nd->SetLineStyle(2);
  hDrMuTau2nd->SetLineWidth(2);
  hDrMuTau2nd->Draw("histsame");
  TLatex *t = new TLatex();
  t->SetTextSize(0.045);
  t->DrawLatex(1.0, 0.56,"gg#rightarrowH1, H1#rightarrowH2H2#rightarrow#tau_{#mu}#tau_{h}#tau_{#mu}#tau_{h}");
  t->DrawLatex(1.0, 0.52,"m_{H1}=125 GeV, m_{H2}=8 GeV");

  t->DrawLatex(2.0, 0.40,"p_{T}^{#mu1}>17 GeV");
  t->DrawLatex(2.0, 0.34,"|#eta^{#mu1}|<2.1");
  t->DrawLatex(2.0, 0.28,"p_{T}^{#mu2}>10 GeV");
  t->DrawLatex(2.0, 0.22,"|#eta^{#mu1}|<2.4");
  t->DrawLatex(2.0, 0.16,"p_{T}^{#tau_{h}}>10 GeV");
  t->DrawLatex(2.0, 0.10,"|#eta^{#tau_{h}}|<2.4");
  t->DrawLatex(1.0, 0.04,"and after #DeltaR(#mu-#mu) > 1.0 selection");

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
  c7->SaveAs("drmutauh_nmssm_4tau.png");

  /*
  t->DrawLatex(0.7,0.38,"gg#rightarrowH1, H1#rightarrowH2H2#rightarrow#tau_{#mu}#tau_{h}bb, m_{H1}=125 GeV");
  t->DrawLatex(3.5, 0.30,"p_{T}^{#mu}>20 GeV");
  t->DrawLatex(3.5, 0.25,"|#eta^{#mu}|<2.1");
  t->DrawLatex(3.5, 0.20,"p_{T}^{#tau_{h}}>20 GeV");
  t->DrawLatex(3.5, 0.15,"|#eta^{#tau_{h}}|<2.4");
  t->DrawLatex(3.5, 0.10,"p_{T}^{b}>25 GeV");
  t->DrawLatex(3.5, 0.05,"|#eta^{b}|<2.4");
  c10->SaveAs("drbbbars_nmssm_2tau2b.png");
  */
}
