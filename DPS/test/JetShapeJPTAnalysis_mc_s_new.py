import FWCore.ParameterSet.Config as cms

process = cms.Process("RECO4")

process.load('Configuration/StandardSequences/Services_cff')
process.load('FWCore/MessageService/MessageLogger_cfi')
process.load('Configuration/StandardSequences/GeometryExtended_cff')
process.load('Configuration/StandardSequences/MagneticField_AutoFromDBCurrent_cff')
process.load('Configuration/StandardSequences/RawToDigi_cff')
process.load('Configuration/StandardSequences/L1Reco_cff')
process.load('Configuration/StandardSequences/Reconstruction_cff')
process.load('DQMOffline/Configuration/DQMOffline_cff')
process.load('Configuration/StandardSequences/EndOfProcess_cff')
process.load('Configuration/StandardSequences/FrontierConditions_GlobalTag_cff')
process.load('Configuration/EventContent/EventContent_cff')
process.load('JetMETCorrections.Configuration.DefaultJEC_cff')
process.load('RecoJets.Configuration.RecoJPTJets_cff')
process.load('RecoJets.JetAssociationProducers.ak5JTA_cff')
process.load("RecoJets.Configuration.GenJetParticles_cff")
process.load("RecoJets.Configuration.RecoGenJets_cff")


process.GlobalTag.globaltag = cms.string('MC_44_V10::All')

#process.load("CondCore.DBCommon.CondDBCommon_cfi")
#process.load("CondCore.DBCommon.CondDBSetup_cfi")

from CondCore.DBCommon.CondDBSetup_cfi import *

process.jec = cms.ESSource("PoolDBESSource",CondDBSetup,
                           connect =
   #         cms.string("sqlite:Jec11_V12_20111220.db"),
  cms.string("sqlite:Jec11_V13.db"),
#cms.string("frontier://FrontierPrep/CMS_COND_PHYSICSTOOLS"),
                   toGet =  cms.VPSet(
                       cms.PSet(record = cms.string("JetCorrectionsRecord"),
                                tag =
cms.string("JetCorrectorParametersCollection_Jec11_V13_AK5Calo"),
                                label=cms.untracked.string("AK5Calo")),
                       cms.PSet(record = cms.string("JetCorrectionsRecord"),
                                tag =
cms.string("JetCorrectorParametersCollection_Jec11_V13_AK5PF"),
                                label=cms.untracked.string("AK5PF")),
                       cms.PSet(record = cms.string("JetCorrectionsRecord"),
                                tag =
cms.string("JetCorrectorParametersCollection_Jec11_V13_AK5PFchs"),
                                label=cms.untracked.string("AK5PFchs")),
                       cms.PSet(record = cms.string("JetCorrectionsRecord"),
                                tag =
cms.string("JetCorrectorParametersCollection_Jec11_V13_AK5JPT"),
                                label=cms.untracked.string("AK5JPT"))
#                       cms.PSet(record = cms.string("JetCorrectionsRecord"),
#                                tag =
#cms.string("JetCorrectorParametersCollection_Jec11_V3_KT4Calo"),
##                                label=cms.untracked.string("KT4Calo")),
#                       cms.PSet(record = cms.string("JetCorrectionsRecord"),
#                                tag =
#cms.string("JetCorrectorParametersCollection_Jec11_V3_AK7Calo"),
#                                label=cms.untracked.string("AK7Calo")),
                       )

                   )
process.es_prefer_jec = cms.ESPrefer("PoolDBESSource","jec")

process.ak5JPTL1Offset.algorithm = 'AK5JPT'

process.ak5JetTracksAssociatorAtVertex.useAssigned = cms.bool(True)
process.ak5JetTracksAssociatorAtVertex.pvSrc = cms.InputTag("offlinePrimaryVertices")

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(100)
)

#################################################################  

### For 219, file from RelVal
process.source = cms.Source("PoolSource",
   fileNames = cms.untracked.vstring(
  '/store/mc/Fall11/QCD_Pt-15to3000_TuneZ2_Flat_7TeV_pythia6/AODSIM/RecoTest_PU_S5_START44_V4-v1/0000/F474926B-AACF-E011-B064-0018F3D0960C.root'
)
)

#################################################################  
#At least one P.V. which is not fake and has z distance to interaction point with
#|z|<= 24 cm and impact parameter z has been reconstructed 
#NDOF > 4 .
#process.primaryVertexFilter = cms.EDFilter("VertexSelector",
#   src    = cms.InputTag("offlinePrimaryVertices"),
#   cut    = cms.string("!isFake && ndof > 4 && abs(z) <= 24"), 
#   filter = cms.bool(True),   
#)
########NEW#####################
#process.countVertices = cms.EDFilter(
#  "VertexCountFilter",
#  src = cms.InputTag("offlinePrimaryVertices"),
#  minNumber = cms.uint32(1),
#  maxNumber = cms.uint32(100)
#)
#
#################################################################  
process.primaryVertexFilter = cms.EDFilter("GoodVertexFilter",
                                                      vertexCollection = cms.InputTag('offlinePrimaryVertices'),
                                                      minimumNDOF = cms.uint32(4) ,
 						      maxAbsZ = cms.double(24),	
 						      maxd0 = cms.double(2)	
                                                      )

#################################################################  Zmass =1 for data and DYmc background samples;
#################################################################   but for Signal Zmass =0;
process.myjetplustrack = cms.EDAnalyzer("JetShapeJPTAnalysis_s",
                                        HistOutFile = cms.untracked.string('7_TeV_doublemuons_441.root'),
                                        Verbosity = cms.int32(1),
                                        Muons = cms.InputTag("muons"),
                                        Zmass = cms.int32(1),
                                        JetGen = cms.InputTag("ak5GenJets"),
                                        JetCor = cms.InputTag("ak5JPTJetsL1L2L3Residual"),
#                                        JetCor = cms.InputTag("JetPlusTrackZSPCorJetAntiKt5"),
                                        srccalo = cms.InputTag("ak5CaloJets"),                                  
                                        Data = cms.int32(0),
                                        jetsID = cms.string('ak5JetID'),
                                        ak5JetTracksCalo = cms.InputTag("ak5JetTracksAssociatorAtCaloFace")
)
#    triglabel=cms.untracked.InputTag('TriggerResults','','RECO'),
#
#    triglabel=cms.untracked.InputTag('TriggerResults','','HLT'),
#    trignames=cms.untracked.vstring(
#                                     'HLT_MinBiasBSC',
#                                      'HLT_Jet6U',
#                                      'HLT_Jet15U',
#                                      'HLT_Jet30U',
#                                      'HLT_Jet50U',
#                                      'HLT_Jet70U',
#                                      'HLT_Jet100U',
#                                      'HLT_Jet140U'
#)
#################################################################  

process.p1 =cms.Path(process.primaryVertexFilter*process.ak5JTA*process.recoJPTJets*process.ak5JPTJetsL1L2L3Residual*process.myjetplustrack) 

#################################################################  
