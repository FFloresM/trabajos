color_cantidad = []
marca_color_max = []
marcas = []
marcas_unicas = []
for i in range(1,26):
	filename = 'padron'+str(i)+'.txt'
	file = open(filename, 'r')
	for line in file.readlines():
		partes = line.split(',')
		if partes[2] not in [row[0] for row in color_cantidad]:
			color_cantidad.append([partes[2],1])
		else:
			for row in color_cantidad:
				if row[0] == partes[2]:
					row[1] += 1

		if partes[2] not in [row[0] for row in marca_color_max]:
			marca_color_max.append([partes[2],[partes[1]]])
		
		else:
			for row in marca_color_max:
				if row[0] == partes[2]:
					row[1].append(partes[1])
		if [partes[1]] not in marcas_unicas:
			marcas_unicas.append([partes[1]])

		marcas.append([partes[1], int(partes[3])])


	file.close()

#print(color_cantidad)
#print(marca_color_max)
print('a)')
for i,j in zip(color_cantidad, marca_color_max):
	mas = max(j[1],key=j[1].count)
	v = j[1].count(mas)
	print(i[0], '('+str(i[1])+') max:', v)
	print(mas)
	l = j[1]
	while 1:
		l = list(filter(lambda x: x != mas, l))
		mas = max(l,key=l.count)
		if l.count(mas) == v:
			print(mas)
		else:
			break
		
print('b)')
for i in marcas_unicas:
	anios = []
	for j in marcas:
		if i[0] == j[0]:
			anios.append(j[1])
	i.append(anios)

for l in marcas_unicas:
	print(l[0], '-', max(l[1]),'-', l[1].count(max(l[1])))
	

	
	
	

