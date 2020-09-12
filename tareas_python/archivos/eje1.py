lista_vocales = ['a', 'e', 'i', 'o', 'u']
consonantes = 0
vocales = 0

with open('ex') as f:
	for line in f:
		for v in line:
			if v.isalpha():
				if v in lista_vocales:
					vocales+=1
				else:
					consonantes+=1

print("cantidad de vocales: {}\ncantidad de consonantes {}".format(vocales,consonantes))


