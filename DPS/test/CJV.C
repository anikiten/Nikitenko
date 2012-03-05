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


  // stream A+B

  cout <<" ========================== A+B ============================" << endl;

  // CJV 25 GeV 
  // pT
  setTDRStyle(0,0);
  // data
  cout <<" =============== CJV with pT tag jets > 25 GeV =================== " << endl;
  TFile* file = new TFile("DYhistosA+B.root");
  TCanvas* c1 = new TCanvas("X","Y",1);
  hPtJ3tag25->GetXaxis()->SetTitle("p_{T} central jet, GeV");
  hPtJ3tag25->GetYaxis()->SetTitle("Nev / 5 GeV");
  hPtJ3tag25->SetMaximum(1000.);
  hPtJ3tag25->SetMinimum(0.);
  hPtJ3tag25->SetLineStyle(1);
  hPtJ3tag25->SetLineWidth(3);
  hPtJ3tag25->SetMarkerStyle(24);
  hPtJ3tag25->SetMarkerSize(1.2);
  hPtJ3tag25->Draw("PE");
  Double_t N0data = hZY2JDeta->Integral();
  Double_t NSdata = hEtaJ3tag25->Integral();
  Double_t effdata = (N0data-NSdata)/N0data;
  Double_t err = sqrt(effdata*(1-effdata)/(N0data-NSdata));
  cout <<" => data: Nev before CJV = " << N0data 
       <<" Nev after CVJ = " << N0data-NSdata
       <<" efficiency = " << effdata <<" +/- " << err << endl;
  TLegend *leg = new TLegend(0.35,0.7,0.95,0.85,NULL,"brNDC");
  leg->SetFillColor(10);
  leg->AddEntry(hPtJ3tag25,"data, p_{T}^{j1,j2}>25 GeV, #Delta#eta_{j1j2}>3.5","P");
  // MC
  TFile* file = new TFile("DYhistosMCA+B.root");
  Double_t N0mc = hZY2JDeta->Integral();
  Double_t NSmc = hEtaJ3tag25->Integral();
  Double_t effmc = (N0mc-NSmc)/N0mc;
  cout <<" => mc  : Nev before CJV = " << N0mc 
       <<" Nev after CVJ = " << N0mc-NSmc
       <<" efficiency = " << effmc << endl;
  Double_t scale = NSdata/hEtaJ3tag25->Integral();
  hPtJ3tag25->Scale(scale);
  hPtJ3tag25->SetLineStyle(1);
  hPtJ3tag25->SetLineWidth(3);
  hPtJ3tag25->Draw("same");
  leg->AddEntry(hPtJ3tag25,"simulation","L");
  leg->Draw();
  c1->SaveAs("cjv25pt.png");


  // eta
  setTDRStyle(0,0);
  // data
  TFile* file = new TFile("DYhistosA+B.root");
  TCanvas* c2 = new TCanvas("X","Y",1);
  hEtaJ3tag25->GetXaxis()->SetTitle("#eta");
  hEtaJ3tag25->GetYaxis()->SetTitle("Nev / 0.4");
  hEtaJ3tag25->SetMaximum(400.);
  hEtaJ3tag25->SetMinimum(0.);
  hEtaJ3tag25->SetLineStyle(1);
  hEtaJ3tag25->SetLineWidth(3);
  hEtaJ3tag25->SetMarkerStyle(24);
  hEtaJ3tag25->SetMarkerSize(1.2);
  hEtaJ3tag25->Draw("PE");
  TLegend *leg = new TLegend(0.25,0.75,0.85,0.90,NULL,"brNDC");
  leg->SetFillColor(10);
  leg->AddEntry(hEtaJ3tag25,"data, p_{T}^{j1,j2}>25 GeV, #Delta#eta_{j1j2}>3.5","P");
  // MC
  TFile* file = new TFile("DYhistosMCA+B.root");
  Double_t scale = NSdata/hEtaJ3tag25->Integral();
  hEtaJ3tag25->Scale(scale);
  hEtaJ3tag25->SetLineStyle(1);
  hEtaJ3tag25->SetLineWidth(3);
  hEtaJ3tag25->Draw("same");
  leg->AddEntry(hEtaJ3tag25,"simulation","L");
  leg->Draw();
  /*
    TLatex *t = new TLatex();
    t->SetTextSize(0.042);
    t->DrawLatex(50,600,"p_{T}^{tag jets}>25 GeV");
    t->DrawLatex(50,600,"p_{T}^{tag jets}>25 GeV");
  */
  c2->SaveAs("cjv25eta.png");

  // CJV 35 GeV 
  // pT
  setTDRStyle(0,0);
  // data
  cout <<" =============== CJV with pT tag jets > 35 GeV =================== " << endl;
  TFile* file = new TFile("DYhistosA+B.root");
  TCanvas* c3 = new TCanvas("X","Y",1);
  hPtJ3tag35->GetXaxis()->SetTitle("p_{T} central jet, GeV");
  hPtJ3tag35->GetYaxis()->SetTitle("Nev / 5 GeV");
  hPtJ3tag35->SetMaximum(350.);
  hPtJ3tag35->SetMinimum(0.);
  hPtJ3tag35->SetLineStyle(1);
  hPtJ3tag35->SetLineWidth(3);
  hPtJ3tag35->SetMarkerStyle(24);
  hPtJ3tag35->SetMarkerSize(1.2);
  hPtJ3tag35->Draw("PE");
  Double_t N0data = hZY2JDeta35->Integral();
  Double_t NSdata = hEtaJ3tag35->Integral();
  Double_t effdata = (N0data-NSdata)/N0data;
  Double_t err = sqrt(effdata*(1-effdata)/(N0data-NSdata));
  cout <<" => data: Nev before CJV = " << N0data 
       <<" Nev after CVJ = " << N0data-NSdata
       <<" efficiency = " << effdata <<" +/- " << err << endl;
  TLegend *leg = new TLegend(0.35,0.7,0.95,0.85,NULL,"brNDC");
  leg->SetFillColor(10);
  leg->AddEntry(hPtJ3tag35,"data, p_{T}^{j1,j2}>35 GeV, #Delta#eta_{j1j2}>3.5","P");
  // MC
  TFile* file = new TFile("DYhistosMCA+B.root");
  Double_t N0mc = hZY2JDeta35->Integral();
  Double_t NSmc = hEtaJ3tag35->Integral();
  Double_t effmc = (N0mc-NSmc)/N0mc;
  cout <<" => mc  : Nev before CJV = " << N0mc 
       <<" Nev after CVJ = " << N0mc-NSmc
       <<" efficiency = " << effmc << endl;
  Double_t scale = NSdata/hEtaJ3tag35->Integral();
  hPtJ3tag35->Scale(scale);
  hPtJ3tag35->SetLineStyle(1);
  hPtJ3tag35->SetLineWidth(3);
  hPtJ3tag35->Draw("same");
  leg->AddEntry(hPtJ3tag35,"simulation","L");
  leg->Draw();
  c3->SaveAs("cjv35pt.png");

  // eta
  setTDRStyle(0,0);
  // data
  TFile* file = new TFile("DYhistosA+B.root");
  TCanvas* c4 = new TCanvas("X","Y",1);
  hEtaJ3tag35->GetXaxis()->SetTitle("#eta");
  hEtaJ3tag35->GetYaxis()->SetTitle("Nev / 0.4");
  hEtaJ3tag35->SetMaximum(220.);
  hEtaJ3tag35->SetMinimum(0.);
  hEtaJ3tag35->SetLineStyle(1);
  hEtaJ3tag35->SetLineWidth(3);
  hEtaJ3tag35->SetMarkerStyle(24);
  hEtaJ3tag35->SetMarkerSize(1.2);
  hEtaJ3tag35->Draw("PE");
  TLegend *leg = new TLegend(0.25,0.75,0.85,0.90,NULL,"brNDC");
  leg->SetFillColor(10);
  leg->AddEntry(hEtaJ3tag35,"data, p_{T}^{j1,j2}>35 GeV, #Delta#eta_{j1j2}>3.5","P");
  // MC
  TFile* file = new TFile("DYhistosMCA+B.root");
  Double_t scale = NSdata/hEtaJ3tag35->Integral();
  hEtaJ3tag35->Scale(scale);
  hEtaJ3tag35->SetLineStyle(1);
  hEtaJ3tag35->SetLineWidth(3);
  hEtaJ3tag35->Draw("same");
  leg->AddEntry(hEtaJ3tag35,"simulation","L");
  leg->Draw();
  /*
    TLatex *t = new TLatex();
    t->SetTextSize(0.042);
    t->DrawLatex(50,600,"p_{T}^{tag jets}>35 GeV");
    t->DrawLatex(50,600,"p_{T}^{tag jets}>35 GeV");
  */
  c4->SaveAs("cjv35eta.png");


  // CJV 45 GeV 
  // pT
  setTDRStyle(0,0);
  // data
  cout <<" =============== CJV with pT tag jets > 45 GeV =================== " << endl;
  TFile* file = new TFile("DYhistosA+B.root");
  TCanvas* c5 = new TCanvas("X","Y",1);
  hPtJ3tag45->GetXaxis()->SetTitle("p_{T} central jet, GeV");
  hPtJ3tag45->GetYaxis()->SetTitle("Nev / 5 GeV");
  hPtJ3tag45->SetMaximum(160.);
  hPtJ3tag45->SetMinimum(0.);
  hPtJ3tag45->SetLineStyle(1);
  hPtJ3tag45->SetLineWidth(3);
  hPtJ3tag45->SetMarkerStyle(24);
  hPtJ3tag45->SetMarkerSize(1.2);
  hPtJ3tag45->Draw("PE");
  Double_t N0data = hZY2JDeta45->Integral();
  Double_t NSdata = hEtaJ3tag45->Integral();
  Double_t effdata = (N0data-NSdata)/N0data;
  Double_t err = sqrt(effdata*(1-effdata)/(N0data-NSdata));
  cout <<" => data: Nev before CJV = " << N0data 
       <<" Nev after CVJ = " << N0data-NSdata
       <<" efficiency = " << effdata <<" +/- " << err << endl;
  TLegend *leg = new TLegend(0.35,0.7,0.95,0.85,NULL,"brNDC");
  leg->SetFillColor(10);
  leg->AddEntry(hPtJ3tag45,"data, p_{T}^{j1,j2}>45 GeV, #Delta#eta_{j1j2}>3.5","P");
  // MC
  TFile* file = new TFile("DYhistosMCA+B.root");
  Double_t N0mc = hZY2JDeta45->Integral();
  Double_t NSmc = hEtaJ3tag45->Integral();
  Double_t effmc = (N0mc-NSmc)/N0mc;
  cout <<" => mc  : Nev before CJV = " << N0mc 
       <<" Nev after CVJ = " << N0mc-NSmc
       <<" efficiency = " << effmc << endl;
  Double_t scale = NSdata/hEtaJ3tag45->Integral();
  hPtJ3tag45->Scale(scale);
  hPtJ3tag45->SetLineStyle(1);
  hPtJ3tag45->SetLineWidth(3);
  hPtJ3tag45->Draw("same");
  leg->AddEntry(hPtJ3tag45,"simulation","L");
  leg->Draw();
  c5->SaveAs("cjv45pt.png");

  // eta
  setTDRStyle(0,0);
  // data
  TFile* file = new TFile("DYhistosA+B.root");
  TCanvas* c6 = new TCanvas("X","Y",1);
  hEtaJ3tag45->GetXaxis()->SetTitle("#eta");
  hEtaJ3tag45->GetYaxis()->SetTitle("Nev / 0.4");
  hEtaJ3tag45->SetMaximum(120.);
  hEtaJ3tag45->SetMinimum(0.);
  hEtaJ3tag45->SetLineStyle(1);
  hEtaJ3tag45->SetLineWidth(3);
  hEtaJ3tag45->SetMarkerStyle(24);
  hEtaJ3tag45->SetMarkerSize(1.2);
  hEtaJ3tag45->Draw("PE");
  TLegend *leg = new TLegend(0.25,0.75,0.85,0.90,NULL,"brNDC");
  leg->SetFillColor(10);
  leg->AddEntry(hEtaJ3tag45,"data, p_{T}^{j1,j2}>45 GeV, #Delta#eta_{j1j2}>3.5","P");
  // MC
  TFile* file = new TFile("DYhistosMCA+B.root");
  Double_t scale = NSdata/hEtaJ3tag45->Integral();
  hEtaJ3tag45->Scale(scale);
  hEtaJ3tag45->SetLineStyle(1);
  hEtaJ3tag45->SetLineWidth(3);
  hEtaJ3tag45->Draw("same");
  leg->AddEntry(hEtaJ3tag45,"simulation","L");
  leg->Draw();
  /*
    TLatex *t = new TLatex();
    t->SetTextSize(0.042);
    t->DrawLatex(50,600,"p_{T}^{tag jets}>45 GeV");
    t->DrawLatex(50,600,"p_{T}^{tag jets}>45 GeV");
  */
  c6->SaveAs("cjv45eta.png");

}
