import cupy as cp

def calcular_rendimiento_vector(x):
  """
  Función para calcular el rendimiento esperado

  params:
      x     vector de precios
  
  return:
      r_est rendimiento esperado diario
  """

  # Definimos precios iniciales y finales como arreglo alojado en la gpu
  x_o = cp.asarray(x)
  x_f = x_o[1:]

  # Calculamos los rendimientos diarios
  r = cp.log(x_f/x_o[:-1])

  return r

def calcular_rendimiento(X):
  """
  Función para calcular el rendimiento esperado para un conjunto de acciones

  params:
      X      matriz mxn de precios, donde:
             m es el número de observaciones y
             n el número de acciones
  
  return:
      r_est rvector de rendimientos esperados
  """
  m,n = X.shape
  r_est = cp.zeros(n)
  X = cp.asarray(X)

  for i in range(n):
    r_est[i] = calcular_rendimiento_vector(X[:,i]).mean()

  return 264*r_est

def calcular_varianza(X):

  """
  Función para calcular el la matriz de varianzas y covarianzas para un conjunto de acciones

  params:
      X      matriz mxn de precios, donde:
             m es el número de observaciones y
               n el número de acciones
  
  return:
      S  matriz de varianzas y covarianzas
  """
  m,n=X.shape
  X = cp.asarray(X)

  X_m = cp.zeros((m-1,n))

  for i in range(n):
    X_m[:,i] = calcular_rendimiento_vector(X[:,i]) - calcular_rendimiento_vector(X[:,i]).mean()

  S = (cp.transpose(X_m)@X_m)/(m-2)

  return S


