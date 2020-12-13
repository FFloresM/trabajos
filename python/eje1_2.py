a = [[1,1,1], [1,0,5], [2,1,1]]
b = [[1,-2,1],[5,0,5],[-2,1,-2]]
c = [[0,7,-5], [-5, 0, 10], [10, -2, 0]]

aux = []
traspuesta = []
suma = []
for i in range(len(a)):
    aux.append([0]*3)
    traspuesta.append([0]*3)
    suma.append([0]*3)

for i in range(len(a)):
    for j in range(len(a)):
        for k in range(len(a)):
            aux[i][j] += a[i][k] * b[k][j]

for i in range(len(a)):
    fila = []
    for j in range(len(a)):
        fila.append( aux[j][i] )
    traspuesta[i] = fila

for i in range(len(a)):
    for j in range(len(a)):
        suma[i][j] = traspuesta[i][j] + c[i][j]

for i in suma:
    print(i)