import FWCore.ParameterSet.Config as cms

process = cms.Process("RECO4")

process.load('Configuration/StandardSequences/Services_cff')
process.load('FWCore/MessageService/MessageLogger_cfi')
process.load('Configuration/StandardSequences/GeometryExtended_cff')
process.load('Configuration/StandardSequences/MagneticField_AutoFromDBCurrent_cff')
process.load('Configuration/StandardSequences/RawToDigi_Data_cff')
process.load('Configuration/StandardSequences/L1Reco_cff')
process.load('Configuration/StandardSequences/Reconstruction_cff')
process.load('DQMOffline/Configuration/DQMOffline_cff')
process.load('Configuration/StandardSequences/EndOfProcess_cff')
process.load('Configuration/StandardSequences/FrontierConditions_GlobalTag_cff')
process.load('Configuration/EventContent/EventContent_cff')

process.GlobalTag.globaltag = cms.string('START38_V14::All')

#### Choose techical bits 40 or 41 and coincidence with BPTX (0)
process.load('L1TriggerConfig.L1GtConfigProducers.L1GtTriggerMaskTechTrigConfig_cff')
process.load('HLTrigger/HLTfilters/hltLevel1GTSeed_cfi')
process.hltLevel1GTSeed.L1TechTriggerSeeding = cms.bool(True)
process.hltLevel1GTSeed.L1SeedsLogicalExpression = cms.string('0')
####
process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(10)
)
### For 219, file from RelVal
process.source = cms.Source("PoolSource",
   fileNames = cms.untracked.vstring(
###'/store/relval/CMSSW_3_8_6/RelValQCD_Pt_80_120/GEN-SIM-RECO/MC_38Y_V13-v1/0066/10290BA3-C7E7-DF11-8888-0018F3D096C8.root',
###'/store/relval/CMSSW_3_8_7/RelValQCD_Pt_80_120/GEN-SIM-RECO/MC_38Y_V13-v1/0016/66DDC707-82FC-DF11-AE89-002618943916.root'
###'/store/relval/CMSSW_3_8_7/RelValQCD_FlatPt_15_3000/GEN-SIM-RECO/MC_38Y_V13-v1/0017/D6537BBF-99FC-DF11-B625-001A92810ADE.root'
'/store/mc/Fall10/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6/GEN-SIM-RECO/START38_V12-v1/0000/547B9F31-B2CB-DF11-AEB3-00215E21DA2C.root'
)
)
#process.monster = cms.EDFilter("FilterOutScraping",
#                                applyfilter = cms.untracked.bool(True),
#                                debugOn = cms.untracked.bool(True),
#                                numtrack = cms.untracked.uint32(10),
#                                thresh = cms.untracked.double(0.25)
#                                )


process.primaryVertexFilter = cms.EDFilter("GoodVertexFilter",
                                                      vertexCollection = cms.InputTag('offlinePrimaryVertices'),
                                                      minimumNDOF = cms.uint32(4) ,
 						      maxAbsZ = cms.double(24),	
 						      maxd0 = cms.double(2)	
                                                      )



process.load("RecoJets.Configuration.RecoJPTJets_cff")
process.load('JetMETCorrections.Configuration.DefaultJEC_cff')
process.load("RecoJets.Configuration.GenJetParticles_cff")
process.load("RecoJets.Configuration.RecoGenJets_cff")
process.load('JetMETCorrections.Configuration.JetCorrectionServices_cff')
###process.ak5JPTL1L2L3.useCondDB = False
#!
#! JEC: FALL10 FROM SQLITE FILE (PROVIDED BY KOSTAS)
#! 
process.load("RecoJets.JetPlusTracks.JEC_cff")

#process.myjetplustrack = cms.EDFilter("JetShapeJPTAnalysis_s",
process.myjetplustrack = cms.EDAnalyzer("JetShapeJPTAnalysis_s",
    HistOutFile = cms.untracked.string('7tev.root'),
    JetGen = cms.InputTag("ak5GenJets"),
#    JetCor = cms.InputTag("ak5JPTJetsL1L2L3Residual"),
#    JetCor = cms.InputTag("JetPlusTrackZSPCorJetAntiKt5"),
    JetCor = cms.InputTag("ak5JPTJetsL1L2L3"),
    Data = cms.int32(0),
    triglabel=cms.untracked.InputTag('TriggerResults','','RECO'),
    trignames=cms.untracked.vstring(
                                     'HLT_MinBiasBSC',
                                      'HLT_Jet6U',
                                      'HLT_Jet15U',
                                      'HLT_Jet30U',
                                      'HLT_Jet50U',
				      'HLT_Jet70U',
				      'HLT_Jet100U',
				      'HLT_Jet140U'
                                   ),
    jetsID = cms.string('ak5JetID')
)

####process.p1 = cms.Path(process.hltLevel1GTSeed*process.myjetplustrack)
#process.p1 = cms.Path(process.hltLevel1GTSeed*process.primaryVertexFilter*process.recoJPTJets*process.ak5JPTJetsL1L2L3Residual*process.myjetplustrack)
process.p1 = cms.Path(process.primaryVertexFilter*process.recoJPTJets*process.ak5JPTJetsL1L2L3*process.myjetplustrack)
#process.p1 = cms.Path(process.primaryVertexFilter*process.recoJPTJets*process.myjetplustrack)
####process.p1 = cms.Path(process.recoJPTJets*process.ak5JPTJetsL1L2L3*process.myjetplustrack)
