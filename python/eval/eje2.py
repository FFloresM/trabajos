import matplotlib.pyplot as plt
import math
import numpy as np

x = np.arange(0,5,0.0001)
f = np.cos(5*x+10)
g = np.exp(-(x/3))
idx = np.argwhere(np.diff(np.sign(f - g))).flatten()
plt.plot(x,f,'b-', x,g, 'g-', x[idx],f[idx],'ro')
plt.show()