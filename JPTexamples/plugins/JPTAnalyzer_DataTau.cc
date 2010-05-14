// system include files
//
#include <memory>
#include <string>
#include <iostream>
#include <fstream>
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
//
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
#include "DataFormats/JetReco/interface/GenJet.h"
#include "DataFormats/JetReco/interface/GenJetCollection.h"
#include "JetMETCorrections/Objects/interface/JetCorrector.h"
// #include "JetMETCorrections/Algorithms/interface/JetPlusTrackCorrector.h"
#include "DataFormats/JetReco/interface/JetExtendedAssociation.h"
#include "DataFormats/JetReco/interface/JetID.h"
// taus
#include "DataFormats/TauReco/interface/CaloTau.h"
#include "RecoTauTag/TauTagTools/interface/CaloTauElementsOperators.h"
#include "RecoTauTag/RecoTau/interface/TauDiscriminationProducerBase.h"
//
// muons and tracks
#include "DataFormats/MuonReco/interface/MuonFwd.h"
#include "DataFormats/MuonReco/interface/Muon.h"
#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/TrackReco/interface/TrackFwd.h"
#include "DataFormats/TrackReco/interface/TrackBase.h"
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

#include <vector>

using namespace std;
using namespace reco;

//
// class decleration
//

class JPTAnalyzer_DataTau : public edm::EDAnalyzer {
   public:
      explicit JPTAnalyzer_DataTau(const edm::ParameterSet&);
      ~JPTAnalyzer_DataTau();


   private:
  //      virtual void beginJob(const edm::EventSetup&) ;
      virtual void beginJob() ;
      virtual void analyze(const edm::Event&, const edm::EventSetup&);
      virtual void endJob() ;

  // ----------member data ---------------------------
  // JPT corrector
  //  const JetPlusTrackCorrector* jptCorrector_;
  //
  // output root file
  string fOutputFileName ;
  // names of modules, producing object collections
  // raw calo jets
  string calojetsSrc;
  string jetsIDSrc;
  string jetExtenderSrc;

  // variables to be stored in ntpl
  int     jtau;
  int     run, event;
  double  PVx, PVy, PVz;

  // raw calo jet info
  std::vector<double> *EtaRaw;
  std::vector<double> *PhiRaw;
  std::vector<double> *EtRaw;

  // there is track within cone 0.5 around jet direction
  std::vector<int> *ltrexists;

