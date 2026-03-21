import matplotlib.pyplot as plt
import pandas as pd

#Leemos el archivo csv
df = pd.read_csv('datos_mapeo_tienda_campana.csv')
df.columns = df.columns.str.strip()

#Graficamos el histograma de los datos para 40 iteraciones
plt.figure()
plt.hist(df["Datos 40 iteraciones"].dropna(), bins=10, edgecolor='black')
plt.title('Histograma - 40 iteraciones')
plt.xlabel('Valores')
plt.ylabel('Frecuencia')
plt.grid()

#Graficamos el histograma de los datos para 100 iteraciones
plt.figure()
plt.hist(df["Datos 100 iteraciones"].dropna(), bins=10, edgecolor='black')
plt.title('Histograma - 100 iteraciones')
plt.xlabel('Valores')
plt.ylabel('Frecuencia')
plt.grid()

#Graficamos el histograma de los datos para 10000 iteraciones
plt.figure()
plt.hist(df["Datos 10000 iteraciones"].dropna(), bins=20, edgecolor='black')
plt.title('Histograma - 10000 iteraciones')
plt.xlabel('Valores')
plt.ylabel('Frecuencia')
plt.grid()

plt.show()