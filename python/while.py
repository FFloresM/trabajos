n = 1
"""
while n<=10:
	print(n)
	n = n + 1
"""
"""
vocales = ['a', 'e', 'i', 'o', 'u']
#         0    1    2    3    4
i = 0
while i<len(vocales):
	print(vocales[i], end=" ")
	i += 1 # i = i+1

valores = [1,2,3,4,5,6]
i = 0
suma = 0
while i < len(valores):
	suma += valores[i]
	print(suma)
	i += 1
print("La suma es: ", suma)
promedio = suma/len(valores)
print("El promedio es: ", promedio)

"""

valores = [1,2,3,4,5,6]
suma = 0
#for i in valores:
#	suma += i	

for i in range(len(valores)):
	suma += valores[i]
print(suma)