  // ip of leading track
  std::vector<double> *d0ltr;
  // pT of leading track
  std::vector<double> *ptltr;
  // DR ltr and jet axis
  std::vector<double> *drltrjet;
  // number of tracks in signal cone
  std::vector<int> *ntrsign;
  // trk ptmin in signal cone
  std::vector<double> *ptminsign;
  // number of tracks in isolation cone
  std::vector<int> *ntrisol;
  // trk ptmin in isolation cone
  std::vector<double> *ptminisol;
  // max dz ltr - trl
  std::vector<double> *dzmaxltr;  
  // ecal isolation
  std::vector<float>  *emisolat;  
  // discriminators
  std::vector<float>  *dByLeadingTrackFinding;
  std::vector<float>  *dByLeadingTrackPtCut;
  std::vector<float>  *dByIsolation;
  std::vector<float>  *dAgainstElectron;

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
//JPTAnalyzer_DataTau::beginJob(const edm::EventSetup&)
JPTAnalyzer_DataTau::beginJob()
{
  using namespace edm;

  // creating a simple tree

  EtaRaw    = new std::vector<double>();
  PhiRaw    = new std::vector<double>();
  EtRaw     = new std::vector<double>();
  ltrexists = new std::vector<int>();

  d0ltr     = new std::vector<double>();
  ptltr     = new std::vector<double>();
  drltrjet  = new std::vector<double>();
  ntrsign   = new std::vector<int>();
  ptminsign = new std::vector<double>();
  ntrisol   = new std::vector<int>();
  ptminisol = new std::vector<double>();
  dzmaxltr  = new std::vector<double>();
  emisolat  = new std::vector<float>();  

  dByLeadingTrackFinding = new std::vector<float>();
  dByLeadingTrackPtCut   = new std::vector<float>();
  dByIsolation           = new std::vector<float>();
  dAgainstElectron       = new std::vector<float>();

  hOutputFile   = new TFile( fOutputFileName.c_str(), "RECREATE" ) ;

  t1 = new TTree("t1","analysis tree");
 
  t1->Branch("jtau",&jtau,"jtau/I");
  t1->Branch("run",&run,"run/I");
  t1->Branch("event",&event,"event/I");

  t1->Branch("PVx",&PVx,"PVx/D");
  t1->Branch("PVy",&PVy,"PVy/D");
  t1->Branch("PVz",&PVz,"PVz/D");

  t1->Branch("EtaRaw","vector<double>",&EtaRaw);
  t1->Branch("PhiRaw","vector<double>",&PhiRaw);
  t1->Branch("EtRaw" ,"vector<double>",&EtRaw);

  t1->Branch("ltrexists" ,"vector<int>",&ltrexists);

  t1->Branch("d0ltr" ,"vector<double>",&d0ltr);
  t1->Branch("ptltr" ,"vector<double>",&ptltr);
  t1->Branch("drltrjet" ,"vector<double>",&drltrjet);
  t1->Branch("ntrsign" ,"vector<int>",&ntrsign);
  t1->Branch("ptminsign" ,"vector<double>",&ptminsign);
  t1->Branch("ntrisol" ,"vector<int>",&ntrisol);
  t1->Branch("ptminisol" ,"vector<double>",&ptminisol);
  t1->Branch("dzmaxltr" ,"vector<double>",&dzmaxltr);
  t1->Branch("emisolat" ,"vector<float>",&emisolat);

  t1->Branch("dByLeadingTrackFinding" ,"vector<float>",&dByLeadingTrackFinding);
  t1->Branch("dByLeadingTrackPtCut" ,"vector<float>",&dByLeadingTrackPtCut);
  t1->Branch("dByIsolation" ,"vector<float>",&dByIsolation);
  t1->Branch("dAgainstElectron" ,"vector<float>",&dAgainstElectron);

  return ;
}

// ------------ method called once each job just after ending the event loop  ------------
void 
JPTAnalyzer_DataTau::endJob() {

  hOutputFile->Write() ;
  hOutputFile->Close() ;
  
  return ;
}

//
// constructors and destructor
//
JPTAnalyzer_DataTau::JPTAnalyzer_DataTau(const edm::ParameterSet& iConfig)

{
   //now do what ever initialization is needed
  using namespace edm;
  // 
  // get name of output file with histogramms
  fOutputFileName = iConfig.getUntrackedParameter<string>("HistOutFile");
  //
  // get names of input object collections
  // raw calo jets
  calojetsSrc      = iConfig.getParameter< std::string > ("calojets");
  jetsIDSrc        = iConfig.getParameter< std::string > ("jetsID");
}


JPTAnalyzer_DataTau::~JPTAnalyzer_DataTau()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called to for each event  ------------
void
JPTAnalyzer_DataTau::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
   using namespace edm;

   // initialize tree variables

   run = iEvent.id().run();
   event = iEvent.id().event();

   jtau = 0;

   PVx = -1000.; 
   PVy = -1000.; 
   PVz = -1000.;
 
   EtaRaw->clear();
   PhiRaw->clear();
   EtRaw->clear();
 
   ltrexists->clear();
 
   d0ltr->clear();
   ptltr->clear();
   drltrjet->clear();
   ntrsign->clear();
   ptminsign->clear();
   ntrisol->clear();
   ptminisol->clear();
   dzmaxltr->clear();
   emisolat->clear();

   dByLeadingTrackFinding->clear();
   dByLeadingTrackPtCut->clear();
   dByIsolation->clear();
   dAgainstElectron->clear();

  // calo jets
   edm::Handle<CaloJetCollection> calojets;
   iEvent.getByLabel(calojetsSrc, calojets);

   // calo taus
   Handle<CaloTauCollection> theCaloTauHandle;
   //   iEvent.getByLabel("caloRecoTauProducer",theCaloTauHandle);
   iEvent.getByLabel("tcRecoTauProducer",theCaloTauHandle);
   const CaloTauCollection & caloTaus = *(theCaloTauHandle.product());
   int nCaloTaus = caloTaus.size();

   // calo tau discriminators
   //   
   Handle<CaloTauDiscriminator> theCaloTauDiscriminatorByLeadingTrackFinding;
   iEvent.getByLabel("caloRecoTauDiscriminationByLeadingTrackFinding",theCaloTauDiscriminatorByLeadingTrackFinding);
   //
   Handle<CaloTauDiscriminator> theCaloTauDiscriminatorByLeadingTrackPtCut;
   iEvent.getByLabel("caloRecoTauDiscriminationByLeadingTrackPtCut",theCaloTauDiscriminatorByLeadingTrackPtCut);
   //
   Handle<CaloTauDiscriminator> theCaloTauDiscriminatorByIsolation;
   iEvent.getByLabel("caloRecoTauDiscriminationByIsolation",theCaloTauDiscriminatorByIsolation);
   //
   Handle<CaloTauDiscriminator> theCaloTauDiscriminatorAgainstElectron;
   iEvent.getByLabel("caloRecoTauDiscriminationAgainstElectron",theCaloTauDiscriminatorAgainstElectron);

