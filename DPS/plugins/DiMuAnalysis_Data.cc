// system include files
// http://cmslxr.fnal.gov/lxr/source/RecoJets/JetAlgorithms/src/JetIDHelper.cc?v=CMSSW_3_3_6
#include <memory>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
// /CMSSW/Calibration/HcalAlCaRecoProducers/src/AlCaIsoTracksProducer.cc  track propagator
// user include files
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
//
// HLT/L1 and Trigger data formats
#include "DataFormats/L1GlobalTrigger/interface/L1GlobalTriggerReadoutRecord.h"
#include "DataFormats/L1GlobalTrigger/interface/L1GlobalTriggerReadoutSetup.h"
#include "DataFormats/L1GlobalTrigger/interface/L1GlobalTriggerReadoutSetupFwd.h"
#include "DataFormats/L1GlobalTrigger/interface/L1GlobalTriggerObjectMapRecord.h"
#include "DataFormats/L1GlobalTrigger/interface/L1GlobalTriggerObjectMapFwd.h"
#include "DataFormats/L1GlobalTrigger/interface/L1GlobalTriggerObjectMap.h"
#include "FWCore/Common/interface/TriggerNames.h"
#include "DataFormats/Common/interface/TriggerResults.h"
#include "CondFormats/L1TObjects/interface/L1GtTriggerMenuFwd.h"
#include "CondFormats/L1TObjects/interface/L1GtTriggerMenu.h"
#include "CondFormats/DataRecord/interface/L1GtTriggerMenuRcd.h"

// MC info and vectors
// #include "CLHEP/Vector/LorentzVector.h"
#include "CLHEP/Units/GlobalPhysicalConstants.h"
#include "SimGeneral/HepPDTRecord/interface/ParticleDataTable.h"
#include "SimDataFormats/GeneratorProducts/interface/HepMCProduct.h"
//#include "CLHEP/HepPDT/DefaultConfig.hh"
#include "DataFormats/Math/interface/LorentzVector.h"
#include "DataFormats/Math/interface/Vector3D.h"
#include "Math/GenVector/VectorUtil.h"
#include "Math/GenVector/PxPyPzE4D.h"
#include "DataFormats/Math/interface/deltaR.h"
//double dR = deltaR( c1, c2 );
//
#include "MagneticField/Records/interface/IdealMagneticFieldRecord.h"
#include "Geometry/Records/interface/IdealGeometryRecord.h"
#include "Geometry/CaloGeometry/interface/CaloCellGeometry.h"
#include "Geometry/CaloGeometry/interface/CaloGeometry.h"
// muons
#include "DataFormats/MuonReco/interface/Muon.h"
#include "DataFormats/MuonReco/interface/MuonFwd.h"
#include "DataFormats/MuonReco/interface/MuonSelectors.h"
//jets
#include "DataFormats/JetReco/interface/CaloJet.h"
#include "DataFormats/JetReco/interface/CaloJetCollection.h"
#include "DataFormats/JetReco/interface/JPTJetCollection.h"
#include "DataFormats/JetReco/interface/JPTJet.h"
#include "DataFormats/JetReco/interface/GenJet.h"
#include "DataFormats/JetReco/interface/GenJetCollection.h"

#include "CondFormats/JetMETObjects/interface/JetCorrectorParameters.h"
#include "CondFormats/JetMETObjects/interface/JetCorrectionUncertainty.h"

// #include "JetMETCorrections/Objects/interface/JetCorrector.h"
// #include "JetMETCorrections/Algorithms/interface/JetPlusTrackCorrector.h"
#include "DataFormats/JetReco/interface/JetExtendedAssociation.h"
#include "DataFormats/JetReco/interface/JetID.h"

#include "DataFormats/JetReco/interface/PFJet.h"

