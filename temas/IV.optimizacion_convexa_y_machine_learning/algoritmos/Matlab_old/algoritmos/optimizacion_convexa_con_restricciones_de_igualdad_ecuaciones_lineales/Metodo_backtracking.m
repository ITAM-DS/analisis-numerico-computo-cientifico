function t=Metodo_backtracking(alpha, beta,f,dir_desc,x,derivada_direccional)
%In:
%alpha, beta parámetros del método por backtracking
%f función de Rn a R a minimizar
%dir_desc dirección de descenso en el punto x
%x punto en el que se buscará el tamaño de paso para la dirección de descenso dada
%grad_f gradiente de f en x
%Out: 
%t tamaño de paso
 
t=1;
if alpha>1/2
    disp('alpha de backtracking debe ser menor o igual a 1/2')
    t=-1;
end
 
if beta>1
    disp('beta de backtracking debe ser menor a 1')
    t=-1;
end
 
if(t!=-1) %parámetros de backtracking son correctos
     
    eval1=f(x+t*dir_desc);  
    eval2=f(x)+alpha*t*derivada_direccional;
    while(eval1>eval2)
        t=beta*t;
        eval1=f(x+t*dir_desc);
        eval2=f(x)+alpha*t*derivada_direccional;
    end %while
else
   t=-1;
end%if
 
 
end%function
