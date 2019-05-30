#Métodos de Gauss
hermite_pol <- function(grado){
    if(grado == 0)
      h <- 1
    else
      if(grado == 1)
        h <- c(2, 0)
      else{
        h1 <- rep(0, grado + 1)
        h1[1:grado] <- 2 * hermite_pol(grado - 1)
        h2 <- rep(0, grado + 1)
        h2[3:length(h2)] <- 2 * (grado - 1) * hermite_pol(grado - 2)
        
        h <- h1 - h2
      }
      return(h)
}

eval_hermite <- function(grado, x){
  pol <- hermite_pol(grado)
  n <- length(pol)
  grados <- rev(seq(0, n - 1))
  eval <- 0
  
  for (i in 1:(n - 1))
    eval <- eval + pol[i] * x ^ grados[i]
  
  eval <- eval + pol[n]
  return(eval)
}

hermite_weights <- function(grado) {
  polinomio <- rev(hermite_pol(grado))
  raices <- as.numeric(polyroot(polinomio))
  pesos <- rep(0, length(raices))
  numerador <- 2^(grado - 1) * factorial(grado) * sqrt(pi) 
  
  for (i in 1:length(raices)) 
    pesos[i] = numerador / (grado ^ 2 * eval_hermite(grado - 1, raices[i])^2)
  
  return(cbind(raices, pesos))
}

hermite_gauss <- function(func, n_max){
  resultados <- NULL
  for (i in 2:n_max) {
    #browser()
    hermite <- hermite_weights(i)
    aprox <- 0
    for (j in 1:dim(hermite)[1]) 
      aprox <- aprox + hermite[j,2] * func(hermite[j,1])
    
    res <- data.frame(n = i, aprox = aprox, row.names = NULL)
    resultados <- rbind(resultados, res)
  }
  return(resultados)
}

g <- function(x){
  27*x^6+42*x-132
}

real <- -144.233
integral <- hermite_gauss(g, 20)
integral$error <-real - integral$aprox
