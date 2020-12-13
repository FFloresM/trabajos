def f(x,y):
    return (x+10)**2 + (y-10)**3

def media(lista):
    return sum(lista) / len(lista)

n = int(input("n: "))
Matriz = []

for i in range(n):
    Matriz.append([0]*n)

    
for i in range(n):
    for j in range(n):
        Matriz[i][j] = f(i,j)

print(Matriz)

fila = []
col = []
for i in range(n):
    fila.append(media(Matriz[i]))

for i in range(n):
    aux = []
    for j in range(n):
        aux.append( Matriz[j][i] )
    col.append(aux)

print("fila: " ,fila.index(max(fila)))
print("columna : " ,col.index(min(col)))
