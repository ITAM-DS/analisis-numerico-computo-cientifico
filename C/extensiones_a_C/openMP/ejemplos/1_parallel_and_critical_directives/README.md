# Ejemplos con openMP

Para los siguientes ejemplos suponemos un sistema ubuntu 14.04 (o más reciente) y que está instalado el paquete build-essential o hacemos:

```
$sudo apt-get update -y && sudo apt-get install -y build-essential

```
para instalar el compilador **gcc**.

Usamos **pragmas** para indicar al preprocesador (vía la compilación) que ejecutaremos una instrucción que no se encuentra en la especificación básica del lenguaje C, esto se le conoce con el nombre de **directive**.

Cabe señalar que las versiones más recientes de **gcc** sí soportan a los **pragmas** y todas las preprocessor directive son por default de longitud una línea. Si no cabe en una línea usamos un escaping (precedemos con un backslash "\" la "nueva línea").

Los pragmas de openMP siempre inician con:

```
# pragma omp
```

## Programa de hello world:

```
#include<stdio.h>
#include<stdlib.h>
#include<omp.h> //header file con prototipos y macro definitions para 
                //la librería de funciones y macros de openMP.

void Hello(void); //función a ejecutar por los threads
int main(int argc, char *argv[]){
    long thread_count;
    thread_count = strtol(argv[1], NULL, 10);
    //Siempre iniciamos con un #pragma omp la directive:

    #pragma omp parallel num_threads(thread_count) //directive parallel
       //structured block: 
        Hello();
return 0;
}

//función que será ejecutada por los threads
void Hello(void){
    int my_rank = omp_get_thread_num(); //obtenemos el rank dado por
                    //el run-time system a cada thread
    int thread_count = omp_get_num_threads(); //obtenemos
                    //el número de threads que realizaron un fork
                    //del master thread
    printf("Hola del thread: %d de %d\n", my_rank, thread_count);
}

```

Compilar:

```
$gcc -Wall -fopenmp hello_omp.c -o hello_omp.out
```

añadimos la flag **Wall** para que se detecten warnings o posibles errores al momento de compilación y la flag fopenmp para soporte de openMP.

Ejecutar con 5 threads:

```
./hello_omp.out 5
```

Resultado:

```
Hola del thread: 0 de 5
Hola del thread: 4 de 5
Hola del thread: 3 de 5
Hola del thread: 2 de 5
Hola del thread: 1 de 5
```

obsérvese el no determinismo.

## Programa de la regla del trapecio:

```
#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include<math.h>
void Trap(double ext_izq, double ext_der, int num_trap,\
    double *global_result_p);
double f(double node);
int main(int argc, char *argv[]){
    double global_result = 0.0;
    double a=-1.0, b=3.0;
    int n=1e8; //número de subintervalos
    int thread_count;
    thread_count = strtol(argv[1], NULL, 10);
    #pragma omp parallel num_threads(thread_count)
        Trap(a,b,n,&global_result);
    printf("Integral de %f a %f = %1.14f\n", a,b,global_result);
    return 0;
}
void Trap(double a, double b, int n, double *global_result_p){
    double h=(b-a)/n;
    double x, my_result;
    double local_a, local_b;
    int i,local_n;
    int my_rank = omp_get_thread_num();
    int thread_count = omp_get_num_threads();
    local_n = n/thread_count;
    local_a = a + my_rank*local_n*h;
    local_b = local_a + local_n*h;
    my_result = (f(local_a)+f(local_b))/2.0;
    for(i=0;i<=local_n-1;i++){
        x = local_a+i*h;
        my_result+=f(x);
    }
    my_result =h*my_result;
    //directiva critical:
    #pragma omp critical
        *global_result_p+=my_result;
}
double f(double nodo){
    double valor_f;
    valor_f = exp(nodo);
    return valor_f;
}
```

Compilar:

```
$gcc -Wall -fopenmp omp_trap.c -o omp_trap.out -lm
```

Ejecutar:

```
./omp_trap.out 10
```

Una alternativa para este programa es:

```
#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include<math.h>
double Trap(double ext_izq, double ext_der, int num_trap);
double f(double node);
int main(int argc, char *argv[]){
    double global_result = 0.0;
    double a=-1.0, b=3.0;
    int n=1e8; //número de subintervalos
    int thread_count;
    thread_count = strtol(argv[1], NULL, 10);
    #pragma omp parallel num_threads(thread_count)
    {
        double my_result = 0.0;
        my_result=Trap(a,b,n);
    //directiva critical:
    #pragma omp critical
        global_result+=my_result;
    }
    printf("Integral de %f a %f = %1.14f\n", a,b,global_result);
    return 0;
}
double Trap(double a, double b, int n){
    double h=(b-a)/n;
    double x, my_result;
    double local_a, local_b;
    int i,local_n;
    int my_rank = omp_get_thread_num();
    int thread_count = omp_get_num_threads();
    local_n = n/thread_count;
    local_a = a + my_rank*local_n*h;
    local_b = local_a + local_n*h;
    my_result = (f(local_a)+f(local_b))/2.0;
    for(i=0;i<=local_n-1;i++){
        x = local_a+i*h;
        my_result+=f(x);
    }
    my_result =h*my_result;
    return my_result;
}
double f(double nodo){
    double valor_f;
    valor_f = exp(nodo);
    return valor_f;
}

```

Compilar: 

```
$gcc -Wall -fopenmp omp_trap_alternativa.c -o omp_trap_alternativa.out -lm
```

Ejecutar:

```
$./omp_trap_alternativa.out 10
```


