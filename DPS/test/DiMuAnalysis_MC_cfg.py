import FWCore.ParameterSet.Config as cms

process = cms.Process("RECO3")

process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.load("Configuration.StandardSequences.Geometry_cff")
process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_cff")
process.load("Configuration.StandardSequences.MagneticField_cff")

process.GlobalTag.globaltag = cms.string('START44_V13::All') 

process.load("RecoJets.Configuration.RecoJPTJets_cff")
process.load("RecoJets.JetAssociationProducers.ak5JTA_cff")
process.load('JetMETCorrections.Configuration.DefaultJEC_cff')
process.load('JetMETCorrections.Configuration.JetCorrectionServices_cff')

from CondCore.DBCommon.CondDBSetup_cfi import *
process.jec = cms.ESSource("PoolDBESSource",CondDBSetup,
                                connect =
cms.string("sqlite:src/CondFormats/JetMETObjects/data/Fall11.db"),
                                toGet =  cms.VPSet(
                       cms.PSet(record = cms.string("JetCorrectionsRecord"),
                                tag =
cms.string("JetCorrectorParametersCollection_Fall11_AK5Calo"),
                                label=cms.untracked.string("AK5Calo")),
                       cms.PSet(record = cms.string("JetCorrectionsRecord"),
                                tag =
cms.string("JetCorrectorParametersCollection_Fall11_AK5PF"),
                                label=cms.untracked.string("AK5PF")),
                       cms.PSet(record = cms.string("JetCorrectionsRecord"),
                                tag =
cms.string("JetCorrectorParametersCollection_Fall11_AK5JPT"),
                                label=cms.untracked.string("AK5JPT"))
                       )
                   )
process.es_prefer_jec = cms.ESPrefer("PoolDBESSource","jec")

process.ak5JPTL1Offset.algorithm = 'AK5JPT'
process.ak5JetTracksAssociatorAtVertex.useAssigned = cms.bool(True)
process.ak5JetTracksAssociatorAtVertex.pvSrc = cms.InputTag("offlinePrimaryVertices")

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(10000)
)
### For 219, file from RelVal
process.source = cms.Source("PoolSource",
fileNames = cms.untracked.vstring(
# '/store/data/Run2011A/Jet/AOD/PromptReco-v1/000/161/312/F2A79C25-0A58-E011-BE69-003048F024C2.root')
#  'rfio:/castor/cern.ch/user/a/anikiten/di_muon_mc44/di_muon_mc44x_1_1_YUh.root')
  'file:/tmp/anikiten/dymadgraph.root')	
)


process.myjetplustrack = cms.EDAnalyzer("DiMuAnalysis_Data",
    HistOutFile = cms.untracked.string('DiMuAnalysis_MC.root'),
    DataOrMC = cms.untracked.int32(1),
    Muons    = cms.InputTag("muons"),	
    calojets = cms.InputTag("ak5CaloJets"),
    jetsID  = cms.InputTag("ak5JetID"),
    JPTjets = cms.InputTag("JetPlusTrackZSPCorJetAntiKt5"),
    JPTjetsL1L2L3 = cms.InputTag("ak5JPTJetsL1L2L3"),
    TriggerResults = cms.InputTag("TriggerResults","","HLT")	
)

# JPTjetsL2L3 = cms.InputTag("ak5JPTJetsL2L3"),
# PFjetsL2K3 = cms.InputTag("ak5PFJetsL2L3"),
# CaloJetsL2L3 = cms.InputTag("ak5CaloJetsL2L3"),


process.dump = cms.EDAnalyzer("EventContentAnalyzer")

# process.p1 = cms.Path(process.dump)


process.p1 = cms.Path(process.ak5JTA*process.recoJPTJets*process.ak5JPTJetsL1L2L3*process.myjetplustrack)

