function gf_rest = Gradiente_f_rest(f_rest,x_val)
%Cálculo del gradiente para cada función restricción de desigualdad
%In:
%f_rest: vector de functions handle que contiene cada una de las funciones de desigualdad
%x_val: punto a evaluar el gradiente de cada función de restricción de desigualdad

%Out:
%gf_rest: aproximación a los gradientes de cada función de restricción de desigualdad


m=length(f_rest(x_val));

gf_rest=zeros(m,1);

gf_rest=0;
for i=1:m
	f_rest_componente = @(x)f_rest(x)(i);
	grad_f_rest_componente_eval = Gradiente_f(f_rest_componente,x_val);
	gf_rest+=-grad_f_rest_componente_eval./f_rest_componente(x_val);
end

end
