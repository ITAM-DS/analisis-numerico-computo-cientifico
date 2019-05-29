
data <- read.csv(file="./Portafolio.csv", header=TRUE, sep=",",stringsAsFactors=FALSE)
summary(data[,2:5])

valores <- as.matrix(data[,2:5])
cor(valores)
det(cor(valores))

Sigma <- cor(valores)

## Aplicamos Barrera Logarítmica
#Función y condiciones
A <- diag(-1, 4, 4)
b <- rep(0, 4)
RI <- matrix(c(1,1,1,1), 1, 4)
bi <- matrix(1,1,1,1)
x <- c(1/4,1/4,1/4,1/4)

#Función a optimizar
barrera <- function(t, x, A, b){
  m <- dim(A)[1]
  d <- A %*% x - b
  D <- diag(as.vector(1/d))
  
  f <- t*(x %*% Sigma %*% x) - log(-t(d)) %*% rep(1,m)
  g <- t*(Sigma %*% x) - t(A) %*% D %*% rep(1, m)
  H <- t * Sigma + t(A) %*% D ^ 2 %*% A
  resultados <- list(f = f, g = g, H = H)
  return(resultados)
}

# Parámetros de Barrera
mu <- 10
t <- 1
epsilon <- 1e-6

# Parámetros de Backtracking
# La "t" de backtracking se define en el loop como "s"
alpha <- .01
beta <- .5

hist_obj <- NULL

nt_tol <- 1e-10
max_iters <- 500

m <- dim(A)[1]

while(m/t > epsilon){
  n_iter <- 0
  for(k in 1:max_iters){
    res <- barrera(t, x, A, b)
    val <- res$f
    g <- res$g
    H <- res$H
    
    H_aum <- cbind(H, t(RI))
    H_aum <- rbind(H_aum, cbind(RI, matrix(rep(0, dim(RI)[1]^2), dim(RI)[1], dim(RI)[1])))
    g_aum <- c(g, rep(0, dim(RI)[1]))
    
    
    v <- -solve(H_aum, g_aum)
    v <- v[1:dim(RI)[2]]
    lambda <-  t(v) %*% H %*% v
    
    #Backtracking
    s <- 1 #Parámetro de backtracking
    while (min(b - A %*% (x + s * v)) < 0) {
      s <- beta * s
    }
    
    #Buscar mínimo
    while(barrera(t, x + s * v, A, b)$f > val + alpha * s * lambda){
      s <- beta * s
    }
    
    x <- x + s * v
    n_iter <- n_iter + 1
    
    #Probar mínimo
    if(abs(lambda / 2) < nt_tol)
      break
  }
  
  #Progreso
  obj <- t*(x %*% Sigma %*% x)
  hist_obj <- rbind(hist_obj, c(obj, n_iter, m/t, mu))
  print(paste0('No. de Cond. Sigma:',kappa(H_aum),'; miu: ', mu ,'; obj: ', obj, '; PDGap: ', m/t, '; number iterations: ', n_iter, '; x: ', paste(x,collapse = ", ")))
  
  t <- mu * t
}
