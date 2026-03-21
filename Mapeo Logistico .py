#Importamos las librerias necesarias para trabajar con listas y realizar el respectivo histograma
import numpy as np 
import matplotlib.pyplot as plt 

#1. Modelo Caótico: Mapeo Logístico
#En primera instancia, escogemos los parametros utilizados y una lista donde 
#guardaremos cada x adicional

r = 4 
xn = 0.4
datos_50 = []

#Definimos un ciclo for para obtener un numero aleatorio, teniendo en cuenta 
#el modelo
for i in range(50):
    xn = r*xn*(1 - xn)
    datos_50.append(xn)

N_50 = len(datos_50)

print("El valor aleatorio obtenido luego de 50 iteraciones es: ", datos_50[-1])

#Ahora, calculamos la estadistica de los datos obtenidos: 

datos_50 = np.array(datos_50)

#En primer lugar, calculamos el promedio
x_mean_50 = np.mean(datos_50)

#Luego, la varianza 
varianza_50 = np.sum((datos_50 - x_mean_50)**2)/N_50

#Finalmente, la asimetria
asimetria_50 = np.sum(((datos_50 - x_mean_50)/((varianza_50)**(1/2)))**3)/N_50

#Asi, imprimimos los valores estadisticos: 
print("El valor promedio de los datos (50 iteraciones) es: ", x_mean_50)
print("El valor de varianza de los datos (50 iteraciones) es: ", varianza_50)
print("El valor de asimetria de los datos (50 iteraciones) es: ", asimetria_50)



#Ahora repetimos el procedimiento para 10000 iteraciones

r = 4 
xn = 0.4
datos_10000 = []

for i in range(10000):
    xn = r*xn*(1 - xn)
    datos_10000.append(xn)

N_10000 = len(datos_10000)

print("El valor aleatorio obtenido luego de 10000 iteraciones es: ", datos_10000[-1])

datos_10000 = np.array(datos_10000)

x_mean_10000 = np.mean(datos_10000)
varianza_10000 = np.sum((datos_10000 - x_mean_10000)**2)/N_10000
asimetria_10000 = np.sum(((datos_10000 - x_mean_10000)/((varianza_10000)**(1/2)))**3)/N_10000

print("El valor promedio de los datos (10000 iteraciones) es: ", x_mean_10000)
print("El valor de varianza de los datos (10000 iteraciones) es: ", varianza_10000)
print("El valor de asimetria de los datos (10000 iteraciones) es: ", asimetria_10000)



#Con esto, realizamos los histogramas

plt.figure()
plt.hist(datos_50, bins=10)
plt.title("Histograma - 50 iteraciones")
plt.xlabel("Valores")
plt.ylabel("Frecuencia")

plt.figure()
plt.hist(datos_10000, bins=20)
plt.title("Histograma - 10000 iteraciones")
plt.xlabel("Valores")
plt.ylabel("Frecuencia")

plt.show()