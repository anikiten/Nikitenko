# Auto generated configuration file
# using: 
# Revision: 1.303.2.7 
# Source: /cvs_server/repositories/CMSSW/CMSSW/Configuration/PyReleaseValidation/python/ConfigBuilder.py,v 
# with command line options: QCD_Pt_80_120_7TeV.cfi -s GEN,SIM,DIGI,L1,DIGI2RAW,HLT:GRun,RAW2DIGI,L1Reco -n 10 --geometry DB --conditions auto:mc --relval 9000,50 --datatier GEN-SIM-DIGI-RAW-HLTDEBUG --eventcontent FEVTDEBUGHLT --no_exec --python_filename RelValQCD_Pt_80_120_MC.py
import FWCore.ParameterSet.Config as cms

process = cms.Process('HLT')

# import of standard configurations

process.load("FWCore.MessageLogger.MessageLogger_cfi")
#process.load("Configuration.StandardSequences.Geometry_cff")
process.load("Configuration.Geometry.GeometryIdeal_cff")
process.load("Configuration.StandardSequences.MagneticField_cff")

process.load('Configuration.StandardSequences.Services_cff')
process.load('SimGeneral.HepPDTESSource.pythiapdt_cfi')
process.load('FWCore.MessageService.MessageLogger_cfi')
process.load('Configuration.EventContent.EventContent_cff')
process.load('SimGeneral.MixingModule.mixNoPU_cfi')
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
    input = cms.untracked.int32(5)
)

# Input source
process.source = cms.Source("EmptySource")

process.options = cms.untracked.PSet(

)

