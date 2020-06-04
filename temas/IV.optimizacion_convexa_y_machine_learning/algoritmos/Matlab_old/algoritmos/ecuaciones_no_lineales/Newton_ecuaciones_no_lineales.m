%Método de Newton para ecuaciones no lineales
%versión preliminar (no para producción)
 
function [x,iter,Err_plot,Err_iter_plot,x_plot]=Newton_ecuaciones_no_lineales(x0,f,df,x_ast,tol1,tol2,maxiter)
%Entrada:
%x0: aproximación inicial a x_ast
%f: función a la que se desea encontrar una raíz, esto es,  resolver f(x)=0.
%Definida como una function handle
%df: derivada de función. Definida como una function handle 
%x_ast: solución de f(x)=0.
%tol1: para los criterios de paro. Típicamente menor o igual a 1e-8. Controla |xk+1-xk|
%tol2: para los criterios de paro. Típicamente menor o igual a 1e-8. Controla |f(x)|
%maxiter: máximo número de iteraciones a realizar.
%Salida:
%x: aproximación a x_ast
%iter: número de iteraciones
%Err_plot: error de la aproximación x a x_ast (relativo o absoluto) para cada iteración
%(para realizar gráficas de monitoreo)
%x_plot: vector de aproximaciones para cada iteración
%Err_iter_plot: error entre iteraciones abs(x_k+1-xk)
 
%%%%%%%%Inicio
 
iter=1;
x=x0;
 
%imprimir título de tabla de monitoreo en pantalla
fprintf('   i         |F|           x              Err             |df|\n');
 
%evaluaciones
feval=f(x);
dfeval = df(x);
 
%evaluaciones para monitoreo
normaf=abs(feval);
normadf=abs(dfeval);
 
%vector que ayudará a obtener Err_plot, Err_iter_plot
Err_plot_aux = zeros(maxiter,1);
Err_iter_plot_aux = zeros(maxiter,1);
 
 
%revisar si calcular error relativo o error absoluto
if(abs(x_ast) > realmin*eps) Err=abs(x_ast-x)/abs(x_ast); else Err=abs(x_ast-x); end
Err_plot_aux(iter)=Err;
 
%vector que ayudará a obtener x_plot
x_plot_aux=zeros(maxiter,1);
x_plot_aux(iter)=x;
 
%imprimir en pantalla valores iniciales
fprintf(' %3i   %1.6e   %1.6e   %1.6e   %1.6e\n',iter, normaf,x,Err,normadf);
 
if(Err>tol2 && iter==1) %realizamos método de Newton
    x=x-feval/dfeval;
    feval=f(x);
    dfeval=df(x);
    normaf=abs(feval);
    normadf=abs(dfeval);
    if(abs(x_ast) > realmin*eps) Err=abs(x_ast-x)/abs(x_ast); else Err=abs(x_ast-x); end
    iter=iter+1;
    Err_plot_aux(iter)=Err;
    x_plot_aux(iter)=x;
    Err_iter_plot_aux(iter-1)=abs(x-x_plot_aux(iter-1));
     
    %imprimir en pantalla
    fprintf(' %3i   %1.6e   %1.6e   %1.6e   %1.6e\n',iter, normaf,x,Err,normadf);
    while(Err_iter_plot_aux(iter-1)>(1+abs(x))*tol1 && iter<maxiter) %continuamos con método de Newton
        x=x-feval/dfeval;
        feval=f(x);
        dfeval=df(x);
        normaf=abs(feval);
        normadf=abs(dfeval);
        if(abs(x_ast) > realmin*eps) Err=abs(x_ast-x)/abs(x_ast); else Err=abs(x_ast-x); end
        iter=iter+1;
        Err_plot_aux(iter)=Err;
        x_plot_aux(iter)=x;
        Err_iter_plot_aux(iter-1)=abs(x-x_plot_aux(iter-1));
        fprintf(' %3i   %1.6e   %1.6e   %1.6e   %1.6e\n',iter, normaf,x,Err,normadf);
    end
 
    if(iter==maxiter)
        disp('Método de Newton para ecuaciones no lineales alcanzó el máximo número de iteraciones')
    else % revisar si se llegó a solución
        if(normaf>tol2)
            disp('La norma de f no es menor a tolerancia, revisar valor x aproximado')
        else %se llegó a solución
            disp('Éxito')
        end
    end
 
end
 
fprintf('Error utilizando valor de x_ast: %1.6e\n', Err)
fprintf('Valor aproximado a x_ast: %1.6e\n', x);
 
%Obtener vectores para monitoreo
Err_plot = Err_plot_aux(abs(Err_plot_aux)>realmin*eps);
Err_iter_plot = Err_iter_plot_aux(abs(Err_iter_plot_aux)>realmin*eps);
x_plot = x_plot_aux(abs(x_plot_aux)>realmin*eps);
 
%%%%%%%%fin
 
end %Newton_ecuaciones_no_lineales