   Handle<ValueMap<reco::JetID> > jetsID;
   iEvent.getByLabel(jetsIDSrc,jetsID);

   // get vertex
   Handle<reco::VertexCollection> recVtxs;
   iEvent.getByLabel("offlinePrimaryVertices",recVtxs);

   /*
   Handle<VertexCollection> thePVs;
   iEvent.getByLabel(PVProducer_,thePVs);
   const VertexCollection vertCollection=*(thePVs.product());
   Vertex thePV;
   thePV=*(vertCollection.begin());
   */

   int nvtx = 0;
   int ntrkV = 0;

   for(unsigned int ind = 0; ind < recVtxs->size(); ind++) 
     {
       if (!((*recVtxs)[ind].isFake())) 
	 {
	   nvtx = nvtx + 1;
	   if(nvtx == 1) {
	     PVx  = (*recVtxs)[ind].x();
	     PVy  = (*recVtxs)[ind].y();
	     PVz  = (*recVtxs)[ind].z();
	     //	     ntrkV = (*recVtxs)[ind].tracksSize();
	     reco::Vertex::trackRef_iterator ittrk;
	     for(ittrk =(*recVtxs)[ind].tracks_begin();ittrk != (*recVtxs)[ind].tracks_end(); ++ittrk)
	       if( (*recVtxs)[ind].trackWeight(*ittrk)>0.5 ) ntrkV++;
	   }
	 }
     }
   
