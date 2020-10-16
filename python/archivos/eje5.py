n = int(input("ingrese n: "))

fila = [1]
y = [0]
with open('triangle.txt', 'w') as t:
	for x in range(n):
		row = " ".join(map(str,fila))+"\n"
		esp = " "*(n-x)
		t.write(esp+row)
		fila=[i+j for i,j in zip(fila+y, y+fila)]

