## import skeleton process
from PhysicsTools.PatAlgos.patTemplate_cfg import *


# comment this line for CMSSW_4_1_4
process.GlobalTag.globaltag = cms.string('MC_42_V9::All')

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

# produce JPT jets: uncomment these lines for 4_1_X
# from RecoJets.JetPlusTracks.JetPlusTrackCorrections_cff import *
# JetPlusTrackZSPCorJetAntiKt5.LeakageMap = "CondFormats/JetMETObjects/data/CMSSW_362_TrackLeakage.txt"
# JetPlusTrackZSPCorJetAntiKt5.ResponseMap = "CondFormats/JetMETObjects/data/CMSSW_362_response.txt"
# JetPlusTrackZSPCorJetAntiKt5.EfficiencyMap = "CondFormats/JetMETObjects/data/CMSSW_362_TrackNonEff.txt"
# JetPlusTrackZSPCorJetAntiKt5.UseEfficiency = True
# JetPlusTrackZSPCorJetAntiKt5.UseZSP = True
# JetPlusTrackZSPCorJetAntiKt5.tagName = cms.vstring('ZSP_CMSSW390_Akt_05_PU0')

# if one wants another JEC like Fall10 put JecFall10.db file into DB using JEC_cff.py with following line: 
# process.load("RecoJets.JetPlusTracks.JEC_cff")
# both Fall10.db and JEC_cff.py files are under JPTexamples/test should be moved to RecoJets/JetPlusTracks/python
# example how it is working for RECO/AOD analysis is JetShapeJPTAnalysis_mc_s_z2.py

#JES: comment these lines in case of CMSSW_4_1_X: preliminary Spring11 corrections for CMSSW_4_2_0
process.load("CondCore.DBCommon.CondDBCommon_cfi")
process.jec = cms.ESSource("PoolDBESSource",
      DBParameters = cms.PSet(
        messageLevel = cms.untracked.int32(0)
        ),
      timetype = cms.string('runnumber'),
      toGet = cms.VPSet(
      cms.PSet(
            record = cms.string('JetCorrectionsRecord'),
            tag    = cms.string('JetCorrectorParametersCollection_Jec11_V1_AK5JPT'),
            label  = cms.untracked.string('AK5JPT')
            )
      ),
      ## here you add as many jet types as you need (AK5Calo, AK5JPT, AK7PF, AK7Calo, KT4PF, KT4Calo)
      connect = cms.string('frontier://FrontierPrep/CMS_COND_PHYSICSTOOLS')
)
process.es_prefer_jec = cms.ESPrefer('PoolDBESSource','jec')
################################################################################################################

# uncomment for CMSSW_4_1_4
# process.load("RecoJets.JetAssociationProducers.ak5JTA_cff")
# process.load("RecoJets.Configuration.RecoJPTJets_cff")

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
## uncomment for CMSSW_4_1_4
# process.p = cms.Path(
#   process.ak5JTA*process.jetPlusTrackZSPCorJetAntiKt5*process.patDefaultSequence
#    )

process.p = cms.Path(
   process.patDefaultSequence
   )

## ------------------------------------------------------
#  In addition you usually want to change the following
#  parameters:
## ------------------------------------------------------
#                                         ##
process.source.fileNames = [          ##
#    '/store/relval/CMSSW_4_1_3/RelValTTbar/GEN-SIM-RECO/START311_V2-v1/0037/648B6AA5-C751-E011-8208-001A928116C6.root'
    '/store/relval/CMSSW_4_2_0/RelValTTbar/GEN-SIM-RECO/MC_42_V9-v1/0054/3CBCB401-935E-E011-8345-0026189437F8.root'
   ]                                     ##  (e.g. 'file:AOD.root')
#                                         ##
#   process.maxEvents.input = cms.untracked.int32(2)            ##  (e.g. -1 to run on all events)
#                                         ##
#   process.out.outputCommands = [ ... ]  ##  (e.g. taken from PhysicsTools/PatAlgos/python/patEventContent_cff.py)
#                                         ##
#   process.out.fileName = ...            ##  (e.g. 'myTuple.root')
#                                         ##
#   process.options.wantSummary = True    ##  (to suppress the long output at the end of the job)    
process.selectedPatElectrons.cut = 'pt > 10. & abs(eta) < 12.'