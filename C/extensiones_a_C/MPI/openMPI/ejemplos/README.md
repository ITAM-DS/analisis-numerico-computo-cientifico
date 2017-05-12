# Ejemplos con openmpi

Para los siguientes ejemplos, se supone que se ha [levantado un cluster de forma pseudo distribuida con openMPI y docker](../). 

Se compilarán y ejecutarán los ejemplos en el master_container.

## Programa de hello world:

`hello_clase.c`:

```
#include<stdio.h>
#include<string.h>
#include<mpi.h>
int main(){
    int max_string=100;
    char greeting[max_string];
    int comm_sz;
    int my_rank;
    int q;
    MPI_Init(NULL,NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    if(my_rank!=0){
     sprintf(greeting, "Hola del procesador %d de %d!", my_rank, comm_sz);
     MPI_Send(greeting, strlen(greeting)+1,MPI_CHAR,0,0,MPI_COMM_WORLD);    
    }else{
     printf("Hola del procesador %d de %d!\n", my_rank, comm_sz);
     for(q=1;q<comm_sz;q++){
      MPI_Recv(greeting, max_string, MPI_CHAR,q,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
      printf("%s\n",greeting);
     }
    }
    MPI_Finalize();
return 0;
}
```

Compilar:

```
$mpicc hello_clase.c -o hello_clase.out
```
Ejecutar con un sólo procesador:

```
$mpiexec -n 5 hello_clase.out
```

Ejecutar de forma pseudo distribuida:

```
$mpirun --prefix /opt/openmpi-2.0.2/ -n 2 -H master,nodo1 hello_clase.out
```

## Programa de trapecio compuesto:

`trapecio_compuesto_mpi`:

```
#include<stdio.h>
#include<mpi.h>
#include<math.h>
//prototipo de Trap:
double Trap(double ext_izq, double ext_der, int num_trap, double longitud_base);
int main(void){
    int mi_rango;
    int comm_sz;
    int n=1e6;//número de trapecios
    int local_n;
    double a=-1.0, b=3.0,h;
    double local_a, local_b,local_int, total_int;
    //local_int estima por cada proceso con la regla del trapecio
    //la integral
    int num_proceso_contador;
    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
    MPI_Comm_rank(MPI_COMM_WORLD, &mi_rango);
    h=(b-a)/n; //el valor de h es el mismo para todos los procesos
    local_n = n/comm_sz;//número de subintervalos para cada proceso
    local_a = a + mi_rango*local_n*h;//calculamos el extremo izquierdo
    local_b = local_a + local_n*h;//calculamos el extremo derecho
    local_int = Trap(local_a, local_b, local_n, h);
    if(mi_rango!= 0)
     MPI_Send(&local_int, 1, MPI_DOUBLE, 0,0,MPI_COMM_WORLD);
    else{
        total_int = local_int;
        for(num_proceso_contador=1;num_proceso_contador<comm_sz;num_proceso_contador++){
            MPI_Recv(&local_int, 1, MPI_DOUBLE, num_proceso_contador, 0, MPI_COMM_WORLD,MPI_STATUS_IGNORE);
            total_int+=local_int;
        }//for
    }//else
    if(mi_rango == 0)
        printf("Valor de la integral de %f a %f es: %1.14e\n",a,b,total_int);
    MPI_Finalize();
    return 0;
}//main
//prototipo de f:
double f(double nodo);
double Trap(double ext_izq, double ext_der, int num_trap, double longitud_base){
    double estimacion;
    double x;
    int contador;
    estimacion = (f(ext_izq) + f(ext_der))/2.0;
    for(contador=1;contador<=num_trap-1;contador++){
        x =ext_izq + contador*longitud_base;
        estimacion += f(x);
    }
    estimacion=estimacion*longitud_base;
    return estimacion;
}
//la regla de correspondencia f del integrando
double f(double nodo){
    double valor_f;
    valor_f = exp(nodo);
    return valor_f;
}
```

Compilar: 

```
$mpicc trapecio_compuesto_mpi.c -o trapecio_compuesto_mpi.out -lm
```

Ejecutar con un sólo procesador:

```
$mpiexec -n 10 trapecio_compuesto_mpi.out
```

Ejecutar de forma pseudodistribuida:

```
$mpirun --prefix /opt/openmpi-2.0.2/ -n 2 -H master,nodo1 trapecio_compuesto_mpi.out
```

Resultado:

```
Valor de la integral de -1.000000 a 3.000000 es: 1.97176574820423e+01
```

Si hacemos que el procesador con rank 0 lea con scanf:

`trapecio_compuesto_input_data_cmd_line.c`:

```
#include<stdio.h>
#include<mpi.h>
#include<math.h>
//prototipo de Trap:
double Trap(double ext_izq, double ext_der, int num_trap_local, double longitud_base);
void lee_constantes(double *ext_izq, double *ext_der, int *num_trap, int rank_proceso, int num_procesos);
int main(void){
    int mi_rango;
    int comm_sz;
    int n;//número de trapecios
    int local_n;
    double a, b,h;
    double local_a, local_b,local_int, total_int;
    //local_int estima por cada proceso con la regla del trapecio
    //la integral
    int num_proceso_contador;

    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
    MPI_Comm_rank(MPI_COMM_WORLD, &mi_rango);
    lee_constantes(&a, &b, &n, mi_rango, comm_sz);
    h=(b-a)/n; //el valor de h es el mismo para todos los procesos
    local_n = n/comm_sz;//número de subintervalos para cada proceso
    local_a = a + mi_rango*local_n*h;//calculamos el extremo izquierdo
    local_b = local_a + local_n*h;//calculamos el extremo derecho
    local_int = Trap(local_a, local_b, local_n, h);
    if(mi_rango!= 0)
     MPI_Send(&local_int, 1, MPI_DOUBLE, 0,0,MPI_COMM_WORLD);
    else{
        total_int = local_int;
        for(num_proceso_contador=1;num_proceso_contador<comm_sz;num_proceso_contador++){
            MPI_Recv(&local_int, 1, MPI_DOUBLE, num_proceso_contador, 0, MPI_COMM_WORLD,MPI_STATUS_IGNORE);
            total_int+=local_int;
        }//for
    }//else
    if(mi_rango == 0)
        printf("Valor de la integral de %f a %f es: %1.14e\n",a,b,total_int);
    MPI_Finalize();
    return 0;
}//main
//prototipo de f:
double f(double nodo);
double Trap(double ext_izq, double ext_der, int num_trap, double longitud_base){
    double estimacion;
    double x;
    int contador;
    estimacion = (f(ext_izq) + f(ext_der))/2.0;
    for(contador=1;contador<=num_trap-1;contador++){
        x =ext_izq + contador*longitud_base;
        estimacion += f(x);
    }
    estimacion=estimacion*longitud_base;
    return estimacion;
}
//la regla de correspondencia f del integrando
double f(double nodo){
    double valor_f;
    valor_f = exp(nodo);
    return valor_f;
}
void lee_constantes(double *a, double *b, int *n, int rank, int comm_sz){
    int procesador_fuente=0, procesador_destino;
    int tag;
    MPI_Status status;
    if(rank == 0){
        printf("Introduce valores de a, b, n\n");
        scanf("%lf %lf %d", a, b, n);
        for(procesador_destino=1;procesador_destino<comm_sz;procesador_destino++){
            tag=0;
            MPI_Send(a,1,MPI_DOUBLE,procesador_destino,tag,MPI_COMM_WORLD);
            tag=1;
            MPI_Send(b,1,MPI_DOUBLE,procesador_destino,tag,MPI_COMM_WORLD);
            tag=2;
            MPI_Send(n,1,MPI_INT,procesador_destino,tag,MPI_COMM_WORLD);
        }
    }
    else{
        tag=0;
            MPI_Recv(a,1,MPI_DOUBLE,procesador_fuente,tag,MPI_COMM_WORLD, &status);
        tag=1;
            MPI_Recv(b,1,MPI_DOUBLE,procesador_fuente,tag,MPI_COMM_WORLD, &status);
        tag=2;
            MPI_Recv(n,1,MPI_DOUBLE,procesador_fuente,tag,MPI_COMM_WORLD, &status);
    }

}

```

Compilamos:

```
$mpicc trapecio_compuesto_input_data_cmd_line.c -o trapecio_compuesto_input_data_cmd_line.out -lm
```

Ejecutamos:

```
$mpiexec -n 10 trapecio_compuesto_input_data_cmd_line.out
```

Después de insertar los valores separados uno a uno por espacio y dar enter (a=-1, b=3, n=1000000), se tiene el resultado:

```
Valor de la integral de -1.000000 a 3.000000 es: 1.97176574820423e+01
```

