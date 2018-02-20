# Ejemplos con openmpi

Para los siguientes ejemplos, se supone que se ha [levantado un cluster de forma pseudo distribuida con openMPI y docker](/C/extensiones_a_C/MPI/openMPI/
) o bien se siguió el [tutorial de uso de AWS con OpenMPI](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/wiki/Iniciar-cluster-con-Autoscaling-y-OpenMPI) ambos enfoques para un sistema ubuntu. De acuerdo a las arquitecturas anteriores compilar y ejectuar los siguientes programas ejemplo.

## Comunicación punto a punto:

### Programa de hello world:

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
$mpirun -n 5 hello_clase.out
```

Resultado:

```
Hola del procesador 0 de 5!
Hola del procesador 1 de 5!
Hola del procesador 2 de 5!
Hola del procesador 3 de 5!
Hola del procesador 4 de 5!
```

Ejecutar de forma pseudo distribuida:

```
$mpirun --prefix $inst_ompi -n 2 -H master,nodo1 hello_clase.out
```

**(La variable `inst_ompi` está definida en el ambiente de bash y apunta a la ruta en la que está instalado openMPI)**

La sintaxis de las funciones `MPI_Send` y `MPI_Recv` es:

```
int MPI_Send(
    void            *message   /*in*/,
    int             count       /*in*/,
    MPI_Datatype    datatype    /*in*/,
    int             dest        /*in*/,
    int             tag         /*in*/,
    MPI_Comm        comm        /*in*/
)
```

```
int MPI_Recv(
    void            *message    /*out*/,
    int             count       /*in*/,
    MPI_Datatype    datatype    /*in*/,
    int             source      /*in*/,
    int             tag         /*in*/,
    MPI_Comm        comm        /*in*/,
    MPI_Status      *status     /*out*/
)
```

### Programa de trapecio compuesto:

`trapecio_compuesto_mpi.c`:

```
#include<stdio.h>
#include<mpi.h>
#include<math.h>
//prototipo de Trap:
double Trap(double ext_izq, double ext_der, int num_trap, double longitud_base);
int main(void){
    int mi_rango;
    int comm_sz;
    int n=1e7;//número de trapecios
    int local_n;
    double a=-1.0, b=3.0,h;
    double objetivo=19.717657482016225;
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
    if(mi_rango == 0){
        printf("Valor de la integral de %f a %f es: %1.14e\n",a,b,total_int);
        printf("Error relativo de la solución: %1.15e\n", fabs(total_int-objetivo)/fabs(objetivo));
    }
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
$mpirun --prefix $inst_ompi -n 2 -H master,nodo1 trapecio_compuesto_mpi.out
```

Resultado:

```
Valor de la integral de -1.000000 a 3.000000 es: 1.97176574820423e+01
```

Si hacemos que el procesador con rank 0 lea con scanf tenemos el siguiente código:

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
    double objetivo=19.717657482016225;
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
    if(mi_rango == 0){
        printf("Valor de la integral de %f a %f es: %1.14e\n",a,b,total_int);
        printf("Error relativo de la solución: %1.15e\n", fabs(total_int-objetivo)/fabs(objetivo));
    }
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
Introduce valores de a, b, n
-1 3 1000000
Valor de la integral de -1.000000 a 3.000000 es: 1.97176574820423e+01
```

Obs: se usó diferentes tags sólo por seguridad, MPI garantiza que una secuencia de mensajes enviados de un proceso a otro serán recibidos en el orden en el que fueron enviados.

## Comunicación colectiva (broadcast, reduce y allreduce):

Ahorramos escribir líneas de **send** y **receive** si utilizamos un **broadcast** para distribuir los valores de a, b y n a los demás procesos a partir del proceso que leyó los datos de entrada:

`trapecio_compuesto_input_data_cmd_line_and_broadcast.c`:

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
    double objetivo=19.717657482016225;
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
    if(mi_rango == 0){
        printf("Valor de la integral de %f a %f es: %1.14e\n",a,b,total_int);
        printf("Error relativo de la solución: %1.15e\n", fabs(total_int-objetivo)/fabs(objetivo));
    }
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
    }
    MPI_Bcast(a, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
    MPI_Bcast(b, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
    MPI_Bcast(n, 1, MPI_INT, 0, MPI_COMM_WORLD);
}

```

La función `MPI_Bcast` tiene la sintaxis:

```
int MPI_Bcast(
    void            *message         /*in/out*/,
    int             count            /*in */,
    MPI_Datatype    datatype         /* in*/,
    int             root             /*in */,
    MPI_Comm        comm             /*in*/
    )
```

y cada proceso ejecuta el **broadcast** en un mismo orden, es decir, la secuencia de broadcasts que ejecuta el proceso 1 hacen match con la secuencia de broadcasts que ejecuta el proceso 0 en el mismo orden (sincronización), así se garantiza que se almacenen las variables en la localidad de memoria correcta.

`root` es el proceso que se encargará de distribuir el mensaje.

Obs: A diferencia de la comunicación punto a punto, los argumentos `root`, `count` y `datatype` deben ser los mismos en todos los procesos del communicator `comm` y obsérvese que no se tiene un argumento para un `tag` (de hecho todas las funciones colectivas no usan tags).

Un último cambio al código anterior, sería ejecutar un **reduce** por todos los procesadores, así se evita que el proceso 0 tenga todo el trabajo de hacer la suma final:


`trapecio_compuesto_input_data_cmd_line_and_broadcast_and_reduce.c`:

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
    double objetivo=19.717657482016225;
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
    MPI_Reduce(&local_int, &total_int, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
    if(mi_rango == 0){
        printf("Valor de la integral de %f a %f es: %1.14e\n",a,b,total_int);
        printf("Error relativo de la solución: %1.15e\n", fabs(total_int-objetivo)/fabs(objetivo));
    }
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
    }
    MPI_Bcast(a, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
    MPI_Bcast(b, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
    MPI_Bcast(n, 1, MPI_INT, 0, MPI_COMM_WORLD);
}

```

Compilamos:

```
$mpicc trapecio_compuesto_input_data_cmd_line_and_broadcast_and_reduce.c -o trapecio_compuesto_input_data_cmd_line_and_broadcast_and_reduce.out -lm
```

Ejecutamos:

```
$mpiexec -n 10 trapecio_compuesto_input_data_cmd_line_and_broadcast_and_reduce.out
```

Resultado:

```
Introduce valores de a, b, n
-1 3 1000000
Valor de la integral de -1.000000 a 3.000000 es: 1.97176574820423e+01
```

La sintaxis del `MPI_Reduce` es la siguiente:

```
int MPI_Reduce(
    void           *operand     /*in*/,
    void           *result      /*out*/,
    int             count       /*in*/,
    MPI_Datatype    datatype    /*in*/,
    MPI_Op          operator    /*in*/,
    int             root        /*in*/,
    MPI_Comm        comm        /*in*/
)
```

Así como con `MPI_Broadcast` la función `MPI_Reduce` debe ser llamada por todos los procesos en el comunicator `comm` y `count`, `datatype`, `operator` y `root` deben tener los mismos valores. Obs: `operand` y `result` deben ser variables distintas. `root` es el único proceso que tendrá el `result`, en el caso del programa del trapecio es `total_int`, si quisiéramos que todos los procesos almacenaran `total_int` en lugar de hacer primero un **reduce** seguido de un **broadcast** usaríamos la función `MPI_Allreduce` y por ejemplo si queremos que el proceso con rank igual a 1 imprima el resultado tendríamos:

`trapecio_compuesto_input_data_cmd_line_and_broadcast_and_allreduce.out`:

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
    double objetivo=19.717657482016225;
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
    MPI_Allreduce(&local_int, &total_int, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);
    if(mi_rango == 1){
        printf("Valor de la integral de %f a %f es: %1.14e\n",a,b,total_int);
        printf("Error relativo de la solución: %1.15e\n", fabs(total_int-objetivo)/fabs(objetivo));
    }
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
    }
    MPI_Bcast(a, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
    MPI_Bcast(b, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
    MPI_Bcast(n, 1, MPI_INT, 0, MPI_COMM_WORLD);
}

```

La sintaxis de `MPI_Allreduce` es:

```
int MPI_ALLreduce(
    void           *operand     /*in*/,
    void           *result      /*out*/,
    int             count       /*in*/,
    MPI_Datatype    datatype    /*in*/,
    MPI_Op          operator    /*in*/,
    MPI_Comm        comm        /*in*/
)

```

Compilamos:

```
$mpicc trapecio_compuesto_input_data_cmd_line_and_broadcast_and_allreduce.c -o trapecio_compuesto_input_data_cmd_line_and_broadcast_and_allreduce.out -lm
```

Ejecutamos:

```
$mpiexec -n 10 trapecio_compuesto_input_data_cmd_line_and_broadcast_and_allreduce.out
```

Resultado:

```
Introduce valores de a, b, n
-1 3 1000000
Valor de la integral de -1.000000 a 3.000000 es: 1.97176574820423e+01
```