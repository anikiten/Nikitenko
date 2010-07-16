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
#include "FWCore/ParameterSet/interface/InputTag.h"
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

#include "DataFormats/L1Trigger/interface/L1EmParticleFwd.h"
#include "DataFormats/L1Trigger/interface/L1EmParticle.h"
#include "DataFormats/L1Trigger/interface/L1JetParticleFwd.h"
#include "DataFormats/L1Trigger/interface/L1JetParticle.h"
#include "DataFormats/L1Trigger/interface/L1MuonParticleFwd.h"
#include "DataFormats/L1Trigger/interface/L1MuonParticle.h"
#include "DataFormats/L1Trigger/interface/L1EtMissParticleFwd.h"
#include "DataFormats/L1Trigger/interface/L1EtMissParticle.h"
#include "DataFormats/L1Trigger/interface/L1HFRingsFwd.h"
#include "DataFormats/L1Trigger/interface/L1HFRings.h"
#include "DataFormats/L1GlobalTrigger/interface/L1GlobalTriggerReadoutRecord.h"

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
#include "MagneticField/Records/interface/IdealMagneticFieldRecord.h"
#include "Geometry/Records/interface/IdealGeometryRecord.h"
#include "Geometry/CaloGeometry/interface/CaloCellGeometry.h"
#include "Geometry/CaloGeometry/interface/CaloGeometry.h"
//jets
#include "DataFormats/JetReco/interface/CaloJet.h"
#include "DataFormats/JetReco/interface/CaloJetCollection.h"
#include "DataFormats/JetReco/interface/JPTJetCollection.h"
#include "DataFormats/JetReco/interface/JPTJet.h"
#include "DataFormats/JetReco/interface/GenJet.h"
#include "DataFormats/JetReco/interface/GenJetCollection.h"
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
// candidates
#include "DataFormats/Candidate/interface/LeafCandidate.h"
#include "DataFormats/Candidate/interface/Candidate.h"
#include "DataFormats/Candidate/interface/CandidateFwd.h"
//
#include "TFile.h"
#include "TTree.h"
#include "TH1.h"
#include "TH2.h"
//
#include "DataFormats/Math/interface/LorentzVector.h"
#include "DataFormats/Math/interface/Vector3D.h"
#include "Math/GenVector/VectorUtil.h"
#include "Math/GenVector/PxPyPzE4D.h"

//
using namespace std;
using namespace reco;

//
// class decleration
//

class AccessL1HLT : public edm::EDAnalyzer {
public:
  explicit AccessL1HLT(const edm::ParameterSet&);
  ~AccessL1HLT();


private:
  //      virtual void beginJob(const edm::EventSetup&) ;
  virtual void beginJob() ;
  virtual void analyze(const edm::Event&, const edm::EventSetup&);
  virtual void endJob() ;

  // ----------member data ---------------------------
  InputTag srcL1CenJet;
  InputTag srcL1TauJet;
  InputTag srcL1FwdJet;
  InputTag srcTriggerResults_;
};

//
// constants, enums and typedefs
//

//
// static data member definitions
//

// ------------ method called once each job just before starting event loop  ------------
void 
//AccessL1HLT::beginJob(const edm::EventSetup&)
AccessL1HLT::beginJob()
{
  return ;
}

// ------------ method called once each job just after ending the event loop  ------------
void 
AccessL1HLT::endJob() {
  return ;
}

//
// constructors and destructor
//
AccessL1HLT::AccessL1HLT(const edm::ParameterSet& iConfig)
{
   //now do what ever initialization is needed
  using namespace edm;
  // 
  srcL1CenJet  = iConfig.getParameter<edm::InputTag>("L1CenJet");
  srcL1TauJet  = iConfig.getParameter<edm::InputTag>("L1TauJet");
  srcL1FwdJet  = iConfig.getParameter<edm::InputTag>("L1FwdJet");
  srcTriggerResults_ = iConfig.getParameter<edm::InputTag> ("TriggerResults");
}


