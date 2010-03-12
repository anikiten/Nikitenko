#ifndef JetPlusTrackAnalysis_h
#define JetPlusTrackAnalysis_h

#include "TrackingTools/TrackAssociator/interface/TrackDetectorAssociator.h"
// user include files
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include <string>
#include <memory>
#include <map>

namespace edm {
  class Event;
  class EventSetup;
  class ParameterSet;
}
#include "TFile.h"
#include "TTree.h"

///
/// jet energy corrections from MCjet calibration
///
namespace cms
{

class JetPlusTrackAnalysis : public edm::EDAnalyzer
{
public:  

  JetPlusTrackAnalysis(const edm::ParameterSet& fParameters);

  virtual ~JetPlusTrackAnalysis();

      virtual void analyze(const edm::Event&, const edm::EventSetup&);
      virtual void beginJob() ;
      virtual void beginRun(edm::Run const&, edm::EventSetup const&);
      virtual void endJob() ;
   
private:
// Histograms/Tree
     std::string fOutputFileName ;
     bool allowMissingInputs_;
     TFile*      hOutputFile ;
     TTree * myTree;
     int NumRecoJetsCaloTower, NumRecoJetsJPTCorrected, NumRecoJetsRecHit, NumGenJets;
     float JetRecoEtCaloTower[10],JetRecoEtaCaloTower[10],JetRecoPhiCaloTower[10];
     float JetRecoEtJPTCorrected[10],JetRecoEtCaloJetInit[10],JetRecoEtZSPCorrected[10],JetRecoEtAACorrected[10],
           JetRecoEtaJPTCorrected[10],JetRecoPhiJPTCorrected[10],JetRecoEtaCaloJetInit[10],JetRecoPhiCaloJetInit[10];
     float JetRecoGenRecType[10],JetRecoGenPartonType[10];
     float JetRecoEtRecHit[10],EcalEmpty[10],HcalEmpty[10];
     float JetGenEt[10],JetGenEta[10],JetGenPhi[10],JetGenCode[10];
     int Code[2],Charge[2],NumPart;
     float partpx[2],partpy[2],partpz[2],parte[2],partm[2];
     int run, event;

  double mCone;
  edm::InputTag mInputJetsCaloTower;
  edm::InputTag mInputJetsCorrected; 
  edm::InputTag mInputJetsGen;
  std::vector<edm::InputTag> ecalLabels_;
  edm::InputTag ebrechit;
  edm::InputTag eerechit;
  edm::InputTag hbhelabel_;
  edm::InputTag holabel_;
  const CaloGeometry* geo;
};
}
#endif
