#!/bin/sh


likwid-perfctr -o FLOPS_DP.txt -C 3 -g FLOPS_DP -m ./resolveEDO < teste.dat

grep -o 'FP_ARITH_INST_RETIRED_SCALAR_DOUBLE*|' FLOPS_DP.txt
