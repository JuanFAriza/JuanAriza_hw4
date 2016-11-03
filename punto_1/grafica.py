import numpy as np
import matplotlib.pyplot as plt
import csv

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

V = np.array(medidas[0:250],dtype='float')
Ex = np.array(medidas[250:500],dtype='float')
Ey = np.array(medidas[500:],dtype='float')

archivo = 'placas.pdf'
