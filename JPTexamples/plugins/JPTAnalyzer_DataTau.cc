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

  // tcTau
  std::vector<double> *tcEta;
  std::vector<double> *tcPhi;
  std::vector<double> *tcEt;
  std::vector<double> *mass;

  std::vector<double> *vmEmf;
  std::vector<double> *vmfHPD;
  std::vector<double> *vmN90Hits;

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
  // max dz vtx - trk
  std::vector<double> *dzmaxvtx;  
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

  tcEta     = new std::vector<double>();
  tcPhi     = new std::vector<double>();
  tcEt      = new std::vector<double>();
  mass      = new std::vector<double>();

  vmEmf    = new std::vector<double>();
  vmfHPD   = new std::vector<double>();
  vmN90Hits= new std::vector<double>();

  ltrexists = new std::vector<int>();

  d0ltr     = new std::vector<double>();
  ptltr     = new std::vector<double>();
  drltrjet  = new std::vector<double>();
  ntrsign   = new std::vector<int>();
  ptminsign = new std::vector<double>();
  ntrisol   = new std::vector<int>();
  ptminisol = new std::vector<double>();
  dzmaxltr  = new std::vector<double>();
  dzmaxvtx  = new std::vector<double>();
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

  t1->Branch("tcEta","vector<double>",&tcEta);
  t1->Branch("tcPhi","vector<double>",&tcPhi);
  t1->Branch("tcEt" ,"vector<double>",&tcEt);
  t1->Branch("mass" ,"vector<double>",&mass);

  t1->Branch("mEmf","vector<double>",&vmEmf);
  t1->Branch("mfHPD","vector<double>",&vmfHPD);
  t1->Branch("mN90Hits","vector<double>",&vmN90Hits);

  t1->Branch("ltrexists" ,"vector<int>",&ltrexists);

  t1->Branch("d0ltr" ,"vector<double>",&d0ltr);
  t1->Branch("ptltr" ,"vector<double>",&ptltr);
  t1->Branch("drltrjet" ,"vector<double>",&drltrjet);
  t1->Branch("ntrsign" ,"vector<int>",&ntrsign);
  t1->Branch("ptminsign" ,"vector<double>",&ptminsign);
  t1->Branch("ntrisol" ,"vector<int>",&ntrisol);
  t1->Branch("ptminisol" ,"vector<double>",&ptminisol);
  t1->Branch("dzmaxltr" ,"vector<double>",&dzmaxltr);
  t1->Branch("dzmaxvtx" ,"vector<double>",&dzmaxvtx);
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

   tcEta->clear();
   tcPhi->clear();
   tcEt->clear();
 
   vmEmf->clear();
   vmfHPD->clear();
   vmN90Hits->clear();

   ltrexists->clear();
 
   d0ltr->clear();
   ptltr->clear();
   drltrjet->clear();
   ntrsign->clear();
   ptminsign->clear();
   ntrisol->clear();
   ptminisol->clear();
   dzmaxltr->clear();
   dzmaxvtx->clear();
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

     CaloTauCollection::const_iterator iTau;

     float DiscriminatorByLeadingTrackFinding = 0.;
     float DiscriminatorByLeadingTrackPtCut   = 0;
     float DiscriminatorByIsolation           = 0;
     float DiscriminatorAgainstElectron       = 0;

     int iTauInd = 0;
     CaloTau theCaloTau;

     for(iTau = caloTaus.begin(); iTau != caloTaus.end(); iTau++) {

       theCaloTau = *iTau;

       CaloTauRef  theCaloTauRef(theCaloTauHandle,iTauInd);
       iTauInd++;
 
       CaloJetRef RawCaloJet = (*iTau).rawJetRef();
	 
       if(     iTau->pt()   < 10.0) continue;
       if(fabs(iTau->eta()) >  2.5) continue;
       
       EtaRaw->push_back(RawCaloJet->eta());
       PhiRaw->push_back(RawCaloJet->phi());
       EtRaw ->push_back(RawCaloJet->pt());

       tcEta->push_back(iTau->eta());
       tcPhi->push_back(iTau->phi());
       tcEt->push_back(iTau->pt());

       double m = sqrt( (iTau->energy()*iTau->energy()) - (iTau->p()*iTau->p()) ); 
       mass->push_back(m);
       
       double mN90     = RawCaloJet->n90();
       double mEmf     = RawCaloJet->emEnergyFraction(); 	
       double mfHPD    = (*jetsID)[RawCaloJet].fHPD;
       double mfRBX    = (*jetsID)[RawCaloJet].fRBX; 
       double mN90Hits = (*jetsID)[RawCaloJet].n90Hits;
	 
       /*
       if(mEmf < 0.01) continue;
       if(mfHPD>0.98) continue;
       if(mN90Hits < 2) continue;
       */
  
       vmEmf->push_back(mEmf);
       vmfHPD->push_back(mfHPD);
       vmN90Hits->push_back(mN90Hits);

       DiscriminatorByLeadingTrackFinding = (*theCaloTauDiscriminatorByLeadingTrackFinding)[theCaloTauRef];
       DiscriminatorByLeadingTrackPtCut   = (*theCaloTauDiscriminatorByLeadingTrackPtCut)[theCaloTauRef];
       DiscriminatorByIsolation           = (*theCaloTauDiscriminatorByIsolation)[theCaloTauRef];
       DiscriminatorAgainstElectron       = (*theCaloTauDiscriminatorAgainstElectron)[theCaloTauRef];

       // e.m. isolation
       float pisol = 1000.;
       if(DiscriminatorByLeadingTrackPtCut == 1.) { pisol = (*iTau).isolationECALhitsEtSum();}
       
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
	   
       // leading track in cone 0.1 around jet axis
       const TrackRef leadingTrack =op.leadTk(metric,matchingConeSize,ptLeadingTrackMin);
       
       int ltr= 1;

       if(leadingTrack.isNull()) ltr = 0;
       
       ltrexists->push_back(ltr);
       
       if(ltr == 1) {
	 
	 double ip = fabs(leadingTrack->dxy((*recVtxs)[0].position()));
	 d0ltr->push_back(ip);
	 //	   d0ltr->push_back(leadingTrack->d0());
	 ptltr->push_back(leadingTrack->pt());
	 //	 double DRltrjet = deltaR(leadingTrack->eta(),leadingTrack->phi(),RawCaloJet->eta(),RawCaloJet->phi()); 
	 double DRltrjet = deltaR(leadingTrack->eta(),leadingTrack->phi(),iTau->eta(),iTau->phi()); 
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
	 double dzvtxMax = 0.;
	 for (reco::TrackRefVector::const_iterator it = isolatTracks.begin(); it != isolatTracks.end(); ++it) {
	   const double pt  = (*it)->pt();
	   //	     double dz = fabs(leadingTrack->dz()-(*it)->dz());
	   // fabs((*it).dz(pv.position()))<=tktorefpointmaxDZ)
	   double dz = fabs(leadingTrack->vz()-(*it)->vz());
	   double dzvtx = fabs( (*it)->dz((*recVtxs)[0].position()) );
	   if(dzvtx > dzvtxMax ) {
	     dzvtxMax = dzvtx;
	   }
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
	 dzmaxvtx->push_back(dzvtxMax);
       }
       jtau = jtau + 1;
     }
     if(jtau >= 1) t1->Fill();
   }
}

//define this as a plug-in
DEFINE_FWK_MODULE(JPTAnalyzer_DataTau);
