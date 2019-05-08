Utilizamos el siguiente script para resolver los siguientes problemas de optimización:

```
%1) Convex Optimization, Boyd & Vandenbergue chap 9
gamma_cte=10;
f=@(x)1/2*(x(1)^2+gamma_cte*x(2)^2);
 
x_ast=[0;0];
x0=[1;1];
tol=1e-8;
tol_backtracking=1e-14;
maxiter=30;
p_ast=f(x_ast);
 
 
#descenso con dirección de Newton
[x,iter,Err_plot,x_plot]=Newton_sin_restricciones(f,x_ast,p_ast,x0,tol,tol_backtracking,maxiter)
 
 
 
plot(1:iter,Err_plot)
plot(x_plot(1,:),x_plot(2,:),'o')
 
 
%2)Ejemplo Convex Optimization, Boyd & Vandenbergue chap 9
 
f=@(x) exp(x(1)+3*x(2)-0.1)+exp(x(1)-3*x(2)-0.1)+exp(-x(1)-0.1)
 
 
x_ast=[-3.4654e-01;-7.6725e-06];
x0=[0;0];
tol=1e-8;
tol_backtracking=1e-14;
maxiter=30;
p_ast=f(x_ast);
 
 
#descenso con dirección de Newton
[x,iter,Err_plot,x_plot]=Newton_sin_restricciones(f,x_ast,p_ast,x0,tol,tol_backtracking,maxiter)
 
plot(1:iter,Err_plot)
plot(x_plot(1,:),x_plot(2,:),'o')
```


