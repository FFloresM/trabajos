import matplotlib.pyplot as plt
import numpy as np

def f(a,alfa):
	x = a*(np.cos(alfa) + alfa*np.sin(alfa))
	y = a*(np.sin(alfa) - alfa*np.cos(alfa))
	return x,y 

alfa1= int(input("alfa 1: "))
alfa2= int(input("alfa 2: "))
a = int(input("a: "))

alfa = np.arange(alfa1, alfa2, 0.1)

x, y = f(a, alfa)

print(x, y)  
plt.plot(x, y)
plt.show()