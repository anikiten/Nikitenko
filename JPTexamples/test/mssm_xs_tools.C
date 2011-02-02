// tool to access MSSM neutral Higgs quantities 
// Version 0.1 by  Trevor Vickey    (Trevor.Vickey@cern.ch)
//             and Markus Warsinsky (Markus.Warsinsky@cern.ch
// to do:
//        - implement a help method to list all accessor methods
//        - ... 
#define mssm_xs_tools_cxx
#include "TH2F.h"
#include "mssm_xs_tools.h"
#include <iostream>
mssm_xs_tools::mssm_xs_tools(){
   std::cout<<"Welcome to the MSSM neutral cross section tool"<<std::endl;
   std::cout<<" Version 0.1 \n by  Monica Vazquez Acosta (Monica.Vazquez.Acosta@cern.ch),\n     Trevor Vickey         (Trevor.Vickey@cern.ch)\n     Markus Warsinsky      (Markus.Warsinsky@cern.ch)\n"<<std::endl;
   std::cout<<"please chose your input file with the SetInput method"<<std::endl;
}

mssm_xs_tools::~mssm_xs_tools() {}

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


void mssm_xs_tools::help(){
  std::cout<<"this is the MSSM neutral Higgs xsec tool"<<std::endl;
  std::cout<<"it takes prefabricated 2D ROOT histograms to obtain xsections"<<std::endl;
  std::cout<<"and BRs of h/H/A in dependence of mA and tan(beta)"<<std::endl;
  std::cout<<"to use it, first open an input file with the SetInput(filename) method"<<std::endl<<std::endl;
  std::cout<<"there are accessor classes for different quantities:"<<std::endl;
  std::cout<<"-  Give_Mass_h(Double_t mA, Double_t tanb) and\n   Give_Mass_H(Double_t mA, Double_t tanb)"<<std::endl;
  std::cout<<"   give the masses of the scalar bosons"<<std::endl;
  std::cout<<"-  Give_BR_X_YYY(Double_t mA, Double_t tanb) give the BRs,\n   where X can be h,H or A, and YYY can be bb, tautau or mumu"<<std::endl;
  std::cout<<"-  Give_Xsec_bbX5f(Double_t mA, Double_t tanb) gives the xsection in fb "<<std::endl;
  std::cout<<"   for b-associated production in the 5 flavour scheme (X can be h, H or A)"<<std::endl;
  std::cout<<"-  Give_Xsec_bbX4f(Double_t mA, Double_t tanb) gives the xsection in fb "<<std::endl;
  std::cout<<"   for b-associated production in the 5 flavour scheme (X can be h, H or A)"<<std::endl;
  std::cout<<"-  Give_Xsec_ggFX(Double_t mA, Double_t tanb) gives the xsection in fb "<<std::endl;
  std::cout<<"   for gluon-gluon fusion(X can be h, H or A)"<<std::endl;
  std::cout<<"-  for all xsections there are also accessor methods for the"<<std::endl;
  std::cout<<"       - scale uncertainties in fb "<<std::endl;
  std::cout<<"          (Give_XsecUnc_muup_YYY, Give_Xsec_Unc_mudown_YYY "<<std::endl;
  std::cout<<"             with YYY either bbX5f, bbX4f or ggFX with X h, H or A)"<<std::endl;
  std::cout<<"       - PDF uncertainties in fb"<<std::endl;
  std::cout<<"          (Give_XsecUnc_pdf68up/pdf90up/pdf68down/pdf90down)"<<std::endl;
  std::cout<<"          - Currently not available for b-assoc. prod. in 4 flavour scheme"<<std::endl;
  std::cout<<"          - 90% CL only for b-assoc. prod. in 5 flavour scheme"<<std::endl;
  std::cout<<"       - PDF+alphas uncertainties in fb"<<std::endl;
  std::cout<<"          (Give_XsecUnc_pdfalphas68up/pdfalphas90up/\n           pdfalphas68down/pdfalphas90down)"<<std::endl;
  std::cout<<"          - Currently not available for b-assoc. prod. in 4 flavour scheme"<<std::endl;
  std::cout<<"          - 90% CL only for b-assoc. prod. in 5 flavour scheme"<<std::endl;
  std::cout<<" please look into the header file for more detail"<<std::endl;

  return;
}


