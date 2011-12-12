#define dymadgraph_cxx
#include "dymadgraph.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void dymadgraph::setTDRStyle(Int_t xlog, Int_t ylog, Int_t zlog) {

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

void dymadgraph::Loop()
{
//   In a ROOT session, you can do:
//      Root > .L dymadgraph.C
//      Root > dymadgraph t
//      Root > t.GetEntry(12); // Fill t data members with entry number 12
//      Root > t.Show();       // Show values of entry 12
//      Root > t.Show(16);     // Read and show values of entry 16
//      Root > t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   TH1F * hpTZ         = new TH1F( "hpTZ", "pTZ", 30, 0., 150.);
   TH1F * hpTZ1J       = new TH1F( "hpTZ1J", "pTZ1J", 30, 0., 150.);
   TH1F * hpTZ2J       = new TH1F( "hpTZ2J", "pTZ2J", 30, 0., 150.);
   TH1F * hpTZ2JDeta   = new TH1F( "hpTZ2JDeta", "pTZ2JDeta", 30, 0., 150.);

   TH1F * hyZ         = new TH1F( "hyZ", "yZ", 20, 0., 4.);
   TH1F * hyZ1J       = new TH1F( "hyZ1J", "yZ1J", 20, 0., 4.);
   TH1F * hyZ2J       = new TH1F( "hyZ2J", "yZ2J", 20, 0., 4.);
   TH1F * hyZ2JDeta   = new TH1F( "hyZ2JDeta", "yZ2JDeta", 20, 0., 4.);

   TH1F * hnjets      = new TH1F( "hnjets", "njets", 5, 0., 5.);
   TH1F * hDetaJJ     = new TH1F( "hDetaJJ", "DetaJJ", 5, 0., 5.);
   TH1F * hMjj        = new TH1F( "hMjj", "Mjj", 20, 0., 1000.);

   Long64_t nbytes = 0, nb = 0;
   Int_t nev = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;

      // muon acceptance

      if( (*PtMu)[0] < 20 || (*PtMu)[1] < 20 ) {continue;}
      if( fabs((*EtaMu)[0]) > 2.4 || fabs((*EtaMu)[1]) > 2.4 ) {continue;}

      Int_t njets = pTJ->size();
      nev++;
      //      cout <<" event = " << nev << " njets = " << njets <<" weight = " << event_w << endl;
      hnjets->Fill(1.*njets,event_w);
      // Z inclusive
      hpTZ->Fill(pTZ,event_w);
      hyZ->Fill(fabs(yZ),event_w);
      // Z + >=1 jet
      if(njets != 0 ) {
	hpTZ1J->Fill(pTZ,event_w);
	hyZ1J->Fill(fabs(yZ),event_w);
      }
      if(njets >= 2 ) {
	if( (*pTJ)[0] > 25. && (*pTJ)[1] > 25.0 ) {
	  hpTZ2J->Fill(pTZ,event_w);
	  hyZ2J->Fill(fabs(yZ),event_w);
	  Double_t DetaJJ = fabs((*EtaJ)[0]-(*EtaJ)[1]);
	  hDetaJJ->Fill(DetaJJ,event_w);
	  // Mjj
	  Double_t PJ1x = (*pTJ)[0] * cos((*PhiJ)[0]); 
	  Double_t PJ1y = (*pTJ)[0] * sin((*PhiJ)[0]);
	  Double_t Eta = (*EtaJ)[0];
	  Double_t theta = 2. * atan(exp(-Eta));
	  Double_t PJ1z = (*pTJ)[0] / tan(theta);
	  Double_t EJ1  = (*pTJ)[0] / sin(theta);
	
	  Double_t PJ2x = (*pTJ)[1] * cos((*PhiJ)[1]); 
	  Double_t PJ2y = (*pTJ)[1] * sin((*PhiJ)[1]);
	  Eta = (*EtaJ)[1];
	  theta = 2. * atan(exp(-Eta));
	  Double_t PJ2z = (*pTJ)[1] / tan(theta);
	  Double_t EJ2  = (*pTJ)[1] / sin(theta);
	
	  Double_t Mj1j2 = sqrt( (EJ1+EJ2)*(EJ1+EJ2) - (PJ1x+PJ2x)*(PJ1x+PJ2x) - (PJ1y+PJ2y)*(PJ1y+PJ2y) - (PJ1z+PJ2z)*(PJ1z+PJ2z) ); 
	  if(DetaJJ > 3.5) {
	    hpTZ2JDeta->Fill(pTZ,event_w);
	    hyZ2JDeta->Fill(fabs(yZ),event_w);
	    hMjj->Fill(Mj1j2,event_w);
	    
	  }
	}
      }
      
      /*
	if( ( (*EtJPT)[0] < 25.0 ) || 
	( (*EtJPT)[1] < 25.0 ) || 
	( fabs((*EtaJPT)[0]) > 4.7) || 
	  ( fabs((*EtaJPT)[1]) > 4.7) ) {continue;}
      */
      
   }

   TFile efile("DYsherpa_histos.root","recreate");

   hpTZ->Write();
   hpTZ1J->Write();
   hpTZ2J->Write();
   hpTZ2JDeta->Write();

   hyZ->Write();       
   hyZ1J->Write();     
   hyZ2J->Write();     
   hyZ2JDeta->Write(); 

   hnjets->Write();    
   hDetaJJ->Write();   
   hMjj->Write();      

   efile.Close();

   setTDRStyle(0,1,0);
   TCanvas* c1 = new TCanvas("X","Y",1);
   hpTZ->GetXaxis()->SetTitle("p_{T}^{Z}, GeV");
   hpTZ->GetYaxis()->SetTitle("");
   Double_t scale = 1./ hpTZ->Integral();
   hpTZ->Scale(scale);
   hpTZ->SetMaximum(1.0);
   hpTZ->SetMinimum(0.001);
   hpTZ->SetLineStyle(1);
   hpTZ->SetLineWidth(1);
   hpTZ->Draw("hist");

   scale = 1./ hpTZ1J->Integral();
   hpTZ1J->Scale(scale);
   hpTZ1J->SetLineStyle(2);
   hpTZ1J->SetLineWidth(3);
   hpTZ1J->Draw("same");

   scale = 1./ hpTZ2J->Integral();
   hpTZ2J->Scale(scale);
   hpTZ2J->SetLineStyle(3);
   hpTZ2J->SetLineWidth(3);
   hpTZ2J->Draw("same");


   scale = 1./ hpTZ2JDeta->Integral();
   hpTZ2JDeta->Scale(scale);
   hpTZ2JDeta->SetLineStyle(1);
   hpTZ2JDeta->SetLineWidth(3);
   hpTZ2JDeta->Draw("same");

   TLegend *leg = new TLegend(0.35,0.7,0.9,0.9,NULL,"brNDC");
   leg->SetFillColor(10);
   /*
   leg->AddEntry(hpTZ,"MadGraph Z inclusive","L");
   leg->AddEntry(hpTZ1J,"MadGraph Z+#geq 1J","L");
   leg->AddEntry(hpTZ2J,"MagGraph Z+#geq 2J","L");
   */
   leg->AddEntry(hpTZ,"MadGraph Z inclusive","L");
   leg->AddEntry(hpTZ1J,"MadGraph Z+#geq 1J","L");
   leg->AddEntry(hpTZ2J,"MadGraph Z+#geq 2J","L");
   leg->AddEntry(hpTZ2JDeta,"MadGraph Z+#geq 2J, #Delta #eta _{J1J2} > 3.5","L");
   leg->Draw();
   c1->SaveAs("pTZ_madgraph.gif");

   setTDRStyle(0,0,0);
   TCanvas* c2 = new TCanvas("X","Y",1);
   hyZ->GetXaxis()->SetTitle("y^{Z}");
   hyZ->GetYaxis()->SetTitle("");
   Double_t scale = 1./ hyZ->Integral();
   hyZ->Scale(scale);
   hyZ->SetMaximum(0.2);
   //   hyZ->SetMinimum(0.01);
   hyZ1J->SetLineStyle(1);
   hyZ1J->SetLineWidth(1);
   hyZ->Draw("hist");

   scale = 1./ hyZ1J->Integral();
   hyZ1J->Scale(scale);
   hyZ1J->SetLineStyle(2);
   hyZ1J->SetLineWidth(3);
   hyZ1J->Draw("same");

   scale = 1./ hyZ2J->Integral();
   hyZ2J->Scale(scale);
   hyZ2J->SetLineStyle(3);
   hyZ2J->SetLineWidth(3);
   hyZ2J->Draw("same");

   scale = 1./ hyZ2JDeta->Integral();
   hyZ2JDeta->Scale(scale);
   hyZ2JDeta->SetLineStyle(4);
   hyZ2JDeta->SetLineWidth(3);
   hyZ2JDeta->Draw("same");

   TLegend *leg = new TLegend(0.35,0.70,0.9,0.90,NULL,"brNDC");
   leg->SetFillColor(10);
   /*
   leg->AddEntry(hyZ,"MadGraph Z inclusive","L");
   leg->AddEntry(hyZ1J,"MadGraph Z+#geq 1J","L");
   leg->AddEntry(hyZ2J,"MagGraph Z+#geq 2J","L");
   */
   leg->AddEntry(hyZ,"MadGraph Z inclusive","L");
   leg->AddEntry(hyZ1J,"MadGraph Z+#geq 1J","L");
   leg->AddEntry(hyZ2J,"MadGraph Z+#geq 2J","L");
   leg->AddEntry(hyZ2JDeta,"MadGraph Z+#geq 2J, #Delta #eta > 3.5","L");
   leg->Draw();
   c2->SaveAs("yZ_madgraph.gif");

   /*
   setTDRStyle(0,1,0);
   TCanvas* c3 = new TCanvas("X","Y",1);
   hnjets->GetXaxis()->SetTitle("N jets p_{T}>20 GeV, |#eta|<4.7");
   hnjets->GetYaxis()->SetTitle("");
   hnjets->SetLineWidth(3);
   scale = 1./ hnjets->Integral();
   hnjets->Scale(scale);
   hnjets->SetMaximum(2.);
   hnjets->SetMinimum(0.01);
   hnjets->Draw("hist");
   TLegend *leg = new TLegend(0.35,0.8,0.9,0.9,NULL,"brNDC");
   leg->SetFillColor(10);
   leg->AddEntry(hnjets,"MadGraph, Z+jets","L");
   leg->Draw();
   c3->SaveAs("njets_madgrapg.gif");

   setTDRStyle(0,0,0);
   TCanvas* c4 = new TCanvas("X","Y",1);
   hDetaJJ->GetXaxis()->SetTitle("#Delta #eta _{j1j2}");
   hDetaJJ->GetYaxis()->SetTitle("");
   hDetaJJ->SetLineWidth(3);
   scale = 1./ hDetaJJ->Integral();
   hDetaJJ->Scale(scale);
   hDetaJJ->SetMaximum(0.2);
   //   hDetaJJ->SetMinimum(1.0);
   hDetaJJ->Draw("hist");
   TLegend *leg = new TLegend(0.35,0.8,0.9,0.9,NULL,"brNDC");
   leg->SetFillColor(10);
   leg->AddEntry(hDetaJJ,"MadGraph, Z+jets","L");
   leg->Draw();
   c4->SaveAs("DetaJJ_madgrapg.gif");

   setTDRStyle(0,1,0);
   TCanvas* c5 = new TCanvas("X","Y",1);
   hMjj->GetXaxis()->SetTitle("M_{j1j2}, GeV");
   hMjj->GetYaxis()->SetTitle("");
   hMjj->SetLineWidth(3);
   scale = 1./ hMjj->Integral();
   hMjj->Scale(scale);
   hMjj->SetMaximum(1.0);
   hMjj->SetMinimum(0.001);
   hMjj->Draw("hist");
   TLegend *leg = new TLegend(0.35,0.8,0.9,0.9,NULL,"brNDC");
   leg->SetFillColor(10);
   leg->AddEntry(hMjj,"MadGraph, Z+jets","L");
   leg->Draw();
   c5->SaveAs("Mjj_madgrapg.gif");
   */
}
