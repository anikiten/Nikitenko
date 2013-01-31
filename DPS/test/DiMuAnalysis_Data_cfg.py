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

# 1.    Run2012A-13Jul2012 Re-reco....................GT: FT_53_V6_AN3
# process.GlobalTag.globaltag = cms.string('FT_53_V6_AN3::All') 
#
# 2.    Run2012A-recover-06Aug2012  Re-reco ..........GT: FT_53_V6C_AN3
# process.GlobalTag.globaltag = cms.string('FT_53_V6C_AN3::All') 
#
# 3.    Run2012B-13Jul2012 Re-reco ...................GT: FT_53_V6_AN3
# process.GlobalTag.globaltag = cms.string('FT_53_V6_AN3::All') 
#
# 4.    Run2012C-ReReco 24Aug.........................GT: FT_53_V10_AN3
# process.GlobalTag.globaltag = cms.string('FT_53_V10_AN3::All') 
#
# 5.    Run2012C-PromptReco-v2 ...................... GT: GR_P_V42_AN3 
# process.GlobalTag.globaltag = cms.string('GR_P_V42_AN3::All') 
#
# 6.    Run2012C-EcalRecover_11Dec2012................GT: FT_P_V42C_AN3
# process.GlobalTag.globaltag = cms.string('FT_P_V42C_AN3::All') 
#
# 7.    Run2012D-PromptReco-v1........................GT: GR_P_V42_AN3 
process.GlobalTag.globaltag = cms.string('GR_P_V42_AN3::All') 
#
# ############# electrons #################################################################
# rho value for isolation
#
from RecoJets.JetProducers.kt4PFJets_cfi import *
process.kt6PFJetsForIsolation = kt4PFJets.clone( rParam = 0.6, doRhoFastjet = True )
process.kt6PFJetsForIsolation.Rho_EtaMax = cms.double(2.5)
#
# particle flow isolation
#
from CommonTools.ParticleFlow.Tools.pfIsolation import setupPFElectronIso, setupPFMuonIso
process.eleIsoSequence = setupPFElectronIso(process, 'gsfElectrons')
process.pfiso = cms.Sequence(process.pfParticleSelectionSequence + process.eleIsoSequence)
###########################################################################################


# MVA PU jets ID
process.load("CMGTools.External.pujetidsequence_cff")
from CMGTools.External.pujetidsequence_cff import puJetId
process.recoPuJetId = puJetId.clone(
   jets = cms.InputTag("ak5PFJetsL1L2L3Residual"),
   applyJec = cms.bool(False),
   inputIsCorrected = cms.bool(True)                
)

from CMGTools.External.pujetidsequence_cff import puJetMva
process.recoPuJetMva = puJetMva.clone(
   jets = cms.InputTag("ak5PFJetsL1L2L3Residual"),
   jetids = cms.InputTag("recoPuJetId"),
   applyJec = cms.bool(False),
   inputIsCorrected = cms.bool(True)                
)

################## filters ##########################################################

## The good primary vertex filter
process.primaryVertexFilter = cms.EDFilter(
    "VertexSelector",
    src = cms.InputTag("offlinePrimaryVertices"),
    cut = cms.string("!isFake && ndof > 4 && abs(z) <= 24 && position.Rho <= 2"),
    filter = cms.bool(True)
    ) 

## The beam scraping filter
process.noscraping = cms.EDFilter(
    "FilterOutScraping",
    applyfilter = cms.untracked.bool(True),
    debugOn = cms.untracked.bool(False),
    numtrack = cms.untracked.uint32(10),
    thresh = cms.untracked.double(0.25)
    )

## The iso-based HBHE noise filter
process.load('CommonTools.RecoAlgos.HBHENoiseFilter_cfi')

## The CSC beam halo tight filter 
process.load('RecoMET.METAnalyzers.CSCHaloFilter_cfi')

## The HCAL laser filter 
process.load("RecoMET.METFilters.hcalLaserEventFilter_cfi")
process.MyhcalLaserEventFilter = process.hcalLaserEventFilter.clone()
process.MyhcalLaserEventFilter.taggingMode  = cms.bool(True)

## The ECAL dead cell trigger primitive filter
process.load('RecoMET.METFilters.EcalDeadCellTriggerPrimitiveFilter_cfi')
process.MyEcalDeadCellTriggerPrimitiveFilter = process.EcalDeadCellTriggerPrimitiveFilter.clone()
process.MyEcalDeadCellTriggerPrimitiveFilter.taggingMode  = cms.bool(True)

## The EE bad SuperCrystal filter
process.load('RecoMET.METFilters.eeBadScFilter_cfi')
process.MyeeBadScFilter = process.eeBadScFilter.clone()
process.MyeeBadScFilter.taggingMode  = cms.bool(True)

