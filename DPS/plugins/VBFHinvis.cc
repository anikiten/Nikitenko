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
#include "DataFormats/METReco/interface/PFMET.h"
#include "DataFormats/METReco/interface/PFMETFwd.h"
#include "CMGTools/External/interface/PileupJetIdentifier.h"
#include "CMGTools/External/interface/PileupJetIdAlgo.h"
#include "DataFormats/JetReco/interface/Jet.h"
#include "DataFormats/JetReco/interface/JetTracksAssociation.h"

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

class VBFHinvis : public edm::EDAnalyzer {
public:
  explicit VBFHinvis(const edm::ParameterSet&);
  ~VBFHinvis();

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
  //
  // run/event
  int     run, event; 
  //
  int     f1, f2, f3, f4, f5;  
  // trigger flags
  int     L1ETM40, VBF_AllJets, DoubleMu7, Mu13_Mu8, Mu17_Mu8, Mu17_TkMu8;
  // vertex
  double  DZmin, PVx, PVy, PVz;
  int     nvertex, nsimvertex;
  // MET
  double  pfmet, pfmetType1,pfmetType2;
  // di muon pass
  double  mass_mumu;
  // muon eta/phi/pT/isolation/distance from PV in Z coordinate
  std::vector<double> *EtaMu;
  std::vector<double> *PhiMu;
  std::vector<double> *PtMu;
  std::vector<double> *dzmuon;
  std::vector<double> *mutrkisol;
  std::vector<double> *mupfisol;
  std::vector<int>    *mucharge;
  // eta/phi/pt of raw calo jet from JPT
  std::vector<double> *EtaRaw;
  std::vector<double> *PhiRaw;
  std::vector<double> *EtRaw;
  // eta/phi/pt of JPT corrected jets
  std::vector<double> *EtaJPT;
  std::vector<double> *PhiJPT;
  std::vector<double> *EtJPT;
  // JPT N in-vertex-cone tracks
  std::vector<int>    *Ntrk;
  // JPT JES uncertainty
  std::vector<double> *jesunc;
  // JPT beta
  std::vector<double> *beta;
  // tracks counting: number of tracks between tagging jets
  int n_trk1GeV, n_trk2GeV, n_trk3GeV;
  // pf info
  std::vector<double> *EtaPF;
  std::vector<double> *PhiPF;
  std::vector<double> *EtPF;
  std::vector<float>  *MVAPF;
  std::vector<int>    *IDPF;
  std::vector<int>    *JTypePF;
  //
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
//VBFHinvis::beginJob(const edm::EventSetup&)
VBFHinvis::beginJob()
{
  using namespace edm;

  EtaMu        = new std::vector<double>();
  PhiMu        = new std::vector<double>();
  PtMu         = new std::vector<double>();
  dzmuon       = new std::vector<double>();
  mutrkisol    = new std::vector<double>();
  mupfisol     = new std::vector<double>();
  mucharge     = new std::vector<int>();

  EtaRaw       = new std::vector<double>();  
  PhiRaw       = new std::vector<double>();
  EtRaw        = new std::vector<double>();
  EtaJPT       = new std::vector<double>();
  PhiJPT       = new std::vector<double>();
  EtJPT        = new std::vector<double>();
  Ntrk         = new std::vector<int>();
  jesunc       = new std::vector<double>();
  beta         = new std::vector<double>();;

  EtaPF        = new std::vector<double>();
  PhiPF        = new std::vector<double>();
  EtPF         = new std::vector<double>();
  MVAPF        = new std::vector<float>();
  IDPF         = new std::vector<int>();
  JTypePF      = new std::vector<int>();

  // creating a simple tree

  hOutputFile   = new TFile( fOutputFileName.c_str(), "RECREATE" ) ;

  t1 = new TTree("t1","analysis tree");

  t1->Branch("run",&run,"run/I");
  t1->Branch("event",&event,"event/I");
  t1->Branch("nvertex",&nvertex,"nvertex/I");
  t1->Branch("nsimvertex",&nsimvertex,"nsimvertex/I");

  t1->Branch("f1",&f1,"f1/I");
  t1->Branch("f2",&f2,"f2/I");
  t1->Branch("f3",&f3,"f3/I");
  t1->Branch("f4",&f4,"f4/I");
  t1->Branch("f5",&f5,"f5/I");

  t1->Branch("L1ETM40",&L1ETM40,"L1ETM40/I");
  t1->Branch("VBF_AllJets",&VBF_AllJets,"VBF_AllJets/I");
  t1->Branch("DoubleMu7",&DoubleMu7,"DoubleMu7/I");
  t1->Branch("Mu13_Mu8",&Mu13_Mu8,"Mu13_Mu8/I");
  t1->Branch("Mu17_Mu8",&Mu17_Mu8,"Mu17_Mu8/I");
  t1->Branch("Mu17_TkMu8",&Mu17_TkMu8,"Mu17_TkMu8/I");

  t1->Branch("DZmin",&DZmin,"DZmin/D");
  t1->Branch("PVx",&PVx,"PVx/D");
  t1->Branch("PVy",&PVy,"PVy/D");
  t1->Branch("PVz",&PVz,"PVz/D");
  t1->Branch("pfmet",&pfmet,"pfmet/D");
  t1->Branch("pfmetType1",&pfmetType1,"pfmetType1/D");

  t1->Branch("mass_mumu",&mass_mumu,"mass_mumu/D");
  t1->Branch("EtaMu","vector<double>",&EtaMu);
  t1->Branch("PhiMu","vector<double>",&PhiMu);
  t1->Branch("PtMu" ,"vector<double>",&PtMu);
  t1->Branch("dzmuon" ,"vector<double>",&dzmuon);
  t1->Branch("mutrkisol" ,"vector<double>",&mutrkisol);
  t1->Branch("mupfisol" ,"vector<double>",&mupfisol);
  t1->Branch("mucharge" ,"vector<int>",&mucharge);

  t1->Branch("EtaRaw","vector<double>",&EtaRaw);
  t1->Branch("PhiRaw","vector<double>",&PhiRaw);
  t1->Branch("EtRaw" ,"vector<double>",&EtRaw);
  t1->Branch("EtaJPT","vector<double>",&EtaJPT);
  t1->Branch("PhiJPT","vector<double>",&PhiJPT);
  t1->Branch("EtJPT" ,"vector<double>",&EtJPT);
  t1->Branch("Ntrk","vector<int>",&Ntrk);
  t1->Branch("jesunc" ,"vector<double>",&jesunc);
  t1->Branch("beta" ,"vector<double>",&beta);

  t1->Branch("n_trk1GeV",&n_trk1GeV,"n_trk1GeV/I");
  t1->Branch("n_trk2GeV",&n_trk2GeV,"n_trk2GeV/I");
  t1->Branch("n_trk3GeV",&n_trk3GeV,"n_trk3GeV/I");

  t1->Branch("EtaPF","vector<double>",&EtaPF);
  t1->Branch("PhiPF","vector<double>",&PhiPF);
  t1->Branch("EtPF" ,"vector<double>",&EtPF);
  t1->Branch("MVAPF" ,"vector<float>",&MVAPF);
  t1->Branch("IDPF","vector<int>",&IDPF);
  t1->Branch("JTypePF","vector<int>",&JTypePF);

  return ;
}

// ------------ method called once each job just after ending the event loop  ------------
void 
VBFHinvis::endJob() {

  hOutputFile->Write() ;
  hOutputFile->Close() ;
  
  return ;
}

//
// constructors and destructor
//
VBFHinvis::VBFHinvis(const edm::ParameterSet& iConfig)

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


VBFHinvis::~VBFHinvis()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called to for each event  ------------
void
VBFHinvis::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  using namespace edm;

