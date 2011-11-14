# Auto generated configuration file
# using: 
# Revision: 1.303.2.7 
# Source: /cvs_server/repositories/CMSSW/CMSSW/Configuration/PyReleaseValidation/python/ConfigBuilder.py,v 
# with command line options: QCD_Pt_80_120_7TeV.cfi -s GEN,SIM,DIGI,L1,DIGI2RAW,HLT:GRun,RAW2DIGI,L1Reco -n 10 --geometry DB --conditions auto:mc --relval 9000,50 --datatier GEN-SIM-DIGI-RAW-HLTDEBUG --eventcontent FEVTDEBUGHLT --no_exec --python_filename RelValQCD_Pt_80_120_MC.py
import FWCore.ParameterSet.Config as cms

process = cms.Process('HLT')

# import of standard configurations
process.load('Configuration.StandardSequences.Services_cff')
process.load('SimGeneral.HepPDTESSource.pythiapdt_cfi')
process.load('FWCore.MessageService.MessageLogger_cfi')
process.load('Configuration.EventContent.EventContent_cff')
process.load('SimGeneral.MixingModule.mixNoPU_cfi')
process.load('Configuration.StandardSequences.GeometryDB_cff')
process.load('Configuration.StandardSequences.MagneticField_38T_cff')
process.load('Configuration.StandardSequences.Generator_cff')
process.load('IOMC.EventVertexGenerators.VtxSmearedRealistic7TeV2011Collision_cfi')
process.load('GeneratorInterface.Core.genFilterSummary_cff')
process.load('Configuration.StandardSequences.SimIdeal_cff')
process.load('Configuration.StandardSequences.Digi_cff')
process.load('Configuration.StandardSequences.SimL1Emulator_cff')
process.load('Configuration.StandardSequences.DigiToRaw_cff')
process.load('HLTrigger.Configuration.HLT_GRun_cff')
process.load('Configuration.StandardSequences.RawToDigi_cff')
process.load('Configuration.StandardSequences.L1Reco_cff')
process.load('Configuration.StandardSequences.EndOfProcess_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')

from Configuration.Generator.PythiaUEZ2Settings_cfi import *
from GeneratorInterface.ExternalDecays.TauolaSettings_cff import *

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(100000)
)

# Input source
process.source = cms.Source("EmptySource")

process.options = cms.untracked.PSet(

)

# Production Info
process.configurationMetadata = cms.untracked.PSet(
    version = cms.untracked.string('$Revision: 1.303.2.7 $'),
    annotation = cms.untracked.string('QCD_Pt_80_120_7TeV.cfi nevts:10'),
    name = cms.untracked.string('PyReleaseValidation')
)

# Output definition

process.FEVTDEBUGHLToutput = cms.OutputModule("PoolOutputModule",
    splitLevel = cms.untracked.int32(0),
    eventAutoFlushCompressedSize = cms.untracked.int32(5242880),
    outputCommands = process.FEVTDEBUGHLTEventContent.outputCommands,
    fileName = cms.untracked.string('QCD_Pt_80_120_7TeV_cfi_GEN_SIM_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco.root'),
    dataset = cms.untracked.PSet(
        filterName = cms.untracked.string(''),
        dataTier = cms.untracked.string('GEN-SIM-DIGI-RAW-HLTDEBUG')
    ),
    SelectEvents = cms.untracked.PSet(
        SelectEvents = cms.vstring('generation_step')
    )
)

# Additional output definition

# Other statements
process.GlobalTag.globaltag = 'MC_42_V12::All'