// taus
#include "DataFormats/TauReco/interface/CaloTau.h"
#include "RecoTauTag/TauTagTools/interface/CaloTauElementsOperators.h"
//
// muons and tracks
#include "DataFormats/MuonReco/interface/MuonFwd.h"
#include "DataFormats/MuonReco/interface/Muon.h"
#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/TrackReco/interface/TrackFwd.h"
#include "DataFormats/TrackReco/interface/HitPattern.h"
// ecal
//#include "DataFormats/EgammaCandidates/interface/PixelMatchGsfElectron.h"
#include "DataFormats/EgammaReco/interface/BasicClusterFwd.h"
#include "DataFormats/EgammaReco/interface/SuperClusterFwd.h"
#include "DataFormats/EgammaReco/interface/ClusterShapeFwd.h"
#include "DataFormats/EgammaReco/interface/BasicClusterShapeAssociation.h"
#include "DataFormats/EcalDetId/interface/EcalSubdetector.h"
#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/VertexReco/interface/VertexFwd.h"
// PU summary info
#include "SimDataFormats/PileupSummaryInfo/interface/PileupSummaryInfo.h" 
// candidates
#include "DataFormats/Candidate/interface/LeafCandidate.h"
#include "DataFormats/Candidate/interface/Candidate.h"
#include "DataFormats/Candidate/interface/CandidateFwd.h"
// beam spot
#include "DataFormats/BeamSpot/interface/BeamSpot.h"
#include "DataFormats/VertexReco/interface/Vertex.h"
//
#include "TFile.h"
#include "TTree.h"
#include "TH1.h"
#include "TH2.h"

using namespace std;
using namespace reco;

//
// class decleration
//

class DiMuAnalysis_Data : public edm::EDAnalyzer {
public:
  explicit DiMuAnalysis_Data(const edm::ParameterSet&);
  ~DiMuAnalysis_Data();

protected: 

  // Some useful typedefs
  typedef reco::MuonCollection RecoMuons;

private:

  //      virtual void beginJob(const edm::EventSetup&) ;
  virtual void beginJob() ;
  virtual void analyze(const edm::Event&, const edm::EventSetup&);
  virtual void endJob() ;

  // ----------member data ---------------------------
  // output root file
  string fOutputFileName ;
  // data or MC
  int DataOrMCSrc;
  // names of modules, producing object collections
  // raw calo jet ID map
  edm::InputTag muonsSrc;
  // raw calo jet ID map
  edm::InputTag jetsIDSrc;
  // calo jets
  edm::InputTag calojetsSrc; 
  // JPT jets raw
  edm::InputTag JPTjetsSrc;
  // JPT jets L1L2L3 corr
  edm::InputTag JPTjetsL1L2L3Src;
  // MC jet corrections
  //  string JetCorrectionMC;
  // PF jet corrections
  //  string JetCorrectionPF;
  // HLT result
  edm:: InputTag srcTriggerResults_;