void mssm_xs_tools::SetInput(char* filename){
  m_input=new TFile(filename);
  m_h_brbb_h = (TH2F*) m_input->Get("h_brbb_h");	 
  m_h_brbb_H = (TH2F*) m_input->Get("h_brbb_H");	 
  m_h_brbb_A = (TH2F*) m_input->Get("h_brbb_A");	 
  m_h_brtautau_h = (TH2F*) m_input->Get("h_brtautau_h");	 
  m_h_brtautau_H = (TH2F*) m_input->Get("h_brtautau_H");	 
  m_h_brtautau_A = (TH2F*) m_input->Get("h_brtautau_A");	 
  m_h_brmumu_h = (TH2F*) m_input->Get("h_brmumu_h");	 
  m_h_brmumu_H = (TH2F*) m_input->Get("h_brmumu_H");	 
  m_h_brmumu_A = (TH2F*) m_input->Get("h_brmumu_A");	 

  
  
  m_h_ggF_xsec_h = (TH2F*) m_input->Get("h_ggF_xsec_h");	 
  m_h_ggF_xsec_H = (TH2F*) m_input->Get("h_ggF_xsec_H");	 
  m_h_ggF_xsec_A = (TH2F*) m_input->Get("h_ggF_xsec_A");	 
  m_h_ggF_xsec05_h = (TH2F*) m_input->Get("h_ggF_xsec05_h");
  m_h_ggF_xsec05_H = (TH2F*) m_input->Get("h_ggF_xsec05_H");
  m_h_ggF_xsec05_A = (TH2F*) m_input->Get("h_ggF_xsec05_A");
  m_h_ggF_xsec20_h = (TH2F*) m_input->Get("h_ggF_xsec20_h");
  m_h_ggF_xsec20_H = (TH2F*) m_input->Get("h_ggF_xsec20_H");
  m_h_ggF_xsec20_A = (TH2F*) m_input->Get("h_ggF_xsec20_A");
  
  m_h_ggF_pdfup_h = (TH2F*) m_input->Get("h_ggF_pdfup_h"); 
  m_h_ggF_pdfup_H = (TH2F*) m_input->Get("h_ggF_pdfup_H"); 
  m_h_ggF_pdfup_A = (TH2F*) m_input->Get("h_ggF_pdfup_A"); 
  m_h_ggF_pdfdown_h = (TH2F*) m_input->Get("h_ggF_pdfdown_h");
  m_h_ggF_pdfdown_H = (TH2F*) m_input->Get("h_ggF_pdfdown_H");
  m_h_ggF_pdfdown_A = (TH2F*) m_input->Get("h_ggF_pdfdown_A");
  


  m_h_ggF_alphasup_h = (TH2F*) m_input->Get("h_ggF_alphasup_h");
  m_h_ggF_alphasup_H = (TH2F*) m_input->Get("h_ggF_alphasup_H");
  m_h_ggF_alphasup_A = (TH2F*) m_input->Get("h_ggF_alphasup_A");
  m_h_ggF_alphasdown_h = (TH2F*) m_input->Get("h_ggF_alphasdown_h");
  m_h_ggF_alphasdown_H = (TH2F*) m_input->Get("h_ggF_alphasdown_H");
  m_h_ggF_alphasdown_A = (TH2F*) m_input->Get("h_ggF_alphasdown_A");
  


  
  m_h_bbH4f_xsec_h = (TH2F*) m_input->Get("h_bbH4f_xsec_h"); 
  m_h_bbH4f_xsec_H = (TH2F*) m_input->Get("h_bbH4f_xsec_H"); 
  m_h_bbH4f_xsec_A = (TH2F*) m_input->Get("h_bbH4f_xsec_A"); 
  m_h_bbH4f_xsec_h_low = (TH2F*) m_input->Get("h_bbH4f_xsec_h_low"); 
  m_h_bbH4f_xsec_H_low = (TH2F*) m_input->Get("h_bbH4f_xsec_H_low"); 
  m_h_bbH4f_xsec_A_low = (TH2F*) m_input->Get("h_bbH4f_xsec_A_low"); 
  m_h_bbH4f_xsec_h_high = (TH2F*) m_input->Get("h_bbH4f_xsec_h_high");
  m_h_bbH4f_xsec_H_high = (TH2F*) m_input->Get("h_bbH4f_xsec_H_high"); 
  m_h_bbH4f_xsec_A_high = (TH2F*) m_input->Get("h_bbH4f_xsec_A_high"); 
  

  
  m_h_bbH_xsec_h = (TH2F*) m_input->Get("h_bbH_xsec_h"); 
  m_h_bbH_xsec_H = (TH2F*) m_input->Get("h_bbH_xsec_H"); 
  m_h_bbH_xsec_A = (TH2F*) m_input->Get("h_bbH_xsec_A"); 

  m_h_bbH_mufdown_h = (TH2F*) m_input->Get("h_bbH_mufdown_h"); 
  m_h_bbH_mufdown_H = (TH2F*) m_input->Get("h_bbH_mufdown_H"); 
  m_h_bbH_mufdown_A = (TH2F*) m_input->Get("h_bbH_mufdown_A"); 
  m_h_bbH_mufup_h = (TH2F*) m_input->Get("h_bbH_mufup_h"); 
  m_h_bbH_mufup_H = (TH2F*) m_input->Get("h_bbH_mufup_H"); 
  m_h_bbH_mufup_A = (TH2F*) m_input->Get("h_bbH_mufup_A"); 

  m_h_bbH_murdown_h = (TH2F*) m_input->Get("h_bbH_murdown_h");
  m_h_bbH_murdown_H = (TH2F*) m_input->Get("h_bbH_murdown_H");
  m_h_bbH_murdown_A = (TH2F*) m_input->Get("h_bbH_murdown_A");
  m_h_bbH_murup_h = (TH2F*) m_input->Get("h_bbH_murup_h");  
  m_h_bbH_murup_H = (TH2F*) m_input->Get("h_bbH_murup_H");  
  m_h_bbH_murup_A = (TH2F*) m_input->Get("h_bbH_murup_A");  
  
  m_h_bbH_mudown_h = (TH2F*) m_input->Get("h_bbH_mudown_h"); 
  m_h_bbH_mudown_H = (TH2F*) m_input->Get("h_bbH_mudown_H"); 
  m_h_bbH_mudown_A = (TH2F*) m_input->Get("h_bbH_mudown_A"); 
  m_h_bbH_muup_h = (TH2F*) m_input->Get("h_bbH_muup_h"); 
  m_h_bbH_muup_H = (TH2F*) m_input->Get("h_bbH_muup_H"); 
  m_h_bbH_muup_A = (TH2F*) m_input->Get("h_bbH_muup_A"); 

  m_h_bbH_pdf68down_h = (TH2F*) m_input->Get("h_bbH_pdf68down_h"); 
  m_h_bbH_pdf68down_H = (TH2F*) m_input->Get("h_bbH_pdf68down_H"); 
  m_h_bbH_pdf68down_A = (TH2F*) m_input->Get("h_bbH_pdf68down_A"); 
  m_h_bbH_pdf68up_h = (TH2F*) m_input->Get("h_bbH_pdf68up_h"); 
  m_h_bbH_pdf68up_H = (TH2F*) m_input->Get("h_bbH_pdf68up_H"); 
  m_h_bbH_pdf68up_A = (TH2F*) m_input->Get("h_bbH_pdf68up_A"); 

  m_h_bbH_pdf90down_h = (TH2F*) m_input->Get("h_bbH_pdf90down_h"); 
  m_h_bbH_pdf90down_H = (TH2F*) m_input->Get("h_bbH_pdf90down_H"); 
  m_h_bbH_pdf90down_A = (TH2F*) m_input->Get("h_bbH_pdf90down_A"); 
  m_h_bbH_pdf90up_h = (TH2F*) m_input->Get("h_bbH_pdf90up_h"); 
  m_h_bbH_pdf90up_H = (TH2F*) m_input->Get("h_bbH_pdf90up_H"); 
  m_h_bbH_pdf90up_A = (TH2F*) m_input->Get("h_bbH_pdf90up_A"); 

  m_h_bbH_pdfalphas68down_h = (TH2F*) m_input->Get("h_bbH_pdfalphas68down_h"); 
  m_h_bbH_pdfalphas68down_H = (TH2F*) m_input->Get("h_bbH_pdfalphas68down_H"); 
  m_h_bbH_pdfalphas68down_A = (TH2F*) m_input->Get("h_bbH_pdfalphas68down_A"); 
  m_h_bbH_pdfalphas68up_h = (TH2F*) m_input->Get("h_bbH_pdfalphas68up_h"); 
  m_h_bbH_pdfalphas68up_H = (TH2F*) m_input->Get("h_bbH_pdfalphas68up_H"); 
  m_h_bbH_pdfalphas68up_A = (TH2F*) m_input->Get("h_bbH_pdfalphas68up_A"); 

  m_h_bbH_pdfalphas90down_h = (TH2F*) m_input->Get("h_bbH_pdfalphas90down_h"); 
  m_h_bbH_pdfalphas90down_H = (TH2F*) m_input->Get("h_bbH_pdfalphas90down_H"); 
  m_h_bbH_pdfalphas90down_A = (TH2F*) m_input->Get("h_bbH_pdfalphas90down_A"); 
  m_h_bbH_pdfalphas90up_h = (TH2F*) m_input->Get("h_bbH_pdfalphas90up_h"); 
  m_h_bbH_pdfalphas90up_H = (TH2F*) m_input->Get("h_bbH_pdfalphas90up_H"); 
  m_h_bbH_pdfalphas90up_A = (TH2F*) m_input->Get("h_bbH_pdfalphas90up_A"); 
  
  m_h_mh = (TH2F*) m_input->Get("h_mh"); 
  m_h_mH = (TH2F*) m_input->Get("h_mH"); 

 
  std::cout<<"some info about the setup used for your chosen output file:"<<std::endl;
  TObjString* description=(TObjString*) m_input->Get("description");
  std::cout<<description->String()<<std::endl;

  return;
}
// New Stuff:
Double_t mssm_xs_tools::Give_BR_A_bb(Double_t mA, Double_t tanb){
  int gbin=m_h_brbb_A->FindBin(mA,tanb);
  return m_h_brbb_A->GetBinContent(gbin);
}
Double_t mssm_xs_tools::Give_BR_H_bb(Double_t mA, Double_t tanb){
  int gbin=m_h_brbb_H->FindBin(mA,tanb);
  return m_h_brbb_H->GetBinContent(gbin);
}
Double_t mssm_xs_tools::Give_BR_h_bb(Double_t mA, Double_t tanb){
  int gbin=m_h_brbb_h->FindBin(mA,tanb);
  return m_h_brbb_h->GetBinContent(gbin);
}

Double_t mssm_xs_tools::Give_BR_A_tautau(Double_t mA, Double_t tanb){
  int gbin=m_h_brtautau_A->FindBin(mA,tanb);
  return m_h_brtautau_A->GetBinContent(gbin);
}
Double_t mssm_xs_tools::Give_BR_H_tautau(Double_t mA, Double_t tanb){
  int gbin=m_h_brtautau_H->FindBin(mA,tanb);
  return m_h_brtautau_H->GetBinContent(gbin);
}
Double_t mssm_xs_tools::Give_BR_h_tautau(Double_t mA, Double_t tanb){
  int gbin=m_h_brtautau_h->FindBin(mA,tanb);
  return m_h_brtautau_h->GetBinContent(gbin);
}

Double_t mssm_xs_tools::Give_BR_A_mumu(Double_t mA, Double_t tanb){
  int gbin=m_h_brmumu_A->FindBin(mA,tanb);
  return m_h_brmumu_A->GetBinContent(gbin);
}
Double_t mssm_xs_tools::Give_BR_H_mumu(Double_t mA, Double_t tanb){
  int gbin=m_h_brmumu_H->FindBin(mA,tanb);
  return m_h_brmumu_H->GetBinContent(gbin);
}
Double_t mssm_xs_tools::Give_BR_h_mumu(Double_t mA, Double_t tanb){
  int gbin=m_h_brmumu_h->FindBin(mA,tanb);
  return m_h_brmumu_h->GetBinContent(gbin);
}






