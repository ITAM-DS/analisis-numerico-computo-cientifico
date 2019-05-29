#Tridiagonal Matrix Solver
#Esta función realiza el tridiagonal matrix algorithm con sustitución hacia atrás
TDMA <- function(A, b){
  n <- dim(A)[1]
  #R <- diag(n)
  x <- b
  
  A[1,2] <- A[1,2] / A[1,1]
  b[1] <- b[1] / A[1,1]
  
  for(j in 2:(n-1)){
    temp <- (A[j,j] - A[j, (j-1)] * A[(j - 1), j])
    A[j, (j+1)] <- A[j, (j+1)] / temp
    b[j] <- (b[j] - b[j - 1] *  A[j, (j - 1)]) / temp
  }
  
  x[n] <- (b[n] - b[n - 1] *  A[n, (n - 1)])  / (A[n, n] - A[n, (n-1)] * A[(n-1), n])
  for(i in (n-1):1){
    x[i] <- b[i] - A[i, (i + 1)] * x[(i + 1)]
  }
  return(x)
}
