# Ejemplos con openmpi

Para los siguientes ejemplos, se supone que se ha [levantado un cluster de forma pseudo distribuida con openMPI y docker](/C/extensiones_a_C/MPI/openMPI/
) o bien se siguió el [tutorial de uso de AWS con OpenMPI](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/wiki/Iniciar-cluster-con-Autoscaling-y-OpenMPI) ambos enfoques para un sistema ubuntu. De acuerdo a las arquitecturas anteriores compilar y ejectuar los siguientes programas ejemplo.

## Comunicación colectiva (scatter, gather):

Supongamos que quisiéramos distribuir un vector entre los procesos que son iniciados por **MPI_Init** vía línea de comando en una forma block-order. Para fijar ideas consideramos el siguiente archivo:

`x.txt`:

```
1
2
3
4
5
6
7
8
9
10
11
12
```

y si son iniciados **4** procesos entonces el proceso con rank 0 recibirá los datos 1,2,3 el proceso con rank 1 recibirá 4,5,6 y así sucesivamente. Lo anterior lo podemos realizar con `MPI_Scatter` cuya sintaxis es:

```
int MPI_Scatter(
	void			*send_data		*/in*/,
	int 			send_count 		*/in*/,
	MPI_Datatype    	send_type 		*/in*/,
	void			*recv_data		*/out*/,
	int 			recv_count 		*/in*/,
	MPI_Datatype    	recv_type 		*/in*/,
	int 			root 			*/in*/,
	MPI_Comm 		comm 			*/in*/
)

```

`MPI_Scatter` splits los datos referenciados por `send_data` en el proceso con rank `root` en número de segmentos igual al número de procesos en el communicator `comm`. El primer segmento es enviado al proceso con rank 0, el segundo al proceso con rank 1 y así sucesivamente. `root` y `comm` deben ser los mismos en todos los procesos. Los parámetros `send_count` y `send_type` son importantes sólo para el proceso con rank `root`.

¿Qué pasaría si en lugar de que el número de procesos no dividiera al número de entradas del vector? Una posibilidad es realizar un padding con ceros al vector que será leído de modo que todos los procesos tengan mismo número de entradas. A lo más realizaremos un padding con número de procesos - 1. Entonces no añadimos muchos datos.

Si después de distribuir los datos quisiéramos colectarlos nuevamente usaríamos la función de `MPI_Gather` cuya sintaxis es:

```
int MPI_Gather(
	void			*send_data		*/in*/,
	int 			send_count 		*/in*/,
	MPI_Datatype    	send_type 		*/in*/,
	void			*recv_data		*/out*/,
	int 			recv_count 		*/in*/,
	MPI_Datatype    	recv_type 		*/in*/,
	int 			root 			*/in*/,
	MPI_Comm 		comm 			*/in*/
)
```

y `MPI_Gather` colecta los datos referenciados por `send_data` de cada proceso en el communicator `comm` y se almacena en el proceso con rank `root` en la memoria referenciada por `recv_data`. A los datos del proceso 0 le continúan los datos del proceso 1, a continuación los del proceso 2 y así sucesivamente. Hay que hacer notar que tanto los parámetros `recv_count`, `recv_type` y `send_count`, `send_type` especifican el número de elementos y el tipo de elementos recibidos de *cada proceso*, no especifican el total de datos recibidos. De hecho, los parámetros `recv_count`, `recv_type` sólo les son importantes al proceso `root`.

Obsérvese que `MPI_Scatter` y `MPI_Gather` tienen la misma sintaxis.

Un ejemplo para lo anterior considera los siguientes archivos:

`definiciones.h`:

