READ 
l0: NOOP
LOAD 0
STORE v0
LOAD x
SUB v0
BRPOS l1
LOAD x
STORE y
l2: NOOP
LOAD 0
STORE v1
LOAD y
SUB v1
BRPOS l3
LOAD y
STORE v2
WRITE v2
LOAD 1
STORE v3
LOAD y
SUB v3
STORE y
BR l3
l3: NOOP
LOAD 1
STORE v4
LOAD x
SUB v4
STORE x
BR l3
l3: NOOP
STOP
x: 0
y: 0
v0: 0
v1: 0
v2: 0
v3: 0
v4: 0