  run = iEvent.id().run();
  event = iEvent.id().event();

  //  cout <<" ====== run/event " << run <<" "<< event << endl;

  nvertex = 0;
  nsimvertex = 0;

  f1 = 0;
  f2 = 0;
  f3 = 0;
  f4 = 0;
  f5 = 0;

  L1ETM40 = 0;
  VBF_AllJets = 0;
  DoubleMu7   = 0;
  Mu13_Mu8    = 0;
  Mu17_Mu8    = 0;
  Mu17_TkMu8  = 0;;

  DZmin =   0.;
  PVx = -1000.; 
  PVy = -1000.; 
  PVz = -1000.;

  pfmet = 0.;
  pfmetType1 = 0.;

  mass_mumu = 0.;
  EtaMu->clear();
  PhiMu->clear();
  PtMu->clear();
  dzmuon->clear();
  mutrkisol->clear();
  mupfisol->clear();
  mucharge->clear();

  EtaRaw->clear();
  PhiRaw->clear();
  EtRaw->clear();
  EtaJPT->clear();
  PhiJPT->clear();
  EtJPT->clear();
  Ntrk->clear();
  jesunc->clear(); 
  beta->clear(); 

  n_trk1GeV = 0.;
  n_trk2GeV = 0.;
  n_trk3GeV = 0.;

