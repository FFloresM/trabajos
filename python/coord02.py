import matplotlib.pyplot as plt
import numpy as np

def X(a,alfa):
	x = a*(np.cos(alfa) + alfa*np.sin(alfa))
	return x

def Y(a,alfa):
	y = a*(np.sin(alfa) - alfa*np.cos(alfa))
	return y 

al1= int(input("alfa1: "))
al2= int(input("alfa2: "))
a = int(input("a: "))

alfa = np.arange(al1, al2, 0.1)

x = X(a, alfa)
y = Y(a,alfa)

print(x, y)  
plt.plot(x, y)
plt.show()