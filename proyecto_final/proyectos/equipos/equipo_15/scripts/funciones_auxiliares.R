##########################################################################
# 
# Descripción: funciones auxiliares utilizadas para resolver el problema de
#          optimización descrito por Zibo Yang en el artículo "Online Convex 
#          Optimization for Online Job Scheduling". Las funciones fueron 
#          "traducidas" de MATLAB a R a partir del código proporcionado por
#          Erick Palacios para la materia de MNO.}
# 
# Autores: Juan B. Martínez Parente y Vianney Sánchez Gutiérrez
#          (Mayo 2019)
# 
##########################################################################

gradiente <- function(f, x) {
  # In:
    # f función a la que se le calculará su gradiente
    # x punto en el que se aproximará el gradiente de f
  # Out:
    # grad_f: aproximación al gradiente de f por diferencias centradas
  
  h      <- 1e-6
  n      <- length(x)
  grad_f <- matrix(rep(0, n), nrow = n)
  xaux   <- x
  xaux2  <- x
  
  for(i in 1:n) {
    xaux[i]   <- x[i] + h
    xaux2[i]  <- x[i] - h
    grad_f[i] <- (f(xaux) - f(xaux2)) / (2 * h)
    xaux[i]   <- xaux[i] - h
    xaux2[i]  <- xaux2[i] + h
  }
  
  return(grad_f)

  }

gradiente_rest <- function(f_rest, x_val) {
  # In:
    # f_rest: vector de functions handle que contiene cada una de las funciones de desigualdad
    # x_val: punto a evaluar el gradiente de cada función de restricción de desigualdad
  # Out:
    # gf_rest: aproximación a los gradientes de cada función de restricción de desigualdad
  
  m       <- length(f_rest)
  gf_rest <- 0
  
  for (i in 1:m) {
    f_rest_componente <- f_rest[[i]]
    grad_f_rest_componente_eval <- gradiente(f_rest_componente, x_val)
    # gf_rest <- gf_rest - grad_f_rest_componente_eval / f_rest_componente(x_val)
    # #print(gf_rest)
    gf_rest <- gf_rest - grad_f_rest_componente_eval / as.vector(f_rest_componente(x_val))
  }
  
  return(gf_rest)
  
} 

hessiana <- function(f, x) {
  # In:
    # f función a la que se le calculará su Hessiana
    # x punto en el que se aproximará la Hessiana de f
  # Out:
    # Hf: aproximación a la Hessiana de f por diferencias hacia delante
  
  h      <- 1e-5
  n      <- length(x)
  Hf     <- matrix(rep(0, n*n), nrow = n)
  xaux_i <- x
  xaux_j <- x
  
  for(i in 1:n) {
    xaux_i[i] <- xaux_i[i] + h
    xaux_ij   <- x
    for(j in i:n) {
      xaux_j[j]  <- xaux_j[j] + h
      xaux_ij[j] <- xaux_i[j] + h
      dif1       <- f(xaux_ij) - f(xaux_i) 
      dif2       <- f(xaux_j) - f(x)
      Hf[i,j]    <- (dif1 - dif2) / (h * h)
      if(j != i)
        Hf[j,i]  <- (dif1 - dif2) / (h * h)
      xaux_j[j]  <- xaux_j[j] - h
      xaux_ij[j] <- xaux_ij[j] - h
    }
    xaux_i[i] <- xaux_i[i] - h
  }
  
  return(Hf)
  
}

hessiana_rest <- function(f_rest, x_val) {
  # In:
    # f_rest: vector de functions handle que contiene cada una de las funciones de desigualdad
    # x_val: punto a evaluar el gradiente de cada función de restricción de desigualdad
  # Out:
    # hf_rest: aproximación a la Hessiana de cada función de restricción de desigualdad
  
  m <- length(f_rest)
  hf_rest <- 0
  
  for (i in 1:m) {
    f_rest_componente <- f_rest[[i]]
    gf_rest_componente_eval  <- gradiente(f_rest_componente, x_val)
    hf_rest_componente_eval <- hessiana(f_rest_componente, x_val)
    f_rest_componente_eval <- f_rest_componente(x_val)
    # hf_rest <- hf_rest + gf_rest_componente_eval %*% t(gf_rest_componente_eval) / (f_rest_componente_eval^2) - hf_rest_componente_eval / f_rest_componente_eval
    hf_rest <- hf_rest + gf_rest_componente_eval %*% t(gf_rest_componente_eval) / as.vector(f_rest_componente_eval^2) - hf_rest_componente_eval / as.vector(f_rest_componente_eval)
  }
  
  return(hf_rest)
  
}

