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

process.load("RecoJets.Configuration.RecoJPTJets_cff")

process.load('JetMETCorrections.Configuration.DefaultJEC_cff')

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(100)
)
### For 219, file from RelVal
process.source = cms.Source("PoolSource",
fileNames = cms.untracked.vstring(
'/store/relval/CMSSW_3_6_0_pre6/RelValQCD_Pt_3000_3500/GEN-SIM-RECO/START36_V4-v1/0011/FE30B408-D044-DF11-92FC-0026189438C1.root')
)


process.myjetplustrack = cms.EDFilter("JetPlusTrackAnalysis",
    HistOutFile = cms.untracked.string('JPTAnalysis.root'),
    calojets = cms.InputTag("ak5CaloJets"),
    jetsID  = cms.InputTag("ak5JetID"),
    JPTjets = cms.InputTag("JetPlusTrackZSPCorJetAntiKt5"),
# JPTjetsL2L3 = cms.InputTag("ak5JPTJetsL2L3"),
# PFjetsL2K3 = cms.InputTag("ak5PFJetsL2L3"),
# CaloJetsL2L3 = cms.InputTag("ak5CaloJetsL2L3"),
    TriggerResults = cms.InputTag("TriggerResults","","HLT")	
)


process.dump = cms.EDFilter("EventContentAnalyzer")

# for 360 to be used with 35X datasets. It create JPT not L2L3 corrected jet collecion: JetPlusTrackZSPCorJetAntiKt5
# process.p1 = cms.Path(process.recoJPTJets*process.myjetplustrack)

# for 360: access to not L2L3 corrected JPT jet collection: JetPlusTrackZSPCorJetAntiKt5
process.p1 = cms.Path(process.myjetplustrack)

# for 360: create colection of L2L3 corrected JPT jets: ak5JPTJetsL2L3  
# one need set of tags will be provided be JES
# process.p1 = cms.Path(process.ak5JPTJetsL2L3*process.myjetplustrack)