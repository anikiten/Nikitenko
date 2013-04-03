// system include files
// http://cmslxr.fnal.gov/lxr/source/RecoJets/JetAlgorithms/src/JetIDHelper.cc?v=CMSSW_3_3_6
#include <memory>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
//
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "DataFormats/Common/interface/Handle.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
//#include "FWCore/ParameterSet/interface/InputTag.h"
#include "FWCore/Utilities/interface/InputTag.h"
// gen particles
#include "SimDataFormats/GeneratorProducts/interface/GenEventInfoProduct.h"
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"
// parton jets
#include "DataFormats/JetReco/interface/GenJet.h"
#include "DataFormats/JetReco/interface/GenJetCollection.h"
// MC info
#include "CLHEP/Vector/LorentzVector.h"
#include "CLHEP/Units/GlobalPhysicalConstants.h"
#include "SimGeneral/HepPDTRecord/interface/ParticleDataTable.h"
#include "SimDataFormats/GeneratorProducts/interface/HepMCProduct.h"
//#include "CLHEP/HepPDT/DefaultConfig.hh"
//
#include "DataFormats/Math/interface/LorentzVector.h"
#include "DataFormats/Math/interface/Vector3D.h"
#include "Math/GenVector/VectorUtil.h"
#include "Math/GenVector/PxPyPzE4D.h"
#include "DataFormats/Math/interface/deltaR.h"
//double dR = deltaR( c1, c2 );
//
// root
#include "TFile.h"
#include "TTree.h"
#include "TH1.h"
#include "TH2.h"
//
using namespace std;
using namespace reco;

//
// class declaration
//

class nmssm_wh_4b : public edm::EDAnalyzer {
public:
  explicit nmssm_wh_4b(const edm::ParameterSet&);
  ~nmssm_wh_4b();


private:
  //      virtual void beginJob(const edm::EventSetup&) ;
  virtual void beginJob() ;
  virtual void analyze(const edm::Event&, const edm::EventSetup&);
  virtual void endJob() ;

  // ----------member data ---------------------------
  // output root file
  string fOutputFileName ;
  // names of modules, producing object collections
  // variables to store in ntpl
  double ptel, etael, phiel;
  double ptmu, etamu, phimu;
  
  std::vector<double> *ptb;
  std::vector<double> *etab;
  std::vector<double> *phib;
  
  //
  TFile*      hOutputFile ;
  TTree*      t1;
};

//
// constants, enums and typedefs
//

//
// static data member definitions
//

// ------------ method called once each job just before starting event loop  ------------
void 
//nmssm_wh_4b::beginJob(const edm::EventSetup&)
nmssm_wh_4b::beginJob()
{
  using namespace edm;

  // creating a simple tree

  hOutputFile   = new TFile( fOutputFileName.c_str(), "RECREATE" ) ;

  t1 = new TTree("t1","analysis tree");

  ptb  = new std::vector<double>();
  etab = new std::vector<double>();
  phib = new std::vector<double>();


  //
  t1->Branch("ptel",&ptel,"ptel/D");
  t1->Branch("etael",&etael,"etael/D");
  t1->Branch("phiel",&phiel,"phiel/D");
  //
  t1->Branch("ptmu",&ptmu,"ptmu/D");
  t1->Branch("etamu",&etamu,"etamu/D");
  t1->Branch("phimu",&phimu,"phimu/D");
  //
  t1->Branch("ptb","vector<double>",&ptb);
  t1->Branch("etab","vector<double>",&etab);
  t1->Branch("phib","vector<double>",&phib);
  //
  return ;
}

// ------------ method called once each job just after ending the event loop  ------------
void 
nmssm_wh_4b::endJob() {

  hOutputFile->Write() ;
  hOutputFile->Close() ;

  return ;
}

//
// constructors and destructor
//
nmssm_wh_4b::nmssm_wh_4b(const edm::ParameterSet& iConfig)

{
   //now do what ever initialization is needed
  using namespace edm;
  // 
  // get name of output file with histogramms
  fOutputFileName = iConfig.getUntrackedParameter<string>("HistOutFile");
  //
}


