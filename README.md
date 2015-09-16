# thread_local-Test-ICC
Example showing issue with thread_local for MIC with icc

##Requirements
icc
gcc compatibility (testted with gcc 4.9.2)

## Problem description
The same code is compiled twice, once for the x86_64 architecture and once for MIC architecture. The code does not compile for MIC: the ```thread_local``` non-POD type object cannot be compiled correctly.

## To reproduce the problem
Run script ```testme.sh```