  // variables to store in ntpl
  int     run, event, nvertex, nsimvertex;
  double  DZmin, PVx, PVy, PVz;
  // di muon pass
  double  mass_mumu;
  // muon eta/phi/pT
  std::vector<double> *EtaMu;
  std::vector<double> *PhiMu;
  std::vector<double> *PtMu;
  std::vector<double> *dzmuon;
  std::vector<double> *muisol;
  // eta/phi/pt of raw calo jet from JPT
  std::vector<double> *EtaRaw;
  std::vector<double> *PhiRaw;
  std::vector<double> *EtRaw;
  // eta/phi/pt of JPT corrected jets
  std::vector<double> *EtaJPT;
  std::vector<double> *PhiJPT;
  std::vector<double> *EtJPT;
  // N in-vertex-cone tracks
  std::vector<int>    *Ntrk;
  // in-cone-in vertex track with max pT
  std::vector<double> *jesunc;
  // beta
  std::vector<double> *beta;
  // number of Pxl and silicon inner and outer layers used for trk. measurement
  //  std::vector<int>    *NPxlMaxPtTrk;  
  //  std::vector<int>    *NSiIMaxPtTrk;  
  //  std::vector<int>    *NSiOMaxPtTrk;  
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
//DiMuAnalysis_Data::beginJob(const edm::EventSetup&)
DiMuAnalysis_Data::beginJob()
{
  using namespace edm;

  EtaMu        = new std::vector<double>();
  PhiMu        = new std::vector<double>();
  PtMu         = new std::vector<double>();
  EtaRaw       = new std::vector<double>();  
  dzmuon       = new std::vector<double>();
  muisol       = new std::vector<double>();
  PhiRaw       = new std::vector<double>();
  EtRaw        = new std::vector<double>();
  EtaJPT       = new std::vector<double>();
  PhiJPT       = new std::vector<double>();
  EtJPT        = new std::vector<double>();
  Ntrk         = new std::vector<int>();
  jesunc       = new std::vector<double>();
  beta         = new std::vector<double>();;
  //  NPxlMaxPtTrk = new std::vector<int>();
  //  NSiIMaxPtTrk = new std::vector<int>();
  //  NSiOMaxPtTrk = new std::vector<int>();

  // creating a simple tree

  hOutputFile   = new TFile( fOutputFileName.c_str(), "RECREATE" ) ;

  t1 = new TTree("t1","analysis tree");

  t1->Branch("run",&run,"run/I");
  t1->Branch("event",&event,"event/I");

  t1->Branch("nvertex",&nvertex,"nvertex/I");
  t1->Branch("nsimvertex",&nsimvertex,"nsimvertex/I");
  t1->Branch("DZmin",&DZmin,"DZmin/D");

  t1->Branch("PVx",&PVx,"PVx/D");
  t1->Branch("PVy",&PVy,"PVy/D");
  t1->Branch("PVz",&PVz,"PVz/D");

  t1->Branch("mass_mumu",&mass_mumu,"mass_mumu/D");
  t1->Branch("EtaMu","vector<double>",&EtaMu);
  t1->Branch("PhiMu","vector<double>",&PhiMu);
  t1->Branch("PtMu" ,"vector<double>",&PtMu);
  t1->Branch("dzmuon" ,"vector<double>",&dzmuon);
  t1->Branch("muisol" ,"vector<double>",&muisol);

  t1->Branch("EtaRaw","vector<double>",&EtaRaw);
  t1->Branch("PhiRaw","vector<double>",&PhiRaw);
  t1->Branch("EtRaw" ,"vector<double>",&EtRaw);
  t1->Branch("EtaJPT","vector<double>",&EtaJPT);
  t1->Branch("PhiJPT","vector<double>",&PhiJPT);
  t1->Branch("EtJPT" ,"vector<double>",&EtJPT);
  t1->Branch("Ntrk","vector<int>",&Ntrk);
  t1->Branch("jesunc" ,"vector<double>",&jesunc);
  t1->Branch("beta" ,"vector<double>",&beta);
  //  t1->Branch("NPxlMaxPtTrk","vector<int>",&NPxlMaxPtTrk);
  //  t1->Branch("NSiIMaxPtTrk","vector<int>",&NSiIMaxPtTrk);
  //  t1->Branch("NSiOMaxPtTrk","vector<int>",&NSiOMaxPtTrk);

  return ;
}

// ------------ method called once each job just after ending the event loop  ------------
void 
DiMuAnalysis_Data::endJob() {

  hOutputFile->Write() ;
  hOutputFile->Close() ;
  
  return ;
}

//
// constructors and destructor
//
DiMuAnalysis_Data::DiMuAnalysis_Data(const edm::ParameterSet& iConfig)

{
   //now do what ever initialization is needed
  using namespace edm;
  // 
  // get name of output file with histogramms
  fOutputFileName = iConfig.getUntrackedParameter<string>("HistOutFile");
  // DataOrMC
  DataOrMCSrc     = iConfig.getUntrackedParameter<int>("DataOrMC");
  //
  // get names of input object collections
  // muons
  muonsSrc         = iConfig.getParameter<edm::InputTag>("Muons");
  // raw calo jets
  jetsIDSrc        = iConfig.getParameter<edm::InputTag>("jetsID");
  // JPT jets raw
  JPTjetsSrc       = iConfig.getParameter<edm::InputTag>("JPTjets");
  // JPT L1L2L3 corrected
  JPTjetsL1L2L3Src = iConfig.getParameter<edm::InputTag>("JPTjetsL1L2L3");
  // calo jets
  calojetsSrc      = iConfig.getParameter<edm::InputTag>("calojets");
  // MC corrections
  //  JetCorrectionMC  = iConfig.getParameter< std::string > ("JetCorrectionMC");
  // PF corrections
  //  JetCorrectionPF  = iConfig.getParameter< std::string > ("JetCorrectionPF");
  // HLT results
  srcTriggerResults_ = iConfig.getParameter<edm::InputTag> ("TriggerResults");
}


DiMuAnalysis_Data::~DiMuAnalysis_Data()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called to for each event  ------------
void
DiMuAnalysis_Data::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  using namespace edm;

