#Importamos las librerias necesarias para trabajar con listas y realizar el respectivo histograma
import numpy as np
import matplotlib.pyplot as plt

#2. Modelo Caótico: Mapeo Tienda de Campaña
#En primera instancia, escogemos los parametros utilizados y una lista donde
#guardaremos cada x adicional

miu = 2
xn = 0.371234
datos_40 = []

#Definimos un ciclo for para obtener un numero aleatorio, teniendo en cuenta
#el modelo
for i in range(40):
    if xn < 0.5:
        xn = miu * xn
    else:
        xn = miu * (1 - xn)
    datos_40.append(xn)

N_40 = len(datos_40)
#Con esto, obtenemos el valor aleatorio despues de 40 iteraciones
print("El valor aleatorio obtenido luego de 40 iteraciones es: ", datos_40[-1])

#Ahora, calculamos la estadistica de los datos obtenidos:

#Convertimos los datos en un Array
datos_40 = np.array(datos_40)

#En primer lugar, calculamos el promedio
x_mean_40 = np.mean(datos_40)

#Luego, la varianza
varianza_40 = np.sum((datos_40 - x_mean_40)**2)/N_40

#Finalmente, la asimetria
asimetria_40 = np.sum(((datos_40 - x_mean_40)/(varianza_40)**(1/2))**3)/N_40

#Asi, imprimimos los valores estadisticos:
print("El valor promedio de los datos para 40 iteraciones es: ", x_mean_40)
print("El valor de varianza de los datos para 40 iteraciones es: ", varianza_40)
print("El valor de asimetria de los datos para 40 iteraciones es: ", asimetria_40)


#En segunda instancia, repetimos el procedimiento para 100 iteraciones

miu = 2
xn = 0.371234
datos_100 = []

for i in range(100):
    if xn < 0.5:
        xn = miu * xn
    else:
        xn = miu * (1 - xn)
    datos_100.append(xn)

N_100 = len(datos_100)
print("El valor aleatorio obtenido luego de 100 iteraciones es: ", datos_100[-1])

datos_100 = np.array(datos_100)
x_mean_100 = np.mean(datos_100)
varianza_100 = np.sum((datos_100 - x_mean_100)**2)/N_100
asimetria_100 = np.sum(((datos_100 - x_mean_100)/(varianza_100)**(1/2))**3)/N_100

print("El valor promedio de los datos para 100 iteraciones es: ", x_mean_100)
print("El valor de varianza de los datos para 100 iteraciones es: ", varianza_100)
print("El valor de asimetria de los datos para 100 iteraciones es: ", asimetria_100)


#En tercera instancia, repetimos el procedimiento para 10000 iteraciones

miu = 2
xn = 0.371234
datos_10000 = []

for i in range(10000):
    if xn < 0.5:
        xn = miu * xn
    else:
        xn = miu * (1 - xn)
    datos_10000.append(xn)

N_10000 = len(datos_10000)
print("El valor aleatorio obtenido luego de 10000 iteraciones es: ", datos_10000[-1])

datos_10000 = np.array(datos_10000)
x_mean_10000 = np.mean(datos_10000)
varianza_10000 = np.sum((datos_10000 - x_mean_10000)**2)/N_10000
asimetria_10000 = np.sum(((datos_10000 - x_mean_10000)/(varianza_10000)**(1/2))**3)/N_10000

print("El valor promedio de los datos para 10000 iteraciones es: ", x_mean_10000)
print("El valor de varianza de los datos para 10000 iteraciones es: ", varianza_10000)
print("El valor de asimetria de los datos para 10000 iteraciones es: ", asimetria_10000)


#Con esto, realizamos los histogramas

plt.figure()
plt.hist(datos_40, bins=10)
plt.title("Histograma para 40 iteraciones")
plt.xlabel("Valores")
plt.ylabel("Frecuencia")

plt.figure()
plt.hist(datos_100, bins=10)
plt.title("Histograma para 100 iteraciones")
plt.xlabel("Valores")
plt.ylabel("Frecuencia")

plt.figure()
plt.hist(datos_10000, bins=20)
plt.title("Histograma para 10000 iteraciones")
plt.xlabel("Valores")
plt.ylabel("Frecuencia")

plt.show()