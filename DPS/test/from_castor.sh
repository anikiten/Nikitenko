#!/bin/tcsh

@ i =  1

while ( $i <= 30 )

rfcp /castor/cern.ch/user/a/anikiten/DiMuonData2011/DiMuons_May10ReReco_$i*.root /tmp/anikiten/SinglePionEfficiencyNew/DiMuons_May10ReReco_$i.root

@ i = $i + 1      

end




