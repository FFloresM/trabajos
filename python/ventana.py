import tkinter as tk
from tkinter import ttk
from tkinter import Menu
from tkinter import messagebox as msg

#crear una instancia
ventana = tk.Tk()

#agregar titulo a la ventana
ventana.title("GUI en python")
#etiqueta
etiqueta = ttk.Label(ventana, text="Ingrese su nombre y apellido")
etiqueta.grid(column=0, row=0)

etiqueta2 = ttk.Label(ventana , text="ingrese Operación")
etiqueta2.grid(column=2, row=0)

etiqueta3 = ttk.Label(ventana)
etiqueta3.grid(column=0, row=4)

def click():
	#etiqueta3.configure(text="Hola "+ nombre.get()+" tienes "+edad.get()+" años.")
	#msg.showinfo("Esto es un mensaje de información", "Creado con tkinter\n Septiembre 2020")
	etiqueta_patron1.configure(text="señal Buffer 7 mV")
	
	
	text_patron1.grid(column=0, row=4)
	
	
	boton1.grid(column=3, row=4)


#boton
boton = ttk.Button(ventana, text="ACEPTAR", command=click)
boton.grid(column=3, row=1)
#agregar un text box 
nombre_apellido = tk.StringVar()
operacion = tk.StringVar()
nombre_text_box = ttk.Entry(ventana, width=25, textvariable=nombre_apellido)
nombre_text_box.grid(column=0, row=1)

#combo box
seleccion_operacion = ttk.Combobox(ventana, width=25, textvariable=operacion)
seleccion_operacion['values'] = ("Revisión sensor pH", "Revisión sensor de oxígeno", "Revisión sensor de conductividad", "Determinación de humedad")
seleccion_operacion.grid(column=2,row=1)
seleccion_operacion.current(0)

#checkbutton
terreno = tk.IntVar()
check1 = tk.Checkbutton(ventana, text="Terreno", variable=terreno)
check1.grid(column=0, row=2)

lab = tk.IntVar()
check2 = tk.Checkbutton(ventana, text="Laboratorio", variable=lab)
check2.grid(column=1, row=2)

###Calculo de pH
def hacer_calculo():
	print("calculando.....")
	v1 = (float(patron2.get()) - float(patron1.get()))/3
	v2 = (float(patron3.get()) - float(patron1.get()))/3
	promedio = (v1+(v2*-1))/2
	tol = (promedio/54.16)*100
	if tol >90 and tol>100:
		print("sensor bueno")
	else:
		print("sensor malo, enviar a servicio tecnico")

def click4():
	etiqueta_patron3.configure(text="señal Buffer 10 mV")
	text_patron3.grid(column=2, row=4)
	if patron3.get().isnumeric():
		patron3_valor = float(patron3.get())*-1
		#print(type(patron1_valor), patron1_valor)
		if patron3_valor > -210 and patron3_valor < -150:
			hacer_calculo()
		else:
			msg.showinfo("Advertencia", "Sensor dañado, envíe a servicio técnico.")

	else:
		msg.showinfo("ERROR", "Tiene que ingresar un número en señal Buffer 10 mV")

def click3():
	etiqueta_patron2.configure(text="señal Buffer 4 mV")
	text_patron2.grid(column=1, row=4)
	if patron2.get().isnumeric():
		patron2_valor = float(patron2.get())
		#print(type(patron1_valor), patron1_valor)
		if patron2_valor > 150 and patron2_valor < 210:
			click4()
		else:
			msg.showinfo("Advertencia", "Sensor dañado, envíe a servicio técnico.")

	else:
		msg.showinfo("ERROR", "Tiene que ingresar un número en señal Buffer 4 mV")


def click2():
	if patron1.get().isnumeric():
		patron1_valor = float(patron1.get())
		#print(type(patron1_valor), patron1_valor)
		if patron1_valor > -30 and patron1_valor < 30:
			click3()
		else:
			msg.showinfo("Advertencia", "Sensor dañado, envíe a servicio técnico.")

	else:
		msg.showinfo("ERROR", "Tiene que ingresar un número")


boton1 = ttk.Button(ventana, text="aceptar", command=click2)


etiqueta_patron1 = ttk.Label(ventana)
etiqueta_patron1.grid(column=0, row=3)
patron1 = tk.StringVar() #-30 y +30
text_patron1 = ttk.Entry(ventana, width=25, textvariable=patron1)


etiqueta_patron2 = ttk.Label(ventana)
etiqueta_patron2.grid(column=1, row=3)
patron2 = tk.StringVar() #150 a 210
text_patron2 = ttk.Entry(ventana, width=25, textvariable=patron2)


etiqueta_patron3 = ttk.Label(ventana)
etiqueta_patron3.grid(column=2, row=3)
patron3 = tk.StringVar()
text_patron3 = ttk.Entry(ventana, width=25, textvariable=patron3)

"""
def radiofun():
	val = radiovar.get()
	if val == 1:
		ventana.configure(background="red")
	elif val == 2:
		ventana.configure(background="green")
	elif val == 3:
		ventana.configure(background="blue")

#radiobutton
radiovar = tk.IntVar()
radio1 = tk.Radiobutton(ventana, text="rojo", variable=radiovar, value=1, command=radiofun)
radio1.grid(column=0,row=3)
radio2 = tk.Radiobutton(ventana, text="verde", variable=radiovar, value=2, command=radiofun)
radio2.grid(column=1,row=3)
radio3 = tk.Radiobutton(ventana, text="azul", variable=radiovar, value=3, command=radiofun)
radio3.grid(column=2,row=3)
"""
#crear menu
barra_menu = Menu(ventana)
ventana.config(menu=barra_menu)

#agregar un item al menu
archivo_menu = Menu(barra_menu)
archivo_menu.add_command(label="Nuevo")
barra_menu.add_cascade(label="Archivo", menu=archivo_menu)

#dialog box




#ejecutar
ventana.mainloop()

