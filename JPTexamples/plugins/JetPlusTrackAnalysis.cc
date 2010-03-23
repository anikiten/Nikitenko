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
#include "FWCore/Framework/interface/TriggerNames.h"
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

using namespace std;
using namespace reco;

//
// class decleration
//

class JetPlusTrackAnalysis : public edm::EDAnalyzer {
public:
  explicit JetPlusTrackAnalysis(const edm::ParameterSet&);
  ~JetPlusTrackAnalysis();


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
//JetPlusTrackAnalysis::beginJob(const edm::EventSetup&)
JetPlusTrackAnalysis::beginJob()
{
  using namespace edm;

  EtaRaw       = new std::vector<double>();
  PhiRaw       = new std::vector<double>();
  EtRaw        = new std::vector<double>();
  EtaJPT       = new std::vector<double>();
  PhiJPT       = new std::vector<double>();
  EtJPT        = new std::vector<double>();
  Ntrk         = new std::vector<int>();
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
  t1->Branch("Ntrk","vector<int>",&Ntrk);
  t1->Branch("NPxlMaxPtTrk","vector<int>",&NPxlMaxPtTrk);
  t1->Branch("NSiIMaxPtTrk","vector<int>",&NSiIMaxPtTrk);
  t1->Branch("NSiOMaxPtTrk","vector<int>",&NSiOMaxPtTrk);

  return ;
}

// ------------ method called once each job just after ending the event loop  ------------
void 
JetPlusTrackAnalysis::endJob() {

  hOutputFile->Write() ;
  hOutputFile->Close() ;
  
  return ;
}

//
// constructors and destructor
//
JetPlusTrackAnalysis::JetPlusTrackAnalysis(const edm::ParameterSet& iConfig)

{
   //now do what ever initialization is needed
  using namespace edm;
  // 
  // get name of output file with histogramms
  fOutputFileName = iConfig.getUntrackedParameter<string>("HistOutFile");
  //
  // get names of input object collections
  // raw calo jets
  jetsIDSrc        = iConfig.getParameter<edm::InputTag> ("jetsID");
  // JPT jets
  JPTjetsSrc       = iConfig.getParameter<edm::InputTag>("JPTjets");
  // MC corrections
  //  JetCorrectionMC  = iConfig.getParameter< std::string > ("JetCorrectionMC");
  // PF corrections
  //  JetCorrectionPF  = iConfig.getParameter< std::string > ("JetCorrectionPF");
  // HLT results
  srcTriggerResults_ = iConfig.getParameter<edm::InputTag> ("TriggerResults");
}


JetPlusTrackAnalysis::~JetPlusTrackAnalysis()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called to for each event  ------------
void
JetPlusTrackAnalysis::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
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

   edm::TriggerNames triggerNames;
   triggerNames.init(*triggerResults);

   unsigned index = triggerNames.triggerIndex("HLT_PhysicsDeclared");
   bool physdecl= (index<triggerNames.size()&&triggerResults->accept(index)) ? 1 : 0;

