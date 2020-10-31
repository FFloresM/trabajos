
while 1:
	n = input("ingrese numero de tres digitos: ")
	if len(n) == 3: 
		break
n = int(n[::-1])

primo = True
for i in range(2, n):
	if n % i == 0:
		primo =  False

if primo:
	print("el número ",n, "es primo")
else:
	print("el número ",n, "no es primo")