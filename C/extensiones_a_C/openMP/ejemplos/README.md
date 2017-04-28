## Programa de hello world:

```
#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
void Hello(void); //función a ejecutar por los threads
int main(int argc, char *argv[]){
    long thread_count;
    thread_count = strtol(argv[1], NULL, 10);
    #pragma omp parallel num_threads(thread_count) //directiva
                    //pragma omp
        Hello();
return 0;
}
void Hello(void){
    int my_rank = omp_get_thread_num();
    int thread_count = omp_get_num_threads(); //obtenemos
                    //el número de threads que fueron forkeados
    printf("Hola del thread: %d de %d\n", my_rank, thread_count);
}

```

Compilar:

```
$gcc -Wall -fopenmp hello_omp.c -o hello_omp.out
```

Ejecutar:

```
./hello_omp.out 5
```

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
$./omp_trap.out 10
```


