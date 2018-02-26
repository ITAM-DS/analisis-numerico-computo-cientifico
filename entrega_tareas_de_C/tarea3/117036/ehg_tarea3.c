/*Tarea 3
Eduardo Hidalgo García
CU 000117036 */

#include<stdio.h>

void funcion_1_datos_impares(int *arreglo, int tamano_arreglo) {
  /* Definimos la funcion que imprime los datos en las posiciones del arreglo impares */
  int i=0;
  printf("Valores impares:\n");
  for (i=0; i < tamano_arreglo; i++) {
    /* Recorremos el arreglo y ponemos una condicion para las posiciones impares */
    if (i%2!=0) {printf("p[%i]=%d\n",i,*(arreglo+1));}
  }
  printf("\n");
}


void funcion_2_imprime_las_direcciones(int *arreglo, int tamano_arreglo) {
  /* Definimos la funcion que imprimira las direcciones de las posiciones impares del arreglo*/
  int i=0;
  printf("Las Direcciones de Memoria:\n");
  for (i = 0; i < tamano_arreglo; i++) {
    /* Recorremos el arreglo y ponemos la condicion del modulo para las posiciones impares del arreglo */
    if (i%2!=0) {
      printf("&p[%i]=%p\n",i,(arreglo+1) );
    }
    printf("\n");
  }
}
/*Ya con las funciones contruidas, declaramos la variables pertinentes en el main para poder compilar el ejercicio*/

int main() {
  int array[10];
  int k,m,n;
  int *apuntador1;
  apuntador1=array;
  int disp[2][3];
  int *apuntador2;
  apuntador2=disp;
  /*Se inicializa el arreglo unidimensional con los valores de la tarea*/
  for (k = 0; k < 10; k++) {
    /* Nota que los valores son negativos */
    array[k]=-(k+1);
  }


/*Se inicializa el arreglo multidimensional con los valores de la tarea*/
k=0;
for (n = 0; n < 2; n++) {
  for (m = 0; m < 3; m++) {
    disp[n][m]=-(k+1);
    k=k+1;
  }
}

funcion_1_datos_impares(apuntador1,10);
funcion_2_imprime_las_direcciones(apuntador1,10);


funcion_1_datos_impares(apuntador2,6);
funcion_2_imprime_las_direcciones(apuntador2,6);
return 0;
}
