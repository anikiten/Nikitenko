import FWCore.ParameterSet.Config as cms

process = cms.Process("RECO3")

process.load("Configuration.StandardSequences.Services_cff")

process.load("Configuration.StandardSequences.Reconstruction_cff")

process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_cff")
process.GlobalTag.globaltag = cms.string('MC_3XY_V21::All')


process.load("Configuration.StandardSequences.Simulation_cff")

process.load("Configuration.StandardSequences.MixingNoPileUp_cff")

process.load("Configuration.StandardSequences.VtxSmearedGauss_cff")

process.load("Configuration.StandardSequences.Geometry_cff")

process.load("Configuration.StandardSequences.MagneticField_cff")

process.load("FWCore.MessageLogger.MessageLogger_cfi")

process.load('Configuration/StandardSequences/EndOfProcess_cff')

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(100)
)
### For 219, file from RelVal
process.source = cms.Source("PoolSource",
fileNames = cms.untracked.vstring(
  '/store/data/Run2010A/EGMonitor/RAW/v1/000/136/082/F684F6F7-AD66-DF11-A37B-000423D98B5C.root')
# '/store/data/Run2010A/EGMonitor/RECO/v1/000/136/082/DEDC155A-CE66-DF11-8432-0030487A18F2.root')
)


process.skimming = cms.EDFilter("Photon10Filter",
    TriggerResults = cms.InputTag("TriggerResults","","HLT"))

process.out = cms.OutputModule("PoolOutputModule",
    SelectEvents = cms.untracked.PSet(SelectEvents = cms.vstring('p')),
    outputCommands = cms.untracked.vstring('keep *'), 
    fileName = cms.untracked.string('Photon10.root'),
    dataset = cms.untracked.PSet(dataTier = cms.untracked.string('RAW'),filterName = cms.untracked.string('Photon10Filter'))
)

process.p = cms.Path(process.skimming)
process.endjob_step = cms.Path(process.endOfProcess)
process.e = cms.EndPath(process.out)

# Schedule definition
process.schedule = cms.Schedule(process.p,process.endjob_step,process.e)


# process.dump = cms.EDFilter("EventContentAnalyzer")

# process.p1 = cms.Path(process.dump)


