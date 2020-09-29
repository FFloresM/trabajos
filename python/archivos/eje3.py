from random import randint as rd

n = int(input("ingrese cantidad de filas: "))
m = int(input("ingrese cantidad de columnas: "))
min_ = -n*m
max_ = -min_
matriz = [[rd(min_,max_) for _ in range(m)] for _ in range(n)]

with open('matriz.txt', 'w') as m:
	for fila in matriz:
		linea = str(fila)[1:-1]+"\n"
		m.write(linea) 
#print(matriz)
