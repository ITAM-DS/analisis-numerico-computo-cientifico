# Ejemplos con openMP

Para los siguientes ejemplos suponemos un sistema ubuntu 14.04 (o más reciente) y que está instalado el paquete build-essential o hacemos:

```
$sudo apt-get update -y && sudo apt-get install -y build-essential
```

para instalar el compilador **gcc**.

Usamos **pragmas** para indicar al preprocesador (vía la compilación) que ejecutaremos una instrucción que no se encuentra en la especificación básica del lenguaje C, esto se le conoce con el nombre de **directive**.

Cabe señalar que las versiones más recientes de **gcc** sí soportan a los **pragmas** y todas las preprocessor directive son por default de longitud una línea. Si no cabe en una línea usamos un escaping (precedemos con un backslash "\\" la "nueva línea").

Los pragmas de openMP siempre inician con:

```
# pragma omp
```

# Directive parallel.

La directive parallel en openMP se utiliza como:

```
# pragma omp parallel 
```

Ejemplo:

## Programa de hello world:

```hello_world_omp.c```:

```
#include<stdio.h>
#include<stdlib.h>
#include<omp.h> //header file con prototipos y macro definitions para 
                //la librería de funciones y macros de openMP.

void Hello(void); //prototipo de función a ejecutar por los threads.
int main(int argc, char *argv[]){

    //Siempre iniciamos con un #pragma omp ... :

    #pragma omp parallel //directive parallel: #pragma omp parallel
       //structured block que sólo consiste del llamado a la función Hello: 
        Hello();
return 0;
}

//función que será ejecutada por los threads
void Hello(void){
    int mi_rango = omp_get_thread_num(); //obtenemos el rank dado por
                    //el run-time system a cada thread
    int conteo_threads = omp_get_num_threads(); //obtenemos el número de threads 
                    //que realizaron un fork
                    //del master thread
    printf("Hola del thread: %d de %d\n", mi_rango, conteo_threads);
}

```

Compilar:

```
$gcc -Wall -fopenmp hello_world_omp.c -o hello_world_omp.out
```

añadimos la flag **Wall** para que se detecten warnings o posibles errores al momento de compilación y la flag fopenmp para soporte de openMP.

Ejecutamos:

```
$./hello_world_omp.out
```

Resultado:

```
Hola del thread: 0 de 1
```

Dependiendo del número de cores de nuestro sistema tendremos diferentes número de printf.

Lo que continúa a la línea de **#pragma omp parallel** es un structured block, es decir, un statement o conjunto de statements que tienen un punto de entrada y un punto de salida, no se permiten statements como los siguientes:

```
#pragma omp parallel
    if(...) break;

```

o bien:

```
#pragma omp parallel
    {
        if(variable == valor) return 1;
        return -1;
    }

```


A continuación del nombre **parallel** podemos usar diferentes tipos de clauses, una clause en openMP es un texto que modifica una directive. Por ejemplo, podemos usar la clause **num_threads** para permitir a la programadora especificar el número de threads que ejecutarán el structured block:

## Programa de hello world con un número de threads definido por la usuaria:

```hello_world_omp_modificado.c```:

```
#include<stdio.h>
#include<stdlib.h>
#include<omp.h> //header file con prototipos y macro definitions para 
                //la librería de funciones y macros de openMP.

void Hello(void); //prototipo de función a ejecutar por los threads.
int main(int argc, char *argv[]){
    long conteo_threads;
    conteo_threads = strtol(argv[1], NULL, 10);

    //Siempre iniciamos con un #pragma omp ... :

    #pragma omp parallel num_threads(conteo_threads) //directive parallel con clause num_threads
       //structured block que sólo consiste del llamado a la función Hello: 
        Hello();
return 0;
}

//función que será ejecutada por los threads
void Hello(void){
    int mi_rango = omp_get_thread_num(); //obtenemos el rank dado por
                    //el run-time system a cada thread
    int conteo_threads = omp_get_num_threads(); //obtenemos el número de threads 
                    //que realizaron un fork
                    //del master thread
    printf("Hola del thread: %d de %d\n", mi_rango, conteo_threads);
}

```

Compilamos:

```
$gcc -Wall -fopenmp hello_world_omp_modificado.c -o hello_world_omp_modificado.out
```


Ejecutar con 5 threads:

```
./hello_world_omp_modificado.out 5
```

Resultado:

```
Hola del thread: 0 de 5
Hola del thread: 4 de 5
Hola del thread: 3 de 5
Hola del thread: 2 de 5
Hola del thread: 1 de 5
```

obsérvese el no determinismo. Además pueden haber límites del número de threads que la usuaria puede especificar, esto es definido por el sistema. La mayoría de los sistemas pueden iniciar centenares o miles de threads y casi siempre se obtiene esta cantidad de threads.


## Programa de la regla del trapecio:

### Forma secuencial:


```trapecio_secuencial.c```:

```
#include<stdio.h>
#include<stdlib.h>
#include<math.h> //header para funciones de mate
void Trap(double ext_izq, double ext_der, int num_trap,\
    double *suma_global_p);
double f(double nodo);
int main(int argc, char *argv[]){
    double suma_global = 0.0;
    double a=-1.0, b=3.0;
    int n=1e7; //número de subintervalos
    double objetivo=19.717657482016225;
    Trap(a,b,n,&suma_global);
    printf("Integral de %f a %f = %1.15e\n", a,b,suma_global);
    printf("Error relativo de la solución: %1.15e\n", fabs(suma_global-objetivo)/fabs(objetivo));
    return 0;
}
void Trap(double a, double b, int n, double *sum){
    double h=(b-a)/n;
    double x;
    int i;
    *sum = (f(a)+f(b))/2.0;
    for(i=0;i<=n-1;i++){
        x = a+i*h;
        *sum+=f(x);
    }
    *sum =h*(*sum);
}
double f(double nodo){
    double valor_f;
    valor_f = exp(nodo);
    return valor_f;
}
```

