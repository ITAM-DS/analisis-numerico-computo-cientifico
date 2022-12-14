import utils
import numpy as np
from scipy import optimize

#Archivo de resultados
file = open("./src/test_results.txt", "a")

#Prueba para una parábola
#f(x) = (x-1)^2
def f1(x): return (x - 1)**2

best, coords = utils.simulated_annealing(
    f=utils.parabola(), 
    x=2, 
    T=None, 
    t=utils.annealing_schedule, 
    k_max=1000, 
    temp=100)

#Ahora obtenemos las raices con scipy
grounth_truth = optimize.minimize(f1, x0=0)
diff = np.array([grounth_truth['x'][0] - best[0], f1(grounth_truth['x'][0]) - best[1]])

prompt = "--- Parábola ---\n"
prompt += f"\tSimulated annealing:\t{best}\n"
prompt += f"\tGrounth truth:\t\t{grounth_truth['x'][0], f1(grounth_truth['x'][0])}\n"
prompt += f"\tDiff:\t\t\t{diff}\n"
prompt += f"\tNorma 2:\t\t{np.linalg.norm(diff)}\n\n"

file.write(prompt)
print(prompt)


#Prueba para un coseno
#f(x) = |x| + cos(x)
def f2(x): return np.abs(x) + np.cos(x)

best, coords = utils.simulated_annealing(
    f=utils.cos_x2(), 
    x=2, 
    T=None, 
    t=utils.annealing_schedule, 
    k_max=1000, 
    temp=100)

#Ahora obtenemos las raices con scipy
grounth_truth = optimize.minimize(f2, x0=0)
diff = np.array([grounth_truth['x'][0] - best[0], f1(grounth_truth['x'][0]) - best[1]])

prompt = "--- Cosine ---\n"
prompt += f"\tSimulated annealing:\t{best}\n"
prompt += f"\tGrounth truth:\t\t{grounth_truth['x'][0], f1(grounth_truth['x'][0])}\n"
prompt += f"\tDiff:\t\t\t{diff}\n"
prompt += f"\tNorma 2:\t\t{np.linalg.norm(diff)}\n"

file.write(prompt)
print(prompt)

file.close()