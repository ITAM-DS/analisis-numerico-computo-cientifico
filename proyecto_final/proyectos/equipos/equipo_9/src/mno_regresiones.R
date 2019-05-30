## Valuación de opciones Americanas

library(MASS)
library(dplyr)
library(ggplot2)
library(purrr)


# Funciones

# ---------------------------------------------------------------------------- #
# payoff_call: Calcula opción CALL
# ---------------------------------------------------------------------------- #
payoff_call <- function(x,K){
  # Recive 2 valores (precios)
  # Si x > K: retorna la diferencia (x-K)
  # Si x < K: retorna 0
  (x-K + abs(x-K))/2
}

# ---------------------------------------------------------------------------- #
# payoff_put: Calcula opción PUT
# ---------------------------------------------------------------------------- #
payoff_put <- function(x,K){
  # Recive 2 valores (precios)
  # Si x < K: retorna la diferencia (x-K)
  # Si x > K: retorna 0
  (K-x + abs(K-x))/2
}

# ---------------------------------------------------------------------------- #
# func_betas: Resuelve sistemas de ecuaciones:
# ---------------------------------------------------------------------------- # 
func_betas <- function(x,vp){
  # Resuelve sistema de ecuaciones
  # en caso de excepcion cambia de método
  tryCatch(
    expr = {
      solve(t(x)%*%x, t(x)%*%vp)  
    },
    error = function(e){
      ginv(t(x)%*%x) %*% t(x)%*%vp
    }
  )
}

# ---------------------------------------------------------------------------- #
# estrategias: Determinal el tiempo de paro para cada trayectoria:
# ---------------------------------------------------------------------------- # 
estrategias <- function(m, r){
  #----------[ Parametros:
  # m - matriz con preciós
  # r - tasa libre de riesgo
  #----------].
  
  # Para cada fila obtengo el indice del 1er. valor > 0, si el registro contiene todos 0's retorna 0:
  ids <- unlist(lapply(apply(m[,-1], 1, function(x) which(x>0)), function(l) ifelse(length(l)>0, l[[1]],0) ))
  # Genero lista de la cantidad de registros:
  pos <- m[,1]
  # Armo matriz con Posición + ID ibtenido en el 1er. paso facilitar el recorrido de los datos:
  ids_m <- data.frame(sim=pos, ids=ids)
  # Recorro la matriz original y para cada pos. tomo el valor del ID y calculo el precio:
  vps <- matrix(unlist(lapply(pos, function(i) ifelse(ids_m[i,2] > 0, m[ids_m[i,1], ids_m[i,2]+1] * exp(-1*ids_m[i,2]*r), 0))))
  # Retorno matrix con: Posición, ID, VP: 
  ids_m <-  as.data.frame(cbind(ids_m, vps))
  
  return(ids_m)
}

# ---------------------------------------------------------------------------- #
# val_tradicional: Retorna la valuacion tradicional (payoff maximos traidos al presente)
# ---------------------------------------------------------------------------- #
val_tradicional <- function(m, r){
  #----------[ Parametros:
  # m - matriz con preciós
  # r - tasa libre de riesgo
  #----------].
  
  # Para cada fila obtengo el indice del mayor valor:
  ids <- unlist(lapply(apply(m[,-1], 1, function(x) which.max(x)), function(l) l[[1]]))
  # Genero lista de la cantidad de registros:
  pos <- m[,1]
  # Armo matriz con Posición + ID ibtenido en el 1er. paso facilitar el recorrido de los datos:
  ids_m <- data.frame(sim=pos, ids=ids)
  # Recorro la matriz original y para cada pos. tomo el valor del ID y calculo el precio para traer el mayor valor al presete:
  max_vp <- matrix(unlist(lapply(pos, function(i) ifelse(ids_m[i,2] > 0, m[ids_m[i,1], ids_m[i,2]+1] * exp( (-1*ids_m[i,2]*r)/360 ), 0))))
  # Retorno la media de los payoff maximos traidos al presente:
  return(list(val_tradic=mean(max_vp), 
              var_val_tradic=as.numeric(var(max_vp))))
}

