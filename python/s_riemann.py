c0 = float(input("ingrese c0: "))
c1 = float(input("ingrese c1: "))
c2 = float(input("ingrese c2: "))
a = int(input("ingrese a: "))
b = int(input("ingrese b: "))
dx = float(input("ingrese dx: "))

n = int((b-a)/dx)
S = 0

for i in range(1, n):
	S += (c0*(i*dx)**3 + c1*(i*dx)**2 + c2*(i*dx))*dx

print("La suma de Riemann (por la izquierda) es: ", S )