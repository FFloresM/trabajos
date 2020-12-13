A = [[1,1,1], [1,0,5], [2,1,1]]
B = [[1,-2,1],[5,0,5],[-2,1,-2]]
C = [[0,7,-5], [-5, 0, 10], [10, -2, 0]]

aux = []
T = []
suma = []
for i in range(len(A)):
    aux.append([0,0,0])
    T.append([0,0,0])
    suma.append([0,0,0])

for i in range(len(A)):
    for j in range(len(A)):
        for k in range(len(A)):
            aux[i][j] += A[i][k] * B[k][j]

for i in range(len(A)):
    aux0 = []
    for j in range(len(A)):
        aux0.append( aux[j][i] )
    T[i] = aux0

for i in range(len(A)):
    for j in range(len(A)):
        suma[i][j] = T[i][j] + C[i][j]

for i in suma:
    print(i)