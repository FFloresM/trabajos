def f(x):
	return c0*x**3 + c1*x**2 + c2*x
c0 = float(input("c0 "))
c1 = float(input("c1 "))
c2 = float(input("c2 "))
a = int(input("a "))
b = int(input("b "))
dx = float(input("dx "))

n = int((b-a)/dx)
suma = 0
i=1
while i<n:
	suma+=f(i*dx)*dx
	i+=1
print("La integral de Riemann es ", suma)
	