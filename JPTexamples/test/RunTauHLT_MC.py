# Auto generated configuration file
# using: 
# Revision: 1.172.2.6 
# Source: /cvs_server/repositories/CMSSW/CMSSW/Configuration/PyReleaseValidation/python/ConfigBuilder.py,v 
# with command line options: RelVal --step=HLT --conditions=auto:startup --filein=file:RelVal_HLT_8E29.root --fileout=RelVal_HLT2_8E29.root --number=100 --mc --no_exec --datatier RAW-HLT --eventcontent=FEVTDEBUGHLT --customise=HLTrigger/Configuration/customL1THLT_Options.py --python_filename=RelVal_HLT2_8E29.py --processName=HLT2
import FWCore.ParameterSet.Config as cms

process = cms.Process('HLT2')

# The paths that are running are:
# HLT_SingleLooseIsoTau25_Trk5 (Threshold 25 , Leading Track>5 only)
# HLT_SingleIsoTau20_Trk5 (Threshold 20,Leading Track>5 , Track Iso)
# HLT_SingleIsoTau30_Trk5_NoJEC (Threshold 30 ,Leading Track 5 , Track iso)
#     --This is the 1E31 path but without corrections)
#  MC_31X global tag has correct L1 Menu 
#  to have latest L1 Tau isolation algo need to use  cmssw > 362

# import of standard configurations
process.load('Configuration.StandardSequences.Services_cff')
process.load('SimGeneral.HepPDTESSource.pythiapdt_cfi')
process.load('FWCore.MessageService.MessageLogger_cfi')
process.load('Configuration.StandardSequences.MixingNoPileUp_cff')
process.load('Configuration.StandardSequences.GeometryExtended_cff')
process.load('Configuration.StandardSequences.MagneticField_38T_cff')
process.load('HLTrigger.Configuration.HLT_8E29_cff')
process.load('HLTrigger.Configuration.Tau5E30_MC_cff')
process.load('Configuration.StandardSequences.EndOfProcess_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')
process.load('Configuration.EventContent.EventContent_cff')

process.configurationMetadata = cms.untracked.PSet(
    version = cms.untracked.string('$Revision: 1.1 $'),
    annotation = cms.untracked.string('RelVal nevts:100'),
    name = cms.untracked.string('PyReleaseValidation')
)
process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(100)
)
process.options = cms.untracked.PSet(

)
# Input source
process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
# /Wtaunu/Summer09-MC_31X_V3_7TeV-v1/GEN-SIM-RECO
# /Wtaunu/Summer09-MC_31X_V3_7TeV-v1/GEN-SIM-RAW
                '/store/relval/CMSSW_3_6_0_pre4/RelValZTT/GEN-SIM-DIGI-RAW-HLTDEBUG/START36_V3-v1/0002/E41B7B7E-FC37-DF11-A644-0030487CD7C0.root',
                '/store/relval/CMSSW_3_6_0_pre4/RelValZTT/GEN-SIM-DIGI-RAW-HLTDEBUG/START36_V3-v1/0002/CE827AB6-FB37-DF11-A060-0030487A3232.root',
                '/store/relval/CMSSW_3_6_0_pre4/RelValZTT/GEN-SIM-DIGI-RAW-HLTDEBUG/START36_V3-v1/0002/BE02950D-FC37-DF11-8F15-0030487CD812.root',
                '/store/relval/CMSSW_3_6_0_pre4/RelValZTT/GEN-SIM-DIGI-RAW-HLTDEBUG/START36_V3-v1/0002/BA63E8D1-FA37-DF11-83A7-0030487CAF0E.root',
                '/store/relval/CMSSW_3_6_0_pre4/RelValZTT/GEN-SIM-DIGI-RAW-HLTDEBUG/START36_V3-v1/0002/9E73096C-FB37-DF11-9AEA-00304879FBB2.root',
                '/store/relval/CMSSW_3_6_0_pre4/RelValZTT/GEN-SIM-DIGI-RAW-HLTDEBUG/START36_V3-v1/0002/5EE4E3EF-1638-DF11-87EF-0030487CD7E0.root',
                '/store/relval/CMSSW_3_6_0_pre4/RelValZTT/GEN-SIM-DIGI-RAW-HLTDEBUG/START36_V3-v1/0002/586F1D21-FA37-DF11-A2A5-001617DBD5AC.root',
                '/store/relval/CMSSW_3_6_0_pre4/RelValZTT/GEN-SIM-DIGI-RAW-HLTDEBUG/START36_V3-v1/0002/5021A055-FD37-DF11-9814-0030487C8CB6.root',
                '/store/relval/CMSSW_3_6_0_pre4/RelValZTT/GEN-SIM-DIGI-RAW-HLTDEBUG/START36_V3-v1/0002/3CED1546-FD37-DF11-9051-0030487CD6F2.root',
                '/store/relval/CMSSW_3_6_0_pre4/RelValZTT/GEN-SIM-DIGI-RAW-HLTDEBUG/START36_V3-v1/0002/1E35230D-FF37-DF11-9E2A-0030487A3C9A.root',
                '/store/relval/CMSSW_3_6_0_pre4/RelValZTT/GEN-SIM-DIGI-RAW-HLTDEBUG/START36_V3-v1/0002/0AFCD774-FD37-DF11-B08E-0030487A18F2.root',
                '/store/relval/CMSSW_3_6_0_pre4/RelValZTT/GEN-SIM-DIGI-RAW-HLTDEBUG/START36_V3-v1/0002/007B499F-FB37-DF11-9440-0030487C6062.root'
    )
)

# Output definition
process.output = cms.OutputModule("PoolOutputModule",
    splitLevel = cms.untracked.int32(0),
    outputCommands = process.FEVTDEBUGHLTEventContent.outputCommands,
    fileName = cms.untracked.string('TauHLTPOutput.root'),
    dataset = cms.untracked.PSet(
        dataTier = cms.untracked.string('RAW-HLT'),
        filterName = cms.untracked.string('')
    )
)

# Additional output definition

# Other statements
process.GlobalTag.globaltag = 'START36_V10::All'

# Path and EndPath definitions
process.endjob_step = cms.Path(process.endOfProcess)
process.out_step = cms.EndPath(process.output)

# Schedule definition
process.schedule = cms.Schedule()
process.schedule.extend(process.HLTSchedule)
process.schedule.extend([process.HLTriggerFinalPath])

process.schedule.extend([process.endjob_step,process.out_step])

# Automatic addition of the customisation function
def customise(process):
    if 'hltTrigReport' in process.__dict__:
        process.hltTrigReport.HLTriggerResults = cms.InputTag( 'TriggerResults','',process.name_() )

    if 'hltDQMHLTScalers' in process.__dict__:
        process.hltDQMHLTScalers.triggerResults = cms.InputTag( 'TriggerResults','',process.name_() )

    if 'hltDQML1SeedLogicScalers' in process.__dict__:
        process.hltDQML1SeedLogicScalers.processname = process.name_()

    process.options.wantSummary = cms.untracked.bool(True)
    process.MessageLogger.categories.append('TriggerSummaryProducerAOD')
    process.MessageLogger.categories.append('L1GtTrigReport')
    process.MessageLogger.categories.append('HLTrigReport')

    return(process)


# End of customisation function definition

process = customise(process)



