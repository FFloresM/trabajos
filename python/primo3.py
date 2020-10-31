def esPrimo(numero):
    if numero < 1:
        return False
    elif numero == 2:
        return True
    else:
        for i in range(2, numero):
            if numero % i == 0:
                return False
        return True

x = input("ingrese numero de tres digitos: ")
while len(x) != 3:
	x = input("ingrese numero de tres digitos: ")
x = int(x[::-1])

if esPrimo(x):
	print(x, "es primo")
else:
	print(x, "no es primo")
