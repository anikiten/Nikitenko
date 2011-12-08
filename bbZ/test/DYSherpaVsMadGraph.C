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
   hpTZ->SetMaximum(50000);
   hpTZ->SetMinimum(1.);
   hpTZ->SetLineStyle(1);
   hpTZ->SetLineWidth(2);
   Double_t nm = hpTZ->Integral();
   hpTZ->Draw("hist");

   hpTZ1J->SetLineStyle(1);
   hpTZ1J->SetLineWidth(3);
   Double_t nm1J = hpTZ1J->Integral();
   hpTZ1J->Draw("same");

   hpTZ2J->SetLineStyle(1);
   hpTZ2J->SetLineWidth(4);
   Double_t nm2J = hpTZ2J->Integral();
   hpTZ2J->Draw("same");

   TLegend *leg = new TLegend(0.3,0.65,0.9,0.95,NULL,"brNDC");
   leg->SetFillColor(10);
   leg->AddEntry(hpTZ,"MadGraph Z inclusive","L");
   leg->AddEntry(hpTZ1J,"MadGraph Z+#geq1jet","L");
   leg->AddEntry(hpTZ2J,"MadGraph Z+#geq2jet","L");

   TFile* file = new TFile("DYsherpa_histos.root");

   Double_t scale = nm/hpTZ->Integral();
   hpTZ->Scale(scale);
   hpTZ->SetLineStyle(2);
   hpTZ->SetLineWidth(2);
   hpTZ->Draw("same");

   scale = nm1J/hpTZ1J->Integral();
   hpTZ1J->Scale(scale);
   hpTZ1J->SetLineStyle(2);
   hpTZ1J->SetLineWidth(3);
   hpTZ1J->Draw("same");

   scale = nm2J/hpTZ2J->Integral();
   hpTZ2J->Scale(scale);
   hpTZ2J->SetLineStyle(2);
   hpTZ2J->SetLineWidth(4);
   hpTZ2J->Draw("same");

   leg->AddEntry(hpTZ,"Sherpa Z inclusive","L");
   leg->AddEntry(hpTZ1J,"Sherpa Z+#geq1jet","L");
   leg->AddEntry(hpTZ2J,"Sherpa Z+#geq2jet","L");
   leg->Draw();

   c1->SaveAs("pTZ.png");

   setTDRStyle(0,1);

   TCanvas* c2 = new TCanvas("X","Y",1);

   TFile* file = new TFile("DYmadgraph_histos.root");

   hyZ->GetXaxis()->SetTitle("Z rapidity");
   hyZ->GetYaxis()->SetTitle("");
   hyZ->SetMaximum(100000);
   hyZ->SetMinimum(1.);
   hyZ->SetLineStyle(1);
   hyZ->SetLineWidth(2);
   Double_t nm = hyZ->Integral();
   hyZ->Draw("hist");

   hyZ1J->SetLineStyle(1);
   hyZ1J->SetLineWidth(3);
   Double_t nm1J = hyZ1J->Integral();
   hyZ1J->Draw("same");

   hyZ2J->SetLineStyle(1);
   hyZ2J->SetLineWidth(4);
   Double_t nm2J = hyZ2J->Integral();
   hyZ2J->Draw("same");

   TLegend *leg = new TLegend(0.3,0.65,0.9,0.95,NULL,"brNDC");
   leg->SetFillColor(10);
   leg->AddEntry(hyZ,"MadGraph Z inclusive","L");
   leg->AddEntry(hyZ1J,"MadGraph Z+#geq1jet","L");
   leg->AddEntry(hyZ2J,"MadGraph Z+#geq2jet","L");

   TFile* file = new TFile("DYsherpa_histos.root");

   Double_t scale = nm/hyZ->Integral();
   hyZ->Scale(scale);
   hyZ->SetLineStyle(2);
   hyZ->SetLineWidth(2);
   hyZ->Draw("same");

   scale = nm1J/hyZ1J->Integral();
   hyZ1J->Scale(scale);
   hyZ1J->SetLineStyle(2);
   hyZ1J->SetLineWidth(3);
   hyZ1J->Draw("same");

   scale = nm2J/hyZ2J->Integral();
   hyZ2J->Scale(scale);
   hyZ2J->SetLineStyle(2);
   hyZ2J->SetLineWidth(4);
   hyZ2J->Draw("same");

   leg->AddEntry(hyZ,"Sherpa Z inclusive","L");
   leg->AddEntry(hyZ1J,"Sherpa Z+#geq1jet","L");
   leg->AddEntry(hyZ2J,"Sherpa Z+#geq2jet","L");
   leg->Draw();

   c2->SaveAs("yZ.png");


}
