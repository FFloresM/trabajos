def f(x,y):
    return (x+10)**2 + (y-10)**3

def promedio(it):
    return sum(it) / len(it)

n = int(input(" n "))
M = ([0]*n)*n
    
for i in range(n):
    for j in range(n):
        M[i][j] = f(i,j)

print(M)

promF = []
promC = []
for i in range(n):
    promF.append(promedio(M[i]))

for i in range(n):
    aux = []
    for j in range(n):
        aux.append( M[j][i] )
    promC.append(aux)

print("fila con promedio mayor: " ,promF.index(max(promF)))
print("columna con promedio menor: " ,promC.index(min(promC)))