```
#include<mpi.h>
typedef struct{
MPI_Comm *comm;
#define Comm_pointer_vector(arreglo) ((arreglo)->comm)
#define Comm_vector(arreglo) (*((arreglo)->comm))
int comm_size;
#define Comm_size(arreglo) ((arreglo)->comm_size)
int mirank;
#define Comm_rank(arreglo) ((arreglo)->mirank)
int n;
#define renglones_vector(arreglo) ((arreglo)->n)
int n_ceros_added;
#define renglones_vector_added_ceros(arreglo) ((arreglo)->n_ceros_added)
double *arr;
#define entradas_vector(arreglo) ((arreglo)->arr)
#define entrada_vector(arreglo,i) ((arreglo)->arr[i])
int nlocal;
#define renglones_vector_local(arreglo) ((arreglo)->nlocal)
double *arrlocal;
#define entradas_vector_local(arreglo) ((arreglo)->arrlocal)
#define entrada_vector_local(arreglo,i) ((arreglo)->arrlocal[i])
}arreglo_1d;
typedef arreglo_1d *arreglo_1d_T;
void imprime_vector(arreglo_1d_T);
void inicializa_vector(arreglo_1d_T, char *);
void inicializa_vector_ceros(arreglo_1d_T);
void inicializa_vector_ceros_local(arreglo_1d_T);
void imprime_vector_local(arreglo_1d_T p);
void imprime_entradas_almacenadas_en_procesos(arreglo_1d_T);
void inicializa_vector_mpi(arreglo_1d_T, char *);
void incrementa_size_array(arreglo_1d_T);
```


`funciones.c`:

```
#include<stdio.h>
#include<stdlib.h>
#include"definiciones.h"
static int i,j;
void inicializa_vector(arreglo_1d_T p, char *s){
	int m = renglones_vector(p);
	FILE * pFile;
  	pFile = fopen (s,"r");
  	for(i=0;i<m;i++)
			fscanf(pFile,"%lf", &entrada_vector(p,i));
	fclose(pFile);
}
void inicializa_vector_ceros(arreglo_1d_T p){
	int n = renglones_vector(p);
	for(j=0;j<n;j++)
		entrada_vector(p,j)=0;
}
void inicializa_vector_ceros_local(arreglo_1d_T p){
	int n = renglones_vector_local(p);
	for(j=0;j<n;j++)
		entrada_vector_local(p,j)=0;
}
void imprime_vector(arreglo_1d_T p){
	int m = renglones_vector(p);
		for(i=0;i<m;i++)
				printf("vector[%d]=%.5f\n",i,entrada_vector(p,i));
}
void imprime_vector_local(arreglo_1d_T p){
	int m = renglones_vector_local(p);
		for(i=0;i<m;i++)
				printf("vector[%d]=%.5f\n",i,entrada_vector_local(p,i));
}
void inicializa_vector_mpi(arreglo_1d_T a, char *s){
	if(Comm_rank(a)==0){
		entradas_vector(a)=malloc(renglones_vector_added_ceros(a)*sizeof(double));
		inicializa_vector(a,s);
		for(i=renglones_vector(a);i<renglones_vector_added_ceros(a);i++)
			entrada_vector(a,i)=0.0;
	}
}
void imprime_entradas_almacenadas_en_procesos(arreglo_1d_T a){
	int tag=0;
	int destino=0;
	int fuente;
	int i;
	int indice_arreglo=0;
	int n=renglones_vector_local(a);
	arreglo_1d_T a_recibido;
	if(Comm_rank(a)!=0)
		MPI_Send(entradas_vector_local(a), renglones_vector_local(a),MPI_DOUBLE,destino,tag,Comm_vector(a));
	else{
		for(i=0;i<n;i++){
			printf("arreglo_local[%d] = %.5f\n",i,entrada_vector_local(a,i));
			fflush(stdout);
			indice_arreglo++;
		}//asumiendo mismos tamaños de arr entre los procesadores
		a_recibido=malloc(sizeof(*a_recibido));
		renglones_vector_local(a_recibido)=renglones_vector_local(a);
		entradas_vector_local(a_recibido)=malloc(renglones_vector_local(a_recibido)*sizeof(double));
		for(fuente=1;fuente<Comm_size(a);fuente++){
			MPI_Recv(entradas_vector_local(a_recibido), renglones_vector_local(a), MPI_DOUBLE, fuente,tag,Comm_vector(a),MPI_STATUS_IGNORE);
			for(i=0;i<n;i++){
				printf("arreglo_local[%d] = %.5f recibido de %d\n",indice_arreglo,entrada_vector_local(a_recibido,i),fuente);
				fflush(stdout);
				indice_arreglo++;
			}
		}
		free(a_recibido);
	}
}
void incrementa_size_array(arreglo_1d_T a){
        int residuo;
        residuo=renglones_vector(a)%Comm_size(a);
        if(residuo==0)
                renglones_vector_added_ceros(a)=renglones_vector(a);
        else
                renglones_vector_added_ceros(a)=Comm_size(a)*(renglones_vector(a)/Comm_size(a)+1);
}
```

