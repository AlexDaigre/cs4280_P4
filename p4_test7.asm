READ 
LOAD 0
STORE tempVar
LOAD x
SUB tempVar
BRZNEG label
LOAD x
STORE tempVar
WRITE tempVar
label: NOOP
