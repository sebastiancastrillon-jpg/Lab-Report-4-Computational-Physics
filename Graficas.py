import numpy as np
import matplotlib.pyplot as plt

# ==========================================
# LEER LOS DATOS
# ==========================================

data = np.loadtxt("mt_random.txt")

# ==========================================
# CREAR PARES SUCESIVOS
# (x_i , y_i) = (r_(2i-1), r_(2i))
# ==========================================

x = data[0::2]
y = data[1::2]

# Igualar tamaños
n = min(len(x), len(y))

x = x[:n]
y = y[:n]

# ==========================================
# GRAFICAR
# ==========================================

plt.figure(figsize=(6,6))

plt.plot(x, y, '.', markersize=2)

plt.xlabel(r"$r_{2i-1}$")
plt.ylabel(r"$r_{2i}$")

plt.title("Successive pairs - Mersenne Twister")

plt.grid()

# Guardar figura
plt.savefig("mt_pairs.png", dpi=300)

print("Figure saved as mt_pairs.png")