READ 
l0: NOOP
LOAD 0
STORE v0
LOAD x
SUB v0
BRPOS l1
LOAD x
STORE v1
WRITE v1
LOAD 2
STORE v2
LOAD x
SUB v2
STORE x
BR l1
l1: NOOP
STOP
x: 0
v0: 0
v1: 0
v2: 0