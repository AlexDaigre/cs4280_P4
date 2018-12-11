READ 
LOAD 1
STORE tempVar
LOAD x
SUB tempVar
BRNEG label
LOAD 10
STORE tempVar
LOAD x
SUB tempVar
BRPOS label
LOAD x
STORE tempVar
WRITE tempVar
label: NOOP
label: NOOP
