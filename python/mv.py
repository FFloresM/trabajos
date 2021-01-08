import numpy as np

B = np.array([[-1,2,-1], [2,-1,2], [-1,2,-1]])
b = np.array([1,2,3])
print(B,b)
A = []
for i in range(3):
	p = input(f"fila {i+1} : ").split()
	p = [int(i) for i in p ]
	A.append(p)

A = np.array(A)

C = A*B*A.T

if np.linalg.det(C) != 0:
	print(np.linalg.solve(C,b))
else:
	print("matriz C no invertible")