  /*
  // L1
   edm::Handle<L1GlobalTriggerReadoutRecord> l1GtRR;
   iEvent.getByLabel("gtDigis",l1GtRR);
   
   edm::Handle<L1GlobalTriggerObjectMapRecord> l1GtOMRec;
   iEvent.getByLabel("hltL1GtObjectMap",l1GtOMRec);
   
   edm::ESHandle<L1GtTriggerMenu> menuRcd;
   iSetup.get<L1GtTriggerMenuRcd>().get(menuRcd) ;
   const L1GtTriggerMenu* menu = menuRcd.product();

   if(l1GtRR.isValid()) {

     L1GlobalTriggerReadoutRecord L1GTRR = *l1GtRR.product();
     const TechnicalTriggerWord&  technicalTriggerWordBeforeMask =  L1GTRR.technicalTriggerWord();
     DecisionWord gtDecisionWord = L1GTRR.decisionWord();

     for (CItAlgo algo = menu->gtAlgorithmMap().begin(); algo != menu->gtAlgorithmMap().end(); ++algo) {
       int algBitNumber = ( algo->second).algoBitNumber();
       //algo
       //if(algBitNumber == 124) 
       std::cout << " algo bits " << algBitNumber << " " 
		 << (algo->second).algoName() << " " <<  gtDecisionWord.at(algBitNumber) << std::endl;
     }

     for (CItAlgo techTrig = menu->gtTechnicalTriggerMap().begin(); techTrig != menu->gtTechnicalTriggerMap().end(); ++techTrig) {
       int techBitNumber = ( techTrig->second).algoBitNumber();
       //technical
       //       if(techBitNumber ==40) 
       std::cout << " tech bits " 
		 << techBitNumber << " "
		 << (techTrig->second).algoName() 
		 << " " << technicalTriggerWordBeforeMask.at(techBitNumber) << std::endl;
     }
   }

   //int printVerbosity = 0;
   //menu->print(std::cout, printVerbosity);
   */

   // HLT
  /*
   edm::Handle<TriggerResults> triggerResults;
   iEvent.getByLabel(srcTriggerResults_,triggerResults);

   const edm::TriggerNames & triggerNames = iEvent.triggerNames(*triggerResults);

   unsigned index = triggerNames.triggerIndex("HLT_PhysicsDeclared");
   bool physdecl= (index<triggerNames.size()&&triggerResults->accept(index)) ? 1 : 0;

   for(unsigned ihlt = 0; ihlt < triggerNames.size(); ihlt++) {
     std::cout <<" HLT bit " << ihlt <<" name = " << triggerNames.triggerName(ihlt) 
	       <<" accepted = " << triggerResults->accept(ihlt) <<" index = " << index << std::endl; 
   }
  */

  //  std::map<double,int> pTjptIndex;

  std::map<double,const JPTJet*> pTjptIndex;
  std::map<double,const Muon*> pTMuonIndex;
  math::XYZTLorentzVector  muon1(0.,0.,0.,0.);
  math::XYZTLorentzVector  muon2(0.,0.,0.,0.);

  run = iEvent.id().run();
  event = iEvent.id().event();

  cout <<" run = " << run <<" event = " << event << endl;

  nvertex = 0;
  nsimvertex = 0;

  DZmin =   0.;
  PVx = -1000.; 
  PVy = -1000.; 
  PVz = -1000.;

  mass_mumu = 0.;
  EtaMu->clear();
  PhiMu->clear();
  PtMu->clear();
  dzmuon->clear();
  muisol->clear();

  EtaRaw->clear();
  PhiRaw->clear();
  EtJPT->clear();
  EtaJPT->clear();
  PhiJPT->clear();
  EtJPT->clear();
  Ntrk->clear();
  jesunc->clear(); 
  beta->clear(); 

  //  NPxlMaxPtTrk->clear();
  //  NSiIMaxPtTrk->clear();
  //  NSiOMaxPtTrk->clear();
  
  // PU info
  if(DataOrMCSrc == 1) {

    edm::InputTag PileupSrc_("addPileupInfo");
    Handle<std::vector< PileupSummaryInfo > >  PupInfo;
    iEvent.getByLabel(PileupSrc_, PupInfo);
    // const float getTrueNumInteractions() - the *true* mean number of pileup interactions for this event from which each bunch crossing has been sampled for
    // Fall 11 MC (CMSSW 4_2_8 and later)
    
    std::vector<PileupSummaryInfo>::const_iterator PVI;
    for(PVI = PupInfo->begin(); PVI != PupInfo->end(); ++PVI) {
      //      std::cout << " Pileup Information: bunchXing, nvtx: " << PVI->getBunchCrossing() << " " << PVI->getPU_NumInteractions() << std::endl;
      if(PVI->getBunchCrossing() == 0) nsimvertex = PVI->getPU_NumInteractions();
    }
  }

