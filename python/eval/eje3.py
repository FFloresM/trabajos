import matplotlib.pyplot as plt
import math
import numpy as np

def sistemaN():
    while 1:
        n = int(input("ingrse n: "))
        A = np.zeros((n,n))
        b = np.zeros(n)
        for i in range(n):
            for j in range(n):
                A[i,j] = 20-2*np.cos(3*i)+3*np.sin(3*j)
        for i in range(n):
            b[i] = sum(A[i])
        if np.linalg.det(A) == 0:
            print("matriz singular")
        else:
            x = np.linalg.solve(A,b)
            break
    N = [i for i in range(1,n+1)]
    plt.scatter(x,N)
    plt.plot(x,N)
    plt.show()

sistemaN()