Double_t mssm_xs_tools::Give_Mass_h(Double_t mA, Double_t tanb){
  int gbin=m_h_mh->FindBin(mA,tanb);
  return m_h_mh->GetBinContent(gbin);
}
Double_t mssm_xs_tools::Give_Mass_H(Double_t mA, Double_t tanb){
  int gbin=m_h_mH->FindBin(mA,tanb);
  return m_h_mH->GetBinContent(gbin);
}

  
Double_t mssm_xs_tools::Give_Xsec_bbA5f(Double_t mA, Double_t tanb){
  int gbin=m_h_bbH_xsec_A->FindBin(mA,tanb);
  return m_h_bbH_xsec_A->GetBinContent(gbin);
}
Double_t mssm_xs_tools::Give_Xsec_bbh5f(Double_t mA, Double_t tanb){
  int gbin=m_h_bbH_xsec_h->FindBin(mA,tanb);
  return m_h_bbH_xsec_h->GetBinContent(gbin);
}
Double_t mssm_xs_tools::Give_Xsec_bbH5f(Double_t mA, Double_t tanb){
  int gbin=m_h_bbH_xsec_H->FindBin(mA,tanb);
  return m_h_bbH_xsec_H->GetBinContent(gbin);
}
Double_t mssm_xs_tools::Give_XsecUnc_muup_bbA5f(Double_t mA, Double_t tanb){
  int gbin=m_h_bbH_muup_A->FindBin(mA,tanb);
  return m_h_bbH_muup_A->GetBinContent(gbin);
}
Double_t mssm_xs_tools::Give_XsecUnc_muup_bbh5f(Double_t mA, Double_t tanb){
  int gbin=m_h_bbH_muup_h->FindBin(mA,tanb);
  return m_h_bbH_muup_h->GetBinContent(gbin);
}
Double_t mssm_xs_tools::Give_XsecUnc_muup_bbH5f(Double_t mA, Double_t tanb){
  int gbin=m_h_bbH_muup_H->FindBin(mA,tanb);
  return m_h_bbH_muup_H->GetBinContent(gbin);
}


Double_t mssm_xs_tools::Give_XsecUnc_mudown_bbA5f(Double_t mA, Double_t tanb){
  int gbin=m_h_bbH_mudown_A->FindBin(mA,tanb);
  return m_h_bbH_mudown_A->GetBinContent(gbin);
}
Double_t mssm_xs_tools::Give_XsecUnc_mudown_bbh5f(Double_t mA, Double_t tanb){
  int gbin=m_h_bbH_mudown_h->FindBin(mA,tanb);
  return m_h_bbH_mudown_h->GetBinContent(gbin);
}
Double_t mssm_xs_tools::Give_XsecUnc_mudown_bbH5f(Double_t mA, Double_t tanb){
  int gbin=m_h_bbH_mudown_H->FindBin(mA,tanb);
  return m_h_bbH_mudown_H->GetBinContent(gbin);
}


Double_t mssm_xs_tools::Give_XsecUnc_pdf68up_bbA5f(Double_t mA, Double_t tanb){
  int gbin=m_h_bbH_pdf68up_A->FindBin(mA,tanb);
  return m_h_bbH_pdf68up_A->GetBinContent(gbin);
}
Double_t mssm_xs_tools::Give_XsecUnc_pdf68up_bbh5f(Double_t mA, Double_t tanb){
  int gbin=m_h_bbH_pdf68up_h->FindBin(mA,tanb);
  return m_h_bbH_pdf68up_h->GetBinContent(gbin);
}
Double_t mssm_xs_tools::Give_XsecUnc_pdf68up_bbH5f(Double_t mA, Double_t tanb){
  int gbin=m_h_bbH_pdf68up_H->FindBin(mA,tanb);
  return m_h_bbH_pdf68up_H->GetBinContent(gbin);
}

Double_t mssm_xs_tools::Give_XsecUnc_pdf68down_bbA5f(Double_t mA, Double_t tanb){
  int gbin=m_h_bbH_pdf68down_A->FindBin(mA,tanb);
  return m_h_bbH_pdf68down_A->GetBinContent(gbin);
}
Double_t mssm_xs_tools::Give_XsecUnc_pdf68down_bbh5f(Double_t mA, Double_t tanb){
  int gbin=m_h_bbH_pdf68down_h->FindBin(mA,tanb);
  return m_h_bbH_pdf68down_h->GetBinContent(gbin);
}
Double_t mssm_xs_tools::Give_XsecUnc_pdf68down_bbH5f(Double_t mA, Double_t tanb){
  int gbin=m_h_bbH_pdf68down_H->FindBin(mA,tanb);
  return m_h_bbH_pdf68down_H->GetBinContent(gbin);
}



Double_t mssm_xs_tools::Give_XsecUnc_pdfalphas68up_bbA5f(Double_t mA, Double_t tanb){
  int gbin=m_h_bbH_pdfalphas68up_A->FindBin(mA,tanb);
  return m_h_bbH_pdfalphas68up_A->GetBinContent(gbin);
}
Double_t mssm_xs_tools::Give_XsecUnc_pdfalphas68up_bbh5f(Double_t mA, Double_t tanb){
  int gbin=m_h_bbH_pdfalphas68up_h->FindBin(mA,tanb);
  return m_h_bbH_pdfalphas68up_h->GetBinContent(gbin);
}
Double_t mssm_xs_tools::Give_XsecUnc_pdfalphas68up_bbH5f(Double_t mA, Double_t tanb){
  int gbin=m_h_bbH_pdfalphas68up_H->FindBin(mA,tanb);
  return m_h_bbH_pdfalphas68up_H->GetBinContent(gbin);
}

Double_t mssm_xs_tools::Give_XsecUnc_pdfalphas68down_bbA5f(Double_t mA, Double_t tanb){
  int gbin=m_h_bbH_pdfalphas68down_A->FindBin(mA,tanb);
  return m_h_bbH_pdfalphas68down_A->GetBinContent(gbin);
}
Double_t mssm_xs_tools::Give_XsecUnc_pdfalphas68down_bbh5f(Double_t mA, Double_t tanb){
  int gbin=m_h_bbH_pdfalphas68down_h->FindBin(mA,tanb);
  return m_h_bbH_pdfalphas68down_h->GetBinContent(gbin);
}
Double_t mssm_xs_tools::Give_XsecUnc_pdfalphas68down_bbH5f(Double_t mA, Double_t tanb){
  int gbin=m_h_bbH_pdfalphas68down_H->FindBin(mA,tanb);
  return m_h_bbH_pdfalphas68down_H->GetBinContent(gbin);
}





Double_t mssm_xs_tools::Give_XsecUnc_pdf90up_bbA5f(Double_t mA, Double_t tanb){
  int gbin=m_h_bbH_pdf90up_A->FindBin(mA,tanb);
  return m_h_bbH_pdf90up_A->GetBinContent(gbin);
}
Double_t mssm_xs_tools::Give_XsecUnc_pdf90up_bbh5f(Double_t mA, Double_t tanb){
  int gbin=m_h_bbH_pdf90up_h->FindBin(mA,tanb);
  return m_h_bbH_pdf90up_h->GetBinContent(gbin);
}
Double_t mssm_xs_tools::Give_XsecUnc_pdf90up_bbH5f(Double_t mA, Double_t tanb){
  int gbin=m_h_bbH_pdf90up_H->FindBin(mA,tanb);
  return m_h_bbH_pdf90up_H->GetBinContent(gbin);
}

Double_t mssm_xs_tools::Give_XsecUnc_pdf90down_bbA5f(Double_t mA, Double_t tanb){
  int gbin=m_h_bbH_pdf90down_A->FindBin(mA,tanb);
  return m_h_bbH_pdf90down_A->GetBinContent(gbin);
}
Double_t mssm_xs_tools::Give_XsecUnc_pdf90down_bbh5f(Double_t mA, Double_t tanb){
  int gbin=m_h_bbH_pdf90down_h->FindBin(mA,tanb);
  return m_h_bbH_pdf90down_h->GetBinContent(gbin);
}
Double_t mssm_xs_tools::Give_XsecUnc_pdf90down_bbH5f(Double_t mA, Double_t tanb){
  int gbin=m_h_bbH_pdf90down_H->FindBin(mA,tanb);
  return m_h_bbH_pdf90down_H->GetBinContent(gbin);
}



Double_t mssm_xs_tools::Give_XsecUnc_pdfalphas90up_bbA5f(Double_t mA, Double_t tanb){
  int gbin=m_h_bbH_pdfalphas90up_A->FindBin(mA,tanb);
  return m_h_bbH_pdfalphas90up_A->GetBinContent(gbin);
}
Double_t mssm_xs_tools::Give_XsecUnc_pdfalphas90up_bbh5f(Double_t mA, Double_t tanb){
  int gbin=m_h_bbH_pdfalphas90up_h->FindBin(mA,tanb);
  return m_h_bbH_pdfalphas90up_h->GetBinContent(gbin);
}
Double_t mssm_xs_tools::Give_XsecUnc_pdfalphas90up_bbH5f(Double_t mA, Double_t tanb){
  int gbin=m_h_bbH_pdfalphas90up_H->FindBin(mA,tanb);
  return m_h_bbH_pdfalphas90up_H->GetBinContent(gbin);
}

