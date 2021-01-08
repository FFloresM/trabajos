import numpy as np
B_ = [[-1,2,-1],[2,-1,2],[-1,2,-1]]
B = np.array(B_)
b_ = [1,2,3]
b = np.array(b_)

A = []
for x in range(3):
	l = input("ingrese fila: ").split()
	l = [float(i) for i in l ]
	A.append(l)

A = np.array(A)

C = A*B*A.T

if np.linalg.det(C) == 0:
	print("C no es invertible")
else:
	print(np.linalg.solve(C,b))
	