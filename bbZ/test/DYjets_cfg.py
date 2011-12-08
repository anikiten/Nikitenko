import FWCore.ParameterSet.Config as cms

process = cms.Process("RECO3")

process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.load("Configuration.StandardSequences.Geometry_cff")
process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_cff")
process.load("Configuration.StandardSequences.MagneticField_cff")

# parton jet
process.load("RecoJets.Configuration.GenJetParticles_cff")
process.genParticlesForPartonJets = process.genParticlesForJets.clone()
# process.genParticlesForPartonJets.ignoreParticleIDs = cms.vuint32()
process.genParticlesForPartonJets.partonicFinalState = True
process.genParticlesForPartonJets.excludeFromResonancePids = cms.vuint32(11, 12, 13, 14, 15, 16)

process.load("RecoJets.JetProducers.ak5GenJets_cfi")
process.ak5PartonJets  =  process.ak5GenJets.clone()
process.ak5PartonJets.src = cms.InputTag("genParticlesForPartonJets")


process.GlobalTag.globaltag = cms.string('START42_V11::All')

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(10000)
)
### For 219, file from RelVal
process.source = cms.Source("PoolSource",
fileNames = cms.untracked.vstring(
  'rfio:/castor/cern.ch/user/a/anikiten/dy_sherpa_madgraph/dymadgraph_1_1_xn5.root')
#  'rfio:/castor/cern.ch/user/a/anikiten/dy_sherpa_madgraph/dysherpa_1_1_pMD.root',
#  'rfio:/castor/cern.ch/user/a/anikiten/dy_sherpa_madgraph/dysherpa_2_1_IRW.root',
#  'rfio:/castor/cern.ch/user/a/anikiten/dy_sherpa_madgraph/dysherpa_3_1_rBk.root',
#  'rfio:/castor/cern.ch/user/a/anikiten/dy_sherpa_madgraph/dysherpa_4_1_gl5.root')
)


process.bbhanalysis = cms.EDAnalyzer("DYjets",
    HistOutFile = cms.untracked.string('dymadgraph.root'),
#    HistOutFile = cms.untracked.string('dysherpa.root'),
#    parton_jets = cms.InputTag("ak5PartonJets")
    parton_jets = cms.InputTag("ak5GenJets")
)

# JPTjetsL2L3 = cms.InputTag("ak5JPTJetsL2L3"),
# PFjetsL2K3 = cms.InputTag("ak5PFJetsL2L3"),
# CaloJetsL2L3 = cms.InputTag("ak5CaloJetsL2L3"),


process.dump = cms.EDAnalyzer("EventContentAnalyzer")

# process.p1 = cms.Path(process.genParticlesForPartonJets*process.ak5PartonJets*process.bbhanalysis)

process.p1 = cms.Path(process.bbhanalysis)

# process.p1 = cms.Path(process.dump)
