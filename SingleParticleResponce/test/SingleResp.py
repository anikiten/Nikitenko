# Auto generated configuration file
# using:
# Revision: 1.168
# Source: /cvs_server/repositories/CMSSW/CMSSW/Configuration/PyReleaseValidation/python/ConfigBuilder.py,v
# with command line options: step2 -s RAW2DIGI,RECO --datatier GEN-SIM-RECO --eventcontent RECOSIM --conditions FrontierConditions_GlobalTag,M$
import FWCore.ParameterSet.Config as cms

process = cms.Process('RECO2')

# import of standard configurations
process.load('Configuration.StandardSequences.Services_cff')
process.load('SimGeneral.HepPDTESSource.pythiapdt_cfi')
process.load('FWCore.MessageService.MessageLogger_cfi')
process.load('Configuration.StandardSequences.MixingNoPileUp_cff')
process.load('Configuration.StandardSequences.GeometryExtended_cff')
process.load('Configuration.StandardSequences.MagneticField_38T_cff')
process.load('Configuration/StandardSequences/Digi_cff')
process.load('Configuration/StandardSequences/SimL1Emulator_cff')
process.load('Configuration/StandardSequences/DigiToRaw_cff')
process.load('Configuration.StandardSequences.RawToDigi_cff')
process.load('Configuration.StandardSequences.Reconstruction_cff')
process.load('Configuration.StandardSequences.EndOfProcess_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')
process.load('Configuration.EventContent.EventContent_cff')

process.load("RecoTracker.TrackProducer.TrackRefitter_cfi")
process.TrackRefitter.TrajectoryInEvent = cms.bool(True)


process.load("RecoTracker.FinalTrackSelectors.selectHighPurity_cfi")
process.selectHighPurity.src = cms.InputTag('TrackRefitter')
process.selectHighPurity.copyExtras = True
process.selectHighPurity.copyTrajectories = True
#set this to true to have all tracks (highQuality or not but with quality added). false makes the
#collection contain only highQuality tracks
process.selectHighPurity.keepAllTracks = True


process.GlobalTag.globaltag = cms.string('MC_36Y_V10::All')
process.configurationMetadata = cms.untracked.PSet(
    version = cms.untracked.string('$Revision: 1.168 $'),
    annotation = cms.untracked.string('step2 nevts:1'),
    name = cms.untracked.string('PyReleaseValidation')
)
process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)
process.options = cms.untracked.PSet(

)
# Input source
process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring('/store/relval/CMSSW_3_6_2/RelValProdMinBias/GEN-SIM-RAW/MC_36Y_V10-v1/0002/CC5C0267-DF70-DF11-9780-00261894392F.root')
)

process.myanalysis = cms.EDFilter("SinglePionEfficiencyNew",
    HistOutFile = cms.untracked.string('resp.root'),
    tracks = cms.string('selectHighPurity'), 
    pxltracks = cms.string('pixelTracks'),
    pxlhits = cms.string('siPixelRecHits'),
    calotowers = cms.string('caloTowers'),
    towermaker = cms.string('towerMaker'),
    hbheInput = cms.string('hbhereco'),
    hoInput = cms.string('horeco'),
    hfInput = cms.string('hfreco'),
    ecalRecHitsProducer = cms.string('ecalRecHit'),
    ECALbarrelHitCollection = cms.string('EcalRecHitsEB'),
    ECALendcapHitCollection = cms.string('EcalRecHitsEE'),
    EbSrFlagCollection = cms.InputTag("ecalDigis","ebSrFlags"),
    TrackAssociatorParameters = cms.PSet(
        muonMaxDistanceSigmaX = cms.double(0.0),
        muonMaxDistanceSigmaY = cms.double(0.0),
        CSCSegmentCollectionLabel = cms.InputTag("cscSegments"),
        dRHcal = cms.double(9999.0),
        dREcal = cms.double(9999.0),
        CaloTowerCollectionLabel = cms.InputTag("towerMaker"),
        useEcal = cms.bool(True),
        dREcalPreselection = cms.double(0.05),
        HORecHitCollectionLabel = cms.InputTag("horeco"),
        dRMuon = cms.double(9999.0),
        trajectoryUncertaintyTolerance = cms.double(-1.0),
        propagateAllDirections = cms.bool(True),
        muonMaxDistanceX = cms.double(5.0),
        muonMaxDistanceY = cms.double(5.0),
        useHO = cms.bool(True),
        accountForTrajectoryChangeCalo = cms.bool(False),
        DTRecSegment4DCollectionLabel = cms.InputTag("dt4DSegments"),
        EERecHitCollectionLabel = cms.InputTag("ecalRecHit","EcalRecHitsEE"),
        dRHcalPreselection = cms.double(0.2),
        useMuon = cms.bool(True),
        useCalo = cms.bool(False),
        EBRecHitCollectionLabel = cms.InputTag("ecalRecHit","EcalRecHitsEB"),
        dRMuonPreselection = cms.double(0.2),
        usePreshower = cms.bool(False),
        dRPreshowerPreselection = cms.double(0.2),
        truthMatch = cms.bool(False),
        HBHERecHitCollectionLabel = cms.InputTag("hbhereco"),
        useHcal = cms.bool(True)
    )
)
# Path and EndPath definitions

process.digitisation_step = cms.Path(process.pdigi)
process.L1simulation_step = cms.Path(process.SimL1Emulator)
process.digi2raw_step = cms.Path(process.DigiToRaw)
process.raw2digi_step = cms.Path(process.RawToDigi)
process.reconstruction_step = cms.Path(process.reconstruction_HcalNZS)
process.endjob_step = cms.Path(process.endOfProcess)
process.myan = cms.Path(process.TrackRefitter*process.selectHighPurity*process.myanalysis)

# Schedule definition
process.schedule = cms.Schedule(process.digitisation_step,process.L1simulation_step,process.digi2raw_step,process.raw2digi_step,process.reconstruction_step,process.myan,process.endjob_step)

# Automatic addition of the customisation function
# Fragment to switch off HCAL zero suppression as an option
# by cmsDriver customisation

# to generate Unsuppressed digis, one has to set the following parameter:
# process.simHcalDigis.useConfigZSvalues = 1
# to generate suppressed digis, useConfigZSvalues should be set to 0

def customise(process):

#    process.hcalDigiSequence.replace(process.simHcalDigis,cms.SequencePlaceholder("simHcalDigis"))
#    process.load("SimCalorimetry.HcalZeroSuppressionProducers.hcalDigisNoSuppression_cfi")

    process.simHcalDigis.HBlevel = -999
    process.simHcalDigis.HElevel = -999
    process.simHcalDigis.HOlevel = -999
    process.simHcalDigis.HFlevel = -999
    process.simHcalDigis.useConfigZSvalues = 1

    return(process)


# End of customisation function definition

process = customise(process)

