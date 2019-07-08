import numpy as np
#para que muestre con pocos decimales
np.set_printoptions(suppress=True)

def pibote(tabla, base):

    #guarda el minimo valor de la primera fila
    min_ = tabla[0,:].argmin()
    #print(min_)
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
    tabla[pib] = tabla[pib] / tabla[pib,col]
    #itera soble todas las filas, menos la del pibote actual
    for i in range(len(tabla)):
        if (tabla[i] !=tabla[p]).any():
            tabla[i] = tabla[i]-tabla[i,col]*tabla[p]
            
    return tabla
    
#para guardar los valores del modelo
matriz = []
#leer archivo
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
#elimina el último cero de x_k > 0
matriz.remove([0])

#transforma matriz en numpy array
tabla = np.array(matriz, dtype=float)
#multiplica por -1 la primera fila
tabla[0,:]*=-1
#para guardar las variables que entran a la base
base = [0 for x in range(len(tabla[0,:])-1)]

print("Tabla incial del simplex")
print(tabla)

i = 1
while True:
    if (tabla[0,:] >= 0).all():
        break
    print("iteración",i)
    i+=1
    p,c = pibote(tabla, base)
    base[p[0][0]-1] = 1
    tabla = ops(tabla,p,c)
    print(tabla)

result = tabla[:,-1][1:]
var = ['x1', 'x2', 'x3']
print("Solución")

for i in range(len(base)):
	if base[i] == 1:
		print(var[i], "=", result[i])
	else:
		print(var[i], "= 0")

print("Z = ",tabla[0,3])

