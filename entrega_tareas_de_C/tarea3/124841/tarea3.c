#include <stdio.h>
main ( void )
{
 


    int arr[10]={-1,-2,-3,-4,-5,-6,-7,-8,-9,-10};
    int matrix[2][3]={{-1,-2,-3},{-4,-5,-6}};
   int len=sizeof(arr)/sizeof(int);
   int len2=sizeof(matrix)/sizeof(int);
 printf("Entradas impares del arreglo:\n");
    print_nones(arr, len);
printf("Direcciones de memoria del arreglo:\n");
   print_mem(arr, len);
printf("Entradas impares de la matriz:\n");
    print_nones(matrix, len2);
printf("Direcciones de memoria de la matriz:\n");
   print_mem(matrix, len2);
}


//Funciones 


//Funcion 1, imprime el contenido del arreglo o matriz
void print_nones (int array[],int elem){
   

for (int i=1; i < elem; i=i+2){
 printf("p[%d]:%d\n", i, array[i]);
}
}

//Funcion 2, imprime las direcciones de memoria del arreglo o matriz 
void print_mem (int array[],int elem){
for (int i=1; i < elem; i=i+2){
 printf("&p[%d]:%p\n", i, &array[i]);
}
}
