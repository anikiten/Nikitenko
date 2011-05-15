import FWCore.ParameterSet.Config as cms

process = cms.Process("RECO3")

process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.load("Configuration.StandardSequences.Geometry_cff")
process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_cff")
process.load("Configuration.StandardSequences.MagneticField_cff")

process.GlobalTag.globaltag = cms.string('START311_V2::All')
# process.GlobalTag.globaltag = cms.string('MC_311_V1::All')
# process.GlobalTag.globaltag = cms.string('GR_R_311_V2::All')

# process.load("Configuration.StandardSequences.Services_cff")
# process.load("Configuration.StandardSequences.Reconstruction_cff")
# process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_cff")
# process.GlobalTag.globaltag = cms.string('MC_3XY_V21::All')
# process.GlobalTag.globaltag = cms.string('GR_R_38X_V15::All')
# process.GlobalTag.globaltag = cms.string('START39_V8::All')
# process.load("Configuration.StandardSequences.Simulation_cff")
# process.load("Configuration.StandardSequences.MixingNoPileUp_cff")
# process.load("Configuration.StandardSequences.VtxSmearedGauss_cff")

#
# Summer10 corrections. For 4_1_X use pre420 corrections. For 420X use 420X KJS
#
process.load("RecoJets.Configuration.RecoJPTJets_cff")
process.load('JetMETCorrections.Configuration.DefaultJEC_cff')
process.load('JetMETCorrections.Configuration.JetCorrectionServices_cff')

#process.ak5JPTL1Offset.useCondDB = False
#process.ak5JPTL2Relative = process.ak5CaloL2Relative.clone( era='Summer10',algorithm = 'AK5JPT' )
#process.ak5JPTL3Absolute    = process.ak5CaloL3Absolute.clone( era='Summer10',algorithm = 'AK5JPT' )
#process.ak5JPTResidual = process.ak5CaloResidual.clone( era='Summer10',algorithm = 'AK5JPT' )
#
# pre 420 corrections
#
# Preliminary Spring11 corrections for CMSSW_4_2_0 to be used with 4_1_X for JPT
#
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

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(10000)
)
### For 219, file from RelVal
process.source = cms.Source("PoolSource",
fileNames = cms.untracked.vstring(
 '/store/data/Run2011A/Jet/AOD/PromptReco-v1/000/161/312/F2A79C25-0A58-E011-BE69-003048F024C2.root')
)


process.myjetplustrack = cms.EDAnalyzer("JetPlusTrackAnalysis_Data",
    HistOutFile = cms.untracked.string('JPTAnalysis_Data.root'),
#    HistOutFile = cms.untracked.string('JPTAnalysis_MC.root'),
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
