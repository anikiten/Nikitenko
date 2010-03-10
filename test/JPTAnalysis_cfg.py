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


process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(10)
)
### For 219, file from RelVal
process.source = cms.Source("PoolSource",
fileNames = cms.untracked.vstring('/store/relval/CMSSW_3_5_0/RelValQCD_Pt_80_120/GEN-SIM-RECO/MC_3XY_V21-v1/0012/16F61E92-3513-DF11-97DB-00248C0BE013.root')
)


process.myjetplustrack = cms.EDFilter("JetPlusTrackAnalysis",
    HistOutFile = cms.untracked.string('JetAnalysis.root'),
    src2 = cms.InputTag("ak5GenJets"),
    src3 = cms.InputTag("JetPlusTrackZSPCorJetAntiKt5"),
    src4 = cms.InputTag("ZSPJetCorJetAntiKt5"),
    src1 = cms.InputTag("ak5CaloJets"),
    Cone = cms.double(0.5),
    ecalInputs = cms.VInputTag(cms.InputTag("ecalRecHit","EcalRecHitsEB"), cms.InputTag("ecalRecHit","EcalRecHitsEE")),
    HFRecHitCollectionLabel = cms.InputTag("hfreco"),
    HORecHitCollectionLabel = cms.InputTag("horeco"),
    HBHERecHitCollectionLabel = cms.InputTag("hbhereco"),
    inputTrackLabel = cms.untracked.string('generalTracks')
)

#process.p1 = cms.Path(process.recoJPTJets)

process.p1 = cms.Path(process.recoJPTJets*process.myjetplustrack)