## The ECAL laser correction filter
process.load('RecoMET.METFilters.ecalLaserCorrFilter_cfi')
process.MyecalLaserCorrFilter = process.ecalLaserCorrFilter.clone()
process.MyecalLaserCorrFilter.taggingMode  = cms.bool(True)

## The Good vertices collection needed by the tracking failure filter
process.goodVertices = cms.EDFilter(
  "VertexSelector",
  filter = cms.bool(False),
  src = cms.InputTag("offlinePrimaryVertices"),
  cut = cms.string("!isFake && ndof > 4 && abs(z) <= 24 && position.rho < 2")
) 

## The tracking failure filter
process.load('RecoMET.METFilters.trackingFailureFilter_cfi')
process.MytrackingFailureFilter = process.trackingFailureFilter.clone()
process.MytrackingFailureFilter.taggingMode  = cms.bool(True)

## filter laser HCAL 2012 events
process.load("EventFilter.HcalRawToDigi.hcallasereventfilter2012_cfi")

## total sequence
process.filtersSeq = cms.Sequence(
   process.primaryVertexFilter *
   process.noscraping *
   process.HBHENoiseFilter *
   process.CSCTightHaloFilter *
   process.MyhcalLaserEventFilter *
   process.MyEcalDeadCellTriggerPrimitiveFilter *
   process.goodVertices * process.MytrackingFailureFilter *
   process.MyeeBadScFilter *
   process.MyecalLaserCorrFilter*
   process.hcallasereventfilter2012	
)

## for usage of JES from JetMET latest development
## see on https://twiki.cern.ch/twiki/bin/view/CMS/JetPlusTracksCorrections
#from CondCore.DBCommon.CondDBSetup_cfi import *
#process.jec = cms.ESSource("PoolDBESSource",CondDBSetup,
#                       connect =
#                       cms.string("sqlite:Fall12_V1_DATA.db"),
#                       toGet =  cms.VPSet(
#                       cms.PSet(record = cms.string("JetCorrectionsRecord"),
#                                tag =
#cms.string("JetCorrectorParametersCollection_Fall12_V1_DATA_AK5Calo"),
#                                label=cms.untracked.string("AK5Calo")),
#                       cms.PSet(record = cms.string("JetCorrectionsRecord"),
#                                tag =
#cms.string("JetCorrectorParametersCollection_Fall12_V1_DATA_AK5PF"),
#                                label=cms.untracked.string("AK5PF")),
#                       cms.PSet(record = cms.string("JetCorrectionsRecord"),
#                                tag =
#cms.string("JetCorrectorParametersCollection_Fall12_V1_DATA_AK5JPT"),
#                                label=cms.untracked.string("AK5JPT"))
#                       )
#                   )
#process.es_prefer_jec = cms.ESPrefer("PoolDBESSource","jec")
#
#process.ak5JPTL1Offset.algorithm = 'AK5JPT'
########################################################################################

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
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
    DataOrMC            = cms.untracked.int32(0),
    Muons               = cms.InputTag("muons"),
    electronsInputTag   = cms.InputTag("gsfElectrons"),
    conversionsInputTag = cms.InputTag("allConversions"),
    rhoIsoInputTag      = cms.InputTag("kt6PFJetsForIsolation", "rho"),
    isoValInputTags     = cms.VInputTag(cms.InputTag('elPFIsoValueCharged03PFIdPFIso'),
                                        cms.InputTag('elPFIsoValueGamma03PFIdPFIso'),
                                        cms.InputTag('elPFIsoValueNeutral03PFIdPFIso')),
    calojets            = cms.InputTag("ak5CaloJets"),
    jetsID              = cms.InputTag("ak5JetID"),
    JPTjets             = cms.InputTag("JetPlusTrackZSPCorJetAntiKt5"),
    JPTjetsL1L2L3       = cms.InputTag("ak5JPTJetsL1L2L3Residual"),
    PFjetsL1L2L3        = cms.InputTag("ak5PFJetsL1L2L3Residual"),
    TriggerResults      = cms.InputTag("TriggerResults","","HLT")	
)

# JPTjetsL2L3 = cms.InputTag("ak5JPTJetsL2L3"),
# PFjetsL2K3 = cms.InputTag("ak5PFJetsL2L3"),
# CaloJetsL2L3 = cms.InputTag("ak5CaloJetsL2L3"),


process.dump = cms.EDAnalyzer("EventContentAnalyzer")

process.p1 = cms.Path(process.filtersSeq*
                      process.producePFMETCorrections*
                      process.ak5PFJetsL1L2L3Residual*
                      process.recoPuJetId*
                      process.recoPuJetMva*
                      process.ak5JTA*
                      process.jetPlusTrackZSPCorJetAntiKt5*
                      process.ak5JPTJetsL1L2L3Residual*
	              process.kt6PFJetsForIsolation* 
	              process.pfiso*
                      process.myjetplustrack)
#                      process.dump)

