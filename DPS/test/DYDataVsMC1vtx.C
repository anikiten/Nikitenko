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

   /*
   TCanvas* c0 = new TCanvas("X","Y",1);
   TFile* file = new TFile("DYData18nov.root");
   hnvtx0->GetXaxis()->SetTitle("N reco vertices");
   hnvtx0->GetYaxis()->SetTitle("");
   hnvtx0->SetLineStyle(1);
   hnvtx0->SetLineWidth(3);
   hnvtx0->SetMarkerStyle(24);
   hnvtx0->SetMarkerSize(1.0);
   hnvtx0->SetMaximum(200000.);
   hnvtx0->SetMinimum(0.5);
   hnvtx0->Draw("PE");
   TLegend *leg = new TLegend(0.35,0.75,0.9,0.85,NULL,"brNDC");
   leg->SetFillColor(10);
   leg->AddEntry(hnvtx0,"data: p_{T}^{#mu}> 20 GeV, |#eta|<2.4","P");
   cout <<"  Vertexing: N data = " << hnvtx0->Integral() << endl;

   TFile* file = new TFile("DYMC18novPUW.root");
   hnvtx0->SetLineStyle(1);
   hnvtx0->SetLineWidth(3);
   hnvtx0->Draw("same");
   leg->AddEntry(hnvtx0,"MC, DY#rightarrowll","L");
   leg->Draw();
   cout <<"  Vertexing: N MC = " << hnvtx0->Integral() << endl;
   c0->SaveAs("nvtx0.png");
   */

   // YZ
   setTDRStyle(0,1);
   TFile* file = new TFile("Run2011A_08Nov_23Feb.root");
   TCanvas* c1 = new TCanvas("X","Y",1);
   //   TAxis* xaxis = hprEH11x5->GetXaxis();

   hZY->GetXaxis()->SetTitle("Z rapidity");
   hZY->GetYaxis()->SetTitle("Nev / 0.2");

   hZY->SetMaximum(100000.);
   hZY->SetMinimum(0.5);
   hZY->SetLineStyle(1);
   hZY->SetLineWidth(3);
   hZY->SetMarkerStyle(26);
   hZY->SetMarkerSize(0.7);
   hZY->Draw("PE");
   Double_t Ndata = hZY->Integral();

   hZY1J->SetLineStyle(1);
   hZY1J->SetLineWidth(3);
   hZY1J->SetMarkerStyle(24);
   hZY1J->SetMarkerSize(0.7);
   hZY1J->Draw("samePE");

   cout <<" N data with >= 1 jet = " << hZY1J->Integral() << endl;

   hZY2J->SetLineStyle(1);
   hZY2J->SetLineWidth(3);
   hZY2J->SetMarkerStyle(25);
   hZY2J->SetMarkerSize(0.7);
   hZY2J->Draw("samePE");

   cout <<" N data with >= 2 jet = " << hZY2J->Integral() << endl;

   TLegend *leg = new TLegend(0.3,0.75,0.7,0.9,NULL,"brNDC");
   leg->SetFillColor(10);
   leg->AddEntry(hZY,"Z inclusive","P");
   leg->AddEntry(hZY1J,"Z+#geq 1jets","P");
   leg->AddEntry(hZY2J,"Z+#geq 2jets","P");
   leg->Draw();

   TFile* file = new TFile("DiMuonMCFall11_23Feb.root");

   Double_t Nmc   = hZY->Integral();
   Double_t scale = Ndata/Nmc;

   cout <<" Ndata = " << Ndata <<" Nmc = " << Nmc <<" scale = " << scale << endl;

   hZY->Scale(scale);
   hZY->SetLineStyle(1);
   hZY->SetLineWidth(1);
   hZY->Draw("same");

   hZY1J->Scale(scale);
   hZY1J->SetLineStyle(1);
   hZY1J->SetLineWidth(2);
   hZY1J->Draw("same");

   cout <<" N MC with >= 1 jet = " << hZY1J->Integral() << endl;

   hZY2J->Scale(scale);
   hZY2J->SetLineStyle(1);
   hZY2J->SetLineWidth(3);
   hZY2J->Draw("same");

   cout <<" N MC with >= 2 jet = " << hZY2J->Integral() << endl;

   c1->SaveAs("zy1vxtA.png");

   /*
   // pTZ
   setTDRStyle(0,1);
   TFile* file = new TFile("Run2011A_08Nov_23Feb.root");
   TCanvas* c2 = new TCanvas("X","Y",1);
   hPtZ->GetXaxis()->SetTitle("p_{T} di-muon, GeV");
   hPtZ->GetYaxis()->SetTitle("Nev / 5 GeV");

   hPtZ->SetMaximum(40000.);
   hPtZ->SetMinimum(0.5);
   hPtZ->SetLineStyle(1);
   hPtZ->SetLineWidth(3);
   hPtZ->SetMarkerStyle(26);
   hPtZ->SetMarkerSize(0.7);
   hPtZ->Draw("PE");

   hPtZ1J->SetLineStyle(1);
   hPtZ1J->SetLineWidth(3);
   hPtZ1J->SetMarkerStyle(24);
   hPtZ1J->SetMarkerSize(0.7);
   hPtZ1J->Draw("samePE");

   hPtZ2J->SetLineStyle(1);
   hPtZ2J->SetLineWidth(3);
   hPtZ2J->SetMarkerStyle(25);
   hPtZ2J->SetMarkerSize(0.7);
   hPtZ2J->Draw("samePE");


   TLegend *leg = new TLegend(0.4,0.75,0.8,0.9,NULL,"brNDC");
   leg->SetFillColor(10);
   leg->AddEntry(hPtZ,"Z inclusive","P");
   leg->AddEntry(hPtZ1J,"Z+#geq 1jets","P");
   leg->AddEntry(hPtZ2J,"Z+#geq 2jets","P");
   leg->Draw();

   TFile* file = new TFile("DiMuonMCFall11_23Feb.root");

   hPtZ->Scale(scale);
   hPtZ->SetLineStyle(1);
   hPtZ->SetLineWidth(1);
   hPtZ->Draw("same");

   hPtZ1J->Scale(scale);
   hPtZ1J->SetLineStyle(1);
   hPtZ1J->SetLineWidth(2);
   hPtZ1J->Draw("same");

   hPtZ2J->Scale(scale);
   hPtZ2J->SetLineStyle(1);
   hPtZ2J->SetLineWidth(3);
   hPtZ2J->Draw("same");

   c2->SaveAs("ptz1vtxA.png");

   // Njets
   setTDRStyle(0,1);
   TFile* file = new TFile("Run2011A_08Nov_23Feb.root");
   TCanvas* c3 = new TCanvas("X","Y",1);

   hNjets->GetXaxis()->SetTitle("jet multiplicity");
   hNjets->GetYaxis()->SetTitle("Nev");

   hNjets->SetMaximum(100000.);
   hNjets->SetMinimum(0.5);
   hNjets->SetLineStyle(1);
   hNjets->SetLineWidth(3);
   hNjets->SetMarkerStyle(24);
   hNjets->SetMarkerSize(1.0);
   hNjets->Draw("PE");

   TLegend *leg = new TLegend(0.5,0.75,0.9,0.9,NULL,"brNDC");
   leg->SetFillColor(10);
   leg->AddEntry(hNjets,"data","P");
   leg->Draw();

   TFile* file = new TFile("DiMuonMCFall11_23Feb.root");

   hNjets->Scale(scale);
   hNjets->SetLineStyle(1);
   hNjets->SetLineWidth(2);
   hNjets->Draw("same");
   leg->AddEntry(hNjets,"simulation","L");
   leg->Draw();

   c3->SaveAs("njets1vtxA.png");

   // pT jets for Nj >= 1
   setTDRStyle(0,1);
   TFile* file = new TFile("Run2011A_08Nov_23Feb.root");
   TCanvas* c4 = new TCanvas("X","Y",1);

   hPtJ->GetXaxis()->SetTitle("p_{T} jet, GeV");
   hPtJ->GetYaxis()->SetTitle("Nev / 5 GeV");

   hPtJ->SetMaximum(10000.);
   hPtJ->SetMinimum(2.0);
   hPtJ->SetLineStyle(1);
   hPtJ->SetLineWidth(3);
   hPtJ->SetMarkerStyle(24);
   hPtJ->SetMarkerSize(1.0);
   hPtJ->Draw("PE");

   TLegend *leg = new TLegend(0.5,0.75,0.9,0.9,NULL,"brNDC");
   leg->SetFillColor(10);
   leg->AddEntry(hPtJ,"data, #geq1jet","P");
   leg->Draw();

   TFile* file = new TFile("DiMuonMCFall11_23Feb.root");

   hPtJ->Scale(scale);
   hPtJ->SetLineStyle(1);
   hPtJ->SetLineWidth(2);
   hPtJ->Draw("same");
   leg->AddEntry(hPtJ,"simulation, #geq1j","L");
   leg->Draw();

   c4->SaveAs("ptj1vtxA.png");
   */

   // eta jets for Nj >= 1
   setTDRStyle(0,0);
   TFile* file = new TFile("Run2011A_08Nov_23Feb.root");
   TCanvas* c5 = new TCanvas("X","Y",1);

   TH1F *hEtaJData = (TH1F*)hEtaJ->Clone();
   TH1F *hEtaJDiv  = (TH1F*)hEtaJ->Clone();
   TH1F *hEtaJDivmjes  = (TH1F*)hEtaJ->Clone();
   TH1F *hEtaJDivpjes  = (TH1F*)hEtaJ->Clone();

   TPad *pad1 = new TPad("plotpad", "plotpad",0.,0.2,1.,1.);
   pad1->SetPad(0, 0.2, 1.0, 1.0);
   pad1->SetFillStyle(0);
   pad1->SetTopMargin(0.06);
   pad1->SetRightMargin(0.04);
   pad1->SetLeftMargin(0.16);

   TPad *pad2 = new TPad("ratiopad", "ratiopad",0.,0.,1.,1.);
   pad2->SetPad(0.0, 0.0, 1.0, 0.2+0.12);
   pad2->SetFillStyle(4000);
   pad2->SetBottomMargin(0.3);
   pad2->SetRightMargin(0.04);
   pad2->SetLeftMargin(0.16);

   pad3 = new TPad("pad3","pad3", 0.0, 0.0, 1.0, 1.0, 0, 0, 0);
   pad3->SetPad(0.065, 0.285, 0.155, 0.33);

   pad1->Draw();
   pad1->Update();
   pad2->Draw();
   pad2->Update(); 
  
   pad3->Draw();
   pad2->Draw();


   pad1->cd();
   //   hEtaJData->GetYaxis()->SetTitleFont(42);
   //   hEtaJData->GetYaxis()->SetLabelFont(42);
   hEtaJData->GetYaxis()->SetTitleOffset(1.5);
   hEtaJData->GetYaxis()->SetTitle("Nev / 0.1");
   hEtaJData->SetMaximum(1200.);
   hEtaJData->SetLineStyle(1);
   hEtaJData->SetLineWidth(2);
   hEtaJData->SetMarkerStyle(24);
   hEtaJData->SetMarkerSize(0.7);
   hEtaJData->Draw("PE");
   hEtaJData->GetXaxis()->SetTitle("");
   hEtaJData->GetXaxis()->SetLabelSize(2.0); //??? it works
   

   TLegend *leg = new TLegend(0.3,0.70,0.9,0.90,NULL,"brNDC");
   leg->SetFillColor(10);
   leg->AddEntry(hEtaJData,"data, #geq1jet, Nvxt < 3","P");
   leg->Draw();

   TFile* file = new TFile("DiMuonMCFall11_23Feb.root");
   TH1F *hEtaJMC = (TH1F*)hEtaJ->Clone();
   hEtaJMC->Scale(scale);
   hEtaJMC->SetLineStyle(1);
   hEtaJMC->SetLineWidth(3);
   hEtaJMC->Draw("samehist");
   leg->AddEntry(hEtaJMC,"simulation","L");

   TFile* file = new TFile("DYhistosMCA1vtx+jes.root");
   Nmc   = hZY->Integral();
   Double_t scalepjes = Ndata/Nmc;
   TH1F *hEtaJMCpjes = (TH1F*)hEtaJ->Clone();
   hZY1J->Scale(scalepjes);
   hZY2J->Scale(scalepjes);
   hEtaJMCpjes->Scale(scalepjes); 
   hEtaJMCpjes->SetLineStyle(2);
   hEtaJMCpjes->SetLineWidth(2);
   hEtaJMCpjes->Draw("samehist");
   leg->AddEntry(hEtaJMCpjes,"simulation, +1 #sigma JES","L");
   cout <<" " << endl;
   cout <<" MC with >= 1 jets + 1sigma JES = " << hZY1J->Integral() << endl;
   cout <<" MC with >= 2 jets + 1sigma JES = " << hZY2J->Integral() << endl;

   TFile* file = new TFile("DYhistosMCA1vtx-jes.root");
   Nmc   = hZY->Integral();
   Double_t scalemjes = Ndata/Nmc;
   TH1F *hEtaJMCmjes = (TH1F*)hEtaJ->Clone();
   hZY1J->Scale(scalemjes);
   hZY2J->Scale(scalemjes);
   hEtaJMCmjes->Scale(scalemjes); 
   hEtaJMCmjes->SetLineStyle(3);
   hEtaJMCmjes->SetLineWidth(2);
   hEtaJMCmjes->Draw("samehist");
   leg->AddEntry(hEtaJMCmjes,"simulation, -1 #sigma JES","L");
   cout <<" " << endl;
   cout <<" MC with >= 1 jets - 1sigma JES = " << hZY1J->Integral() << endl;
   cout <<" MC with >= 2 jets - 1sigma JES = " << hZY2J->Integral() << endl;

   leg->Draw();
   //
   hEtaJData->Sumw2();
   Int_t nbins = hEtaJMC->GetNbinsX();
   for (Int_t ib = 1; ib <= nbins; ib++) {
     hEtaJMC->SetBinError(ib,0.1);
   }

   Int_t nbins = hEtaJMCmjes->GetNbinsX();
   for (Int_t ib = 1; ib <= nbins; ib++) {
     hEtaJMCmjes->SetBinError(ib,0.1);
     hEtaJMCpjes->SetBinError(ib,0.1);
   }

   hEtaJDiv->Divide(hEtaJData,hEtaJMC,1.,1.,"");
   hEtaJDivmjes->Divide(hEtaJData,hEtaJMCmjes,1.,1.,"");
   hEtaJDivpjes->Divide(hEtaJData,hEtaJMCpjes,1.,1.,"");
   pad2->cd();
   hEtaJDiv->SetMarkerStyle(24);
   hEtaJDiv->SetMarkerSize(0.7);
   hEtaJDiv->SetMaximum(2.0);
   hEtaJDiv->SetMinimum(0.0);
   hEtaJDiv->SetLineStyle(1);
   hEtaJDiv->SetLineWidth(2);
   hEtaJDiv->Draw("PE");

   hEtaJDivmjes->SetLineStyle(3);
   hEtaJDivmjes->SetLineWidth(2);
   hEtaJDivmjes->Draw("samehist");

   hEtaJDivpjes->SetLineStyle(2);
   hEtaJDivpjes->SetLineWidth(2);
   hEtaJDivpjes->Draw("samehist");

   //
   Double_t titleSize = hEtaJDiv->GetXaxis()->GetTitleSize(); 
   double labelSize = hEtaJDiv->GetXaxis()->GetLabelSize();
   double titleOffset = hEtaJDiv->GetXaxis()->GetTitleOffset();
   hEtaJDiv->GetXaxis()->SetTitleSize(titleSize*3.0);
   hEtaJDiv->GetXaxis()->SetTitle("#eta jet");
   hEtaJDiv->GetXaxis()->SetLabelSize(labelSize*2.5);
   hEtaJDiv->GetXaxis()->SetTitleOffset(titleOffset*0.8);
   hEtaJDiv->GetYaxis()->SetTitleSize(titleSize*3.0);
   hEtaJDiv->GetYaxis()->SetTitle("Data/MC");
   hEtaJDiv->GetYaxis()->SetLabelSize(labelSize*1.7);
   hEtaJDiv->GetYaxis()->SetTitleOffset(titleOffset*0.45);  
   line = new TLine(-5.,1.,5.,1.);
   line->Draw("same");

   c5->SaveAs("etaj1vtxA.png");

   /*
   // Detaj1j2 jets for Nj >= 2
   setTDRStyle(0,0);
   TFile* file = new TFile("Run2011A_08Nov_23Feb.root");
   TCanvas* c6 = new TCanvas("X","Y",1);

   hDeta0->GetXaxis()->SetTitle("#Delta#eta_{j1j2}");
   hDeta0->GetYaxis()->SetTitle("Nev / 0.2");

   //   hDeta0->SetMaximum(120.);
   //   hDeta0->SetMinimum(2.0);
   hDeta0->SetLineStyle(1);
   hDeta0->SetLineWidth(1);
   hDeta0->SetMarkerStyle(24);
   hDeta0->SetMarkerSize(0.7);
   hDeta0->Draw("PE");

   TLegend *leg = new TLegend(0.5,0.8,0.9,0.95,NULL,"brNDC");
   leg->SetFillColor(10);
   leg->AddEntry(hDeta0,"data, #geq2jet","P");
   leg->Draw();

   TFile* file = new TFile("DiMuonMCFall11_23Feb.root");

   hDeta0->Scale(scale);
   hDeta0->SetLineStyle(1);
   hDeta0->SetLineWidth(2);
   hDeta0->Draw("same");
   leg->AddEntry(hDeta0,"simulation, #geq2j","L");
   leg->Draw();

   c6->SaveAs("deta01vtxA.png");

   // Detaj1j2 jets for Nj >= 2
   setTDRStyle(0,1);
   TFile* file = new TFile("Run2011A_08Nov_23Feb.root");
   TCanvas* c7 = new TCanvas("X","Y",1);

   hMjjnoVBF->GetXaxis()->SetTitle("M_{j1j2}, GeV");
   hMjjnoVBF->GetYaxis()->SetTitle("Nev / 50 GeV");

   hMjjnoVBF->SetMaximum(5000.);
   hMjjnoVBF->SetMinimum(0.1);
   hMjjnoVBF->SetLineStyle(1);
   hMjjnoVBF->SetLineWidth(2);
   hMjjnoVBF->SetMarkerStyle(24);
   hMjjnoVBF->SetMarkerSize(0.7);
   hMjjnoVBF->Draw("PE");

   TLegend *leg = new TLegend(0.5,0.8,0.9,0.95,NULL,"brNDC");
   leg->SetFillColor(10);
   leg->AddEntry(hMjjnoVBF,"data, #geq2jet","P");
   leg->Draw();

   TFile* file = new TFile("DiMuonMCFall11_23Feb.root");

   hMjjnoVBF->Scale(scale);
   hMjjnoVBF->SetLineStyle(1);
   hMjjnoVBF->SetLineWidth(2);
   hMjjnoVBF->Draw("same");
   leg->AddEntry(hMjjnoVBF,"simulation, #geq2j","L");
   leg->Draw();

   c7->SaveAs("mjjnovbf1vtxA.png");
   */

}
