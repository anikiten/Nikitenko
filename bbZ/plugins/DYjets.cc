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

class DYjets : public edm::EDAnalyzer {
public:
  explicit DYjets(const edm::ParameterSet&);
  ~DYjets();


private:
  //      virtual void beginJob(const edm::EventSetup&) ;
  virtual void beginJob() ;
  virtual void analyze(const edm::Event&, const edm::EventSetup&);
  virtual void endJob() ;

  // ----------member data ---------------------------
  // output root file
  string fOutputFileName ;
  // names of modules, producing object collections
  edm::InputTag partonjetsSrc; 
  // variables to store in ntpl
  double event_w, pTZ, yZ;
  std::vector<double> *EtaMu;
  std::vector<double> *PhiMu;
  std::vector<double> *PtMu;
  std::vector<double> *EtaJ;
  std::vector<double> *PhiJ;
  std::vector<double> *pTJ;
  // output root file and tree
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
//DYjets::beginJob(const edm::EventSetup&)
DYjets::beginJob()
{
  using namespace edm;


  EtaMu        = new std::vector<double>();
  PhiMu        = new std::vector<double>();
  PtMu         = new std::vector<double>();
  EtaJ         = new std::vector<double>();
  PhiJ         = new std::vector<double>();
  pTJ          = new std::vector<double>();
  // creating a simple tree

  hOutputFile   = new TFile( fOutputFileName.c_str(), "RECREATE" ) ;

  t1 = new TTree("t1","analysis tree");

  t1->Branch("event_w",&event_w,"event_w/D");
  t1->Branch("pTZ",&pTZ,"pTZ/D");
  t1->Branch("yZ",&yZ,"yZ/D");

  t1->Branch("EtaMu","vector<double>",&EtaMu);
  t1->Branch("PhiMu","vector<double>",&PhiMu);
  t1->Branch("PtMu" ,"vector<double>",&PtMu);

  t1->Branch("EtaJ","vector<double>",&EtaJ);
  t1->Branch("PhiJ","vector<double>",&PhiJ);
  t1->Branch("pTJ" ,"vector<double>",&pTJ);

  return ;
}

// ------------ method called once each job just after ending the event loop  ------------
void 
DYjets::endJob() {

  hOutputFile->Write() ;
  hOutputFile->Close() ;
  
  return ;
}

//
// constructors and destructor
//
DYjets::DYjets(const edm::ParameterSet& iConfig)

{
   //now do what ever initialization is needed
  using namespace edm;
  // 
  // get name of output file with histogramms
  fOutputFileName = iConfig.getUntrackedParameter<string>("HistOutFile");
  //
  // get parton jets
  partonjetsSrc      = iConfig.getParameter<edm::InputTag>("parton_jets");
}


DYjets::~DYjets()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called to for each event  ------------
void
DYjets::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  using namespace edm;

  edm::Handle<GenEventInfoProduct> genEvt;;
  iEvent.getByLabel("generator",genEvt);

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
  
  event_w = 0.; 
  pTZ     = 0.; 
  yZ      = 0.;

  EtaMu->clear();
  PhiMu->clear();
  PtMu->clear();

  EtaJ->clear();
  PhiJ->clear();
  pTJ->clear();


  int procid = (int) genEvt->signalProcessID();
  event_w = genEvt->weight();

  //  cout <<"  proc ID = " << procid <<" event weight = " << event_w << endl;

  //  cout <<"  Event particles " << endl;

  math::XYZTLorentzVector  muon1(0.,0.,0.,0.);
  math::XYZTLorentzVector  muon2(0.,0.,0.,0.);

  edm::Handle<reco::GenParticleCollection> genparticles;
  iEvent.getByLabel("genParticles", genparticles);

  int imu = 0.;

  for( size_t i = 0; i < genparticles->size(); i++)
    {
      const reco::GenParticle & p = (*genparticles)[i];
      
      /*
      cout <<" i = " << i 
	   <<" ID = " << p.pdgId() 
	   <<" status = " << p.status() 
	   <<" rapidity = " << p.y() 
	   <<" eta = " << p.eta() << endl;
      */

      if(p.pdgId() == 23 && p.status() == 2 ) {
	pTZ = p.pt();
	yZ  = p.y();
      }
      
      if(i > 100 ) {continue;}
      if( fabs(p.pdgId()) != 11 && fabs(p.pdgId()) != 13 && fabs(p.pdgId()) != 15 ) {continue;}
      if(p.status() == 1 || (fabs(p.pdgId()) == 15 && p.status() == 2)) {
	imu++;
	if(imu <= 2) {
	  EtaMu->push_back(p.eta());
	  PhiMu->push_back(p.phi());
	  PtMu->push_back(p.pt());
	}
	math::XYZTLorentzVector muonc(p.px(),p.py(), p.pz(), p.p());
	if (imu == 1) muon1 = muonc; 
	if (imu == 2) muon2 = muonc; 
      }
    }

  math::XYZTLorentzVector twomuons = muon1 + muon2;
  pTZ = twomuons.pt();
  yZ  = 0.5 * log( (twomuons.e()+twomuons.pz()) / (twomuons.e()-twomuons.pz()) ); 
  double mumu_mass = twomuons.M();

  // parton jets
  edm::Handle<GenJetCollection> partonjets;
  iEvent.getByLabel(partonjetsSrc, partonjets);

  for(GenJetCollection::const_iterator partonjet = partonjets->begin();  partonjet != partonjets->end(); ++partonjet ) { 
    if( partonjet->pt() > 20. && fabs(partonjet->eta()) < 4.7 ) {

	/*
	  std::vector<const reco::Candidate*> partons = partonjet->getJetConstituentsQuick();
	  for (unsigned int i = 0; i < partons.size(); ++i) {
	  const reco::Candidate* parton = partons[i];
	  //	      cout <<"   jet constituent i = " << i <<" ID " << parton->pdgId() << endl;
	  if( fabs(parton->pdgId()) == 5 ) {}
	  }
	*/
      Double_t DR1 = deltaR(muon1.Eta(), muon1.Phi(), partonjet->eta(), partonjet->phi());
      Double_t DR2 = deltaR(muon2.Eta(), muon2.Phi(), partonjet->eta(), partonjet->phi());
      if( DR1 > 0.6 && DR2 > 0.6 ) {
	EtaJ->push_back(partonjet->eta());
	PhiJ->push_back(partonjet->phi());
	pTJ->push_back(partonjet->pt());
      }
    }
  }
  /*
  int njets = pTJ->size();
  cout <<" muon1 = " << muon1.pt() <<" eta = " << muon1.eta() <<" phi = " << muon1.phi() << endl;
  cout <<" muon2 = " << muon2.pt() <<" eta = " << muon2.eta() <<" phi = " << muon2.phi() << endl;
  cout <<" mumu_mass = " << mumu_mass <<" njets = " << njets <<" event W = " << event_w <<  endl;
  for(int ind = 0; ind < njets; ind++) {
    cout <<"   jet N = " << ind <<" pTJ = " << (*pTJ)[ind] <<" eta = " << (*EtaJ)[ind] <<" phi = " << (*PhiJ)[ind] << endl;
  }
  */

  t1->Fill();
}
//define this as a plug-in
DEFINE_FWK_MODULE(DYjets);
