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
#include "FWCore/Utilities/interface/InputTag.h"
//#include "FWCore/ParameterSet/interface/InputTag.h"
//
// HLT/L1 and Trigger data formats
#include "HLTrigger/HLTcore/interface/HLTConfigProvider.h"
#include "L1Trigger/GlobalTriggerAnalyzer/interface/L1GtUtils.h"
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
#include "DataFormats/HLTReco/interface/TriggerEvent.h"

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

  L1GtUtils m_l1GtUtils;
  HLTConfigProvider hltConfig_;

  //      virtual void beginJob(const edm::EventSetup&) ;
  virtual void beginRun(edm::Run const &, edm::EventSetup const&) ;
  virtual void beginJob() ;
  virtual void analyze(const edm::Event&, const edm::EventSetup&);
  virtual void endJob() ;
  

  // ----------member data ---------------------------
  edm::InputTag  srcL1CenJet;
  edm::InputTag  srcL1TauJet;
  edm::InputTag  srcL1FwdJet;
  edm::InputTag  srcHLTSummary;
  edm::InputTag  srcTriggerResults_;
  std::vector<edm::InputTag> hltPaths_;

  // counters
  double ntot;
  double ntau30;
  double ntau20;
  double ntaumet30;
  double ntaumet20;
};

//
// constants, enums and typedefs
//

//
// static data member definitions
//

