import FWCore.ParameterSet.Config as cms

process = cms.Process("RECO3")

process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.load("Configuration.StandardSequences.Geometry_cff")
process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_cff")
process.load("Configuration.StandardSequences.MagneticField_cff")
# process.GlobalTag.globaltag = cms.string('START311_V2::All')
process.GlobalTag.globaltag = cms.string('MC_311_V1::All')

# process.load("Configuration.StandardSequences.Services_cff")
# process.load("Configuration.StandardSequences.Reconstruction_cff")
# process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_cff")
# process.GlobalTag.globaltag = cms.string('MC_3XY_V21::All')
# process.GlobalTag.globaltag = cms.string('GR_R_38X_V15::All')
# process.GlobalTag.globaltag = cms.string('START39_V8::All')
# process.load("Configuration.StandardSequences.Simulation_cff")
# process.load("Configuration.StandardSequences.MixingNoPileUp_cff")
# process.load("Configuration.StandardSequences.VtxSmearedGauss_cff")

process.load("RecoJets.Configuration.RecoJPTJets_cff")
process.load('JetMETCorrections.Configuration.DefaultJEC_cff')
process.load('JetMETCorrections.Configuration.JetCorrectionServices_cff')
process.ak5JPTL1Offset.useCondDB = False
process.ak5JPTL2Relative = process.ak5CaloL2Relative.clone( era='Summer10',algorithm = 'AK5JPT' )
process.ak5JPTL3Absolute    = process.ak5CaloL3Absolute.clone( era='Summer10',algorithm = 'AK5JPT' )
process.ak5JPTResidual = process.ak5CaloResidual.clone( era='Summer10',algorithm = 'AK5JPT' )

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(100)
)
### For 219, file from RelVal
process.source = cms.Source("PoolSource",
fileNames = cms.untracked.vstring(
#'/store/relval/CMSSW_3_5_0/RelValQCD_Pt_80_120/GEN-SIM-RECO/MC_3XY_V21-v1/0012/16F61E92-3513-DF11-97DB-00248C0BE013.root')
# '/store/relval/CMSSW_3_6_0_pre2/RelValQCD_Pt_80_120/GEN-SIM-RECO/MC_3XY_V24-v1/0001/22D67382-A427-DF11-975F-00261894397E.root')
#'/store/relval/CMSSW_3_6_0_pre6/RelValQCD_Pt_3000_3500/GEN-SIM-RECO/START36_V4-v1/0011/FE30B408-D044-DF11-92FC-0026189438C1.root')
# '/store/relval/CMSSW_3_9_7/RelValQCD_Pt_80_120/GEN-SIM-RECO/START39_V8-v1/0050/1C628AB0-CA0D-E011-BC46-001A92810A94.root')
#  '/store/relval/CMSSW_4_1_3/RelValTTbar/GEN-SIM-RECO/START311_V2-v1/0037/648B6AA5-C751-E011-8208-001A928116C6.root')
# '/store/relval/CMSSW_3_11_1/RelValProdMinBias/AODSIM/MC_311_V1_64bit-v1/0091/5AAB06A6-DB35-E011-AE91-0018F3D095FA.root')
'/store/relval/CMSSW_3_11_1/RelValProdTTbar/AODSIM/MC_311_V1_64bit-v1/0091/9C4D3BA6-DB35-E011-A35F-0018F3D095EA.root')
)


process.myjetplustrack = cms.EDAnalyzer("JetPlusTrackAnalysis_MC",
     HistOutFile = cms.untracked.string('JPTAnalysis_Data.root'),
    genjets = cms.InputTag("ak5GenJets"),
    calojets = cms.InputTag("ak5CaloJets"),
    jetsID  = cms.InputTag("ak5JetID"),
    JPTjets = cms.InputTag("JetPlusTrackZSPCorJetAntiKt5"),
    TriggerResults = cms.InputTag("TriggerResults","","HLT")	
)

# JPTjetsL2L3 = cms.InputTag("ak5JPTJetsL2L3"),
# PFjetsL2K3 = cms.InputTag("ak5PFJetsL2L3"),
# CaloJetsL2L3 = cms.InputTag("ak5CaloJetsL2L3"),


process.dump = cms.EDAnalyzer("EventContentAnalyzer")

# process.p1 = cms.Path(process.dump)

# process.p1 = cms.Path(process.recoJPTJets*process.myjetplustrack)
 
# process.p1 = cms.Path(process.ak5JPTJetsL2L3*process.myjetplustrack)

process.p1 = cms.Path(process.ak5JPTJetsL1L2L3*process.myjetplustrack)

# process.p1 = cms.Path(process.dump)
