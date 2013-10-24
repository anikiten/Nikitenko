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
  TFile* file = new TFile("nmssm_wh_4b_mh20_histos.root");
  TH1F *hptl_20     = (TH1F*)hptl->Clone();
  TH1F *hetal_20    = (TH1F*)hetal->Clone();
  TH1F *hptb_20     = (TH1F*)hptb->Clone();
  TH1F *hetab_20    = (TH1F*)hetab->Clone();
  TH1F *hdrlbmin_20 = (TH1F*)hdrlbmin->Clone();
  TH1F *hdrb1b2_20  = (TH1F*)hdrb1b2->Clone();
  TH1F *hdrb1b3_20  = (TH1F*)hdrb1b3->Clone();

  // mh = 40 GeV
  TFile* file = new TFile("nmssm_wh_4b_mh40_histos.root");
  TH1F *hptl_40     = (TH1F*)hptl->Clone();
  TH1F *hetal_40    = (TH1F*)hetal->Clone();
  TH1F *hptb_40     = (TH1F*)hptb->Clone();
  TH1F *hetab_40    = (TH1F*)hetab->Clone();
  TH1F *hdrlbmin_40 = (TH1F*)hdrlbmin->Clone();
  TH1F *hdrb1b2_40  = (TH1F*)hdrb1b2->Clone();
  TH1F *hdrb1b3_40  = (TH1F*)hdrb1b3->Clone();

  // mh = 60 GeV
  TFile* file = new TFile("nmssm_wh_4b_mh60_histos.root");
  TH1F *hptl_60     = (TH1F*)hptl->Clone();
  TH1F *hetal_60    = (TH1F*)hetal->Clone();
  TH1F *hptb_60     = (TH1F*)hptb->Clone();
  TH1F *hetab_60    = (TH1F*)hetab->Clone();
  TH1F *hdrlbmin_60 = (TH1F*)hdrlbmin->Clone();
  TH1F *hdrb1b2_60  = (TH1F*)hdrb1b2->Clone();
  TH1F *hdrb1b3_60  = (TH1F*)hdrb1b3->Clone();

  /*
  // pT lepton
  setTDRStyle(0,0,0);
  TCanvas* c1 = new TCanvas("X","Y",1);
  Double_t scale = 1./ hptl_20->Integral();
  hptl_20->Scale(scale);
  scale = 1./ hptl_40->Integral();
  hptl_40->Scale(scale);
  scale = 1./ hptl_60->Integral();
  hptl_60->Scale(scale);

  hptl_20->GetXaxis()->SetTitle("p_{T}^{lepton} from W decay, GeV");
  hptl_20->SetMaximum(0.2);
  hptl_20->SetLineStyle(1);
  hptl_20->SetLineWidth(2);
  hptl_20->Draw("hist");
  hptl_40->SetLineStyle(2);
  hptl_40->SetLineWidth(2);
  hptl_40->Draw("same");
  hptl_60->SetLineStyle(3);
  hptl_60->SetLineWidth(2);
  hptl_60->Draw("same");

  TLegend *leg = new TLegend(0.5,0.7,0.9,0.9,NULL,"brNDC");
  leg->SetFillColor(10);
  leg->AddEntry(hptl_20,"m_{H1}=20 GeV","L");
  leg->AddEntry(hptl_40,"m_{H1}=40 GeV","L");
  leg->AddEntry(hptl_60,"m_{H1}=60 GeV","L");
  leg->Draw();

  TLatex *t = new TLatex();
  t->SetTextSize(0.045);
  t->DrawLatex(30, 0.12,"WH2, H2#rightarrowH1H1#rightarrowbbbb");
  t->DrawLatex(50, 0.10,"m_{H2}=125 GeV");

  TLatex *tex = new TLatex(0.65,0.96,"CMS Simulation");
  tex->SetNDC();
  tex->SetTextFont(43);
  tex->SetTextSize(27);
  tex->SetLineWidth(2);
  tex->Draw();
  tex = new TLatex(0.2,0.96,"#sqrt{s} = 14 TeV");
  tex->SetNDC();
  tex->SetTextFont(43);
  tex->SetTextSize(27);
  tex->SetLineWidth(2);
  tex->Draw();
  c1->SaveAs("ptl_nmssm_wh_bbbb.pdf");


  // eta lepton
  setTDRStyle(0,0,0);
  TCanvas* c2 = new TCanvas("X","Y",1);
  Double_t scale = 1./ hetal_20->Integral();
  hetal_20->Scale(scale);
  scale = 1./ hetal_40->Integral();
  hetal_40->Scale(scale);
  scale = 1./ hetal_60->Integral();
  hetal_60->Scale(scale);

  hetal_20->GetXaxis()->SetTitle("|#eta|^{lepton} from W decay");
  hetal_20->SetMaximum(0.10);
  hetal_20->SetLineStyle(1);
  hetal_20->SetLineWidth(2);
  hetal_20->Draw("hist");
  hetal_40->SetLineStyle(2);
  hetal_40->SetLineWidth(2);
  hetal_40->Draw("same");
  hetal_60->SetLineStyle(3);
  hetal_60->SetLineWidth(2);
  hetal_60->Draw("same");

  TLegend *leg = new TLegend(0.5,0.7,0.9,0.9,NULL,"brNDC");
  leg->SetFillColor(10);
  leg->AddEntry(hetal_20,"m_{H1}=20 GeV","L");
  leg->AddEntry(hetal_40,"m_{H1}=40 GeV","L");
  leg->AddEntry(hetal_60,"m_{H1}=60 GeV","L");
  leg->Draw();

  TLatex *t = new TLatex();
  t->SetTextSize(0.045);
  t->DrawLatex(-1., 0.06,"WH2, H2#rightarrowH1H1#rightarrowbbbb");
  t->DrawLatex(2.0, 0.05,"m_{H2}=125 GeV");

  TLatex *tex = new TLatex(0.65,0.96,"CMS Simulation");
  tex->SetNDC();
  tex->SetTextFont(43);
  tex->SetTextSize(27);
  tex->SetLineWidth(2);
  tex->Draw();
  tex = new TLatex(0.2,0.96,"#sqrt{s} = 14 TeV");
  tex->SetNDC();
  tex->SetTextFont(43);
  tex->SetTextSize(27);
  tex->SetLineWidth(2);
  tex->Draw();
  c2->SaveAs("etal_nmssm_wh_bbbb.pdf");
*/

  // pT b
  setTDRStyle(0,0,0);
  TCanvas* c3 = new TCanvas("X","Y",1);
  Double_t scale = 1./ hptb_20->Integral();
  hptb_20->Scale(scale);
  scale = 1./ hptb_40->Integral();
  hptb_40->Scale(scale);
  scale = 1./ hptb_60->Integral();
  hptb_60->Scale(scale);
  hptb_20->SetTitleSize(0.05, "X");
  hptb_20->GetXaxis()->SetTitle("p_{T}^{b-quark}, GeV");
  hptb_20->SetMaximum(0.2);
  hptb_20->SetLineStyle(1);
  hptb_20->SetLineWidth(2);
  hptb_20->Draw("hist");
  hptb_40->SetLineStyle(2);
  hptb_40->SetLineWidth(2);
  hptb_40->Draw("same");
  hptb_60->SetLineStyle(3);
  hptb_60->SetLineWidth(2);
  hptb_60->Draw("same");

  TLegend *leg = new TLegend(0.5,0.7,0.9,0.9,NULL,"brNDC");
  leg->SetFillColor(10);
  leg->AddEntry(hptb_20,"m_{H1}=20 GeV","L");
  leg->AddEntry(hptb_40,"m_{H1}=40 GeV","L");
  leg->AddEntry(hptb_60,"m_{H1}=60 GeV","L");
  leg->Draw();

  TLatex *t = new TLatex();
  t->SetTextSize(0.045);
  t->DrawLatex(40, 0.12,"WH2, H2#rightarrowH1H1#rightarrowbbbb");
  t->DrawLatex(60, 0.10,"m_{H2}=125 GeV");

  TLatex *tex = new TLatex(0.65,0.96,"CMS Simulation");
  tex->SetNDC();
  tex->SetTextFont(43);
  tex->SetTextSize(27);
  tex->SetLineWidth(2);
  tex->Draw();
  tex = new TLatex(0.2,0.96,"#sqrt{s} = 14 TeV");
  tex->SetNDC();
  tex->SetTextFont(43);
  tex->SetTextSize(27);
  tex->SetLineWidth(2);
  tex->Draw();
  c3->SaveAs("ptb_nmssm_wh_bbbb.pdf");

  // eta b
  setTDRStyle(0,0,0);
  TCanvas* c4 = new TCanvas("X","Y",1);
  Double_t scale = 1./ hetab_20->Integral();
  hetab_20->Scale(scale);
  scale = 1./ hetab_40->Integral();
  hetab_40->Scale(scale);
  scale = 1./ hetab_60->Integral();
  hetab_60->Scale(scale);
  hetab_20->SetTitleSize(0.05, "X");
  hetab_20->GetXaxis()->SetTitle("|#eta|^{b-quark}");
  hetab_20->SetMaximum(0.10);
  hetab_20->SetLineStyle(1);
  hetab_20->SetLineWidth(2);
  hetab_20->Draw("hist");
  hetab_40->SetLineStyle(2);
  hetab_40->SetLineWidth(2);
  hetab_40->Draw("same");
  hetab_60->SetLineStyle(3);
  hetab_60->SetLineWidth(2);
  hetab_60->Draw("same");

  TLegend *leg = new TLegend(0.5,0.7,0.9,0.9,NULL,"brNDC");
  leg->SetFillColor(10);
  leg->AddEntry(hetab_20,"m_{H1}=20 GeV","L");
  leg->AddEntry(hetab_40,"m_{H1}=40 GeV","L");
  leg->AddEntry(hetab_60,"m_{H1}=60 GeV","L");
  leg->Draw();

  TLatex *t = new TLatex();
  t->SetTextSize(0.045);
  t->DrawLatex(-1., 0.06,"WH2, H2#rightarrowH1H1#rightarrowbbbb");
  t->DrawLatex(2.0, 0.05,"m_{H2}=125 GeV");

  TLatex *tex = new TLatex(0.65,0.96,"CMS Simulation");
  tex->SetNDC();
  tex->SetTextFont(43);
  tex->SetTextSize(27);
  tex->SetLineWidth(2);
  tex->Draw();
  tex = new TLatex(0.2,0.96,"#sqrt{s} = 14 TeV");
  tex->SetNDC();
  tex->SetTextFont(43);
  tex->SetTextSize(27);
  tex->SetLineWidth(2);
  tex->Draw();
  c4->SaveAs("etab_nmssm_wh_bbbb.pdf");

  /*
  // DR b1-b3
  setTDRStyle(0,0,0);
  TCanvas* c5 = new TCanvas("X","Y",1);
  Double_t scale = 1./ hdrb1b2_20->Integral();
  hdrb1b2_20->Scale(scale);
  scale = 1./ hdrb1b2_40->Integral();
  hdrb1b2_40->Scale(scale);
  scale = 1./ hdrb1b2_60->Integral();
  hdrb1b2_60->Scale(scale);

  hdrb1b2_20->GetXaxis()->SetTitle("#DeltaR^{b1-b2}");
  hdrb1b2_20->SetMaximum(0.30);
  hdrb1b2_20->SetLineStyle(1);
  hdrb1b2_20->SetLineWidth(2);
  hdrb1b2_20->Draw("hist");
  hdrb1b2_40->SetLineStyle(2);
  hdrb1b2_40->SetLineWidth(2);
  hdrb1b2_40->Draw("same");
  hdrb1b2_60->SetLineStyle(3);
  hdrb1b2_60->SetLineWidth(2);
  hdrb1b2_60->Draw("same");

  TLegend *leg = new TLegend(0.5,0.7,0.9,0.9,NULL,"brNDC");
  leg->SetFillColor(10);
  leg->AddEntry(hdrb1b2_20,"m_{H1}=20 GeV","L");
  leg->AddEntry(hdrb1b2_40,"m_{H1}=40 GeV","L");
  leg->AddEntry(hdrb1b2_60,"m_{H1}=60 GeV","L");
  leg->Draw();

  TLatex *t = new TLatex();
  t->SetTextSize(0.045);
  t->DrawLatex(2.0, 0.17,"WH2, H2#rightarrowH1H1#rightarrowbbbb");
  t->DrawLatex(2.5, 0.14,"m_{H2}=125 GeV");

  TLatex *tex = new TLatex(0.65,0.96,"CMS Simulation");
  tex->SetNDC();
  tex->SetTextFont(43);
  tex->SetTextSize(27);
  tex->SetLineWidth(2);
  tex->Draw();
  tex = new TLatex(0.2,0.96,"#sqrt{s} = 14 TeV");
  tex->SetNDC();
  tex->SetTextFont(43);
  tex->SetTextSize(27);
  tex->SetLineWidth(2);
  tex->Draw();
  c5->SaveAs("drb1b2_nmssm_wh_bbbb.pdf");

  // DR b1-b2
  setTDRStyle(0,0,0);
  TCanvas* c6 = new TCanvas("X","Y",1);
  Double_t scale = 1./ hdrb1b3_20->Integral();
  hdrb1b3_20->Scale(scale);
  scale = 1./ hdrb1b3_40->Integral();
  hdrb1b3_40->Scale(scale);
  scale = 1./ hdrb1b3_60->Integral();
  hdrb1b3_60->Scale(scale);

  hdrb1b3_20->GetXaxis()->SetTitle("#DeltaR^{b1-b3}");
  hdrb1b3_20->SetMaximum(0.20);
  hdrb1b3_20->SetLineStyle(1);
  hdrb1b3_20->SetLineWidth(2);
  hdrb1b3_20->Draw("hist");
  hdrb1b3_40->SetLineStyle(2);
  hdrb1b3_40->SetLineWidth(2);
  hdrb1b3_40->Draw("same");
  hdrb1b3_60->SetLineStyle(3);
  hdrb1b3_60->SetLineWidth(2);
  hdrb1b3_60->Draw("same");

  TLegend *leg = new TLegend(0.5,0.7,0.9,0.9,NULL,"brNDC");
  leg->SetFillColor(10);
  leg->AddEntry(hdrb1b3_20,"m_{H1}=20 GeV","L");
  leg->AddEntry(hdrb1b3_40,"m_{H1}=40 GeV","L");
  leg->AddEntry(hdrb1b3_60,"m_{H1}=60 GeV","L");
  leg->Draw();

  TLatex *t = new TLatex();
  t->SetTextSize(0.045);
  t->DrawLatex(2.0, 0.12,"WH2, H2#rightarrowH1H1#rightarrowbbbb");
  t->DrawLatex(2.5, 0.10,"m_{H2}=125 GeV");

  TLatex *tex = new TLatex(0.65,0.96,"CMS Simulation");
  tex->SetNDC();
  tex->SetTextFont(43);
  tex->SetTextSize(27);
  tex->SetLineWidth(2);
  tex->Draw();
  tex = new TLatex(0.2,0.96,"#sqrt{s} = 14 TeV");
  tex->SetNDC();
  tex->SetTextFont(43);
  tex->SetTextSize(27);
  tex->SetLineWidth(2);
  tex->Draw();
  c6->SaveAs("drb1b3_nmssm_wh_bbbb.pdf");

  // DR b1-b2
  setTDRStyle(0,0,0);
  TCanvas* c7 = new TCanvas("X","Y",1);
  Double_t scale = 1./ hdrlbmin_20->Integral();
  hdrlbmin_20->Scale(scale);
  scale = 1./ hdrlbmin_40->Integral();
  hdrlbmin_40->Scale(scale);
  scale = 1./ hdrlbmin_60->Integral();
  hdrlbmin_60->Scale(scale);

  hdrlbmin_20->GetXaxis()->SetTitle("#DeltaR_{l-b}^{min}");
  hdrlbmin_20->SetMaximum(0.20);
  hdrlbmin_20->SetLineStyle(1);
  hdrlbmin_20->SetLineWidth(2);
  hdrlbmin_20->Draw("hist");
  hdrlbmin_40->SetLineStyle(2);
  hdrlbmin_40->SetLineWidth(2);
  hdrlbmin_40->Draw("same");
  hdrlbmin_60->SetLineStyle(3);
  hdrlbmin_60->SetLineWidth(2);
  hdrlbmin_60->Draw("same");

  TLegend *leg = new TLegend(0.5,0.7,0.9,0.9,NULL,"brNDC");
  leg->SetFillColor(10);
  leg->AddEntry(hdrlbmin_20,"m_{H1}=20 GeV","L");
  leg->AddEntry(hdrlbmin_40,"m_{H1}=40 GeV","L");
  leg->AddEntry(hdrlbmin_60,"m_{H1}=60 GeV","L");
  leg->Draw();

  TLatex *t = new TLatex();
  t->SetTextSize(0.045);
  t->DrawLatex(2.0, 0.12,"WH2, H2#rightarrowH1H1#rightarrowbbbb");
  t->DrawLatex(2.5, 0.10,"m_{H2}=125 GeV");

  TLatex *tex = new TLatex(0.65,0.96,"CMS Simulation");
  tex->SetNDC();
  tex->SetTextFont(43);
  tex->SetTextSize(27);
  tex->SetLineWidth(2);
  tex->Draw();
  tex = new TLatex(0.2,0.96,"#sqrt{s} = 14 TeV");
  tex->SetNDC();
  tex->SetTextFont(43);
  tex->SetTextSize(27);
  tex->SetLineWidth(2);
  tex->Draw();
  c7->SaveAs("drlbmin_nmssm_wh_bbbb.pdf");
  */

  /*
  // eta mu
  setTDRStyle(0,0,0);
  TCanvas* c2 = new TCanvas("X","Y",1);
  scale = 1./ hEtaMu20->Integral();
  hEtaMu20->Scale(scale);
  scale = 1./ hEtaMu40->Integral();
  hEtaMu40->Scale(scale);
  scale = 1./ hEtaMu60->Integral();
  hEtaMu60->Scale(scale);

  hEtaMu20->GetXaxis()->SetTitle("#eta^{#mu}");
  hEtaMu20->SetMaximum(0.1);
  //  hEtaMu20->SetMinimum(0.001);
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
  tex = new TLatex(0.2,0.96,"#sqrt{s} = 14 TeV");
  tex->SetNDC();
  tex->SetTextFont(43);
  tex->SetTextSize(27);
  tex->SetLineWidth(2);
  tex->Draw();

  t->DrawLatex(-4.5, 0.06,"gg#rightarrowH1, H1#rightarrowH2H2#rightarrow#tau_{#mu}#tau_{h}bb, m_{H1}=125 GeV");

  c2->SaveAs("etamu_nmssm_2tau2b.pdf");

  // pT tau_h 
  setTDRStyle(0,1,0);
  TCanvas* c3 = new TCanvas("X","Y",1);
  scale = 1./ hPtTauH20->Integral();
  hPtTauH20->Scale(scale);
  scale = 1./ hPtTauH40->Integral();
  hPtTauH40->Scale(scale);
  scale = 1./ hPtTauH60->Integral();
  hPtTauH60->Scale(scale);

  hPtTauH20->GetXaxis()->SetTitle("p_{T}^{#tau_{h}}, GeV");
  hPtTauH20->SetMaximum(1.0);
  hPtTauH20->SetMinimum(0.001);
  hPtTauH20->SetLineStyle(1);
  hPtTauH20->SetLineWidth(2);
  hPtTauH20->Draw("hist");
  hPtTauH40->SetLineStyle(2);
  hPtTauH40->SetLineWidth(2);
  hPtTauH40->Draw("same");
  hPtTauH60->SetLineStyle(3);
  hPtTauH60->SetLineWidth(2);
  hPtTauH60->Draw("same");

  TLegend *leg = new TLegend(0.5,0.55,0.9,0.75,NULL,"brNDC");
  leg->SetFillColor(10);
  leg->AddEntry(hPtTauH20,"m_{H2}=20 GeV","L");
  leg->AddEntry(hPtTauH40,"m_{H2}=40 GeV","L");
  leg->AddEntry(hPtTauH60,"m_{H2}=60 GeV","L");
  leg->Draw();
  TLatex *tex = new TLatex(0.65,0.96,"CMS Simulation");
  tex->SetNDC();
  tex->SetTextFont(43);
  tex->SetTextSize(27);
  tex->SetLineWidth(2);
  tex->Draw();
  tex = new TLatex(0.2,0.96,"#sqrt{s} = 14 TeV");
  tex->SetNDC();
  tex->SetTextFont(43);
  tex->SetTextSize(27);
  tex->SetLineWidth(2);
  tex->Draw();

  t->DrawLatex(5.0, 0.5,"gg#rightarrowH1, H1#rightarrowH2H2#rightarrow#tau_{#mu}#tau_{h}bb, m_{H1}=125 GeV");

  c3->SaveAs("pttauh_nmssm_2tau2b.pdf");


  // eta tauh
  setTDRStyle(0,0,0);
  TCanvas* c4 = new TCanvas("X","Y",1);
  scale = 1./ hEtaTauH20->Integral();
  hEtaTauH20->Scale(scale);
  scale = 1./ hEtaTauH40->Integral();
  hEtaTauH40->Scale(scale);
  scale = 1./ hEtaTauH60->Integral();
  hEtaTauH60->Scale(scale);

  hEtaTauH20->GetXaxis()->SetTitle("#eta^{#tau_{h}}");
  hEtaTauH20->SetMaximum(0.1);
  //  hEtaTauH20->SetMinimum(0.001);
  hEtaTauH20->SetLineStyle(1);
  hEtaTauH20->SetLineWidth(2);
  hEtaTauH20->Draw("hist");
  hEtaTauH40->SetLineStyle(2);
  hEtaTauH40->SetLineWidth(2);
  hEtaTauH40->Draw("same");
  hEtaTauH60->SetLineStyle(3);
  hEtaTauH60->SetLineWidth(2);
  hEtaTauH60->Draw("same");

  TLegend *leg = new TLegend(0.5,0.7,0.9,0.9,NULL,"brNDC");
  leg->SetFillColor(10);
  leg->AddEntry(hEtaTauH20,"m_{H2}=20 GeV","L");
  leg->AddEntry(hEtaTauH40,"m_{H2}=40 GeV","L");
  leg->AddEntry(hEtaTauH60,"m_{H2}=60 GeV","L");
  leg->Draw();
  TLatex *tex = new TLatex(0.65,0.96,"CMS Simulation");
  tex->SetNDC();
  tex->SetTextFont(43);
  tex->SetTextSize(27);
  tex->SetLineWidth(2);
  tex->Draw();
  tex = new TLatex(0.2,0.96,"#sqrt{s} = 14 TeV");
  tex->SetNDC();
  tex->SetTextFont(43);
  tex->SetTextSize(27);
  tex->SetLineWidth(2);
  tex->Draw();

  t->DrawLatex(-4.5, 0.06,"gg#rightarrowH1, H1#rightarrowH2H2#rightarrow#tau_{#mu}#tau_{h}bb, m_{H1}=125 GeV");

  c4->SaveAs("etatauh_nmssm_2tau2b.pdf");


  // pT b
  setTDRStyle(0,0,0);
  TCanvas* c5 = new TCanvas("X","Y",1);
  scale = 1./ hPtB20->Integral();
  hPtB20->Scale(scale);
  scale = 1./ hPtB40->Integral();
  hPtB40->Scale(scale);
  scale = 1./ hPtB60->Integral();
  hPtB60->Scale(scale);

  hPtB20->GetXaxis()->SetTitle("p_{T}^{b quark}, GeV");
  hPtB20->SetMaximum(0.3);
  //  hPtB20->SetMinimum(0.001);
  hPtB20->SetLineStyle(1);
  hPtB20->SetLineWidth(2);
  hPtB20->Draw("hist");
  hPtB40->SetLineStyle(2);
  hPtB40->SetLineWidth(2);
  hPtB40->Draw("same");
  hPtB60->SetLineStyle(3);
  hPtB60->SetLineWidth(2);
  hPtB60->Draw("same");

  TLegend *leg = new TLegend(0.5,0.55,0.9,0.75,NULL,"brNDC");
  leg->SetFillColor(10);
  leg->AddEntry(hPtB20,"m_{H2}=20 GeV","L");
  leg->AddEntry(hPtB40,"m_{H2}=40 GeV","L");
  leg->AddEntry(hPtB60,"m_{H2}=60 GeV","L");
  leg->Draw();
  TLatex *tex = new TLatex(0.65,0.96,"CMS Simulation");
  tex->SetNDC();
  tex->SetTextFont(43);
  tex->SetTextSize(27);
  tex->SetLineWidth(2);
  tex->Draw();
  tex = new TLatex(0.2,0.96,"#sqrt{s} = 14 TeV");
  tex->SetNDC();
  tex->SetTextFont(43);
  tex->SetTextSize(27);
  tex->SetLineWidth(2);
  tex->Draw();

  t->DrawLatex(5.0, 0.25,"gg#rightarrowH1, H1#rightarrowH2H2#rightarrow#tau_{#mu}#tau_{h}bb, m_{H1}=125 GeV");

  c5->SaveAs("ptb_nmssm_2tau2b.pdf");


  // eta b
  setTDRStyle(0,0,0);
  TCanvas* c6 = new TCanvas("X","Y",1);
  scale = 1./ hEtaB20->Integral();
  hEtaB20->Scale(scale);
  scale = 1./ hEtaB40->Integral();
  hEtaB40->Scale(scale);
  scale = 1./ hEtaB60->Integral();
  hEtaB60->Scale(scale);

  hEtaB20->GetXaxis()->SetTitle("#eta^{b-quark}");
  hEtaB20->SetMaximum(0.1);
  //  hEtaB20->SetMinimum(0.001);
  hEtaB20->SetLineStyle(1);
  hEtaB20->SetLineWidth(2);
  hEtaB20->Draw("hist");
  hEtaB40->SetLineStyle(2);
  hEtaB40->SetLineWidth(2);
  hEtaB40->Draw("same");
  hEtaB60->SetLineStyle(3);
  hEtaB60->SetLineWidth(2);
  hEtaB60->Draw("same");

  TLegend *leg = new TLegend(0.5,0.7,0.9,0.9,NULL,"brNDC");
  leg->SetFillColor(10);
  leg->AddEntry(hEtaB20,"m_{H2}=20 GeV","L");
  leg->AddEntry(hEtaB40,"m_{H2}=40 GeV","L");
  leg->AddEntry(hEtaB60,"m_{H2}=60 GeV","L");
  leg->Draw();
  TLatex *tex = new TLatex(0.65,0.96,"CMS Simulation");
  tex->SetNDC();
  tex->SetTextFont(43);
  tex->SetTextSize(27);
  tex->SetLineWidth(2);
  tex->Draw();
  tex = new TLatex(0.2,0.96,"#sqrt{s} = 14 TeV");
  tex->SetNDC();
  tex->SetTextFont(43);
  tex->SetTextSize(27);
  tex->SetLineWidth(2);
  tex->Draw();

  t->DrawLatex(-4.5, 0.06,"gg#rightarrowH1, H1#rightarrowH2H2#rightarrow#tau_{#mu}#tau_{h}bb, m_{H1}=125 GeV");

  c6->SaveAs("etab_nmssm_2tau2b.pdf");

  // dr mu tauh
  setTDRStyle(0,0,0);
  TCanvas* c7 = new TCanvas("X","Y",1);
  scale = 1./ hDrMuTauH20->Integral();
  hDrMuTauH20->Scale(scale);
  scale = 1./ hDrMuTauH40->Integral();
  hDrMuTauH40->Scale(scale);
  scale = 1./ hDrMuTauH60->Integral();
  hDrMuTauH60->Scale(scale);

  hDrMuTauH20->GetXaxis()->SetTitle("#DeltaR(#mu-#tau_{h})");
  hDrMuTauH20->SetMaximum(0.4);
  //  hDrMuTauH20->SetMinimum(0.001);
  hDrMuTauH20->SetLineStyle(1);
  hDrMuTauH20->SetLineWidth(2);
  hDrMuTauH20->Draw("hist");
  hDrMuTauH40->SetLineStyle(2);
  hDrMuTauH40->SetLineWidth(2);
  hDrMuTauH40->Draw("same");
  hDrMuTauH60->SetLineStyle(3);
  hDrMuTauH60->SetLineWidth(2);
  hDrMuTauH60->Draw("same");

  TLegend *leg = new TLegend(0.5,0.75,0.9,0.9,NULL,"brNDC");
  leg->SetFillColor(10);
  leg->AddEntry(hDrMuTauH20,"m_{H2}=20 GeV","L");
  leg->AddEntry(hDrMuTauH40,"m_{H2}=40 GeV","L");
  leg->AddEntry(hDrMuTauH60,"m_{H2}=60 GeV","L");
  leg->Draw();
  TLatex *tex = new TLatex(0.65,0.96,"CMS Simulation");
  tex->SetNDC();
  tex->SetTextFont(43);
  tex->SetTextSize(27);
  tex->SetLineWidth(2);
  tex->Draw();
  tex = new TLatex(0.2,0.96,"#sqrt{s} = 14 TeV");
  tex->SetNDC();
  tex->SetTextFont(43);
  tex->SetTextSize(27);
  tex->SetLineWidth(2);
  tex->Draw();

  t->DrawLatex(0.2, 0.26,"gg#rightarrowH1, H1#rightarrowH2H2#rightarrow#tau_{#mu}#tau_{h}bb, m_{H1}=125 GeV");

  c7->SaveAs("drmutauh_nmssm_2tau2b.pdf");

  // dr b-b_bar
  setTDRStyle(0,0,0);
  TCanvas* c8 = new TCanvas("X","Y",1);
  scale = 1./ hDrBBbar20->Integral();
  hDrBBbar20->Scale(scale);
  scale = 1./ hDrBBbar40->Integral();
  hDrBBbar40->Scale(scale);
  scale = 1./ hDrBBbar60->Integral();
  hDrBBbar60->Scale(scale);

  hDrBBbar20->GetXaxis()->SetTitle("#DeltaR(b-b)");
  hDrBBbar20->SetMaximum(0.4);
  //  hDrBBbar20->SetMinimum(0.001);
  hDrBBbar20->SetLineStyle(1);
  hDrBBbar20->SetLineWidth(2);
  hDrBBbar20->Draw("hist");
  hDrBBbar40->SetLineStyle(2);
  hDrBBbar40->SetLineWidth(2);
  hDrBBbar40->Draw("same");
  hDrBBbar60->SetLineStyle(3);
  hDrBBbar60->SetLineWidth(2);
  hDrBBbar60->Draw("same");

  TLegend *leg = new TLegend(0.5,0.75,0.9,0.9,NULL,"brNDC");
  leg->SetFillColor(10);
  leg->AddEntry(hDrBBbar20,"m_{H2}=20 GeV","L");
  leg->AddEntry(hDrBBbar40,"m_{H2}=40 GeV","L");
  leg->AddEntry(hDrBBbar60,"m_{H2}=60 GeV","L");
  leg->Draw();
  TLatex *tex = new TLatex(0.65,0.96,"CMS Simulation");
  tex->SetNDC();
  tex->SetTextFont(43);
  tex->SetTextSize(27);
  tex->SetLineWidth(2);
  tex->Draw();
  tex = new TLatex(0.2,0.96,"#sqrt{s} = 14 TeV");
  tex->SetNDC();
  tex->SetTextFont(43);
  tex->SetTextSize(27);
  tex->SetLineWidth(2);
  tex->Draw();

  t->DrawLatex(1.0, 0.26,"gg#rightarrowH1, H1#rightarrowH2H2#rightarrow#tau_{#mu}#tau_{h}bb");
  t->DrawLatex(1.0, 0.22,"m_{H1}=125 GeV");

  c8->SaveAs("drbbbar_nmssm_2tau2b.pdf");

  // dr mu tauh
  setTDRStyle(0,0,0);
  TCanvas* c9 = new TCanvas("X","Y",1);
  scale = 1./ hDrMuTauH20S->Integral();
  hDrMuTauH20S->Scale(scale);
  scale = 1./ hDrMuTauH40S->Integral();
  hDrMuTauH40S->Scale(scale);
  scale = 1./ hDrMuTauH60S->Integral();
  hDrMuTauH60S->Scale(scale);

  hDrMuTauH20S->GetXaxis()->SetTitle("#DeltaR(#mu-#tau_{h})");
  hDrMuTauH20S->SetMaximum(0.6);
  hDrMuTauH20S->SetMinimum(0.0);
  hDrMuTauH20S->SetLineStyle(1);
  hDrMuTauH20S->SetLineWidth(2);
  hDrMuTauH20S->Draw("hist");
  hDrMuTauH40S->SetLineStyle(2);
  hDrMuTauH40S->SetLineWidth(2);
  hDrMuTauH40S->Draw("same");
  hDrMuTauH60S->SetLineStyle(3);
  hDrMuTauH60S->SetLineWidth(2);
  hDrMuTauH60S->Draw("same");

  TLegend *leg = new TLegend(0.5,0.75,0.9,0.9,NULL,"brNDC");
  leg->SetFillColor(10);
  leg->AddEntry(hDrMuTauH20S,"m_{H2}=20 GeV","L");
  leg->AddEntry(hDrMuTauH40S,"m_{H2}=40 GeV","L");
  leg->AddEntry(hDrMuTauH60S,"m_{H2}=60 GeV","L");
  leg->Draw();
  TLatex *tex = new TLatex(0.65,0.96,"CMS Simulation");
  tex->SetNDC();
  tex->SetTextFont(43);
  tex->SetTextSize(27);
  tex->SetLineWidth(2);
  tex->Draw();
  tex = new TLatex(0.2,0.96,"#sqrt{s} = 14 TeV");
  tex->SetNDC();
  tex->SetTextFont(43);
  tex->SetTextSize(27);
  tex->SetLineWidth(2);
  tex->Draw();

  t->DrawLatex(0.5,0.38,"gg#rightarrowH1, H1#rightarrowH2H2#rightarrow#tau_{#mu}#tau_{h}bb, m_{H1}=125 GeV");
  t->DrawLatex(3.5, 0.30,"p_{T}^{#mu}>20 GeV");
  t->DrawLatex(3.5, 0.25,"|#eta^{#mu}|<2.1");
  t->DrawLatex(3.5, 0.20,"p_{T}^{#tau_{h}}>20 GeV");
  t->DrawLatex(3.5, 0.15,"|#eta^{#tau_{h}}|<2.4");
  t->DrawLatex(3.5, 0.10,"p_{T}^{b}>25 GeV");
  t->DrawLatex(3.5, 0.05,"|#eta^{b}|<2.4");

  c9->SaveAs("drmutauhs_nmssm_2tau2b.pdf");

  // dr b-b_bar S
  setTDRStyle(0,0,0);
  TCanvas* c10 = new TCanvas("X","Y",1);
  scale = 1./ hDrBBbar20S->Integral();
  hDrBBbar20S->Scale(scale);
  scale = 1./ hDrBBbar40S->Integral();
  hDrBBbar40S->Scale(scale);
  scale = 1./ hDrBBbar60S->Integral();
  hDrBBbar60S->Scale(scale);

  hDrBBbar20S->GetXaxis()->SetTitle("#DeltaR(b-b)");
  hDrBBbar20S->SetMaximum(0.6);
  //  hDrBBbar20S->SetMinimum(0.001);
  hDrBBbar20S->SetLineStyle(1);
  hDrBBbar20S->SetLineWidth(2);
  hDrBBbar20S->Draw("hist");

  hDrBBbar40S->SetLineStyle(2);
  hDrBBbar40S->SetLineWidth(2);
  hDrBBbar40S->Draw("same");
  hDrBBbar60S->SetLineStyle(3);
  hDrBBbar60S->SetLineWidth(2);
  hDrBBbar60S->Draw("same");

  TLegend *leg = new TLegend(0.5,0.75,0.9,0.9,NULL,"brNDC");
  leg->SetFillColor(10);
  leg->AddEntry(hDrBBbar20S,"m_{H2}=20 GeV","L");
  leg->AddEntry(hDrBBbar40S,"m_{H2}=40 GeV","L");
  leg->AddEntry(hDrBBbar60S,"m_{H2}=60 GeV","L");
  leg->Draw();

  TLatex *tex = new TLatex(0.65,0.96,"CMS Simulation");
  tex->SetNDC();
  tex->SetTextFont(43);
  tex->SetTextSize(27);
  tex->SetLineWidth(2);
  tex->Draw();
  tex = new TLatex(0.2,0.96,"#sqrt{s} = 14 TeV");
  tex->SetNDC();
  tex->SetTextFont(43);
  tex->SetTextSize(27);
  tex->SetLineWidth(2);
  tex->Draw();

  t->DrawLatex(0.7,0.38,"gg#rightarrowH1, H1#rightarrowH2H2#rightarrow#tau_{#mu}#tau_{h}bb, m_{H1}=125 GeV");
  t->DrawLatex(3.5, 0.30,"p_{T}^{#mu}>20 GeV");
  t->DrawLatex(3.5, 0.25,"|#eta^{#mu}|<2.1");
  t->DrawLatex(3.5, 0.20,"p_{T}^{#tau_{h}}>20 GeV");
  t->DrawLatex(3.5, 0.15,"|#eta^{#tau_{h}}|<2.4");
  t->DrawLatex(3.5, 0.10,"p_{T}^{b}>25 GeV");
  t->DrawLatex(3.5, 0.05,"|#eta^{b}|<2.4");
  c10->SaveAs("drbbbars_nmssm_2tau2b.pdf");
  */
}
