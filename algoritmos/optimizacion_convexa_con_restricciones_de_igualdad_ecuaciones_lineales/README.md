Utilizamos el siguiente script y los archivos `Gradiente_f.m`, `Hessiana_f_dif_ad.m`, `Metodo_backtracking.m`, `Newton_con_restricciones_de_igualdad.m`,  para resolver los siguientes problemas de optimización:

```
%Example section 13.8 Luenberger (modified a little bit)
 
%1)
 
f = @(x) x(1)^2+2*x(1)*x(2)+x(2)^2-2*x(2)
 
A=[1 0];
 
b=[0];
 
x_ast=[0;1];
x0=[0;-2]; 
tol=1e-8;
tol_backtracking=1e-14;
maxiter=30;
p_ast=f(x_ast);
 
[x,iter,Err_plot,x_plot]=Newton_con_restricciones_de_igualdad(f,A,b,x_ast,p_ast,x0,tol,tol_backtracking,maxiter)
 
 
plot(log(1:iter),log(Err_plot))
plot(x_plot(1,:),x_plot(2,:),'o')
 
 
x =
 
   0.00000
   1.00000
 
%Podemos graficar esta superficie y sus curvas de nivel(sólo para ver cómo es (: )
 
[X,Y] = meshgrid(-10:0.5:10,-10:.5:10);
f = @(x,y) x.^2+2*x.*y+y.^2-2*y
Z = f(X,Y);
surf(X,Y,Z)
 
 
%level curves of this surface:
 
contour(X,Y,Z,'ShowText','on')
 
%2)
 
f=@(x) 1/2*(x(1)^2+x(2)^2)
 
A=[2 -1];
 
b=5;
 
x_ast=[2;-1];
 
tol=1e-8;
tol_backtracking=1e-14;
maxiter=30;
p_ast=f(x_ast);
 
x0=[0;-5];
 
[x,iter,Err_plot,x_plot]=Newton_con_restricciones_de_igualdad(f,A,b,x_ast,p_ast,x0,tol,tol_backtracking,maxiter)
 
plot(1:iter,Err_plot)
plot(x_plot(1,:),x_plot(2,:),'o')
 
x =
 
   2.0000
  -1.0001
 
 
%3) without restrictions
 
gamma_cte=10;
f=@(x)1/2*(x(1)^2+gamma_cte*x(2)^2);
 
x_ast=[0;0];
x0=[1;1];
tol=1e-8;
tol_backtracking=1e-14;
maxiter=30;
p_ast=f(x_ast);
 
A=[0 0];
 
b=0;
 
[x,iter,Err_plot,x_plot]=Newton_con_restricciones_de_igualdad(f,A,b,x_ast,p_ast,x0,tol,tol_backtracking,maxiter)
 
x=
0
0
 
 
%4)
 
f=@(x)x(1)^2+x(2)^2
 
x_ast=[1/2;1/2];
tol=1e-8;
tol_backtracking=1e-14;
maxiter=30;
p_ast=f(x_ast);
 
A=[1 1];
b=1;
x0=[2;-1];
 
[x,iter,Err_plot,x_plot]=Newton_con_restricciones_de_igualdad(f,A,b,x_ast,p_ast,x0,tol,tol_backtracking,maxiter)
 
x =
 
   0.50000
   0.50000
 
 
%5)
f=@(x) exp(x(1)+3*x(2)-0.1)+exp(x(1)-3*x(2)-0.1)+exp(-x(1)-0.1)
 
 
x_ast=[-0.23104907880100917;0.0770163596518852];
 
tol=1e-8;
tol_backtracking=1e-14;
maxiter=30;
p_ast=f(x_ast);
 
x0=[0;0];
 
A=[1 3];
 
b=0;
 
 
[x,iter,Err_plot,x_plot]=Newton_con_restricciones_de_igualdad(f,A,b,x_ast,p_ast,x0,tol,tol_backtracking,maxiter)
 
x =
 
  -0.231049
   0.077016
```