  // muons
  edm::Handle<RecoMuons> reco_muons;
  iEvent.getByLabel(muonsSrc, reco_muons );

  // get jet ID map
  edm::Handle<ValueMap<reco::JetID> > jetsID;
  iEvent.getByLabel(jetsIDSrc,jetsID);
  // 'ak5JetID'

   // pf jets
  edm::Handle<PFJetCollection> pfjetsakt5;
  iEvent.getByLabel("ak5PFJets", pfjetsakt5);
   
  // JPT jets raw
  edm::Handle<reco::JPTJetCollection> jptjets;
  iEvent.getByLabel(JPTjetsSrc, jptjets);

  // JPT jets L1L2L3
  edm::Handle<reco::JPTJetCollection> jptjetsl1l2l3;
  iEvent.getByLabel(JPTjetsL1L2L3Src, jptjetsl1l2l3);

  // JES uncertainty
  JetCorrectionUncertainty *jecUnc = new JetCorrectionUncertainty("GR_R_42_V23_AK5JPT_Uncertainty.txt");
  
  // Calo jets
  edm::Handle<CaloJetCollection> calojets;
  iEvent.getByLabel(calojetsSrc, calojets);

  // get vertex
  edm::Handle<reco::VertexCollection> recVtxs;
  iEvent.getByLabel("offlinePrimaryVertices",recVtxs);

  // get beam spot
  edm::Handle<reco::BeamSpot> beamSpot_;
  iEvent.getByLabel( "offlineBeamSpot", beamSpot_);
  const reco::BeamSpot& bs = *(beamSpot_.product());

  // reco vertex part
  int nvtx = 0;
  unsigned ntrkV = 0;
  double cDVZmin = 1000.;
  for(unsigned int ind = 0; ind < recVtxs->size(); ind++) 
    {
      if ( !((*recVtxs)[ind].isFake()) && ((*recVtxs)[ind].ndof() > 4) )
	{

	  nvtx = nvtx + 1;

	  double cPVx  = (*recVtxs)[ind].x();
	  double cPVy  = (*recVtxs)[ind].y();
	  double cPVz  = (*recVtxs)[ind].z();

	  if(nvtx == 1) {
	    PVx  = cPVx;
	    PVy  = cPVy;
	    PVz  = cPVz;
	    //      ndof(PV)>=5.0
	    //	     ntrkV = (*recVtxs)[ind].tracksSize();
	    //	    reco::Vertex::trackRef_iterator ittrk;
	    //	    for(ittrk =(*recVtxs)[ind].tracks_begin();ittrk != (*recVtxs)[ind].tracks_end(); ++ittrk) 
	    //	      if( (*recVtxs)[ind].trackWeight(*ittrk)>0.5 ) ntrkV++;
	  } else {
	    double DZ = fabs(cPVz - PVz);
	    if(DZ < cDVZmin) 
	      {
		cDVZmin = DZ;
	      } 
	  }
	}
    }

  nvertex = nvtx;
  DZmin = cDVZmin;

