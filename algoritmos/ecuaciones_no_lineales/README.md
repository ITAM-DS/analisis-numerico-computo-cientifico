Utilizamos el siguiente script para resolver la ecuación no lineal:

$e^{-x}-x=0$


```
tol1 = 1e-8; %Controla |xk+1-xk|
tol2 = 1e-8; %Controla |f(x)|
maxiter = 30;
 
 
x_ast = 5.671432904097840e-001
x0=1
f=@(x) exp(-x)-x
df=@(x)-exp(-x)-1
[x,iter,Err_plot,Err_iter_plot,x_plot]=Newton_ecuaciones_no_lineales(x0,f,df,x_ast,tol1,tol2,maxiter)
```
