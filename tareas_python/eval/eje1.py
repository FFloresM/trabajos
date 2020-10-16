import matplotlib.pyplot as plt
import math
import numpy as np

def inversa():
    while 1:
        filas = []
        for i in range(3):
            fila = input("ingrese elementos fila {}: ".format(1+i))
            fila = fila.split()
            fila = list(map(int, fila))
            filas.append(fila)
        A = np.array((filas[0],filas[1], filas[2]))
        det = np.linalg.det(A)
        if det == 0:
            print("matriz singular")
        else:
            break
    b = input("ingrese terminos de b: ")
    b = b.split()
    b = np.array(list(map(int, fila)))
    x = np.linalg.solve(A,b)
    return x

print(inversa())