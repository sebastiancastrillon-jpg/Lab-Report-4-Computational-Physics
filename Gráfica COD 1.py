import matplotlib.pyplot as plt
import pandas as pd 

#Leemos le archivo csv 
df = pd.read_csv('secuencia_pseudoaleatoria.csv')
df.columns = df.columns.str.strip()  # Eliminar espacios en los nombres de las columnas

#Creamos los indices 
indices = range(len(df))

#Graficamos la seceuncia vs el indice 
plt.plot(df ["Secuencia Normalizada"], marker='o')
plt.title('Secuencia Normalizada vs Índice')
plt.xlabel('Índice')
plt.ylabel('Valor')
plt.grid()
plt.show()

#Graficamos el histograma de la secuencia
plt.hist(df["Secuencia Normalizada"], bins=9, edgecolor='black')
plt.title('Histograma de la Secuencia Normalizada')
plt.xlabel('Valor de la Secuencia')
plt.ylabel('Frecuencia')
plt.grid()
plt.show()

#Graficamos el diagrama de dispersión de la secuencia
x_n = df["Secuencia Normalizada"][:-1]  # Todos los elementos excepto el último
x_n1 = df["Secuencia Normalizada"][1:]  # Todos los elementos excepto el primero

plt.figure(figsize=(8, 5))
plt.scatter(x_n, x_n1, color='r', marker='o')
plt.title('Diagrama de Dispersión de la Secuencia')
plt.xlabel('x_n')
plt.ylabel('x_(n+1)')
plt.grid()
plt.show()