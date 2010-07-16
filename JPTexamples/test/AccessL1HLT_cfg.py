import FWCore.ParameterSet.Config as cms

process = cms.Process("RECO4")

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

process.load('JetMETCorrections.Configuration.DefaultJEC_cff')

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(10)
)
### For 219, file from RelVal
process.source = cms.Source("PoolSource",
fileNames = cms.untracked.vstring(
# '/store/relval/CMSSW_3_5_0/RelValQCD_Pt_80_120/GEN-SIM-RECO/MC_3XY_V21-v1/0012/16F61E92-3513-DF11-97DB-00248C0BE013.root')
# '/store/relval/CMSSW_3_6_0_pre2/RelValQCD_Pt_80_120/GEN-SIM-RECO/MC_3XY_V24-v1/0001/22D67382-A427-DF11-975F-00261894397E.root')
# '/store/relval/CMSSW_3_6_0_pre6/RelValQCD_Pt_3000_3500/GEN-SIM-RECO/START36_V4-v1/0011/FE30B408-D044-DF11-92FC-0026189438C1.root')
 '/store/data/Run2010A/JetMETTau/RECO/Jun14thReReco_v2/0000/4CC2E9A2-047A-DF11-90B1-003048D476CC.root')
#  '/store/data/Run2010A/EGMonitor/RAW/v1/000/136/082/F684F6F7-AD66-DF11-A37B-000423D98B5C.root')
# '/store/data/Run2010A/EGMonitor/RECO/v1/000/136/082/DEDC155A-CE66-DF11-8432-0030487A18F2.root')
#  'file:Photon10.root')
#  'rfio:/castor/cern.ch/user/a/anikiten/Photon10Skim/Photon10.root')
)


process.myjetplustrack = cms.EDFilter("AccessL1HLT",
     L1CenJet = cms.InputTag("l1extraParticles","Central"),
     L1TauJet = cms.InputTag("l1extraParticles","Tau"),
     L1FwdJet = cms.InputTag("l1extraParticles","Forward"),
     HLTSummary = cms.InputTag("hltTriggerSummaryAOD"),
     TriggerResults = cms.InputTag("TriggerResults","","HLT"),
     HLTTags = cms.VInputTag(cms.InputTag("hltL1sJet15U","","HLT"),
                             cms.InputTag("hltL1sJet30U","","HLT"),
                             cms.InputTag("hltL1sJet50U","","HLT"),
                             cms.InputTag("hltL1sFwdJet20U","","HLT"),
                             cms.InputTag("hltL1sL1Jet10U","","HLT"),
                             cms.InputTag("hltL1sL1Jet6U","","HLT"),
                             cms.InputTag("hltL1sL1SingleCenJet","","HLT"),
                             cms.InputTag("hltL1sL1SingleForJet","","HLT"),
                             cms.InputTag("hltL1sL1SingleTauJet","","HLT"),
                             cms.InputTag("hltL1sSingleLooseIsoTau20","","HLT"))
)


process.dump = cms.EDFilter("EventContentAnalyzer")

# process.p1 = cms.Path(process.dump)

# process.p1 = cms.Path(process.recoJPTJets*process.myjetplustrack)
 
# process.p1 = cms.Path(process.ak5JPTJetsL2L3*process.dump*process.myjetplustrack)

# process.p1 = cms.Path(process.ak5JPTJetsL2L3*process.myjetplustrack)

process.p1 = cms.Path(process.myjetplustrack)

