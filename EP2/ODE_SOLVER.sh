#!/bin/sh

make purge
make
likwid-perfctr -o FLOPS_DP.txt -C 3 -g FLOPS_DP -m ./resolveEDO < teste.dat

grep 'FP_ARITH_INST_RETIRED_SCALAR_DOUBLE' FLOPS_DP.txt | awk '{print $2 "," $6}' 
