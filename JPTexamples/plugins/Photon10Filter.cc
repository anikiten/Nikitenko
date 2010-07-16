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
#include "FWCore/Framework/interface/EDFilter.h"

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

class Photon10Filter : public edm::EDFilter {
public:
   Photon10Filter(const edm::ParameterSet&);
  ~Photon10Filter();

  //      virtual void beginJob(const edm::EventSetup&) ;
  virtual void beginJob() ;
  virtual bool filter(edm::Event&, const edm::EventSetup&);
  virtual void endJob() ;

  // ----------member data ---------------------------

private:
  // HLT result
  InputTag srcTriggerResults_;
  int accepted;

};

//
// constants, enums and typedefs
//

//
// static data member definitions
//

// ------------ method called once each job just before starting event loop  ------------
void 
//Photon10Filter::beginJob(const edm::EventSetup&)
Photon10Filter::beginJob()
{
  return ;
}

// ------------ method called once each job just after ending the event loop  ------------
void 
Photon10Filter::endJob() {
  return ;
}

//
// constructors and destructor
//
Photon10Filter::Photon10Filter(const edm::ParameterSet& iConfig)

{
   //now do what ever initialization is needed
  using namespace edm;
  // HLT results
  srcTriggerResults_ = iConfig.getParameter<edm::InputTag> ("TriggerResults");
  accepted = 0;
}


Photon10Filter::~Photon10Filter()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called to for each event  ------------
bool
Photon10Filter::filter(edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  using namespace edm;

  bool retcode = false;

  /*
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
   */

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
       if (triggerResults->accept(ihlt) == 1) {
	 retcode = true;
	 accepted = accepted + 1;
	 std::cout <<" event accepted ! = " << accepted << std::endl;
       }
     }
   }
    return retcode; 
}

//define this as a plug-in
DEFINE_FWK_MODULE(Photon10Filter);
