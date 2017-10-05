# Ejemplos con openMP

Para los siguientes ejemplos suponemos un sistema ubuntu 14.04 (o más reciente) y que está instalado el paquete build-essential o hacemos:

```
$sudo apt-get update -y && sudo apt-get install -y build-essential
```

para instalar el compilador **gcc**.


## Parallel for directive.

OpenMP provee una directive con el nombre **parallel for**. Esta directive ayuda a paralelizar ciclos for que tienen una forma canónica (ver más abajo para revisar a qué se refiere esto). Por ejemplo, para la regla del trapecio en su forma secuencial se tienen los statements:

```
double h=(b-a)/n;
int i;
double suma_global;
suma_global = (f(a)+f(b))/2.0;
    for(i=0;i<=n-1;i++){
        suma_global += f(a+i*h);
    }
suma_global = h*suma_global;
```

y al colocar la directive **parallel for** antes del ciclo for:

```
double h=(b-a)/n;
int i;
double suma_global;
suma_global = (f(a)+f(b))/2.0;
#pragma omp parallel for num_threads(conteo_threads) reduction(+: suma_global)
    for(i=0;i<=n-1;i++){
        suma_global += f(a+i*h);
    }
suma_global = h*suma_global;
```

es posible realizar en paralelo la regla del trapecio compuesta.

Puntos a señalar:

* La directive **parallel for** realiza el proceso de fork para que un team de threads ejecuten el **structured block** que continúa a la directive, pero este structured block **debe ser un ciclo for**.

* Con la directive **parallel for** se dividen **las iteraciones del loop entre los threads** y no el trabajo. En la directive parallel se divide **el trabajo entre los threads** (ver el tipo de tareas que se tienen que realizar para la regla del trapecio en las [Notas del curso MNO](https://www.dropbox.com/s/vcxbrqkk6x946d7/2.4.Sistemas_de_memoria_compartida_openMP.pdf?dl=0)).

* Obsérvese en el ejemplo anterior que se utilizó la **reduction clause** para definir a la variable suma_global como una **reduction_variable** y de esta forma no tener una critical section pues si el código hubiera sido:

```
double h=(b-a)/n;
int i;
double suma_global;
suma_global = (f(a)+f(b))/2.0;
#pragma omp parallel for num_threads(conteo_threads)
    for(i=0;i<=n-1;i++){
        suma_global += f(a+i*h); //esta es una critical section no protegida
    }
suma_global = h*suma_global;

```

entonces suma_global es **shared** y cada thread la actualiza generando una **race condition**. Para race condition y critical section, ver [Notas del curso MNO](https://www.dropbox.com/s/vcxbrqkk6x946d7/2.4.Sistemas_de_memoria_compartida_openMP.pdf?dl=0) para una explicación de esto.


* Como default, todas las variables definidas antes de una directive parallel son compartida **pero en la directiva parallel for la variable del ciclo i es private**, cada thread tiene su propia copia de la variable **i**.


De esta forma, el programa para realizar la regla compuesta del Trapecio con una directive parallel for es:

```trapecio_parallel_for.c```:

```
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

```

Compilamos:

```
$gcc -Wall -fopenmp trapecio_parallel_for.c -o trapecio_parallel_for.out -lm

```


Ejecutamos:

```
./trapecio_parallel_for.out 10
```

Resultado:

```
Integral de -1.000000 a 3.000000 = 1.971765762916819e+01
Error relativo de la solución: 7.462953721242119e-09
```

Obsérvese el error relativo y compárese con el programa secuencial en [1_parallel_and_critical_directives](../1_parallel_and_critical_directives).



