import matplotlib.pyplot as plt

def F(lista):
	S=0
	for i in lista:
		S+=i**2
	return S

def lista(n):
	l = map(int,str(n))
	return list(l)


F_x = []
F_y = []
NF_x = []
NF_y = []
a = int(input("a: "))

for i in range(a):
	v = lista(i)
	f = F(v)
	valores = []
	while True:
		valores.append(f)
		f = lista(f)
		f = F(f)
		if f==1:
			F_x.append(i)
			F_y.append(f)
			break
		elif f in valores:
			NF_x.append(i)
			NF_y.append(f)
			break

plt.plot(F_x,F_y, NF_x,NF_y)
plt.show()