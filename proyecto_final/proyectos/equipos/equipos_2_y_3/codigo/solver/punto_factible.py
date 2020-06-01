import cupy as cp
def feasible_markowitz(r,mu):
  '''
  Funcion que devuelve un punto factible del problema de Markowitz, resolviendo
  las ecuaciones normales asociadas
  Args:
     r (float): real positivo, que modela rendimiento esperado por inversionista
     mu (aray): array de cupy que contiene los valores medios de los rendimientos
          de los activos en el portafolio
  Return:
     w_star (float): punto feasible del problema de Markowitz
  '''
  # matriz del sistema para ecuaciones normales
  M = cp.ones((2,mu.shape[0]))

  for i in range(mu.shape[0]):
    M[0,i]=mu[i,0]

  # lado derecho de sistema
  b= cp.array([r,1])

  # Resuelve ecuaciones normales
  w_star = cp.linalg.solve(M.transpose()@M,M.transpose()@b)
  
  return w_star