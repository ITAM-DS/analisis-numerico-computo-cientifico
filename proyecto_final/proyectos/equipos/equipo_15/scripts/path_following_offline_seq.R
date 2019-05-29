##########################################################################
# 
# Descripción: 
# Solución del problema de optimización descrito por Zibo Yang en el artículo 
# "Online Convex Optimization for Online jobs Scheduling" disponible en
# https://pdfs.semanticscholar.org/480a/daf38839240567e82e999b35a8ee7a214d5d.pdf.
# Se da una solución offline del problema utilizando el método de  
# barrera logarítmica basada en parte en el código de Yang, mismo que ya no está
# disponible en el repositorio original, pero sí en el fork
# https://github.com/visagu55/Online-Convex-Optimization-for-Online-Job-Scheduling/blob/master/lkm1.m"
# 
# Autores: Juan B. Martínez Parente y Vianney Sánchez Gutiérrez
#          (Mayo 2019)
# 
##########################################################################

library('limSolve')
library('tidyverse')
library('RColorBrewer')
source('scripts/funciones_auxiliares.R')

colores <- brewer.pal(n = 10, 'Paired')

# ¿Cuántas corridas (simulaciones) queremos hacer?
corridas <- 10
plot1 <- ggplot()
plot2 <- ggplot()

set.seed(815)

