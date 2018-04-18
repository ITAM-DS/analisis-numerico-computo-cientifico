#include<stdio.h>
#include<stdlib.h>
#include<math.h> //header para funciones de mate
double f(double node);
int main(int argc, char *argv[]){
    double suma_global = 0.0;
    double a=-1.0, b=3.0;
    int n=1e7; //número de subintervalos
    double objetivo=19.717657482016225;
	double h=(b-a)/n;
	int conteo_threads;//conteo_threads debe dividir de forma exacta a n
	int i;
	suma_global = (f(a)+f(b))/2.0;
	conteo_threads = strtol(argv[1], NULL, 10);
# pragma omp parallel for num_threads(conteo_threads) reduction(+: suma_global)
    for(i=0;i<=n-1;i++){
        suma_global += f(a+i*h);
    }
	suma_global = h*suma_global;
    printf("Integral de %f a %f = %1.15e\n", a,b,suma_global);
    printf("Error relativo de la solución: %1.15e\n", fabs(suma_global-objetivo)/fabs(objetivo));
    return 0;
}
double f(double nodo){
    double valor_f;
    valor_f = exp(nodo);
    return valor_f;
}