AccessL1HLT::~AccessL1HLT()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called to for each event  ------------
void
AccessL1HLT::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  using namespace edm;

  // L1
   edm::Handle<L1GlobalTriggerReadoutRecord> l1GtRR;
   iEvent.getByLabel("gtDigis",l1GtRR);
   
   //   edm::Handle<L1GlobalTriggerObjectMapRecord> l1GtOMRec;
   //   iEvent.getByLabel("hltL1GtObjectMap",l1GtOMRec);
   
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
   
   // HLT
   edm::Handle<TriggerResults> triggerResults;
   iEvent.getByLabel(srcTriggerResults_,triggerResults);

   const edm::TriggerNames & triggerNames = iEvent.triggerNames(*triggerResults);

   //   unsigned index = triggerNames.triggerIndex("HLT_PhysicsDeclared");
   //   bool physdecl= (index<triggerNames.size()&&triggerResults->accept(index)) ? 1 : 0;

   std::string Photon10 = "HLT_Photon10_L1R";

   for(unsigned ihlt = 0; ihlt < triggerNames.size(); ihlt++) {
     unsigned index = triggerNames.triggerIndex(triggerNames.triggerName(ihlt));
     if ( triggerNames.triggerName(ihlt) == Photon10) {
       std::cout <<" HLT bit " << ihlt <<" name = " << triggerNames.triggerName(ihlt) 
		 <<" accepted = " << triggerResults->accept(ihlt) <<" index = " << index << std::endl; 
     }
   }

   edm::Handle<l1extra::L1JetParticleCollection> lCenJet;
   edm::Handle<l1extra::L1JetParticleCollection> lFwdJet;
   edm::Handle<l1extra::L1JetParticleCollection> lTauJet;

   iEvent.getByLabel(srcL1CenJet,lCenJet);
   iEvent.getByLabel(srcL1TauJet,lTauJet);
   iEvent.getByLabel(srcL1FwdJet,lFwdJet);
   
   std::cout <<" N taus = " << lTauJet->size()
	     <<" N cent = " << lCenJet->size()
	     <<" N forw = " << lFwdJet->size() << std::endl;
 
   if (lTauJet.isValid()) 
     {
       for (l1extra::L1JetParticleCollection::const_iterator iter = lTauJet->begin(); iter != lTauJet->end(); iter++)
	 {
	   // variables ...
	   std::cout <<" Taus:  pt = " << (*iter).pt() << std::endl;
	   /*
	     lVars.pT = (*iter).pt();
	     lVars.ET = (*iter).et();
	     lVars.eta = (*iter).eta();
	     lVars.phi = (*iter).phi();
	     lVars.bx = (*iter).bx();
	   */
	 }
     }


   /*
  //  std::map<double,int> pTjptIndex;

  std::map<double,const JPTJet*> pTjptIndex;

  jjpt = 0;
  run = iEvent.id().run();
  event = iEvent.id().event();
  PVx = -1000.; 
  PVy = -1000.; 
  PVz = -1000.;
  EtaRaw->clear();
  PhiRaw->clear();
  EtJPT->clear();
  EtaJPT->clear();
  PhiJPT->clear();
  EtJPT->clear();
  pTtrkMax->clear(); 
  Ntrk->clear();
  NPxlMaxPtTrk->clear();
  NSiIMaxPtTrk->clear();
  NSiOMaxPtTrk->clear();

  // initialize vector containing four highest Et gen jets > 20 GeV
  //   vector<CLHEP::HepLorentzVector> gjets;
  //   gjets.clear();
  
  // get jet ID map
  edm::Handle<ValueMap<reco::JetID> > jetsID;
  iEvent.getByLabel(jetsIDSrc,jetsID);

   // pf jets
  edm::Handle<PFJetCollection> pfjetsakt5;
  iEvent.getByLabel("ak5PFJets", pfjetsakt5);
   
  // JPT jets
  edm::Handle<reco::JPTJetCollection> jptjets;
  iEvent.getByLabel(JPTjetsSrc, jptjets);
  
  // Calo jets
  edm::Handle<CaloJetCollection> calojets;
  iEvent.getByLabel(calojetsSrc, calojets);

  // get vertex
  edm::Handle<reco::VertexCollection> recVtxs;
  iEvent.getByLabel("offlinePrimaryVertices",recVtxs);

  int nvtx = 0;
  unsigned ntrkV = 0;
  
  
  for(unsigned int ind = 0; ind < recVtxs->size(); ind++) 
    {
      if (!((*recVtxs)[ind].isFake())) 
	{
	  nvtx = nvtx + 1;
	  if(nvtx == 1) {
	    PVx  = (*recVtxs)[ind].x();
	    PVy  = (*recVtxs)[ind].y();
	    PVz  = (*recVtxs)[ind].z();
	    //      ndof(PV)>=5.0
	    //	     ntrkV = (*recVtxs)[ind].tracksSize();
	    reco::Vertex::trackRef_iterator ittrk;
	    for(ittrk =(*recVtxs)[ind].tracks_begin();ittrk != (*recVtxs)[ind].tracks_end(); ++ittrk) 
	      if( (*recVtxs)[ind].trackWeight(*ittrk)>0.5 ) ntrkV++; 
	    }
	}
    }
  
  if( (nvtx == 1) && (ntrkV > 3) && (ntrkV < 100) ) {

     // PF jet energy corrections
    //    const JetCorrector* correctorPF = JetCorrector::getJetCorrector (JetCorrectionPF, iSetup);
    
    // MC jet energy corrections
    //    const JetCorrector* correctorMC = JetCorrector::getJetCorrector (JetCorrectionMC, iSetup);
     
    if(jptjets->size() != 0) {

      for(JPTJetCollection::const_iterator jptjet = jptjets->begin(); jptjet != jptjets->end(); ++jptjet ) { 
	if(jptjet->pt() > 10.) {
	  pTjptIndex[jptjet->pt()] = &(*jptjet);
	}
      }
    }
  }

  int jc = 0;
  //      for(map<double,int>::reverse_iterator it = pTjptIndex.end(); it != pTjptIndex.begin(); ++it) {
  map<double,const JPTJet*>::reverse_iterator rfirst(pTjptIndex.end());
  map<double,const JPTJet*>::reverse_iterator rlast(pTjptIndex.begin());
  while (rfirst != rlast) {

    //    cout <<" jc = " << jc <<" energy = " << (*rfirst).first <<" jet energy = " << ((*rfirst).second)->pt() << endl;

    const JPTJet* jptjet = (*rfirst).second;
    RefToBase<Jet> jptjetRef = jptjet->getCaloJetRef();
    reco::CaloJet const * rawcalojet = dynamic_cast<reco::CaloJet const *>( &* jptjetRef);

    //    RefToBase<Jet> jetRef(Ref<CaloJetCollection>(calojets,jc));

    double mN90Hits_jpt  = (*jetsID)[jptjetRef].n90Hits;
    double mfHPD_jpt     = (*jetsID)[jptjetRef].fHPD;
    double mfRBX_jpt     = (*jetsID)[jptjetRef].fRBX;

    double mN90      = rawcalojet->n90();
    double mEmf      = rawcalojet->emEnergyFraction(); 	
    
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
    
    EtaRaw->push_back(jptjetRef->eta());
    PhiRaw->push_back(jptjetRef->phi());
    EtJPT->push_back(jptjetRef->pt());
    EtaJPT->push_back(jptjet->eta());
    PhiJPT->push_back(jptjet->phi());
    EtJPT->push_back(jptjet->pt());
    pTtrkMax->push_back(pTMax);
    Ntrk->push_back(npions);
    NPxlMaxPtTrk->push_back(NLayersPxl);
    NSiIMaxPtTrk->push_back(NLayersSiI);
    NSiOMaxPtTrk->push_back(NLayersSiO);
    
    cout <<" jpt jet pT = " << jptjet->pt()
	 <<" jpt eta = " << jptjet->eta() 
	 <<" jpt phi = " << jptjet->phi() 
	 <<" raw pt = " << jptjetRef->pt()
	 <<" raw eta = " << jptjetRef->eta()
	 <<" raw phi = " << jptjetRef->phi() 
	 <<" Ntrk1 = " << pionsInVertexInCalo.size()
	 <<" Ntrk2 = " << pionsInVertexOutCalo.size() << endl; 
    jc++;
    rfirst++;
  }
  // fill tree
  if(pTjptIndex.size() != 0) t1->Fill();
   */
}


//define this as a plug-in
DEFINE_FWK_MODULE(AccessL1HLT);
