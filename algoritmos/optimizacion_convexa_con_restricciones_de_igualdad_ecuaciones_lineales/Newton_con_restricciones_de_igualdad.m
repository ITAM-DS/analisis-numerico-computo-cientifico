%Método de Newton problemas de optimizacion con restricciones de igualdad
 
function [x,iter,Err_plot,x_plot]=Newton_con_restricciones_de_igualdad(f,A,b,x_ast,p_ast,x0,tol,tol_backtracking,maxiter)
%Entrada:
%f: función a encontrar el mínimo. Definida como una function handle
%A y b: matriz y lado derecho del conjunto de restricciones de igualdad del problema
%de optimización (Ax = b)
%x_ast: solución de min f(x) sujeto a: Ax=b.
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
 
if(norm(b)>realmin*eps) valor_restriccion=norm(b-A*x0)/norm(b);else valor_restriccion=norm(b-A*x0);end
 
if(valor_restriccion<tol)
    iter=1;
    x=x0;
     
    %Evaluaciones:
     
    feval=f(x);
    gfeval=Gradiente_f(f,x);
    Hfeval=Hessiana_f_dif_ad(f,x);
    normagf = norm(gfeval);
     
    Err_plot_aux = zeros(maxiter,1);
    Err_plot_aux(iter)=abs(feval-p_ast);
     
     
    if(norm(x_ast) > realmin*eps) Err=norm(x_ast-x)/norm(x_ast); else Err=norm(x_ast-x); end
     
    [m,n] = size(A);
    x_plot_aux=zeros(n,maxiter);
    x_plot(:,1) = x;
     
    alpha=.15;%parámetro para el backtracking
    beta=.5;%parámetro para el backtracking
     
    %Modificar siguientes líneas para evitar crear matriz_sistema
    matriz_ceros = zeros(m,m);
    matriz_sistema = [Hfeval A';A matriz_ceros];
    vector_ceros = zeros(m,1);
    lado_derecho = - [gfeval; vector_ceros];
    dir_desc = matriz_sistema\lado_derecho;
    dir_Newton = dir_desc(1:n);
    w_estimacion_variable_dual = dir_desc(n+1:end);
     
    %definición decremento en x:
    lambda_cuadrada_Newton = dir_Newton'*(Hfeval*dir_Newton);
         
    %Para monitoreo pues se resolvió un sistema de ecuaciones lineales
    cond_matriz_sistema = cond(matriz_sistema);
     
     
    fprintf('Iter      Normagf             f(x)            Decremento_en_x     Error_x_ast      Error_p_ast      backtracking     Condición_matriz_sistema\n')
     
    fprintf('%3i    %1.7e      %1.7e      %1.7e      %1.7e      %1.7e      %s              %1.7e\n',iter, normagf, feval, lambda_cuadrada_Newton, Err, Err_plot_aux(iter),'---', cond_matriz_sistema);
     
    criterio_de_paro = lambda_cuadrada_Newton/2;
     
    while(criterio_de_paro>tol && iter<maxiter)
    derivada_direccional_Newton = -lambda_cuadrada_Newton;
    t=Metodo_backtracking(alpha, beta,f,dir_Newton,x,derivada_direccional_Newton);
    x=x+t*dir_Newton;
 
    %Volver a evaluar:
    feval=f(x);
    gfeval=Gradiente_f(f,x);
    Hfeval=Hessiana_f_dif_ad(f,x);
    normagf = norm(gfeval);
     
    %Modificar siguientes líneas para evitar crear matriz_sistema
    matriz_sistema = [Hfeval A';A matriz_ceros];
    lado_derecho = - [gfeval; vector_ceros];
    dir_desc = matriz_sistema\lado_derecho;
    dir_Newton = dir_desc(1:n);
    w_estimacion_variable_dual = dir_desc(n+1:end);
     
    %definición decremento en x:
    lambda_cuadrada_Newton = dir_Newton'*(Hfeval*dir_Newton);
     
    %Para monitoreo pues se resolvió un sistema de ecuaciones lineales  
    cond_matriz_sistema = cond(matriz_sistema);
     
    if(norm(x_ast) > realmin*eps) Err=norm(x_ast-x)/norm(x_ast); else Err=norm(x_ast-x); end 
    iter=iter+1;
    Err_plot_aux(iter)=abs(feval-p_ast);
    x_plot_aux(:,iter-1)=x;
     
    fprintf('%3i    %1.7e      %1.7e      %1.7e      %1.7e      %1.7e      %1.7e    %1.7e\n',iter, normagf, feval, lambda_cuadrada_Newton, Err, Err_plot_aux(iter),t,cond_matriz_sistema);
         
    criterio_de_paro = lambda_cuadrada_Newton/2;
     
    if(t<tol_backtracking)%valor de backtracking es menor a tol_backtracking, revisar motivo...
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
     
 
else %Ax0!=b
    disp('Revisar punto inicial, posible falla en: A*x0 = b')
end
 
 
end %Newton_con_restricciones_de_igualdad
