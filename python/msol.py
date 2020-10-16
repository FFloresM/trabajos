def evaluar_utilidad(paneles, termos, inv):
	t_panes = sum(paneles)
	t_termos = sum(termos)

	return t_panes + t_termos - inv

def mostrar_mayores(arr):
	return max(arr)

def menu():
	saludo = "Bienvenido a MSOL"
	op = "ingrese una opción"
	op1 = "1 -> ingresar venta paneles"
	op2 = "2 -> ingresar venta termos"
	op3 = "3 -> Evaluar utilidad"
	op4 = "4 -> mostrar mayores ventas"
	q = "q -> para salir"

	print(saludo)
	print(op)
	print(op1)
	print(op2)
	print(op3)
	print(op4)
	print(q)

def opcion(pan, ter, m, inv):
	while(1):	
		op = input("> ")

		if op == '1':
			for i in m:
				s = "ingrese venta mes "+i+" "
				pan.append(int(input(s)))
			menu()
		elif op == '2':
			for i in m:
				s = "ingrese venta mes "+i+" "
				ter.append(int(input(s)))
			menu()
		elif op == '3':
			if len(pan) > 0 and len(ter) > 0:
				util = evaluar_utilidad(pan, ter, inv)
				print("La utilidad anual es: ",util)
			
			else:
				continue
			menu()
		elif op == '4':
			may_pan = pan.index(mostrar_mayores(pan))
			may_ter = ter.index(mostrar_mayores(ter))
			print("el mes de ",m[may_pan], 'se vendio más paneles')
			print("el mes de ",m[may_ter], 'se vendio más termos')
			menu()
		elif op == 'q' or op == 'Q':
			print("Adios!")
			break
		else:
			print("ingrese una opción correcta")
			menu()


paneles12 = []
termos12 = []
meses = ['enero', 'febrero', 'marzo', 'abril', 'mayo', 'junio','julio', 'ago', 'sep', 'oct', 'nov', 'dic']
inv = int(input("ingrese inversión: "))
menu()
opcion(paneles12, termos12, meses, inv)