Double_t mssm_xs_tools::Give_XsecUnc_pdfalphas90down_bbA5f(Double_t mA, Double_t tanb){
  int gbin=m_h_bbH_pdfalphas90down_A->FindBin(mA,tanb);
  return m_h_bbH_pdfalphas90down_A->GetBinContent(gbin);
}
Double_t mssm_xs_tools::Give_XsecUnc_pdfalphas90down_bbh5f(Double_t mA, Double_t tanb){
  int gbin=m_h_bbH_pdfalphas90down_h->FindBin(mA,tanb);
  return m_h_bbH_pdfalphas90down_h->GetBinContent(gbin);
}
Double_t mssm_xs_tools::Give_XsecUnc_pdfalphas90down_bbH5f(Double_t mA, Double_t tanb){
  int gbin=m_h_bbH_pdfalphas90down_H->FindBin(mA,tanb);
  return m_h_bbH_pdfalphas90down_H->GetBinContent(gbin);
}

Double_t mssm_xs_tools::Give_Xsec_bbA4f(Double_t mA, Double_t tanb){
  int gbin=m_h_bbH4f_xsec_A->FindBin(mA,tanb);
  return m_h_bbH4f_xsec_A->GetBinContent(gbin);
}
Double_t mssm_xs_tools::Give_Xsec_bbH4f(Double_t mA, Double_t tanb){
  int gbin=m_h_bbH4f_xsec_H->FindBin(mA,tanb);
  return m_h_bbH4f_xsec_H->GetBinContent(gbin);
}
Double_t mssm_xs_tools::Give_Xsec_bbh4f(Double_t mA, Double_t tanb){
  int gbin=m_h_bbH4f_xsec_h->FindBin(mA,tanb);
  return m_h_bbH4f_xsec_h->GetBinContent(gbin);
}


Double_t mssm_xs_tools::Give_XsecUnc_mudown_bbA4f(Double_t mA, Double_t tanb){
  int gbin=m_h_bbH4f_xsec_A_low->FindBin(mA,tanb);
  double lowval=m_h_bbH4f_xsec_A_low->GetBinContent(gbin);
  gbin=m_h_bbH4f_xsec_A->FindBin(mA,tanb);
  double centval=m_h_bbH4f_xsec_A->GetBinContent(gbin);
  return lowval-centval;
}

Double_t mssm_xs_tools::Give_XsecUnc_mudown_bbh4f(Double_t mA, Double_t tanb){
  int gbin=m_h_bbH4f_xsec_h_low->FindBin(mA,tanb);
  double lowval=m_h_bbH4f_xsec_h_low->GetBinContent(gbin);
  gbin=m_h_bbH4f_xsec_h->FindBin(mA,tanb);
  double centval=m_h_bbH4f_xsec_h->GetBinContent(gbin);
  return lowval-centval;
}

Double_t mssm_xs_tools::Give_XsecUnc_mudown_bbH4f(Double_t mA, Double_t tanb){
  int gbin=m_h_bbH4f_xsec_H_low->FindBin(mA,tanb);
  double lowval=m_h_bbH4f_xsec_H_low->GetBinContent(gbin);
  gbin=m_h_bbH4f_xsec_H->FindBin(mA,tanb);
  double centval=m_h_bbH4f_xsec_H->GetBinContent(gbin);
  return lowval-centval;
}


Double_t mssm_xs_tools::Give_XsecUnc_muup_bbA4f(Double_t mA, Double_t tanb){
  int gbin=m_h_bbH4f_xsec_A_high->FindBin(mA,tanb);
  double highval=m_h_bbH4f_xsec_A_high->GetBinContent(gbin);
  gbin=m_h_bbH4f_xsec_A->FindBin(mA,tanb);
  double centval=m_h_bbH4f_xsec_A->GetBinContent(gbin);
  return highval-centval;
}

Double_t mssm_xs_tools::Give_XsecUnc_muup_bbh4f(Double_t mA, Double_t tanb){
  int gbin=m_h_bbH4f_xsec_h_high->FindBin(mA,tanb);
  double highval=m_h_bbH4f_xsec_h_high->GetBinContent(gbin);
  gbin=m_h_bbH4f_xsec_h->FindBin(mA,tanb);
  double centval=m_h_bbH4f_xsec_h->GetBinContent(gbin);
  return highval-centval;
}

Double_t mssm_xs_tools::Give_XsecUnc_muup_bbH4f(Double_t mA, Double_t tanb){
  int gbin=m_h_bbH4f_xsec_H_high->FindBin(mA,tanb);
  double highval=m_h_bbH4f_xsec_H_high->GetBinContent(gbin);
  gbin=m_h_bbH4f_xsec_H->FindBin(mA,tanb);
  double centval=m_h_bbH4f_xsec_H->GetBinContent(gbin);
  return highval-centval;
}

Double_t mssm_xs_tools::Give_Xsec_ggFA(Double_t mA, Double_t tanb){
  int gbin=m_h_ggF_xsec_A->FindBin(mA,tanb);
  return 1000.*m_h_ggF_xsec_A->GetBinContent(gbin);
}
Double_t mssm_xs_tools::Give_Xsec_ggFH(Double_t mA, Double_t tanb){
  int gbin=m_h_ggF_xsec_H->FindBin(mA,tanb);
  return 1000.*m_h_ggF_xsec_H->GetBinContent(gbin);
}
Double_t mssm_xs_tools::Give_Xsec_ggFh(Double_t mA, Double_t tanb){
  int gbin=m_h_ggF_xsec_h->FindBin(mA,tanb);
  return 1000.*m_h_ggF_xsec_h->GetBinContent(gbin);
}

Double_t mssm_xs_tools::Give_XsecUnc_muup_ggFA(Double_t mA, Double_t tanb){
  int gbin=m_h_ggF_xsec05_A->FindBin(mA,tanb);
  double highval=1000.*m_h_ggF_xsec05_A->GetBinContent(gbin);
  gbin=m_h_ggF_xsec_A->FindBin(mA,tanb);
  double centval=1000.*m_h_ggF_xsec_A->GetBinContent(gbin);
  return (highval-centval);
}

Double_t mssm_xs_tools::Give_XsecUnc_muup_ggFH(Double_t mA, Double_t tanb){
  int gbin=m_h_ggF_xsec05_H->FindBin(mA,tanb);
  double highval=1000.*m_h_ggF_xsec05_H->GetBinContent(gbin);
  gbin=m_h_ggF_xsec_H->FindBin(mA,tanb);
  double centval=1000.*m_h_ggF_xsec_H->GetBinContent(gbin);
  return (highval-centval);
}

Double_t mssm_xs_tools::Give_XsecUnc_muup_ggFh(Double_t mA, Double_t tanb){
  int gbin=m_h_ggF_xsec05_h->FindBin(mA,tanb);
  double highval=1000.*m_h_ggF_xsec05_h->GetBinContent(gbin);
  gbin=m_h_ggF_xsec_h->FindBin(mA,tanb);
  double centval=1000.*m_h_ggF_xsec_h->GetBinContent(gbin);
  return (highval-centval);
}


Double_t mssm_xs_tools::Give_XsecUnc_mudown_ggFA(Double_t mA, Double_t tanb){
  int gbin=m_h_ggF_xsec20_A->FindBin(mA,tanb);
  double lowval=1000.*m_h_ggF_xsec20_A->GetBinContent(gbin);
  gbin=m_h_ggF_xsec_A->FindBin(mA,tanb);
  double centval=1000.*m_h_ggF_xsec_A->GetBinContent(gbin);
  return (lowval-centval);
}

Double_t mssm_xs_tools::Give_XsecUnc_mudown_ggFH(Double_t mA, Double_t tanb){
  int gbin=m_h_ggF_xsec20_H->FindBin(mA,tanb);
  double lowval=1000.*m_h_ggF_xsec20_H->GetBinContent(gbin);
  gbin=m_h_ggF_xsec_H->FindBin(mA,tanb);
  double centval=1000.*m_h_ggF_xsec_H->GetBinContent(gbin);
  return (lowval-centval);
}

Double_t mssm_xs_tools::Give_XsecUnc_mudown_ggFh(Double_t mA, Double_t tanb){
  int gbin=m_h_ggF_xsec20_h->FindBin(mA,tanb);
  double lowval=1000.*m_h_ggF_xsec20_h->GetBinContent(gbin);
  gbin=m_h_ggF_xsec_h->FindBin(mA,tanb);
  double centval=1000.*m_h_ggF_xsec_h->GetBinContent(gbin);
  return (lowval-centval);
}


