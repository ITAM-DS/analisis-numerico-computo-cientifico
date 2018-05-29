//arreglo2d:
typedef struct{
int m, n;
#define renglones(arreglo) ((arreglo)->m)
#define columnas(arreglo) ((arreglo)->n)
double *arr;
#define entradas(arreglo) ((arreglo)->arr)
#define entrada(arreglo,i,j) ((arreglo)->arr[j*renglones(arreglo)+i]) //almacenamos column major
}arreglo_2d;
typedef arreglo_2d *arreglo_2d_T;

//arreglo1d
typedef struct{
int n;
#define renglones_vector(arreglo) ((arreglo)->n)
double *arr;
int *arr_int;
#define entradas_vector(arreglo) ((arreglo)->arr)
#define entrada_vector(arreglo,i) ((arreglo)->arr[i])
#define entradas_vector_entero(arreglo) ((arreglo)->arr_int)
#define entrada_vector_entero(arreglo,i) ((arreglo)->arr_int[i])
}arreglo_1d;
typedef arreglo_1d *arreglo_1d_T;

//funciones
void imprime_vector(arreglo_1d_T);
void imprime_matriz(arreglo_2d_T);
void inicializa_matriz(arreglo_2d_T, char *);
void inicializa_vector(arreglo_1d_T, char *);
void imprime_vector_entero(arreglo_1d_T);
