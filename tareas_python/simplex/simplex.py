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
#determina columna pibote
col_pib = tabla[:,min_][1:]
# obtiene columna del lado derecho
col_LD = tabla[:,-1][1:]
# hace división para obtener el mínimo
div = col_LD//col_pib
# obtinene el índice del mínimo
index_min = np.where(div == min(div))
print(col_pib[index_min])

