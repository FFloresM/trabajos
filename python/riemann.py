c0 = float(input("c0: "))
c1 = float(input("c1: "))
c2 = float(input("c2: "))
a = float(input("a: "))
b = float(input("b: "))
dx = float(input("dx: "))

def f(x):
	return c0*x**3 + c1*x**2 + c2*x

n = int((b-a)/dx)
print("n = ",n)
suma = 0
for i in range(1, n):
	suma+=f(i*dx)*dx

print("la integral es ", suma)