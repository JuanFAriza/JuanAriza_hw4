import numpy as np
import matplotlib.pyplot as plt
import csv
import os

file = open('datos.dat', 'rt') # Abre el archivo de datos

try:
    lector = csv.reader(file) # Lee el archivo de datos
    datos = []
    for linea in lector: # Agrega cada linea a la lista de datos
        datos.append(linea)
finally:
    file.close()

medidas = []
for dato in datos:
    medida = dato[0]
    a = medida.split(' ') # Separa por espacios los valores de cada linea
    del a[-1]
    medidas.append(a)

x = np.array(medidas[-1],dtype='float')
del medidas[-1]

t = np.array(medidas[-1],dtype='float')
del medidas[-1]

posiciones = np.array(medidas[:len(t)],dtype='float')

A = np.max(posiciones[0])*1.1

def GraficarMovimiento():
    if (os.path.exists("figs_jfariza10_temp")):
        command = 'rm figs_jfariza10_temp -r'
        os.system(command)
    command = 'mkdir figs_jfariza10_temp'
    os.system(command)
    os.chdir('figs_jfariza10_temp')
    
    decimales = int(-np.log10(t[-1]/len(t)))+1
    filenames = ''

    for i in range(len(posiciones)):
        y = posiciones[i].copy()
        fig = plt.figure()
        ax = plt.axes()
        ax.set_xlabel("X")
        ax.set_ylabel("Y")
        ax.set_title("Cuerda de longitud " + format(x[-1]))

        plt.plot(x,y,label="Tiempo " + format(round(t[i],decimales)) + " s")
        plt.ylim(-A,A)
        ax.legend()

        filename = 'fig_temp_' + format(i) + '.png'
        plt.savefig(filename,format='png')
        plt.close()

        filenames = filenames + ' ' + filename
    
    T = 5 # Tiempo que dura cada cuadro en 10^-2 s (1/20)
    command = 'convert -delay ' + format(T) + ' -loop 0 ' + filenames + ' movimiento.gif'
    os.system(command)
    command = 'mv movimiento.gif ..'
    os.system(command)
    os.chdir('..')
    command = 'rm figs_jfariza10_temp -r'
    os.system(command)

GraficarMovimiento()
