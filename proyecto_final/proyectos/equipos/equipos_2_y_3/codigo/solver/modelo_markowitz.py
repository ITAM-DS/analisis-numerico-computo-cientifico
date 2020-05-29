import cupy as cp
import pandas as pd

def formar_vectores(mu, Sigma):
  '''
  Calcula las cantidades u = \Sigma^{-1}  \mu y v := \Sigma^{-1} \cdot 1 del problema de Markowitz

  Args:
    mu (cupy array, vector): valores medios esperados de activos (dimension n)
    Sigma (cupy array, matriz): matriz de covarianzas asociada a activos (dimension n x n)

  Return:
    u (cupy array, escalar): vector dado por \cdot Sigma^-1 \cdot mu (dimension n)
    v (cupy array, escalar): vector dado por Sigma^-1 \cdot 1 (dimension n)
  '''

  # Vector auxiliar con entradas igual a 1
  n = Sigma.shape[0]
  ones_vector = cp.ones(n)

  # Formamos vector \cdot Sigma^-1 mu y Sigm^-1 1
  # Nota: 
  #   1) u= Sigma^-1 \cdot mu se obtiene resolviendo  Sigma u = mu
  #   2) v= Sigma^-1 \cdot 1 se obtiene resolviendo  Sigma v = 1

  # Obtiene vectores de interes
  u = cp.linalg.solve(Sigma, mu)
  u = u.transpose() # correcion de expresion de array
  v = cp.linalg.solve(Sigma, ones_vector)

  return u , v

def formar_abc(mu, Sigma):
  '''
  Calcula las cantidades A, B y C del diagrama de flujo del problema de Markowitz

  Args:
    mu (cupy array, vector): valores medios esperados de activos (dimension n)
    Sigma (cupy array, matriz): matriz de covarianzas asociada a activos (dimension n x n)

  Return:
    A (cupy array, escalar): escalar dado por mu^t \cdot Sigma^-1 \cdot mu
    B (cupy array, escalar): escalar dado por 1^t \cdot Sigma^-1 \cdot 1
    C (cupy array, escalar): escalar dado por 1^t \cdot Sigma^-1 \cdot mu
  '''

  # Vector auxiliar con entradas igual a 1
  n = Sigma.shape[0]
  ones_vector = cp.ones(n)

  # Formamos vector \cdot Sigma^-1 mu y Sigm^-1 1
  # Nota: 
  #   1) u= Sigma^-1 \cdot mu se obtiene resolviendo  Sigma u = mu
  #   2) v= Sigma^-1 \cdot 1 se obtiene resolviendo  Sigma v = 1

  u, v = formar_vectores(mu, Sigma)

  # Obtiene escalares de interes
  A = mu.transpose()@u
  B = ones_vector.transpose()@v
  C = ones_vector.transpose()@u

  return A, B, C


def delta(A,B,C):
  '''
  Calcula las cantidad Delta = AB-C^2 del diagrama de flujo del problema de Markowitz

  Args:
    A (cupy array, escalar): escalar dado por mu^t \cdot Sigma^-1 \cdot mu
    B (cupy array, escalar): escalar dado por 1^t \cdot Sigma^-1 \cdot 1
    C (cupy array, escalar): escalar dado por 1^t \cdot Sigma^-1 \cdot mu

  Return:
    Delta (cupy array, escalar): escalar dado \mu^t \cdot \Sigma^{-1} \cdot \mu
  '''
  Delta = A*B-C**2

  return Delta


def formar_omegas(r, mu, Sigma):
  '''
  Calcula las cantidades w_o y w_ del problema de Markowitz

  Args:
    r (escalar) : retorno esperado por el inversionista
    mu (cupy array, vector): valores medios esperados de activos (dimension n)
    Sigma (cupy array, matriz): matriz de covarianzas asociada a activos (dimension n x n)

  Return:
    w_0 (cupy escalar, matriz): escalar dado por 
          w_0 = \frac{1}{\Delta} (B \Sigma^{-1} \hat{\mu}- C\Sigma^{-1} 1) 
    w_1 (cupy escalar, vector): escalar dado por 
         w_1 = \frac{1}{\Delta} (C \Sigma^{-1} \hat{\mu}- A\Sigma^{-1} 1)
  '''
  # Obtenemos u = Sigma^{-1} \hat{\mu}, v = \Sigma^{-1} 1
  u, v = formar_vectores(mu, Sigma)
  # Escalares relevantes
  A, B, C = formar_abc(mu, Sigma)
  Delta = delta(A,B,C)
  # Formamos w_0 y w_1
  w_0 = (1/Delta)*(r*B-C)
  w_1 = (1/Delta)*(A-C*r)

  return w_0, w_1

def markowitz(r, mu, Sigma):
  '''
  Calcula las cantidades w_o y w_ del problema de Markowitz

  Args:
    r (escalar) : retorno esperado por el inversionista
    mu (cupy array, vector): valores medios esperados de activos (dimension n)
    Sigma (cupy array, matriz): matriz de covarianzas asociada a activos (dimension n x n)

  Return:
    w (cupy array, vector): vector de pesos que minimizan la varianza del portfolio
  '''
  # Obtenemos u = Sigma^{-1} \hat{\mu}, v = \Sigma^{-1} 1
  u, v = formar_vectores(mu, Sigma)

  # Formamos w_0 y w_1
  w_0, w_1 = formar_omegas(r, mu, Sigma)

  return w_0*u+w_1*v

def markowitz_df(r, mu, Sigma, stocks):
  '''
  Crea data frame de la función markowitz relacionando los pesos con las acciones

  Args:
    r (escalar) : retorno esperado por el inversionista
    mu (cupy array, vector): valores medios esperados de activos (dimension n)
    Sigma (cupy array, matriz): matriz de covarianzas asociada a activos (dimension n x n)
    stocks (lista): Códigos bursátiles de las acciones a evaluar

  Return:
    df (DataFrame): Data Frame con acciones como índices y los pesos ordenados correspondientes
  '''

  aux = markowitz(r, mu, Sigma)
  df =pd.DataFrame( cp.asnumpy(aux), columns = ['pesos'])
  df["stocks"]=stocks
  df = df.sort_values(by=['pesos'], ascending=False)
  return df


