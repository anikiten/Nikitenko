import FWCore.ParameterSet.Config as cms

process = cms.Process("RECO3")

process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.load("Configuration.StandardSequences.Geometry_cff")
process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_cff")
process.load("Configuration.StandardSequences.MagneticField_cff")
# process.GlobalTag.globaltag = cms.string('START311_V2::All')
# process.GlobalTag.globaltag = cms.string('MC_311_V1::All')
process.GlobalTag.globaltag = cms.string('MC_42_V6::All')

# process.load("RecoJets.Configuration.RecoJPTJets_cff")
process.load('JetMETCorrections.Configuration.DefaultJEC_cff')
#
# Summer10 corrections to be used for 3_9_X
#
# process.load('JetMETCorrections.Configuration.JetCorrectionServices_cff')
# process.ak5JPTL1Offset.useCondDB = False
# process.ak5JPTL2Relative = process.ak5CaloL2Relative.clone( era='Summer10',algorithm = 'AK5JPT' )
# process.ak5JPTL3Absolute    = process.ak5CaloL3Absolute.clone( era='Summer10',algorithm = 'AK5JPT' )
# process.ak5JPTResidual = process.ak5CaloResidual.clone( era='Summer10',algorithm = 'AK5JPT' )


#
# Preliminary Spring11 corrections for CMSSW_4_2_0 to be used with 4_1_X. Comment these lines for 4_2_X and 3_9_X
#
########################################################################################
process.load("CondCore.DBCommon.CondDBCommon_cfi")
process.jec = cms.ESSource("PoolDBESSource",
      DBParameters = cms.PSet(
        messageLevel = cms.untracked.int32(0)
        ),
      timetype = cms.string('runnumber'),
      toGet = cms.VPSet(
      cms.PSet(
            record = cms.string('JetCorrectionsRecord'),
            tag    = cms.string('JetCorrectorParametersCollection_Jec11_V1_AK5JPT'),
            label  = cms.untracked.string('AK5JPT')
            )
      ),
      ## here you add as many jet types as you need (AK5Calo, AK5JPT, AK7PF, AK7Calo, KT4PF, KT4Calo)
      connect = cms.string('frontier://FrontierPrep/CMS_COND_PHYSICSTOOLS')
)
process.es_prefer_jec = cms.ESPrefer('PoolDBESSource','jec')
#########################################################################################

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(100)
)
### For 219, file from RelVal
process.source = cms.Source("PoolSource",
fileNames = cms.untracked.vstring(
#  '/store/relval/CMSSW_4_1_3/RelValTTbar/GEN-SIM-RECO/START311_V2-v1/0037/648B6AA5-C751-E011-8208-001A928116C6.root')
# '/store/relval/CMSSW_3_11_1/RelValProdMinBias/AODSIM/MC_311_V1_64bit-v1/0091/5AAB06A6-DB35-E011-AE91-0018F3D095FA.root')
# '/store/relval/CMSSW_3_11_1/RelValProdTTbar/AODSIM/MC_311_V1_64bit-v1/0091/9C4D3BA6-DB35-E011-A35F-0018F3D095EA.root')
  '/store/relval/CMSSW_4_2_0/RelValQCD_Pt_80_120/GEN-SIM-RECO/MC_42_V9-v1/0054/6C66ADBF-6B5E-E011-89CF-00304867C16A.root')
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
