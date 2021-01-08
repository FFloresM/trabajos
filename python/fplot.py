import matplotlib.pyplot as plt
def toList(number):
	number = str(number)
	return list(map(int,number))


def F(v):
	suma=0
	for i in v:
		suma+=i**2
	return suma

xF = []
yF = []
xNF = []
yNF = []
a = int(input("a: "))

for i in range(a+1):
	x = toList(i)
	f = F(x)
	print(f)
	result = []
	while 1:#f != 1 and f not in result: 
		result.append(f)
		f = toList(f)
		f = F(f)
		if f==1:
			xF.append(i)
			yF.append(f)
			break
		elif f in result:
			xNF.append(i)
			yNF.append(f)
			break
print('F', xF, yF)
print('NF', xNF, yNF)
plt.plot(xF,yF, xNF,yNF)
plt.show()