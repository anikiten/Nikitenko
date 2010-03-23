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

# process.load("JetMETCorrections.Configuration.L2L3Corrections_Summer09_7TeV_ReReco332_cff")

# process.prefer("L2L3JetCorrectorAK5Calo") 

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(10)
)
### For 219, file from RelVal
process.source = cms.Source("PoolSource",
fileNames = cms.untracked.vstring(
#'/store/relval/CMSSW_3_5_0/RelValQCD_Pt_80_120/GEN-SIM-RECO/MC_3XY_V21-v1/0012/16F61E92-3513-DF11-97DB-00248C0BE013.root')
 '/store/relval/CMSSW_3_6_0_pre2/RelValQCD_Pt_80_120/GEN-SIM-RECO/MC_3XY_V24-v1/0001/22D67382-A427-DF11-975F-00261894397E.root')
)


process.myjetplustrack = cms.EDFilter("JetPlusTrackAnalysis",
    HistOutFile = cms.untracked.string('JetAnalysis.root'),
#    src2 = cms.InputTag("ak5GenJets"),
    jetsID  = cms.InputTag("ak5JetID"),
    JPTjets = cms.InputTag("JetPlusTrackZSPCorJetAntiKt5"),
    TriggerResults = cms.InputTag("TriggerResults","","HLT")	
)


process.dump = cms.EDFilter("EventContentAnalyzer")

# process.p1 = cms.Path(process.recoJPTJets)

process.p1 = cms.Path(process.recoJPTJets*process.myjetplustrack)
