import numpy as np
import matplotlib.pyplot as plt

datos = np.loadtxt("datos.txt")
x = datos[:,0]
yini = datos[:,1]
ymod = datos[:,2]
plt.plot(x,yini, label = "Funcion inicial", c = "m")
plt.plot(x,ymod, label = "Modificada", c = "c")
plt.legend()
plt.xlabel("x")
plt.ylabel("t")
plt.savefig("grafica.pdf")
