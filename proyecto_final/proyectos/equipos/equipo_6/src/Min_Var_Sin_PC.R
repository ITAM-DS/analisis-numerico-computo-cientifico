# //////////////////////////////////////////////////////////////////////////////////////
# Trabajo_MNO
# Equipo 6

# Portafolio de Media-Varianza
# Utilización del método de programación cuadrática

# Portafolio sin posiciones cortas
# Función Portafolio_Optimo
# /////////////////////////////////////////////////////////////////////////////////
# Los inputs son el rendimiento de los activos y el rendimiento establecido por el inversionista

Portfolio_Optimo <- function(Rendimientos_Activos, Rend_Obj)
{ # Obtenemos el número de activos
  n = ncol(Rendimientos_Activos)
  # Determinamos la matriz de covarianzas de los rendimientos
  Dmat = cov(Rendimientos_Activos)
  # Hacemos que el vector 'd' sea de puros ceros para que -d^Tb = 0
  dvec = rep(0, times = n)
  # Definimos la matriz de restricciones
  Amat = t(rbind(Rendimiento = colMeans(Rendimientos_Activos),Presupuesto = rep(1, n),LongOnly = diag(n)))
  # Definimos lo que debe cumplirse: Que el rendimiento sea igual al rendimiento objetivo y que los pesos sumen 1
  bvec = c(Rendimiento = Rend_Obj, Presupuesto = 1, LongOnly = rep(0, times = n))
  # Le decimos a la función que sólo las dos primeras restricciónes son de igualdad
  meq = 2
  # 2 Optimize Weights:
  # La función <solve.QP> imiplementa el método dual de Golfarb & Idnani (1982) para resolver problemas
  # de programación cuadrática (quadratic programming) de la forma 
  # min (-d' * b + 1/2 * b' D * b) con la restricción A' * b >= b_0
  # En la que Dmat es la función objetivo
  # Amat son las restricciones
  # bvec es el equivalente a b_0
  Portfolio = solve.QP(Dmat, dvec, Amat, bvec, meq)
  Pesos = Portfolio$solution
  names(Pesos) = colnames(Rendimientos_Activos)
  # Return Value:
  list(
    Pesos = 100*Pesos,
    Riesgo = Portfolio$value,
    Rendimiento = Rend_Obj)
}

# Cargar las librerías necesarias
library(quadprog)
args(solve.QP)
library(fBasics)
# Obtener los rendimeintos
Rendimientos_Activos = 100 * LPP2005REC[, 1:6]
Rendimientos_Activos
# Verificar los rendimientos
names(Rendimientos_Activos)
# Proponemos como rendimiento objetivo la media de todos los activos del portafolio:
Rend_Obj = mean(colMeans(Rendimientos_Activos))
Rend_Obj
# Optimizamos utilizando la función creada <Portafolio_Optimo>
Portafolio = Portfolio_Optimo(Rendimientos_Activos, Rend_Obj)
Portafolio
# Obtenemos los pesos del portafolio
Pesos = Portafolio$Pesos
Pesos
# Revisamos que la suma de los pesos da 100%
sum(Pesos)
# Revisamos que el rendimiento ponderado coincide con el rendimiento objetivo
Rendimiento_Ponderado = Pesos %*% colMeans(Rendimientos_Activos)
Rendimiento_Ponderado 