Compilamos:

```
$gcc -Wall trapecio_secuencial.c -o trapecio_secuencial.out -lm
```

Ejecutamos:

```
./trapecio_secuencial.out
```

Resultado:

```
Integral de -1.000000 a 3.000000 = 1.971765762916886e+01
Error relativo de la solución: 7.462987594950100e-09
```

### Forma en paralelo:

Dividimos el número de subintervalos  **n** entre el número de threads que deseamos lanzar, por esto, **n** debe ser **divisible** entre **conteo_threads** y esta cantidad es el número de subintervalos contiguos que le corresponde a cada thread.

Además, se debe de agregar el resultado de la suma de cada thread. Esto es posible realizar de forma sencilla definiendo una variable que sea **shared**. Una variable es **shared** en openMP si puede ser accesada por todos los threads de un **team** y al definir la variable en la función **main** y antes de un parallel block el default es que sea considerada como **shared** . Y como este recurso compartido será actualizado por cada uno de los threads se debe manejar la **critical section** (ver [Notas del curso MNO](https://www.dropbox.com/s/vcxbrqkk6x946d7/2.4.Sistemas_de_memoria_compartida_openMP.pdf?dl=0) para un ejemplo de critical section) por esto hacemos uso de la **directive critical** que se escribe como sigue:

```
#pragma omp critical
```

y como consecuencia se tiene que la ejecución del structured block que le continúa a la critical section es secuencial.


Ejemplo:

```trapecio_paralelo_omp.c```:


```
#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include<math.h> //header para funciones de mate
void Trap(double ext_izq, double ext_der, int num_trap,\
    double *suma_global_p);
double f(double nodo);
int main(int argc, char *argv[]){
    double suma_global = 0.0; //variable que es shared, en esta se sumarán los resultados
                //de las aproximaciones de cada uno de los threads.
    double a=-1.0, b=3.0;
    int n=1e7; //número de subintervalos
    int conteo_threads;//conteo_threads debe dividir de forma exacta a n
    double objetivo=19.717657482016225;
    conteo_threads = strtol(argv[1], NULL, 10);
    #pragma omp parallel num_threads(conteo_threads)
        Trap(a,b,n,&suma_global);
    printf("Integral de %f a %f = %1.15e\n", a,b,suma_global);
    printf("Error relativo de la solución: %1.15e\n", fabs(suma_global-objetivo)/fabs(objetivo));
    return 0;
}
void Trap(double a, double b, int n, double *suma_global_p){
    double h=(b-a)/n;
    double x, local_int; //local_int es la aproximación de cada thread a la integral en los
                    //subintervalos contiguos designados a cada thread.
    double local_a, local_b;
    int i,local_n;
    int mi_rango = omp_get_thread_num();
    int conteo_threads = omp_get_num_threads();
    local_n = n/conteo_threads; //número de subintervalos para cada thread, esta 
                                //división es exacta
    local_a = a + mi_rango*local_n*h; //extremo izquierdo para un thread
    local_b = local_a + local_n*h; //extremo derecho para un thread
    local_int = (f(local_a)+f(local_b))/2.0;
    for(i=0;i<=local_n-1;i++){
        x = local_a+i*h;
        local_int+=f(x);
    }
    local_int =h*local_int;
    //directiva critical:
    #pragma omp critical
        *suma_global_p+=local_int; //critical section, esta línea será ejecutada de forma secuencial
                                //por el uso de la directive critical
}
double f(double nodo){
    double valor_f;
    valor_f = exp(nodo);
    return valor_f;
}
```

Compilar:

```
$gcc -Wall -fopenmp trapecio_paralelo_omp.c -o trapecio_paralelo_omp.out -lm
```

Ejecutar:

```
./trapecio_paralelo_omp.out 10
```

Resultado:

```
Integral de -1.000000 a 3.000000 = 1.971767351834608e+01
Error relativo de la solución: 8.132979220043139e-07
```

Obsérvese que para el mismo número de subintervalos **n = 1e7** se tiene un error relativo menor para el caso del algoritmo en su forma secuencial que en su forma en paralelo. Esto es probablemente resultado de la no asociatividad de la suma en la aritmética de un sistema de punto flotante.


Para este ejemplo, las variables que son shared son: **n, a, b, conteo_threads, suma_global, objetivo** y las variables que son **private** resultan ser las que fueron definidas en la función Trap, una de ellas **suma_global_p** hace referencia a la variable shared **suma_global**, esto es indispensable para la agregación del resultado de cada uno de los threads.

Una alternativa para este programa haciendo que Trap devuelva un valor double es el siguiente programa:

```trapecio_paralelo_omp_alternativa.c```:

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
    #pragma omp parallel num_threads(conteo_threads)
    {
        double local_int = 0.0; //variable que es privada y se usará para 
                                //almacenar el valor aproximado de la Integral
                                //por cada thread
        local_int=Trap(a,b,n);
    //directiva critical:
    #pragma omp critical
        suma_global+=local_int; //manejo de la critical section
    }
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

Compilar: 

```
$gcc -Wall -fopenmp trapecio_paralelo_omp_alternativa.c -o trapecio_paralelo_omp_alternativa.out -lm
```

Ejecutar:

```
$./trapecio_paralelo_omp_alternativa.out 10
```

Resultado:

```
Integral de -1.000000 a 3.000000 = 1.971767351834609e+01
Error relativo de la solución: 8.132979221844932e-07
```