Observa en el archivo de `funciones.c` anterior la función para realizar **output** ` imprime_valores_almacenados_en_procesos` que el proceso con rank 0 es el encargado de imprimir en pantalla.

El programa `scatter_gather_example.c` es:

```
#include<stdio.h>
#include<stdlib.h>
#include"definiciones.h"
#define x_vector "x.txt"
int main(int argc, char *argv[]){
	arreglo_1d_T x_local;
	MPI_Comm comm;
	MPI_Init(&argc,&argv);
	x_local=malloc(sizeof(*x_local));
	//MPI_Comm_dup(MPI_COMM_WORLD, &comm);
	comm=MPI_COMM_WORLD;
	Comm_pointer_vector(x_local)=&comm;
	MPI_Comm_size(comm, &Comm_size(x_local));//Comm_size representa para este ejemplo
							//el número de procesadores y por tanto
							//número de bloques para dividir los datos
	MPI_Comm_rank(comm, &Comm_rank(x_local));
	
	Comm_pointer_vector(x_local)=&comm;

	if(Comm_rank(x_local)==0){
		renglones_vector(x_local)=atoi(argv[1]);
		incrementa_size_array(x_local);
		renglones_vector_local(x_local)=renglones_vector_added_ceros(x_local)/Comm_size(x_local);
	}
	//Se broadcast lo hecho por el proceso con rank 0
	MPI_Bcast(&renglones_vector(x_local),1,MPI_INT,0,Comm_vector(x_local));
	MPI_Bcast(&renglones_vector_added_ceros(x_local),1,MPI_INT,0,Comm_vector(x_local));
	MPI_Bcast(&renglones_vector_local(x_local),1,MPI_INT,0,Comm_vector(x_local));
	
	//alojar espacio e inicializar
	entradas_vector_local(x_local)=malloc(renglones_vector_local(x_local)*sizeof(double));
	inicializa_vector_ceros_local(x_local);
	inicializa_vector_mpi(x_local, x_vector);

	//Scatter el vector leído del archivo x.txt
	MPI_Scatter(entradas_vector(x_local),renglones_vector_local(x_local),MPI_DOUBLE,entradas_vector_local(x_local),renglones_vector_local(x_local),MPI_DOUBLE,0,Comm_vector(x_local));
	
	if(Comm_rank(x_local)==0)
		free(entradas_vector(x_local));

	//Imprimir entradas almacenadas en procesos
	imprime_entradas_almacenadas_en_procesos(x_local);

	//Hacer Gather en un y_local
	arreglo_1d_T y_local;
	y_local=malloc(sizeof(*y_local));
	if(Comm_rank(x_local)==0){
		renglones_vector(y_local)=renglones_vector_added_ceros(x_local);
		entradas_vector(y_local)=malloc(renglones_vector(y_local)*sizeof(double));
		inicializa_vector_ceros(y_local);
		printf("Vector y_local incializado en ceros:\n");
		imprime_vector(y_local);
		printf("Realizando MPI_Gather en proceso con rank 0: en un vector y\n");
	}
	MPI_Gather(entradas_vector_local(x_local), renglones_vector_local(x_local), MPI_DOUBLE, entradas_vector(y_local), 
		renglones_vector_local(x_local), MPI_DOUBLE, 0, Comm_vector(x_local));
	
	//Free arreglo_1d_T
	if(Comm_rank(x_local)==0){
		renglones_vector(y_local)=renglones_vector(x_local);
		printf("Vector y_local:\n");
		imprime_vector(y_local);
		free(entradas_vector(y_local));
		free(y_local);
	}
	free(entradas_vector_local(x_local));
	free(x_local);
	MPI_Finalize();
	return 0;
}

```

