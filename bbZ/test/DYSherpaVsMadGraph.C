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

   setTDRStyle(0,1);

   TCanvas* c1 = new TCanvas("X","Y",1);

   TFile* file = new TFile("DYmadgraph_histos.root");

   hpTZ->GetXaxis()->SetTitle("p_{T}^{Z}, GeV");
   hpTZ->GetYaxis()->SetTitle("");
   hpTZ->SetMaximum(10000000.);
   hpTZ->SetMinimum(10.);
   hpTZ->SetLineStyle(1);
   hpTZ->SetLineWidth(2);
   Double_t nm = hpTZ->Integral();
   hpTZ->Draw("hist");

   hpTZ2J->SetLineStyle(1);
   hpTZ2J->SetLineWidth(3);
   Double_t nm2J = hpTZ2J->Integral();
   hpTZ2J->Draw("same");


   hpTZ2JDeta->SetLineStyle(1);
   hpTZ2JDeta->SetLineWidth(4);
   Double_t nm2JDeta = hpTZ2JDeta->Integral();
   hpTZ2JDeta->Draw("same");

   TLegend *leg = new TLegend(0.3,0.75,0.95,0.95,NULL,"brNDC");
   leg->SetFillColor(10);
   leg->AddEntry(hpTZ,"MadGraph, Z inclusive","L");
   leg->AddEntry(hpTZ2J,"Z+#geq2jet","L");
   leg->AddEntry(hpTZ2JDeta,"Z+#geq2jet, #Delta#eta_{J1J2}>3.5","L");

   TFile* file = new TFile("DYsherpa_histos.root");

   Double_t scale = nm/hpTZ->Integral();
   hpTZ->Scale(scale);
   hpTZ->SetLineStyle(2);
   hpTZ->SetLineWidth(2);
   hpTZ->Draw("same");

   scale = nm2J/hpTZ2J->Integral();
   hpTZ2J->Scale(scale);
   hpTZ2J->SetLineStyle(2);
   hpTZ2J->SetLineWidth(3);
   hpTZ2J->Draw("same");

   scale = nm2JDeta/hpTZ2JDeta->Integral();
   hpTZ2JDeta->Scale(scale);
   hpTZ2JDeta->SetLineStyle(2);
   hpTZ2JDeta->SetLineWidth(4);
   hpTZ2JDeta->Draw("same");

   leg->AddEntry(hpTZ,"Sherpa","L");
   //   leg->AddEntry(hpTZ2J,"Sherpa Z+#geq2jet","L");
   //   leg->AddEntry(hpTZ2JDeta,"Sherpa Z+#geq2jet, #Delta#eta_{J1J2}>3.5","L");
   leg->Draw();

   TLatex *t = new TLatex();
   t->SetTextSize(0.04);
   t->DrawLatex(50,100000,"85<m_{ll}<97 GeV, p_{T}^{l}>20 GeV, #eta_{l}<2.4");
   t->DrawLatex(70,40000,"p_{T}^{jet}>25 GeV, #eta_{jet}<4.7");

   c1->SaveAs("pTZ.png");


   setTDRStyle(0,1);

   TCanvas* c2 = new TCanvas("X","Y",1);

   TFile* file = new TFile("DYmadgraph_histos.root");

   hyZ2J->GetXaxis()->SetTitle("Z rapidity");
   hyZ2J->GetYaxis()->SetTitle("");
   hyZ2J->SetLineStyle(1);
   hyZ2J->SetLineWidth(2);
   hyZ2J->SetMaximum(1000000.);
   hyZ2J->SetMinimum(10.);
   Double_t nm2J = hyZ2J->Integral();
   hyZ2J->Draw("hist");


   hyZ2JDeta->SetLineStyle(1);
   hyZ2JDeta->SetLineWidth(4);
   Double_t nm2JDeta = hyZ2JDeta->Integral();
   hyZ2JDeta->Draw("same");

   TLegend *leg = new TLegend(0.3,0.8,0.9,0.95,NULL,"brNDC");
   leg->SetFillColor(10);
   //   leg->AddEntry(hyZ,"MadGraph Z inclusive","L");
   leg->AddEntry(hyZ2J,"MadGraph Z+#geq2jet","L");
   leg->AddEntry(hyZ2JDeta,"Z+#geq2jet, #Delta#eta_{J1J2}>3.5","L");

   TFile* file = new TFile("DYsherpa_histos.root");

   scale = nm2J/hyZ2J->Integral();
   hyZ2J->Scale(scale);
   hyZ2J->SetLineStyle(2);
   hyZ2J->SetLineWidth(2);
   hyZ2J->Draw("same");

   scale = nm2JDeta/hyZ2JDeta->Integral();
   hyZ2JDeta->Scale(scale);
   hyZ2JDeta->SetLineStyle(2);
   hyZ2JDeta->SetLineWidth(4);
   hyZ2JDeta->Draw("same");

   //   leg->AddEntry(hyZ,"Sherpa Z inclusive","L");
   leg->AddEntry(hyZ2J,"Sherpa","L");
   //   leg->AddEntry(hyZ2JDeta,"Sherpa Z+#geq2jet, #Delta#eta_{J1J2}>3.5","L");
   leg->Draw();

   TLatex *t = new TLatex();
   t->SetTextSize(0.04);
   t->DrawLatex(1.0,40000,"85<m_{ll}<97 GeV, p_{T}^{l}>20 GeV, #eta_{l}<2.4");
   t->DrawLatex(2.0,20000,"p_{T}^{jet}>25 GeV, #eta_{jet}<4.7");

   c2->SaveAs("yZ.png");

   setTDRStyle(0,1);

   TCanvas* c3 = new TCanvas("X","Y",1);

   TFile* file = new TFile("DYmadgraph_histos.root");

   hnjets->GetXaxis()->SetTitle("N gen jets p_{T}> 20 GeV, |#eta|<4.7");
   hnjets->GetYaxis()->SetTitle("");
   hnjets->SetMaximum(10000000.);
   hnjets->SetMinimum(1000.);
   hnjets->SetLineStyle(1);
   hnjets->SetLineWidth(2);
   nm = hnjets->Integral();
   hnjets->Draw("hist");

   TLegend *leg = new TLegend(0.3,0.8,0.9,0.9,NULL,"brNDC");
   leg->SetFillColor(10);
   leg->AddEntry(hnjets,"MadGraph Z+jets","L");

   TFile* file = new TFile("DYsherpa_histos.root");

   scale = nm/hnjets->Integral();
   hnjets->Scale(scale);
   hnjets->SetLineStyle(2);
   hnjets->SetLineWidth(4);
   hnjets->Draw("same");
   hnjets->SetLineStyle(2);
   hnjets->SetLineWidth(2);

   leg->AddEntry(hnjets,"Sherpa Z+jets","L");
   leg->Draw();

   t->DrawLatex(1.5,1000000,"85<m_{ll}<97 GeV, p_{T}^{l}>20 GeV, #eta_{l}<2.4");
   t->DrawLatex(2.5,500000,"p_{T}^{jet}>25 GeV, #eta_{jet}<4.7");

   c3->SaveAs("njets.png");

