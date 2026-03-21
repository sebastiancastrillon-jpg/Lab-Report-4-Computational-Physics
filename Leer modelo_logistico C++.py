import matplotlib.pyplot as plt
import pandas as pd

#Leemos el archivo csv
df = pd.read_csv('datos_mapeo_logistico.csv')
df.columns = df.columns.str.strip()

#Graficamos el histograma de los datos para 50 iteraciones
plt.figure()
plt.hist(df["Datos 50 iteraciones"].dropna(), bins=10, edgecolor='black')
plt.title('Histograma - 50 iteraciones')
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