# Production Info
process.configurationMetadata = cms.untracked.PSet(
    version = cms.untracked.string('$Revision: 1.1 $'),
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
process.GlobalTag.globaltag = 'START53_V7A::All'

# parton jet
process.load("RecoJets.Configuration.GenJetParticles_cff")
process.genParticlesForPartonJets = process.genParticlesForJets.clone()
# process.genParticlesForPartonJets.ignoreParticleIDs = cms.vuint32()
process.genParticlesForPartonJets.partonicFinalState = True
process.genParticlesForPartonJets.excludeFromResonancePids = cms.vuint32(11, 12, 13, 14, 15, 16)

process.load("RecoJets.JetProducers.ak5GenJets_cfi")
process.ak5PartonJets  =  process.ak5GenJets.clone()
process.ak5PartonJets.src = cms.InputTag("genParticlesForPartonJets")

process.nmssmanalysis = cms.EDAnalyzer("nmssm_4b",
    HistOutFile = cms.untracked.string('nmssm_4b_mh60.root'),
    parton_jets = cms.InputTag("ak5PartonJets")
)

process.generator = cms.EDFilter("Pythia6GeneratorFilter",
    pythiaHepMCVerbosity = cms.untracked.bool(False),
    maxEventsToPrint = cms.untracked.int32(1),
    pythiaPylistVerbosity = cms.untracked.int32(2),
    filterEfficiency = cms.untracked.double(1.0),
    comEnergy = cms.double(7000.0),
    crossSection = cms.untracked.double(1.1),
    ExternalDecays = cms.PSet(
        Tauola = cms.untracked.PSet(
            TauolaPolar,
#            TauolaDefaultInputCards
	     InputCards = cms.PSet(
               pjak1 = cms.int32(0),
               pjak2 = cms.int32(0),
               mdtau = cms.int32(126)
             )
        ),
        parameterSets = cms.vstring('Tauola')
    ),
    UseExternalGenerators = cms.untracked.bool(True),
    PythiaParameters = cms.PSet(
        pythiaUESettingsBlock,
        processParameters = cms.vstring('MSEL=0         ! User defined processes',
            'MSUB(152)= 1   ! gg->H',
            # MSSM settings
            'IMSS(4)= 2     ! masses fixed by user',
            'RMSS(5)= 30.   ! tan beta', 
            'RMSS(19)= 125. ! m_A', 
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
            # Higgs masses
            'PMAS(25,1)=60.   ! mh',
            'PMAS(35,1)=125.  ! mH',
            # Switch off / on desirable channels for H->hh
            'MDME(334,1)=0  ! Higgs(H) decay into d              dbar', 
            'MDME(335,1)=0  ! Higgs(H) decay into u              ubar', 
            'MDME(336,1)=0  ! Higgs(H) decay into s              sbar', 
            'MDME(337,1)=0  ! Higgs(H) decay into c              cbar', 
            'MDME(338,1)=0  ! Higgs(H) decay into b              bbar', 
            'MDME(339,1)=0  ! Higgs(H) decay into t              tbar', 
            'MDME(340,1)=0  ! Higgs(H) decay into b              bbar', 
            'MDME(341,1)=0  ! Higgs(H) decay into t              tbar', 
            'MDME(342,1)=0  ! Higgs(H) decay into e-             e+', 
            'MDME(343,1)=0  ! Higgs(H) decay into mu-            mu+', 
            'MDME(344,1)=0  ! Higgs(H) decay into tau-           tau+', 
            'MDME(345,1)=0  ! Higgs(H) decay into tau-           tau+', 
            'MDME(346,1)=0  ! Higgs(H) decay into g              g', 
            'MDME(347,1)=0  ! Higgs(H) decay into gamma          gamma', 
            'MDME(348,1)=0  ! Higgs(H) decay into gamma          Z0', 
            'MDME(349,1)=0  ! Higgs(H) decay into Z0             Z0', 
            'MDME(350,1)=0  ! Higgs(H) decay into W+             W-', 
            'MDME(351,1)=0  ! Higgs(H) decay into Z0             h0', 
            'MDME(352,1)=1  ! Higgs(H) decay into h0             h0', 
            'MDME(353,1)=0  ! Higgs(H) decay into W+             H-', 
            'MDME(354,1)=0  ! Higgs(H) decay into H+             W-', 
            'MDME(355,1)=0  ! Higgs(H) decay into Z0             A0', 
            'MDME(356,1)=0  ! Higgs(H) decay into h0             A0', 
            'MDME(357,1)=0  ! Higgs(H) decay into A0             A0', 
            'MDME(358,1)=0  ! Higgs(H) decay into ~chi_10        ~chi_10', 
            'MDME(359,1)=0  ! Higgs(H) decay into ~chi_20        ~chi_10', 
            'MDME(360,1)=0  ! Higgs(H) decay into ~chi_20        ~chi_20', 
            'MDME(361,1)=0  ! Higgs(H) decay into ~chi_30        ~chi_10', 
            'MDME(362,1)=0  ! Higgs(H) decay into ~chi_30        ~chi_20', 
            'MDME(363,1)=0  ! Higgs(H) decay into ~chi_30        ~chi_30', 
            'MDME(364,1)=0  ! Higgs(H) decay into ~chi_40        ~chi_10', 
            'MDME(365,1)=0  ! Higgs(H) decay into ~chi_40        ~chi_20', 
            'MDME(366,1)=0  ! Higgs(H) decay into ~chi_40        ~chi_30', 
            'MDME(367,1)=0  ! Higgs(H) decay into ~chi_40        ~chi_40', 
            'MDME(368,1)=0  ! Higgs(H) decay into ~chi_1+        ~chi_1-', 
            'MDME(369,1)=0  ! Higgs(H) decay into ~chi_1+        ~chi_2-', 
            'MDME(370,1)=0  ! Higgs(H) decay into ~chi_2+        ~chi_1-', 
            'MDME(371,1)=0  ! Higgs(H) decay into ~chi_2+        ~chi_2-', 
            'MDME(372,1)=0  ! Higgs(H) decay into ~d_L           ~d_Lbar', 
            'MDME(373,1)=0  ! Higgs(H) decay into ~d_R           ~d_Rbar', 
            'MDME(374,1)=0  ! Higgs(H) decay into ~d_L           ~d_Rbar', 
            'MDME(375,1)=0  ! Higgs(H) decay into ~d_Lbar        ~d_R', 
            'MDME(376,1)=0  ! Higgs(H) decay into ~u_L           ~u_Lbar', 
            'MDME(377,1)=0  ! Higgs(H) decay into ~u_R           ~u_Rbar', 
            'MDME(378,1)=0  ! Higgs(H) decay into ~u_L           ~u_Rbar', 
            'MDME(379,1)=0  ! Higgs(H) decay into ~u_Lbar        ~u_R', 
            'MDME(380,1)=0  ! Higgs(H) decay into ~s_L           ~s_Lbar', 
            'MDME(381,1)=0  ! Higgs(H) decay into ~s_R           ~s_Rbar', 
            'MDME(382,1)=0  ! Higgs(H) decay into ~s_L           ~s_Rbar', 
            'MDME(383,1)=0  ! Higgs(H) decay into ~s_Lbar        ~s_R', 
            'MDME(384,1)=0  ! Higgs(H) decay into ~c_L           ~c_Lbar', 
            'MDME(385,1)=0  ! Higgs(H) decay into ~c_R           ~c_Rbar', 
            'MDME(386,1)=0  ! Higgs(H) decay into ~c_L           ~c_Rbar', 
            'MDME(387,1)=0  ! Higgs(H) decay into ~c_Lbar        ~c_R', 
            'MDME(388,1)=0  ! Higgs(H) decay into ~b_1           ~b_1bar', 
            'MDME(389,1)=0  ! Higgs(H) decay into ~b_2           ~b_2bar', 
            'MDME(390,1)=0  ! Higgs(H) decay into ~b_1           ~b_2bar', 
            'MDME(391,1)=0  ! Higgs(H) decay into ~b_1bar        ~b_2', 
            'MDME(392,1)=0  ! Higgs(H) decay into ~t_1           ~t_1bar', 
            'MDME(393,1)=0  ! Higgs(H) decay into ~t_2           ~t_2bar', 
            'MDME(394,1)=0  ! Higgs(H) decay into ~t_1           ~t_2bar', 
            'MDME(395,1)=0  ! Higgs(H) decay into ~t_1bar        ~t_2', 
            'MDME(396,1)=0  ! Higgs(H) decay into ~e_L-          ~e_L+', 
            'MDME(397,1)=0  ! Higgs(H) decay into ~e_R-          ~e_R+', 
            'MDME(398,1)=0  ! Higgs(H) decay into ~e_L-          ~e_R+', 
            'MDME(399,1)=0  ! Higgs(H) decay into ~e_L+          ~e_R-', 
            'MDME(400,1)=0  ! Higgs(H) decay into ~nu_eL         ~nu_eLbar', 
            'MDME(401,1)=0  ! Higgs(H) decay into ~nu_eR         ~nu_eRbar', 
            'MDME(402,1)=0  ! Higgs(H) decay into ~nu_eL         ~nu_eRbar', 
            'MDME(403,1)=0  ! Higgs(H) decay into ~nu_eLbar      ~nu_eR', 
            'MDME(404,1)=0  ! Higgs(H) decay into ~mu_L-         ~mu_L+', 
            'MDME(405,1)=0  ! Higgs(H) decay into ~mu_R-         ~mu_R+', 
            'MDME(406,1)=0  ! Higgs(H) decay into ~mu_L-         ~mu_R+', 
            'MDME(407,1)=0  ! Higgs(H) decay into ~mu_L+         ~mu_R-', 
            'MDME(408,1)=0  ! Higgs(H) decay into ~nu_muL        ~nu_muLbar', 
            'MDME(409,1)=0  ! Higgs(H) decay into ~nu_muR        ~nu_muRbar', 
            'MDME(410,1)=0  ! Higgs(H) decay into ~nu_muL        ~nu_muRbar', 
            'MDME(411,1)=0  ! Higgs(H) decay into ~nu_muLbar     ~nu_muR', 
            'MDME(412,1)=0  ! Higgs(H) decay into ~tau_1-        ~tau_1+', 
            'MDME(413,1)=0  ! Higgs(H) decay into ~tau_1-        ~tau_1+', 
            'MDME(414,1)=0  ! Higgs(H) decay into ~tau_1-        ~tau_1+', 
            'MDME(415,1)=0  ! Higgs(H) decay into ~tau_1-        ~tau_1+', 
            'MDME(416,1)=0  ! Higgs(H) decay into ~tau_1-        ~tau_1+', 
            'MDME(417,1)=0  ! Higgs(H) decay into ~tau_1-        ~tau_1+', 
            'MDME(418,1)=0  ! Higgs(H) decay into ~tau_1-        ~tau_1+', 
            'MDME(419,1)=0  ! Higgs(H) decay into ~tau_2-        ~tau_2+',
# h->bb
            'MDME(210,1)=0  ! Higgs(h) decay                            ',
            'MDME(211,1)=0  ! Higgs(h) decay                            ',
            'MDME(212,1)=0  ! Higgs(h) decay                            ',
            'MDME(213,1)=0  ! Higgs(h) decay                            ',
            'MDME(214,1)=1  ! Higgs(h) decay   b b_bar                  ',
            'MDME(215,1)=0  ! Higgs(h) decay                            ',
            'MDME(216,1)=0  ! Higgs(h) decay                            ',
            'MDME(217,1)=0  ! Higgs(h) decay                            ',
            'MDME(218,1)=0  ! Higgs(h) decay                            ',
            'MDME(219,1)=0  ! Higgs(h) decay                            ',
            'MDME(220,1)=0  ! Higgs(h) decay   tau tau                  ',
            'MDME(221,1)=0  ! Higgs(h) decay                            ',
            'MDME(222,1)=0  ! Higgs(h) decay                            ',
            'MDME(223,1)=0  ! Higgs(h) decay                            ',
            'MDME(224,1)=0  ! Higgs(h) decay                            ',
            'MDME(225,1)=0  ! Higgs(h) decay                            ',
            'MDME(226,1)=0  ! Higgs(h) decay                            ',
            'MDME(227,1)=0  ! Higgs(h) decay                            ',
            'MDME(228,1)=0  ! Higgs(h) decay                            ',
            'MDME(229,1)=0  ! Higgs(h) decay                            ',
            'MDME(230,1)=0  ! Higgs(h) decay                            ',
            'MDME(231,1)=0  ! Higgs(h) decay                            ',
            'MDME(232,1)=0  ! Higgs(h) decay                            ',
            'MDME(233,1)=0  ! Higgs(h) decay                            ',
            'MDME(234,1)=0  ! Higgs(h) decay                            ',
            'MDME(235,1)=0  ! Higgs(h) decay                            ',
            'MDME(236,1)=0  ! Higgs(h) decay                            ',
            'MDME(237,1)=0  ! Higgs(h) decay                            ',
            'MDME(238,1)=0  ! Higgs(h) decay                            ',
            'MDME(239,1)=0  ! Higgs(h) decay                            ',
            'MDME(240,1)=0  ! Higgs(h) decay                            ',
            'MDME(241,1)=0  ! Higgs(h) decay                            ',
            'MDME(242,1)=0  ! Higgs(h) decay                            ',
            'MDME(243,1)=0  ! Higgs(h) decay                            ',
            'MDME(244,1)=0  ! Higgs(h) decay                            ',
            'MDME(245,1)=0  ! Higgs(h) decay                            ',
            'MDME(246,1)=0  ! Higgs(h) decay                            ',
            'MDME(247,1)=0  ! Higgs(h) decay                            ',
            'MDME(248,1)=0  ! Higgs(h) decay                            ',
            'MDME(249,1)=0  ! Higgs(h) decay                            ',
            'MDME(250,1)=0  ! Higgs(h) decay                            ',
            'MDME(251,1)=0  ! Higgs(h) decay                            ',
            'MDME(252,1)=0  ! Higgs(h) decay                            ',
            'MDME(253,1)=0  ! Higgs(h) decay                            ',
            'MDME(254,1)=0  ! Higgs(h) decay                            ',
            'MDME(255,1)=0  ! Higgs(h) decay                            ',
            'MDME(256,1)=0  ! Higgs(h) decay                            ',
            'MDME(257,1)=0  ! Higgs(h) decay                            ',
            'MDME(258,1)=0  ! Higgs(h) decay                            ',
            'MDME(259,1)=0  ! Higgs(h) decay                            ',
            'MDME(260,1)=0  ! Higgs(h) decay                            ',
            'MDME(261,1)=0  ! Higgs(h) decay                            ',
            'MDME(262,1)=0  ! Higgs(h) decay                            ',
            'MDME(263,1)=0  ! Higgs(h) decay                            ',
            'MDME(264,1)=0  ! Higgs(h) decay                            ',
            'MDME(265,1)=0  ! Higgs(h) decay                            ',
            'MDME(266,1)=0  ! Higgs(h) decay                            ',
            'MDME(267,1)=0  ! Higgs(h) decay                            ',
            'MDME(268,1)=0  ! Higgs(h) decay                            ',
            'MDME(269,1)=0  ! Higgs(h) decay                            ',
            'MDME(270,1)=0  ! Higgs(h) decay                            ',
            'MDME(271,1)=0  ! Higgs(h) decay                            ',
            'MDME(272,1)=0  ! Higgs(h) decay                            ',
            'MDME(273,1)=0  ! Higgs(h) decay                            ',
            'MDME(274,1)=0  ! Higgs(h) decay                            ',
            'MDME(275,1)=0  ! Higgs(h) decay                            ',
            'MDME(276,1)=0  ! Higgs(h) decay                            ',
            'MDME(277,1)=0  ! Higgs(h) decay                            ',
            'MDME(278,1)=0  ! Higgs(h) decay                            ',
            'MDME(279,1)=0  ! Higgs(h) decay                            ',
            'MDME(280,1)=0  ! Higgs(h) decay                            ',
            'MDME(281,1)=0  ! Higgs(h) decay                            ',
            'MDME(282,1)=0  ! Higgs(h) decay                            ',
            'MDME(283,1)=0  ! Higgs(h) decay                            ',
            'MDME(284,1)=0  ! Higgs(h) decay                            ',
            'MDME(285,1)=0  ! Higgs(h) decay                            ',
            'MDME(286,1)=0  ! Higgs(h) decay                            ',
            'MDME(287,1)=0  ! Higgs(h) decay                            ',
            'MDME(288,1)=0  ! Higgs(h) decay                            '),
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

#process.an = cms.Path(process.genParticlesForPartonJets*process.ak5PartonJets*process.nmssmanalysis)

process.an = cms.Path(process.nmssmanalysis)

process.schedule = cms.Schedule(process.generation_step,process.an)

#process.p1 = cms.Path(process.genParticlesForPartonJets*process.ak5PartonJets*process.bbhanalysis)

#process.schedule.extend(process.HLTSchedule)
#process.schedule.extend([process.raw2digi_step,process.L1Reco_step,process.endjob_step,process.FEVTDEBUGHLToutput_step])
# filter all path with the production filter sequence
for path in process.paths:
	getattr(process,path)._seq = process.generator * getattr(process,path)._seq 
