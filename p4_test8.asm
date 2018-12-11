READ 
LOAD 1
STORE tempVar
LOAD 1
SUB tempVar
STORE tempVar
LOAD x
SUB tempVar
BRZERO label
LOAD x
MULT -1
STORE tempVar
WRITE tempVar
label: NOOP
