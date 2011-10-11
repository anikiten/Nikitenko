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
    input = cms.untracked.int32(1000)
)
### For 219, file from RelVal
process.source = cms.Source("PoolSource",
fileNames = cms.untracked.vstring(
# '/store/data/Run2011A/Jet/AOD/PromptReco-v1/000/161/312/F2A79C25-0A58-E011-BE69-003048F024C2.root')
  'rfio:/castor/cern.ch/user/a/anikiten/bbHMC/bbHMCevents_1_1_JAC.root')
)


process.bbhanalysis = cms.EDAnalyzer("bbH",
    HistOutFile = cms.untracked.string('bbH.root'),
    parton_jets = cms.InputTag("ak5PartonJets")
)

# JPTjetsL2L3 = cms.InputTag("ak5JPTJetsL2L3"),
# PFjetsL2K3 = cms.InputTag("ak5PFJetsL2L3"),
# CaloJetsL2L3 = cms.InputTag("ak5CaloJetsL2L3"),


process.dump = cms.EDAnalyzer("EventContentAnalyzer")

# process.p1 = cms.Path(process.dump)

# process.p1 = cms.Path(process.recoJPTJets*process.myjetplustrack)
 
# process.p1 = cms.Path(process.ak5JPTJetsL2L3*process.myjetplustrack)

process.p1 = cms.Path(process.genParticlesForPartonJets*process.ak5PartonJets*process.bbhanalysis)

# process.p1 = cms.Path(process.dump)
