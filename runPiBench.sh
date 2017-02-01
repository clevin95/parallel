#!/bin/bash
#PBS -l procs=1,tpn=1,mem=34gb,walltime=15:00
#PBS -q cpsc424
cd "$PBS_O_WORKDIR"
./piBench0
./piBench1
./piBench2
./piBench3
# ./vectorTri