   for(unsigned ihlt = 0; ihlt < triggerNames.size(); ihlt++) {
     std::cout <<" HLT bit " << ihlt <<" name = " << triggerNames.triggerName(ihlt) 
	       <<" accepted = " << triggerResults->accept(ihlt) <<" index = " << index << std::endl; 
   }
*/

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
	cout <<" jet pT = " << jptjet->pt()
	     <<" eta = " << jptjet->eta() 
	     <<" phi = " << jptjet->phi() << endl; 
      }
    }
  }

   /*
     //start from here
     // raw jet selection 
	 RefToBase<Jet> jetRef(Ref<CaloJetCollection>(calojets,jc));
	 double mN90      = (*calojets)[jc].n90();
	 double mEmf      = (*calojets)[jc].emEnergyFraction(); 	
	 double mN90Hits  = (*jetsID)[jetRef].n90Hits;
	 double mfHPD     = (*jetsID)[jetRef].fHPD;
	 double mfRBX     = (*jetsID)[jetRef].fRBX; 
	 
	 jc++;
	 
	 // good jet selections
	 // loose selections (in // part of tight for inclusive jets: need to add sigma_eta, sigma_phi

	 if(mEmf < 0.01) continue;
	 if(mfHPD>0.98) continue;
	 if(mN90Hits < 2) continue;
	 if(fabs(cjet->eta()) > 2.0) continue;
     */

	 //
     //	 CLHEP::HepLorentzVector cjetc(cjet->px(), cjet->py(), cjet->pz(), cjet->energy());

     // MC correction
     //     double scaleMC = correctorMC->correction(cjet->p4());
     
     /*
     if(jjpt <= 2) {

	     // track info
	     jpt::MatchedTracks pions;
	     jpt::MatchedTracks muons;
	     jpt::MatchedTracks electrons;
	     const bool particlesOK = true;
	     jptCorrector_ = dynamic_cast<const JetPlusTrackCorrector*>(correctorJPT);
	     jptCorrector_->matchTracks((*zspjet),iEvent,iSetup,pions,muons,electrons);
	     int NtrkJPT = pions.inVertexOutOfCalo_.size() + pions.inVertexInCalo_.size();
	     
	     double pTtrkMax = 0.;
	     double pTMax = 0.;
	     int NLayersMaxPtTrk = 0;
	     int NPxlMaxPtTrk = 0;

	     for (reco::TrackRefVector::const_iterator iInConeVtxTrk = pions.inVertexOutOfCalo_.begin(); 
		  iInConeVtxTrk != pions.inVertexOutOfCalo_.end(); ++iInConeVtxTrk) {

	       const double pt  = (*iInConeVtxTrk)->pt();
	       if(pt > pTMax) {
		 pTtrkMax = pt;
		 pTMax = pTtrkMax;
		 NPxlMaxPtTrk    = (*iInConeVtxTrk)->hitPattern().pixelLayersWithMeasurement();
		 NLayersMaxPtTrk = (*iInConeVtxTrk)->hitPattern().trackerLayersWithMeasurement();
	       }
	
	       int nNLayersPxl = (*iInConeVtxTrk)->hitPattern().pixelLayersWithMeasurement();
	       
	       int nNLayersStI = (*iInConeVtxTrk)->hitPattern().stripTIBLayersWithMeasurement() +
		                 (*iInConeVtxTrk)->hitPattern().stripTIDLayersWithMeasurement();

	       int nNLayersStO = (*iInConeVtxTrk)->hitPattern().stripTOBLayersWithMeasurement() +
		                 (*iInConeVtxTrk)->hitPattern().stripTECLayersWithMeasurement();

	       NLayersPxl[nNLayersPxl] += 1; 
	       NLayersStI[nNLayersStI] += 1; 
	       NLayersStO[nNLayersStO] += 1;
 
	     }
	   
	     for (reco::TrackRefVector::const_iterator iInConeVtxTrk = pions.inVertexInCalo_.begin(); 
		  iInConeVtxTrk != pions.inVertexInCalo_.end(); ++iInConeVtxTrk) {

	       const double pt  = (*iInConeVtxTrk)->pt();
	       if(pt > pTMax) {
		 pTtrkMax = pt;
		 pTMax = pTtrkMax;
		 NPxlMaxPtTrk    = (*iInConeVtxTrk)->hitPattern().pixelLayersWithMeasurement();
		 NLayersMaxPtTrk = (*iInConeVtxTrk)->hitPattern().trackerLayersWithMeasurement();
	       }

	       int nNLayersPxl = (*iInConeVtxTrk)->hitPattern().pixelLayersWithMeasurement();
	       
	       int nNLayersStI = (*iInConeVtxTrk)->hitPattern().stripTIBLayersWithMeasurement() +
		                 (*iInConeVtxTrk)->hitPattern().stripTIDLayersWithMeasurement();

	       int nNLayersStO = (*iInConeVtxTrk)->hitPattern().stripTOBLayersWithMeasurement() +
		                 (*iInConeVtxTrk)->hitPattern().stripTECLayersWithMeasurement();

	       NLayersPxl[nNLayersPxl] += 1; 
	       NLayersStI[nNLayersStI] += 1; 
	       NLayersStO[nNLayersStO] += 1;
 
	     }

	     double EtPFJ  = 0.;
	     double EtaPFJ = 0.;
	     double PhiPFJ = 0.;
	     double DRMAX  = 1000.;
	     double DRPFJ  = 1000.;
	     double scalePFJ = 0.;
	     // match with JPT jets. find closest pf jet in eta/phi
	     for (PFJetCollection::const_iterator itpfj = pfjetsakt5->begin();
		  itpfj != pfjetsakt5->end(); ++itpfj) {	     
	       double pT  = itpfj->pt();
	       double eta = itpfj->eta();
	       double phi = itpfj->phi();
	       double DR = deltaR(cjet->eta(),cjet->phi(),eta,phi);
	       // PF correction
	       double scalePF = correctorPF->correction(itpfj->p4());
	       if(DR < DRMAX) {
		 DRMAX  = DR;
		 DRPFJ  = DR;
		 EtPFJ  = pT;
		 EtaPFJ = eta;
		 PhiPFJ = phi;
		 scalePFJ = scalePF;
	       }
	     }

	     if(jjpt == 1) {
	       
	       DRPFJ1    = DRPFJ;
	       EtPFJCor1 = EtPFJ*scalePFJ;
	       EtPFJ1    = EtPFJ;
	       EtaPFJ1   = EtaPFJ;
	       PhiPFJ1   = PhiPFJ;
	       EtaRaw1 = cjet->eta(); 
	       PhiRaw1 = cjet->phi();
	       EtRaw1  = cjet->pt();
	       EtMCJ1  = cjet->pt() * scaleMC;
	       EtZSP1  = zspjet->pt(); 
	       EtaJPT1 = cjetJPT.eta();
	       PhiJPT1 = cjetJPT.phi();
	       EtJPT1  = cjetJPT.pt();
	       Ntrk1   = NtrkJPT;  
	       pTtrkMax1 = pTtrkMax;	   
	       NPxlMaxPtTrk1 = NPxlMaxPtTrk; 
	       NLayersMaxPtTrk1 = NLayersMaxPtTrk; 
   

	     }
	     if(jjpt == 2) {

	       DRPFJ2    = DRPFJ;
	       EtPFJCor2 = EtPFJ*scalePFJ;
	       EtPFJ2    = EtPFJ;
	       EtaPFJ2   = EtaPFJ;
	       PhiPFJ2   = PhiPFJ;
	       EtaRaw2 = cjet->eta(); 
	       PhiRaw2 = cjet->phi();
	       EtRaw2  = cjet->pt();
	       EtMCJ2  = cjet->pt() * scaleMC;
	       EtZSP2  = zspjet->pt(); 
	       EtaJPT2 = cjetJPT.eta();
	       PhiJPT2 = cjetJPT.phi();
	       EtJPT2  = cjetJPT.pt(); 
	       Ntrk2   = NtrkJPT;  
	       pTtrkMax2 = pTtrkMax;	   
	       NPxlMaxPtTrk2 = NPxlMaxPtTrk; 
	       NLayersMaxPtTrk2 = NLayersMaxPtTrk; 
	     }
	   }
	 }
       }
       if(jjpt >= 1) t1->Fill();
     }
   }
     */


     /*
       cout <<" best match to 1st gen get = " << DRMAXgjet1
       <<" raw jet pt = " << EtRaw1 <<" eta = " << EtaRaw1 <<" phi " << PhiRaw1 
       <<" mcj pt = " << EtMCJ1 << " zsp pt = " << EtZSP1 <<" jpt = " << EtJPT1 << endl; 
       if(gjets.size() == 2) {
       cout <<" best match to 2st gen get = " << DRMAXgjet2
       <<" raw jet pt = " << EtRaw2 <<" eta = " << EtaRaw2 <<" phi " << PhiRaw2 
       <<" mcj pt = " << EtMCJ2 << " zsp pt = " << EtZSP2 <<" jpt = " << EtJPT2 << endl; 
       }
     */
   // fill tree
}

//define this as a plug-in
DEFINE_FWK_MODULE(JetPlusTrackAnalysis);
