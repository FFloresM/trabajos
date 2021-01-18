#mport numpy as np

file_duelos = "duelos.txt"
#with open(duelos, 'r') as file:
file = open(file_duelos, 'r')
lineas = file.readlines()
#print(lineas)
participantes = []

for linea in lineas:
	l = []
	partes = linea.split(',')
	l.append(partes[0])
	l.append(partes[1])
	if l not in participantes:
		participantes.append(l)

	l[0] = partes[2]
	l[1] = partes[3]
	if l not in participantes:
		participantes.append(l)

print(participantes)

#matriz = np.zeros([len(participantes), len(dojo)])
#print(matriz)
#print(participantes)
#print(dojo)

resultados = "resultados.txt"
file2 = open(resultados,'r')
lineas2 = file2.readlines()
puntos = []
for linea in lineas2:
	l = []
	partes = linea.split(',')
	l.append(partes[0])
	l.append(int(partes[1]))
	#if l not in puntos:
	puntos.append(l)
	l = []
	l.append(partes[2])
	l.append(int(partes[3]))
	#if l not in puntos:
	puntos.append(l)

print(puntos)

puntos_participantes = []

for fila in participantes:
	suma = 0
	nombre = fila[0]
	for i in puntos:
		if i[0] == nombre:
			suma += i[1]
	puntos_participantes.append([nombre, suma])


print(puntos_participantes)

