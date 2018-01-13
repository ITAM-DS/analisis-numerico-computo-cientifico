#include <stdio.h>

void imprime_elementos_impares(int *apuntador, int tamano);
/*Esta función imprime las entradas impares de un arreglo
Recibe como entrada un apuntador y funciona para 
arreglos de una dimensión y de dos dimensiones. */
void imprime_direcciones_memoria_impares(int *apuntador, int tamano);
/*Esta función imprime las direcciones de memoria
de las entradas impares de un arreglo
Recibe como entrada un apuntador y funciona para 
arreglos de una dimensión y de dos dimensiones. */
int main(){
  int arreglo_dos_dimensiones[2][3] = {-1, -2, -3,    
   									   -4, -5, -6 };   

  int arreglo_una_dim[10]={-1,-2,-3,-4,-5,-6,-7,-8,-9,-10};

  int *apuntador_una_dimension, *apuntador_bidimensional;

  int tamano_arreglo_una_dim, tamano_arreglo_dos_dim;
  tamano_arreglo_una_dim=sizeof(arreglo_una_dim)/sizeof(arreglo_una_dim[0]);
  tamano_arreglo_dos_dim=sizeof(arreglo_dos_dimensiones)/sizeof(arreglo_dos_dimensiones[0][0]);
  printf("Tamaño del arreglo una dim = %d \n",tamano_arreglo_una_dim);
  printf("Tamaño del arreglo dos dim = %d \n",tamano_arreglo_dos_dim);
  apuntador_una_dimension= &arreglo_una_dim;
  apuntador_bidimensional= &arreglo_dos_dimensiones;
 
  printf("Los elementos y las posiciones de memoria impares de el arreglo de una dimensión son:\n");
  imprime_elementos_impares(apuntador_una_dimension,tamano_arreglo_una_dim);
  imprime_direcciones_memoria_impares(apuntador_una_dimension,tamano_arreglo_una_dim);

  printf("Los elementos y las posiciones de memoria de el arreglo bidimensional son:\n ");
  imprime_elementos_impares(apuntador_bidimensional,tamano_arreglo_dos_dim);
  imprime_direcciones_memoria_impares(apuntador_bidimensional,tamano_arreglo_dos_dim);
  
     return 0; // si esto se imprime quiere decir que todo se ejecutó exitosamente
}/* cerrando main int */
     
void imprime_elementos_impares(int *apuntador, int tamano){
	apuntador++;
	for(int i=1; i<tamano; i=i+2){
		printf("Elemento %d del arreglo = %d \n",i,*apuntador);
		apuntador=apuntador+2;
	}/*for i=1*/
} /*imprime_elementos_impares void*/

void imprime_direcciones_memoria_impares(int *apuntador, int tamano){
	apuntador++;
	for(int i=1; i<tamano; i=i+2){
		printf("Dirección de memoria del elemento %d del arreglo = %p \n",i,apuntador);
		apuntador=apuntador+2;
	}/*for i=1*/
}/*imprime_direcciones_memoria_impares void*/
	