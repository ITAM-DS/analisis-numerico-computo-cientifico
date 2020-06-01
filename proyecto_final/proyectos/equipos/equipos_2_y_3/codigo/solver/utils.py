import cupy as cp

def inc_index(vec,index,h):
    '''
    Funcion auxiliar para calculo gradiente y hessiano.
    Args:
        vec (array): array de cupy.
        index (int): indice.
        h (float):   cantidad del vec[index] que sera incrementada.
    Returns:
        vec (array): array vec de cupy con vec[index] incrementado con h.
    '''
    vec[index] +=h
    return vec

def dec_index(vec,index,h=1):
    '''
    Funcion auxiliar para calculo gradiente y hessiano.
    Args:
        vec (array): array de cupy.
        index (int): indice.
        h (float):   antidad del vec[index] que sera disminuida.
    Returns:
        vec (array): array vec de cupy con vec[index] disminuida con h.
    '''
    vec[index] -=h
    return vec

def compute_error(x_obj,x_approx):
    '''
    Error absoluto o relativo entre x_obj y x_approx.
    '''
    if cp.linalg.norm(x_obj) > cp.nextafter(0,1):
        Err=cp.linalg.norm(x_obj-x_approx)/cp.linalg.norm(x_obj)
    else:
        Err=cp.linalg.norm(x_obj-x_approx)
    return Err

def norm_residual(feas_primal, feas_dual):
    '''
    Calcula la norma de residuos para el método de punto inicial no factible de Newton
    '''
    return cp.sqrt(cp.linalg.norm(feas_primal)**2 +\
                   cp.linalg.norm(feas_dual)**2
                   )

def condicion_cupy(A):
    '''
    Función que calcula la condición de una matriz para matrices en Cupy
    Args:
      A:  Matriz de cupy
    Return:
      c: Condición de una matriz
    '''
    A_inv = cp.linalg.inv(A)
    NAi = cp.linalg.norm(A_inv)
    NA = cp.linalg.norm(A)
    return NAi*NA

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
    M[0,i]=mu[i]

  # lado derecho de sistema
  b= cp.array([r,1])

  # Resuelve ecuaciones normales
  w_star = cp.linalg.solve(M.transpose()@M,M.transpose()@b)
  
  return w_star