//
void
AccessL1HLT::beginRun(edm::Run const & iRun, edm::EventSetup const& iSetup)
{
  bool changed(true);
  hltConfig_.init(iRun,iSetup,"HLT",changed);
}
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
  srcL1CenJet   = iConfig.getParameter<edm::InputTag>("L1CenJet");
  srcL1TauJet   = iConfig.getParameter<edm::InputTag>("L1TauJet");
  srcL1FwdJet   = iConfig.getParameter<edm::InputTag>("L1FwdJet");
  srcHLTSummary = iConfig.getParameter<edm::InputTag> ("HLTSummary");
  srcTriggerResults_ = iConfig.getParameter<edm::InputTag> ("TriggerResults");
  hltPaths_          = iConfig.getParameter<std::vector<edm::InputTag> >("HLTPaths");

  // counters
  ntot      = 0; 
  ntau30    = 0;
  ntau20    = 0;
  ntaumet30 = 0;
  ntaumet20 = 0;
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

  ntot += 1.;

  // L1

  m_l1GtUtils.retrieveL1EventSetup(iSetup);
  int iErrorCode = -1;
  std::string m_nameAlgTechTrig = "L1_ETM20";
  bool l1_etm20 = m_l1GtUtils.decisionBeforeMask(iEvent, m_nameAlgTechTrig, iErrorCode);
  
  /*
  // Algo bits
  edm::ESHandle<L1GtTriggerMenu> menuRcd;
  iSetup.get<L1GtTriggerMenuRcd>().get(menuRcd) ;
  const L1GtTriggerMenu* menu = menuRcd.product();
  
  for (CItAlgo algo = menu->gtAlgorithmMap().begin(); algo != menu->gtAlgorithmMap().end(); ++algo) {
    int algBitNumber = ( algo->second).algoBitNumber();
    std::cout << " algo bits " << algBitNumber 
    << " name: "  << (algo->second).algoName() 
    << " alias: " << (algo->second).algoAlias() 
    << " decision = " << m_l1GtUtils.decisionBeforeMask(iEvent,(algo->second).algoName(),iErrorCode) << std::endl;
    }
  */    

  /*
  // Technical bits
  for (CItAlgo techTrig = menu->gtTechnicalTriggerMap().begin(); techTrig != menu->gtTechnicalTriggerMap().end(); ++techTrig) {
  int techBitNumber = ( techTrig->second).algoBitNumber();
  //technical
  //       if(techBitNumber ==40) 
  std::cout << " tech bits " 
  << techBitNumber << " "
  << (techTrig->second).algoName() << std::endl;
  }
  */
  
  //int printVerbosity = 0;
  //menu->print(std::cout, printVerbosity);
   
   // HLT
   edm::Handle<TriggerResults> triggerResults;
   iEvent.getByLabel(srcTriggerResults_,triggerResults);

   const edm::TriggerNames & triggerNames = iEvent.triggerNames(*triggerResults);

   //   unsigned index = triggerNames.triggerIndex("HLT_PhysicsDeclared");
   //   bool physdecl= (index<triggerNames.size()&&triggerResults->accept(index)) ? 1 : 0;

   for(unsigned ihlt = 0; ihlt < triggerNames.size(); ihlt++) {
     unsigned index = triggerNames.triggerIndex(triggerNames.triggerName(ihlt));
     //     if( (ihlt == 0) || (ihlt == 2) ) {
       int prescale = hltConfig_.prescaleValue(iEvent, iSetup,triggerNames.triggerName(ihlt));
       std::cout <<" ==> HLT bit " << ihlt 
		 <<" name = " << triggerNames.triggerName(ihlt)
		 <<" prescale = " << prescale 
		 <<" accepted = " << triggerResults->accept(ihlt) 
		 <<" l1_etm20 = " << l1_etm20 << std::endl; 
       if( (triggerResults->accept(ihlt) == 1) && (ihlt == 0) ){ntau30 += 1.;}
       if( (triggerResults->accept(ihlt) == 1) && (ihlt == 2) ){ntau20 += 1.;}
       if( (triggerResults->accept(ihlt) == 1) && (ihlt == 0) && (l1_etm20 == 1) ) {ntaumet30 += 1.;}
       if( (triggerResults->accept(ihlt) == 1) && (ihlt == 2) && (l1_etm20 == 1) ) {ntaumet20 += 1.;}
       //     }
   }

   std::cout <<"     ntot = " << ntot
	     <<" ntau30 = " << ntau30
	     <<" ntau20 = " << ntau20
	     <<" ntaumet30 = " << ntaumet30 
	     <<" ntaumet20 = " << ntaumet20 << std::endl;

   /*
   edm::Handle<l1extra::L1JetParticleCollection> lCenJet;
   edm::Handle<l1extra::L1JetParticleCollection> lFwdJet;
   edm::Handle<l1extra::L1JetParticleCollection> lTauJet;

   iEvent.getByLabel(srcL1CenJet,lCenJet);
   iEvent.getByLabel(srcL1FwdJet,lFwdJet);
   iEvent.getByLabel(srcL1TauJet,lTauJet);
   
   std::cout <<" N taus = " << lTauJet->size()
	     <<" N cent = " << lCenJet->size()
	     <<" N forw = " << lFwdJet->size() << std::endl;
 
   if (lTauJet.isValid()) 
     {
       for (l1extra::L1JetParticleCollection::const_iterator iter = lTauJet->begin(); iter != lTauJet->end(); iter++)
	 {
	   // variables ...
	   std::cout <<" L1 Taus:  pt = " << (*iter).pt() 
		     <<" eta = " << (*iter).eta()
		     <<" phi = " << (*iter).phi() << std::endl;

//	     lVars.bx = (*iter).bx();
	 }
     }
*/

   // HLT staff
   //  access objects passed your filter

   /*  from Mike
     If you want to have a complicated path with many filters
     and you need to access each of those then please use
     TriggerEventWithRefs
     A good example in Tau HLT DQM is
     here :
     
     http://cmssw.cvs.cern.ch/cgi-bin/cmssw.cgi/CMSSW/DQM/HLTEvF/src/HLTTauDQMPathPlotter.cc?revision=1.9&view=markup
     
     Check the getFilterCollectiion
   */


   /* example frrom Sam 
      edm::Handle<trigger::TriggerEvent> trigEvt;
      iEvent.getByLabel("hltTriggerSummaryAOD",hltTag,trigEvt);
      
      size_t filterNrInEvt = trigEvt->filterIndex(edm::InputTag(filterName,"",hltTag).encode());
      if(filterNrInEvt<trigEvt->sizeFilters()){ //filter found in event
      
      const trigger::Keys& trigKeys = trigEvt->filterKeys(filterNrInEvt);  //trigger::Keys is actually a vector<uint16_t> holding
      the position of trigger objects in the trigger collection passing the filter
      const trigger::TriggerObjectCollection & trigObjColl(trigEvt->getObjects());
      for(trigger::Keys::const_iterator keyIt=trigKeys.begin();keyIt!=trigKeys.end();++keyIt){ //we now have access to all triggerobjects passing filter
      float trigObjEta = trigObjColl[*keyIt].eta();
      float trigObjPhi = trigObjColl[*keyIt].phi();
      if (reco::deltaR(detEta,detPhi,trigObjEta,trigObjPhi) < maxDeltaR){
      return true;
      }//end dR<maxDeltaR trig obj match test
    }//end loop over all objects passing filter
    }//check filter is present in event
    return false;
    }
   */

   // Working example
   /*
   edm::Handle<trigger::TriggerEvent> lHltSummary;
   iEvent.getByLabel(srcHLTSummary,lHltSummary);

   if (lHltSummary.isValid()) {

     const trigger::TriggerObjectCollection & toc(lHltSummary->getObjects());
     
     //cout
     for (unsigned i=0; i < lHltSummary->sizeFilters(); i++){
       const edm::InputTag & lTag = lHltSummary->filterTag(i);
       std::cout << "ele " << i << ": " << lTag << std::endl;
     }
     
     for (unsigned i(0); i < hltPaths_.size(); i++){
       const int index = lHltSummary->filterIndex(hltPaths_[i]);
       //       if (index >= lHltSummary->sizeFilters()) {
       std::cout << " ---> My filter " << hltPaths_[i] << std::endl;
       //       continue;
       //     }
       const trigger::Keys & k = lHltSummary->filterKeys(index);
       
       for (trigger::Keys::const_iterator ki = k.begin(); ki !=k.end(); ++ki ) {
	 std::cout <<"       pT = " << toc[*ki].pt()
		   <<" eta = " << toc[*ki].eta()
		   <<" phi = " << toc[*ki].phi()
		   <<" id = " << toc[*ki].id() << std::endl;
	 // ... variables ...
	 //	 lVars.pT = toc[*ki].pt();
	 //	 lVars.eta = toc[*ki].eta();
	 //	 lVars.phi = toc[*ki].phi();
	 //	 lVars.id = toc[*ki].id();
	 //	 lVars.mass = toc[*ki].mass();
       }
     }
   }
   */
}


//define this as a plug-in
DEFINE_FWK_MODULE(AccessL1HLT);
