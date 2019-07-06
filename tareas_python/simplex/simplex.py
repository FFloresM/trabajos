import numpy as np
#para que muestre con pocos decimales
np.set_printoptions(suppress=True)

def pibote(tabla):
    #multiplica por -1 la primera fila
    tabla[0,:]*=-1
    #print(tabla)
    #guarda el minimo valor de la primera fila
    min_ = tabla[0,:].argmin()
    print(min_)
    #determina columna pibote
    col_pib = tabla[:,min_]#[1:]
    # obtiene columna del lado derecho
    col_LD = tabla[:,-1]#[1:]
    # hace división para obtener el mínimo
    div = col_LD//col_pib
    #evuleve el indice dela menor fila (sin contar la fila z)
    index_min = np.where(div == np.partition(div,1)[1])
    #retorna el indice de fila y columna
    return index_min, min_

def ops(tabla, pib, col):
    tabla[pib] = tabla[pib] / tabla[pib,0]
    #itera soble todas las filas,menos la del pibote actual
    for i in range(len(tabla)):
        if (tabla[i] !=tabla[p]).any():
            tabla[i] = tabla[i]-tabla[i,col]*tabla[p]
            
    return tabla
    



matriz = []
with open('modelo.txt', 'r') as f:
	lineas = f.readlines()
	for i in lineas:
		n = []
		for s in i.split():
			if s.isdigit():
				n.append(int(s))
		matriz.append(n)
#agraga un cero a la primera fila z=0
matriz[:][0].append(0)
#elimina el último cero 
matriz.remove([0])
#print(matriz)

tabla = np.array(matriz, dtype=float)
print(tabla)
p,c = pibote(tabla)
print(tabla[p])
ops(tabla,p,c)