Double_t mssm_xs_tools::Give_XsecUnc_pdf68up_ggFA(Double_t mA, Double_t tanb){
  int gbin=m_h_ggF_pdfup_A->FindBin(mA,tanb);
  return 1000.*m_h_ggF_pdfup_A->GetBinContent(gbin);
}
Double_t mssm_xs_tools::Give_XsecUnc_pdf68up_ggFH(Double_t mA, Double_t tanb){
  int gbin=m_h_ggF_pdfup_H->FindBin(mA,tanb);
  return 1000.*m_h_ggF_pdfup_H->GetBinContent(gbin);
}

Double_t mssm_xs_tools::Give_XsecUnc_pdf68up_ggFh(Double_t mA, Double_t tanb){
  int gbin=m_h_ggF_pdfup_h->FindBin(mA,tanb);
  return 1000.*m_h_ggF_pdfup_h->GetBinContent(gbin);
}


Double_t mssm_xs_tools::Give_XsecUnc_pdf68down_ggFA(Double_t mA, Double_t tanb){
  int gbin=m_h_ggF_pdfdown_A->FindBin(mA,tanb);
  return (-1000.)*m_h_ggF_pdfdown_A->GetBinContent(gbin);
}
Double_t mssm_xs_tools::Give_XsecUnc_pdf68down_ggFH(Double_t mA, Double_t tanb){
  int gbin=m_h_ggF_pdfdown_H->FindBin(mA,tanb);
  return (-1000.)*m_h_ggF_pdfdown_H->GetBinContent(gbin);
}

Double_t mssm_xs_tools::Give_XsecUnc_pdf68down_ggFh(Double_t mA, Double_t tanb){
  int gbin=m_h_ggF_pdfdown_h->FindBin(mA,tanb);
  return (-1000.)*m_h_ggF_pdfdown_h->GetBinContent(gbin);
}

Double_t mssm_xs_tools::Give_XsecUnc_pdfalphas68up_ggFA(Double_t mA, Double_t tanb){
  int gbin=m_h_ggF_alphasup_A->FindBin(mA,tanb);
  double alphasval=1000.*m_h_ggF_alphasup_A->GetBinContent(gbin);
  gbin=m_h_ggF_pdfup_A->FindBin(mA,tanb);
  double pdfval=1000.*m_h_ggF_pdfup_A->GetBinContent(gbin);
  return sqrt(alphasval*alphasval+pdfval*pdfval);
}


Double_t mssm_xs_tools::Give_XsecUnc_pdfalphas68up_ggFH(Double_t mA, Double_t tanb){
  int gbin=m_h_ggF_alphasup_H->FindBin(mA,tanb);
  double alphasval=1000.*m_h_ggF_alphasup_H->GetBinContent(gbin);
  gbin=m_h_ggF_pdfup_H->FindBin(mA,tanb);
  double pdfval=1000.*m_h_ggF_pdfup_H->GetBinContent(gbin);
  return sqrt(alphasval*alphasval+pdfval*pdfval);
}

Double_t mssm_xs_tools::Give_XsecUnc_pdfalphas68up_ggFh(Double_t mA, Double_t tanb){
  int gbin=m_h_ggF_alphasup_h->FindBin(mA,tanb);
  double alphasval=1000.*m_h_ggF_alphasup_h->GetBinContent(gbin);
  gbin=m_h_ggF_pdfup_h->FindBin(mA,tanb);
  double pdfval=1000.*m_h_ggF_pdfup_h->GetBinContent(gbin);
  return sqrt(alphasval*alphasval+pdfval*pdfval);
}

Double_t mssm_xs_tools::Give_XsecUnc_pdfalphas68down_ggFA(Double_t mA, Double_t tanb){
  int gbin=m_h_ggF_alphasdown_A->FindBin(mA,tanb);
  double alphasval=1000.*m_h_ggF_alphasdown_A->GetBinContent(gbin);
  gbin=m_h_ggF_pdfdown_A->FindBin(mA,tanb);
  double pdfval=1000.*m_h_ggF_pdfdown_A->GetBinContent(gbin);
  return -sqrt(alphasval*alphasval+pdfval*pdfval);
}


Double_t mssm_xs_tools::Give_XsecUnc_pdfalphas68down_ggFH(Double_t mA, Double_t tanb){
  int gbin=m_h_ggF_alphasdown_H->FindBin(mA,tanb);
  double alphasval=1000.*m_h_ggF_alphasdown_H->GetBinContent(gbin);
  gbin=m_h_ggF_pdfdown_H->FindBin(mA,tanb);
  double pdfval=1000.*m_h_ggF_pdfdown_H->GetBinContent(gbin);
  return -sqrt(alphasval*alphasval+pdfval*pdfval);
}

Double_t mssm_xs_tools::Give_XsecUnc_pdfalphas68down_ggFh(Double_t mA, Double_t tanb){
  int gbin=m_h_ggF_alphasdown_h->FindBin(mA,tanb);
  double alphasval=1000.*m_h_ggF_alphasdown_h->GetBinContent(gbin);
  gbin=m_h_ggF_pdfdown_h->FindBin(mA,tanb);
  double pdfval=1000.*m_h_ggF_pdfdown_h->GetBinContent(gbin);
  return -sqrt(alphasval*alphasval+pdfval*pdfval);
}

