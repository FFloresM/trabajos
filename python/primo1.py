while True:
	numero = int(input("numero de tres cifras: "))
	if numero > 99 and numero<=999: 
		break
numero = int(str(numero)[::-1])

esPrimo = 1
i=2
while i<numero:
	if numero % i == 0:
		esPrimo = 0
	i+=1

if esPrimo:
	print(numero, "es primo")
else:
	print(numero, "no es primo")