Posdef <- function (n, ev = runif(n, 0, 10)) 
{
  Z <- matrix(ncol=n, rnorm(n^2))
  decomp <- qr(Z)
  Q <- qr.Q(decomp) 
  R <- qr.R(decomp)
  d <- diag(R)
  ph <- d / abs(d)
  O <- Q %*% diag(ph)
  Z <- t(O) %*% diag(ev) %*% O
  return(Z)
}

pdmat <- Posdef(n=15000, ev=1:15000)
pdmat

write.table(pdmat, 'matrizSPD.txt',sep='\n',row.names=FALSE,col.names =  FALSE, dec='.')
