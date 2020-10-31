a1 = int(input("a1: "))
d = int(input("d:"))
b1 = int(input("b1: "))
b2 = int(input("b2: "))
b3 = int(input("b3: "))

n = 1000
i=1
while i<=n:
	s = a1 + d*(i-1)
	if s == b1:
		print(b1, "pertenece a la sucesion, n = ", i)
	elif s == b2:
		print(b2, "pertenece a la sucesion, n = ", i)
	elif s == b3:
		print(b3, "pertenece a la sucesion, n = ", i)
	i+=1