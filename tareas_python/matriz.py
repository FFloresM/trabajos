import random as rd

n = int(input("ingrese tamaño matriz cuadrada: "))

matriz = []
for i in range(n):
	matriz.append([])
	for j in range(n):
		matriz[i].append(rd.randrange(100))

for i in range(n):
	for j in range(n):
		print(matriz[i][j],end=' ')
	print()

suma_fila = []
suma_col = []

for i in range(n):
	suma_fila.append(sum(matriz[i]))
print(suma_fila)

for i in range(n):
	col = [col[i] for col in matriz]
	suma_col.append(sum(col))
print(suma_col)