/*
   setTDRStyle(0,0);

   TCanvas* c4 = new TCanvas("X","Y",1);

   TFile* file = new TFile("DYmadgraph_histos.root");

   hDetaJJ->GetXaxis()->SetTitle("#Delta #eta _{J1J2}");
   hDetaJJ->GetYaxis()->SetTitle("");
   //   hDetaJJ->SetMaximum(50000);
   //   hDetaJJ->SetMinimum(10.);
   hDetaJJ->SetLineStyle(1);
   hDetaJJ->SetLineWidth(3);
   nm = hDetaJJ->Integral();
   hDetaJJ->Draw("hist");

   TLegend *leg = new TLegend(0.3,0.85,0.9,0.95,NULL,"brNDC");
   leg->SetFillColor(10);
   leg->AddEntry(hDetaJJ,"MadGraph Z+jets","L");

   TFile* file = new TFile("DYsherpa_histos.root");

   scale = nm/hDetaJJ->Integral();
   hDetaJJ->Scale(scale);
   hDetaJJ->SetLineStyle(2);
   hDetaJJ->SetLineWidth(4);
   hDetaJJ->Draw("same");
   hDetaJJ->SetLineStyle(2);
   hDetaJJ->SetLineWidth(3);

   leg->AddEntry(hDetaJJ,"Sherpa Z+jets","L");
   leg->Draw();

   c4->SaveAs("DetaJJ.png");

   setTDRStyle(0,1);

   TCanvas* c5 = new TCanvas("X","Y",1);

   TFile* file = new TFile("DYmadgraph_histos.root");

   hMjj->GetXaxis()->SetTitle("M_{J1J2}, GeV");
   hMjj->GetYaxis()->SetTitle("");
   //   hMjj->SetMaximum(50000);
   //   hMjj->SetMinimum(10.);
   hMjj->SetLineStyle(1);
   hMjj->SetLineWidth(3);
   nm = hMjj->Integral();
   hMjj->Draw("hist");

   TLegend *leg = new TLegend(0.3,0.85,0.9,0.95,NULL,"brNDC");
   leg->SetFillColor(10);
   leg->AddEntry(hMjj,"MadGraph Z+jets","L");

   TFile* file = new TFile("DYsherpa_histos.root");

   scale = nm/hMjj->Integral();
   hMjj->Scale(scale);
   hMjj->SetLineStyle(2);
   hMjj->SetLineWidth(4);
   hMjj->Draw("same");
   hMjj->SetLineStyle(2);
   hMjj->SetLineWidth(3);

   leg->AddEntry(hMjj,"Sherpa Z+jets","L");
   leg->Draw();

   c5->SaveAs("Mjj.png");
   */
}
