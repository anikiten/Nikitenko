## import skeleton process

# process.load('PhysicsTools.PatAlgos.patSequences_cff')

from PhysicsTools.PatAlgos.patTemplate_cfg import *

from PhysicsTools.PatAlgos.tools.coreTools import *
removeMCMatching(process,['All'])

process.load('RecoJets.JetProducers.kt4PFJets_cfi')
process.load('RecoJets.Configuration.RecoPFJets_cff')

process.kt6PFJets = process.kt4PFJets.clone( rParam = 0.6, doRhoFastjet = True )
process.kt6PFJets.Rho_EtaMax = cms.double(2.5)
process.rhoProcess = cms.Sequence( process.kt6PFJets )
process.kt6PFJets.doRhoFastjet = True
process.ak5PFJets.doAreaFastjet = True

# use proper tag. corresponding to CMSSW version !
# process.GlobalTag.globaltag = cms.string('MC_42_V13::All')

process.GlobalTag.globaltag = cms.string('GR_R_42_V19::All')

## ------------------------------------------------------
#  NOTE: you can use a bunch of core tools of PAT to
#  taylor your PAT configuration; for a few examples
#  uncomment the lines below
## ------------------------------------------------------
#from PhysicsTools.PatAlgos.tools.coreTools import *

## remove MC matching from the default sequence
# removeMCMatching(process, ['Muons'])
# runOnData(process)

## remove certain objects from the default sequence
# removeAllPATObjectsBut(process, ['Muons'])
# removeSpecificPATObjects(process, ['Electrons', 'Muons', 'Taus'])

process.out.outputCommands+= ["keep *_selectedPatJets*_*_*"]  ##  (e.g. taken from PhysicsTools/PatAlgos/python/patEventContent_cff.py)

#
# produce JPT jets: uncomment these lines for 4_1_X and 3_9_X
#
# from RecoJets.JetPlusTracks.JetPlusTrackCorrections_cff import *
# JetPlusTrackZSPCorJetAntiKt5.LeakageMap = "CondFormats/JetMETObjects/data/CMSSW_362_TrackLeakage.txt"
# JetPlusTrackZSPCorJetAntiKt5.ResponseMap = "CondFormats/JetMETObjects/data/CMSSW_362_response.txt"
# JetPlusTrackZSPCorJetAntiKt5.EfficiencyMap = "CondFormats/JetMETObjects/data/CMSSW_362_TrackNonEff.txt"
# JetPlusTrackZSPCorJetAntiKt5.UseEfficiency = True
# JetPlusTrackZSPCorJetAntiKt5.UseZSP = True
# JetPlusTrackZSPCorJetAntiKt5.tagName = cms.vstring('ZSP_CMSSW390_Akt_05_PU0')

#
#JES: preliminary Spring11 corrections for CMSSW_4_2_0 to be used with 4_1_X. Uncomment these lines for 4_1_X.
#
#process.load("CondCore.DBCommon.CondDBCommon_cfi")
#process.jec = cms.ESSource("PoolDBESSource",
#      DBParameters = cms.PSet(
#        messageLevel = cms.untracked.int32(0)
#        ),
#      timetype = cms.string('runnumber'),
#      toGet = cms.VPSet(
#      cms.PSet(
#            record = cms.string('JetCorrectionsRecord'),
#            tag    = cms.string('JetCorrectorParametersCollection_Jec11_V1_AK5JPT'),
#            label  = cms.untracked.string('AK5JPT')
#            )
#      ),
#      ## here you add as many jet types as you need (AK5Calo, AK5JPT, AK7PF, AK7Calo, KT4PF, KT4Calo)
#      connect = cms.string('frontier://FrontierPrep/CMS_COND_PHYSICSTOOLS')
#)
# process.es_prefer_jec = cms.ESPrefer('PoolDBESSource','jec')
################################################################################################################

process.load("RecoJets.JetAssociationProducers.ak5JTA_cff")
process.load("RecoJets.Configuration.RecoJPTJets_cff")

process.dump = cms.EDAnalyzer("EventContentAnalyzer")

# Add JPT jets

from PhysicsTools.PatAlgos.tools.jetTools import *

process.patJetCorrFactors.levels = ['L1Offset', 'L2Relative', 'L3Absolute']

# process.patJetCorrFactors.levels = ['L2Relative', 'L3Absolute']

addJetCollection( process,
                           cms.InputTag('JetPlusTrackZSPCorJetAntiKt5'),
                           'AK5','JPT',
                           doJTA        = True,
                           doBTagging   = True,
                           jetCorrLabel = ('AK5JPT', ['L1Offset', 'L2Relative', 'L3Absolute']),
                           doType1MET   = False,
                           doL1Cleaning = False,
                           doL1Counters = False,
                           genJetCollection = cms.InputTag("ak5GenJets"),
                           doJetID      = True,
                           jetIdLabel   = "ak5")
##
process.p = cms.Path(process.rhoProcess
                    +process.kt6PFJets
                    +process.ak5PFJets   
                    +process.ak5JTA
                    +process.jetPlusTrackZSPCorJetAntiKt5
                    +process.patDefaultSequence)

## ------------------------------------------------------
#  In addition you usually want to change the following
#  parameters:
## ------------------------------------------------------
#                                         ##
process.source.fileNames = [          ##
#    '/store/relval/CMSSW_4_1_3/RelValTTbar/GEN-SIM-RECO/START311_V2-v1/0037/648B6AA5-C751-E011-8208-001A928116C6.root'
#    '/store/relval/CMSSW_4_2_0/RelValTTbar/GEN-SIM-RECO/MC_42_V9-v1/0054/3CBCB401-935E-E011-8345-0026189437F8.root'
     '/store/data/Run2011A/Jet/RECO/PromptReco-v4/000/165/121/4C12EC82-7481-E011-8499-0030487C8CB8.root'
   ]                                     ##  (e.g. 'file:AOD.root')
#                                         ##
#   process.maxEvents.input = cms.untracked.int32(2)            ##  (e.g. -1 to run on all events)
#                                         ##
#   process.out.outputCommands = [ ... ]  ##  (e.g. taken from PhysicsTools/PatAlgos/python/patEventContent_cff.py)
#                                         ##
#   process.out.fileName = ...            ##  (e.g. 'myTuple.root')
#                                         ##
#   process.options.wantSummary = True    ##  (to suppress the long output at the end of the job)    
# process.selectedPatElectrons.cut = 'pt > 10. & abs(eta) < 12.'