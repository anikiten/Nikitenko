import FWCore.ParameterSet.Config as cms

process = cms.Process("RECO3")

process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.load("Configuration.Geometry.GeometryIdeal_cff")
process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_cff")
process.load("Configuration.StandardSequences.MagneticField_cff")

#process.GlobalTag.globaltag = cms.string('START53_V15::All') 
process.GlobalTag.globaltag = cms.string('FT_53_V6_AN3::All') 

# MVA PU jets ID
process.load("CMGTools.External.pujetidsequence_cff")
from CMGTools.External.pujetidsequence_cff import puJetId
process.recoPuJetId = puJetId.clone(
   jets = cms.InputTag("ak5PFJetsL1L2L3"),
   applyJec = cms.bool(False),
   inputIsCorrected = cms.bool(True)                
)

from CMGTools.External.pujetidsequence_cff import puJetMva
process.recoPuJetMva = puJetMva.clone(
   jets = cms.InputTag("ak5PFJetsL1L2L3"),
   jetids = cms.InputTag("recoPuJetId"),
   applyJec = cms.bool(False),
   inputIsCorrected = cms.bool(True)                
)

process.load("RecoJets.Configuration.RecoJPTJets_cff")
process.load("RecoJets.JetAssociationProducers.ak5JTA_cff")
process.load('JetMETCorrections.Configuration.DefaultJEC_cff')
process.load('JetMETCorrections.Configuration.JetCorrectionServices_cff')
process.load('JetMETCorrections.Type1MET.pfMETCorrections_cff')

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(10000)
)
### For 219, file from RelVal
process.source = cms.Source("PoolSource",
fileNames = cms.untracked.vstring(
# '/store/data/Run2011A/Jet/AOD/PromptReco-v1/000/161/312/F2A79C25-0A58-E011-BE69-003048F024C2.root')
#  'rfio:/castor/cern.ch/user/a/anikiten/di_muon_mc44/di_muon_mc44x_1_1_YUh.root')
#  'file:/tmp/anikiten/dymadgraph.root')	
  'file:/localscratch/MET_PD_test/MET_PD_test_1_1_JAH.root')
)


process.myjetplustrack = cms.EDAnalyzer("VBFHinvis",
    HistOutFile = cms.untracked.string('VBFHinvis.root'),
    DataOrMC = cms.untracked.int32(1),
    Muons    = cms.InputTag("muons"),	
    calojets = cms.InputTag("ak5CaloJets"),
    jetsID  = cms.InputTag("ak5JetID"),
    JPTjets = cms.InputTag("JetPlusTrackZSPCorJetAntiKt5"),
    JPTjetsL1L2L3 = cms.InputTag("ak5JPTJetsL1L2L3"),
    PFjetsL1L2L3 = cms.InputTag("ak5PFJetsL1L2L3"),
    TriggerResults = cms.InputTag("TriggerResults","","HLT")	
)

# JPTjetsL2L3 = cms.InputTag("ak5JPTJetsL2L3"),
# PFjetsL2K3 = cms.InputTag("ak5PFJetsL2L3"),
# CaloJetsL2L3 = cms.InputTag("ak5CaloJetsL2L3"),


process.dump = cms.EDAnalyzer("EventContentAnalyzer")

# process.p1 = cms.Path(process.dump)

#process.p1 = cms.Path(process.ak5JTA*process.recoJPTJets*process.ak5JPTJetsL1L2L3*process.myjetplustrack)

process.p1 = cms.Path(process.producePFMETCorrections*
                      process.ak5PFJetsL1L2L3*
                      process.recoPuJetId*
                      process.recoPuJetMva*
                      process.ak5JTA*
                      process.jetPlusTrackZSPCorJetAntiKt5*
                      process.ak5JPTJetsL1L2L3*
                      process.myjetplustrack)
