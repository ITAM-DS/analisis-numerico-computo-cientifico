function hf_rest = Hessiana_f_rest(f_rest,x_val)
%Cálculo de la Hessiana para cada función restricción de desigualdad
%In:
%f_rest: vector de functions handle que contiene cada una de las funciones de desigualdad
%x_val: punto a evaluar el gradiente de cada función de restricción de desigualdad

%Out:
%hf_rest: aproximación a la Hessiana de cada función de restricción de desigualdad

m=length(f_rest(x_val));

hf_rest=0;

for i=1:m
	f_rest_componente = @(x)f_rest(x)(i);
	gf_rest_componente_eval = Gradiente_f(f_rest_componente,x_val);
	hf_rest_componente_eval = Hessiana_f_dif_ad(f_rest_componente,x_val);
	f_rest_componente_eval = f_rest_componente(x_val);
	hf_rest+= gf_rest_componente_eval*gf_rest_componente_eval'./(f_rest_componente_eval^2) - hf_rest_componente_eval./f_rest_componente_eval;
end


end
