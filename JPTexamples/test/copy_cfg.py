import FWCore.ParameterSet.Config as cms

process = cms.Process("copy") 

process.maxEvents = cms.untracked.PSet(input=cms.untracked.int32(-1))

process.source = cms.Source("PoolSource", 
                            fileNames=cms.untracked.vstring(

                            '/castor/cern.ch/user/a/abdollah/Ntuple/MC/V_1/Wenu/outZZ3X_10_1_EBm.root',
                            
                            )
                            )
process.copyAll = cms.OutputModule("PoolOutputModule", fileName=cms.untracked.string("OutPut.root"))
process.printEventNumber = cms.EDAnalyzer("AsciiOutputModule")
process.out = cms.EndPath(process.copyAll + process.printEventNumber)