  EtaPF->clear();
  PhiPF->clear();
  EtPF->clear(); 
  MVAPF->clear();
  IDPF->clear(); 
  JTypePF->clear();


  // muons
   edm::Handle<RecoMuons> reco_muons;
   iEvent.getByLabel(muonsSrc, reco_muons );
   
   // get jet ID map
   edm::Handle<ValueMap<reco::JetID> > jetsID;
   iEvent.getByLabel(jetsIDSrc,jetsID);
   // 'ak5JetID'
   
   // pf jets
   edm::Handle<PFJetCollection> pfjets;
   iEvent.getByLabel("ak5PFJets", pfjets);

   // pf jets corrected
   edm::Handle<edm::View <reco::Jet> > pfjetsl1l2l3;
   //   edm::Handle<PFJetCollection> pfjetsl1l2l3;
   iEvent.getByLabel("ak5PFJetsL1L2L3Residual", pfjetsl1l2l3);
   reco::JetRefBaseProd pfjetref(*pfjetsl1l2l3);

   // MVA PU PF jet discriminator
   edm::Handle<edm::ValueMap<float> > puJetIdMVA;
   iEvent.getByLabel("recoPuJetMva","fullDiscriminant",puJetIdMVA);
   //
   edm::Handle<edm::ValueMap<int> > puJetIdFlag;
   iEvent.getByLabel("recoPuJetMva","fullId",puJetIdFlag);
   
   // JPT jets raw
   edm::Handle<reco::JPTJetCollection> jptjets;
   iEvent.getByLabel(JPTjetsSrc, jptjets);
   //   
   // JPT jets L1L2L3
   edm::Handle<reco::JPTJetCollection> jptjetsl1l2l3;
   iEvent.getByLabel(JPTjetsL1L2L3Src, jptjetsl1l2l3);

  // JES uncertainty
   std::string JEC_PATH("CondFormats/JetMETObjects/data/");
   edm::FileInPath fip(JEC_PATH+"GR_R_53_V13_Uncertainty_AK5JPT.txt");
   JetCorrectionUncertainty *jecUnc = new JetCorrectionUncertainty(fip.fullPath());
   //   delete jecUnc;
  
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

   edm::Handle<reco::PFMETCollection> mets;
   iEvent.getByLabel("pfMet", mets);
   pfmet = mets->front().pt();

   edm::Handle<reco::PFMETCollection> metsType1;
   iEvent.getByLabel("pfType1CorrectedMet", metsType1);
   pfmetType1 = metsType1->front().pt();

   // MET filters
   edm::Handle<bool> filter1;
   iEvent.getByLabel("MyEcalDeadCellTriggerPrimitiveFilter", filter1);
   f1 = (int)(*(filter1.product()));
   //
   edm::Handle<bool> filter2;
   iEvent.getByLabel("MyecalLaserCorrFilter", filter2);
   f2 = (int)(*(filter2.product()));
   //
   edm::Handle<bool> filter3;
   iEvent.getByLabel("MyeeBadScFilter", filter3);
   f3 = (int)(*(filter3.product()));
   //
   edm::Handle<bool> filter4;
   iEvent.getByLabel("MyhcalLaserEventFilter", filter4);
   f4 = (int)(*(filter4.product()));
   //
   edm::Handle<bool> filter5;
   iEvent.getByLabel("MytrackingFailureFilter", filter5);
   f5 = (int)(*(filter5.product()));

