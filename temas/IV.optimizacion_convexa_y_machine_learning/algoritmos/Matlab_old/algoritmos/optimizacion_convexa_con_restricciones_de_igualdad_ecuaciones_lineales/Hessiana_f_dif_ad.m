function Hf=Hessiana_f_dif_ad(f,x)
%In:
%f función a la que se le calculará su Hessiana
%x punto en el que se aproximará la Hessiana de f
%Out:
%Hf: aproximación a la Hessiana de f por diferencias hacia delante
h=1e-6; %mismo valor de h para segundas derivadas parciales
n=length(x);
Hf=zeros(n,n);
 
xaux_i = x;
xaux_j = x;
for i=1:n
    xaux_i(i) = xaux_i(i) + h;
    xaux_ij = x;
    for j=i:n
        xaux_j(j) = xaux_j(j) + h;
        xaux_ij(j) = xaux_i(j) + h;
        dif1 = f(xaux_ij)-f(xaux_i);
        dif2 = f(xaux_j)-f(x);
        Hf(i,j) = (dif1-dif2)/(h*h);
        if(j!=i)
            Hf(j,i) = (dif1-dif2)/(h*h);
        end
        xaux_j(j) = xaux_j(j) - h;
        xaux_ij(j) = xaux_ij(j) - h;
    end
    xaux_i(i) = xaux_i(i) - h;
end
end
