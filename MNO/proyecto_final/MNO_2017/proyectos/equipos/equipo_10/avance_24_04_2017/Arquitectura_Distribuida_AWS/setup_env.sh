#!/bin/bash 

aws ec2 describe-instances | \
jq '.Reservations[].Instances[].PublicDnsName' | \
tr '"' ' ' > instancias

sed 's/ //g' instancias > instancias2
rm instancias
mv instancias2 instancias

parallel --nonall --slf instancias "sudo apt-get install -y parallel"

parallel --nonall --basefile installmpi.sh  --slf instancias "./installmpi.sh"

parallel --nonall --basefile sourcefile  --slf instancias "source sourcefile"

parallel --nonall --basefile hosts.sh  --slf instancias "./hosts.sh"

parallel --nonall --basefile hello.sh  --slf instancias "./mpicc.sh"