  //  NPxlMaxPtTrk->clear();
  //  NSiIMaxPtTrk->clear();
  //  NSiOMaxPtTrk->clear();
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
   edm::Handle<TriggerResults> triggerResults;
   iEvent.getByLabel(srcTriggerResults_,triggerResults);

   const edm::TriggerNames & triggerNames = iEvent.triggerNames(*triggerResults);

   unsigned index = triggerNames.triggerIndex("HLT_PhysicsDeclared");
   bool physdecl= (index<triggerNames.size()&&triggerResults->accept(index)) ? 1 : 0;

   for(unsigned ihlt = 0; ihlt < triggerNames.size(); ihlt++) {

     if( (int)(triggerNames.triggerName(ihlt)).find("DoubleMu7")  > 0 ) 
       {DoubleMu7  = triggerResults->accept(ihlt);}
     if( (int)(triggerNames.triggerName(ihlt)).find("Mu13_Mu8")   > 0 ) 
       {Mu13_Mu8   = triggerResults->accept(ihlt);}
     if( (int)(triggerNames.triggerName(ihlt)).find("Mu17_Mu8")   > 0 ) 
       {Mu17_Mu8   = triggerResults->accept(ihlt);}
     if( (int)(triggerNames.triggerName(ihlt)).find("Mu17_TkMu8") > 0 ) 
       {Mu17_TkMu8 = triggerResults->accept(ihlt);}

     if((int)(triggerNames.triggerName(ihlt)).find("L1ETM40")>0) 
       {L1ETM40  = triggerResults->accept(ihlt);}
     if((int)(triggerNames.triggerName(ihlt)).find("DiPFJet40_PFMETnoMu65_MJJ800VBF_AllJets")>0) 
       {VBF_AllJets  = triggerResults->accept(ihlt);}

     /*
     std::cout <<" HLT bit " << ihlt <<" name = " << triggerNames.triggerName(ihlt) 
	       <<" accepted = " << triggerResults->accept(ihlt) <<" index = " << index << std::endl; 
     */
   }

  //  std::map<double,int> pTjptIndex;

   std::map<double,const JPTJet*> pTjptIndex;

   std::map<double,const PFJet*> pTpfIndex;
   std::map<double,float> PuMVApfIndex;
   std::map<double,int> PuIDpfIndex;

   std::map<double,const Muon*> pTMuonIndex;
   math::XYZTLorentzVector  muon1(0.,0.,0.,0.);
   math::XYZTLorentzVector  muon2(0.,0.,0.,0.);
   
  
  // PU info
   if(DataOrMCSrc == 1) {

     edm::InputTag PileupSrc_("addPileupInfo");
     Handle<std::vector< PileupSummaryInfo > >  PupInfo;
     iEvent.getByLabel(PileupSrc_, PupInfo);
     std::vector<PileupSummaryInfo>::const_iterator PVI;
     for(PVI = PupInfo->begin(); PVI != PupInfo->end(); ++PVI) {
       //       std::cout << " Pileup Information: bunchXing, nvtx: " << PVI->getBunchCrossing() << " " << PVI->getTrueNumInteractions() << std::endl;
       //       std::cout << " Pileup Information: bunchXing, nvtx: " << PVI->getBunchCrossing() << " " << PVI->getPU_NumInteractions() << std::endl;
       //       if(PVI->getBunchCrossing() == 0) nsimvertex = PVI->getPU_NumInteractions();
       if(PVI->getBunchCrossing() == 0) nsimvertex = PVI->getTrueNumInteractions();
     }
   }
   
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
	     //	    reco::Vertex::trackRef_iterator ittk;
	     //	    for(ittrk =(*recVtxs)[ind].tracks_begin();
	     //                 ittrk != (*recVtxs)[ind].tracks_end(); ++ittrk) 
	     //	      if( (*recVtxs)[ind].trackWeight(*ittrk)>0.5 ) ntrkV++;
	     // access tracks from PV
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