barrera_logaritmica <- function(f, f_rest, t, x) {
  # In:
    # f: función objetivo definida como una function handle
    # f_rest: vector de functions handle que contiene cada una de las funciones de restricción desigualdad
    # t: parámetro de barrera
    # x: punto a evaluar la función de barrera logarítmica
  # Out:
    # f_barrera: evaluación de la función de barrera logarítmica en x
  
  suma <- 0
  m <- length(f_rest)
  
  for(i in 1:m) {
  
    f_rest_componente = f_rest[[i]]
    f_rest_componente_eval <- f_rest_componente(x)
    
    if(f_rest_componente_eval >= 0) {
      barrera_componente_eval <- 1e10
    } else {
      barrera_componente_eval <- log(-f_rest_componente_eval+0.0001)
    }
    
    suma <- suma + barrera_componente_eval
    
  }
  
  feval <- f(x)
  f_barrera <- t * feval + suma
  
  return(f_barrera)
  
}

backtracking <- function(alpha, beta, f, f_rest, dir_desc, t0, x, derivada_direccional) {
  # In:
    # alpha, beta parámetros del método por backtracking
    # f función de Rn a R a minimizar
    # dir_desc dirección de descenso en el punto x
    # x punto en el que se buscará el tamaño de paso para la dirección de descenso dada
    # grad_f gradiente de f en x
  # Out: 
    # t tamaño de paso
    # optim
  
  t <- 1
  
  if(alpha > 0.5) {
    print('alpha de backtracking debe ser menor o igual a 1/2')
    t <-  -1
  }
  
  if(beta > 1) {
    print('beta de backtracking debe ser menor a 1')
    t <-  -1
  }
  
  if(t != -1) {
    
    eval1 <- barrera_logaritmica(f, f_rest, t0, x + as.vector(t)*t(dir_desc))
    eval2 <- barrera_logaritmica(f, f_rest, t0, x) + alpha*t*derivada_direccional
    
    while (eval1 > eval2) {
      
      t     <- beta * t
      eval1 <- barrera_logaritmica(f, f_rest, t = t0, x = x + as.vector(t)*t(dir_desc))
      eval2 <- barrera_logaritmica(f, f_rest, t0, x) + alpha*t*derivada_direccional
      
    }
    
  } else { 
    
    t <- -1
    
  }
  
  return(t)
  
}

