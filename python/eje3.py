n = int(input("n: "))
a = int(input("a: "))
b = int(input("b: "))
coords= []
while n:
    x = list(int(num) for num in input().strip().split())
    if x not in coords:
        coords.append(x)
        n-=1

for i in range(n):
    for j in range(3):
        coords[i][j] = int(coords[i][j])
print(coords)


M = [[a**2, 1, b], [1, (a**2 - b**2), 2*b], [-b, 1, a**2]]
for i in range(n):
    for j in range(n):
        M[1][j] = M[i][j]*(a/b)

print(M)
X = []
Y = []
Z = []
v = 0
todo = []
for i in range(n):
    for j in range(3):
        for k in range(3):
            v += M[j][k]*coords[i][k]
            print(M[j][k], coords[i][k])
        todo.append(v)

print(todo)