#process.generator = cms.EDFilter("Pythia6GeneratorFilter",
#    pythiaPylistVerbosity = cms.untracked.int32(0),
#    filterEfficiency = cms.untracked.double(1.0),
#    pythiaHepMCVerbosity = cms.untracked.bool(False),
#    comEnergy = cms.double(7000.0),
#    maxEventsToPrint = cms.untracked.int32(0),
#    PythiaParameters = cms.PSet(
#        pythiaUESettings = cms.vstring('MSTJ(11)=3     ! Choice of the fragmentation function', 
#            'MSTJ(22)=2     ! Decay those unstable particles', 
#            'PARJ(71)=10 .  ! for which ctau  10 mm', 
#            'MSTP(2)=1      ! which order running alphaS', 
#            'MSTP(33)=0     ! no K factors in hard cross sections', 
#            'MSTP(51)=10042 ! structure function chosen (external PDF CTEQ6L1)', 
#            'MSTP(52)=2     ! work with LHAPDF', 
#            'MSTP(81)=1     ! multiple parton interactions 1 is Pythia default', 
#            'MSTP(82)=4     ! Defines the multi-parton model', 
#            'MSTU(21)=1     ! Check on possible errors during program execution', 
#            'PARP(82)=1.8387   ! pt cutoff for multiparton interactions', 
#            'PARP(89)=1960. ! sqrts for which PARP82 is set', 
#            'PARP(83)=0.5   ! Multiple interactions: matter distrbn parameter', 
#            'PARP(84)=0.4   ! Multiple interactions: matter distribution parameter', 
#            'PARP(90)=0.16  ! Multiple interactions: rescaling power', 
#            'PARP(67)=2.5    ! amount of initial-state radiation', 
#            'PARP(85)=1.0  ! gluon prod. mechanism in MI', 
#            'PARP(86)=1.0  ! gluon prod. mechanism in MI', 
#            'PARP(62)=1.25   ! ', 
#            'PARP(64)=0.2    ! ', 
#            'MSTP(91)=1      !', 
#            'PARP(91)=2.1   ! kt distribution', 
#            'PARP(93)=15.0  ! '),
#        processParameters = cms.vstring('MSEL=1               ! QCD hight pT processes', 
#            'CKIN(3)=80.          ! minimum pt hat for hard interactions', 
#            'CKIN(4)=120.         ! maximum pt hat for hard interactions'),
#        parameterSets = cms.vstring('pythiaUESettings', 
#            'processParameters')
#    )
#)
# parton jet
process.load("RecoJets.Configuration.GenJetParticles_cff")
process.genParticlesForPartonJets = process.genParticlesForJets.clone()
# process.genParticlesForPartonJets.ignoreParticleIDs = cms.vuint32()
process.genParticlesForPartonJets.partonicFinalState = True
process.genParticlesForPartonJets.excludeFromResonancePids = cms.vuint32(11, 12, 13, 14, 15, 16)

process.load("RecoJets.JetProducers.ak5GenJets_cfi")
process.ak5PartonJets  =  process.ak5GenJets.clone()
process.ak5PartonJets.src = cms.InputTag("genParticlesForPartonJets")

process.bbhanalysis = cms.EDAnalyzer("bbH",
    HistOutFile = cms.untracked.string('bbH.root'),
    parton_jets = cms.InputTag("ak5PartonJets")
)

