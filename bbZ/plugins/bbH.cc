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

class bbH : public edm::EDAnalyzer {
public:
  explicit bbH(const edm::ParameterSet&);
  ~bbH();


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
  int     jjpt;
  double  PVx;
  std::vector<double> *EtaRaw;
  // output root file and tree
  TFile*      hOutputFile ;
  TTree*      t1;

  int nbq0, nbq1, nbq2;
  int nbj0, nbj1, nbj2;
  int ntot;

};

//
// constants, enums and typedefs
//

//
// static data member definitions
//

// ------------ method called once each job just before starting event loop  ------------
void 
//bbH::beginJob(const edm::EventSetup&)
bbH::beginJob()
{
  using namespace edm;

  nbq0 = 0; 
  nbq1 = 0;
  nbq2 = 0;

  nbj0 = 0; 
  nbj1 = 0; 
  nbj2 = 0;

  ntot = 0;

  EtaRaw       = new std::vector<double>();

  // creating a simple tree

  hOutputFile   = new TFile( fOutputFileName.c_str(), "RECREATE" ) ;

  t1 = new TTree("t1","analysis tree");

  t1->Branch("jjpt",&jjpt,"jjpt/I");
  t1->Branch("PVx",&PVx,"PVx/D");
  t1->Branch("EtaRaw","vector<double>",&EtaRaw);

  return ;
}

// ------------ method called once each job just after ending the event loop  ------------
void 
bbH::endJob() {

  hOutputFile->Write() ;
  hOutputFile->Close() ;
  
  cout <<" Results for b quarks and jets " << endl;
  cout <<" " << endl;

  cout <<"   total number of events processed = " << ntot << endl;
  cout <<" " << endl;
  cout <<" b-quark / jet selections: pTb > 20 GeV , |eta| < 2.4 " << endl;
  cout <<" " << endl;
 
  cout <<" zero b quarks = " << nbq0 
       <<"    >= 1 b quarks = " << nbq1 
       <<"    = 2 b quarks = "  << nbq2 << endl;

  cout <<" " << endl;
  cout <<" zero b jets = " << nbj0 
       <<"    >= 1 b jets = " << nbj1 
       <<"    = 2 b jets = "  << nbj2 << endl;

  return ;
}

//
// constructors and destructor
//
bbH::bbH(const edm::ParameterSet& iConfig)

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


bbH::~bbH()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called to for each event  ------------
void
bbH::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  using namespace edm;

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

  int nbquarks = 0; 

  for( size_t i = 0; i < genparticles->size(); i++)
    {
      const reco::GenParticle & p = (*genparticles)[i];

      //      cout <<" i = " << i <<" ID = " << p.pdgId() <<" status = " << p.status() << endl;
      
      if( fabs(p.pdgId()) == 5 && p.status() == 3 && p.pt() > 20. &&  fabs(p.eta()) < 2.4 ) {
	++nbquarks;
	//	cout <<" good b quark i = " << i 
	//     <<" id = " << p.pdgId() 
	//    <<" status = " << p.status() 
	//   <<" pt / eta = " << p.pt() <<" " << p.eta() << endl;
	// if(p.status() == 2) {
	//  const Candidate * moth = p.mother();
	//  if(moth) {
	//    cout <<"         mother = " << moth->pdgId() << endl;
	//  }
      }
    }

  if(nbquarks == 0) {++nbq0;}
  if(nbquarks == 1) {++nbq1;}
  if(nbquarks == 2) {++nbq2;}

  // parton jets
  edm::Handle<GenJetCollection> partonjets;
  iEvent.getByLabel(partonjetsSrc, partonjets);

  int nbjets = 0; 

  ++ntot;

  if( partonjets->size() != 0) {
    
    for(GenJetCollection::const_iterator partonjet = partonjets->begin();  partonjet != partonjets->end(); ++partonjet ) { 
      int nb = 0;
      if( ( partonjet->pt() > 20. ) && ( fabs(partonjet->eta()) ) < 2.4 ) {
	//	    cout <<" parton jet pt / eta = " << partonjet->pt() <<" "<< partonjet->eta() <<  endl; 
	    std::vector<const reco::Candidate*> partons = partonjet->getJetConstituentsQuick();
	    for (unsigned int i = 0; i < partons.size(); ++i) {
	      const reco::Candidate* parton = partons[i];
	      //	      cout <<"   jet constituent i = " << i <<" ID " << parton->pdgId() << endl;
	      if( fabs(parton->pdgId()) == 5 ) {++nb; }
	    }
	    //	    cout <<"   n bquarks in jet = " << nb << endl;
	    if( nb > 0 ) {++nbjets;}
      }
    }
  }
	
  if(nbjets == 0) {++nbj0;}
  if(nbjets == 1) {++nbj1;}
  if(nbjets >= 2) {++nbj2;}

  //  cout <<"    ---> n b-jets   counters nbj0, nbj1, nbj2 = " << nbj0 <<" " << nbj1 <<" "<< nbj2 << endl;
  //  cout <<"    ---> n b-quarks counters nbq0, nbq1, nbq2 = " << nbq0 <<" " << nbq1 <<" "<< nbq2 << endl;

  jjpt = 0;
  PVx = -1000.; 
  EtaRaw->clear();
  //  t1->Fill();
}

//define this as a plug-in
DEFINE_FWK_MODULE(bbH);
