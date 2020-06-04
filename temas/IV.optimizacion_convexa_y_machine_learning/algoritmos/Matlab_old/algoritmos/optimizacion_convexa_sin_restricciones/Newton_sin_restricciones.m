%Método de Newton problemas de optimizacion sin restricciones
 
function [x,iter,Err_plot,x_plot]=Newton_sin_restricciones(f,x_ast,p_ast,x0,tol,tol_backtracking,maxiter)
%Entrada:
%f: función a encontrar el mínimo. Definida como una function handle
%x_ast: solución de min f(x).
%p_ast: valor óptimo de f: p_ast = f(x_ast)
%x0: aproximaciones iniciales a x_ast (mínimo de f) para los algoritmos
%tol: para el criterio de paro. Típicamente menor o igual a 1e-8. Controla decremento en x 
%tol_backtracking: para backtracking. Típicamente menor o igual a 1e-14. Controla actualización de x.
%maxiter: máximo número de iteraciones a realizar.
 
%Salida:
%x: aproximación a x_ast
%iter: número de iteraciones realizadas (para gráficas de monitoreo)
%Err_plot: error medido como error absoluto o relativo respecto a p_ast (para gráficas de monitoreo)
%x_plot: vector de aproximaciones (para gráficas de monitoreo)
 
iter=1;
x=x0;
 
%Evaluaciones:
 
feval=f(x);
gfeval=Gradiente_f(f,x);
Hfeval=Hessiana_f_dif_ad(f,x);
 
normagf = norm(gfeval);
 
condHf=cond(Hfeval);
 
Err_plot_aux = zeros(maxiter,1);
Err_plot_aux(iter)=abs(feval-p_ast);
 
 
if(norm(x_ast) > realmin*eps) Err=norm(x_ast-x)/norm(x_ast); else Err=norm(x_ast-x); end
 
n=length(x);
x_plot_aux=zeros(n,maxiter);
x_plot(:,1) = x;
 
 
alpha=.15;%parámetro para el backtracking
beta=.5;%parámetro para el backtracking
 
%definición decremento en x:
dir_Newton = Hfeval\(-gfeval);
lambda_cuadrada = dir_Newton'*(Hfeval*dir_Newton);
 
fprintf('Iter      Normagf     Decremento_en_x     Error_x_ast   Error_p_ast    backtracking_result  Condición_Hf\n')
 
fprintf('%3i   %1.6e     %1.6e     %1.6e     %1.6e     %s             %1.6e\n',iter, normagf, lambda_cuadrada, Err, Err_plot_aux(iter),'---', condHf);
 
 
criterio_de_paro = lambda_cuadrada/2;
 
while(criterio_de_paro>tol && iter<maxiter)
derivada_direccional = -lambda_cuadrada;
t=Metodo_backtracking(alpha, beta,f,dir_Newton,x,derivada_direccional);
x=x+t*dir_Newton;
feval=f(x);
gfeval=Gradiente_f(f,x);
Hfeval=Hessiana_f_dif_ad(f,x);
normagf = norm(gfeval);
condHf=cond(Hfeval);
dir_Newton = Hfeval\(-gfeval);
lambda_cuadrada = dir_Newton'*(Hfeval*dir_Newton);
 
if(norm(x_ast) > realmin*eps) Err=norm(x_ast-x)/norm(x_ast); else Err=norm(x_ast-x); end 
iter=iter+1;
Err_plot_aux(iter)=abs(feval-p_ast);
x_plot_aux(:,iter-1)=x;
fprintf('%3i   %1.6e     %1.6e     %1.6e     %1.6e     %1.6e    %1.6e\n',iter, normagf, lambda_cuadrada, Err, Err_plot_aux(iter),t, condHf);
 
criterio_de_paro = lambda_cuadrada/2;
 
if(t<tol_backtracking)%valor de backtracking es menor a tolerancia2, revisar motivo...
    iter_salida=iter;
    iter = maxiter;
end
 
end%while
 
fprintf('Error utilizando valor de x_ast: %1.6e\n', Err)
fprintf('Valor aproximado a x_ast:\n');
x
Err_plot = Err_plot_aux(abs(Err_plot_aux)>realmin*eps);
if(norm(x_ast) > realmin*eps) aux_diferencia_x_plot_aux = (x_plot_aux-x_ast)./norm(x_ast); else aux_diferencia_x_plot_aux=x_plot_aux-x_ast; end
 
index = norm(aux_diferencia_x_plot_aux,'cols')>realmin*eps & sum(x_plot_aux)!=0;
if(sum(index)!=0)
    x_plot(:,2:2+sum(index)-1) = x_plot_aux(:,index);
end
 
if(iter==maxiter && t<tol_backtracking)
    disp('Valor de backtracking menor a tol_backtracking, revisar aproximación')
    iter = iter_salida;
end
 
end
