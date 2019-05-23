function f_barrera = Barrera_logaritmica(f,f_rest,t,x)
%Evaluación de la función de barrera
%In:
%f: función objetivo definida como una function handle
%f_rest: vector de functions handle que contiene cada una de las funciones de restricción desigualdad
%t: parámetro de barrera
%x: punto a evaluar la función de barrera logarítmica
%Out:
%f_barrera: evaluación de la función de barrera logarítmica en x
suma=0;
m=length(f_rest(x));

for i=1:m
	f_rest_componente = @(x)f_rest(x)(i);
	f_rest_componente_eval = f_rest_componente(x);
	if(f_rest_componente_eval>=0)
		barrera_componente_eval = 1e10;
	else
		barrera_componente_eval = log(-f_rest_componente_eval);
	end
	suma+=barrera_componente_eval;
end
feval = f(x);
f_barrera = t*feval+suma;

end
