import FWCore.ParameterSet.Config as cms

# put this file into your crab job script

process = cms.Process("copy") 

process.maxEvents = cms.untracked.PSet(input=cms.untracked.int32(-1))

process.source = cms.Source("PoolSource", 
                            fileNames=cms.untracked.vstring(



                            'file:/tmp/abdollah/Tau/TauHLTPOutputMET15_44_1_asc.root'



                            
                            )
                            )
process.copyAll = cms.OutputModule("PoolOutputModule", fileName=cms.untracked.string("OutPut.root"))
process.printEventNumber = cms.EDAnalyzer("AsciiOutputModule")
process.out = cms.EndPath(process.copyAll + process.printEventNumber)