# ---------------------------------------------------------------------------- #
# valida_opcion: Caclula el valor de ejecutar una opción (PUT / CALL)
# ---------------------------------------------------------------------------- #
valida_opcion <- function(filename, K=0, r=0.06, tipo_opcion='PUT'){
  #----------[ Parametros:
  # Inputs:
  # - filename: Archivo de precios
  # - r: Tasa libre de riesgo
  # - tipo_opcion: función de payoff_call o payoff_put
  #
  # Outputs - list():
  # - df_params: 
  ##  - grado: Grado de polinimo utilizado en cada iteración
  ##  - terminos: Cantidad de terminos que utiliza para la matriz de diseño
  ##  - ceros_reg: Cantidad de terminos que se hacen 0 luego de la regresión
  # - K: Precio inicial - Strike
  # - tiempo_paro: Matriz con tiempo de paro par acada trayectoria
  # - precio_amer: Precio opción Americana
  # - var_amer: Varianza opción Americana
  # - precio_eur: Precio opción Europea 
  # - var_eur: Varianza opción Europea
  # - val_tradic: Valuacion tradicional
  # - var_val_tradic: Varianza Valuacion tradicional
  #----------].
  
  # Cargo datos:
  precios <- read.csv(filename)
  
  # Defino nombre de columna para id de simulación:
  if (colnames(precios)[1] != "sim"){
    colnames(precios)[1] <- "sim"
  }
  
  
  # Precio strike:
  if (K == 0){
    ## Selecciono 180 ids corresponeidntes a filas:
    ids_r <- sample(1:nrow(precios), 180)
    ## Selecciono 1 solumna aleatoriamente (entre las primeras 3)
    id_c <- sample(2:4, 1)
    
    # Si no se indica precio inicial, lo obtengo a partir de una muestra de lss simulaciones:
    K <- mean(as.numeric(precios[ids_r,id_c]), na.rm = TRUE)
  }
  
  # Aplica función de Payoff (Put o Call) a los precios:
  if (tipo_opcion == 'PUT'){
    payoffs <- data.frame(sim=precios$sim, apply(precios[,-1], MARGIN = c(1,2), 
                                                 K = K, 
                                                 FUN = payoff_put))
  }
  else {
    payoffs <- data.frame(sim=precios$sim, apply(precios[,-1], MARGIN = c(1,2), 
                                                 K = K, 
                                                 FUN = payoff_call))
  }

  # Precio de la opción Europea:
  precio_eur <- (mean(payoffs[,ncol(payoffs)], na.rm = TRUE) * exp((-1)*r*0.5))
  var_eur <- (exp((-1)*r)) * var(payoffs[,ncol(payoffs)], na.rm = TRUE)
    
  # Cambio nombres a columnas para que las de Payoff comiencen con "p":
  colnames(payoffs) <- c("sim", paste(rep("p",ncol(payoffs)-1), c(2:ncol(payoffs)-1), sep=""))
  
  # Variables de monioreo:
  terminos <- numeric()   # Cantidad de terminos que utiliza para la matriz de diseño
  ceros_reg <- numeric()  # Cantida de terminos que se convierten en 0 luego de calcular la regresion
  grados <- numeric()
  
  # Carcula regresiones para cada trayectoria:
  for (i in (ncol(precios)-1):2){
    
    # Determina nombres de columnas a procesar:
    ids_precio <- c("sim", paste0("V", i-1))
    ids_payoffs <- c(paste0("p", i-1), paste0("p", i))
    
    # Arma dataframe con columnas a procesar (sim, V_i, p_(i-1), p_i) y valvula VP
    # ademas elimina elimina los registros con Payoff_(i) = 0
    payoff_tmp <- data.frame(precios[ids_precio], payoffs[ids_payoffs]) %>% 
      mutate(vp = exp(-r) * .[[ncol(.)]]) %>% 
      filter(.[ids_payoffs[1]] > 0)
    
    # Actualizo lista con cant. de registros para tener registro de cuantos 
    # terminos se eliminan en cada iteración:
    terminos <- c(terminos, nrow(payoff_tmp))
    
    # Genera dataframe con coeficientes de 0 a 10 par determinar el grado optimo:
    payoff_coef <- payoff_tmp %>% 
      mutate(unos = 1) %>% 
      mutate(!!(paste0(ids_precio[2], "_1")) := .[[ids_precio[2]]]) %>% 
      mutate(!!(paste0(ids_precio[2], "_2")) := .[[ids_precio[2]]]^2) %>% 
      mutate(!!(paste0(ids_precio[2], "_3")) := .[[ids_precio[2]]]^3) %>%
      mutate(!!(paste0(ids_precio[2], "_4")) := .[[ids_precio[2]]]^4) %>% 
      mutate(!!(paste0(ids_precio[2], "_5")) := .[[ids_precio[2]]]^5) %>% 
      mutate(!!(paste0(ids_precio[2], "_6")) := .[[ids_precio[2]]]^6) %>% 
      mutate(!!(paste0(ids_precio[2], "_7")) := .[[ids_precio[2]]]^7) %>% 
      mutate(!!(paste0(ids_precio[2], "_8")) := .[[ids_precio[2]]]^8) %>% 
      mutate(!!(paste0(ids_precio[2], "_9")) := .[[ids_precio[2]]]^9) %>% 
      mutate(!!(paste0(ids_precio[2],"_10")) := .[[ids_precio[2]]]^10)
    
    
    # Resuelve sistema de ecuaciones para calcular el error y determinar el grado:
    sce <- rep(0,10)
    for (j in 6:(ncol(payoff_coef)-1)){
      # En cada iteración se incluye un nuevo termino:
      X <- as.matrix(payoff_coef[,6:(j+1)])
      
      betas <- func_betas(X,payoff_coef[,5])
      
      sce[j-5] <- sum((X%*%betas - payoff_coef[,5])^2)
      
    }
    den <-  nrow(X) - (1:10) - 1
    sce_pol <- sce / den
    # Determino grado optimo - Menor error
    k <- which.min(sce_pol)
    
    # Actualizo lista con nro.  de grado optimo
    grados <- c(grados,k)
    
    # Genera matrix con la cant. de coeficientes determinado por el grado:
    Y <- as.matrix(payoff_coef[,6:(k+5)])
    # Resuelve sistema
    bta <- func_betas(Y,payoff_coef[,5])
    # Caclula VP estimado:
    vp_gorro <- Y%*%bta
    
    # Genero dataframe y valido el Payoff(i) respecto al VP estimado
    # para generar terminos en 0
    ids_y <- payoff_tmp %>% mutate(vp_gorro = vp_gorro) %>%
      mutate(y = if_else(.[ids_payoffs[1]] > vp_gorro, 1,0)) %>%
      filter(y == 0) %>%
      dplyr::select(sim) %>%
      flatten_dbl()
    
    # Actualizo lista con cant. de registros que se convierten en 0:
    ceros_reg <- c(ceros_reg, length(ids_y))
    
    # Convierte en 0 los terminos determinados por las regresiones:
    payoffs[ids_y, ids_payoffs[1]] <- 0
  } 
  
  
  # Determina el tiempo de paro y el precio de la opción:
  tiempo_paro <- estrategias(payoffs, r)
  
  # Determina el valor de los maximos payoff traidos al presente:
  val_tradic <- val_tradicional(payoffs, r)
  
  # Precio:
  precio_amer <- mean(tiempo_paro$vps)
  # Varianza:
  var_amer <- as.numeric(var(tiempo_paro$vps))
  
  
  # grado: Grado de polinimo utilizado en cada iteración
  # terminos: Cantidad de terminos que utiliza para la matriz de diseño
  # ceros_reg: Cantidad de terminos que se hacen 0 luego de la regresión
  df_params <- data_frame(grados=as.factor(grados), terminos=terminos,  ceros_reg=ceros_reg)
  
  # Outputs:
  result <- list(df_params=df_params,          # DF con Grado, Terminos y Ceros:
                 K=K,                         # Precio inicial - Strike
                 tiempo_paro=tiempo_paro,      # Matriz con tiempo de paro par acada trayectoria
                 precio_amer=precio_amer,      # Precio opción Americana
                 var_amer=var_amer,            # Varianza opción Americana
                 precio_eur=precio_eur,        # Precio opción Europea 
                 var_eur=var_eur,              # Varianza opción Europea
                 val_tradic=val_tradic$val_tradic,         # Valuacion tradicional
                 var_val_tradic=val_tradic$var_val_tradic) # Varianza Valuacion tradicional
  return(result)
}
# ---------------------------------------------------------------------------- #