newton.sin.rest <- function(f, t0, f_rest, x_ast, p_ast, x0, tol, tol_backtracking, maxiter) {
  # Entrada:
    # f: función a encontrar el mínimo. Definida como una function handle
    # x_ast: solución de min f(x) sujeto a: Ax=b.
    # p_ast: valor óptimo de f: p_ast = f(x_ast)
    # x0: aproximaciones iniciales a x_ast (mínimo de f) para los algoritmos
    # tol: para el criterio de paro. Típicamente menor o igual a 1e-8. Controla decremento en x 
    # tol_backtracking: para backtracking. Típicamente menor o igual a 1e-14. Controla actualización de x.
    # maxiter: máximo número de iteraciones a realizar.
  # Salida:
    # x: aproximación a x_ast
    # iter: número de iteraciones realizadas (para gráficas de monitoreo)
    # Err_plot: error medido como error absoluto o relativo respecto a p_ast (para gráficas de monitoreo)
    # x_plot: vector de aproximaciones (para gráficas de monitoreo)
  
  iter <- 1
  x    <- x0
  
  # Evaluaciones
  feval  <- f(x)
  gfeval <- as.vector(t0)*gradiente(f, x) + gradiente_rest(f_rest, x)
  Hfeval <- as.vector(t0)*hessiana(f, x) + hessiana_rest(f_rest, x)
  
  normagf <- norm(gfeval, type = '2')
  condHf <- kappa(Hfeval, exact = TRUE)
  
  if(norm(x_ast, type = '2') > 1e-300) {
    Err <- norm(x_ast - x, type = '2') / norm(x_ast, type = '2')
  } else {
    Err <- norm(x_ast - x, type = '2')
  }
  
  n <- length(x)
  
  alpha <- 0.15 # parámetro para el bactracking
  beta <- 0.5   # parámetro para el bactracking
  
  # Definición decremento en x:
  
  
  dir_Newton <- Solve(Hfeval, -gfeval)
  lambda_cuadrada <- t(dir_Newton) %*% (Hfeval %*% dir_Newton)
  
  # fprintf('Iter      Normagf     Decremento_en_x     Error_x_ast   Error_p_ast    backtracking_result  Condición_Hf\n')
  # fprintf('%3i   %1.6e     %1.6e     %1.6e     %1.6e     %s             %1.6e\n',
  # iter, normagf, lambda_cuadrada, Err, Err_plot_aux[iter], '---', condHf);
  
  criterio_de_paro <- lambda_cuadrada / 2
  contador <- 1
  
  while(abs(criterio_de_paro) > tol & iter < maxiter) {
    derivada_direccional<- -lambda_cuadrada
    
    t <- backtracking(alpha = alpha, beta = beta, f = f, f_rest = f_rest,
                      dir_desc = dir_Newton, t0 = t0, 
                      x = x, derivada_direccional = derivada_direccional)
    
    x       <- x + as.vector(t)*t(dir_Newton)
    feval   <- f(x)
    gfeval  <- as.vector(t0)*gradiente(f, x) + gradiente_rest(f_rest, x)
    Hfeval  <- as.vector(t0)*hessiana(f, x) + hessiana_rest(f_rest, x)
    normagf <- norm(gfeval, type = '2')
    condHf  <- kappa(Hfeval, exact = TRUE)
    
    dir_Newton      <- Solve(Hfeval, -gfeval)
    lambda_cuadrada <- t(dir_Newton) %*% (Hfeval %*% dir_Newton)
    
    if(norm(x_ast, type = '2') > 1e-300) {
      Err <- norm(x_ast - x, type = '2') / norm(x_ast, type = '2')
    } else {
      Err <- norm(x_ast - x, type = '2')
    }
    
    iter <- iter + 1
    
    if(contador %% 1 == 0)
      # fprintf('%3i   %1.6e     %1.6e     %1.6e     %1.6e     %1.6e    %1.6e\n',
      # iter, normagf, lambda_cuadrada, Err, Err_plot_aux[iter], t, condHf);
    
    criterio_de_paro <- lambda_cuadrada / 2
    
    if(t < tol_backtracking) {
      iter_salida <- iter
      iter <- maxiter
    }
    contador <- contador + 1
  }
  
  # fprintf('Error utilizando valor de x_ast: %1.6e\n', Err)
  # fprintf('Valor aproximado a x_ast:\n')
  # print(x)
  
  # helper <- matrix(rep(0, maxiter * n), nrow = n)
  # for(i in 1: ncol(x_plot_aux)) {
  #   helper[,i] <- x_plot_aux[,i] - x_ast
  # }
  
  # if(norm(x_ast, type = '2') > 1e-300) {
  #   aux_diferencia_x_plot_aux <- (helper) / norm(x_ast, type = '2')
  # } else {
  #   aux_diferencia_x_plot_aux <- helper
  # }
  
  
  # index <- which(apply(aux_diferencia_x_plot_aux, 1, function(x) norm(x ,type = '2')) > 1e-300  & rowSums(x_plot_aux) != 0)
  # index2 <- apply(aux_diferencia_x_plot_aux, 1, function(x) norm(x ,type = '2')) > 1e-300 & rowSums(x_plot_aux) != 0
  # 
  # if(sum(index) != 0) {
  #   x_plot[,2:(2+sum(index2)-1)] <- x_plot_aux[,index]
  # }
  
  if(iter == maxiter & t < tol_backtracking) {
    #disp('Valor de backtracking menor a tol_backtracking, revisar aproximación')
    iter <- iter_salida
  }
  
  
  # return(list(x = x, iter = iter, Err_plot = Err_plot, x_plot = x_plot))
  return(list(x = x, iter = iter))
  
} 

