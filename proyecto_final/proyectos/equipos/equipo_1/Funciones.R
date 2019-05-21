#--- Función de cálculo de matriz Hessiana

hessiana <- function(fname, x){
  fx <- fname(x)
  h <- 1e-6
  n <- length(x)
  B <- diag(0, n)
  for (i in 1:n){
    for (j in 1:i){
      xt <- x 
      xt[i] <- xt[i] + h
      B[i,j] <- -fname(xt)
      xt <- x
      xt[j] <- xt[j] + h
      B[i,j] <- B[i,j] - fname(xt)
      xt <- x
      xt[i] <- xt[i] + h
      xt[j] <- xt[j] + h
      B[i,j] <- (B[i,j] + fname(xt) + fx)/(h^2)
      if (j != i){
        B[j,i] <- B[i,j]
      }
      
    }
  }
  return(B) 
}


#--- Función de cálculo de gradiente


gradiente <- function(fname, x){
  h <- 1e-8
  fx <- fname(x)
  n <- length(x)
  g <- rep(0,n)
  
  for(i in 1:n){
    xt <-  x
    xt[i] <- xt[i] + h
    fxh <- fname(xt)
    g[i] <- (fxh - fx) / h
  }
  
  return(g)
}



#--- Función de cálculo de gradiente con dirección de Newton

Newton_Desc <- function(fname,x){
    
    ##Parámetros
    n <- length(x)
    tol <- 1e-5  #tolerancia para la norma del gradiente
    maxiter <- 50 #número máximo de iteraciones externas permitidas
    maxjter <- 6
    c1 <- 0.1 
    
    ##valores iniciales
    iter <- 0 #Contador de iteraciones
    
    g <-  gradiente(fname,x)
    ng <- norm(g, '2') # Norma 2 del gradiente
    
    
    ##Iteraciones
    while((ng > tol) && (iter < maxiter)){
      H <- hessiana(fname,x)
      p <- - solve(H,g)
      
      alfa <- 1
      xt <- x + alfa*p
      
      ###Búsqueda de línea
      
      f <- fname(x)
      f1 <- fname(xt)
      s <- t(p)%*%g  # derivada direccional
      jter <- 0 #iteraciones internas
      
      while((f1 > f + alfa * c1* s) && (jter < maxjter)){ #Búsqueda de línea
        alfa <- alfa / 2
        xt <- x + alfa*p
        f1 <- fname(xt) # valor de la función en el punto de prueba
        jter <- jter + 1
        
      }  
      
      x <- x + alfa * p
      g <- gradiente(fname , x)
      ng <- norm(g , '2')
      iter <- iter + 1
    }
return(list(x, iter))
}

funcion_prueba <- function(x){
  R <- t(x)%*%x
  return(R)
}

Newton_Desc(funcion_prueba,sample(1:1000,10000,replace = T))

