"""
cosas = ["hola", 5, 4, [1,2,3,4,5]]
print(cosas)
print(len(cosas))
cosas.append(3)
print(cosas)
print(len(cosas))

print(cosas[3][4])

print(cosas[2:])
print(cosas[:3])


print(cosas)

print(cosas.count("dfsdf"))

print(cosas.index(3))

print(cosas[3].index(1))
"""

diccionario = {"nombres":["pepe", "juan"], "apellidos":["appelido1", "ortiz"]}
print(diccionario)

print(diccionario["nombres"])

print(diccionario.keys())
print(diccionario.values())
diccionario["edades"] = [14, 19, 25]
print(diccionario)

diccionario["nombres"] = ["pedro", "hugo"]
print(diccionario)
diccionario["nombres"].append("Hector")
print(diccionario)

for d in diccionario:
	print(d, diccionario[d])