void mssm_xs_tools::myanalysis(){
  std::cout<<"My analysis starts"<<std::endl;

  const Int_t nbhmass = 11;
  Double_t mass[nbhmass]={90., 100., 120., 130., 140., 160., 180., 200., 250., 300., 350.};

  Double_t xsect_x_Br_limit[nbhmass]={185.99, 148.32, 36.17, 22.42, 15.74, 8.77, 5.78, 4.35, 2.46, 1.58, 1.23};

  Double_t tanb_exp[nbhmass];
  Double_t tanb_exp_thu[nbhmass];
  Double_t tanb_exp_thd[nbhmass];


  Double_t tanb_exp_abdel[nbhmass];
  Double_t tanb_exp_thu_abdel[nbhmass];
  Double_t tanb_exp_thd_abdel[nbhmass];

  Double_t br_abdel[nbhmass] =           {0.096, 0.098, 0.101, 0.103, 0.104, 0.106, 0.108, 0.110, 0.115, 0.118, 0.121};
  Double_t ggh_abdel[nbhmass] =          {542.3, 320.3, 126.3, 83.2,  56.3,  27.5,  14.5,   8.04,  2.24,  0.76, 0.30};
  Double_t err_ggh_up_abdel[nbhmass]   = { 0.5,  0.5,   0.5,   0.5,   0.5,   0.5,   0.5,    0.5,   0.5,   0.5,  0.5};
  Double_t err_ggh_down_abdel[nbhmass] = { 0.4,  0.4,   0.4,   0.4,   0.4,   0.4,   0.4,    0.4,   0.4,   0.4,  0.4};

  Double_t bbh_abdel[nbhmass] =          {487.8, 346.5, 186.6, 141.0, 108.1, 65.8,  42.0,   27.6, 10.97,  4.94, 2.43};
  Double_t err_bbh_up_abdel[nbhmass]   = {0.44,  0.41,  0.36,  0.34,  0.31,  0.28,  0.25,   0.24, 0.23,   0.24, 0.26};
  Double_t err_bbh_down_abdel[nbhmass] = {0.33,  0.30,  0.27,  0.27,  0.27,  0.27,  0.26,   0.26,  0.25,   0.25, 0.25};

  /*
  cout <<" gg->A: xsect = " << Give_Xsec_ggFA(300,30)
       <<" scaleU = " << Give_XsecUnc_muup_ggFA(300,30)
       <<" scaleD = " << Give_XsecUnc_mudown_ggFA(300,30)
       <<" PDF+alphaU= " << Give_XsecUnc_pdfalphas68up_ggFA(300,30)
       <<" PDF+alphaD= " << Give_XsecUnc_pdfalphas68down_ggFA(300,30) << endl;

  cout <<" gg->A: xsect = " << Give_Xsec_bbA5f(100,30)
       <<" scaleU = " << Give_XsecUnc_muup_bbA5f(100,30)
       <<" scaleD = " << Give_XsecUnc_mudown_bbA5f(100,30)
       <<" PDF+alphaU= " << Give_XsecUnc_pdfalphas68up_bbA5f(100,30)
       <<" PDF+alphaD= " << Give_XsecUnc_pdfalphas68down_bbA5f(100,30) << endl;
  */

  for(Int_t i = 0; i < nbhmass ; i++) {

    Int_t tanlow  = 0;
    Int_t tan     = 0;
    Int_t tanhigh = 0;

    Int_t tanlow_abdel  = 0;
    Int_t tan_abdel     = 0;
    Int_t tanhigh_abdel = 0;

    std::cout <<" " << std::endl;

    for(Int_t j = 10; j < 60; j ++) {

      Double_t tanb = 1.*j;
      Double_t xsec_x_Br = 0.;
      Double_t xsect_x_Br_UncU = 0.;
      Double_t xsect_x_Br_UncD = 0.; 

      Double_t tanb_abdel = 1.*j;
      Double_t xsec_x_Br_abdel = (ggh_abdel[i] + bbh_abdel[i]) * br_abdel[i] * 2.0 * (tanb_abdel*tanb_abdel) 
	* 0.001;
      Double_t xsect_x_Br_UncU_abdel = (ggh_abdel[i]*err_ggh_up_abdel[i] + bbh_abdel[i]*err_bbh_up_abdel[i]) * br_abdel[i] * 2.0 * (tanb_abdel*tanb_abdel) 
	* 0.001;
      Double_t xsect_x_Br_UncD_abdel = -1.0 * (ggh_abdel[i]*err_ggh_down_abdel[i] + bbh_abdel[i]*err_bbh_down_abdel[i]) * br_abdel[i] * 2.0 * (tanb_abdel*tanb_abdel) 
	* 0.001; 

      if(mass[i] < 130) {
	xsec_x_Br = 
	  (Give_Xsec_ggFA(mass[i],tanb)+Give_Xsec_bbA5f(mass[i],tanb))*Give_BR_A_tautau(mass[i],tanb) +
	  (Give_Xsec_ggFh(mass[i],tanb)+Give_Xsec_bbh5f(mass[i],tanb))*Give_BR_h_tautau(mass[i],tanb);

	//  sum of PDF unce in quardature
	xsect_x_Br_UncU = 
	  (Give_XsecUnc_muup_ggFA(mass[i],tanb)+Give_XsecUnc_muup_bbA5f(mass[i],tanb) +
	   sqrt(Give_XsecUnc_pdfalphas68up_ggFA(mass[i],tanb)*Give_XsecUnc_pdfalphas68up_ggFA(mass[i],tanb) + 
		Give_XsecUnc_pdfalphas68up_bbA5f(mass[i],tanb)*Give_XsecUnc_pdfalphas68up_bbA5f(mass[i],tanb))) *
	  Give_BR_A_tautau(mass[i],tanb) +                        
	  (Give_XsecUnc_muup_ggFh(mass[i],tanb)+Give_XsecUnc_muup_bbh5f(mass[i],tanb) +
	   sqrt(Give_XsecUnc_pdfalphas68up_ggFh(mass[i],tanb)*Give_XsecUnc_pdfalphas68up_ggFh(mass[i],tanb) + 
		Give_XsecUnc_pdfalphas68up_bbh5f(mass[i],tanb)*Give_XsecUnc_pdfalphas68up_bbh5f(mass[i],tanb))) *
	  Give_BR_h_tautau(mass[i],tanb);                        

	xsect_x_Br_UncD = 
	  (Give_XsecUnc_mudown_ggFA(mass[i],tanb)+Give_XsecUnc_mudown_bbA5f(mass[i],tanb) -
	   sqrt(Give_XsecUnc_pdfalphas68down_ggFA(mass[i],tanb)*Give_XsecUnc_pdfalphas68down_ggFA(mass[i],tanb) + 
		Give_XsecUnc_pdfalphas68down_bbA5f(mass[i],tanb)*Give_XsecUnc_pdfalphas68down_bbA5f(mass[i],tanb))) *
	  Give_BR_A_tautau(mass[i],tanb) +                        
	  (Give_XsecUnc_mudown_ggFh(mass[i],tanb)+Give_XsecUnc_mudown_bbh5f(mass[i],tanb) -
	   sqrt(Give_XsecUnc_pdfalphas68down_ggFh(mass[i],tanb)*Give_XsecUnc_pdfalphas68down_ggFh(mass[i],tanb) + 
		Give_XsecUnc_pdfalphas68down_bbh5f(mass[i],tanb)*Give_XsecUnc_pdfalphas68down_bbh5f(mass[i],tanb))) *
	  Give_BR_h_tautau(mass[i],tanb);                        


	/* linear sum of PDF
	xsect_x_Br_UncU = 
	  (Give_XsecUnc_muup_ggFA(mass[i],tanb)+Give_XsecUnc_muup_bbA5f(mass[i],tanb) +
	   Give_XsecUnc_pdfalphas68up_ggFA(mass[i],tanb) + Give_XsecUnc_pdfalphas68up_bbA5f(mass[i],tanb)) *
	  Give_BR_A_tautau(mass[i],tanb) +                        
	  (Give_XsecUnc_muup_ggFh(mass[i],tanb)+Give_XsecUnc_muup_bbh5f(mass[i],tanb) +
	   Give_XsecUnc_pdfalphas68up_ggFh(mass[i],tanb) + Give_XsecUnc_pdfalphas68up_bbh5f(mass[i],tanb)) *
	  Give_BR_h_tautau(mass[i],tanb);                        

	xsect_x_Br_UncD = 
	  (Give_XsecUnc_mudown_ggFA(mass[i],tanb)+Give_XsecUnc_mudown_bbA5f(mass[i],tanb) +
	   Give_XsecUnc_pdfalphas68down_ggFA(mass[i],tanb) + Give_XsecUnc_pdfalphas68down_bbA5f(mass[i],tanb)) *
	  Give_BR_A_tautau(mass[i],tanb) +                        
	  (Give_XsecUnc_mudown_ggFh(mass[i],tanb)+Give_XsecUnc_mudown_bbh5f(mass[i],tanb) +
	   Give_XsecUnc_pdfalphas68down_ggFh(mass[i],tanb) + Give_XsecUnc_pdfalphas68down_bbh5f(mass[i],tanb)) *
	  Give_BR_h_tautau(mass[i],tanb);                        
	*/
      }
      
      if(mass[i] == 130.) {
	xsec_x_Br = 
	  (Give_Xsec_ggFA(mass[i],tanb)+Give_Xsec_bbA5f(mass[i],tanb))*Give_BR_A_tautau(mass[i],tanb) +
	  (Give_Xsec_ggFH(mass[i],tanb)+Give_Xsec_bbH5f(mass[i],tanb))*Give_BR_H_tautau(mass[i],tanb) +
	  (Give_Xsec_ggFh(mass[i],tanb)+Give_Xsec_bbh5f(mass[i],tanb))*Give_BR_h_tautau(mass[i],tanb);

	//  sum of PDF unce in quardature
	xsect_x_Br_UncU = 
	  (Give_XsecUnc_muup_ggFA(mass[i],tanb)+Give_XsecUnc_muup_bbA5f(mass[i],tanb) +
	   sqrt(Give_XsecUnc_pdfalphas68up_ggFA(mass[i],tanb)*Give_XsecUnc_pdfalphas68up_ggFA(mass[i],tanb) + 
		Give_XsecUnc_pdfalphas68up_bbA5f(mass[i],tanb)*Give_XsecUnc_pdfalphas68up_bbA5f(mass[i],tanb))) *
	  Give_BR_A_tautau(mass[i],tanb) +                        
	  (Give_XsecUnc_muup_ggFh(mass[i],tanb)+Give_XsecUnc_muup_bbh5f(mass[i],tanb) +
	   sqrt(Give_XsecUnc_pdfalphas68up_ggFh(mass[i],tanb)*Give_XsecUnc_pdfalphas68up_ggFh(mass[i],tanb) + 
		Give_XsecUnc_pdfalphas68up_bbh5f(mass[i],tanb)*Give_XsecUnc_pdfalphas68up_bbh5f(mass[i],tanb))) *
	  Give_BR_h_tautau(mass[i],tanb) +
	  (Give_XsecUnc_muup_ggFH(mass[i],tanb)+Give_XsecUnc_muup_bbH5f(mass[i],tanb) +
	   sqrt(Give_XsecUnc_pdfalphas68up_ggFH(mass[i],tanb)*Give_XsecUnc_pdfalphas68up_ggFH(mass[i],tanb) + 
		Give_XsecUnc_pdfalphas68up_bbH5f(mass[i],tanb)*Give_XsecUnc_pdfalphas68up_bbH5f(mass[i],tanb))) *
	  Give_BR_H_tautau(mass[i],tanb);                        
                        
	xsect_x_Br_UncD = 
	  (Give_XsecUnc_mudown_ggFA(mass[i],tanb)+Give_XsecUnc_mudown_bbA5f(mass[i],tanb) -
	   sqrt(Give_XsecUnc_pdfalphas68down_ggFA(mass[i],tanb)*Give_XsecUnc_pdfalphas68down_ggFA(mass[i],tanb) + 
		Give_XsecUnc_pdfalphas68down_bbA5f(mass[i],tanb)*Give_XsecUnc_pdfalphas68down_bbA5f(mass[i],tanb))) *
	  Give_BR_A_tautau(mass[i],tanb) +                        
	  (Give_XsecUnc_mudown_ggFh(mass[i],tanb)+Give_XsecUnc_mudown_bbh5f(mass[i],tanb) -
	   sqrt(Give_XsecUnc_pdfalphas68down_ggFh(mass[i],tanb)*Give_XsecUnc_pdfalphas68down_ggFh(mass[i],tanb) + 
		Give_XsecUnc_pdfalphas68down_bbh5f(mass[i],tanb)*Give_XsecUnc_pdfalphas68down_bbh5f(mass[i],tanb))) *
	  Give_BR_h_tautau(mass[i],tanb) +                        
	  (Give_XsecUnc_mudown_ggFH(mass[i],tanb)+Give_XsecUnc_mudown_bbH5f(mass[i],tanb) -
	   sqrt(Give_XsecUnc_pdfalphas68down_ggFH(mass[i],tanb)*Give_XsecUnc_pdfalphas68down_ggFH(mass[i],tanb) + 
		Give_XsecUnc_pdfalphas68down_bbH5f(mass[i],tanb)*Give_XsecUnc_pdfalphas68down_bbH5f(mass[i],tanb))) *
	  Give_BR_H_tautau(mass[i],tanb);                        

	/* PDF unce. are added linerly
	xsect_x_Br_UncU = 
	  (Give_XsecUnc_muup_ggFA(mass[i],tanb)+Give_XsecUnc_muup_bbA5f(mass[i],tanb) +
	   Give_XsecUnc_pdfalphas68up_ggFA(mass[i],tanb) + Give_XsecUnc_pdfalphas68up_bbA5f(mass[i],tanb)) *
	  Give_BR_A_tautau(mass[i],tanb) +                        
	  (Give_XsecUnc_muup_ggFH(mass[i],tanb)+Give_XsecUnc_muup_bbH5f(mass[i],tanb) +
	   Give_XsecUnc_pdfalphas68up_ggFH(mass[i],tanb) + Give_XsecUnc_pdfalphas68up_bbH5f(mass[i],tanb)) *
	  Give_BR_H_tautau(mass[i],tanb) +                        
	  (Give_XsecUnc_muup_ggFh(mass[i],tanb)+Give_XsecUnc_muup_bbh5f(mass[i],tanb) +
	   Give_XsecUnc_pdfalphas68up_ggFh(mass[i],tanb) + Give_XsecUnc_pdfalphas68up_bbh5f(mass[i],tanb)) *
	  Give_BR_h_tautau(mass[i],tanb);                        

	xsect_x_Br_UncD = 
	  (Give_XsecUnc_mudown_ggFA(mass[i],tanb)+Give_XsecUnc_mudown_bbA5f(mass[i],tanb) +
	   Give_XsecUnc_pdfalphas68down_ggFA(mass[i],tanb) + Give_XsecUnc_pdfalphas68down_bbA5f(mass[i],tanb)) *
	  Give_BR_A_tautau(mass[i],tanb) +                        
	  (Give_XsecUnc_mudown_ggFH(mass[i],tanb)+Give_XsecUnc_mudown_bbH5f(mass[i],tanb) +
	   Give_XsecUnc_pdfalphas68down_ggFH(mass[i],tanb) + Give_XsecUnc_pdfalphas68down_bbH5f(mass[i],tanb)) *
	  Give_BR_H_tautau(mass[i],tanb) +                        
	  (Give_XsecUnc_mudown_ggFh(mass[i],tanb)+Give_XsecUnc_mudown_bbh5f(mass[i],tanb) +
	   Give_XsecUnc_pdfalphas68down_ggFh(mass[i],tanb) + Give_XsecUnc_pdfalphas68down_bbh5f(mass[i],tanb)) *
	  Give_BR_h_tautau(mass[i],tanb);                        
	*/

      }
      
      if(mass[i] > 130) {
	xsec_x_Br = 
	  (Give_Xsec_ggFA(mass[i],tanb)+Give_Xsec_bbA5f(mass[i],tanb))*Give_BR_A_tautau(mass[i],tanb) +
	  (Give_Xsec_ggFH(mass[i],tanb)+Give_Xsec_bbH5f(mass[i],tanb))*Give_BR_H_tautau(mass[i],tanb);

	// PDF are added in quardature
	xsect_x_Br_UncU = 
	  (Give_XsecUnc_muup_ggFA(mass[i],tanb)+Give_XsecUnc_muup_bbA5f(mass[i],tanb) +
	   sqrt(Give_XsecUnc_pdfalphas68up_ggFA(mass[i],tanb)*Give_XsecUnc_pdfalphas68up_ggFA(mass[i],tanb) + 
		Give_XsecUnc_pdfalphas68up_bbA5f(mass[i],tanb)*Give_XsecUnc_pdfalphas68up_bbA5f(mass[i],tanb))) *
	  Give_BR_A_tautau(mass[i],tanb) +                        
	  (Give_XsecUnc_muup_ggFH(mass[i],tanb)+Give_XsecUnc_muup_bbH5f(mass[i],tanb) +
	   sqrt(Give_XsecUnc_pdfalphas68up_ggFH(mass[i],tanb)*Give_XsecUnc_pdfalphas68up_ggFH(mass[i],tanb) + 
		Give_XsecUnc_pdfalphas68up_bbH5f(mass[i],tanb)*Give_XsecUnc_pdfalphas68up_bbH5f(mass[i],tanb))) *
	  Give_BR_H_tautau(mass[i],tanb);                        

	xsect_x_Br_UncD = 
	  (Give_XsecUnc_mudown_ggFA(mass[i],tanb)+Give_XsecUnc_mudown_bbA5f(mass[i],tanb) -
	   sqrt(Give_XsecUnc_pdfalphas68down_ggFA(mass[i],tanb)*Give_XsecUnc_pdfalphas68down_ggFA(mass[i],tanb) + 
		Give_XsecUnc_pdfalphas68down_bbA5f(mass[i],tanb)*Give_XsecUnc_pdfalphas68down_bbA5f(mass[i],tanb))) *
	  Give_BR_A_tautau(mass[i],tanb) +                        
	  (Give_XsecUnc_mudown_ggFH(mass[i],tanb)+Give_XsecUnc_mudown_bbH5f(mass[i],tanb) -
	   sqrt(Give_XsecUnc_pdfalphas68down_ggFH(mass[i],tanb)*Give_XsecUnc_pdfalphas68down_ggFH(mass[i],tanb) + 
		Give_XsecUnc_pdfalphas68down_bbH5f(mass[i],tanb)*Give_XsecUnc_pdfalphas68down_bbH5f(mass[i],tanb))) *
	  Give_BR_H_tautau(mass[i],tanb);                        

	/* PDF are added linearly
	xsect_x_Br_UncU = 
	  (Give_XsecUnc_muup_ggFA(mass[i],tanb)+Give_XsecUnc_muup_bbA5f(mass[i],tanb) +
	   Give_XsecUnc_pdfalphas68up_ggFA(mass[i],tanb) + Give_XsecUnc_pdfalphas68up_bbA5f(mass[i],tanb)) *
	  Give_BR_A_tautau(mass[i],tanb) +                        
	  (Give_XsecUnc_muup_ggFH(mass[i],tanb)+Give_XsecUnc_muup_bbH5f(mass[i],tanb) +
	   Give_XsecUnc_pdfalphas68up_ggFH(mass[i],tanb) + Give_XsecUnc_pdfalphas68up_bbH5f(mass[i],tanb)) *
	  Give_BR_H_tautau(mass[i],tanb);                        

	xsect_x_Br_UncD = 
	  (Give_XsecUnc_mudown_ggFA(mass[i],tanb)+Give_XsecUnc_mudown_bbA5f(mass[i],tanb) +
	   Give_XsecUnc_pdfalphas68down_ggFA(mass[i],tanb) + Give_XsecUnc_pdfalphas68down_bbA5f(mass[i],tanb)) *
	  Give_BR_A_tautau(mass[i],tanb) +                        
	  (Give_XsecUnc_mudown_ggFH(mass[i],tanb)+Give_XsecUnc_mudown_bbH5f(mass[i],tanb) +
	   Give_XsecUnc_pdfalphas68down_ggFH(mass[i],tanb) + Give_XsecUnc_pdfalphas68down_bbH5f(mass[i],tanb)) *
	  Give_BR_H_tautau(mass[i],tanb);                        
	*/
      }

      Double_t xsec_x_Br_pb = xsec_x_Br * 0.001; 
      Double_t xsect_x_Br_UncU_pb = xsect_x_Br_UncU * 0.001;
      Double_t xsect_x_Br_UncD_pb = xsect_x_Br_UncD * 0.001; 

      /*
      cout << " MA = " << mass[i] 
	   <<" tanb = " << tanb 
	   <<" xsect x Br = " << xsec_x_Br_pb
	   <<" + " << xsect_x_Br_UncU_pb
	   <<" - " << xsect_x_Br_UncD_pb << endl;
      */	

      if(tanlow == 0) {
	if( (xsec_x_Br_pb + xsect_x_Br_UncU_pb)  > xsect_x_Br_limit[i]) {
	  tanb_exp_thu[i] = tanb;
	  if(mass[i] == 140.) {tanb_exp_thu[i] = tanb-1;}
	  if(mass[i] == 160.) {tanb_exp_thu[i] = tanb-1;}
	  std::cout<<" mass = "<< mass[i] <<" tanb low = "<< tanb_exp_thu[i] <<"  xsect x Br = " << xsec_x_Br_pb +  xsect_x_Br_UncU_pb
		   <<" limit = " << xsect_x_Br_limit[i] << std::endl;
	  tanlow = 1;
	}
      }

      if(tan == 0) {
	if( xsec_x_Br_pb > xsect_x_Br_limit[i]) {
	  tanb_exp[i] = tanb;
	  std::cout<<" mass = "<< mass[i] <<" tanb = "<< tanb_exp_thu[i] <<"  xsect x Br = " << xsec_x_Br_pb 
		   <<" limit = " << xsect_x_Br_limit[i] << std::endl;
	  tan = 1;
	}
      }

      if(tanhigh == 0) {
	if( (xsec_x_Br_pb + xsect_x_Br_UncD_pb)  > xsect_x_Br_limit[i]) {
	  tanb_exp_thd[i] = tanb;
	  std::cout<<" mass = "<< mass[i] <<" tanb high = "<< tanb_exp_thu[i] <<"  xsect x Br = " << xsec_x_Br_pb +  xsect_x_Br_UncD_pb
		   <<" limit = " << xsect_x_Br_limit[i] << std::endl;
          tanhigh = 1;
	}
      }

      // Adbel
      if(tanlow_abdel == 0) {
	if( (xsec_x_Br_abdel + xsect_x_Br_UncU_abdel)  > xsect_x_Br_limit[i]) {
	  //	  std::cout<<" Abdel: mass = "<< mass[i] <<" tanb low = "<< tanb <<"  xsect x Br = " << xsec_x_Br_abdel +  xsect_x_Br_UncU_abdel
	  //		   <<" limit = " << xsect_x_Br_limit[i] << std::endl;
	  tanb_exp_thu_abdel[i] = tanb_abdel;
	  tanlow_abdel = 1;
	}
      }

      if(tan_abdel == 0) {
	if( xsec_x_Br_abdel > xsect_x_Br_limit[i]) {
	  //	  std::cout<<" Abdel: mass = "<< mass[i] <<" tanb = "<< tanb_abdel <<"  xsect x Br = " << xsec_x_Br_abdel
	  //		   <<" limit = " << xsect_x_Br_limit[i] << std::endl;
	  tanb_exp_abdel[i] = tanb_abdel;
	  tan_abdel = 1;
	}
      }

      if(tanhigh_abdel == 0) {
	if( (xsec_x_Br_abdel + xsect_x_Br_UncD_abdel)  > xsect_x_Br_limit[i]) {
	  //	  std::cout<<" Abdel: mass = "<< mass[i] <<" tanb high = "<< tanb_abdel <<"  xsect x Br = " << xsec_x_Br_abdel +  xsect_x_Br_UncD_abdel
	  //		   <<" limit = " << xsect_x_Br_limit[i] << std::endl;
	  tanb_exp_thd_abdel[i] = tanb_abdel;
          tanhigh_abdel = 1;
	}
      }

      //
    }
  }

  setTDRStyle(0,0);
  // create graphs
  TCanvas* c1 = new TCanvas("X","Y",1);
  TGraph* gr_tanb_exp  = new TGraph(nbhmass,mass,tanb_exp);
  TGraph* gr_tanb_exp_thu  = new TGraph(nbhmass,mass,tanb_exp_thu);
  TGraph* gr_tanb_exp_thd  = new TGraph(nbhmass,mass,tanb_exp_thd);

  TGraph* gr_tanb_exp_abdel  = new TGraph(nbhmass,mass,tanb_exp_abdel);
  TGraph* gr_tanb_exp_thu_abdel  = new TGraph(nbhmass,mass,tanb_exp_thu_abdel);
  TGraph* gr_tanb_exp_thd_abdel  = new TGraph(nbhmass,mass,tanb_exp_thd_abdel);

  TAxis* xaxis = gr_tanb_exp->GetXaxis();
  TAxis* yaxis = gr_tanb_exp->GetYaxis();
  gr_tanb_exp->GetXaxis()->SetTitle("M_{A} (GeV)");
  gr_tanb_exp->GetYaxis()->SetTitle("tan #beta");
  gr_tanb_exp->GetXaxis()->CenterTitle();
  gr_tanb_exp->GetYaxis()->CenterTitle();
  xaxis->SetLimits(90.,350.);
  gr_tanb_exp->SetMarkerStyle(20);
  gr_tanb_exp->SetLineWidth(3);
  gr_tanb_exp->SetMaximum(55.);
  gr_tanb_exp->SetMinimum(5.);
  gr_tanb_exp->Draw("ALP");

  gr_tanb_exp_thu->SetMarkerStyle(22);
  gr_tanb_exp_thu->Draw("LP");
  gr_tanb_exp_thd->SetMarkerStyle(21);
  gr_tanb_exp_thd->Draw("LP");

  //  gr_tanb_exp_abdel->SetMarkerStyle(24);
  //  gr_tanb_exp_abdel->Draw("P");
  gr_tanb_exp_thu_abdel->SetMarkerStyle(26);
  gr_tanb_exp_thu_abdel->SetLineStyle(3);
  gr_tanb_exp_thu_abdel->Draw("LP");
  gr_tanb_exp_thd_abdel->SetLineStyle(3);
  gr_tanb_exp_thd_abdel->SetMarkerStyle(25);
  gr_tanb_exp_thd_abdel->Draw("LP");


  TLatex *t = new TLatex();
  t->SetTextSize(0.045);
  t->DrawLatex(150.,50,"CMS 36 pb^{-1}, 7 TeV");
  t->SetTextSize(0.042);
  t->DrawLatex(150.,45,"H #rightarrow #tau #tau, MSSM m_{h}^{max}");
  t->DrawLatex(130.,40,"Observed limit at 95 \% C.L.");

  TLegend *leg = new TLegend(0.6,0.15,0.9,0.45,NULL,"brNDC");
  leg->SetFillColor(10);
  leg->AddEntry(gr_tanb_exp,"no th. uncert.","LP");
  leg->AddEntry(gr_tanb_exp_thu,"  +#Delta _{1}^{theory}","LP");
  leg->AddEntry(gr_tanb_exp_thd,"  -#Delta _{1}^{theory}","LP");
  leg->AddEntry(gr_tanb_exp_thu_abdel,"  +#Delta _{2}^{theory}","LP");
  leg->AddEntry(gr_tanb_exp_thd_abdel,"  -#Delta _{2}^{theory}","LP");
  leg->Draw();  

  /*
  TLegend *leg_abdel = new TLegend(0.5,0.15,0.8,0.25,NULL,"brNDC");
  leg_abdel->SetFillColor(10);
  //  leg_abdel->AddEntry(gr_tanb_exp_abdel,"A.D.: no th. uncertainty","P");
  leg_abdel->AddEntry(gr_tanb_exp_thu_abdel,"+#Delta #sigma _{th}","LP");
  leg_abdel->AddEntry(gr_tanb_exp_thd_abdel,"-#Delta #sigma _{th}","LP");
  leg_abdel->Draw();  
  */

  c1->SaveAs("matanb.gif");
  c1->SaveAs("matanb.pdf");

}


