function grad_f = Gradiente_f(f,x)
%In:
%f función a la que se le calculará su gradiente
%x punto en el que se aproximará el gradiente de f
%Out:
%grad_f: aproximación al gradiente de f por diferencias centradas
h=1e-6;
n=length(x);
grad_f=zeros(n,1);
xaux=x;
xaux2=x;
for i=1:n
xaux(i)=x(i)+h;
xaux2(i)=x(i)-h;
grad_f(i) = (f(xaux)-f(xaux2))/(2*h);
xaux(i)=xaux(i)-h;
xaux2(i)=xaux2(i)+h;
end
 
end
