## Programa de hello world:

```
#include<stdio.h>
#include<stdlib.h> //para malloc
#include<pthread.h>
int thread_count; //variable global
//prototipo función a ejecutar por cada thread:
void *Hello(void * p); //recibe y devuelve un apuntador a un tipo de 
            //dato void
int main(int argc, char *argv[]){
    long int thread; //para nombrar a los threads
    pthread_t *thread_handles; //para almacenar información de cada thread
    thread_count = strtol(argv[1],NULL,10);//obtenemos de la línea
                //de comandos el número de threads para forks-off
                // del proceso
    thread_handles = malloc(thread_count*sizeof(pthread_t)); //alojamos en heap
    for(thread=0;thread<thread_count;thread++)
        pthread_create(&thread_handles[thread], NULL, Hello, \
            (void *)thread);
    printf("Hola del main thread\n");
    for(thread=0;thread<thread_count;thread++)
        pthread_join(thread_handles[thread],NULL);
    free(thread_handles);
    return 0;
}
void *Hello(void * rank){
    long int my_rank = (long int)rank;//convertimos a un tipo de dato
                    //long int
    printf("Hola del thread %ld de %d\n", my_rank, thread_count);
    return NULL;
}
```

Compilar: 

```
$gcc -Wall pth_hello.c -o pth_hello.out -lpthread
```

Ejecutar:

```
./pth_hello.out 4
```

## Estimación de pi (mala estimación):

```
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
int thread_count;
double sum=0.0;
int n=1.e8;
void *Thread_sum(void*);
int main(int argc, char *argv[]){
    long thread;
    pthread_t *thread_handles;
    thread_count = strtol(argv[1], NULL, 10);
    thread_handles = malloc(thread_count*sizeof(pthread_t));
    for(thread=0;thread<thread_count;thread++)
        pthread_create(&thread_handles[thread], NULL, Thread_sum, (void*)thread);
    for(thread=0;thread<thread_count;thread++)
        pthread_join(thread_handles[thread],NULL);
    sum=4.0*sum;
    printf("Estimación de pi: %1.12f\n",sum);
return 0;
}
void *Thread_sum(void *rank){
    long my_rank =(long)rank;
    double factor;
    int i;
    int my_n=n/thread_count;
    int my_first_i=my_n*my_rank;
    int my_last_i=my_first_i+my_n;
    if(my_first_i%2==0)
        factor=1.0;
    else
        factor=-1.0;
    for(i=my_first_i;i<my_last_i;i++,factor=-factor)
        sum+=factor/(2*i+1);
 
return NULL;
}
```

Compilar:

```
$gcc -g -Wall estimacion_mala_de_pi.c -o estimacion_mala_de_pi.out -lpthread
```

Ejecutar:

```
./estimacion_mala_de_pi.out 4
```

## Estimación de pi (corregida):

```
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
int thread_count;
double sum=0.0;
int n=1.e8;
void *Thread_sum(void*);
pthread_mutex_t mutex;
int main(int argc, char *argv[]){
    long thread;
    pthread_t *thread_handles;
    thread_count = strtol(argv[1], NULL, 10);
    thread_handles = malloc(thread_count*sizeof(pthread_t));
    pthread_mutex_init(&mutex, NULL);
    for(thread=0;thread<thread_count;thread++)
        pthread_create(&thread_handles[thread], NULL, Thread_sum, (void*)thread);
    for(thread=0;thread<thread_count;thread++)
        pthread_join(thread_handles[thread],NULL);
    sum=4.0*sum;
    printf("Estimación de pi: %1.12f\n",sum);
    pthread_mutex_destroy(&mutex);
return 0;
}
void *Thread_sum(void *rank){
    long my_rank =(long)rank;
    double factor;
    int i;
    int my_n=n/thread_count;
    int my_first_i=my_n*my_rank;
    int my_last_i=my_first_i+my_n;
    double my_sum=0.0;
    if(my_first_i%2==0)
        factor=1.0;
    else
        factor=-1.0;
    for(i=my_first_i;i<my_last_i;i++,factor=-factor)
        my_sum+=factor/(2*i+1);
    pthread_mutex_lock(&mutex);
        sum+=my_sum;
    pthread_mutex_unlock(&mutex);
return NULL;
}
```
Compilar:

