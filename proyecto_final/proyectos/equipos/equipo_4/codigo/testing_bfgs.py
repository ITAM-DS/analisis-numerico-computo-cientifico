import numpy as np
import numpy.linalg as ln
import scipy as sp
import scipy.optimize
import pandas as pd
from pytest import approx
###IMPORTACION MODULOS funciones BFGS
from funciones_algoritmo_bfgs import cost
from funciones_algoritmo_bfgs import logit
from funciones_algoritmo_bfgs import score
from funciones_algoritmo_bfgs import bfgs

###Carga de datos
datos = pd.read_csv("../Datos/Stroke_Data.csv")

# Cambiamos los datos a un array de numpy pata poder trabajar con ellos.
datos_array = np.asarray(datos)

# Tomamos la variable objetivo, en este caso, esta es `stroke`
y = datos_array[:, 0].astype('float64')

# Tomamos el resto de las variables como variables explicativas, y agregamos un
# intercepto
X = np.asarray(datos_array[:, 1:]).astype('float64')
intercept = np.ones(X.shape[0]).reshape(X.shape[0], 1)
X = np.concatenate((intercept, X), axis = 1)

print('yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy')

# Optimización con BFGS implementado manualmente
result, _ = bfgs(f = cost,
                 gradiente = score ,
                 x_init = np.ones(10)*0.5)

# Optimización con BFGS a través de scipy
sol_scipy_bfgs = sp.optimize.minimize(fun = cost,
                                      x0 = np.ones(10)*0.5,
                                      method = 'BFGS',
                                      args = (X,y),
                                      jac = score)
print('22222222222222222222222222222222222222')

def test(scipy_bfgs, nuestro_bfgs):
    assert scipy_bfgs == approx(nuestro_bfgs, 1e-6) #

test(sol_scipy_bfgs.x, result)
print('jajajajajajajajajajajajajajaja')
