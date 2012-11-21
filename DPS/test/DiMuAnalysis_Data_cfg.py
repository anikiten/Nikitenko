import FWCore.ParameterSet.Config as cms

process = cms.Process("RECO3")

process.load("FWCore.MessageLogger.MessageLogger_cfi")
#process.load("Configuration.StandardSequences.Geometry_cff")
process.load("Configuration.Geometry.GeometryIdeal_cff")
process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_cff")
process.load("Configuration.StandardSequences.MagneticField_cff")

process.load("RecoJets.Configuration.RecoJPTJets_cff")
process.load("RecoJets.JetAssociationProducers.ak5JTA_cff")
process.load('JetMETCorrections.Configuration.DefaultJEC_cff')
process.load('JetMETCorrections.Configuration.JetCorrectionServices_cff')
# process.load('JetMETCorrections.Type1MET.MetType1Corrections_cff')
process.load('JetMETCorrections.Type1MET.pfMETCorrections_cff')

# process.GlobalTag.globaltag = cms.string('START311_V2::All')
# process.GlobalTag.globaltag = cms.string('MC_311_V1::All')
# process.GlobalTag.globaltag = cms.string('GR_R_311_V2::All')

# process.GlobalTag.globaltag = cms.string('FT_R_42_V13A::All') 
# process.GlobalTag.globaltag = cms.string('GR_R_44_V4::All')

# process.GlobalTag.globaltag = cms.string('GR_R_44_V14::All') 

process.GlobalTag.globaltag = cms.string('GR_R_53_V13::All') 

process.load("CMGTools.External.pujetidsequence_cff")

from CMGTools.External.pujetidsequence_cff import puJetId
process.recoPuJetId = puJetId.clone(
   jets = cms.InputTag("ak5PFJets"),
   applyJec = cms.bool(False),
   inputIsCorrected = cms.bool(True)                
)

from CMGTools.External.pujetidsequence_cff import puJetMva
process.recoPuJetMva = puJetMva.clone(
   jets = cms.InputTag("ak5PFJets"),
   jetids = cms.InputTag("recoPuJetId"),
   applyJec = cms.bool(False),
   inputIsCorrected = cms.bool(True)                
)


####################################################################################
#from CondCore.DBCommon.CondDBSetup_cfi import *
#process.jec = cms.ESSource("PoolDBESSource",CondDBSetup,
#                           connect =
#cms.string("frontier://FrontierPrep/CMS_COND_PHYSICSTOOLS"),
#                   toGet =  cms.VPSet(
#                       cms.PSet(record = cms.string("JetCorrectionsRecord"),
#                                tag =
#cms.string("JetCorrectorParametersCollection_Jec11_V7_AK5Calo"),
#                                label=cms.untracked.string("AK5Calo")),
#                       cms.PSet(record = cms.string("JetCorrectionsRecord"),
#                                tag =
#cms.string("JetCorrectorParametersCollection_Jec11_V7_AK5PF"),
#                                label=cms.untracked.string("AK5PF")),
#                       cms.PSet(record = cms.string("JetCorrectionsRecord"),
#                                tag =
#cms.string("JetCorrectorParametersCollection_Jec11_V7_AK5PFchs"),
#                                label=cms.untracked.string("AK5PFchs")),
#                       cms.PSet(record = cms.string("JetCorrectionsRecord"),
#                                tag =
#cms.string("JetCorrectorParametersCollection_Jec11_V7_AK5JPT"),
#                                label=cms.untracked.string("AK5JPT")),
#                       cms.PSet(record = cms.string("JetCorrectionsRecord"),
#                                tag =
#cms.string("JetCorrectorParametersCollection_Jec11_V3_KT4Calo"),
#                                label=cms.untracked.string("KT4Calo")),
#                       cms.PSet(record = cms.string("JetCorrectionsRecord"),
#                                tag =
#cms.string("JetCorrectorParametersCollection_Jec11_V3_AK7Calo"),
#                                label=cms.untracked.string("AK7Calo")),
#                       )
#
#                   )
#process.es_prefer_jec = cms.ESPrefer("PoolDBESSource","jec")
#process.ak5JPTL1Offset.algorithm = 'AK5JPT'
########################################################################################

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(100)
)
### For 219, file from RelVal
process.source = cms.Source("PoolSource",
fileNames = cms.untracked.vstring(
# '/store/data/Run2011A/Jet/AOD/PromptReco-v1/000/161/312/F2A79C25-0A58-E011-BE69-003048F024C2.root')
#  'rfio:/castor/cern.ch/user/a/anikiten/DiMuonData2011/DiMuons_May10ReReco_1_1_ggY.root')
#  'file:/localscratch/dimu2012file/DiMuons2012_1_1_9jG.root')
  'file:/localscratch/MET_PD_test/MET_PD_test_1_1_JAH.root')
)


process.myjetplustrack = cms.EDAnalyzer("VBFHinvis",
    HistOutFile = cms.untracked.string('VBFHinvis.root'),
    DataOrMC = cms.untracked.int32(0),
    Muons    = cms.InputTag("muons"),	
    calojets = cms.InputTag("ak5CaloJets"),
    jetsID  = cms.InputTag("ak5JetID"),
    JPTjets = cms.InputTag("JetPlusTrackZSPCorJetAntiKt5"),
    JPTjetsL1L2L3 = cms.InputTag("ak5JPTJetsL1L2L3Residual"),
#    JPTjetsL1L2L3 = cms.InputTag("ak5JPTJetsL1L2L3"),
    TriggerResults = cms.InputTag("TriggerResults","","HLT")	
)

# JPTjetsL2L3 = cms.InputTag("ak5JPTJetsL2L3"),
# PFjetsL2K3 = cms.InputTag("ak5PFJetsL2L3"),
# CaloJetsL2L3 = cms.InputTag("ak5CaloJetsL2L3"),


process.dump = cms.EDAnalyzer("EventContentAnalyzer")

process.p1 = cms.Path(process.producePFMETCorrections*
                      process.ak5PFJetsL1L2L3Residual*
                      process.recoPuJetId*
                      process.recoPuJetMva*
                      process.ak5JTA*
                      process.jetPlusTrackZSPCorJetAntiKt5*
                      process.ak5JPTJetsL1L2L3Residual*
                      process.myjetplustrack)

# process.p1 = cms.Path(process.metJESCorAK5PFJet*process.dump)

# process.p1 = cms.Path(process.producePFMETCorrections*process.ak5PFJetsL1L2L3Residual*process.dump)