for(ej in 1:corridas) {
  
  window   <- 100      # ¿Cuánto tiempo tenemos para analizar el sistema?
  num.jobs <- 10       # Número de tareas simuladas
  lambda   <- 400      # Incremental del problema dual
  
  # Creamos la matriz 'jobs' en la que visualizamos la asignación de recursos.
  # Cada columna representa lo siguiente:
  # 1 ID de la tarea.
  # 2 Tiempo de llegada de la tarea (0 para el caso offline, pues se conocen
  #   de antemano todas las tareas).
  # 3 Tamaño de la tarea: requerimiento en unidades de los recursos solicitados 
  #   por la tarea.
  # 4 Capacidad del CPU que se necesita para ejecutar la unidades solicitada 
  #   por la tarea.
  # 5 Requerimiento de la tarea que ya ha sido completado. Al momento 
  #   de finalizar la ejecución de todas las tareas esta columna idealmente 
  #   sería igual al tamaño de la tarea.
  # 6 Indicadora 0,1 de si la tarea ya ha llegado al sistema. Para el
  #   problema offline se inicializa en cero.
  # 7 Tiempo total que la tarea pasó en el sistema desde que llegó hasta que 
  #   se terminó de ejecutar.
  
  jobs          <- matrix(rep(0, 7*num.jobs), ncol = 7) 
  
  # Matriz para visualizar la asignación en cada instante t
  schedule      <- matrix(rep(0, window*num.jobs), ncol = window)
  
  # flujo de tiempo fraccional que la tarea pasa en el sistema
  fft           <- matrix(rep(0, num.jobs), nrow = 1)   
  
  # Muestra la acumulación del tiempo total pasado por todas las tareas en cada instante t
  ocoflow       <- matrix(rep(0, window), ncol = 1)               
  
  # Simulamos las características de las tareas
  for (i in 1:num.jobs) {
    jobs[i,1]  <- i
    jobs[i, 3] <- (round(runif(1) * 5) + 1) / 2;
    jobs[i, 4] <- round(runif(1), 1)
  }
  
  jobs
  
  
  # Parámetros para el método de path following.
  # (Ignorar x_ast, se declaró porque es usada en la implementación)
  
  x_ast            <- matrix(rep(0, num.jobs), nrow = 1)
  x0               <- matrix(jobs[,3]/(num.jobs*max(jobs[,3])), nrow=1)
  tol_outer_iter   <- 1e-6
  tol_inner_iter   <- 1e-5
  tol_backtracking <- 1e-14
  maxiter_path     <- 30
  maxiter_Newton   <- 30
  mu               <- 10
  j                <- 1
  
  solucion <- list(t_barrera = 'temp')
  
  while(sum(jobs[,3]-jobs[,5] > 0) != 0 & solucion$t_barrera != "") {
    
    for(i in 1:num.jobs) {
      if(jobs[i,2] >= j) {
        fft[1,i] <- 0
        jobs[i,6] <- 0 # not arrive
      } else {
        fft[1,i] <- (j-jobs[i,2]) / jobs[i,3] + 1
        jobs[i,6] <- 1 # arrive
      }
    }
    
    # Función objetivo
    f <- function(x) {
      
      unos <- matrix(rep(1, num.jobs), ncol = 1)
      
      sum(fft * x) +
        lambda * t(jobs[,6]) %*% (t(jobs[,3] - jobs[,5] - x) * (j * unos - jobs[,2])) +
        sum(x*x) / 100
      
    }
    
    # Restricciones (que deben ser actualizadas para cada t)
    f_rest <- list(function(x) sum(jobs[,4] * x) - 1)
    
    for(i in 1:num.jobs) {
      f_rest[[i+1]] <- eval(parse(text = paste0('function(x) x[', i, '] - 1')))
    }
    
    
    for(i in 1:num.jobs) {
      f_rest[[num.jobs+i+1]] <- eval(parse(text = paste0('function(x) -x[', i, ']')))
    }
    
    for(i in which(jobs[,3]-jobs[,5]!=0)) {
      f_rest[[2*num.jobs+i+1]] <- eval(parse(text = paste0('function(x) x[', i, '] - jobs[', i, ',3] + jobs[', i, ',5]')))
    }
    
    
    f_rest[sapply(f_rest, is.null)] <- NULL
    l <- length(f_rest)
    
    kk <- NULL
    if(sum(jobs[,3]-jobs[,5]==0) > 0) {
      kk <- which(jobs[,3]-jobs[,5]==0)
      for(i in 1:sum(jobs[,3]-jobs[,5]==0)) {
        f_rest[[l+i]] <- eval(parse(text = paste0('function(x) x[', kk[i], '] - 0.001')))
      }  
    }
    
    l <- length(f_rest)
    names(f_rest) <- paste0('f', 1:l)
    
    x0 <- matrix(rep(min(jobs[,3]), num.jobs)/30, nrow = 1)
    x0[kk] <- 0.0005
    p_ast = f(x_ast)
    
    # Resolvemos:
    solucion <- path_following(f = f, f_rest = f_rest, x_ast = x_ast, p_ast = p_ast, 
                               x0 = x0, tol_outer_iter = tol_outer_iter,
                               tol_inner_iter = tol_inner_iter,
                               tol_backtracking = tol_backtracking, 
                               maxiter_path = maxiter_path,
                               maxiter_Newton = maxiter_Newton, mu = mu, j = j)
    
    # Se actualiza lo que ya se ha ejecutado de la tarea 
    x0       <- round(solucion$x, 1)
    jobs[,5] <- jobs[,5] + x0
    
    # update lambda
    lambda <- lambda + 5 * t(matrix(jobs[,6], ncol = 1)) %*% (matrix(jobs[,3], ncol = 1) - matrix(jobs[,5], ncol = 1) - t(x0))
    schedule[,j] <- x0
    
    # Tiempo que la tarea pasó en el sistema
    for(i in 1:num.jobs) {
      if(x0[i] > 0) {
        if(jobs[i, 5] >= jobs[i,3]) {
          jobs[i,7] <- j
        }
      }
    }
    
    # Tiempo acumulado
    for(i in 1:num.jobs) {
      if(jobs[i,7] > 0 & jobs[i,7] <= j) {
        ocoflow[j,1] <- ocoflow[j,1] + (jobs[i,7] - jobs[i,2])
      }
    }
    
    print(jobs)
    j <- j +1 
    
    # Si el problema se tornó no factible, interrumpimos la corrida
    if(solucion$t_barrera == '') {
      next
    }
    
    if(sum(jobs[,3]-jobs[,5] > 0) == 0) {
      print('\n---------- Tareas completadas ----------')
    }
    
  }
  
  # Graficamos el tiempo acumulado y el porcentaje de compleción de cada 
  # corrida para comparar
  ocoflow.plot <- data.frame(flow = ocoflow[ocoflow != 0]) %>% 
    mutate(time = 1:nrow(.))
  
  plot1 <- plot1 +
    geom_line(data = ocoflow.plot,
              aes(time, flow),
              color = colores[ej %% corridas + 1], size = 1) +
    theme_light() +
    theme(panel.grid = element_blank())
  
  completion <- schedule %>% as.data.frame() %>% .[,1:nrow(ocoflow.plot)] %>% 
    rownames_to_column('tarea') %>% 
    gather(tiempo, addition, -tarea) %>% 
    mutate(tiempo = parse_number(tiempo),
           tarea = parse_number(tarea)) %>% 
    group_by(tarea) %>% 
    mutate(addition = cumsum(addition)) %>% 
    left_join(data.frame(tarea = jobs[,1], total = jobs[,3]), by = 'tarea') %>% 
    mutate(addition = addition / total) %>% 
    group_by(tiempo) %>% 
    summarise(addition = sum(addition) / num.jobs)
  
  plot2 <- plot2 +
    geom_line(data = completion, aes(tiempo, addition),
              color = colores[ej %% corridas + 1], size = 1) +
    theme_light() +
    theme(panel.grid = element_blank())
  
}

beepr::beep(2)

plot1 + labs(title = 'Ocoflow') +
  labs(title = 'Flujo de tiempo', x = 'tiempo', y = 'flujo') +
  scale_x_continuous(breaks = 1:20)

ggsave(filename = 'ocoflow.png', width = 8, height = 4, units = 'in')

plot2 + geom_hline(yintercept = 1) + 
  labs(title = 'Porcentaje de compleción', y = 'compleción') +
  scale_y_continuous(labels = scales::percent_format(accuracy = 1)) +
  scale_x_continuous(breaks = 1:20)

ggsave(filename = 'completion.png', width = 8, height = 4, units = 'in')
