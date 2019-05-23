function [x,iter_barrera,t_barrera] = Metodo_path_following(f,f_rest,A,b,x_ast,p_ast,x0,tol_outer_iter,tol_inner_iter,tol_backtracking,maxiter_path,maxiter_Newton,mu)

%Entrada:

%f: función a encontrar su mínimo. Definida como una function handle
%f_rest : vector de funciones de desigualdad, definidas como function handle.
%A y b: matriz y lado derecho del conjunto de restricciones de igualdad del problema
%de optimización (Ax = b)
%p_ast: valor óptimo de f: p_ast = f(x_ast)
%x0: aproximaciones iniciales a x_ast (mínimo de f) para los algoritmos
%tol_outer_iter: para el criterio de paro. Típicamente menor o igual a 1e-6.
	%Controla outer iterations
%tol_inner_iter: para el criterio de paro. Típicamente menor o igual a 1e-5.
	%Controla decremento de Newton de la función de barrera logarítmica en x 
%tol_backtracking: para backtracking. Típicamente menor o igual a 1e-14. Controla actualización de x.
%maxiter_path: máximo número de iteraciones a realizar para el método path following, "outer iterations"
%maxiter_Newton: máximo número de iteraciones a realizar para el método de Newton, "inner iterations"
%mu: valor mayor a uno. Factor que incrementa t_barrera.

%Salida:

%x aproximación a x_ast
%iter_barrera: número de iteraciones del método Metodo_path_following
%t_barrera: valor del parámetro de barrera al finalizar las inner iterations
f_rest_eval = f_rest(x0);
if(sum(f_rest_eval>=realmin*eps) < 1 ) %todas las restricciones son menores o iguales que cero
	if(mu>1)
		disp('Iniciando método path following')
		m = length(f_rest_eval);
		t0 = m/abs(f(x0)-p_ast); %otra opción: t0 = mu*m/(f(x0)-p_ast);
		t = t0;
		x = x0;
		phi = @(x) - sum(log(-f_rest(x)));
		f_barrera_log = @(t_path,x) t_path*f(x) + phi(x);
		f_barrera_log_eval = f_barrera_log(t,x);
		criterio_de_paro = m/t; 
		outer_iter = 1;
		disp('Outer iterations del método path following')
		fprintf('Valor de mu: %1.6e\n', mu);
		fprintf('Outer_iter  f_barrera_log   t_barrera    criterio_de_paro\n');
		fprintf('%i       %1.6e           %1.6e            %1.6e\n', outer_iter, f_barrera_log_eval, t, criterio_de_paro);
		disp('------------------------------------')
		iter_barrera = 0;
		while(criterio_de_paro>tol_outer_iter && outer_iter < maxiter_path)
			[x,iter,Err_plot,x_plot]=Newton_con_restricciones_de_igualdad(f,t,f_rest,A,b,x_ast,p_ast,x,tol_inner_iter,tol_backtracking,maxiter_Newton);
			disp('Inner iterations:')
			x_plot

			f_rest_eval = f_rest(x);
			
			if(sum(f_rest_eval>=realmin*eps) >= 1)
				disp('Alguna de las desigualdades se hizo mayor o igual que cero, revisar aproximaciones')
			end
			t = mu*t;
			f_barrera_log_eval = f_barrera_log(t,x);
			outer_iter +=1;
			criterio_de_paro = m/t; 
			disp('------------------------------------')
			disp('Outer iterations del método path following')
			fprintf('Outer_iter  f_barrera_log   t_barrera    criterio_de_paro\n');
			fprintf('%i       %1.6e           %1.6e            %1.6e\n', outer_iter, f_barrera_log_eval, t, criterio_de_paro);
			disp('------------------------------------')
			iter_barrera = iter_barrera + iter;
		end%while
		t_barrera = t;

	else
		disp('valor de mu debe ser mayor a uno, típicamente se elige entre 10 y 100')

	end %if
	
else
	disp('Alguna de las restricciones es mayor o igual que cero, revisar aproximaciones')
	x = x0;
	iter_barrera='';
	t_barrera='';

end %if


end %Metodo_path_following

