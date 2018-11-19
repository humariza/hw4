import numpy as np
import matplotlib.pylab as plt


ode1= np.genfromtxt('ODES.dat',usecols=0)
ode2= np.genfromtxt('ODES.dat',usecols=1)



pde1= np.genfromtxt('PDES.dat',usecols=0)
pde2= np.genfromtxt('PDES.dat',usecols=1)
