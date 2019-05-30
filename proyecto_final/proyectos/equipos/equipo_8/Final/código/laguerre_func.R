laguerre_pol <- function(grado){
  if(grado == 0)
    h <- 1
  else
    if(grado == 1)
      h <- c(-1, 1)
    else{
      h1 <- rep(0, grado + 1)
      h1[1:grado] <- 1/((grado - 1) + 1) * laguerre_pol(grado - 1)
      h2 <-  rep(0, grado + 1)
      h2[2:length(h2)] <- (2 * (grado - 1)  + 1)/((grado - 1) + 1)* laguerre_pol(grado - 1)
      h3 <-  rep(0, grado + 1)
      h3[3:length(h2)] <- (grado - 1)/((grado - 1) + 1)* laguerre_pol(grado - 2) 
      h <- h2-h1-h3    
    }
    
    return(h)
}

eval_laguerre <- function(grado, x){
  pol <- laguerre_pol(grado)
  n <- length(pol)
  grados <- rev(seq(0, n - 1))
  eval <- 0
  
  for (i in 1:(n - 1))
    eval <- eval + pol[i] * x ^ grados[i]
  
  eval <- eval + pol[n]
  return(eval)
}

laguerre_weights <- function(grado) {
  polinomio <- rev(laguerre_pol(grado))
  raices <- as.numeric(polyroot(polinomio))
  pesos <- rep(0, length(raices))
  
  for (i in 1:length(raices)) 
    pesos[i] = raices[i] / ((grado+1)^2 * eval_laguerre(grado - 1, raices[i])^2)
  
  return(cbind(raices, pesos))
}

laguerre_gauss <- function(func, n_max){
  #browser()
  resultados <- NULL
  for (i in 2:n_max) {
    #browser()
    laguerre <- laguerre_weights(i)
    aprox <- 0
    for (j in 1:dim(laguerre)[1]) 
      aprox <- aprox + laguerre[j,2] * func(laguerre[j,1])
    
    res <- data.frame(n = i, aprox = aprox, row.names = NULL)
    resultados <- rbind(resultados, res)
  }
  return(resultados)
}

g <- function(x){
  cos(x)
}

real <- 0.5
integral <- laguerre_gauss(g, 15)
integral$error <-real - integral$aprox