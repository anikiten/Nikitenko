#include <memory>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
//
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDFilter.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "SimDataFormats/GeneratorProducts/interface/HepMCProduct.h"
#include "SimGeneral/HepPDTRecord/interface/ParticleDataTable.h"
#include <iostream>
//

using namespace edm;
using namespace std;

class DPSAnalyser : public edm::EDAnalyzer {

public:
  explicit DPSAnalyser(const edm::ParameterSet&);
  ~DPSAnalyser();

private:

  virtual void beginJob() ;
  virtual void analyze(const edm::Event&, const edm::EventSetup&);
  virtual void endJob() ;

  // ----------member data ---------------------------
      
  std::string label_;
  
};


void DPSAnalyser::beginJob()
{
  return ;
}

void DPSAnalyser::endJob() {
  return ; 
}

DPSAnalyser::DPSAnalyser(const edm::ParameterSet& iConfig) : 
label_(iConfig.getUntrackedParameter("moduleLabel",std::string("generator")))
{
   //now do what ever initialization is needed

}


DPSAnalyser::~DPSAnalyser() 
{ 
  //
}



//
// member functions
//

// ------------ method called to produce the data  ------------
void DPSAnalyser::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
   using namespace edm;
   bool accepted = false;
   Handle<HepMCProduct> evt;
   iEvent.getByLabel(label_, evt);

   HepMC::GenEvent * myGenEvent = new  HepMC::GenEvent(*(evt->GetEvent()));
    
   //if(processID == 0 || processID == myGenEvent->signal_process_id()) {
    
   for ( HepMC::GenEvent::particle_iterator p = myGenEvent->particles_begin();
	 p != myGenEvent->particles_end(); ++p ) {
      
     std::cout <<" ID = " << (*p)->pdg_id() 
	       <<" status = " << (*p)->status() << std::endl;
     //      rapidity = 0.5*log( (*p)->momentum().e()+(*p)->momentum().pz()) / ((*p)->momentum().e()-(*p)->momentum().pz()) );

     /*
	if ( abs((*p)->pdg_id()) == particleID 
	     && (*p)->momentum().rho() > minpcut 
	     && (*p)->momentum().rho() < maxpcut
	     && (*p)->momentum().perp() > minptcut 
	     && (*p)->momentum().perp() < maxptcut
	     && (*p)->momentum().eta() > minetacut
	     && (*p)->momentum().eta() < maxetacut 
	     && rapidity > minrapcut
	     && rapidity < maxrapcut 
	     && (*p)->momentum().phi() > minphicut
	     && (*p)->momentum().phi() < maxphicut ) {
     */
             
     //	     HepMC::GenParticle* mother = (*((*p)->production_vertex()->particles_in_const_begin()));
     //		 if (abs(mother->pdg_id()) == abs(motherID)) {
   }
}

DEFINE_FWK_MODULE(DPSAnalyser);
