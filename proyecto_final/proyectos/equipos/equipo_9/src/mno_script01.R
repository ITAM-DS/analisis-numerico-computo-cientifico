
## MNO: Proyecto final

datos <- matrix(c(1, 1.09, 1.08, 1.34,
                  1, 1.16, 1.26, 1.54,
                  1, 1.22, 1.07, 1.03,
                  1, 0.93, 0.97, 0.92,
                  1, 1.11, 1.56, 1.52,
                  1, 0.76, 0.77, 0.9,
                  1, 0.92, 0.84, 1.01,
                  1, 0.88, 1.22, 1.34), ncol = 4, byrow = TRUE)


payoff_call <- function(x,k){
  y <- max(x-k,0)
  return(y)
}

payoff_put <- function(x,k){
  y <- max(k-x,0)
  return(y)
}



k=1.1

test_call <- sapply(datos[,3], FUN = payoff_call, k=k)
test_call

test_put <- sapply(datos[,3], FUN = payoff_put, k=k)
test_put


