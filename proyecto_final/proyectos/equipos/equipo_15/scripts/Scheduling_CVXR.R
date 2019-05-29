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

suppressWarnings(library(CVXR, warn.conflicts=FALSE))

numofjob <- 100 # Número de tareas a realizar
lambda <- 400   # Incremental del problema dual 

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
job           <- matrix(rep(0, 7*numofjob), ncol = 7) 
schedule      <- matrix(rep(0, 0), nrow = numofjob)  # Matriz para visualizar la asignación en cada instante t
fft           <- matrix(rep(0, numofjob), nrow = 1)  # flujo de tiempo fraccional que la tarea pasa en el sistema
ocoflow       <- matrix(rep(0, 0), ncol = 1)         # Muestra la acumulación del tiempo total pasado por todas las tareas en cada instante t

# Simulamos las características de las tareas
set.seed(108)
for (i in 1:numofjob) {
  job[i,1]  <- i
  job[i, 3] <- (round(runif(1) * 5) + 1) / 2;
  job[i, 4] <- round(runif(1),1)
}

j <- 0
while(sum(job[,3])!=sum(job[,5])) {
  
    print(j)
    ocoflow  <- rbind(ocoflow,0) 
    schedule <- cbind(schedule,0)
    j        <- j + 1
    
    for(i in 1:numofjob) {
      if(job[i,2] >= j) {
        fft[1,i] <- 0
        job[i,6] <- 0 
      } else {
        fft[1,i] <- (j-job[i,2]) / job[i,3] + 1
        job[i,6] <- 1
      }
    }

  #  Función para CVXR  
  x <- Variable(numofjob)
  objective <- Minimize(fft %*% x +
                          lambda %*% t(job[,6]) %*% ((job[,3] - job[,5] - x) * (j * matrix(rep(1, numofjob), ncol = 1) - job[,2])) +
                          norm2(x)^2 / 100)
  # Restricciones
  constraints <- list(
    t(job[,4]) %*% x <= 1,
                   x <= matrix(rep(1, numofjob), ncol = 1),
                   x >= matrix(rep(0, numofjob), ncol = 1),
                   x <= job[,3]-job[,5]
  )
  
  # Resolviendo el problema usando CVXR
  prob   <- Problem(objective, constraints)
  result <- solve(prob)
  x      <- result$getValue(x)
  cat(sprintf("Optimal value: %.3f\n", result$value))
  
  # Se actualiza lo que ya se ha ejecutado de la tarea 
  x            <- round(x, 1)
  job[,5]      <- job[,5] + x
  lambda       <- lambda + 5 * t(matrix(job[,6], ncol = 1)) %*% (matrix(job[,3], ncol = 1) - matrix(job[,5], ncol = 1) - x)
  schedule[,j] <- x
  
  # Tiempo que la tarea pasó en el sistema
  for(i in 1:numofjob) {
    if(x[i] > 0) {
      if(job[i, 5] >= job[i,3]) {
        job[i,7] <- j
      }
    }
  }
  
  # Tiempo acumulado
  for(i in 1:numofjob) {
    if(job[i,7] > 0 & job[i,7] <= j) {
      ocoflow[j,1] <- ocoflow[j,1] + (job[i,7] - job[i,2])
    }
  }
}

message(sprintf('Requerimiento de tareas:'))
print(job)

message(sprintf("Asignación de recursos a cada instante:"))
print(schedule)

message(sprintf("Histórico del tiempo total que han pasado todas las tareas en cada instante t:"))
print(ocoflow)


ocoflow.plot <- data.frame(flow = ocoflow[ocoflow != 0]) %>% 
  mutate(time = 1:nrow(.))

ggplot(ocoflow.plot, aes(time, flow)) +
  geom_line(color = 'royal blue', size = 1) +
  theme_light() +
  theme(panel.grid = element_blank()) +
  labs(title = 'Flujo de tiempo', x = 'tiempo', y = 'flujo') +
  scale_x_continuous(breaks = seq(0, 200, 5))

ggsave(filename = 'ocoflow_CVXR.png', width = 8, height = 4, units = 'in')

completion <- schedule %>% as.data.frame() %>% .[,1:nrow(ocoflow.plot)] %>% 
  rownames_to_column('tarea') %>% 
  gather(tiempo, addition, -tarea) %>% 
  mutate(tiempo = parse_number(tiempo),
         tarea = parse_number(tarea)) %>% 
  group_by(tarea) %>% 
  mutate(addition = cumsum(addition)) %>% 
  left_join(data.frame(tarea = job[,1], total = job[,3])) %>% 
  mutate(addition = addition / total) %>% 
  group_by(tiempo) %>% 
  summarise(addition = sum(addition) / numofjob)

ggplot(completion, aes(tiempo, addition)) +
  geom_line(color = 'royal blue', size = 1) +
  theme_light() +
  theme(panel.grid = element_blank()) +
  geom_hline(yintercept = 1) + 
  labs(title = 'Porcentaje de compleción', y = 'compleción') +
  scale_y_continuous(labels = scales::percent_format(accuracy = 1)) +
  scale_x_continuous(breaks = seq(0, 200, 5))

ggsave(filename = 'completion_CVXR.png', width = 8, height = 4, units = 'in')


