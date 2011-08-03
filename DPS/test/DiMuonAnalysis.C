#define DiMuonAnalysis_cxx
#include "DiMuonAnalysis.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void DiMuonAnalysis::setTDRStyle(Int_t xlog, Int_t ylog) {

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

Double_t DiMuonAnalysis::deltaPhi(Double_t phi1, Double_t phi2)
{
  Double_t pi = 3.1415927;
  Double_t dphi = fabs(phi1 - phi2);
  if(dphi >= pi) dphi = 2. * pi - dphi; 
  return dphi;
}

Double_t DiMuonAnalysis::deltaEta(Double_t eta1, Double_t eta2)
{
  Double_t deta = fabs(eta1 - eta2);
  return deta;
}

Double_t DiMuonAnalysis::deltaR(Double_t eta1, Double_t phi1, Double_t eta2, Double_t phi2)
{
  Double_t deta = deltaEta(eta1, eta2);
  Double_t dphi = deltaPhi(phi1, phi2);
  Double_t dr = sqrt(deta*deta + dphi*dphi);
  return dr;
}

void DiMuonAnalysis::Loop()
{
//   In a ROOT session, you can do:
//      Root > .L DiMuonAnalysis.C
//      Root > DiMuonAnalysis t
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

   TH1F * hM2mu   = new TH1F( "hM2mu", "M2mu", 60, 20., 140.);
   TH1F * hPtZ    = new TH1F( "hPtZ", "PtZ", 25, 0., 100.);

   TH1F * hEtJ    = new TH1F( "hEtJ", "EtJ", 30, 0., 150.);
   TH1F * hEtaJ   = new TH1F( "hEtaJ", "EtaJ", 24, -2.4, 2.4);
   TH1F * hNvtx   = new TH1F( "hNvtx", "Nvtx", 16, 0., 16.);
   TH1F * hNjets  = new TH1F( "hNjets", "Njets", 6, 0., 6.);

   TH1F * hbeta1  = new TH1F( "hbeta1", "beta1", 25, 0., 1.0);
   TH1F * hbeta2  = new TH1F( "hbeta2", "beta2", 25, 0., 1.0);
   TH1F * hbeta3  = new TH1F( "hbeta3", "beta3", 25, 0., 1.0);

   TH1F * hNvtx01   = new TH1F( "hNvtx01", "Nvtx01", 16, 0., 16.);
   TH1F * hEtJ01    = new TH1F( "hEtJ", "EtJ", 30, 0., 150.);
   TH1F * hEtaJ01   = new TH1F( "hEtaJ", "EtaJ", 24, -2.4, 2.4);
   TH1F * hNjets01  = new TH1F( "hNjets", "Njets", 6, 0., 6.);
   TH1F * hPtZ01    = new TH1F( "hPtZ01", "PtZ01", 25, 0., 100.);
   TH1F * hPtZ0     = new TH1F( "hPtZ0", "PtZ0", 25, 0., 100.);

   TH1F * hDphiZJ   = new TH1F( "hDphiZJ", "DphiZJ", 16, 0., 3.2);
   TH1F * hDphiZJ01 = new TH1F( "hDphiZJ01", "DphiZJ01", 32, 0., 3.2);

   Long64_t nentries = fChain->GetEntriesFast();
   Long64_t nbytes = 0, nb = 0;

   Int_t nev = 0;

   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      nev++;
      Int_t ngoodjets = 0;
      Int_t nalljets = 0;
      // di muon mass
      hM2mu->Fill(mass_mumu);
      if(mass_mumu < 80. || mass_mumu > 100.) {continue;}
      Int_t smallbeta = 0;
      Int_t njets = EtJPT->size();
      Int_t nmuon = PtMu->size();
      // muons
      Double_t PtZx = 0.;
      Double_t PtZy = 0.;
      Double_t DphiZJ = 0;
      for (unsigned int j = 0; j < nmuon; j++) {
	if(j < 2) {
	  PtZx += (*PtMu)[j] * cos((*PhiMu)[j]); 
	  PtZy += (*PtMu)[j] * sin((*PhiMu)[j]); 
	}
      }
      Double_t PtZ = sqrt(PtZx*PtZx + PtZy*PtZy);
      Double_t PhiZ = atan2(PtZy, PtZx);
      // jets
      for (unsigned int i = 0; i < njets; i++) {
	Int_t muonmatch = 0;
	// remove jets from muons
	for (unsigned int j = 0; j < nmuon; j++) {
	  // DR muon-jet
	  Double_t DR = deltaR((*EtaJPT)[i], (*PhiJPT)[i], (*EtaMu)[j], (*PhiMu)[j]);
	  if(DR < 0.5) {
	    muonmatch = 1;
	  }
	}
	if(muonmatch == 0) {
	  nalljets = nalljets + 1;
	  if(fabs((*EtaJPT)[i]) < 2.0) {
	    ngoodjets = ngoodjets + 1;
	    hEtJ->Fill((*EtJPT)[i]); 
	    hEtaJ->Fill((*EtaJPT)[i]);
	    DphiZJ = deltaPhi(PhiZ, (*PhiJPT)[i]);
	    /*
	    if(run == 163301) {
	      if((*beta)[i] < 0.1) cout <<" run " << run 
					<<" event " << event 
					<<" beta = " << (*beta)[i]
					<<" etaj = " << (*EtaJPT)[i]
					<<" phij = " << (*PhiJPT)[i]
					<<" et jpt = " << (*EtJPT)[i]
					<<" ntrk = " << (*Ntrk)[i] 
					<<" nvertex = " << nvertex << endl;
	    }
	    */
	    if( (*beta)[i] < 0.1) {
	      smallbeta = 1;
	      hEtJ01->Fill((*EtJPT)[i]); 
	      hEtaJ01->Fill((*EtaJPT)[i]);
	    }
	    if(nvertex == 1 || nvertex == 2) {
	      hbeta1->Fill((*beta)[i]);
	    }
	    if(nvertex == 5 || nvertex == 6) {
	      hbeta2->Fill((*beta)[i]);
	    }
	    if(nvertex > 7) {
	      hbeta3->Fill((*beta)[i]);
	    }
	  }
	}
      }
      if(nalljets == 0 && ngoodjets == 0) {hPtZ0->Fill(PtZ);}
      if(ngoodjets != 0) {
	hNjets->Fill(1.*ngoodjets);
	hNvtx->Fill(1.*nvertex);
	if(nalljets == 1 && ngoodjets == 1) {
	  hPtZ->Fill(PtZ);
	  hDphiZJ->Fill(DphiZJ);
	}
	if( smallbeta == 1) {
	  hNvtx01->Fill(1.*nvertex);
	  hNjets01->Fill(1.*ngoodjets);
	  if(nalljets == 1 && ngoodjets == 1) {
	    hPtZ01->Fill(PtZ);
	    hDphiZJ01->Fill(DphiZJ);
	  }
	}
      }
   }
   setTDRStyle(0,0);
   // ===> di muon mass: 
   TCanvas* c1 = new TCanvas("X","Y",1);
   hM2mu->GetXaxis()->SetTitle("M_{#mu #mu}, GeV");
   hM2mu->GetYaxis()->SetTitle("Nev/2 GeV");
   hM2mu->Draw("hist");
   c1->SaveAs("M2mu.gif");

   // Et jet
   setTDRStyle(0,0);
   TCanvas* c2 = new TCanvas("X","Y",1);
   hEtJ->GetXaxis()->SetTitle("p_{T} of jets with |#eta|<2.0, GeV");
   hEtJ->GetYaxis()->SetTitle("Nev/5 GeV");
   hEtJ->Draw("hist");
   c2->SaveAs("EtJ.gif");
   // Et jet
   setTDRStyle(0,1);
   TCanvas* c21 = new TCanvas("X","Y",1);
   hEtJ->GetXaxis()->SetTitle("p_{T} of jets with |#eta|<2.0, GeV");
   hEtJ->GetYaxis()->SetTitle("Nev/5 GeV");
   hEtJ->SetMaximum(5000);
   hEtJ->SetMinimum(1.0);
   hEtJ->Draw("hist");
   hEtJ01->SetLineWidth(3);
   hEtJ01->SetLineStyle(2);
   hEtJ01->Draw("same");
   TLegend *leg = new TLegend(0.45,0.75,0.9,0.9,NULL,"brNDC");
   leg->SetFillColor(10);
   leg->AddEntry(hEtJ,"all jets","L");
   leg->AddEntry(hEtJ01,"jets with #beta < 0.1","L");
   leg->Draw();
   c21->SaveAs("EtJ01.gif");
 
   // Eta jet
   setTDRStyle(0,0);
   TCanvas* c3 = new TCanvas("X","Y",1);
   hEtaJ->GetXaxis()->SetTitle("#eta of jets with p_{T}>20 GeV");
   hEtaJ->GetYaxis()->SetTitle("Nev/0.2");
   hEtaJ->Draw("hist");
   c3->SaveAs("EtJ.gif");
   // Eta jet
   setTDRStyle(0,0);
   TCanvas* c31 = new TCanvas("X","Y",1);
   hEtaJ->GetXaxis()->SetTitle("#eta of jets with p_{T}>20 GeV");
   hEtaJ->GetYaxis()->SetTitle("Nev/0.2");
   hEtaJ->SetMaximum(450);
   hEtaJ->Draw("hist");
   hEtaJ01->SetLineStyle(2);
   hEtaJ01->SetLineWidth(3);
   hEtaJ01->Draw("same");
   TLegend *leg = new TLegend(0.45,0.8,0.9,0.9,NULL,"brNDC");
   leg->SetFillColor(10);
   leg->AddEntry(hEtaJ,"all jets","L");
   leg->AddEntry(hEtaJ01,"jets with #beta < 0.1","L");
   leg->Draw();
   c31->SaveAs("EtaJ01.gif");

   // N jets
   setTDRStyle(0,0);
   TCanvas* c4 = new TCanvas("X","Y",1);
   hNjets->GetXaxis()->SetTitle("N jets p_{T}> 20 GeV, |#eta| < 2.0");
   hNjets->GetYaxis()->SetTitle("Nev");
   hNjets->Draw("hist");
   c4->SaveAs("Njets.gif");
   // N jets
   setTDRStyle(0,1);
   TCanvas* c41 = new TCanvas("X","Y",1);
   hNjets->GetXaxis()->SetTitle("N jets p_{T}> 20 GeV, |#eta| < 2.0");
   hNjets->GetYaxis()->SetTitle("Nev");
   hNjets->SetMaximum(10000);
   hNjets->SetMinimum(1.0);
   hNjets->Draw("hist");
   hNjets01->SetLineWidth(3);
   hNjets01->SetLineStyle(2);
   hNjets01->Draw("same");
   TLegend *leg = new TLegend(0.45,0.75,0.9,0.9,NULL,"brNDC");
   leg->SetFillColor(10);
   leg->AddEntry(hNjets,"all jets","L");
   leg->AddEntry(hNjets01,"at least one with #beta < 0.1","L");
   leg->Draw();
   c41->SaveAs("Njets01.gif");

   // Nvtx
   setTDRStyle(0,0);
   TCanvas* c5 = new TCanvas("X","Y",1);
   hNvtx->GetXaxis()->SetTitle("N reco vtx (ev.with p_{T}^{j}>20 GeV, |#eta^{j}|<2.0)");
   hNvtx->GetYaxis()->SetTitle("Nev");
   hNvtx->Draw("hist");
   c5->SaveAs("Nvtx.gif");

   // beta 1 or 2 vtx
   setTDRStyle(0,0);
   TCanvas* c6 = new TCanvas("X","Y",1);
   hbeta1->GetXaxis()->SetTitle("#beta for Nvtx = 1 or 2");
   hbeta1->GetYaxis()->SetTitle("Nev");
   hbeta1->Draw("hist");
   c6->SaveAs("beta1.gif");

   // beta 5 or 6 vtx
   setTDRStyle(0,0);
   TCanvas* c7 = new TCanvas("X","Y",1);
   hbeta2->GetXaxis()->SetTitle("#beta for Nvtx = 5 or 6");
   hbeta2->GetYaxis()->SetTitle("Nev");
   hbeta2->Draw("hist");
   c7->SaveAs("beta2.gif");

   // beta 5 or 6 vtx
   setTDRStyle(0,0);
   TCanvas* c8 = new TCanvas("X","Y",1);
   hbeta3->GetXaxis()->SetTitle("#beta for Nvtx > 7");
   hbeta3->GetYaxis()->SetTitle("Nev");
   hbeta3->Draw("hist");
   c8->SaveAs("beta3.gif");

   // Nvtx
   setTDRStyle(0,1);
   TCanvas* c9 = new TCanvas("X","Y",1);
   hNvtx01->GetXaxis()->SetTitle("N reco vtx");
   hNvtx01->GetYaxis()->SetTitle("At least one jet with #beta < 0.1");
   hNvtx01->Sumw2();
   hNvtx01->Divide(hNvtx01,hNvtx,1.,1.,"B");
   hNvtx01->SetMaximum(0.600);
   hNvtx01->SetMinimum(0.005);
   hNvtx01->SetMarkerStyle(24);
   hNvtx01->Draw("PE1");
   c9->SaveAs("eff_smallbeta.gif");

   //pTz
   setTDRStyle(0,1);
   TCanvas* c10 = new TCanvas("X","Y",1);
   hPtZ->GetXaxis()->SetTitle("p_{T}^{#mu #mu}, GeV");
   hPtZ->GetYaxis()->SetTitle("Nev");
   hPtZ->SetMaximum(1000.);
   hPtZ->SetMinimum(0.1);
   hPtZ->Draw("hist"); 
   hPtZ01->SetLineStyle(1);
   hPtZ01->SetLineWidth(3);
   hPtZ01->Draw("samePE");
   Double_t scale = hPtZ01->Integral()/hPtZ0->Integral();
   hPtZ0->Scale(scale);
   hPtZ0->SetLineStyle(2);
   hPtZ0->SetLineWidth(3);
   hPtZ0->Draw("same");
   TLegend *leg = new TLegend(0.45,0.8,0.9,0.95,NULL,"brNDC");
   leg->SetFillColor(10);
   leg->AddEntry(hPtZ,"Z + 1 jet","L");
   leg->AddEntry(hPtZ01,"Z + 1 jet #beta < 0.1","P");
   leg->AddEntry(hPtZ0,"Z + no jets (scaled)","L");
   leg->Draw();
   c10->SaveAs("PtZ01.gif");

   setTDRStyle(0,1);
   TCanvas* c11 = new TCanvas("X","Y",1);
   hDphiZJ->GetXaxis()->SetTitle("#Delta #phi (Z-jet), rad");
   hDphiZJ->GetYaxis()->SetTitle("Nev");
   hDphiZJ->SetMaximum(2000);
   hDphiZJ->SetMinimum(0.5);
   hDphiZJ->Draw("hist");
   hDphiZJ01->SetLineWidth(3);
   hDphiZJ01->SetLineStyle(2);
   hDphiZJ01->Draw("same");
   TLegend *leg = new TLegend(0.2,0.75,0.65,0.9,NULL,"brNDC");
   leg->SetFillColor(10);
   leg->AddEntry(hDphiZJ,"Z + 1 jet","L");
   leg->AddEntry(hDphiZJ01,"Z + 1 jet #beta < 0.1","L");
   leg->Draw();
   c11->SaveAs("DphiZJ01.gif");

}