nmssm_wh_4b::~nmssm_wh_4b()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called to for each event  ------------
void
nmssm_wh_4b::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  using namespace edm;

  ptel    = 0.; 
  etael   = 0.; 
  phiel   = 0.;

  ptmu    = 0.; 
  etamu   = 0.; 
  phimu   = 0.;

  ptb->clear();
  etab->clear();
  phib->clear();

  edm::Handle<GenEventInfoProduct> genEvt;;
  iEvent.getByLabel("generator",genEvt);

  //  int procid = (int) genEvt->signalProcessID();

  //  edm::Handle<std::vector<PileupSummaryInfo> > infoPU;
  //  iEvent.getByLabel("addPileupInfo",infoPU);
  //  for(std::vector<PileupSummaryInfo>::const_iterator it = infoPU->begin(); it != infoPU->end(); it++)
  //    {
  //      genPU = it->getPU_NumInteractions();
  //      if (verbosity > 0) {   std::cout<<" Pileup "<<genPU<<std::endl;}
  //    }

  //  edm::Handle<reco::CandidateView> mctruth;
  //  for (unsigned int i = 0; i < mctruth->size(); ++ i) {
  //    if(ii > 29) break;
  //    const reco::Candidate& p = (*mctruth)[i];
  //  }
  


  //  cout <<"  Event particles " << endl;

  edm::Handle<reco::GenParticleCollection> genparticles;
  iEvent.getByLabel("genParticles", genparticles);

  math::XYZTLorentzVector  tauh1(0.,0.,0.,0.);
  math::XYZTLorentzVector  tauh2(0.,0.,0.,0.);

  int imu = 0;
  int tau = 0;
  double pt1sttau = 0;

  for( size_t i = 0; i < genparticles->size(); i++)
    {
      const reco::GenParticle & p = (*genparticles)[i];

      int motherID = 0;
      int motherSt = 0;

      int grmotherID = 0;
      int grmotherSt = 0;
      double grmotherPt = 0;

      int grgrmotherID = 0;
      int grgrmotherSt = 0;
      double grgrmotherpx = 0.;

      const Candidate * moth = p.mother();
      if(moth) {
	motherID = moth->pdgId();
	motherSt = moth->status();	
	const Candidate * grmoth = moth->mother();
	if(grmoth) {
	  grmotherID = grmoth->pdgId();
	  grmotherSt = grmoth->status();
	  grmotherPt = grmoth->pt();
	  const Candidate * grgrmoth = grmoth->mother();
	  if(grgrmoth) {
	    grgrmotherID = grgrmoth->pdgId();
	    grgrmotherSt = grgrmoth->status();
	    grgrmotherpx = grgrmoth->px();
	  }	  
	}
      }

      /*
      if(p.status() == 3 && 
	 (fabs(p.pdgId()) == 5 || fabs(p.pdgId()) == 11 || fabs(p.pdgId()) == 13)) {
	   cout <<" i " << i 
		<<" ID " << p.pdgId() 
		<<" status " << p.status() 
		<<" mass " << p.mass() 
		<<" pt " << p.pt() 
		<<" motherID " << motherID 
		<<" motherST " << motherSt
		<<" grmotherID " << grmotherID 
		<<" grmotherST " << grmotherSt 
		<<" grmotherPt " << grmotherPt 
		<<" grgrmotherID " << grgrmotherID 
		<<" grgrmotherST " << grgrmotherSt
		<<" grgrmotherpx " << grgrmotherpx << endl;
	 }
      */
      // select W->enu
      if(fabs(p.pdgId()) == 11 && fabs(motherID) == 24 && motherSt == 3)
	{
	  /*
	  cout <<" electron ID = " << p.pdgId()
	       <<" pt = " << p.pt()
	       <<" eta = " << p.eta()
	       <<" phi = " << p.phi() 
	       <<" p = " << p.px() << endl;
	  */
	  ptel  = p.pt();
	  etael = p.eta();
	  phiel = p.phi();
	}

      // select W->enu
      if(fabs(p.pdgId()) == 13 && fabs(motherID) == 24 && motherSt == 3)
	{
	  /*
	  cout <<" muon ID = " << p.pdgId()
	       <<" pt = " << p.pt()
	       <<" eta = " << p.eta()
	       <<" phi = " << p.phi()
	       <<" p = " << p.px() << endl;
	  */
	  ptmu  = p.pt();
	  etamu = p.eta();
	  phimu = p.phi();
	}

      // select b quarks
      if(fabs(p.pdgId()) == 5 && motherID == 25 && motherSt == 3) 
	{
	  ptb->push_back(p.pt());
	  etab->push_back(p.eta());
	  phib->push_back(p.phi());
	  /*
	  cout <<" b -quark ! + " 
	       <<" id = " << p.pdgId()
	       <<" pt = " << p.pt()
	       <<" eta = " << p.eta()
	       <<" phi = " << p.phi()
	       <<" p = " << p.px() << endl;
	  */
	}
    }
  t1->Fill();
}

//define this as a plug-in
DEFINE_FWK_MODULE(nmssm_wh_4b);
