## import skeleton process
from PhysicsTools.PatAlgos.patTemplate_cfg import *


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

#produce JPT jets

# reset proper settings
# process.load("RecoJets.JetPlusTracks.JetPlusTrackCorrections_cff")
# process.JetPlusTrackZSPCorJetAntiKt5.LeakageMap = "CondFormats/JetMETObjects/data/CMSSW_362_TrackLeakage.txt"
# process.JetPlusTrackZSPCorJetAntiKt5.ResponseMap = "CondFormats/JetMETObjects/data/CMSSW_362_response.txt"
# process.JetPlusTrackZSPCorJetAntiKt5.EfficiencyMap = "CondFormats/JetMETObjects/data/CMSSW_362_TrackNonEff.txt"
# process.JetPlusTrackZSPCorJetAntiKt5.UseEfficiency = True
# process.JetPlusTrackZSPCorJetAntiKt5.UseZSP = True

from RecoJets.JetPlusTracks.JetPlusTrackCorrections_cff import *
JetPlusTrackZSPCorJetAntiKt5.LeakageMap = "CondFormats/JetMETObjects/data/CMSSW_362_TrackLeakage.txt"
JetPlusTrackZSPCorJetAntiKt5.ResponseMap = "CondFormats/JetMETObjects/data/CMSSW_362_response.txt"
JetPlusTrackZSPCorJetAntiKt5.EfficiencyMap = "CondFormats/JetMETObjects/data/CMSSW_362_TrackNonEff.txt"
JetPlusTrackZSPCorJetAntiKt5.UseEfficiency = True
JetPlusTrackZSPCorJetAntiKt5.UseZSP = True
JetPlusTrackZSPCorJetAntiKt5.tagName = cms.vstring('ZSP_CMSSW390_Akt_05_PU0')

# if one wants another JEC like Fall10 put JecFall10.db file into DB using JEC_cff.py with following line: 
# process.load("RecoJets.JetPlusTracks.JEC_cff")
# both Fall10.db and JEC_cff.py files are under JPTexamples/test should be moved to RecoJets/JetPlusTracks/python
# example how it is working for RECO/AOD analysis is JetShapeJPTAnalysis_mc_s_z2.py

process.load("RecoJets.Configuration.RecoJPTJets_cff")

# JES
# process.load('JetMETCorrections.Configuration.DefaultJEC_cff')
# process.load('JetMETCorrections.Configuration.JetCorrectionServices_cff')
# process.ak5JPTL1Offset.useCondDB = False
# process.ak5JPTL2Relative = process.ak5CaloL2Relative.clone( era='Summer10',algorithm = 'AK5JPT')
# process.ak5JPTL3Absolute    = process.ak5CaloL3Absolute.clone( era='Summer10',algorithm = 'AK5JPT')
# process.ak5JPTResidual = process.ak5CaloResidual.clone( era='Summer10',algorithm = 'AK5JPT')

process.dump = cms.EDAnalyzer("EventContentAnalyzer")

# Add JPT jets

from PhysicsTools.PatAlgos.tools.jetTools import *

process.patJetCorrFactors.levels = ['L1Offset', 'L2Relative', 'L3Absolute', 'L2L3Residual']

addJetCollection( process,
                           cms.InputTag('JetPlusTrackZSPCorJetAntiKt5'),
                           'AK5','JPT',
                           doJTA        = True,
                           doBTagging   = True,
                           jetCorrLabel = ('AK5JPT', ['L1Offset', 'L2Relative', 'L3Absolute', 'L2L3Residual']),
                           doType1MET   = False,
                           doL1Cleaning = False,
                           doL1Counters = False,
                           genJetCollection = cms.InputTag("ak5GenJets"),
                           doJetID      = True,
                           jetIdLabel   = "ak5")
##
## let it run
process.p = cms.Path(
   process.jetPlusTrackZSPCorJetAntiKt5*process.patDefaultSequence
    )

## ------------------------------------------------------
#  In addition you usually want to change the following
#  parameters:
## ------------------------------------------------------
#
#   process.GlobalTag.globaltag =  ...    ##  (according to https://twiki.cern.ch/twiki/bin/view/CMS/SWGuideFrontierConditions)
#                                         ##
process.source.fileNames = [          ##
    '/store/relval/CMSSW_4_1_3/RelValTTbar/GEN-SIM-RECO/START311_V2-v1/0037/648B6AA5-C751-E011-8208-001A928116C6.root'
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