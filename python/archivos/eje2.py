p = input("ingrese palabra: ")
flag = 0
with open('ex') as f:
	lineas = f.readlines()
	i=0
	while i<len(lineas):
		words = lineas[i].split()
		j=0
		while j<len(words):
			print(words[j])
			if words[j] == p:
				flag = 1
				break
			j+=1
		if flag:
			break
		i+=1
if flag:
	print(p,"SÍ está en el texto")
else:
	print(p,"NO está en el texto")