     // tight and loose muons
     RecoMuons::const_iterator imuon = reco_muons->begin(); 
     RecoMuons::const_iterator jmuon = reco_muons->end();
     for ( ; imuon != jmuon; ++imuon ) {
       // tight muons
       if(muon::isTightMuon(*imuon,(*recVtxs)[0])) {
	 pTMuonIndex[imuon->innerTrack()->pt()] = &(*imuon);
       }
       // loose muons
       if( (*imuon).isPFMuon() && ((*imuon).isGlobalMuon() || (*imuon).isTrackerMuon()) ) {
	 double pT  = (*imuon).pt(); 
	 double eta = (*imuon).eta(); 
	 double phi = (*imuon).phi(); 
	 double muon_sumTrkPt = (*imuon).isolationR03().sumPt;
	 const MuonPFIsolation pfisol = (*imuon).pfIsolationR04();
	 double muon_sumPFPt = pfisol.sumChargedHadronPt +
	   max(0.,pfisol.sumNeutralHadronEt+pfisol.sumPhotonEt-0.5*pfisol.sumPUPt);
       }
     }

     // fill muon variables
     map<double,const Muon*>::reverse_iterator rmfirst(pTMuonIndex.end());
     map<double,const Muon*>::reverse_iterator rmlast(pTMuonIndex.begin());
     int imu = 0;
     while (rmfirst != rmlast) {
       
       const Muon* muon = (*rmfirst).second;
       
       imu++;
       math::XYZTLorentzVector muonc(muon->innerTrack()->px(),
				     muon->innerTrack()->py(), 
				     muon->innerTrack()->pz(), 
				     muon->innerTrack()->p()); 
       EtaMu->push_back(muon->innerTrack()->eta());
       PhiMu->push_back(muon->innerTrack()->phi());
       PtMu->push_back(muon->innerTrack()->pt());
       mucharge->push_back(muon->charge());
       double dzvtx = fabs(muon->innerTrack()->dz((*recVtxs)[0].position()) );
       dzmuon->push_back(dzvtx);
       // tracker muon isolation variables
       double muon_sumTrkPt = muon->isolationR03().sumPt;
       //       double muon_emEt  = muon->isolationR03().emEt;
       //       double muon_hadEt = muon->isolationR03().hadEt;
       mutrkisol->push_back(muon_sumTrkPt);
       // pf isolation variable
       const MuonPFIsolation pfisol = muon->pfIsolationR04();
       double muon_sumPFPt = pfisol.sumChargedHadronPt +
       	 max(0.,pfisol.sumNeutralHadronEt+pfisol.sumPhotonEt-0.5*pfisol.sumPUPt);
       mupfisol->push_back(muon_sumPFPt);

       if (imu == 1) muon1 = muonc; 
       if (imu == 2) muon2 = muonc; 
       rmfirst++;
     }
   
     if(imu >= 2) {
       math::XYZTLorentzVector twomuons = muon1 + muon2;
       mass_mumu = twomuons.M();
     }
     
     // jpt jets
     if(jptjetsl1l2l3->size() != 0) {

       double DR1 = 10.;
       double DR2 = 10.;
       for(JPTJetCollection::const_iterator jptjet = jptjetsl1l2l3->begin(); 
	                                    jptjet != jptjetsl1l2l3->end(); ++jptjet ) { 
	 if(jptjet->pt() > 20.) {
	   if(imu >= 1) { DR1 = deltaR(muon1.Eta(), muon1.Phi(), jptjet->eta(), jptjet->phi());}
	   if(imu >= 2) { DR2 = deltaR(muon2.Eta(), muon2.Phi(), jptjet->eta(), jptjet->phi());}
	   if( (DR1 > 0.6) && (DR2 > 0.6) ) {
	     pTjptIndex[jptjet->pt()] = &(*jptjet);
	   }
	 }
       }
     }
    
