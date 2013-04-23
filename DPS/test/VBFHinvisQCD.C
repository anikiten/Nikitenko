#define VBFHinvisQCD_cxx
#include "VBFHinvisQCD.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

Double_t VBFHinvisQCD::deltaPhi(Double_t phi1, Double_t phi2)
{
  Double_t pi = 3.1415927;
  Double_t dphi = fabs(phi1 - phi2);
  if(dphi >= pi) dphi = 2. * pi - dphi; 
  return dphi;
}

Double_t VBFHinvisQCD::deltaEta(Double_t eta1, Double_t eta2)
{
  Double_t deta = fabs(eta1 - eta2);
  return deta;
}

Double_t VBFHinvisQCD::deltaR(Double_t eta1, Double_t phi1, Double_t eta2, Double_t phi2)
{
  Double_t deta = deltaEta(eta1, eta2);
  Double_t dphi = deltaPhi(phi1, phi2);
  Double_t dr = sqrt(deta*deta + dphi*dphi);
  return dr;
}

void VBFHinvisQCD::Loop()
{
//   In a ROOT session, you can do:
//      Root > .L VBFHinvisQCD.C
//      Root > VBFHinvisQCD t
//      Root > t.GetEntry(12); // Fill t data members with entry number 12
//      Root > t.Show();       // Show values of entry 12
//      Root > t.Show(16);     // Read and show values of entry 16
//      Root > t.Loop();       // Loop on all entries
//

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

   // selections

   TH1F * hEtaJPU   = new TH1F( "hEtaJPU", "EtaJPU", 50, -5.0, 5.0);
   TH1F * hDphiJJPU = new TH1F( "hDphiJJPU", "DphiJJPU", 17, 0., 3.4);

   TH1F * hPtJ1   = new TH1F( "hPtJ1", "PtJ1", 60, 0., 300.);
   TH1F * hPtJ2   = new TH1F( "hPtJ2", "PtJ2", 60, 0., 300.);
   TH1F * hEtaJ   = new TH1F( "hEtaJ", "EtaJ", 50, -5.0, 5.0);

   TH2F * hDetaJJmJJ = new TH2F( "hDetaJJmJJ", "DetaJJmJJ", 50, 0., 10.,40,0.,2000.);
   TH1F * hmJJ    = new TH1F( "hmJJ", "mJJ", 40, 0., 2000.);
   TH1F * hDetaJJ = new TH1F( "hDetaJJ", "DetaJJ", 50, 0., 10.);

   TH1F * hDphiJJ        = new TH1F( "hDphiJJ", "DphiJJ", 17, 0., 3.4);
   //
   TH1F * hDphiJJmJJ300  = new TH1F( "hDphiJJmJJ300", "DphiJJmJJ300", 17, 0., 3.4);
   TH1F * hDphiJJmJJ500  = new TH1F( "hDphiJJmJJ500", "DphiJJmJJ500", 17, 0., 3.4);
   TH1F * hDphiJJmJJ800  = new TH1F( "hDphiJJmJJ800", "DphiJJmJJ800", 17, 0., 3.4);
   //
   TH1F * hDphiJJDetaJJ2 = new TH1F( "hDphiJJDetaJJ2", "DphiJJDetaJJ2", 17, 0., 3.4);
   TH1F * hDphiJJDetaJJ3 = new TH1F( "hDphiJJDetaJJ3", "DphiJJDetaJJ3", 17, 0., 3.4);
   TH1F * hDphiJJDetaJJ4 = new TH1F( "hDphiJJDetaJJ4", "DphiJJDetaJJ4", 17, 0., 3.4);
   //
   TH1F * hDphiJJmJJ300DetaJJ2   = new TH1F( "hDphiJJmJJ300DetaJJ2", 
                                             "DphiJJmJJ300DetaJJ2", 17, 0., 3.4);
   TH1F * hDphiJJmJJ800DetaJJ4   = new TH1F( "hDphiJJmJJ800DetaJJ4", 
                                             "DphiJJmJJ800DetaJJ4", 17, 0., 3.4);
   // for r measuremet

   TH1F * hDphiJJmJJ1200DetaJJ42 = new TH1F( "hDphiJJmJJ1200DetaJJ42", 
                                             "DphiJJmJJ1200DetaJJ42", 17, 0., 3.4);

   Float_t xbins[11]={0.,10.,20.,30.,40.,50.,60.,70.,80.,100.,120};
   TH1F * hPfMetDphiJJSData = new TH1F("hPfMetDphiJJSData","PfMetDphiJJSData",10,xbins); 
   TH1F * hPfMetDphiJJBData = new TH1F("hPfMetDphiJJBData","PfMetDphiJJBData",10,xbins);

   TH1F * hDphiJJmJJ1200DetaJJ42MET020 = new TH1F( "hDphiJJmJJ1200DetaJJ42MET020", 
                                             "DphiJJmJJ1200DetaJJ42MET020", 17, 0., 3.4);

   TH1F * hDphiJJmJJ1200DetaJJ42MET2030 = new TH1F( "hDphiJJmJJ1200DetaJJ42MET2030", 
                                             "DphiJJmJJ1200DetaJJ42MET2030", 17, 0., 3.4);

   TH1F * hDphiJJmJJ1200DetaJJ42MET3040 = new TH1F( "hDphiJJmJJ1200DetaJJ42MET3040", 
                                             "DphiJJmJJ1200DetaJJ42MET3040", 17, 0., 3.4);

   TH1F * hDphiJJmJJ1200DetaJJ42MET4050 = new TH1F( "hDphiJJmJJ1200DetaJJ42MET4050", 
                                             "DphiJJmJJ1200DetaJJ42MET4050", 17, 0., 3.4);

   TH1F * hDphiJJmJJ1200DetaJJ42MET5060 = new TH1F( "hDphiJJmJJ1200DetaJJ42MET5060", 
                                             "DphiJJmJJ1200DetaJJ42MET5060", 17, 0., 3.4);

   TH1F * hDphiJJmJJ1200DetaJJ42MET6070 = new TH1F( "hDphiJJmJJ1200DetaJJ42MET6070", 
                                             "DphiJJmJJ1200DetaJJ42MET6070", 17, 0., 3.4);

   TH1F * hDphiJJmJJ1200DetaJJ42MET7080 = new TH1F( "hDphiJJmJJ1200DetaJJ42MET7080", 
                                             "DphiJJmJJ1200DetaJJ42MET7080", 17, 0., 3.4);

   TH1F * hDphiJJmJJ1200DetaJJ42MET80100 = new TH1F( "hDphiJJmJJ1200DetaJJ42MET80100", 
                                             "DphiJJmJJ1200DetaJJ42MET80100", 17, 0., 3.4);

   TH1F * hDphiJJmJJ1200DetaJJ42MET100120 = new TH1F( "hDphiJJmJJ1200DetaJJ42MET100120", 
                                             "DphiJJmJJ1200DetaJJ42MET100120", 17, 0., 3.4);


   TH1F * hDphiJJmJJ1200DetaJJ42MET70 = new TH1F( "hDphiJJmJJ1200DetaJJ42MET70", 
                                             "DphiJJmJJ1200DetaJJ42MET70", 17, 0., 3.4);

   TH1F * hDphiJJmJJ900DetaJJ42 = new TH1F( "hDphiJJmJJ900DetaJJ42", 
                                             "DphiJJmJJ900DetaJJ42", 17, 0., 3.4);
   TH1F * hDphiJJmJJ900DetaJJ42MET70 = new TH1F( "hDphiJJmJJ900DetaJJ42MET70", 
                                             "DphiJJmJJ900DetaJJ42MET70", 17, 0., 3.4);

   //

   TH1F * hPFMET1                = new TH1F( "hPFMET1", "PFMET1", 60, 0., 300.);
   TH1F * hPFMET1mJJ300DetaJJ2   = new TH1F( "hPFMET1mJJ300DetaJJ2", 
					       "PFMET1mJJ300DetaJJ2", 60, 0., 300.);
   TH1F * hPFMET1mJJ800DetaJJ4   = new TH1F( "hPFMET1mJJ800DetaJJ4", 
						 "PFMET1mJJ800DetaJJ4", 60, 0., 300.);
   TH1F * hPFMET1mJJ1200DetaJJ42 = new TH1F( "hPFMET1mJJ1200DetaJJ42", 
						 "PFMET1mJJ1200DetaJJ42", 60, 0., 300.);
   TH1F * hPFMET1mJJ900DetaJJ42 = new TH1F( "hPFMET1mJJ900DetaJJ42", 
						 "PFMET1mJJ900DetaJJ42", 60, 0., 300.);
   Long64_t nentries = fChain->GetEntriesFast();
   Long64_t nbytes = 0, nb = 0;

   Int_t ntot = 0;
   Int_t HLT          = 0;
   Int_t met_cleaning = 0;
   Int_t Zmumu        = 0;
   Int_t muonveto     = 0;
   Int_t elecveto     = 0;
   Int_t twojets      = 0;
   Int_t puremove     = 0;
   Int_t eta1eta2     = 0;
   Int_t detaj1j2     = 0;
   Int_t mj1j2        = 0;
   Int_t metcut       = 0;
   Int_t dphij1j2_s   = 0;
   Int_t dphij1j2_b   = 0;

   FILE *Out1 = fopen("events.txt", "w+");

   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      //      break;
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;

      // if (Cut(ientry) < 0) continue;

      //      cout <<" run number = " << run << endl;

      ntot = ntot + 1;
      //
      // *** HLT
      if( (run == 205193 && event == 192024878) ||
	  (run == 207492 && event == 153309740) ||
	  (run == 205666 && event == 61762276)  ||
	  (run == 206208 && event == 375087728) ||
	  (run == 206940 && event == 233232689) ||
	  (run == 207214 && event == 388384248) ) {
	cout <<" ----> new event " << endl;
	cout <<" run = " << run <<" event = " << event <<" before TRG " << endl;
      }
      if(VBF_AllJets != 1) {continue;}
      HLT += 1;
      //
      // *** MET filters

      if( (run == 205193 && event == 192024878) ||
	  (run == 207492 && event == 153309740) ||
	  (run == 205666 && event == 61762276)  ||
	  (run == 206208 && event == 375087728) ||
	  (run == 206940 && event == 233232689) ||
	  (run == 207214 && event == 388384248) ) {
	cout <<" run = " << run <<" event = " << event <<" before MET " << endl;
      }
      if( (f1 != 1) || (f2 != 1) || (f3 != 1) || (f4 != 1) || (f5 != 1) ) {continue;}
      met_cleaning += 1;
      //
      // *** muon veto
      Int_t nmu = PtMu->size();
      Int_t nloosemu = 0;
      for (unsigned int j = 0; j < nmu; j++) {
	if( (*muid)[j] >= 2 && (*mupfisol)[j]/(*PtMu)[j] < 0.2 && fabs((*EtaMu)[j]) < 2.1) 
	  {nloosemu += 1;}
	    //	    (*mutrkisol)[j]/(*PtMu)[j] < 0.1) {nloosemu += 1;}
      }
      if( (run == 205193 && event == 192024878) ||
	  (run == 207492 && event == 153309740) ||
	  (run == 205666 && event == 61762276)  ||
	  (run == 206208 && event == 375087728) ||
	  (run == 206940 && event == 233232689) ||
	  (run == 207214 && event == 388384248) ) {
	cout <<" run = " << run <<" event = " << event <<" before mu veto " << endl;
      }
      if( nloosemu != 0) {continue;}
      muonveto += 1;
      //
      // *** electron veto
      if( (run == 205193 && event == 192024878) ||
	  (run == 207492 && event == 153309740) ||
	  (run == 205666 && event == 61762276)  ||
	  (run == 206208 && event == 375087728) ||
	  (run == 206940 && event == 233232689) ||
	  (run == 207214 && event == 388384248) ) {
	cout <<" run = " << run <<" event = " << event <<" before el veto " << endl;
      }
      Int_t nel = PtEl->size();
      Int_t nlooseel = 0;
      for (unsigned int j = 0; j < nel; j++) {
	if( (*elid)[j] >= 1 && fabs((*EtaEl)[j]) < 2.5) {nlooseel += 1;}
      }
      if( nlooseel != 0) {continue;}
      elecveto += 1;

      // jets
      vector<double> ptjet;
      vector<double> etajet;
      vector<double> phijet;
      vector<int> jetpuid;
      Int_t njets = EtPF->size();
      for(unsigned int j = 0; j < njets; j++) {
	Int_t jtype   = (*JTypePF)[j];
	if(jtype > 0) {
	  Int_t jetlept_match = 0;
	  // check DR with loose muons
	  Int_t nlept = PtMu->size();
	  for(unsigned int l = 0; l < nlept; l++) {
	    Double_t DR = deltaR((*EtaPF)[j],(*PhiPF)[j],(*EtaMu)[l],(*PhiMu)[l]);
	    if(DR < 0.5) {jetlept_match = 1;}
	  }
	  // check DR with veto electrons
	  nlept = PtEl->size();
	  for(unsigned int l = 0; l < nlept; l++) {
	    Double_t DR = deltaR((*EtaPF)[j],(*PhiPF)[j],(*EtaEl)[l],(*PhiEl)[l]);
	    if (DR < 0.5) {jetlept_match = 1;}
	  }
	  if(jetlept_match == 0) {
	    ptjet.push_back((*EtPF)[j]);
	    etajet.push_back((*EtaPF)[j]);
	    phijet.push_back((*PhiPF)[j]);
	    jetpuid.push_back((*JTypePF)[j]);
	  }
	}
      }

      // jets
      njets = ptjet.size();
      /*
      // exist in my ntpl but not in V10
      if(run == 203894 && event == 1003932495) {
	cout <<"  Passed my sel. by not  V10 selections" 
	     <<" run = " << run
	     <<" event = " << event << endl;
	for(unsigned int j = 0; j < njets; j++) {
	  cout <<" j = " << j
	       <<"  ptj = " << ptjet[j]
	       <<"  etaj = " << etajet[j]
	       <<"  phij = " << phijet[j] << endl;
	}
	//	fprintf(Out1,"%d %d %d\n",run, event, njets);
	//	fprintf(Out1,"%d %d %.1f %.1f %.1f %.1f %d %d\n",
	//	run, event, ptjet[0], ptjet[1], etajet[0],etajet[1], jetpuid[0], jetpuid[1]);
      }
      // exist in V10, but not in my ntpl
      if(run == 203894 && event == 1000862781) {
	cout <<"  Passed V10 sel. but not my selections" 
	     <<" run = " << run
	     <<" event = " << event << endl;
	for(unsigned int j = 0; j < njets; j++) {
	  cout <<" j = " << j
	       <<"  ptj = " << ptjet[j]
	       <<"  etaj = " << etajet[j]
	       <<"  phij = " << phijet[j] << endl;
	}
	//	fprintf(Out1,"%d %d %d\n",run, event, njets);
	//	fprintf(Out1,"%d %d %.1f %.1f %.1f %.1f %d %d\n",
	//	run, event, ptjet[0], ptjet[1], etajet[0],etajet[1], jetpuid[0], jetpuid[1]);
      }
      */
      if( (run == 205193 && event == 192024878) ||
	  (run == 207492 && event == 153309740) ||
	  (run == 205666 && event == 61762276)  ||
	  (run == 206208 && event == 375087728) ||
	  (run == 206940 && event == 233232689) ||
	  (run == 207214 && event == 388384248) ) {
	cout <<" run = " << run <<" event = " << event <<" before jets " << endl;
      }
      if(njets < 2) {continue;}

      //      Int_t j1type   = (*JTypePF)[0];
      //      Int_t j2type   = (*JTypePF)[1];

      // tagging kinematics selections
      if(ptjet[0] <= 50. || ptjet[1] <= 50.) {continue;}
      if(fabs(etajet[0]) >= 4.7 || fabs(etajet[1]) >= 4.7) {continue;}
      //
      // *** two jets
      twojets += 1;

      if(jetpuid[0] == 0 || jetpuid[1] == 0) {continue;}
      puremove += 1;

      Double_t DphiJJ = deltaPhi(phijet[0],phijet[1]);
      Double_t DetaJJ = deltaEta(etajet[0],etajet[1]);

      hEtaJPU->Fill(etajet[0]); 
      hEtaJPU->Fill(etajet[1]); 
      hDphiJJPU->Fill(DphiJJ);
      
      // Mj1j2 calculations
      Double_t PJ1x = ptjet[0] * cos(phijet[0]); 
      Double_t PJ1y = ptjet[0] * sin(phijet[0]);
      Double_t Eta  = etajet[0];
      Double_t theta = 2. * atan(exp(-Eta));
      Double_t PJ1z = ptjet[0] / tan(theta);
      Double_t EJ1  = ptjet[0] / sin(theta);

      Double_t PJ2x = ptjet[1] * cos(phijet[1]); 
      Double_t PJ2y = ptjet[1] * sin(phijet[1]);
      Eta = etajet[1];
      theta = 2. * atan(exp(-Eta));
      Double_t PJ2z = ptjet[1] / tan(theta);
      Double_t EJ2  = ptjet[1] / sin(theta);
      Double_t mJJ  = sqrt( (EJ1+EJ2)*(EJ1+EJ2) 
                           - (PJ1x+PJ2x)*(PJ1x+PJ2x) 
                           - (PJ1y+PJ2y)*(PJ1y+PJ2y) 
			   - (PJ1z+PJ2z)*(PJ1z+PJ2z) ); 
      hPtJ1->Fill(ptjet[0]);
      hPtJ2->Fill(ptjet[1]);
      hEtaJ->Fill(etajet[0]); 
      hEtaJ->Fill(etajet[1]); 
      
      hDetaJJmJJ->Fill(DetaJJ,mJJ);

      if(mJJ > 300.)   {hDphiJJmJJ300->Fill(DphiJJ);}
      if(mJJ > 500.)   {hDphiJJmJJ500->Fill(DphiJJ);}
      if(mJJ > 800.)   {hDphiJJmJJ800->Fill(DphiJJ);}
      
      if(DetaJJ > 2.0) {hDphiJJDetaJJ2->Fill(DphiJJ);}
      if(DetaJJ > 3.0) {hDphiJJDetaJJ3->Fill(DphiJJ);}
      if(DetaJJ > 4.0) {hDphiJJDetaJJ4->Fill(DphiJJ);}
      
      if( (mJJ >  300.) && (DetaJJ > 2.0) ) {
	hDphiJJmJJ300DetaJJ2->Fill(DphiJJ);
	hPFMET1mJJ300DetaJJ2->Fill(pfmetType1);
      }
      if( (mJJ >  800.) && (DetaJJ > 4.0) ) {
	hDphiJJmJJ800DetaJJ4->Fill(DphiJJ);
	hPFMET1mJJ800DetaJJ4->Fill(pfmetType1);
      }
      if( (mJJ > 1200.) && (DetaJJ > 4.2) && etajet[0]*etajet[1] < 0 ) {
   
	if(DphiJJ < 1.0) {
	  hPfMetDphiJJSData->Fill(pfmetType1);
	}

	if(DphiJJ > 2.6) {
	  hPfMetDphiJJBData->Fill(pfmetType1);
	}

	hDphiJJmJJ1200DetaJJ42->Fill(DphiJJ);
	hPFMET1mJJ1200DetaJJ42->Fill(pfmetType1);

	if(pfmetType1 >  0. && pfmetType1 <= 20.) {hDphiJJmJJ1200DetaJJ42MET020->Fill(DphiJJ);}
	if(pfmetType1 > 20. && pfmetType1 <= 30.) {hDphiJJmJJ1200DetaJJ42MET2030->Fill(DphiJJ);}
	if(pfmetType1 > 30. && pfmetType1 <= 40.) {hDphiJJmJJ1200DetaJJ42MET3040->Fill(DphiJJ);}
	if(pfmetType1 > 40. && pfmetType1 <= 50.) {hDphiJJmJJ1200DetaJJ42MET4050->Fill(DphiJJ);}
	if(pfmetType1 > 50. && pfmetType1 <= 60.) {hDphiJJmJJ1200DetaJJ42MET5060->Fill(DphiJJ);}
	if(pfmetType1 > 60. && pfmetType1 <= 70.) {hDphiJJmJJ1200DetaJJ42MET6070->Fill(DphiJJ);}
	if(pfmetType1 > 70. && pfmetType1 <= 80.) {hDphiJJmJJ1200DetaJJ42MET7080->Fill(DphiJJ);}
	if(pfmetType1 > 80. && pfmetType1 <= 100.) {hDphiJJmJJ1200DetaJJ42MET80100->Fill(DphiJJ);}
	if(pfmetType1 > 100. && pfmetType1 <= 120.) {hDphiJJmJJ1200DetaJJ42MET100120->Fill(DphiJJ);}

	if(pfmetType1 > 70.) {hDphiJJmJJ1200DetaJJ42MET70->Fill(DphiJJ);}

      }  
      if( (mJJ > 900.) && (DetaJJ > 4.2) ) {
	hDphiJJmJJ900DetaJJ42->Fill(DphiJJ);
	hPFMET1mJJ900DetaJJ42->Fill(pfmetType1);
	if(pfmetType1 > 70.) {hDphiJJmJJ900DetaJJ42MET70->Fill(DphiJJ);}
      }  
      //
      if( (run == 205193 && event == 192024878) ||
	  (run == 207492 && event == 153309740) ||
	  (run == 205666 && event == 61762276)  ||
	  (run == 206208 && event == 375087728) ||
	  (run == 206940 && event == 233232689) ||
	  (run == 207214 && event == 388384248) ) {
	cout <<" run = " << run <<" event = " << event <<" before etaj1 x etaj2" << endl;
      }
      // *** etaj1 x etaj2 < 0
      if( etajet[0]*etajet[1] >= 0) {continue;}
      eta1eta2 += 1;

      
      //      fprintf(Out1,"%d %d\n",run, event);

      //
      if( (run == 205193 && event == 192024878) ||
	  (run == 207492 && event == 153309740) ||
	  (run == 205666 && event == 61762276)  ||
	  (run == 206208 && event == 375087728) ||
	  (run == 206940 && event == 233232689) ||
	  (run == 207214 && event == 388384248) ) {
	cout <<" run = " << run <<" event = " << event <<" before DetaJJ" << endl;
      }
      // *** Detaj1j2 > 4.2
      if(DetaJJ < 4.2) {continue;}
      detaj1j2 += 1;
      // 
      // *** MET
      if( (run == 205193 && event == 192024878) ||
	  (run == 207492 && event == 153309740) ||
	  (run == 205666 && event == 61762276)  ||
	  (run == 206208 && event == 375087728) ||
	  (run == 206940 && event == 233232689) ||
	  (run == 207214 && event == 388384248) ) {
	cout <<" run = " << run <<" event = " << event <<" before MET"  << endl;
      }
      if(pfmetType1 < 130) {continue;}
      metcut += 1;
      // *** mJJ
      if( (run == 205193 && event == 192024878) ||
	  (run == 207492 && event == 153309740) ||
	  (run == 205666 && event == 61762276)  ||
	  (run == 206208 && event == 375087728) ||
	  (run == 206940 && event == 233232689) ||
	  (run == 207214 && event == 388384248) ) {
	cout <<" run = " << run <<" event = " << event <<" before Mjj" 
	     <<" mJJ = " << mJJ << endl;
	for(unsigned int j = 0; j < njets; j++) {
	  cout <<"  ===> j = " << j
	       <<"  ptj = " << ptjet[j]
	       <<"  etaj = " << etajet[j]
	       <<"  phij = " << phijet[j] << endl;
	}
      }
      if(mJJ < 1200.) {continue;}
      mj1j2 += 1;
      // 
      // *** Dphi 
      if( (run == 205193 && event == 192024878) ||
	  (run == 207492 && event == 153309740) ||
	  (run == 205666 && event == 61762276)  ||
	  (run == 206208 && event == 375087728) ||
	  (run == 206940 && event == 233232689) ||
	  (run == 207214 && event == 388384248) ) {
	cout <<" run = " << run <<" event = " << event <<" before Dphijj" << endl;
      }
      if(DphiJJ > 2.6) {
	dphij1j2_b += 1;
	hmJJ->Fill(mJJ);
	hDetaJJ->Fill(DetaJJ);
	hPFMET1->Fill(pfmetType1);
	hDphiJJ->Fill(DphiJJ);
	fprintf(Out1,"%d %d\n",run, event);
      }
      if(DphiJJ < 1.0) {
	dphij1j2_s += 1;
      }
   }

   cout <<" ntot = " << ntot << endl;
   cout <<" HLT = " << HLT << endl;
   cout <<" met_cleaning = " << met_cleaning << endl;
   cout <<" muonveto = " << muonveto << endl;
   cout <<" elecveto = " << elecveto << endl;
   cout <<" twojets pT > 50 GeV, eta < 4.7 = " << twojets << endl;
   cout <<" puremove  = " << puremove << endl;
   cout <<" eta1eta2 < 0 = " << eta1eta2 << endl;
   cout <<" detaj1j2 > 4.2 = " << detaj1j2 << endl;
   cout <<" met > 130 GeV = " << metcut << endl;   
   cout <<" mj1j2 > 1200 GeV = " << mj1j2 << endl;   
   cout <<" dphij1j2_b > 2.6 = " << dphij1j2_b << endl; 
   cout <<" dphij1j2_s < 1.0 = " << dphij1j2_s << endl; 

   TFile efile("VBFHinvisQCDAnalysis.root","recreate");

   hEtaJPU->Write();
   hDphiJJPU->Write();

   hPtJ1->Write();
   hPtJ2->Write();
   hEtaJ->Write();

   hmJJ->Write();
   hDetaJJ->Write();
   hDetaJJmJJ->Write();

   hDphiJJ->Write();

   //
   hDphiJJmJJ300->Write();
   hDphiJJmJJ500->Write();
   hDphiJJmJJ800->Write();
   //
   hDphiJJDetaJJ2->Write();
   hDphiJJDetaJJ3->Write();
   hDphiJJDetaJJ4->Write();
   //
   hDphiJJmJJ300DetaJJ2->Write();
   hDphiJJmJJ800DetaJJ4->Write();  
   hDphiJJmJJ1200DetaJJ42->Write();

   hPfMetDphiJJSData->Write();
   hPfMetDphiJJBData->Write();

   hDphiJJmJJ1200DetaJJ42MET020->Write();
   hDphiJJmJJ1200DetaJJ42MET2030->Write();
   hDphiJJmJJ1200DetaJJ42MET3040->Write();
   hDphiJJmJJ1200DetaJJ42MET4050->Write();
   hDphiJJmJJ1200DetaJJ42MET5060->Write();
   hDphiJJmJJ1200DetaJJ42MET6070->Write();
   hDphiJJmJJ1200DetaJJ42MET7080->Write();
   hDphiJJmJJ1200DetaJJ42MET80100->Write();
   hDphiJJmJJ1200DetaJJ42MET100120->Write();

   hDphiJJmJJ1200DetaJJ42MET70->Write();

   hDphiJJmJJ900DetaJJ42->Write();
   hDphiJJmJJ900DetaJJ42MET70->Write();
    
   hPFMET1->Write();
   hPFMET1mJJ300DetaJJ2->Write();
   hPFMET1mJJ800DetaJJ4->Write();
   hPFMET1mJJ1200DetaJJ42->Write();
   hPFMET1mJJ900DetaJJ42->Write();

   efile.Close();

   fclose(Out1);
}
