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

  /*
   setTDRStyle(0,1);
   TCanvas* c0 = new TCanvas("X","Y",1);
   // data
   TFile* file = new TFile("DYDataA_29Feb.root");
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
   // MC
   TFile* file = new TFile("DYMC18novPUW.root");
   hnvtx0->SetLineStyle(1);
   hnvtx0->SetLineWidth(3);
   hnvtx0->Draw("same");
   leg->AddEntry(hnvtx0,"MC, DY#rightarrowll","L");
   leg->Draw();
   c0->SaveAs("nvtx0.png");
  */

  // stream A

  cout <<" ========================== A ============================" < endl;

   // ZY scaling factor
   setTDRStyle(0,1);
   // data
   TFile* file = new TFile("DYDataA_29Feb.root");
   TCanvas* c1 = new TCanvas("X","Y",1);
   hZY->GetXaxis()->SetTitle("Z rapidity");
   hZY->GetYaxis()->SetTitle("Nev / 0.2");

   hZY->SetMaximum(500000.);
   hZY->SetMinimum(0.5);
   hZY->SetLineStyle(1);
   hZY->SetLineWidth(3);
   hZY->SetMarkerStyle(26);
   hZY->SetMarkerSize(0.7);
   hZY->Draw("PE");
   Double_t Ndata = hZY->Integral();

   hZY2J->SetLineStyle(1);
   hZY2J->SetLineWidth(3);
   hZY2J->SetMarkerStyle(25);
   hZY2J->SetMarkerSize(0.7);
   hZY2J->Draw("samePE");

   hZY2JDeta->SetLineStyle(1);
   hZY2JDeta->SetLineWidth(3);
   hZY2JDeta->SetMarkerStyle(24);
   hZY2JDeta->SetMarkerSize(0.7);
   hZY2JDeta->Draw("samePE");

   TLegend *leg = new TLegend(0.15,0.75,0.95,0.9,NULL,"brNDC");
   leg->SetFillColor(10);
   leg->AddEntry(hZY,"Stream A, Z inclusive","P");
   leg->AddEntry(hZY2J,"Z+2jets, p_{T} > 25 GeV","P");
   leg->AddEntry(hZY2JDeta,"Z+2jets, p_{T} > 25 GeV, #Delta #eta _{j1j2} > 3.5","P");
   leg->Draw();
   // MC
   TFile* file = new TFile("DYMuonMCFall11A_29Feb.root");
   Double_t Nmc   = hZY->Integral();
   Double_t scale = Ndata/Nmc;
   cout <<" Ndata = " << Ndata <<" Nmc = " << Nmc <<" scale = " << scale << endl;
   hZY->Scale(scale);
   hZY->SetLineStyle(1);
   hZY->SetLineWidth(1);
   hZY->Draw("hist");

   hZY2J->Scale(scale);
   hZY2J->SetLineStyle(1);
   hZY2J->SetLineWidth(1);
   hZY2J->Draw("same");

   hZY2JDeta->Scale(scale);
   hZY2JDeta->SetLineStyle(1);
   hZY2JDeta->SetLineWidth(1);
   hZY2JDeta->Draw("same");
   c1->SaveAs("zyA.png");

   // Mmumu after muon selections, but before mass
   setTDRStyle(0,1);
   TCanvas* c2 = new TCanvas("X","Y",1);
   // data
   TFile* file = new TFile("DYDataA_29Feb.root");
   hM2mu0->GetXaxis()->SetTitle("di-muon mass, GeV");
   hM2mu0->GetYaxis()->SetTitle("Nev");

   hM2mu0->SetMaximum(500000.);
   hM2mu0->SetMinimum(100);
   hM2mu0->SetLineStyle(1);
   hM2mu0->SetLineWidth(3);
   hM2mu0->SetMarkerStyle(24);
   //   hM2mu0->SetMarkerSize(0.7);
   hM2mu0->Draw("PE");
   TLegend *leg = new TLegend(0.15,0.8,0.8,0.9,NULL,"brNDC");
   leg->SetFillColor(10);
   leg->AddEntry(hM2mu0,"Stream A, data after muon selections","P");
   // MC
   TFile* file = new TFile("DYMuonMCFall11A_29Feb.root");
   //   TFile* file = new TFile("DYMC15nov.root");
   hM2mu0->Scale(scale);
   hM2mu0->SetLineStyle(1);
   hM2mu0->SetLineWidth(3);
   hM2mu0->Draw("same");
   leg->AddEntry(hM2mu0,"MC, after muon selections","L");
   leg->Draw();
   c2->SaveAs("mass_mumu0A.png");

   // Deta
   setTDRStyle(0,0);
   TCanvas* c3 = new TCanvas("X","Y",1);
   // data
   TFile* file = new TFile("DYDataA_29Feb.root");
   hDeta0->GetXaxis()->SetTitle("#Delta #eta _{j1j2}");
   hDeta0->GetYaxis()->SetTitle("Nev");

   hDeta0->SetMaximum(2000.);
   hDeta0->SetLineStyle(1);
   hDeta0->SetLineWidth(3);
   hDeta0->SetMarkerStyle(24);
   hDeta0->Draw("PE");
   hDeta1->SetLineStyle(1);
   hDeta1->SetLineWidth(3);
   hDeta1->SetMarkerStyle(25);
   hDeta1->Draw("samePE");

   TLegend *leg = new TLegend(0.15,0.75,0.9,0.9,NULL,"brNDC");
   leg->SetFillColor(10);
   leg->AddEntry(hDeta0,"Stream A, data: two jets p_{T}>25 GeV, |#eta|<4.7","P");
   leg->AddEntry(hDeta1,"Stream A, data: two jets p_{T}>25 GeV, |#eta|<4.7, #eta _{j1}#eta _{j2}<0 ","P");
   // MC
   TFile* file = new TFile("DYMuonMCFall11A_29Feb.root");
   hDeta0->Scale(scale);
   cout <<"  Deta0 (events after two jets selection = " << hDeta0->Integral() << endl;
   hDeta0->SetLineStyle(1);
   hDeta0->SetLineWidth(3);
   hDeta0->Draw("same");
   hDeta1->Scale(scale);
   hDeta1->SetLineStyle(3);
   hDeta1->SetLineWidth(3);
   hDeta1->Draw("same");
   leg->AddEntry(hDeta0,"MC, DY#rightarrowll","L");
   leg->AddEntry(hDeta1,"MC, DY#rightarrowll","L");
   leg->Draw();
   c3->SaveAs("detaj1j2A.png");

   // Mjj after Deta and CJV cuts
   setTDRStyle(0,1);
   TCanvas* c4 = new TCanvas("X","Y",1);
   // data
   TFile* file = new TFile("DYDataA_29Feb.root");
   hMjj->GetXaxis()->SetTitle("M_{j1j2}, GeV");
   hMjj->GetYaxis()->SetTitle("Nev");

   hMjj->SetMaximum(2000.);
   hMjj->SetMinimum(0.5);
   hMjj->SetLineStyle(1);
   hMjj->SetLineWidth(3);
   hMjj->SetMarkerStyle(24);
   //   hMjj->SetMarkerSize(0.7);
   hMjj->Draw("PE");
   TLegend *leg = new TLegend(0.15,0.8,0.9,0.9,NULL,"brNDC");
   leg->SetFillColor(10);
   leg->AddEntry(hMjj,"Stream A, two jets p_{T}>25 GeV, |#eta|<4.7, #eta _{j1}#eta _{j2}<0, #Delta#eta>3.5, CJV ","P");
   cout <<" " << endl;
   cout <<"  ->data Z peak = " << hZY->Integral() << endl; 
   cout <<"  ->data two jet selection = " << hZY2J->Integral() << endl; 
   cout <<"  ->data two jet selection, eta1 x eta2<0, Detaj1j2 > 3.5 = " << hZY2JDeta->Integral() << endl; 
   cout <<"  ->data two jet selection, eta1 x eta2<0, Detaj1j2 > 3.5, CJV = " << hZY2JDetaCJV->Integral() << endl; 
   cout <<"  ->data two jet selection, eta1 x eta2<0, Detaj1j2 > 3.5, CJV, Mjj > 700, CJV = " << hZY2JDetaCJVMjj->Integral() << endl; 

   // MC
   TFile* file = new TFile("DYMuonMCFall11A_29Feb.root");
   hMjj->Scale(scale);
   hMjj->SetLineStyle(1);
   hMjj->SetLineWidth(3);
   hMjj->Draw("same");
   leg->AddEntry(hMjj,"MC, DY#rightarrowll","L");
   leg->Draw();

   hZY2J->Scale(scale);   
   hZY2JDeta->Scale(scale);   
   hZY2JDetaCJV->Scale(scale);   
   hZY2JDetaCJVMjj->Scale(scale);   
   cout <<" " << endl;
   cout <<"  ->N MC predicted at Z peak = " << hZY->Integral() << endl; 
   cout <<"  ->N MC predicted after two jet selection = " << hZY2J->Integral() << endl; 
   cout <<"  ->N MC predicted after two jet selection, eta1 x eta2<0, Detaj1j2 > 3.5 = " << hZY2JDeta->Integral() << endl; 
   cout <<"  ->N MC predicted after two jet selection, eta1 x eta2<0, Detaj1j2 > 3.5, CJV = " << hZY2JDetaCJV->Integral() << endl; 
   cout <<"  ->N MC predicted after two jet selection, eta1 x eta2<0, Detaj1j2 > 3.5, CJV, Mjj > 700, CJV = " << hZY2JDetaCJVMjj->Integral() << endl; 
   c4->SaveAs("mass_jjA.png");


}