     for (unsigned ipfjet = 0; ipfjet < pfjetsl1l2l3->size(); ++ipfjet) {

       const reco::PFJet* pfjet = dynamic_cast<const reco::PFJet*>(&(*pfjetsl1l2l3)[ipfjet]);

       double DR1 = 10.;
       double DR2 = 10.;
       if(pfjet->pt() > 20.) {
	 if(imu >= 1) { DR1 = deltaR(muon1.Eta(), muon1.Phi(), pfjet->eta(), pfjet->phi());}
	 if(imu >= 2) { DR2 = deltaR(muon2.Eta(), muon2.Phi(), pfjet->eta(), pfjet->phi());}
	 if( (DR1 > 0.6) && (DR2 > 0.6) ) {
	   
	   float mva  = (*puJetIdMVA)[pfjetref->refAt(ipfjet)];
	   int idflag = (*puJetIdFlag)[pfjetref->refAt(ipfjet)];
	   
	   pTpfIndex[pfjet->pt()]    = pfjet;
	   PuMVApfIndex[pfjet->pt()] = mva; 
	   PuIDpfIndex[pfjet->pt()]  = idflag;
	 }
       }
     }
   }

   // fill pf jet variables
    map<double,const PFJet*>::reverse_iterator rfirstPF(pTpfIndex.end());
    map<double,const PFJet*>::reverse_iterator rlastPF(pTpfIndex.begin());
    while (rfirstPF != rlastPF) {
      const PFJet* pfjet = (*rfirstPF).second;
      rfirstPF++;

      // pfjet id
      if(  (*pfjet).neutralHadronEnergyFraction() > 0.99 )  continue;
      if(  (*pfjet).neutralEmEnergyFraction() > 0.99 )  continue;
      if(( (*pfjet).neutralMultiplicity() + (*pfjet).chargedMultiplicity() ) < 1 )  continue;
      if( fabs((*pfjet).eta()) < 2.4) {
	if( (*pfjet).chargedHadronEnergyFraction() < 0. )  continue;
	if( (*pfjet).chargedMultiplicity() < 0. )  continue;
	if( (*pfjet).chargedEmEnergyFraction() > 0.99 )  continue;
      }
      float mva  = (*PuMVApfIndex.find((*pfjet).pt())).second;
      int idflag = (*PuIDpfIndex.find((*pfjet).pt())).second;

      int pfjidtype = 0;
      if( PileupJetIdentifier::passJetId( idflag, PileupJetIdentifier::kLoose )) 
	{pfjidtype = 1;}
      if( PileupJetIdentifier::passJetId( idflag, PileupJetIdentifier::kMedium )) 
	{pfjidtype = 2;}
      if( PileupJetIdentifier::passJetId( idflag, PileupJetIdentifier::kTight )) 
	{pfjidtype = 3;}

      EtaPF->push_back(pfjet->eta());
      PhiPF->push_back(pfjet->phi());
      EtPF->push_back(pfjet->pt());
      MVAPF->push_back(mva);
      IDPF->push_back(idflag);
      JTypePF->push_back(pfjidtype);
    }

   // fill jpt jet variables
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
     // calo jet ID
     if(mEmf  < 0.01) continue;
     if(mfHPD > 0.98) continue;
     if(mfRBX > 0.98) continue;
     if(mN90  < 2) continue;
     
     // access tracks used in JPT
     TrackRefVector pionsInVertexInCalo  = jptjet->getPionsInVertexInCalo();
     TrackRefVector pionsInVertexOutCalo = jptjet->getPionsInVertexOutCalo();
     int npions = pionsInVertexInCalo.size()+pionsInVertexOutCalo.size();

     /*
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
	 NLayersSiI = (*iInConeVtxTrk)->hitPattern().stripTIBLayersWithMeasurement()+
	              (*iInConeVtxTrk)->hitPattern().stripTIDLayersWithMeasurement();
	 NLayersSiO = (*iInConeVtxTrk)->hitPattern().stripTOBLayersWithMeasurement()+
	              (*iInConeVtxTrk)->hitPattern().stripTECLayersWithMeasurement();
       }
     }
    
     // loop over in-vertex-out of calo tracks
     for (reco::TrackRefVector::const_iterator iInConeVtxTrk = pionsInVertexOutCalo.begin(); 
	  iInConeVtxTrk != pionsInVertexOutCalo.end(); ++iInConeVtxTrk) {
       const double pt  = (*iInConeVtxTrk)->pt();
       if(pt > pTMax) {
	 pTMax = pt;
	 NLayersPxl = (*iInConeVtxTrk)->hitPattern().pixelLayersWithMeasurement();
	 NLayersSiI = (*iInConeVtxTrk)->hitPattern().stripTIBLayersWithMeasurement()+
                      (*iInConeVtxTrk)->hitPattern().stripTIDLayersWithMeasurement();
	 NLayersSiO = (*iInConeVtxTrk)->hitPattern().stripTOBLayersWithMeasurement()+
                      (*iInConeVtxTrk)->hitPattern().stripTECLayersWithMeasurement();
       }
     }
     */

     //     jecUnc->setJetEta(jptjet->eta());
     //     jecUnc->setJetPt (jptjet->pt() ); 
     //     double unc = jecUnc->getUncertainty(true);
   
     double unc = 0.;

     EtaRaw->push_back(jptjetRef->eta());
     PhiRaw->push_back(jptjetRef->phi());
     EtRaw->push_back(jptjetRef->pt());

     EtaJPT->push_back(jptjet->eta());
     PhiJPT->push_back(jptjet->phi());
     EtJPT->push_back(jptjet->pt());
     Ntrk->push_back(npions);
     jesunc->push_back(unc);
     beta->push_back(jptjet->getSpecific().Zch);
   }

   delete jecUnc;

   // code to calculate variables for track counting veto: n_trk1GeV, n_trk3GeV, n_trk1GeV
   // 


   if( (EtJPT->size() >= 2) && ( (*EtaJPT)[0] * (*EtaJPT)[1] < 0.0) ) {

     const std::string trkqualiti = "highPurity";

     RecoMuons::const_iterator imuon = reco_muons->begin(); 
     RecoMuons::const_iterator jmuon = reco_muons->end();

     double eta_jmin = (*EtaJPT)[0]; 
     double eta_jmax = (*EtaJPT)[1]; 
     if( (*EtaJPT)[0] > (*EtaJPT)[1] ) {
       eta_jmin = (*EtaJPT)[1]; 
       eta_jmax = (*EtaJPT)[0]; 
     }
     // loop over tracks in vertex
     reco::Vertex::trackRef_iterator ittrk;
     for(ittrk =(*recVtxs)[0].tracks_begin(); ittrk != (*recVtxs)[0].tracks_end(); ++ittrk) {
       //       cout <<" track weight = " << (*recVtxs)[0].trackWeight(*ittrk) << endl;
       if( (*recVtxs)[0].trackWeight(*ittrk) > 0.5 && 
	   (*ittrk)->quality(reco::TrackBase::qualityByName(trkqualiti)) )  {
	 int muontrack = 0;
	 for ( ; imuon != jmuon; ++imuon ) {
	   if ( imuon->innerTrack().isNull() ) {continue;}
	   const reco::TrackBaseRef ttr1(imuon->innerTrack());
	   if ( *ittrk == ttr1 ) {
	     muontrack = 1; 
	   }
	 }
	 if(muontrack == 0) {
	   if( (*ittrk)->eta() > eta_jmin + 0.5 && (*ittrk)->eta() < eta_jmax - 0.5) {
	     if( (*ittrk)->pt() >= 1.0) {n_trk1GeV++;}
	     if( (*ittrk)->pt() >= 2.0) {n_trk2GeV++;}
	     if( (*ittrk)->pt() >= 3.0) {n_trk3GeV++;}
	   }
	 }
       }
     }
   }
   // fill tree
   //   if( mass_mumu >= 40. ) t1->Fill();

   if( (nvtx >= 1) & (L1ETM40 > 0 || VBF_AllJets > 0 || mass_mumu >= 40) ) t1->Fill();
}
//define this as a plug-in
DEFINE_FWK_MODULE(VBFHinvis);
