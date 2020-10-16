from matplotlib import pyplot as plt

def readFile(filename):
	texto = []
	with open(filename, 'r') as file:
		for linea in file:
			texto.append(linea.strip().split(','))
	return texto

def porcentaje(l,cond=0):
	suma=0
	for i in l:
		if cond==i:
				suma+=1
	return (suma/len(l))*100

def promedio_cond(carrera, buscar,cond):
	suma=0
	total = 0
	for i in range(len(carrera)):
		if cond == carrera[i]:
			suma+=float(buscar[i])
			total+=1
	return suma/total

def mejor(carrera,buscar,cond):
	notas_cond = []
	for i in range(len(carrera)):
		if cond == carrera[i]:
			notas_cond.append(float(buscar[i]))
		else:
			notas_cond.append(0)
	mayor = max(notas_cond)
	return notas_cond.index(mayor)

def verFacultad(carreras, facu, cond):
	for i in range(len(carrera)):
		if carreras[i] == cond:
			return facu[i]

def promedio(l):
	for i in range(len(l)):
		l[i] = float(l[i])
	return sum(l)/len(l)



def crearReporte(datos, carrera):
	
	salida = ["CARRERA: "+carrera]
	nombre = []
	rut = []
	sexo = []
	NES = []
	lenguaje = []
	mates = []
	carreras = []
	facultad = []	
	for row in datos[1:]:
		nombre.append(row[1]+" "+row[2]) #nombre completo
		rut.append(row[0])
		sexo.append(row[4])
		NES.append(row[10])
		lenguaje.append(row[11])
		mates.append(row[12])
		carreras.append(row[7])
		facultad.append(row[6])
	facu = verFacultad(carreras,facultad,carrera)
	macho = porcentaje(sexo,cond="MASCULINO")
	hembra = porcentaje(sexo,cond="FEMENINO")
	salida.append("PORCENTAJE DE ESTUDIANTES SEXO FEMENINO: {:.2f}\n".format(hembra))
	salida.append("PORCENTAJE DE ESTUDIANTES SEXO MASCULINO: {:.2f}\n".format(macho))
	v = mejor(carreras, NES, carrera)
	salida.append("MEJOR NES: "+nombre[v]+" "+rut[v])
	v=mejor(carreras,lenguaje,carrera)
	salida.append("MEJOR LENGUAJE: "+nombre[v]+" "+rut[v])
	v=mejor(carreras,mates,carrera)
	salida.append("MEJOR MATEMATICA: "+nombre[v]+" "+rut[v])
	salida.append("PROMEDIO NES CARRERA: {:.2f}\n".format(promedio_cond(carreras,NES,carrera)))
	salida.append("PROMEDIO NES FACULTAD: {:.2f}\n".format(promedio_cond(facultad,NES,facu)))
	salida.append("PROMEDIO NES UNIVERSIDAD: {:.2f}\n".format(promedio(NES)))
	salida.append("PROMEDIO LENGUAJE CARRERA: {:.2f}\n".format(promedio_cond(carreras,lenguaje,carrera)))
	salida.append("PROMEDIO LENGUAJE FACULTAD: {:.2f}\n".format(promedio_cond(facultad,lenguaje,facu)))
	salida.append("PROMEDIO LENGUAJE UNIVERSIDAD: {:.2f}\n".format(promedio(lenguaje)))
	salida.append("PROMEDIO MATEMÁTICA CARRERA: {:.2f}\n".format(promedio_cond(carreras,mates,carrera)))
	salida.append("PROMEDIO MATEMÁTICA FACULTAD: {:.2f}\n".format(promedio_cond(facultad,mates,facu)))
	salida.append("PROMEDIO MATEMÁTICA UNIVERSIDAD: {:.2f}\n".format(promedio(mates)))

	with open(carrera, 'a') as archivo:
		archivo.writelines(salida)

	name = ["Masculino", "Femenino"]
	values = [int((macho*len(sexo))/100), int((hembra*len(sexo))/100)]
	plt.bar(name,values)
	plt.title("sexo de estudiantes en carrera "+carrera)
	plt.xlabel("sexo")
	plt.ylabel("frecuencia")
	plt.show()

archivo = 'matriculas.csv'
datos = readFile(archivo)
carrera = input("ingrese carrera: ")
crearReporte(datos,carrera)