process.generator = cms.EDFilter("Pythia6GeneratorFilter",
    pythiaHepMCVerbosity = cms.untracked.bool(False),
    maxEventsToPrint = cms.untracked.int32(0),
    pythiaPylistVerbosity = cms.untracked.int32(1),
    filterEfficiency = cms.untracked.double(1.0),
    comEnergy = cms.double(7000.0),
    crossSection = cms.untracked.double(1.1),
    ExternalDecays = cms.PSet(
        Tauola = cms.untracked.PSet(
            TauolaPolar, # tau polarisation switch on
            TauolaDefaultInputCards #set default TAUOLA input card
        ),
        parameterSets = cms.vstring('Tauola')
    ),
    UseExternalGenerators = cms.untracked.bool(True),
    PythiaParameters = cms.PSet(
        pythiaUESettingsBlock,
        processParameters = cms.vstring('MSEL=0         ! User defined processes',
            'MSUB(186)= 1   ! gg->QQbarH (MSSM)', 
            'KFPR(186,2)= 5 ! Q = b Registered by Alexandre.Nikitenko@cern.ch', 
            # MSSM settings
            'IMSS(1)= 1     ! MSSM with parameters',
            'RMSS(5)= 30.   ! tan beta', 
            'RMSS(19)= 140. ! m_A', 
            'RMSS(1)= 100.  ! M1',   
            'RMSS(2)= 200.  ! M2',   
            'RMSS(3)= 800.  ! Mg',   
            'RMSS(4)= 200.  ! mu',   
            'RMSS(6)= 1000.  ! MS',
            'RMSS(7)= 1000.  ! MS',
            'RMSS(8)= 1000.  ! MS',
            'RMSS(9)= 1000.  ! MS',
            'RMSS(10)= 1000.  ! MS',
            'RMSS(11)= 1000.  ! MS',
            'RMSS(12)= 1000.  ! MS',
            'RMSS(13)= 1000.  ! MS',
            'RMSS(14)= 1000.  ! MS',
            'RMSS(15)= 2000.  ! Ab',
            'RMSS(16)= 2000.  ! At',
            'RMSS(17)= 2000.  ! Atau',
            # Switch off / on desirable channels for A
            'MDME(420,1)=0  ! Higgs(H) decay into d              dbar', 
            'MDME(421,1)=0  ! Higgs(H) decay into u              ubar', 
            'MDME(422,1)=0  ! Higgs(H) decay into s              sbar', 
            'MDME(423,1)=0  ! Higgs(H) decay into c              cbar', 
            'MDME(424,1)=0  ! Higgs(H) decay into b              bbar', 
            'MDME(425,1)=0  ! Higgs(H) decay into t              tbar', 
            'MDME(426,1)=0  ! Higgs(H) decay into b              bbar', 
            'MDME(427,1)=0  ! Higgs(H) decay into t              tbar', 
            'MDME(428,1)=0  ! Higgs(H) decay into e-             e+', 
            'MDME(429,1)=0  ! Higgs(H) decay into mu-            mu+', 
            'MDME(430,1)=1  ! Higgs(H) decay into tau-           tau+', 
            'MDME(431,1)=0  ! Higgs(H) decay into tau-           tau+', 
            'MDME(432,1)=0  ! Higgs(H) decay into g              g', 
            'MDME(433,1)=0  ! Higgs(H) decay into gamma          gamma', 
            'MDME(434,1)=0  ! Higgs(H) decay into gamma          Z0', 
            'MDME(435,1)=0  ! Higgs(H) decay into Z0             Z0', 
            'MDME(436,1)=0  ! Higgs(H) decay into W+             W-', 
            'MDME(437,1)=0  ! Higgs(H) decay into Z0             h0', 
            'MDME(438,1)=0  ! Higgs(H) decay into h0             h0', 
            'MDME(439,1)=0  ! Higgs(H) decay into W+             H-', 
            'MDME(440,1)=0  ! Higgs(H) decay into H+             W-', 
            'MDME(441,1)=0  ! Higgs(H) decay into Z0             A0', 
            'MDME(442,1)=0  ! Higgs(H) decay into h0             A0', 
            'MDME(443,1)=0  ! Higgs(H) decay into A0             A0', 
            'MDME(444,1)=0  ! Higgs(H) decay into ~chi_10        ~chi_10', 
            'MDME(445,1)=0  ! Higgs(H) decay into ~chi_20        ~chi_10', 
            'MDME(446,1)=0  ! Higgs(H) decay into ~chi_20        ~chi_20', 
            'MDME(447,1)=0  ! Higgs(H) decay into ~chi_30        ~chi_10', 
            'MDME(448,1)=0  ! Higgs(H) decay into ~chi_30        ~chi_20', 
            'MDME(449,1)=0  ! Higgs(H) decay into ~chi_30        ~chi_30', 
            'MDME(450,1)=0  ! Higgs(H) decay into ~chi_40        ~chi_10', 
            'MDME(451,1)=0  ! Higgs(H) decay into ~chi_40        ~chi_20', 
            'MDME(452,1)=0  ! Higgs(H) decay into ~chi_40        ~chi_30', 
            'MDME(453,1)=0  ! Higgs(H) decay into ~chi_40        ~chi_40', 
            'MDME(454,1)=0  ! Higgs(H) decay into ~chi_1+        ~chi_1-', 
            'MDME(455,1)=0  ! Higgs(H) decay into ~chi_1+        ~chi_2-', 
            'MDME(456,1)=0  ! Higgs(H) decay into ~chi_2+        ~chi_1-', 
            'MDME(457,1)=0  ! Higgs(H) decay into ~chi_2+        ~chi_2-', 
            'MDME(458,1)=0  ! Higgs(H) decay into ~d_L           ~d_Lbar', 
            'MDME(459,1)=0  ! Higgs(H) decay into ~d_R           ~d_Rbar', 
            'MDME(460,1)=0  ! Higgs(H) decay into ~d_L           ~d_Rbar', 
            'MDME(461,1)=0  ! Higgs(H) decay into ~d_Lbar        ~d_R', 
            'MDME(462,1)=0  ! Higgs(H) decay into ~u_L           ~u_Lbar', 
            'MDME(463,1)=0  ! Higgs(H) decay into ~u_R           ~u_Rbar', 
            'MDME(464,1)=0  ! Higgs(H) decay into ~u_L           ~u_Rbar', 
            'MDME(465,1)=0  ! Higgs(H) decay into ~u_Lbar        ~u_R', 
            'MDME(466,1)=0  ! Higgs(H) decay into ~s_L           ~s_Lbar', 
            'MDME(467,1)=0  ! Higgs(H) decay into ~s_R           ~s_Rbar', 
            'MDME(468,1)=0  ! Higgs(H) decay into ~s_L           ~s_Rbar', 
            'MDME(469,1)=0  ! Higgs(H) decay into ~s_Lbar        ~s_R', 
            'MDME(470,1)=0  ! Higgs(H) decay into ~c_L           ~c_Lbar', 
            'MDME(471,1)=0  ! Higgs(H) decay into ~c_R           ~c_Rbar', 
            'MDME(472,1)=0  ! Higgs(H) decay into ~c_L           ~c_Rbar', 
            'MDME(473,1)=0  ! Higgs(H) decay into ~c_Lbar        ~c_R', 
            'MDME(474,1)=0  ! Higgs(H) decay into ~b_1           ~b_1bar', 
            'MDME(475,1)=0  ! Higgs(H) decay into ~b_2           ~b_2bar', 
            'MDME(476,1)=0  ! Higgs(H) decay into ~b_1           ~b_2bar', 
            'MDME(477,1)=0  ! Higgs(H) decay into ~b_1bar        ~b_2', 
            'MDME(478,1)=0  ! Higgs(H) decay into ~t_1           ~t_1bar', 
            'MDME(479,1)=0  ! Higgs(H) decay into ~t_2           ~t_2bar', 
            'MDME(480,1)=0  ! Higgs(H) decay into ~t_1           ~t_2bar', 
            'MDME(481,1)=0  ! Higgs(H) decay into ~t_1bar        ~t_2', 
            'MDME(482,1)=0  ! Higgs(H) decay into ~e_L-          ~e_L+', 
            'MDME(483,1)=0  ! Higgs(H) decay into ~e_R-          ~e_R+', 
            'MDME(484,1)=0  ! Higgs(H) decay into ~e_L-          ~e_R+', 
            'MDME(485,1)=0  ! Higgs(H) decay into ~e_L+          ~e_R-', 
            'MDME(486,1)=0  ! Higgs(H) decay into ~nu_eL         ~nu_eLbar', 
            'MDME(487,1)=0  ! Higgs(H) decay into ~nu_eR         ~nu_eRbar', 
            'MDME(488,1)=0  ! Higgs(H) decay into ~nu_eL         ~nu_eRbar', 
            'MDME(489,1)=0  ! Higgs(H) decay into ~nu_eLbar      ~nu_eR', 
            'MDME(490,1)=0  ! Higgs(H) decay into ~mu_L-         ~mu_L+', 
            'MDME(491,1)=0  ! Higgs(H) decay into ~mu_R-         ~mu_R+', 
            'MDME(492,1)=0  ! Higgs(H) decay into ~mu_L-         ~mu_R+', 
            'MDME(493,1)=0  ! Higgs(H) decay into ~mu_L+         ~mu_R-', 
            'MDME(494,1)=0  ! Higgs(H) decay into ~nu_muL        ~nu_muLbar', 
            'MDME(495,1)=0  ! Higgs(H) decay into ~nu_muR        ~nu_muRbar', 
            'MDME(496,1)=0  ! Higgs(H) decay into ~nu_muL        ~nu_muRbar', 
            'MDME(497,1)=0  ! Higgs(H) decay into ~nu_muLbar     ~nu_muR', 
            'MDME(498,1)=0  ! Higgs(H) decay into ~tau_1-        ~tau_1+', 
            'MDME(499,1)=0  ! Higgs(H) decay into ~tau_1-        ~tau_1+', 
            'MDME(500,1)=0  ! Higgs(H) decay into ~tau_1-        ~tau_1+', 
            'MDME(501,1)=0  ! Higgs(H) decay into ~tau_1-        ~tau_1+', 
            'MDME(502,1)=0  ! Higgs(H) decay into ~tau_2-        ~tau_2+'),
        # This is a vector of ParameterSet names to be read, in this order
        parameterSets = cms.vstring('pythiaUESettings', 
            'processParameters')
    )
)


