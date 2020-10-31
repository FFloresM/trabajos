a1 = int(input("ingrese a1: "))
d = int(input("ingrese d:"))
b1 = int(input("ingrese b1: "))
b2 = int(input("ingrese b2: "))
b3 = int(input("ingrese b3: "))

for i in range(1,1001):
	s = a1 + d*(i-1)
	if s == b1:
		print(b1, "pertenece a la sucesion con n = ", i)
	if s == b2:
		print(b2, "pertenece a la sucesion con n = ", i)
	if s == b3:
		print(b3, "pertenece a la sucesion con n = ", i)