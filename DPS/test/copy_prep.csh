#!/bin/tcsh
# source /vols/cms/grid/setup.sh
# voms-proxy-init -voms cms
# srmls $DCACHE_SRM_ROOT/store/user/anikiten
# To delete a directory (and everything below it):/vols/cms/grid/scripts/srm-delete-directory.py $DCACHE_SRM_ROOT/store/user/anikiten/dirtodelete/ 
#
# 0. 
#    source /vols/cms/grid/setup.sh
#    voms-proxy-init -voms cms
#
# 1.create "list" file with command 2:
#   a. lcg-ls srm://gfe02.grid.hep.ph.ic.ac.uk/pnfs/hep.ph.ic.ac.uk/data/cms/store/user/anikiten/Run2011A-08Nov2011 > list
#   b. lcg-ls srm://gfe02.grid.hep.ph.ic.ac.uk/pnfs/hep.ph.ic.ac.uk/data/cms/store/user/anikiten/Run2011A-08Nov2011 | awk -F / '{print $10}' > list
#
# 2. tcsh 
#    source copy_prep.csh anikiten/Run2011A-08Nov2011 
#
# 3. commands before run: source copy_vols.csh
#   bash
#   source /vols/cms/grid/setup.sh
#   voms-proxy-init -voms cms
#   source copy_vols.csh
#
rm copy_vols.csh
touch copy_vols.csh
setenv DIR ${1}
foreach i (`cat list`)
echo ${i}

echo "srmcp -streams_num=1 srm://gfe02.grid.hep.ph.ic.ac.uk:8443/pnfs/hep.ph.ic.ac.uk/data/cms/store/user/${DIR}/${i} file:////vols/cms02/${DIR}/${i}" >> copy_vols.csh

#echo "srmcp -2 -streams_num=1 srm://srm-cms.cern.ch:8443/srm/managerv2?SFN=${DIR}/${i} file:////vols/cms02/anikiten/Run2011A-08Nov2011/${i}" >> copy_vols.csh
# echo "srmcp srm://gfe02.grid.hep.ph.ic.ac.uk:8443/srm/managerv2?SFN=${DIR}/${i} file:////vols/cms02/anikiten/Run2011A-08Nov2011/${i}" >> copy_vols.csh
end

chmod a+x copy_vols.csh
