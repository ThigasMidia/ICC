#!/bin/sh

#Thiago José Barzotto - GRR20235687
CORE=0

likwid-perfctr -o FLOPS_DP.txt -C ${CORE} -g FLOPS_DP -m ./resolveEDO < edo.dat

grep 'FP_ARITH_INST_RETIRED_SCALAR_DOUBLE' FLOPS_DP.txt | awk '{print $2 "," $6}' 
