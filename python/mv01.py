import numpy as np

B = np.array([
	[-1,2,-1],
	[2,-1,2],
	[-1,2,-1]
])
b = np.array([1,2,3])

A = []
for x in range(3):
	s = "ingrese fila "+str(x+1)+": "
	d = input(s).split()
	d = [int(i) for i in d ]
	A.append(d)

A = np.array(A)

C = A*B*A.T

if np.linalg.det(C) == 0:
	print("C es una matriz singular")
else:
	print(np.linalg.solve(C,b))
	