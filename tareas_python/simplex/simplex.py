import numpy as np


matriz = []
with open('modelo.txt', 'r') as f:
	lineas = f.readlines()
	for i in lineas:
		n = []
		for s in i.split():
			if s.isdigit():
				n.append(int(s))
		matriz.append(n)
#agraga un cero a la primera fila -z=0
matriz[:][0].append(0)
#elimina el último cero 
matriz.remove([0])
#print(matriz)

tabla = np.array(matriz)
#multiplica por -1 la primera fila
tabla[0,:]*=-1
print(tabla)
#guarda el minimo valor de la primera fila
min_ = tabla[0,:].argmin()
col_pib = tabla[:,min_][1:]
col_LD = tabla[:,-1][1:]
div = col_LD//col_pib
index_min = np.where(div == min(div))
print(col_pib[index_min])

