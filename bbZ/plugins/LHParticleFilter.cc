// -*- C++ -*-
//
// Package:    LHParticleFilter
// Class:      LHParticleFilter
// 
/**\class LHParticleFilter LHParticleFilter.cc PhysicsTools/HepMCCandAlgos/plugins/LHParticleFilter.cc

 Description: returns the particles that have the specified particle in the list of ancestors

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  Piergiulio Lenzi,32 3-B06,+41227676396,
//         Created:  Thu Feb 24 20:37:05 CET 2011
// $Id$
//
//


// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDFilter.h"
#include "FWCore/Utilities/interface/InputTag.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include <vector>
#include <string>

//
// class declaration
//

class LHParticleFilter : public edm::EDFilter {
   public:
      explicit LHParticleFilter(const edm::ParameterSet&);
      ~LHParticleFilter();

   private:
      virtual void beginJob() ;
      virtual bool filter(edm::Event&, const edm::EventSetup&);
      virtual void endJob() ;
      
      // ----------member data ---------------------------
      edm::InputTag    _src; 
      uint32_t          _pdgId;
      std::string      _cut; 
};


#include "SimDataFormats/GeneratorProducts/interface/LHEEventProduct.h"
#include "DataFormats/Math/interface/LorentzVector.h"
#include "CommonTools/Utils/interface/StringCutObjectSelector.h"

using namespace edm;
using namespace std;
using namespace reco;
//
// constructors and destructor
//
LHParticleFilter::LHParticleFilter(const edm::ParameterSet& iConfig):
_src(iConfig.getParameter<edm::InputTag>("src")),
_pdgId(iConfig.getParameter<uint32_t>("pdgId")),
_cut(iConfig.getParameter<std::string>("cut"))
{

}


LHParticleFilter::~LHParticleFilter()
{
 
}


//
// member functions
//

// ------------ method called to produce the data  ------------
bool
LHParticleFilter::filter(edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  Handle<LHEEventProduct> pIn;
  iEvent.getByLabel(_src, pIn);

  StringCutObjectSelector<math::XYZTLorentzVector> select(_cut);

  const lhef::HEPEUP & hepup = pIn->hepeup();
  //loop over particles looking for pdgId
  for (int i = 0; i < hepup.NUP; ++i){
    if (fabs(hepup.IDUP[i]) == _pdgId){
      lhef::HEPEUP::FiveVector fv = hepup.PUP[i];
      math::XYZTLorentzVector vec(fv[0], fv[1], fv[2], fv[3]);
      bool pass = select(vec);
      if (pass) return true; 
    }
  }
 
  return false;
}

// ------------ method called once each job just before starting event loop  ------------
void 
LHParticleFilter::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
void 
LHParticleFilter::endJob() {
}

//define this as a plug-in
DEFINE_FWK_MODULE(LHParticleFilter);
