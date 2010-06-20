# ak5JetExtender
# ak5JetID

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

process.load("JetMETCorrections/TauJet/TCTauProducer_cff")

# process.load("RecoTauTag.RecoTau.CaloRecoTauTagInfoProducer_cfi")
# process.caloRecoTauTagInfoProducer.CaloJetTracksAssociatorProducer = cms.InputTag('ak5JetTracksAssociatorAtVertex')
# process.caloRecoTauTagInfoProducer.tkQuality = cms.string('highPurity')

# process.load("RecoTauTag.RecoTau.CaloRecoTauProducer_cfi")
# process.caloRecoTauProducer.TrackerSignalConeSizeFormula = cms.string('0.15')

#### Choose techical bits 40 and coincidence with BPTX (0)
process.load('L1TriggerConfig.L1GtConfigProducers.L1GtTriggerMaskTechTrigConfig_cff')
process.load('HLTrigger/HLTfilters/hltLevel1GTSeed_cfi')
process.hltLevel1GTSeed.L1TechTriggerSeeding = cms.bool(True)
process.hltLevel1GTSeed.L1SeedsLogicalExpression = cms.string('0 AND 40 AND NOT (36 OR 37 OR 38 OR 39)')
#### HLT
process.hltHighLevel = cms.EDFilter("HLTHighLevel",
     TriggerResultsTag = cms.InputTag("TriggerResults","","HLT"),
      HLTPaths = cms.vstring('HLT_PhysicsDeclared'),           # provide list of HLT paths (or patterns) you want
 #    HLTPaths = cms.vstring('HLT_MinBiasBSC'),           # provide list of HLT paths (or patterns) you want
     eventSetupPathsKey = cms.string(''), # not empty => use read paths from AlCaRecoTriggerBitsRcd via this key
     andOr = cms.bool(True),             # how to deal with multiple triggers: True (OR) accept if ANY is true, False (AND) accept if ALL are true
     throw = cms.bool(True)    # throw exception on unknown path names
)
#### remove monster events
process.monster = cms.EDFilter(
    "FilterOutScraping",
    applyfilter = cms.untracked.bool(True),
    debugOn = cms.untracked.bool(True),
    numtrack = cms.untracked.uint32(10),
    thresh = cms.untracked.double(0.2)
    )
####
process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(10)
)

# last re-reco /MinimumBias/BeamCommissioning09-SD_AllMinBias-Dec19thSkim_341_v1/RAW-RECO
# dbs search --query="find run where dataset=/MinimumBias/BeamCommissioning09-SD_AllMinBias-Dec19thSkim_341_v1/RAW-RECO"
# dbs search --query="find file where dataset=/MinimumBias/BeamCommissioning09-SD_AllMinBias-Dec19thSkim_341_v1/RAW-RECO and run=124022"

### For 219, file from RelVal
process.source = cms.Source("PoolSource",
   fileNames = cms.untracked.vstring(
# '/store/relval/CMSSW_3_6_0_pre6/RelValQCD_Pt_3000_3500/GEN-SIM-RECO/START36_V4-v1/0011/FE30B408-D044-DF11-92FC-0026189438C1.root')
'/store/relval/CMSSW_3_5_5/RelValQCD_FlatPt_15_3000/GEN-SIM-RECO/MC_3XY_V25-v1/0007/E0707AC5-0F38-DF11-B1FD-0026189437E8.root')
)
# add after dataset name in crab job
# runselection = XXXXXX, YYYYYYY, .....

# Analyzer module
process.myanalysis = cms.EDFilter(
   "JPTAnalyzer_DataTau",
    HistOutFile      = cms.untracked.string('analysisDataTau.root'),
    calojets         = cms.string('ak5CaloJets'),
    jetsID           = cms.string('ak5JetID'),
    jetExtender      = cms.string('ak5JetExtender')
    )

process.dump = cms.EDFilter("EventContentAnalyzer")

# Path
process.p1 = cms.Path(
   process.hltLevel1GTSeed *
#   process.hltHighLevel *	
   process.monster *
#   process.recoJPTJets *
   process.TCTau *
#   process.tautagging *
#   process.dump *
   process.myanalysis
  )

