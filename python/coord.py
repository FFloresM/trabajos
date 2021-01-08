import numpy as np
import matplotlib.pyplot as plt
a = 2

def f(alpha):
	return a*(np.cos(alpha) + alpha*np.sin(alpha)), a*(np.sin(alpha) - alpha*np.cos(alpha))
#x = a*(np.cos(alpha) + alpha*np.sin(alpha))
#y = a*(np.sin(alpha) - alpha*np.cos(alpha))
a = float(input("ingrese a: "))
alpha1= float(input("alpha 1: "))
alpha2= float(input("alpha 2: "))

alpha = np.arange(alpha1, alpha2, 0.1)

x_, y_ = f(alpha)

print(x_, y_)  
plt.plot(x_, y_)
plt.show()
