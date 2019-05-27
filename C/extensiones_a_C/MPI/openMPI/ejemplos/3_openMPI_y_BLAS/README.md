Suponemos un sistema ubuntu y que está instalado libblas-dev y liblapack-dev.

En las carpetas para los diferentes niveles de BLAS: [level1](level1), [level2](level2), level3 se tienen códigos que utilizan los archivos `definiciones.h` y `funciones.c` siguiente y se basan en [P.Pacheco. Parallel Programming with MPI](http://www.cs.usfca.edu/~peter/ppmpi/):

`definiciones.h`:

```
#include<mpi.h>
typedef struct{
MPI_Comm *comm;
#define Comm_pointer_matriz(arreglo) ((arreglo)->comm)
#define Comm_matriz(arreglo) (*((arreglo)->comm))
int comm_size;
#define Comm_size_matriz(arreglo) ((arreglo)->comm_size)
int mirank;
#define Comm_rank_matriz(arreglo) ((arreglo)->mirank)
int m, n;
#define renglones(arreglo) ((arreglo)->m)
#define columnas(arreglo) ((arreglo)->n)
double *arr;
#define entradas(arreglo) ((arreglo)->arr)
#define entrada(arreglo,i,j) ((arreglo)->arr[j*renglones(arreglo)+i]) //almacenamos column major
int nlocal;
#define columnas_local(arreglo) ((arreglo)->nlocal)
int mlocal;
#define renglones_local(arreglo) ((arreglo)->mlocal)
int m_ceros_added;
#define renglones_added_ceros(arreglo) ((arreglo)->m_ceros_added)
double *arrlocal;
#define entradas_local(arreglo) ((arreglo)->arrlocal)
#define entrada_local(arreglo,i,j,m_local,n_local) ((arreglo)->arrlocal[j*renglones_local(arreglo)+i]) //check this define executing examples
}arreglo_2d;
typedef arreglo_2d *arreglo_2d_T;

typedef struct{
MPI_Comm *comm;
#define Comm_pointer_vector(arreglo) ((arreglo)->comm)
#define Comm_vector(arreglo) (*((arreglo)->comm))
int comm_size;
#define Comm_size_vector(arreglo) ((arreglo)->comm_size)
int mirank;
#define Comm_rank_vector(arreglo) ((arreglo)->mirank)
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
int *arr_int;
#define entradas_vector_entero(arreglo) ((arreglo)->arr_int)
#define entrada_vector_entero(arreglo,i) ((arreglo)->arr_int[i])
}arreglo_1d;
typedef arreglo_1d *arreglo_1d_T;


void imprime_vector(arreglo_1d_T);
void imprime_matriz(arreglo_2d_T);
void inicializa_matriz(arreglo_2d_T, char *);
void inicializa_vector(arreglo_1d_T, char *);
void inicializa_matriz_ceros(arreglo_2d_T);
void inicializa_vector_ceros(arreglo_1d_T);
void inicializa_vector_local_ceros(arreglo_1d_T);
void imprime_vector_local(arreglo_1d_T p);
void imprime_entradas_almacenadas_en_procesos(arreglo_1d_T);
void inicializa_vector_mpi(arreglo_1d_T, char *);
void incrementa_size_array(arreglo_1d_T);
void imprime_matriz_local(arreglo_2d_T);
void inicializa_matriz_local_ceros(arreglo_2d_T);
void imprime_vector_entero(arreglo_1d_T);
void incrementa_size_array_2d(arreglo_2d_T);
void lee_entradas_matriz_distribuye_block_row(arreglo_2d_T , char *, arreglo_1d_T );
```

`funciones.c`:

```
#include<stdio.h>
#include<stdlib.h>
#include"definiciones.h"
static int i,j;
void inicializa_matriz(arreglo_2d_T p, char *s){
	int m = renglones(p);
	int n = columnas(p);
	FILE * pFile;
  	pFile = fopen (s,"r");
  	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			fscanf(pFile,"%lf", &entrada(p,i,j));
	fclose(pFile);
}
void inicializa_vector(arreglo_1d_T p, char *s){
	int m = renglones_vector(p);
	FILE * pFile;
  	pFile = fopen (s,"r");
  	for(i=0;i<m;i++)
			fscanf(pFile,"%lf", &entrada_vector(p,i));
	fclose(pFile);
}
void inicializa_matriz_ceros(arreglo_2d_T p){
	int m = renglones(p);
	int n = columnas(p);
  	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			entrada(p,i,j)=0;
}
void inicializa_matriz_local_ceros(arreglo_2d_T p){
	int m = renglones_local(p);
	int n = columnas_local(p);
  	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			entrada_local(p,i,j,m,n)=0;
}
void inicializa_vector_ceros(arreglo_1d_T p){
	int n = renglones_vector(p);
	for(j=0;j<n;j++)
		entrada_vector(p,j)=0;
}
void inicializa_vector_local_ceros(arreglo_1d_T p){
	int n = renglones_vector_local(p);
	for(j=0;j<n;j++)
		entrada_vector_local(p,j)=0;
}
void imprime_matriz(arreglo_2d_T p){
	int m = renglones(p);
	int n = columnas(p);
		for(i=0;i<m;i++){
			for(j=0;j<n;j++){
				if(j<n-1)
				printf("matriz[%d][%d]=%.5f\t",i,j,entrada(p,i,j));
				else
				printf("matriz[%d][%d]=%.5f\n",i,j,entrada(p,i,j));
			}
		}
}
void imprime_matriz_local(arreglo_2d_T p){
	int m = renglones_local(p);
	int n = columnas_local(p);
		for(i=0;i<m;i++){
			for(j=0;j<n;j++){
				if(j<n-1)
				printf("matriz_local[%d][%d]=%.5f\t",i,j,entrada_local(p,i,j,m,n));
				else
				printf("matriz_local[%d][%d]=%.5f\n",i,j,entrada_local(p,i,j,m,n));
			}
		}
}
void imprime_vector(arreglo_1d_T p){
	int m = renglones_vector(p);
		for(i=0;i<m;i++)
				printf("vector[%d]=%.5f\n",i,entrada_vector(p,i));
}
void imprime_vector_entero(arreglo_1d_T p){
	int m = renglones_vector(p);
		for(i=0;i<m;i++)
				printf("vector[%d]=%d\n",i,entrada_vector_entero(p,i));
}
void imprime_vector_local(arreglo_1d_T p){
	int m = renglones_vector_local(p);
		for(i=0;i<m;i++)
				printf("vector_local[%d]=%.5f\n",i,entrada_vector_local(p,i));
}

void inicializa_vector_mpi(arreglo_1d_T a, char *s){
	if(Comm_rank_vector(a)==0){
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
	if(Comm_rank_vector(a)!=0)
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
		for(fuente=1;fuente<Comm_size_vector(a);fuente++){
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
        residuo=renglones_vector(a)%Comm_size_vector(a);
        if(residuo==0)
                renglones_vector_added_ceros(a)=renglones_vector(a);
        else
                renglones_vector_added_ceros(a)=Comm_size_vector(a)*(renglones_vector(a)/Comm_size_vector(a)+1);
}
void incrementa_size_array_2d(arreglo_2d_T a){
        int residuo;
        residuo=renglones(a)%Comm_size_matriz(a);
        if(residuo==0)
                renglones_added_ceros(a)=renglones(a);
        else
                renglones_added_ceros(a)=Comm_size_matriz(a)*(renglones(a)/Comm_size_matriz(a)+1);

}

void lee_entradas_matriz_distribuye_block_row(arreglo_2d_T mat_local, char *s, arreglo_1d_T m_a){
	int m=renglones(mat_local);
	int n=columnas(mat_local);
	int i,j;
	int ii;
	int destino=0;
	int contador=0;
	arreglo_2d_T temp;
	FILE * pFile;
	MPI_Status status;
	if(Comm_rank_matriz(mat_local)==0){
		temp=malloc(sizeof(*temp));
		ii=0;
		entradas_local(temp)=malloc(entrada_vector_entero(m_a,destino)*columnas_local(mat_local)*sizeof(double));
  		pFile = fopen (s,"r");
  		for(i=0;i<m;i++){
			renglones_local(temp)=entrada_vector_entero(m_a,destino);
			columnas_local(temp)=n;
			if(destino==0){
				for(j=0;j<n;j++)
					fscanf(pFile,"%lf", &entrada_local(mat_local,i,j,renglones_local(mat_local),columnas_local(mat_local)));
			}
			else{
					for(j=0;j<n;j++){
						fscanf(pFile,"%lf", &entrada_local(temp,i-ii,j,entrada_vector_entero(m_a,destino),columnas_local(temp)));
				}
			}
			contador+=1;
			if(contador==entrada_vector_entero(m_a,destino)){	
				if(destino!=0 && (ii+contador)<=m){
					MPI_Send(entradas_local(temp), contador*columnas_local(mat_local), MPI_DOUBLE, destino, 0,Comm_matriz(mat_local));
				}
				contador=0;
				ii+=entrada_vector_entero(m_a,destino);
				destino+=1;
			}
		}
		fclose(pFile);
		free(entradas_local(temp));
		free(temp);
	}
	else{
		if((Comm_rank_matriz(mat_local)+1)*renglones_local(mat_local)<=renglones(mat_local)){
			MPI_Recv(entradas_local(mat_local), renglones_local(mat_local)*columnas_local(mat_local), MPI_DOUBLE, 0, 0, Comm_matriz(mat_local), &status);

		}
	}
}
```
