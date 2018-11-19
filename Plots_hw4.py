import numpy as np
import matplotlib.pylab as plt


ode1= np.genfromtxt('ODE.txt',usecols=0)
ode2= np.genfromtxt('ODE.txt',usecols=1)
plt.figure()
plt.plot(ode1[1:],ode2[1:])
plt.show()

angulos1=np.genfromtxt('ODESANGULOS.txt',usecols=0)
angulos2=np.genfromtxt('ODESANGULOS.txt',usecols=1)


grados10x=angulos1[1:4000]
grados10y=angulos2[1:4000]

grados20x=angulos1[4001:8000]
grados20y=angulos2[4001:8000]

grados30x=angulos1[8001:12000]
grados30y=angulos2[8001:12000]

grados40x=angulos1[12001:16000]
grados40y=angulos2[12001:16000]

grados50x=angulos1[16001:20000]
grados50y=angulos2[16001:20000]

grados60x=angulos1[20001:24000]
grados60y=angulos2[20001:24000]

grados70x=angulos1[24001:28000]
grados70y=angulos2[24001:28000]
plt.figure()
plt.plot(grados10x,grados10y,label="10º")
plt.plot(grados20x,grados20y,label="20º")
plt.plot(grados30x,grados30y,label="30º")
plt.plot(grados40x,grados40y,label="40º")
plt.plot(grados50x,grados50y,label="50º")
plt.plot(grados60x,grados60y,label="60º")
plt.plot(grados70x,grados70y,label="70º")
plt.ylim(0,10)
plt.legend()
plt.grid()
plt.show()