path_following <- function(f, f_rest, x_ast, p_ast, x0, 
                           tol_outer_iter, tol_inner_iter, tol_backtracking, 
                           maxiter_path, maxiter_Newton, mu, j) {
  # Entrada:
    # f: función a encontrar su mínimo. Definida como una function handle
    # f_rest : vector de funciones de desigualdad, definidas como function handle.
    # A y b: matriz y lado derecho del conjunto de restricciones de igualdad del problema
    # de optimización (Ax = b)
    # p_ast: valor óptimo de f: p_ast = f(x_ast)
    # x0: aproximaciones iniciales a x_ast (mínimo de f) para los algoritmos
    # tol_outer_iter: para el criterio de paro. Típicamente menor o igual a 1e-6.
    # Controla outer iterations
    # tol_inner_iter: para el criterio de paro. Típicamente menor o igual a 1e-5.
    # Controla decremento de Newton de la función de barrera logarítmica en x 
    # tol_backtracking: para backtracking. Típicamente menor o igual a 1e-14. Controla actualización de x.
    # maxiter_path: máximo número de iteraciones a realizar para el método path following, "outer iterations"
    # maxiter_Newton: máximo número de iteraciones a realizar para el método de Newton, "inner iterations"
    # mu: valor mayor a uno. Factor que incrementa t_barrera.
  # Salida:
    # x aproximación a x_ast
    # iter_barrera: número de iteraciones del método Metodo_path_following
    # t_barrera: valor del parámetro de barrera al finalizar las inner iterations
  
  f_rest_eval <- bind_rows(map(f_rest, ~.(x0)))
  
  if(sum(f_rest_eval >= 1e-300) < 1 ) { # todas las restricciones son menores o iguales que cero
    if(mu > 1) {
      disp('                                          ')
      disp('                                          ')
      disp('------------------------------------------')
      print('Iniciando metodo path following')
      print(paste0('Tiempo: ', j))
      m  <-  length(f_rest_eval)
      t0 <-  m/abs(f(x0) - p_ast) # otra opción: t0 = mu*m/(f(x0)-p_ast);
      t <-  t0
      x <-  x0
      
      criterio_de_paro <- m/t
      outer_iter <- 1
      #print('Outer iterations del método path following')
      #fprintf('Valor de mu: %1.6e\n', mu)
      #fprintf('Outer_iter  f_barrera_log   t_barrera    criterio_de_paro\n')
      #fprintf('%i       -----           %1.6e            %1.6e\n', outer_iter, t, criterio_de_paro)
      disp('------------------------------------------')
      iter_barrera <-  0
      
      while(criterio_de_paro > tol_outer_iter & outer_iter < maxiter_path) {
        resp_newton <- newton.sin.rest(f, t, f_rest, #A, b,
                                       x_ast, p_ast, x, 
                                       tol_inner_iter,
                                       tol_backtracking, maxiter_Newton)
        
        x           <- resp_newton$x
        iter        <- resp_newton$iter
        Err_plot    <- resp_newton$Err_plot
        x_plot      <- resp_newton$x_plot
        f_rest_eval <-  bind_rows(map(f_rest, ~.(x0)))
        
        if(sum(f_rest_eval > 1e-300) >= 1) {
          print('Alguna de las desigualdades se hizo mayor o igual que cero, revisar aproximaciones')
        }
        
        t <- mu*t
        outer_iter <- outer_iter + 1
        criterio_de_paro <- m/t
        # print('Outer iterations del método path following')
        # fprintf('Outer_iter  f_barrera_log   t_barrera    criterio_de_paro\n')
        # fprintf('%i       -----           %1.6e            %1.6e\n', outer_iter, t, criterio_de_paro)
        # print('------------------------------------')
        iter_barrera <- iter_barrera + 1
      }
      
      t_barrera <- t
      
    } else {
      print('valor de mu debe ser mayor a uno, típicamente se elige entre 10 y 100')
    }
    
    
  } else {
    print('Alguna de las restricciones es mayor o igual que cero, revisar aproximaciones')
    x            <-  x0
    iter_barrera <- ''
    t_barrera    <- ''
  }
  
  return(list(x = x, iter_barrera = iter_barrera, t_barrera = t_barrera))
  
}