  // access muons and jets
  if( nvtx >= 1 ) {

    //    cout <<" nvertex = " << nvertex <<" DZmin = " << DZmin << endl;

    // muons
    RecoMuons::const_iterator imuon = reco_muons->begin(); 
    RecoMuons::const_iterator jmuon = reco_muons->end();
    for ( ; imuon != jmuon; ++imuon ) {
      if ( imuon->innerTrack().isNull() ||

	   //	   !muon::isGoodMuon(*imuon,muon::TMLastStationTight) ||
	   // (*imuon).charge()
	   !muon::isGoodMuon(*imuon,muon::GlobalMuonPromptTight) ||
	   imuon->innerTrack()->numberOfValidHits() <= 10 ||
           imuon->innerTrack()->dxy(bs) > 0.2 ) { continue; }

      pTMuonIndex[imuon->innerTrack()->pt()] = &(*imuon);

    }
    
    // fill muon variables
    map<double,const Muon*>::reverse_iterator rmfirst(pTMuonIndex.end());
    map<double,const Muon*>::reverse_iterator rmlast(pTMuonIndex.begin());
    int imu = 0;
    while (rmfirst != rmlast) {
    
      const Muon* muon = (*rmfirst).second;
      
      imu++;
      math::XYZTLorentzVector muonc(muon->innerTrack()->px(),muon->innerTrack()->py(), muon->innerTrack()->pz(), muon->innerTrack()->p()); 
      EtaMu->push_back(muon->innerTrack()->eta());
      PhiMu->push_back(muon->innerTrack()->phi());
      PtMu->push_back(muon->innerTrack()->pt());
      /*
      cout <<" muon " << imu <<" pT / eta / phi = " << muon->innerTrack()->pt() 
	   <<" "<< muon->innerTrack()->eta() 
	   <<" "<< muon->innerTrack()->phi()
	   << endl;
      */
      double dzvtx = fabs(muon->innerTrack()->dz((*recVtxs)[0].position()) );
      dzmuon->push_back(dzvtx);
      // muon isolation variables
      double muon_sumPt = muon->isolationR03().sumPt;
      double muon_emEt  = muon->isolationR03().emEt;
      double muon_hadEt = muon->isolationR03().hadEt;
      double muon_isol  = (muon_sumPt + muon_emEt + muon_hadEt) / muon->innerTrack()->pt(); 
      muisol->push_back(muon_isol);
      if (imu == 1) muon1 = muonc; 
      if (imu == 2) muon2 = muonc; 
      rmfirst++;
    }
    
    if(imu >= 2) {
      math::XYZTLorentzVector twomuons = muon1 + muon2;
      mass_mumu = twomuons.M();
    }
    
    // jets
    if(jptjetsl1l2l3->size() != 0) {

      double DR1 = 10.;
      double DR2 = 10.;

      int ic = 0;
      for(JPTJetCollection::const_iterator jptjet = jptjetsl1l2l3->begin(); jptjet != jptjetsl1l2l3->end(); ++jptjet ) { 
	if(jptjet->pt() > 20.) {
	  if(imu >= 1) { DR1 = deltaR(muon1.Eta(), muon1.Phi(), jptjet->eta(), jptjet->phi());}
	  if(imu >= 2) { DR2 = deltaR(muon2.Eta(), muon2.Phi(), jptjet->eta(), jptjet->phi());}
	  ic++;
	  /*
	  cout <<" jet = " << ic << " pTj / etaj / phij = " << jptjet->pt() <<" " << jptjet->eta() <<" " << jptjet->phi() 
	       <<" DR1 = " << DR1 
	       <<" DR2 = " 
	       << DR2 << endl;
	  */
	  // do not count jets overlapped with muons
	  if( (DR1 > 0.5) && (DR2 > 0.5) ) {
	    pTjptIndex[jptjet->pt()] = &(*jptjet);
	  }
	}
      }
    }
  }

  //  cout <<" Selected jet size = " << pTjptIndex.size() << endl;

