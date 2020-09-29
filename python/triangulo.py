def area_del_triangulo(base, altura):
	return (base * altura)/2

def pedir_datos():
	b = float(input("ingrese base del triangulo: "))
	h = float(input("ingrese altura del triangulo: "))
	return b,h

b, h = pedir_datos()
area_tr = area_del_triangulo(b,h)
print("El área del triángulo es: ", area_tr)