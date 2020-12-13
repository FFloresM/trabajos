A = [[1,1,1], [1,0,5], [2,1,1]]
B = [[1,-2,1],[5,0,5],[-2,1,-2]]
C = [[0,7,-5], [-5, 0, 10], [10, -2, 0]]

D = [[0]*3]*3
T = [[0]*3]*3
suma = [[0]*3]*3

for i in range(3):
    for j in range(3):
        for k in range(3):
            D[i][j] += A[i][k] * B[k][j]

for i in range(3):
    aux = []
    for j in range(3):
        aux.append( D[j][i] )
    T[i] = aux

for i in range(3):
    for j in range(3):
        suma[i][j] = T[i][j] + C[i][j]

for i in suma:
    print(i)