#Factorización LU con pivoteo parcial
A <- read.csv("matriz_td.csv", header = F)
b <- runif(20, 0, 100)
#A <- matrix(c(1,3,0,0,4,4,2,0,0,1,3,1,0,0,4,3), 4, 4)
#b <- c(1,2,3,4)

LU_pivoteo <- function(A) {
  n <- dim(A)[1]
  n1 <- dim(A)[2]
  L <- diag(n)
  P <- diag(n)
  U <- A
  
  for (j in 1:n) {
    pivote <- max(abs(U[j:n, j])) 
    m <- which(abs(U[j:n, j]) == pivote)
    m <- m + j - 1
   #browser()
    if(m != j){
      U[c(m,j),] <- U[c(j,m),]
      P[c(m,j),] <- P[c(j,m),]
      if(j >=2)
        L[c(m,j),1:(j-1)] <- L[c(j,m),1:(j-1)]
    }
    if(j != n){
      for(i in (j+1):n){
        #browser()
        L[i, j] <- U[i, j] /U[j, j] 
        U[i,] <- U[i,] - L[i, j] * U[j,] 
      }
    }
  }
  resultados <- list("L" = L, "U" = U, "P" = P)
  return(resultados)
}

sust_atras <- function(A, b){
  n <- dim(A)[1]
  
  for(i in n:2){
    b[i] <- b[i]/A[i, i]
    b[1:(i - 1)] <- b[1:(i - 1)] - b[i] * A[1:(i - 1), i]
  }
  b[1] <- b[1] / A[1, 1]
  return(b)
}

sust_adelante <- function(A, b){
  n <- dim(A)[1]
  
  for(j in 1:(n-1)){
    b[j] <- b[j] / A[j, j]
    b[(j + 1)] <- b[(j+1):n] - b[j] * A[(j+1):n, j]
  }
  b[n] = b[n] / A[n,n]
  return(b)
}

sol_ecuacion <- function(A, b) {
  fact <- LU_pivoteo(A)
  y_estrella <- sust_adelante(fact$L, fact$P %*% b)
  x <- sust_atras(fact$U, y_estrella)
}


#----
#Tridiagonal Matrix Solver

TDMA <- function(A, b){
  n <- dim(A)[1]
  R <- diag(n)
  x <- b
  
  R[1,2] <- A[1,2] / A[1,1]
  b[1] <- b[1] / A[1,1]
  
  for(j in 2:k){
    if(j < k)
      R[j, (j+1)] <- A[j, (j+1)] / (A[j,j] - R[(j-1), j] * A[j, (j - 1)])
    b[j] <- (b[j] - b[j - 1] *  A[j, (j - 1)]) / (A[j,j] - R[(j-1), j] *  A[j, (j - 1)])
  }
  
  x <- sust_atras(R,b)
  
  # x[n] <- b[n]
  # for(i in (n-1):1){
  #   x[i] <- b[i] - R[i, (i + 1)] * x[(i + 1)]
  # }
  return(x)
}

#----
#Ambos algoritmos

tinicio_LU <- Sys.time()
x1 <- t(sol_ecuacion(A, b))
tfin_LU <- Sys.time() - tinicio_LU


tinicio_TDMA <- Sys.time()
x2 <- TDMA(A, b)
tfin_TDMA <- Sys.time() - tinicio_TDMA

print(c(tfin_LU, tfin_LU))