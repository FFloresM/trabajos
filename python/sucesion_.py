a1 = int(input("a1: "))
d = int(input("d:"))
b1 = int(input("b1: "))
b2 = int(input("b2: "))
b3 = int(input("b3: "))

n=1000
S = []
for x in range(1,n+1):
	sucesion = a1 + d*(x-1)
	S.append(sucesion)


if b1 in S:
	print(b1, " n = ", S.index(b1)+1)
if b2 in S:
	print(b2, " n = ", S.index(b2)+1)
if b3 in S:
	print(b3, " n = ", S.index(b3)+1)