# Path and EndPath definitions
process.generation_step = cms.Path(process.pgen)
process.simulation_step = cms.Path(process.psim)
process.digitisation_step = cms.Path(process.pdigi)
process.L1simulation_step = cms.Path(process.SimL1Emulator)
process.digi2raw_step = cms.Path(process.DigiToRaw)
process.raw2digi_step = cms.Path(process.RawToDigi)
process.L1Reco_step = cms.Path(process.L1Reco)
process.genfiltersummary_step = cms.EndPath(process.genFilterSummary)
process.endjob_step = cms.EndPath(process.endOfProcess)
process.FEVTDEBUGHLToutput_step = cms.EndPath(process.FEVTDEBUGHLToutput)

# Schedule definition
# process.schedule = cms.Schedule(process.generation_step,process.genfiltersummary_step,process.simulation_step,process.digitisation_step,process.L1simulation_step,process.digi2raw_step)

process.an = cms.Path(process.genParticlesForPartonJets*process.ak5PartonJets*process.bbhanalysis)

process.schedule = cms.Schedule(process.generation_step,process.an)

#process.p1 = cms.Path(process.genParticlesForPartonJets*process.ak5PartonJets*process.bbhanalysis)

#process.schedule.extend(process.HLTSchedule)
#process.schedule.extend([process.raw2digi_step,process.L1Reco_step,process.endjob_step,process.FEVTDEBUGHLToutput_step])
# filter all path with the production filter sequence
for path in process.paths:
	getattr(process,path)._seq = process.generator * getattr(process,path)._seq 
