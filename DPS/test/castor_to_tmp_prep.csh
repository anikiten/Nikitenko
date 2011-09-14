#!/bin/tcsh

rm todo.csh
touch todo.csh
#echo "#!/bin/csh" > todo.csh 
setenv DIR ${1}
foreach i (`nsls ${DIR} | grep root`)
echo "rfcp ${DIR}/${i} $SCRATCH/TEST" >> todo.csh
end

chmod a+x todo.csh
