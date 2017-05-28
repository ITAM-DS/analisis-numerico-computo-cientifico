//arreglo2d:
typedef struct{
int m, n;
#define renglones(arreglo) ((arreglo)->m)
#define columnas(arreglo) ((arreglo)->n)
double *arr;
#define entradas(arreglo) ((arreglo)->arr)
#define entrada(arreglo,i,j) ((arreglo)->arr[(j)*m+(i)])
 //almacenamos column major
}arreglo_2d;
typedef arreglo_2d *mat;

typedef struct{
int mr, nr;

#define renglones_mr(arreglo2) ((arreglo2)->mr)
#define columnas_nr(arreglo2) ((arreglo2)->nr)

double *arr2;

#define entradas2(arreglo2) ((arreglo2)->arr2)
#define entrada2(arreglo2,i,j) ((arreglo2)->arr2[(j)*mr+(i)])

 //almacenamos column major
}arreglo_2dd;

typedef arreglo_2dd *mat2;

typedef struct{
int mh, nh;

#define renglones_mh(arreglo3) ((arreglo3)->mh)
#define columnas_nh(arreglo3) ((arreglo3)->nh)

double *arr3;

#define entradas3(arreglo3) ((arreglo3)->arr3)
#define entrada3(arreglo3,i,j) ((arreglo3)->arr3[(j)*mh+(i)])

 //almacenamos column major
}arreglo_2ddd;
typedef arreglo_2ddd *mat3;


//arreglo1d
typedef struct{
int n;
#define renglones_vector(arreglo) ((arreglo)->n)
double *arr;
#define entradas_vector(arreglo) ((arreglo)->arr)
#define entrada_vector(arreglo,i) ((arreglo)->arr[i])
}arreglo_1d;
typedef arreglo_1d *vect;