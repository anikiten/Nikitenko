#define nmssm_wh_4b_cxx
#include "nmssm_wh_4b.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

Double_t nmssm_wh_4b::deltaPhi(Double_t phi1, Double_t phi2)
{
  Double_t pi = 3.1415927;
  Double_t dphi = fabs(phi1 - phi2);
  if(dphi >= pi) dphi = 2. * pi - dphi; 
  return dphi;
}

Double_t nmssm_wh_4b::deltaEta(Double_t eta1, Double_t eta2)
{
  Double_t deta = fabs(eta1 - eta2);
  return deta;
}

Double_t nmssm_wh_4b::deltaR(Double_t eta1, Double_t phi1, Double_t eta2, Double_t phi2)
{
  Double_t deta = deltaEta(eta1, eta2);
  Double_t dphi = deltaPhi(phi1, phi2);
  Double_t dr = sqrt(deta*deta + dphi*dphi);
  return dr;
}

void nmssm_wh_4b::Loop()
{
//   In a ROOT session, you can do:
//      Root > .L nmssm_wh_4b.C
//      Root > nmssm_wh_4b t
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

   Long64_t nbytes = 0, nb = 0;

   TH1F * hptl  = new TH1F( "hptl", "ptl", 20, 0., 100.);
   TH1F * hetal = new TH1F( "hetal", "etal", 50, -5.0, 5.0);

   TH1F * hptb   = new TH1F( "hptb", "ptb", 20, 0., 100.);
   TH1F * hetab  = new TH1F( "hetab", "etab", 50, -5.0, 5.0);

   TH1F * hdrlbmin  = new TH1F( "hdrlbmin", "drlbmin", 25, 0., 5.0);

   TH1F * hdrb1b2   = new TH1F( "hdrb1b2", "drb1b2", 25, 0., 5.0);
   TH1F * hdrb1b3   = new TH1F( "hdrb1b3", "drb1b3", 25, 0., 5.0);
   TH1F * hdrb1b4   = new TH1F( "hdrb1b4", "drb1b4", 25, 0., 5.0);
   TH1F * hdrb2b3   = new TH1F( "hdrb2b3", "drb2b3", 25, 0., 5.0);
   TH1F * hdrb2b4   = new TH1F( "hdrb2b4", "drb2b4", 25, 0., 5.0);
   TH1F * hdrb3b4   = new TH1F( "hdrb3b4", "drb3b4", 25, 0., 5.0);

   //   TH2F * hdsbj   = new TH2F( "hhdsbj", "hdsbj", 7, 0., 7., 7, 0., 7.);

   TH1F * hdsbj   = new TH1F( "hdsbj", "hdsbj", 8, 0., 8.);

   int ntot     = 0;
   int lpteta   = 0;
   int bpteta   = 0;
   int drlb     = 0;

   double di_b_jet = 0.;
   double single_b_jet = 0.;

   vector<int> twobjet1stindex;
   vector<int> twobjet2ndindex;
   vector<int> singlebindex;
   vector<double> drpair;

   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      
      ntot += 1;

      // select pt/eta lepton
      if(ptl < 20. || fabs(etal) > 2.4) {continue;}
      lpteta += 1;

      hptl->Fill(ptl);
      hetal->Fill(etal);

      Double_t drb1b2 = deltaR((*etab)[0],(*phib)[0],(*etab)[1],(*phib)[1]);
      Double_t drb1b3 = deltaR((*etab)[0],(*phib)[0],(*etab)[2],(*phib)[2]);
      Double_t drb1b4 = deltaR((*etab)[0],(*phib)[0],(*etab)[3],(*phib)[3]);
      Double_t drb2b3 = deltaR((*etab)[1],(*phib)[1],(*etab)[2],(*phib)[2]);
      Double_t drb2b4 = deltaR((*etab)[1],(*phib)[1],(*etab)[3],(*phib)[3]);
      Double_t drb3b4 = deltaR((*etab)[2],(*phib)[2],(*etab)[3],(*phib)[3]);

      hdrb1b2->Fill(drb1b2);
      hdrb1b3->Fill(drb1b3);
      hdrb1b4->Fill(drb1b4);
      hdrb2b3->Fill(drb2b3);
      hdrb2b4->Fill(drb2b4);
      hdrb3b4->Fill(drb3b4);
      
      twobjet1stindex.clear();
      twobjet2ndindex.clear();
      singlebindex.clear();

      Int_t ndbj = 0;
      Int_t nbj = ptb->size();
      for (unsigned int i = 0; i < nbj-1; i++) {
	for (unsigned int j = i+1; j < nbj; j++) {
	  Double_t dr = deltaR((*etab)[i],(*phib)[i],(*etab)[j],(*phib)[j]);
	  if(dr < 0.5) 
	    {
	      twobjet1stindex.push_back(i);
	      twobjet2ndindex.push_back(j);
	      drpair.push_back(dr);	      
	      //	      cout <<"  dr = " << dr 
	      //		   <<" i = " << i 
	      //		   <<" j = " << j << endl;
	    }
	}
      }

      Int_t ndbj = twobjet1stindex.size();

      for (unsigned int i = 0; i < nbj; i++) {
	Int_t sj = 1;
	for (unsigned int i2 = 0; i2 < ndbj; i2++) {
	  if(i == twobjet1stindex[i2] || i == twobjet2ndindex[i2]) {sj = 0;}
	}
	if(sj == 1) {singlebindex.push_back(i);}
      }

      Int_t nsbj = singlebindex.size();
      
      if(nsbj == 4 ) {

	cout <<" " << endl;
	cout <<" ==> Next event nsbj = " << nsbj <<" ndbj = " << ndbj << endl;

	for (unsigned int i = 0; i < nsbj; i++) {
	  cout <<"          singlebindex j = " << singlebindex[i] << endl;
	}

	for (unsigned int i = 0; i < ndbj; i++) {
	  cout <<" pair ij =" << twobjet1stindex[i]
	       <<" " << twobjet2ndindex[i] 
	       <<" dr = " << drpair[i] << endl;
	}
      }

      hdsbj->Fill(1.*nsbj);

      // select pt/eta b  
      int b_in_acc = 1;
      for (unsigned int j = 0; j < nbj; j++) {
	if( (*ptb)[j] < 20 || fabs((*etab)[j]) > 2.4) {b_in_acc = 0;}
      }
      if(b_in_acc == 0) {continue;}
      bpteta += 1;

      for (unsigned int j = 0; j < nbj; j++) {
	hptb->Fill((*ptb)[j]);
	hetab->Fill((*etab)[j]);
      }

      // DR l-b > 0.5
      Double_t drlb_min = 1000.;
      for (unsigned int j = 0; j < nbj; j++) {
	Double_t dr = deltaR((*etab)[j],(*phib)[j],etal,phil);
	if(dr < drlb_min) {
	  drlb_min = dr;
	}
      }

      if(drlb_min < 0.5) {continue;}
      drlb += 1;
      hdrlbmin->Fill(drlb_min);

      // if (Cut(ientry) < 0) continue;
   }

   cout <<"  ========= Selections =========== " << endl;
   cout <<" nton = " << ntot << endl;
   cout <<" lpteta = " << lpteta << endl;
   cout <<" bpteta = " << bpteta << endl;
   cout <<" drlb = " << drlb << endl;
     

   //TFile efile("nmssm_wh_4b_mh60_histos.root","recreate");
   TFile efile("nmssm_wh_4b_mh20_histos.root","recreate");

   hptl->Write();
   hetal->Write();

   hptb->Write();
   hetab->Write();

   hdrlbmin->Write();

   hdrb1b2->Write();
   hdrb1b3->Write();
   hdrb1b4->Write();
   hdrb2b3->Write();
   hdrb2b4->Write();
   hdrb3b4->Write();

   hdsbj->Write();

   efile.Close();
}
