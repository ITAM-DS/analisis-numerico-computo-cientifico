import csv
import pandas as pd
import numpy as np
from scipy.optimize import linprog
from scipy.optimize import OptimizeResult
import matplotlib.pyplot as plt
import cvxpy as cp

# Se leen los datos de las matrices y vectores de:
# Incidencias
# Reactancias
# Balance

df = pd.read_csv('incidencias10.csv')
incidencias = df.to_numpy()
incidencias = np.asmatrix(incidencias)

df = pd.read_csv('reactancias10.csv')
costos = df["R"].to_numpy()

df = pd.read_csv('balance10.csv')
b = df["Balance"].tolist()

# Se establecen los límites de las líneas de transmisión
bounds = [(0, None), (0, None), (0, None), (0, None), (0, None), (0, None), (0, None), (0, None), (0, None), (0, None),
          (0, None), (0, None), (0, None), (0, None), (0, None), (0, None), (0, None), (0, None)]

# Optimización con el programa lineal
opt = linprog(c = costos, A_eq = incidencias, b_eq = b, bounds = bounds)
sol_pl = opt.x.tolist()

# Vector de salidas obtenido con el programa comercial
salida_fp = [50.2,10.9,24.8,23.7,53,41.7,132,5.3,24.1,74,10.4,140,35.6,7.9,6,57,84.3,4.5]

# Nomenclatura de las ramas
ramas = ['R1-2','R1-3','R1-5','R1-6','R1-7','R1-10','R2-4','R2-5','R2-8','R3-4','R3-6',
         'R3-7','R3-9','R3-10','R4-6','R4-7','R4-8','R9-10']

# Gráfica de resultados Programa Lineal vs Flujos de Potencia
resultados = pd.DataFrame(list(zip(ramas,sol_pl,salida_fp)), columns = ['ramas','flujo_pl','flujo_fp'])
plt.rcParams["figure.figsize"] = (16, 8)
plt.plot(resultados.ramas,resultados.flujo_pl, label="Programa Lineal")
plt.plot(resultados.ramas,resultados.flujo_fp, label="Flujos de Potencia")

plt.title("Flujos de Potencia obtenidos con los dos modelos",fontsize=15)
plt.xlabel("Ramas",fontsize=13)
plt.ylabel("Flujo en MW",fontsize=13)
plt.legend()
plt.show()