  // fill jet variables
  int jc = 0;
  map<double,const JPTJet*>::reverse_iterator rfirst(pTjptIndex.end());
  map<double,const JPTJet*>::reverse_iterator rlast(pTjptIndex.begin());
  while (rfirst != rlast) {

    const JPTJet* jptjet = (*rfirst).second;
    RefToBase<Jet> jptjetRef = jptjet->getCaloJetRef();
    reco::CaloJet const * rawcalojet = dynamic_cast<reco::CaloJet const *>( &* jptjetRef);

    //    RefToBase<Jet> jetRef(Ref<CaloJetCollection>(calojets,jc));

    double mN90Hits  = (*jetsID)[jptjetRef].n90Hits;
    double mfHPD     = (*jetsID)[jptjetRef].fHPD;
    double mfRBX     = (*jetsID)[jptjetRef].fRBX;

    double mN90      = rawcalojet->n90();
    double mEmf      = rawcalojet->emEnergyFraction(); 	
 
    jc++;
    rfirst++;

    if(mEmf  < 0.01) continue;
    if(mfHPD > 0.98) continue;
    if(mfRBX > 0.98) continue;
    if(mN90  < 2) continue;

    // access tracks used in JPT
    TrackRefVector pionsInVertexInCalo  = jptjet->getPionsInVertexInCalo();
    TrackRefVector pionsInVertexOutCalo = jptjet->getPionsInVertexOutCalo();
    int npions = pionsInVertexInCalo.size()+pionsInVertexOutCalo.size();
    // find track with max pT and number of layers it crosses
    double pTMax = 0.;
    int NLayersPxl = 0;
    int NLayersSiI = 0;
    int NLayersSiO = 0;
    // loop over in-vertex-in calo tracks
    for (reco::TrackRefVector::const_iterator iInConeVtxTrk = pionsInVertexInCalo.begin(); 
	 iInConeVtxTrk != pionsInVertexInCalo.end(); ++iInConeVtxTrk) {
      const double pt  = (*iInConeVtxTrk)->pt();
      if(pt > pTMax) {
	pTMax = pt;
	NLayersPxl = (*iInConeVtxTrk)->hitPattern().pixelLayersWithMeasurement();
	NLayersSiI = (*iInConeVtxTrk)->hitPattern().stripTIBLayersWithMeasurement()+(*iInConeVtxTrk)->hitPattern().stripTIDLayersWithMeasurement();
	NLayersSiO = (*iInConeVtxTrk)->hitPattern().stripTOBLayersWithMeasurement()+(*iInConeVtxTrk)->hitPattern().stripTECLayersWithMeasurement();
      }
    }
    
    // loop over in-vertex-out of calo tracks
    for (reco::TrackRefVector::const_iterator iInConeVtxTrk = pionsInVertexOutCalo.begin(); 
	 iInConeVtxTrk != pionsInVertexOutCalo.end(); ++iInConeVtxTrk) {
      const double pt  = (*iInConeVtxTrk)->pt();
      if(pt > pTMax) {
	pTMax = pt;
	NLayersPxl = (*iInConeVtxTrk)->hitPattern().pixelLayersWithMeasurement();
	NLayersSiI = (*iInConeVtxTrk)->hitPattern().stripTIBLayersWithMeasurement()+(*iInConeVtxTrk)->hitPattern().stripTIDLayersWithMeasurement();
	NLayersSiO = (*iInConeVtxTrk)->hitPattern().stripTOBLayersWithMeasurement()+(*iInConeVtxTrk)->hitPattern().stripTECLayersWithMeasurement();
      }
    }

    jecUnc->setJetEta(jptjet->eta());
    jecUnc->setJetPt (jptjet->pt() ); 
    double unc = jecUnc->getUncertainty(true);
   
    //    cout <<" jet pT = " << jptjet->pt() <<" eta = " << jptjet->eta() <<" unc = " << unc << endl;

    EtaRaw->push_back(jptjetRef->eta());
    PhiRaw->push_back(jptjetRef->phi());
    EtRaw->push_back(jptjetRef->pt());
    EtaJPT->push_back(jptjet->eta());
    PhiJPT->push_back(jptjet->phi());
    EtJPT->push_back(jptjet->pt());
    Ntrk->push_back(npions);
    jesunc->push_back(unc);
    beta->push_back(jptjet->getSpecific().Zch);

    //    NPxlMaxPtTrk->push_back(NLayersPxl);
    //    NSiIMaxPtTrk->push_back(NLayersSiI);
    //    NSiOMaxPtTrk->push_back(NLayersSiO);
    /*
    cout <<" jpt jet pT = " << jptjet->pt()
	 <<" jpt eta = " << jptjet->eta() 
	 <<" jpt phi = " << jptjet->phi() 
	 <<" raw pt = " << jptjetRef->pt()
	 <<" raw eta = " << jptjetRef->eta()
	 <<" raw phi = " << jptjetRef->phi() 
	 <<" Ntrk1 = " << pionsInVertexInCalo.size()
	 <<" Ntrk2 = " << pionsInVertexOutCalo.size()
	 <<" Zch = " << jptjet->getSpecific().Zch << endl; 
    */
  }

  //  cout <<" mass mumu = " << mass_mumu <<" jc = " <<jc << endl; 

  // fill tree
  //  if( (mass_mumu >= 50.) && (pTjptIndex.size() != 0) ) t1->Fill();
  if( mass_mumu >= 40. ) t1->Fill();
}

//define this as a plug-in
DEFINE_FWK_MODULE(DiMuAnalysis_Data);
