# Ejemplos con openMP

Para los siguientes ejemplos suponemos un sistema ubuntu 14.04 (o más reciente) y que está instalado el paquete build-essential o hacemos:

```
$sudo apt-get update -y && sudo apt-get install -y build-essential
```

para instalar el compilador **gcc**.


## Reduction clause.

En el programa del trapecio al final de [1_parallel_and_critical_directives](../1_parallel_and_critical_directives) se definió una variable **private** para almacenar los resultados calculados por cada thread y se agregaron los resultados con la **directive critical** para realizar una suma secuencial de estos resultados para aproximar la integral de una función con la regla del trapecio compuesto.

openMP provee una solución más limpia para este caso: aplicar la operación de suma (operador binario) a cada resultado de un thread de forma repetida y almacenar en una variable la respuesta.

Llamamos **reduction variable** a la variable que almacenará los resultados intermedios calculados por cada thread y **reduction operator** a la operación **binaria** (por ejemplo una suma o multiplicación) que se aplica repetidamente a una secuencia de operandos para obtener un resultado, en un proceso que se le llama **reduction**. Por ejemplo, si ```A``` es un arreglo de **n** ```ints```, el cálculo:

```
int sum=0;
for(i=0;i<n;i++)
	sum+=A[i];
``` 

es un proceso de **reduction** en el que el **reduction operator** es la suma.

### ¿Cómo se define en openMP una **reduction variable**?

En openMP usamos la **reduction clause** en la **parallel directive** para responder esta pregunta. Ejemplo:

```
suma_global=0.0
#pragma omp parallel num_threads(conteo_threads) reduction(+: suma_global)
	suma_global+=Trap(a,b,n);

```

Con la **reduction clause** openMP crea una variable **private por cada thread** y el run-time system almacena el resultado de cada thread en esta variable private. openMP también crea una **critical section** y los valores almacenados en las variables private son sumadas en esta critical section y **almacenados en la reduction variable suma_global**. El **reduction operator** es: ```+```.

La sintaxis de la **reduction clause** es:

```
reduction( <operator>: <variable list>)
```

El **reduction operator** puede ser cualquiera de los operadores: ```+,*,-,&,|,^,&&,||``` aunque se debe señalar que el proceso de **reduction** asume que los operadores utilizados cumplen con la propiedad asociativa. (El operador de resta no cumple con esto...).

Entonces, el código:


```
suma_global = 0.0;
# pragma omp parallel num_threads(thread_count)
{
	double mi_resultado=0.0; //variable private
	mi_resultado+=Trap(a,b,n);
# pragma omp critical
	suma_global+=mi_resultado;
}
```

es equivalente al código:

```
suma_global=0.0
#pragma omp parallel num_threads(conteo_threads) reduction(+: suma_global)
	suma_global+=Trap(a,b,n);

```

La variable que está en la **reduction clause** es **shared**. Sin embargo una variable **private** es creada por cada thread en el team (**con el mismo nombre** que aparece en la **reduction clause**) y si un thread ejecuta un statement en el parallel block que involucra a la variable, entonces se utiliza la variable **private** y al finalizar el parallel block, los valores calculados en las variables **private** son combinados en la variable **shared**


Ejemplo de uso del nombre ```suma_global``` para definir una variable **private** y **shared** en una **reduction clause**:

```ejemplo_variable_private_shared_reduction_clause.c```

```
#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
int main(int argc, char *argv[]){
long conteo_threads;
int variable_thread;
int suma_global=7;
conteo_threads=strtol(argv[1], NULL, 10);

printf("suma global al inicio : %d\n", suma_global);

#pragma omp parallel num_threads(conteo_threads) reduction(+: suma_global)
{
	int mi_rango=omp_get_thread_num();
	if(mi_rango==0)
                printf("suma_global, 1 printf del thread 0: %d\n", suma_global);
        else
                printf("suma_global, 1 prinftf thread 1: %d\n", suma_global);
	suma_global=(mi_rango==0)?10:20;
	variable_thread=(mi_rango==0)?1:2;
	if(mi_rango==0)
		printf("suma_global, 2 printf del thread 0: %d\n", suma_global);
	else
		printf("suma_global, 2 printf del thread 1: %d\n", suma_global);
	suma_global+=variable_thread;
        if(mi_rango==0)
                printf("suma_global, 3 printf del thread 0: %d\n", suma_global);
        else
                printf("suma_global, 3 printf del thread 1: %d\n", suma_global);

}
	printf("suma_global al final de la directive parallel %d\n", suma_global);
return 0;
}

```

Compilamos:

```
$gcc -Wall -fopenmp ejemplo_variable_private_shared_reduction_clause.c ejemplo_variable_private_shared_reduction_clause.out 
```

Ejecutamos:

```
$./ejemplo_variable_private_shared_reduction_clause.out 2
```

Resultado:

```
suma global al inicio : 7
suma_global, 1 printf del thread 0: 0
suma_global, 2 printf del thread 0: 10
suma_global, 3 printf del thread 0: 11
suma_global, 1 prinftf thread 1: 0
suma_global, 2 printf del thread 1: 20
suma_global, 3 printf del thread 1: 22
suma_global al final de la directive parallel 40
```

Obsérvese que la variable **suma_global** se inicializa en 0. En general, las variables **private** creadas para una **reduction clause** son inicializadas al **identity value** para el **operator**, por ejemplo, si el **operator** es la multiplicación, entonces las variables **private** son inicializadas en 1.

Así, el ejemplo de la regla del trapecio con la reduction clause queda como sigue:


```trapecio_paralelo_omp_reduce_clause.c```:

```
#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include<math.h>
double Trap(double ext_izq, double ext_der, int num_trap); //la función Trap devuelve
                                //un valor double.
double f(double nodo);
int main(int argc, char *argv[]){
    double suma_global = 0.0;
    double a=-1.0, b=3.0;
    int n=1e7; //número de subintervalos
    int conteo_threads; //conteo_threads debe dividir de forma exacta a n
    double objetivo=19.717657482016225;
    conteo_threads = strtol(argv[1], NULL, 10);
    #pragma omp parallel num_threads(conteo_threads) \
    			reduction(+: suma_global) //reduction clause
        suma_global+=Trap(a,b,n);
    printf("Integral de %f a %f = %1.15e\n", a,b,suma_global);
    printf("Error relativo de la solución: %1.15e\n", fabs(suma_global-objetivo)/fabs(objetivo));
    return 0;
}
double Trap(double a, double b, int n){
    double h=(b-a)/n;
    double x, local_int;
    double local_a, local_b;
    int i,local_n;
    int mi_rango = omp_get_thread_num();
    int conteo_threads = omp_get_num_threads();
    local_n = n/conteo_threads; //división exacta
    local_a = a + mi_rango*local_n*h;
    local_b = local_a + local_n*h;
    local_int = (f(local_a)+f(local_b))/2.0;
    for(i=0;i<=local_n-1;i++){
        x = local_a+i*h;
        local_int+=f(x);
    }
    local_int =h*local_int;
    return local_int;
}
double f(double nodo){
    double valor_f;
    valor_f = exp(nodo);
    return valor_f;
}
```

Compilamos:

```
$gcc -Wall -fopenmp trapecio_paralelo_omp_reduce_clause.c -o trapecio_paralelo_omp_reduce_clause.out -lm
```

Ejecutamos:

```
./trapecio_paralelo_omp_reduce_clause.out 10
```

Resultado:

```
Integral de -1.000000 a 3.000000 = 1.971767351834609e+01
Error relativo de la solución: 8.132979223646726e-07
```






