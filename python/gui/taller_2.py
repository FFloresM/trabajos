from tkinter import *
import tkinter as tk 
from tkinter.ttk import *
from tkinter import ttk
from tkinter import messagebox as msg
from PIL import Image, ImageTk
import csv #leer csv

def leer_txt(filename):
	"""Leer archivo txt"""
	with open(filename, 'r') as file:
		return file.readlines()

def leer_csv(filename, sep):
	"""LEer archivo csv"""
	l = []
	with open(filename) as csvfile:
		reader = csv.reader(csvfile, delimiter=sep)
		for fila in reader:	
			l.append(fila)
	return l[1:]

#LEer nombre se usuario y contraseña
nombre_archivo = "datos.txt"
datos = leer_txt(nombre_archivo)
USUARIO = datos[0].rstrip()
CLAVE = datos[1]

#leer instructivo para ventana 2
txt = "" 
for linea in leer_txt("instructivo.txt"):
	txt+=linea
#leer informaciond de ecuaciones apra ventana 2
des = ""
for linea in leer_txt("oee2.txt"):
	des+=linea

#leer rendimiento teorico
teorico = []
teorico = leer_csv("rendimiento_teorico.csv", ';')


def disponibilidad(min_prog,min_parado):
	"""Funcion para calcular disponibilidad"""
	return (min_prog-min_parado)/min_prog

def calidad(merma, cant_prod):
	"""Funcion para calcular calidad"""
	return 1-(merma/(merma+cant_prod))

def rendimiento(cant_prod, min_prog, min_parado):
	"""Funcion para calcular rendimiento real"""
	return cant_prod/(min_prog-min_parado)

def porcentaje_rendimiento(ren_practico, ren_teorico):
	"""Funcion para calcular porcentaje rendimiento"""
	return ren_practico/ren_teorico

def oee(disponibilidad, calidad, rendimiento):
	"""Funcion para calcular Eficiencia genearal de los euipos OEE"""
	return disponibilidad*calidad*rendimiento


def volver_fun():
	"""PAra el boton volver de la tercera ventana"""
	ventana_produccion.destroy()
	segunda_ventana()

def calcular_fun(min_prog, min_parado, merma, cant_prod, codigo, linea):
	"""Funciona que realiza todos los calculos según datos ingresados por el usuario"""
	if min_parado == 0 or min_prog == 0:
		msg.showerror("ERROR", "Ingresar minutos!")
	else:
		kilo = leer_csv("peso_caja_unitario.csv", ',')[0][1]
		cant_prod = cant_prod*int(kilo)
		if cant_prod < 1250:
			msg.showerror("ERROR", "Reingresar Cantidad de Producción")
		else:
			calidad_ = calidad(merma, cant_prod)
			print("calidad = ",calidad_)
			if calidad_ < 0.6:
				msg.showerror("ERROR", "Reproceso")
			else:
				disp = disponibilidad(min_prog, min_parado)
				print("disp = ", disp)
				rend = rendimiento(cant_prod, min_prog, min_parado)
				print(rend)
				ren_teorico = ""
				producto = ""
				for i in teorico:
					if str(codigo) in i:
						ren_teorico = i[2]
						producto = i[1]
				#poner nombre de producto segun codigo
				p = ttk.Entry(ventana_produccion, width=40)
				p.insert(0,producto)
				p.place(x=200,y=75)
				ren_teorico = int(ren_teorico)
				por_rend = porcentaje_rendimiento(rend, ren_teorico)
				print("porcentaje rend = ",por_rend) 
				oee_ = oee(disp, calidad_, por_rend)
				print("oee = ", oee_) 
				resultados = ""
				resultados+=f"Total linea {linea} \n Disponibilidad = {disp:.2g} \n Calidad = {calidad_:.2g} \n Rendimiento = {por_rend:.2g} \n OEE = {oee_:.2g} \n"
				if oee_>0.8:
					resultados+="Producción Aceptada"
				else:
					resultados+="Deficit de producción: Agende Reunión con Superiores"
				msg.showinfo("RESULTADOS DE EFICIENCIA GENERAL DE LOS EQUIPOS", resultados)

def salir_fun():
	"""PAra el boton salir: cierra tercera ventana y abre primera"""
	ventana_produccion.destroy()
	primera_ventana()

