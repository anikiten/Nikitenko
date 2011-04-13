import FWCore.ParameterSet.Config as cms
import os


my_sqlite_file = cms.string(
    "sqlite_file:" +
    os.path.join(os.environ.get("CMSSW_BASE"),
                 "src/RecoJets/JetPlusTracks/python/JecFall10.db")
    )

from CondCore.DBCommon.CondDBSetup_cfi import *

jec = cms.ESSource(
    "PoolDBESSource",
    CondDBSetup,
    connect=my_sqlite_file,
    toGet = cms.VPSet(
    cms.PSet(
    record = cms.string('JetCorrectionsRecord'),
    tag    = cms.string('JetCorrectorParametersCollection_Fall10_AK5PF'),
    label  = cms.untracked.string('AK5PF')
    ),
    cms.PSet(
    record = cms.string('JetCorrectionsRecord'),
    tag    = cms.string('JetCorrectorParametersCollection_Fall10_AK7PF'),
    label  = cms.untracked.string('AK7PF')
    ),
    cms.PSet(
    record = cms.string('JetCorrectionsRecord'),
    tag    = cms.string('JetCorrectorParametersCollection_Fall10_AK5Calo'),
    label  = cms.untracked.string('AK5Calo')
    ),
    cms.PSet(
    record = cms.string('JetCorrectionsRecord'),
    tag    = cms.string('JetCorrectorParametersCollection_Fall10_AK7Calo'),
    label  = cms.untracked.string('AK7Calo')
    ), 
    cms.PSet(
    record = cms.string('JetCorrectionsRecord'),
    tag    = cms.string('JetCorrectorParametersCollection_Fall10_AK5JPT'),
    label  = cms.untracked.string('AK5JPT')
    ) 
    )
    
    #toGet =  cms.VPSet(
    #cms.PSet(record=cms.string("JetCorrectionsRecord"),
    #         tag=cms.string("JetCorrectorParametersCollection_Fall10_V0_AK5Calo"),
    #         label=cms.untracked.string("AK5Calo")),
    #cms.PSet(record=cms.string("JetCorrectionsRecord"),
    #         tag=cms.string("JetCorrectorParametersCollection_Fall10_V0_AK7Calo"),
    #         label=cms.untracked.string("AK7Calo")),
    #cms.PSet(record=cms.string("JetCorrectionsRecord"),
    #         tag=cms.string("JetCorrectorParametersCollection_Fall10_V0_AK5PF"),
    #         label=cms.untracked.string("AK5PF")),
    #cms.PSet(record=cms.string("JetCorrectionsRecord"),
    #         tag=cms.string("JetCorrectorParametersCollection_Fall10_V0_AK7PF"),
    #         label=cms.untracked.string("AK7PF")),
    #cms.PSet(record=cms.string("JetCorrectionsRecord"),
    #         tag=cms.string("JetCorrectorParametersCollection_Fall10_V0_AK5JPT"),
    #         label=cms.untracked.string("AK5JPT")),
    #cms.PSet(record=cms.string("JetCorrectionsRecord"),
    #         tag=cms.string("JetCorrectorParametersCollection_Fall10_V0_AK7JPT"),
    #         label=cms.untracked.string("AK7JPT")),
    #cms.PSet(record=cms.string("JetCorrectionsRecord"),
    #         tag=cms.string("JetCorrectorParametersCollection_Fall10_V0_KT4PF"),
    #         label=cms.untracked.string("KT4PF")),
    #cms.PSet(record=cms.string("JetCorrectionsRecord"),
    #         tag=cms.string("JetCorrectorParametersCollection_Fall10_V0_KT6PF"),
    #         label=cms.untracked.string("KT6PF"))
    #)
    )

es_prefer_jec=cms.ESPrefer("PoolDBESSource","jec")
