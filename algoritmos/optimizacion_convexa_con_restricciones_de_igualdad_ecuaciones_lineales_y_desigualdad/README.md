
Utilizamos el siguiente script y los archivos `Gradiente_f.m`, `Gradiente_f_rest.m`, `Hessiana_f_dif_ad.m`, `Hessiana_f_rest.m`, `Metodo_backtracking.m`, ` Metodo_path_following.m`, `Newton_con_restricciones_de_igualdad_y_desigualdad.m`,  para resolver los siguientes problemas de optimización:



```
%1) %Linear programming, Bazaraa page 14

f = @(x) 2*x(1) + 5*x(2);
f_rest_desigualdad = @(x)[6-x(1)-x(2);-18+x(1)+2*x(2);-x(1);-x(2)];
A= [0 0];
b= 0;
x_ast = [6;0]

x0 = [4;4]   %debe ser estrictamente factible: satisfacer A*x0 = b y f_rest_desigualdad(x0) < 0


tol_outer_iter = 1e-6;

tol_inner_iter = 1e-5;

tol_backtracking = 1e-14;

maxiter_path = 30;

maxiter_Newton = 30;

mu = 10;

p_ast = f(x_ast);

[x,iter_barrera,t_barrera] = Metodo_path_following(f,f_rest_desigualdad,A,b,x_ast,p_ast,x0,tol_outer_iter,tol_inner_iter,tol_backtracking,maxiter_path,maxiter_Newton,mu)


...
Error utilizando valor de x_ast: 8.094184e-06

x =

   6.0000e+00
   1.2035e-05

%2) Luenberger page 378
f = @(x) x(1)^2 + x(2)^2+x(3)^2+x(4)^2-2*x(1)-3*x(4);
f_rest_desigualdad = @(x)[-x(1);-x(2);-x(3);-x(4)];
A= [2 1 1 4;1 1 2 1];
b= [7;6];


x_ast=[1.1232876712328763;0.6506849315068493;1.8287671232876714;0.5684931506849317]

x0 =A\b%x0 debe ser estrictamente factible: satisfacer A*x0 = b y f_rest_desigualdad(x0) < 0

tol_outer_iter = 1e-6;

tol_inner_iter = 1e-5;

tol_backtracking = 1e-14;

maxiter_path = 20;

maxiter_Newton = 15;

mu = 10;

p_ast = f(x_ast);

[x,iter_barrera,t_barrera] = Metodo_path_following(f,f_rest_desigualdad,A,b,x_ast,p_ast,x0,tol_outer_iter,tol_inner_iter,tol_backtracking,maxiter_path,maxiter_Newton,mu)

...
Error utilizando valor de x_ast: 3.379573e-07

x =

   1.12329
   0.65069
   1.82877
   0.56849

%3)Nocedal page 467


f = @(x) x(1)^2 + (x(2) +1)^2;
f_rest_desigualdad = @(x)[-x(1);-x(2)];
A= [0 0];
b= 0;
x_ast = [0;0]

x0 =[1;1]%x0 debe ser estrictamente factible: satisfacer A*x0 = b y f_rest_desigualdad(x0) < 0

tol_outer_iter = 1e-6;

tol_inner_iter = 1e-5;

tol_backtracking = 1e-14;

maxiter_path = 20;

maxiter_Newton = 15;

mu = 10;

p_ast = f(x_ast);

[x,iter_barrera,t_barrera] = Metodo_path_following(f,f_rest_desigualdad,A,b,x_ast,p_ast,x0,tol_outer_iter,tol_inner_iter,tol_backtracking,maxiter_path,maxiter_Newton,mu)

...
Error utilizando valor de x_ast: 3.237312e-03
Valor aproximado a x_ast:
x =

   3.2373e-03
   1.9445e-05


%plot:
[X,Y] = meshgrid(-1:0.5:1,-1:.5:1);
fgraf = @(X,Y) X.^2 + (Y +1).^2;
Z = fgraf(X,Y);
surf(X,Y,Z)


%level curves of this surface:

contour(X,Y,Z,'ShowText','on')


%4)
f=@(x) exp(x(1)+3*x(2)-0.1)+exp(x(1)-3*x(2)-0.1)+exp(-x(1)-0.1)

f_rest_desigualdad = @(x)[(x(1)-1)^2 + (x(2)-.25)^2-1];

A= [0 0];
b= 0;
x_ast = [0.02818941589727335;0.014237029951590515]; 


x0 =[1;1];%x0 debe ser estrictamente factible: satisfacer A*x0 = b y f_rest_desigualdad(x0) < 0

tol_outer_iter = 1e-6;

tol_inner_iter = 1e-5;

tol_backtracking = 1e-14;

maxiter_path = 20;

maxiter_Newton = 15;

mu = 10;

p_ast = f(x_ast);

[x,iter_barrera,t_barrera] = Metodo_path_following(f,f_rest_desigualdad,A,b,x_ast,p_ast,x0,tol_outer_iter,tol_inner_iter,tol_backtracking,maxiter_path,maxiter_Newton,mu)

...
Error utilizando valor de x_ast: 1.272083e-02
Valor aproximado a x_ast:
x =

   0.028591
   0.014255
   
%5) non negative least squares:


X=[0.91177  -1.15847   0.54351
   2.27585  -0.31595  -0.10009
  -0.13817  -0.43913  -0.99416
   0.20257   0.55622  -0.28660
   0.56596   0.54013   1.45889];

y =[1.4339
   5.4793
  -5.7085
   1.1300
   9.1538]


f=@(beta_p) (X*beta_p)'*(X*beta_p)-2*beta_p'*(X'*y)+y'*y;

f_rest_desigualdad = @(beta_p)[-beta_p(1);-beta_p(2);-beta_p(3)];

A= [0 0 0];
b= 0;
beta_ast = [2.9999862;3.00001679;3.99997103]; 


beta0 =[1;1;1];%x0 debe ser estrictamente factible: satisfacer A*x0 = b y f_rest_desigualdad(x0) < 0

tol_outer_iter = 1e-8;

tol_inner_iter = 1e-5;

tol_backtracking = 1e-14;

maxiter_path = 20;

maxiter_Newton = 15;

mu = 10;

p_ast = f(beta_ast);

[beta,iter_barrera,t_barrera] = Metodo_path_following(f,f_rest_desigualdad,A,b,beta_ast,p_ast,beta0,tol_outer_iter,tol_inner_iter,tol_backtracking,maxiter_path,maxiter_Newton,mu)

...
Error utilizando valor de x_ast: 6.196232e-06
Valor aproximado a x_ast:
beta =

   3.0000
   3.0000
   4.0000   
   
   
```
