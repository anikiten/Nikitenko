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
  //===================================================  pT jet

   setTDRStyle(0,1);
   TCanvas* c10 = new TCanvas("X","Y",1);
   TLegend *leg = new TLegend(0.5,0.8,0.9,0.9,NULL,"brNDC");
   TFile* file = new TFile("datatau7TeV.root");
   leg->SetFillColor(10);
   hEtRaw->GetXaxis()->SetTitle("p_{T}^{tcTau}, GeV");
   hEtRaw->GetYaxis()->SetTitle("Nev");
   hEtRaw->SetMarkerSize(1.0);
   hEtRaw->SetMarkerStyle(20);
   hEtRaw->SetMaximum(6000.0);
   hEtRaw->SetMinimum(0.5);
   hEtRaw->Draw("histPE");
   Double_t exp = hEtRaw->Integral();
   leg->AddEntry(hEtRaw,"data  ","P");

   TFile* file = new TFile("mctau7TeV.root");
   Double_t mc = hEtRaw->Integral();
   Double_t scale = exp/mc;
   hEtRaw->Scale(scale);
   hEtRaw->SetLineWidth(3);
   hEtRaw->Draw("same");
   leg->AddEntry(hEtRaw,"Monte Carlo","L");
   leg->Draw();  
   //   TLatex *t = new TLatex();
   //   t->SetTextSize(0.04);
   //   t->DrawLatex(10.0,10.0,"JPT di-jet events");
   //   t->DrawLatex(10.0,7.0,"E_{T}^{jet} > 10 GeV, |#eta^{jet}| < 2");
   c10->SaveAs("hEtRaw.gif");

   // ======================== eta ========================
   setTDRStyle(0,0);
   TCanvas* c20 = new TCanvas("X","Y",1);
   TLegend *leg = new TLegend(0.5,0.8,0.9,0.9,NULL,"brNDC");
   TFile* file = new TFile("datatau7TeV.root");
   leg->SetFillColor(10);
   hEtaRaw->GetXaxis()->SetTitle("#eta ^{tcTau}");
   hEtaRaw->GetYaxis()->SetTitle("Nev");
   hEtaRaw->SetMarkerSize(1.5);
   hEtaRaw->SetMarkerStyle(20);
   hEtaRaw->SetMaximum(1200.0);
   hEtaRaw->SetMinimum(0.0);
   hEtaRaw->Draw("histPE");
   Double_t exp = hEtaRaw->Integral();
   leg->AddEntry(hEtaRaw,"data  ","P");

   TFile* file = new TFile("mctau7TeV.root");
   Double_t mc = hEtaRaw->Integral();
   Double_t scale = exp/mc;
   hEtaRaw->Scale(scale);
   hEtaRaw->SetLineWidth(3);
   hEtaRaw->Draw("same");
   leg->AddEntry(hEtaRaw,"Monte Carlo","L");
   leg->Draw();  
   //   TLatex *t = new TLatex();
   //   t->SetTextSize(0.04);
   //   t->DrawLatex(10.0,10.0,"JPT di-jet events");
   //   t->DrawLatex(10.0,7.0,"E_{T}^{jet} > 10 GeV, |#eta^{jet}| < 2");
   c20->SaveAs("hEtaRaw.gif");

   setTDRStyle(0,0);
   TCanvas* c1 = new TCanvas("X","Y",1);
   TLegend *leg = new TLegend(0.5,0.8,0.9,0.9,NULL,"brNDC");
   TFile* file = new TFile("datatau7TeV.root");
   leg->SetFillColor(10);
   hDRjettrk->GetXaxis()->SetTitle("#Delta R (jet axis-leading p_{T} track)");
   hDRjettrk->GetYaxis()->SetTitle("Nev");
   hDRjettrk->SetMarkerSize(1.2);
   hDRjettrk->SetMarkerStyle(20);
   hDRjettrk->SetMaximum(1600.0);
   hDRjettrk->SetMinimum(0.0);
   hDRjettrk->Draw("histPE");
   Double_t exp = hDRjettrk->Integral();
   leg->AddEntry(hDRjettrk,"data  ","P");

   TFile* file = new TFile("mctau7TeV.root");
   Double_t mc = hDRjettrk->Integral();
   Double_t scale = exp/mc;
   hDRjettrk->Scale(scale);
   hDRjettrk->SetLineWidth(3);
   hDRjettrk->Draw("same");
   leg->AddEntry(hDRjettrk,"Monte Carlo","L");
   leg->Draw();  
   //   TLatex *t = new TLatex();
   //   t->SetTextSize(0.04);
   //   t->DrawLatex(10.0,10.0,"JPT di-jet events");
   //   t->DrawLatex(10.0,7.0,"E_{T}^{jet} > 10 GeV, |#eta^{jet}| < 2");
   c1->SaveAs("hDRjettrk.gif");

  //===================================================  ip of lead pT trk
   setTDRStyle(0,1);
   TCanvas* c2 = new TCanvas("X","Y",1);
   TLegend *leg = new TLegend(0.5,0.8,0.9,0.9,NULL,"brNDC");
   TFile* file = new TFile("datatau7TeV.root");
   leg->SetFillColor(10);
   hd0ltr->GetXaxis()->SetTitle("transv.ip of leading p_{T} track, cm");
   hd0ltr->GetYaxis()->SetTitle("Nev");
   hd0ltr->SetMarkerSize(1.2);
   hd0ltr->SetMarkerStyle(20);
   hd0ltr->SetMaximum(10000.0);
   hd0ltr->SetMinimum(10.);
   hd0ltr->Draw("histPE");
   Double_t exp = hd0ltr->Integral();
   leg->AddEntry(hd0ltr,"data  ","P");

   TFile* file = new TFile("mctau7TeV.root");
   Double_t mc = hd0ltr->Integral();
   Double_t scale = exp/mc;
   hd0ltr->Scale(scale);
   hd0ltr->SetLineWidth(3);
   hd0ltr->Draw("same");
   leg->AddEntry(hd0ltr,"Monte Carlo","L");
   leg->Draw();  
   //   TLatex *t = new TLatex();
   //   t->SetTextSize(0.04);
   //   t->DrawLatex(10.0,10.0,"JPT di-jet events");
   //   t->DrawLatex(10.0,7.0,"E_{T}^{jet} > 10 GeV, |#eta^{jet}| < 2");
   c2->SaveAs("hd0ltr.gif");

  //===================================================  pT of lead pT trk
   setTDRStyle(0,0);
   TCanvas* c3 = new TCanvas("X","Y",1);
   TLegend *leg = new TLegend(0.5,0.8,0.9,0.9,NULL,"brNDC");
   TFile* file = new TFile("datatau7TeV.root");
   leg->SetFillColor(10);
   hptltr->GetXaxis()->SetTitle("p_{T} of leading p_{T} track, GeV");
   hptltr->GetYaxis()->SetTitle("Nev");
   hptltr->SetMarkerSize(1.0);
   hptltr->SetMarkerStyle(20);
   hptltr->SetMaximum(400.0);
   hptltr->SetMinimum(0.0);
   hptltr->Draw("histPE");
   Double_t exp = hptltr->Integral();
   leg->AddEntry(hptltr,"data  ","P");

   TFile* file = new TFile("mctau7TeV.root");
   Double_t mc = hptltr->Integral();
   Double_t scale = exp/mc;
   hptltr->Scale(scale);
   hptltr->SetLineWidth(3);
   hptltr->Draw("same");
   leg->AddEntry(hptltr,"Monte Carlo","L");
   leg->Draw();  
   //   TLatex *t = new TLatex();
   //   t->SetTextSize(0.04);
   //   t->DrawLatex(10.0,10.0,"JPT di-jet events");
   //   t->DrawLatex(10.0,7.0,"E_{T}^{jet} > 10 GeV, |#eta^{jet}| < 2");
   c3->SaveAs("hptltr.gif");

  //===================================================  ntrk in signal cone
   setTDRStyle(0,1);
   TCanvas* c4 = new TCanvas("X","Y",1);
   TLegend *leg = new TLegend(0.5,0.8,0.9,0.9,NULL,"brNDC");
   TFile* file = new TFile("datatau7TeV.root");
   leg->SetFillColor(10);
   hntrsign->GetXaxis()->SetTitle("N tracks in signal cone");
   hntrsign->GetYaxis()->SetTitle("Nev");
   hntrsign->SetMarkerSize(1.2);
   hntrsign->SetMarkerStyle(20);
   hntrsign->SetMaximum(20000.0);
   hntrsign->SetMinimum(0.5);
   hntrsign->Draw("histPE");
   Double_t exp = hntrsign->Integral();
   leg->AddEntry(hntrsign,"data  ","P");

   TFile* file = new TFile("mctau7TeV.root");
   Double_t mc = hntrsign->Integral();
   Double_t scale = exp/mc;
   hntrsign->Scale(scale);
   hntrsign->SetLineWidth(3);
   hntrsign->Draw("same");
   leg->AddEntry(hntrsign,"Monte Carlo","L");
   leg->Draw();  
   //   TLatex *t = new TLatex();
   //   t->SetTextSize(0.04);
   //   t->DrawLatex(10.0,10.0,"JPT di-jet events");
   //   t->DrawLatex(10.0,7.0,"E_{T}^{jet} > 10 GeV, |#eta^{jet}| < 2");
   c4->SaveAs("hntrsign.gif");

  //===================================================  ntrk in isolation ring
   setTDRStyle(0,1);
   TCanvas* c5 = new TCanvas("X","Y",1);
   TLegend *leg = new TLegend(0.5,0.8,0.9,0.9,NULL,"brNDC");
   TFile* file = new TFile("datatau7TeV.root");
   leg->SetFillColor(10);
   hntrisol->GetXaxis()->SetTitle("N tracks in isolation ring");
   hntrisol->GetYaxis()->SetTitle("Nev");
   hntrisol->SetMarkerSize(1.2);
   hntrisol->SetMarkerStyle(20);
   hntrisol->SetMaximum(6000.0);
   hntrisol->SetMinimum(0.5);
   hntrisol->Draw("histPE");
   Double_t exp = hntrisol->Integral();
   leg->AddEntry(hntrisol,"data  ","P");

   TFile* file = new TFile("mctau7TeV.root");
   Double_t mc = hntrisol->Integral();
   Double_t scale = exp/mc;
   hntrisol->Scale(scale);
   hntrisol->SetLineWidth(3);
   hntrisol->Draw("same");
   leg->AddEntry(hntrisol,"Monte Carlo","L");
   leg->Draw();  
   //   TLatex *t = new TLatex();
   //   t->SetTextSize(0.04);
   //   t->DrawLatex(10.0,10.0,"JPT di-jet events");
   //   t->DrawLatex(10.0,7.0,"E_{T}^{jet} > 10 GeV, |#eta^{jet}| < 2");
   c5->SaveAs("hntrisol.gif");

  //=================================================== pt min trk in signal cone
   setTDRStyle(0,0);
   TCanvas* c5 = new TCanvas("X","Y",1);
   TLegend *leg = new TLegend(0.5,0.8,0.9,0.9,NULL,"brNDC");
   TFile* file = new TFile("datatau7TeV.root");
   leg->SetFillColor(10);
   hptminsign->GetXaxis()->SetTitle("track min p_{T}^{min} in signal cone, GeV");
   hptminsign->GetYaxis()->SetTitle("Nev");
   hptminsign->SetMarkerSize(1.0);
   hptminsign->SetMarkerStyle(20);
   hptminsign->SetMaximum(500.0);
   hptminsign->SetMinimum(0.0);
   hptminsign->Draw("histPE");
   Double_t exp = hptminsign->Integral();
   leg->AddEntry(hptminsign,"data  ","P");

   TFile* file = new TFile("mctau7TeV.root");
   Double_t mc = hptminsign->Integral();
   Double_t scale = exp/mc;
   hptminsign->Scale(scale);
   hptminsign->SetLineWidth(3);
   hptminsign->Draw("same");
   leg->AddEntry(hptminsign,"Monte Carlo","L");
   leg->Draw();  
   //   TLatex *t = new TLatex();
   //   t->SetTextSize(0.04);
   //   t->DrawLatex(10.0,10.0,"JPT di-jet events");
   //   t->DrawLatex(10.0,7.0,"E_{T}^{jet} > 10 GeV, |#eta^{jet}| < 2");
   c5->SaveAs("hptminsign.gif");

  //=================================================== pt min trk in isol ring
   setTDRStyle(0,1);
   TCanvas* c6 = new TCanvas("X","Y",1);
   TLegend *leg = new TLegend(0.5,0.8,0.9,0.9,NULL,"brNDC");
   TFile* file = new TFile("datatau7TeV.root");
   leg->SetFillColor(10);
   hptminisol->GetXaxis()->SetTitle("track p_{T}^{min} in isolation ring, GeV");
   hptminisol->GetYaxis()->SetTitle("Nev");
   hptminisol->SetMarkerSize(1.0);
   hptminisol->SetMarkerStyle(20);
   //   hptminisol->SetMaximum(2000.0);
   hptminisol->SetMinimum(0.5);
   hptminisol->Draw("histPE");
   Double_t exp = hptminisol->Integral();
   leg->AddEntry(hptminisol,"data  ","P");

   TFile* file = new TFile("mctau7TeV.root");
   Double_t mc = hptminisol->Integral();
   Double_t scale = exp/mc;
   hptminisol->Scale(scale);
   hptminisol->SetLineWidth(3);
   hptminisol->Draw("same");
   leg->AddEntry(hptminisol,"Monte Carlo","L");
   leg->Draw();  
   //   TLatex *t = new TLatex();
   //   t->SetTextSize(0.04);
   //   t->DrawLatex(10.0,10.0,"JPT di-jet events");
   //   t->DrawLatex(10.0,7.0,"E_{T}^{jet} > 10 GeV, |#eta^{jet}| < 2");
   c6->SaveAs("hptminisol.gif");

   //=================================================== dz ltr-tr
   setTDRStyle(0,1);
   TCanvas* c7 = new TCanvas("X","Y",1);
   TLegend *leg = new TLegend(0.5,0.8,0.9,0.9,NULL,"brNDC");
   TFile* file = new TFile("datatau7TeV.root");
   leg->SetFillColor(10);
   hdzmaxltr->GetXaxis()->SetTitle("#Delta z_{ltr-tr}, cm");
   hdzmaxltr->GetYaxis()->SetTitle("Nev");
   hdzmaxltr->SetMarkerSize(1.0);
   hdzmaxltr->SetMarkerStyle(20);
   //   hdzmaxltr->SetMaximum(350.0);
   hdzmaxltr->SetMinimum(0.5);
   hdzmaxltr->Draw("histPE");
   Double_t exp = hdzmaxltr->Integral();
   leg->AddEntry(hdzmaxltr,"data  ","P");

   TFile* file = new TFile("mctau7TeV.root");
   Double_t mc = hdzmaxltr->Integral();
   Double_t scale = exp/mc;
   hdzmaxltr->Scale(scale);
   hdzmaxltr->SetLineWidth(3);
   hdzmaxltr->Draw("same");
   leg->AddEntry(hdzmaxltr,"Monte Carlo","L");
   leg->Draw();  
   //   TLatex *t = new TLatex();
   //   t->SetTextSize(0.04);
   //   t->DrawLatex(10.0,10.0,"JPT di-jet events");
   //   t->DrawLatex(10.0,7.0,"E_{T}^{jet} > 10 GeV, |#eta^{jet}| < 2");
   c7->SaveAs("hdzmaxltr.gif");

  //=================================================== P_isol
   setTDRStyle(0,0);
   TCanvas* c8 = new TCanvas("X","Y",1);
   TLegend *leg = new TLegend(0.5,0.8,0.9,0.9,NULL,"brNDC");
   TFile* file = new TFile("datatau7TeV.root");
   leg->SetFillColor(10);
   hpisol->GetXaxis()->SetTitle("e.m. isolation (P_{isol}), GeV");
   hpisol->GetYaxis()->SetTitle("Nev");
   hpisol->SetMarkerSize(1.2);
   hpisol->SetMarkerStyle(20);
   //   hpisol->SetMaximum(500.0);
   //   hpisol->SetMinimum(0.5);
   hpisol->Draw("histPE");
   Double_t exp = hpisol->Integral();
   leg->AddEntry(hpisol,"data  ","P");

   TFile* file = new TFile("mctau7TeV.root");
   Double_t mc = hpisol->Integral();
   Double_t scale = exp/mc;
   hpisol->Scale(scale);
   hpisol->SetLineWidth(3);
   hpisol->Draw("same");
   leg->AddEntry(hpisol,"Monte Carlo","L");
   leg->Draw(); 
 
   //   TLatex *t = new TLatex();
   //   t->SetTextSize(0.04);
   //   t->DrawLatex(10.0,10.0,"JPT di-jet events");
   //   t->DrawLatex(10.0,7.0,"E_{T}^{jet} > 10 GeV, |#eta^{jet}| < 2");
   c8->SaveAs("pisol.gif");

  //=================================================== tau id vs Eta raw
   TFile* file = new TFile("datatau7TeV.root");
   TH1F *rat1 = hetarawLeadtrk->Clone();
   TH1F *rat2 = hetarawTrkisol->Clone();
   TH1F *rat3 = hetarawElrejec->Clone();   
   TH1F *rat4 = hetrawLeadtrk->Clone();   
   TH1F *rat5 = hetrawTrkisol->Clone();   
   TH1F *rat6 = hetrawElrejec->Clone();   
   //
   for(Int_t ib = 1; ib <= 5; ib++) {
     Double_t netarawLeadtrk  = hetarawLeadtrk->GetBinContent(ib);
     Double_t netarawTrkisol  = hetarawTrkisol->GetBinContent(ib);
     Double_t netarawElrejec  = hetarawElrejec->GetBinContent(ib);
     Double_t netaraw         = hetaraw->GetBinContent(ib);
     Double_t error1 = sqrt(netarawLeadtrk)/netaraw;
     Double_t error2 = sqrt(netarawTrkisol)/netaraw;     
     Double_t error3 = sqrt(netarawElrejec)/netaraw;     
     rat1->SetBinError(ib,error1);
     rat2->SetBinError(ib,error2);
     rat3->SetBinError(ib,error2);
     cout <<" netaraw = " << netaraw
	  <<" netarawLeadtrk = " << netarawLeadtrk
	  <<" netarawTrkisol = " << netarawTrkisol 
	  <<" netarawElrejec = " << netarawElrejec 
	  << endl;
   }
   cout <<" hetaraw sum = " <<  hetaraw->Integral()
	<<" netarawLeadtrk sum = " << hetarawLeadtrk->Integral()
	<<" netarawElrejec sum = " << hetarawElrejec->Integral()
	<<" netaraw sum = " << hetarawTrkisol->Integral() 
	<< endl;

   for(Int_t ib = 1; ib <= 5; ib++) {
     Double_t netrawLeadtrk  = hetrawLeadtrk->GetBinContent(ib);
     Double_t netrawTrkisol  = hetrawTrkisol->GetBinContent(ib);
     Double_t netrawElrejec  = hetrawElrejec->GetBinContent(ib);
     Double_t netraw         = hetraw->GetBinContent(ib);
     Double_t error1 = sqrt(netrawLeadtrk)/netraw;
     Double_t error2 = sqrt(netrawTrkisol)/netraw;     
     Double_t error3 = sqrt(netrawElrejec)/netraw;     
     rat4->SetBinError(ib,error1);
     rat5->SetBinError(ib,error2);
     rat6->SetBinError(ib,error2);
     cout <<" netraw = " << netraw
	  <<" netrawLeadtrk = " << netrawLeadtrk
	  <<" netrawTrkisol = " << netrawTrkisol 
	  <<" netrawElrejec = " << netrawElrejec 
	  << endl;
   }

   cout <<" hetraw sum = " <<  hetraw->Integral()
	<<" netrawLeadtrk sum = " << hetrawLeadtrk->Integral()
	<<" netrawElrejec sum = " << hetrawElrejec->Integral()
	<<" netraw sum = " << hetrawTrkisol->Integral() << endl;

   rat1->Divide(hetarawLeadtrk,hetaraw,1.,1.,"");
   rat2->Divide(hetarawTrkisol,hetaraw,1.,1.,"");
   rat3->Divide(hetarawElrejec,hetaraw,1.,1.,"");
   rat4->Divide(hetrawLeadtrk,hetraw,1.,1.,"");
   rat5->Divide(hetrawTrkisol,hetraw,1.,1.,"");
   rat6->Divide(hetrawElrejec,hetraw,1.,1.,"");

   TFile* file = new TFile("mctau7TeV.root");
   TH1F *rat10 = hetarawLeadtrk->Clone();
   TH1F *rat20 = hetarawTrkisol->Clone();
   TH1F *rat30 = hetarawElrejec->Clone();
   TH1F *rat40 = hetrawLeadtrk->Clone();   
   TH1F *rat50 = hetrawLeadtrk->Clone();   
   TH1F *rat60 = hetrawElrejec->Clone();
   rat10->Divide(hetarawLeadtrk,hetaraw,1.,1.,"");
   rat20->Divide(hetarawTrkisol,hetaraw,1.,1.,"");
   rat30->Divide(hetarawElrejec,hetaraw,1.,1.,"");
   rat40->Divide(hetrawLeadtrk,hetraw,1.,1.,"");
   rat50->Divide(hetrawTrkisol,hetraw,1.,1.,"");
   rat60->Divide(hetrawElrejec,hetraw,1.,1.,"");


   //=================================================== tau id vs Et raw
   setTDRStyle(0,1);
   TCanvas* c9 = new TCanvas("X","Y",1);
   TLegend *leg = new TLegend(0.30,0.15,0.9,0.40,NULL,"brNDC");
   leg->SetFillColor(10);
   rat4->GetXaxis()->SetTitle("p_{T}^{tcTau}, GeV");
   rat4->GetYaxis()->SetTitle("Nev");
   rat4->SetMarkerSize(1.1);
   rat4->SetMarkerStyle(24);
   rat4->SetMaximum(2.0);
   rat4->SetMinimum(0.0001);
   rat4->Draw("histPE");
   rat5->SetMarkerSize(1.2);
   rat5->SetMarkerStyle(20);
   rat5->Draw("samePE");
   //   rat6->SetMarkerSize(1.2);
   //   rat6->SetMarkerStyle(22);
   //   rat6->Draw("samePE");

   rat40->SetLineWidth(3);
   rat40->Draw("same");
   rat50->SetLineWidth(5);
   rat50->SetLineStyle(2);
   rat50->Draw("same");
   //   rat60->SetLineWidth(4);
   //   rat60->SetLineStyle(3);
   //   rat60->Draw("same");
   leg->AddEntry(rat4,"data  : find track p_{T} > 5 GeV","P");
   leg->AddEntry(rat40,"Monte Carlo: find track p_{T} > 5 GeV","L");
   leg->AddEntry(rat5,"data  : apply trk. isolation","P");
   leg->AddEntry(rat50,"Monte Carlo: apply trk. isolation","L");
   //   leg->AddEntry(rat6,"data  : electron rejection","P");
   //   leg->AddEntry(rat60,"Monte Carlo: electron rejection","L");
   leg->Draw(); 
 
   TLatex *t = new TLatex();
   t->SetTextSize(0.04);
   t->DrawLatex(20.0,1.0,"tcTau ID performance");

   c9->SaveAs("tau_vs_etraw.gif");

   setTDRStyle(0,1);
   TCanvas* c10 = new TCanvas("X","Y",1);
   TLegend *leg = new TLegend(0.3,0.15,0.9,0.40,NULL,"brNDC");
   leg->SetFillColor(10);
   rat1->GetXaxis()->SetTitle("#eta ^{tcTau}");
   rat1->GetYaxis()->SetTitle("Nev");
   rat1->SetMarkerSize(1.2);
   rat1->SetMarkerStyle(24);
   rat1->SetMaximum(2.0);
   rat1->SetMinimum(0.0001);
   rat1->Draw("histPE");

   rat2->SetMarkerSize(1.2);
   rat2->SetMarkerStyle(20);
   rat2->Draw("samePE");

   //   rat3->SetMarkerSize(1.2);
   //   rat3->SetMarkerStyle(22);
   //   rat3->Draw("samePE");

   rat10->SetLineWidth(3);
   rat10->Draw("same");
   rat20->SetLineWidth(5);
   rat20->SetLineStyle(2);
   rat20->Draw("same");
   //   rat30->SetLineWidth(4);
   //   rat30->SetLineStyle(3);
   //   rat30->Draw("same");

   leg->AddEntry(rat1,"data  : find track p_{T} > 5 GeV","P");
   leg->AddEntry(rat2,"data  : apply trk. isolation","P");
   //   leg->AddEntry(rat3,"data  : electron rejection","P");
   leg->AddEntry(rat10,"Monte Carlo: find track p_{T} > 5 GeV","L");
   leg->AddEntry(rat20,"Monte Carlo: apply trk. isolation","L");
   //   leg->AddEntry(rat30,"Monte Carlo: electron rejection","L");
   leg->Draw(); 
 
   TLatex *t = new TLatex();
   t->SetTextSize(0.04);
   t->DrawLatex(0.7,1.0,"tcTau ID performance");

   c10->SaveAs("tau_vs_etaraw.gif");
}

