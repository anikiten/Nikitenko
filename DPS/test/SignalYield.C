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

  // total number of processed MC events
  Double_t NSmc  = 1450000.;
  // Lumi
  // stream A
  Double_t luminosityA = 2.215;
  // stream B
  Double_t luminosityB = 2.534;
  // cross-section in fb
  // MadGraph
  Double_t xsect = 745.0;
  // NLO VBFNLO
  // Double_t xsect = 630.0;
  TFile* file = new TFile("MCPileupHistogram.root");
  Double_t Nmc   = 1.* pileup->Integral();

  cout <<" => total number of processed signal MC events = " << NSmc << endl;

  cout <<" ==> Run A: Signal xsect = " << xsect 
       <<" Total number of expected events at lumi A " << luminosityA 
       <<" = " << xsect*luminosityA << endl;
  cout <<" ==> Run B: Signal xsect = " << xsect
       <<" Total number of expected events at lumi B " << luminosityB 
       <<" = " << xsect*luminosityB << endl;
  cout <<" " << endl;
  // Run A
  cout <<" ================= run A ====================================" << endl;
  TFile* file = new TFile("MyDataPileupHistogramA.root");
  Double_t Ndata = 1.* pileup->Integral();
  Double_t scale = Ndata/Nmc;
  Double_t luminosity = luminosityA;
  // normalization
  Double_t NStot = NSmc * scale;
  cout <<" => NPUdata = " << Ndata <<" NPUmc = " << Nmc <<" scale = " << scale << endl;
  cout <<" => total number of processed MC events after scaling= " << NStot << endl;
  TFile* file = new TFile("SignalMCFall11A_29Feb.root");
  // Z
  Double_t NZY            = hZY->Integral();
  Double_t efficiency     = NZY/NStot;
  Double_t NS             = xsect * luminosity * efficiency;
  cout <<" Expected signal at Z mass peak = " << NS 
       <<"  (efficiency = " << efficiency <<" )" << endl;
 
  // +2J
  Double_t NZY2J          = hZY2J->Integral();
  efficiency     = NZY2J/NStot;
  NS             = xsect * luminosity * efficiency;
  cout <<" Expected signal Z + two jets = " << NS 
       <<"  (efficiency = " << efficiency <<" )" << endl;
   setTDRStyle(0,0);
   TCanvas* c1 = new TCanvas("X","Y",1);
   hDeta0->GetXaxis()->SetTitle("#Delta #eta _{j1j2}");
   hDeta0->GetYaxis()->SetTitle("Nev");
   Double_t norm = NS / hDeta0->Integral();
   hDeta0->Scale(norm);
   hDeta0->SetMaximum(20.);
   hDeta0->SetLineStyle(1);
   hDeta0->SetLineWidth(3);
   //   hDeta1->SetMarkerStyle(24);
   hDeta0->Draw("hist");
   hDeta1->SetLineWidth(3);
   hDeta1->SetLineStyle(2);
   hDeta1->Scale(norm);
   hDeta1->Draw("same");
   TLegend *leg = new TLegend(0.2,0.85,0.9,0.95,NULL,"brNDC");
   leg->SetFillColor(10);
   leg->AddEntry(hDeta0,"two jets","L");
   leg->AddEntry(hDeta1,"two jets, #eta_{j1}#times#eta_{j2}<0","L");
   leg->Draw();
   TLatex *t = new TLatex();
   t->SetTextSize(0.042);
   t->DrawLatex(4.,14.,"EWK Z+2jets, stream A");
   c1->SaveAs("detaj1j2A_signal.png");

  // + Deta
  Double_t NZY2JDeta      = hZY2JDeta->Integral();
  efficiency     = NZY2JDeta/NStot;
  NS             = xsect * luminosity * efficiency;
  cout <<" Expected signal Z + two jets + Deta = " << NS 
       <<"  (efficiency = " << efficiency <<" )" << endl;
  
  // + CJV
  Double_t NZY2JDetaCJV   = hZY2JDetaCJV->Integral();
  efficiency     = NZY2JDetaCJV/NStot;
  NS             = xsect * luminosity * efficiency;
  cout <<" Expected signal Z + two jets + Deta + CJV = " << NS 
       <<"  (efficiency = " << efficiency <<" )" << endl;
  setTDRStyle(0,1);
  TCanvas* c2 = new TCanvas("X","Y",1);
  hMjj->GetXaxis()->SetTitle("M_{j1j2}, GeV");
  hMjj->GetYaxis()->SetTitle("Nev");
  norm = NS / hMjj->Integral();
  hMjj->Scale(norm);
  hMjj->SetMaximum(10.);
  hMjj->SetMinimum(0.1);
  hMjj->SetLineStyle(1);
  hMjj->SetLineWidth(3);
  hMjj->Draw("hist");
  TLegend *leg = new TLegend(0.15,0.8,0.9,0.9,NULL,"brNDC");
  leg->SetFillColor(10);
  leg->AddEntry(hMjj,"two jets, #eta _{j1}#eta _{j2}<0, #Delta#eta>3.5, CJV ","L");
  leg->Draw();
  TLatex *t = new TLatex();
  t->SetTextSize(0.042);
  t->DrawLatex(800.,3.,"EWK Z+2jets, stream A");
  c2->SaveAs("mass_jjA_signal.png");

  // + Mjj
  Double_t NZY2JDetaCJVMjj =  hZY2JDetaCJVMjj->Integral();
  efficiency     = NZY2JDetaCJVMjj/NStot;
  NS             = xsect * luminosity * efficiency;
  cout <<" Expected signal Z + two jets + Deta + CJV + Mjj = " << NS 
       <<"  (efficiency = " << efficiency <<" )" << endl;


  cout <<" " << endl;
  // Run B
  cout <<" ================= run B ====================================" << endl;
  TFile* file = new TFile("MyDataPileupHistogramB.root");
  Ndata = 1.* pileup->Integral();
  scale = Ndata/Nmc;
  luminosity = luminosityB;
  // normalization
  Double_t NStot = NSmc * scale;
  cout <<" => NPUdata = " << Ndata <<" NPUmc = " << Nmc <<" scale = " << scale << endl;
  cout <<" => total number of processed MC events after scaling= " << NStot << endl;
  TFile* file = new TFile("SignalMCFall11B_29Feb.root");
  // Z
  NZY            = hZY->Integral();
  efficiency     = NZY/NStot;
  NS             = xsect * luminosity * efficiency;
  cout <<" Expected signal at Z mass peak = " << NS 
       <<"  (efficiency = " << efficiency <<" )" << endl;
 
  // +2J
  NZY2J          = hZY2J->Integral();
  efficiency     = NZY2J/NStot;
  NS             = xsect * luminosity * efficiency;
  cout <<" Expected signal Z + two jets = " << NS 
       <<"  (efficiency = " << efficiency <<" )" << endl;

  // + Deta
  Double_t NZY2JDeta      = hZY2JDeta->Integral();
  efficiency     = NZY2JDeta/NStot;
  NS             = xsect * luminosity * efficiency;
  cout <<" Expected signal Z + two jets + Deta = " << NS 
       <<"  (efficiency = " << efficiency <<" )" << endl;
  
  // + CJV
  NZY2JDetaCJV   = hZY2JDetaCJV->Integral();
  efficiency     = NZY2JDetaCJV/NStot;
  NS             = xsect * luminosity * efficiency;
  cout <<" Expected signal Z + two jets + Deta + CJV = " << NS 
       <<"  (efficiency = " << efficiency <<" )" << endl;
  
  // + Mjj
  NZY2JDetaCJVMjj =  hZY2JDetaCJVMjj->Integral();
  efficiency      = NZY2JDetaCJVMjj/NStot;
  NS              = xsect * luminosity * efficiency;
  cout <<" Expected signal Z + two jets + Deta + CJV + Mjj = " << NS 
       <<"  (efficiency = " << efficiency <<" )" << endl;

}
