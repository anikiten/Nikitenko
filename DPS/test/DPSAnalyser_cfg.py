import FWCore.ParameterSet.Config as cms

process = cms.Process("GEN")
process.load("FWCore.MessageService.MessageLogger_cfi")

# control point for all seeds
#
process.load("Configuration.StandardSequences.SimulationRandomNumberGeneratorSeeds_cff")

process.load("SimGeneral.HepPDTESSource.pythiapdt_cfi")

process.load("GeneratorInterface.Pythia6Interface.pythiaDefault_cff")

process.load("Configuration.EventContent.EventContent_cff")

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(2)
)
process.options = cms.untracked.PSet(
    wantSummary = cms.untracked.bool(True)
)
process.configurationMetadata = cms.untracked.PSet(
    version = cms.untracked.string(''),
    name = cms.untracked.string(''),
    annotation = cms.untracked.string('Sherpa Analysis')
)

process.source = cms.Source("PoolSource",
fileNames = cms.untracked.vstring(
#  '/store/relval/CMSSW_3_6_3/RelValZTT/GEN-SIM-DIGI-RAW-HLTDEBUG/START36_V10-v1/0006/BEB9D2C1-5878-DF11-B8B7-00248C55CC97.root')
#   'file:/tmp/anikiten/wtaunu.root')
   'file:sherpa.root')
)

process.mydpsanalysis = cms.EDFilter("DPSAnalyser",
    hepmc = cms.InputTag("generator")
)

process.dump = cms.EDFilter("EventContentAnalyzer")

# process.p1 = cms.Path(process.dump)

process.p1 = cms.Path(process.mydpsanalysis)