   if( (nvtx == 1) && (ntrkV > 3) && (ntrkV < 100) ) {

     if( calojets->size() > 0 ) {

       int jc = 0;
       for( CaloJetCollection::const_iterator cjet = calojets->begin(); 
	    cjet != calojets->end(); ++cjet ){ 
	 
	 // raw jet selection 
	 RefToBase<Jet> jetRef(Ref<CaloJetCollection>(calojets,jc));
	 double mN90  = (*calojets)[jc].n90();
	 double mEmf  = (*calojets)[jc].emEnergyFraction(); 	
	 double mN90Hits = (*jetsID)[jetRef].n90Hits;
	 double mfHPD    = (*jetsID)[jetRef].fHPD;
	 double mfRBX    = (*jetsID)[jetRef].fRBX; 
	 
	 jc++;

	 // jet ID selections

	 if(mEmf < 0.01) continue;
	 if(mfHPD>0.98) continue;
	 if(mN90Hits < 2) continue;
	 if(fabs(cjet->eta()) > 2.5) continue;

	 // consider only jets with raw ET > 4 GeV.

	 if( cjet->pt() < 4.0 ) continue;

	 EtaRaw->push_back(cjet->eta());
	 PhiRaw->push_back(cjet->phi());
	 EtRaw ->push_back(cjet->pt());
	 
	 // match calo tau with calo jet
	 double DRMAX = 1000.;
	 CaloTau theCaloTau;

	 CaloTauCollection::const_iterator iTau;
	 int iTauInd = 0;

	 float DiscriminatorByLeadingTrackFinding = 0.;
	 float DiscriminatorByLeadingTrackPtCut   = 0;
	 float DiscriminatorByIsolation           = 0;
	 float DiscriminatorAgainstElectron       = 0;

	 for(iTau = caloTaus.begin(); iTau != caloTaus.end(); iTau++) {
	   double DR = deltaR(cjet->eta(),cjet->phi(),iTau->eta(),iTau->phi());
	   if(DR < DRMAX) {
	     theCaloTau = *iTau;
	     DRMAX = DR;
	     CaloTauRef  theCaloTauRef(theCaloTauHandle,iTauInd);
	     iTauInd++;
	     DiscriminatorByLeadingTrackFinding = (*theCaloTauDiscriminatorByLeadingTrackFinding)[theCaloTauRef];
	     DiscriminatorByLeadingTrackPtCut   = (*theCaloTauDiscriminatorByLeadingTrackPtCut)[theCaloTauRef];
	     DiscriminatorByIsolation           = (*theCaloTauDiscriminatorByIsolation)[theCaloTauRef];
	     DiscriminatorAgainstElectron       = (*theCaloTauDiscriminatorAgainstElectron)[theCaloTauRef];
	   }
	 }

	 // e.m. isolation
	 float pisol = 1000.;
	 if(DiscriminatorByLeadingTrackPtCut == 1.) { pisol = theCaloTau.isolationECALhitsEtSum();}

	 emisolat->push_back(pisol);
	 dByLeadingTrackFinding->push_back(DiscriminatorByLeadingTrackFinding);
	 dByLeadingTrackPtCut->push_back(DiscriminatorByLeadingTrackPtCut);
	 dByIsolation->push_back(DiscriminatorByIsolation);
	 dAgainstElectron->push_back(DiscriminatorAgainstElectron);

	 // settings for tau isolation
	 double matchingConeSize  = 0.10;
	 double signalConeSize    = 0.07;
	 double isolationConeSize = 0.5;
	 //	 double isolationConeSize = 0.4;
	 double ptLeadingTrackMin = 0.;
	 double ptOtherTracksMin  = 0.;
	 //	 double ptLeadingTrackMin = 6.;
	 //	 double ptOtherTracksMin  = 1.;
	 string metric = "DR"; // can be DR,angle,area
	 unsigned int isolationAnnulus_Tracksmaxn = 0;

	 CaloTauElementsOperators op(theCaloTau);
	 double d_trackIsolation = 
	   op.discriminatorByIsolTracksN(metric,
					 matchingConeSize,
					 ptLeadingTrackMin,
					 ptOtherTracksMin,
					 metric,
					 signalConeSize,
					 metric,
					 isolationConeSize,
					 isolationAnnulus_Tracksmaxn);
	   
	 // leading track in cone 0.5 around jet axis
	 const TrackRef leadingTrack =op.leadTk(metric,isolationConeSize,ptLeadingTrackMin);
	   
	 int ltr= 1;
	 if(leadingTrack.isNull()) ltr = 0;

	 ltrexists->push_back(ltr);
      
	 if(ltr == 1) {

	   double ip = fabs(leadingTrack->dxy((*recVtxs)[0].position()));
	   d0ltr->push_back(ip);
	   //	   d0ltr->push_back(leadingTrack->d0());
	   ptltr->push_back(leadingTrack->pt());
	   double DRltrjet = deltaR(leadingTrack->eta(),leadingTrack->phi(),cjet->eta(),cjet->phi()); 
	   drltrjet->push_back(DRltrjet);

	   // tracks in signal cone
	   const TrackRefVector signalTracks = op.tracksInCone(leadingTrack->momentum(),metric,signalConeSize,ptOtherTracksMin);
	   ntrsign->push_back(signalTracks.size());
	   double pTtrkMin = 1000.;
	   double pTmin = 1000.;
	   for (reco::TrackRefVector::const_iterator it = signalTracks.begin(); it != signalTracks.end(); ++it) {
	     const double pt  = (*it)->pt();
	     if(pt < pTmin) {
	       pTmin = pt;
	       pTtrkMin = pt;;
	     }
	   }
	   ptminsign->push_back(pTtrkMin);

	   // tracks in isolation cone
	   // const double tracktorefpoint_maxDZ,const double refpoint_Z)const;
	   const TrackRefVector isolatTracks = op.tracksInCone(leadingTrack->momentum(),metric,isolationConeSize,ptOtherTracksMin);
	   ntrisol->push_back(isolatTracks.size());
	   pTtrkMin = 1000.;
	   pTmin = 1000.;
	   double dzMax = 0.;
	   for (reco::TrackRefVector::const_iterator it = isolatTracks.begin(); it != isolatTracks.end(); ++it) {
	     const double pt  = (*it)->pt();
	     //	     double dz = fabs(leadingTrack->dz()-(*it)->dz());
	     double dz = fabs(leadingTrack->vz()-(*it)->vz());
	     if(dz > dzMax) {
	       dzMax = dz;
	     }
	     if(pt < pTmin) {
	       pTmin = pt;
	       pTtrkMin = pt;
	     }
	   }
	   ptminisol->push_back(pTtrkMin);
	   dzmaxltr->push_back(dzMax);
	 }
	 
	 jtau = jtau + 1;
	   
       }

       if(jtau >= 1) t1->Fill();
     }
   }
}

//define this as a plug-in
DEFINE_FWK_MODULE(JPTAnalyzer_DataTau);