```
$gcc -g -Wall estimacion_de_pi.c -o estimacion_de_pi.out -lpthread
```

Ejecutar:

```
$./estimacion_de_pi.out 4
```

## Multiplicación de matriz vector:

```
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
int thread_count;
int A[4][4] = {
    {-1,1,2,1},
    {1,0,1,-1},
    {1,0,0,1},
    {-1,1,1,3}
    };
int x[4]={1,1,0,-1};
int y[4];
int n=4;
int m=4;
void *Pth_mat_vect(void*);
void print_matrix(void);
void print_vector(int *);
int main(int argc, char *argv[]){
    long thread;
    pthread_t *thread_handles;
    thread_count =strtol(argv[1], NULL, 10);
    thread_handles=malloc(thread_count*sizeof(pthread_t));
    print_matrix();
    printf("vector x:\n");
    print_vector(x);
    printf("vector y:\n");
    print_vector(y);
    for(thread=0;thread<thread_count;thread++)
        pthread_create(&thread_handles[thread], NULL, Pth_mat_vect,
            (void*)thread);
    for(thread=0;thread<thread_count;thread++)
        pthread_join(thread_handles[thread], NULL);
    free(thread_handles);
    printf("result vector:\n");
    print_vector(y);
return 0;
}
void *Pth_mat_vect(void *rank){
    long my_rank=(long)rank;
    int i,j;
    int local_m=m/thread_count;
    int my_first_row=my_rank*local_m;
    int my_last_row=(my_rank+1)*local_m-1;
    for(i=my_first_row;i<=my_last_row;i++){
        y[i]=0.0;
        for(j=0;j<n;j++)
            y[i]+=A[i][j]*x[j]; 
    }
return NULL;
}
void print_matrix(void){
    int i,j;
    for(i=0;i<m;i++){
        for(j=0;j<n-1;j++)
            printf("A[%d][%d]=%d\t",i,j,A[i][j]);
        printf("A[%d][%d]=%d\n",i,j,A[i][j]);
    }
printf("-----------------\n");
}
void print_vector(int *vec){
    int i;
    for(i=0;i<m;i++)
        printf("vec[%d]=%d\n",i,vec[i]);
printf("-----------------\n");
}
```

Compilar:

```
$gcc -g -Wall mult_mat_pthreads.c -o mult_mat_pthreads.out -lpthread
```

Ejecutar:

```
$./mult_mat_pthreads.out 4
```

## Ejemplo de función ejecutada por Pthreads para regresar valor:

```
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
void *funcion(void *p){
    long int num = (long int)p;
    char *c;
    c=num==0?"valor igual a cero":"valor igual a uno";
    return c;
}
int main(void){
    pthread_t thread_info;
    long int valor;
    char *caracter;
    valor=0;
    pthread_create(&thread_info, NULL, funcion, (void *) valor);
    pthread_join(thread_info, (void *)&caracter);
    printf("valor regresado de funcion: %s\n", caracter);
    valor=1;
    pthread_create(&thread_info, NULL, funcion, (void *) valor);
    pthread_join(thread_info, (void *) &caracter);
    printf("valor regresado de funcion: %s\n", caracter);
    return 0;
}
```

Compilar:

```
gcc -g -Wall ejemplo_regreso_de_funcion_pthreads.c -o ejemplo_regreso_de_funcion_pthreads.out -lpthread
```

Ejecutar:

```
./ejemplo_regreso_de_funcion_pthreads.out
```

Salida:

```
valor regresado de funcion: valor igual a cero
valor regresado de funcion: valor igual a uno
```