Compilamos:

```
$mpicc -Wall scatter_gather_example.c funciones.c -o scatter_gather_example.out
```

Ejecutamos:

```
$mpiexec -n 4 scatter_gather_example.out 12
```

Resultado:

```
arreglo_local[0] = 1.00000
arreglo_local[1] = 2.00000
arreglo_local[2] = 3.00000
arreglo_local[3] = 4.00000 recibido de 1
arreglo_local[4] = 5.00000 recibido de 1
arreglo_local[5] = 6.00000 recibido de 1
arreglo_local[6] = 7.00000 recibido de 2
arreglo_local[7] = 8.00000 recibido de 2
arreglo_local[8] = 9.00000 recibido de 2
arreglo_local[9] = 10.00000 recibido de 3
arreglo_local[10] = 11.00000 recibido de 3
arreglo_local[11] = 12.00000 recibido de 3
Vector y_local incializado en ceros:
vector[0]=0.00000
vector[1]=0.00000
vector[2]=0.00000
vector[3]=0.00000
vector[4]=0.00000
vector[5]=0.00000
vector[6]=0.00000
vector[7]=0.00000
vector[8]=0.00000
vector[9]=0.00000
vector[10]=0.00000
vector[11]=0.00000
Realizando MPI_Gather en proceso con rank 0: en un vector y
Vector y_local:
vector[0]=1.00000
vector[1]=2.00000
vector[2]=3.00000
vector[3]=4.00000
vector[4]=5.00000
vector[5]=6.00000
vector[6]=7.00000
vector[7]=8.00000
vector[8]=9.00000
vector[9]=10.00000
vector[10]=11.00000
vector[11]=12.00000

```

Si el archivo `x.txt` hubiera sido:

```
1
2
3
4
5
6
7
8
9
10
11
12
13
```

Ejecutamos:

```
$mpiexec -n 4 scatter_gather_example.out 13
```

Resultado:

```
arreglo_local[0] = 1.00000
arreglo_local[1] = 2.00000
arreglo_local[2] = 3.00000
arreglo_local[3] = 4.00000
arreglo_local[4] = 5.00000 recibido de 1
arreglo_local[5] = 6.00000 recibido de 1
arreglo_local[6] = 7.00000 recibido de 1
arreglo_local[7] = 8.00000 recibido de 1
arreglo_local[8] = 9.00000 recibido de 2
arreglo_local[9] = 10.00000 recibido de 2
arreglo_local[10] = 11.00000 recibido de 2
arreglo_local[11] = 12.00000 recibido de 2
arreglo_local[12] = 13.00000 recibido de 3
arreglo_local[13] = 0.00000 recibido de 3
arreglo_local[14] = 0.00000 recibido de 3
arreglo_local[15] = 0.00000 recibido de 3
Vector y_local incializado en ceros:
vector[0]=0.00000
vector[1]=0.00000
vector[2]=0.00000
vector[3]=0.00000
vector[4]=0.00000
vector[5]=0.00000
vector[6]=0.00000
vector[7]=0.00000
vector[8]=0.00000
vector[9]=0.00000
vector[10]=0.00000
vector[11]=0.00000
vector[12]=0.00000
vector[13]=0.00000
vector[14]=0.00000
vector[15]=0.00000
Realizando MPI_Gather en proceso con rank 0: en un vector y
Vector y_local:
vector[0]=1.00000
vector[1]=2.00000
vector[2]=3.00000
vector[3]=4.00000
vector[4]=5.00000
vector[5]=6.00000
vector[6]=7.00000
vector[7]=8.00000
vector[8]=9.00000
vector[9]=10.00000
vector[10]=11.00000
vector[11]=12.00000
vector[12]=13.00000
```