def tercera_ventana():
	"""Crea la tercera ventana"""
	ventana_bienvenida.destroy()
	global ventana_produccion
	ventana_produccion = tk.Tk()
	ventana_produccion.title("Registro de Producción Diaria")
	ventana_produccion.geometry("600x500")
	#label = ttk.Label(ventana_produccion, text = "Disponibilidad")
	#label.place(x=100, y=50)
	codigo = tk.IntVar()
	codigo_label = ttk.Label(ventana_produccion, text = "Código:")
	codigo_label.place(x=100, y=50)
	codigo_entry = ttk.Entry(ventana_produccion, width=20, textvariable = codigo)
	codigo_entry.place(x=150, y= 50)
	producto = ttk.Label(ventana_produccion, text="PRODUCTO")
	producto.place(x=100,y=75)

	turno = tk.IntVar()
	turno_label = ttk.Label(ventana_produccion, text = "Turno:")
	turno_label.place(x=300, y=50)
	turno_entry = ttk.Entry(ventana_produccion, width=20, textvariable = turno)
	turno_entry.place(x=350, y= 50)
	linea = tk.StringVar()
	linea_label = ttk.Label(ventana_produccion, text = "Linea(A,B):")
	linea_label.place(x=100, y=100)
	linea_entry = ttk.Entry(ventana_produccion, width=5, textvariable = linea)
	linea_entry.place(x=170, y= 100)

	fabricada = tk.IntVar()
	fabricada_label = ttk.Label(ventana_produccion, text = "Cantidad Fabricada (caja):")
	fabricada_label.place(x=100, y=150)
	fabricada_entry = ttk.Entry(ventana_produccion, width=5, textvariable = fabricada)
	fabricada_entry.place(x=250, y= 150)
	merma = tk.IntVar()
	merma_label = ttk.Label(ventana_produccion, text = "Merma:")
	merma_label.place(x=350, y=150)
	merma_entry = ttk.Entry(ventana_produccion, width=5, textvariable = merma)
	merma_entry.place(x=400, y= 150)

	min_prog = tk.IntVar()
	min_prog_label = ttk.Label(ventana_produccion, text = "Minutos Programados:")
	min_prog_label.place(x=100, y=200)
	min_prog_entry = ttk.Entry(ventana_produccion, width=5, textvariable = min_prog)
	min_prog_entry.place(x=250, y= 200)
	min_parado = tk.IntVar()
	min_parado_label = ttk.Label(ventana_produccion, text = "Minutos Parado:")
	min_parado_label.place(x=300, y=200)
	min_parado_entry = ttk.Entry(ventana_produccion, width=5, textvariable = min_parado)
	min_parado_entry.place(x=400, y= 200)

	fecha = tk.StringVar()
	fecha_label = ttk.Label(ventana_produccion, text = "Fecha (dd/mm/aaaa):")
	fecha_label.place(x=100, y=250)
	fecha_entry = ttk.Entry(ventana_produccion, width=10, textvariable = fecha)
	fecha_entry.place(x=220, y= 250)

	supervisor = tk.StringVar()
	supervisor_label = ttk.Label(ventana_produccion, text = "Supervisor:")
	supervisor_label.place(x=100, y=300)
	supervisor_entry = ttk.Entry(ventana_produccion, width=10, textvariable = supervisor)
	supervisor_entry.place(x=200, y= 300)

	volver = ttk.Button(ventana_produccion, text="Volver", command=volver_fun)
	volver.place(x=100, y=350)
	calcular = ttk.Button(ventana_produccion, text="Calcular", command= lambda :calcular_fun(min_prog.get(), min_parado.get(), merma.get(), fabricada.get(), codigo.get(), linea.get()))
	calcular.place(x=200, y=350)
	salir = ttk.Button(ventana_produccion, text="Salir", command=salir_fun)
	salir.place(x=300, y=350)

def segunda_ventana():
	"""Crear segunda ventana"""
	global ventana_bienvenida
	ventana_bienvenida = tk.Tk()
	boton_ingreso_produccion = ttk.Button(ventana_bienvenida, text="Ingreso Producción", command=tercera_ventana)
	ventana_bienvenida.title("Instructivo de Rendimiento de Producción")
	texto = ttk.Label(ventana_bienvenida, text = txt)
	texto.grid(column=0, row=0)
	descripcion = ttk.Label(ventana_bienvenida, text = des)
	descripcion.grid(column=0, row=1)
	boton_ingreso_produccion.grid(column=0, row=2)

def login():
	"""Comprueba si el usuario y contraseña son correctos"""
	#clave y usurio iguales a CLAVE y USUARIO linea 7 y 8
	if usuario_.get() == USUARIO and clave_.get()== CLAVE:
		segunda_ventana()
		ventana_ingreso.destroy()
		
	else:
		print("ERROR!!!")
		msg.showerror("ERROR", "Nombre de usuario y/o contraseña incorrecta")

def limpiar_caja():
	"""PAra boton limpiar: borrar informacion"""
	nombre_usuario.delete(0, 'end')
	clave_usuario.delete(0, 'end')


def primera_ventana():
	"""Funcion para Primera ventana"""
	global ventana_ingreso
	ventana_ingreso = tk.Tk()
	ventana_ingreso.geometry("800x200")
	#icono de la primera ventana
	p1 = ImageTk.PhotoImage(file = 'logo.ico') 
	ventana_ingreso.iconphoto(False,p1)
	#imagen de ienvenida
	background_image=ImageTk.PhotoImage(Image.open("logo.jpeg"))
	background_label = tk.Label(ventana_ingreso, image=background_image)
	background_label.place(x=400, y=30)


	ventana_ingreso.title("Ingreso de operario")
	global usuario_
	usuario_ = tk.StringVar()
	usuario = ttk.Label(ventana_ingreso, text = "ingrese usuario")
	usuario.place(x=100, y=50)
	global nombre_usuario
	nombre_usuario = ttk.Entry(ventana_ingreso, width=20, textvariable = usuario_)
	nombre_usuario.place(x=200, y=50)

	global clave_
	clave_ = tk.StringVar()
	clave = ttk.Label(ventana_ingreso, text = "ingrese clave")
	clave.place(x=100, y=100)
	global clave_usuario
	clave_usuario = ttk.Entry(ventana_ingreso, width=20, textvariable = clave_, show="*")
	clave_usuario.place(x=200, y=100)

	ingresar = ttk.Button(ventana_ingreso, text="INGRESAR", command=login)
	ingresar.place(x=100, y=150)
	limpiar = ttk.Button(ventana_ingreso, text="LIMPIAR", command=limpiar_caja)
	limpiar.place(x=200, y=150)
	ventana_ingreso.mainloop()

primera_ventana()