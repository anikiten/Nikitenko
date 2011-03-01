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

class JetPlusTrackAnalysis_Data : public edm::EDAnalyzer {
public:
  explicit JetPlusTrackAnalysis_Data(const edm::ParameterSet&);
  ~JetPlusTrackAnalysis_Data();


private:
  //      virtual void beginJob(const edm::EventSetup&) ;
  virtual void beginJob() ;
  virtual void analyze(const edm::Event&, const edm::EventSetup&);
  virtual void endJob() ;

  // ----------member data ---------------------------
  // output root file
  string fOutputFileName ;
  // names of modules, producing object collections
  // raw calo jet ID map
  InputTag jetsIDSrc;
  // calo jets
  InputTag calojetsSrc; 
  // JPT jets
  InputTag JPTjetsSrc;
  // MC jet corrections
  //  string JetCorrectionMC;
  // PF jet corrections
  //  string JetCorrectionPF;
  // HLT result
  InputTag srcTriggerResults_;

  // variables to store in ntpl
  int     jjpt;
  int     run, event;
  double  PVx, PVy, PVz;
  // eta/phi/pt of raw calo jet from JPT

  std::vector<double> *EtaRaw;
  std::vector<double> *PhiRaw;
  std::vector<double> *EtRaw;
  // eta/phi/pt of JPT jets
  std::vector<double> *EtaJPT;
  std::vector<double> *PhiJPT;
  std::vector<double> *EtJPT;
  // N in-vertex-cone tracks
  std::vector<int>    *Ntrk;
  // in-cone-in vertex track with max pT
  std::vector<double> *pTtrkMax;
  // number of Pxl and silicon inner and outer layers used for trk. measurement
  std::vector<int>    *NPxlMaxPtTrk;  
  std::vector<int>    *NSiIMaxPtTrk;  
  std::vector<int>    *NSiOMaxPtTrk;  
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
//JetPlusTrackAnalysis_Data::beginJob(const edm::EventSetup&)
JetPlusTrackAnalysis_Data::beginJob()
{
  using namespace edm;

  EtaRaw       = new std::vector<double>();
  PhiRaw       = new std::vector<double>();
  EtRaw        = new std::vector<double>();
  EtaJPT       = new std::vector<double>();
  PhiJPT       = new std::vector<double>();
  EtJPT        = new std::vector<double>();
  Ntrk         = new std::vector<int>();
  pTtrkMax     = new std::vector<double>();
  NPxlMaxPtTrk = new std::vector<int>();
  NSiIMaxPtTrk = new std::vector<int>();
  NSiOMaxPtTrk = new std::vector<int>();

  // creating a simple tree

  hOutputFile   = new TFile( fOutputFileName.c_str(), "RECREATE" ) ;

  t1 = new TTree("t1","analysis tree");

  t1->Branch("jjpt",&jjpt,"jjpt/I");
  t1->Branch("run",&run,"run/I");
  t1->Branch("event",&event,"event/I");

  t1->Branch("PVx",&PVx,"PVx/D");
  t1->Branch("PVy",&PVy,"PVy/D");
  t1->Branch("PVz",&PVz,"PVz/D");

  t1->Branch("EtaRaw","vector<double>",&EtaRaw);
  t1->Branch("PhiRaw","vector<double>",&PhiRaw);
  t1->Branch("EtRaw" ,"vector<double>",&EtRaw);
  t1->Branch("EtaJPT","vector<double>",&EtaJPT);
  t1->Branch("PhiJPT","vector<double>",&PhiJPT);
  t1->Branch("EtJPT" ,"vector<double>",&EtJPT);
  t1->Branch("pTtrkMax" ,"vector<double>",&pTtrkMax);
  t1->Branch("Ntrk","vector<int>",&Ntrk);
  t1->Branch("NPxlMaxPtTrk","vector<int>",&NPxlMaxPtTrk);
  t1->Branch("NSiIMaxPtTrk","vector<int>",&NSiIMaxPtTrk);
  t1->Branch("NSiOMaxPtTrk","vector<int>",&NSiOMaxPtTrk);

  return ;
}

// ------------ method called once each job just after ending the event loop  ------------
void 
JetPlusTrackAnalysis_Data::endJob() {

  hOutputFile->Write() ;
  hOutputFile->Close() ;
  
  return ;
}

//
// constructors and destructor
//
JetPlusTrackAnalysis_Data::JetPlusTrackAnalysis_Data(const edm::ParameterSet& iConfig)

{
   //now do what ever initialization is needed
  using namespace edm;
  // 
  // get name of output file with histogramms
  fOutputFileName = iConfig.getUntrackedParameter<string>("HistOutFile");
  //
  // get names of input object collections
  // raw calo jets
  jetsIDSrc        = iConfig.getParameter<edm::InputTag>("jetsID");
  // JPT jets
  JPTjetsSrc       = iConfig.getParameter<edm::InputTag>("JPTjets");
  // calo jets
  calojetsSrc      = iConfig.getParameter<edm::InputTag>("calojets");
  // MC corrections
  //  JetCorrectionMC  = iConfig.getParameter< std::string > ("JetCorrectionMC");
  // PF corrections
  //  JetCorrectionPF  = iConfig.getParameter< std::string > ("JetCorrectionPF");
  // HLT results
  srcTriggerResults_ = iConfig.getParameter<edm::InputTag> ("TriggerResults");
}


JetPlusTrackAnalysis_Data::~JetPlusTrackAnalysis_Data()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called to for each event  ------------
void
JetPlusTrackAnalysis_Data::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
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
   
   // HLT
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
}

//define this as a plug-in
DEFINE_FWK_MODULE(JetPlusTrackAnalysis_Data);
