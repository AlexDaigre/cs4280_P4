READ 
label: NOOP
LOAD 0
STORE tempVar
LOAD x
SUB tempVar
BRPOS label
LOAD x
STORE tempVar
WRITE tempVar
LOAD 2
STORE tempVar
LOAD x
SUB tempVar
STORE x
BR label
label: NOOP
