def f(x,y):
    return (x+10)*(x+10) + (y-10)*(y-10)

def prom(lista):
    return sum(lista)/len(lista)

n = int(input("n:"))
m = []

for i in range(n):
    m.append([0]*n)

    
for i in range(n):
    for j in range(n):
        m[i][j] = f(i,j)

print(m)

fila = []
col = []
for i in range(n):
    fila.append(prom(m[i]))

for i in range(n):
    aux = []
    for j in range(n):
        aux.append( m[j][i] )
    col.append(aux)

print("mayor fila: " ,fila.index(max(fila)))
print("menor columna : " ,col.index(min(col)))