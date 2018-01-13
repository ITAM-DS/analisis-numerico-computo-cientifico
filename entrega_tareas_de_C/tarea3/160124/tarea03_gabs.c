/*************************************************************************
# ITAM
## Maestría en Ciencia de Datos
## Tarea 03
### Metódos Numéricos y Optimización
#### Profesor: Erick Palacios
#### Alumna: Gabriela Flores Bracamontes - 160124
************************************************************************/

#include<stdio.h>
#define NUM_ROWS(matrix) (sizeof(matrix) / sizeof(matrix[0]))
#define NUM_COLUMNS(matrix) (sizeof(matrix[0]) / sizeof(matrix[0][0]))

void PrintArrayValues(int *puntero, int renglones, int columnas);
void PrintArrayMemoryAddress(int *puntero, int renglones, int columnas);
void PrintTitles(char Title[50]);
void PrintSubTitles(char Title[50]);


/*Definición de Funciones*/
    void PrintArrayValues(int *puntero, int renglones, int columnas)
    {
    	int total= renglones*columnas;

			PrintSubTitles(" Valores de cada posición ");    	
    	    for(int i=0;i<total;i++)
    	    {
    	    	i+=1;
    	    	printf("p[%d]: %d\n", i, *(puntero+i));
    	    }
    }   

    void PrintArrayMemoryAddress(int *puntero, int renglones, int columnas)
    {
		int total= renglones*columnas;
    	PrintSubTitles(" Dirección en memoria de cada posición "); 
    	    for(int i=0;i<total;i++)
    	    {
    	    	i+=1;
    	    	printf("&p[%d]: %p \n", i,puntero+i);
    	    }
    }  

  void PrintTitles(char Title[50])
  {
    printf("\n\n\n---------------------------------------------------------------------------------------------------------\n");
    printf("------------------------------------------------ %s ------------------------------------------------\n", Title);
    printf("---------------------------------------------------------------------------------------------------------\n");

  }

  void PrintSubTitles(char Title[50])
  {
    printf("------------------------------------------------ %s ------------------------------------------------\n", Title);
  }  

/*Programa Principal*/
int main(){ 
	PrintTitles(" Tarea 3 ");
	printf("El programa utiliza una variable llamada arreglo que tiene una dimensión de 10x1 y una variable llamada matrix de 2x3:\n\n");  
	printf(" arreglo[10] = {-1,-2,-3,-4,-5,-6,-7,-8,-9,-10}\n");
	printf(" matrix[2][3]={{-1,-2,-3},{-4,-5,-6}}\n");
	printf("\nA continuación se muestran los valores y las posiciones en memoria de los elementos de cada variable, \nque correspondan a las posiciones impares\n");
    int arreglo[10] = {-1,-2,-3,-4,-5,-6,-7,-8,-9,-10}; //Defino el vector y le asigno los valores
    int matrix[2][3]={{-1,-2,-3},{-4,-5,-6}};
    void *apuntador; // Declaro el puntero
    apuntador = &arreglo; //Asigno la dirección de memoria de la variable arreglo al apuntador

    PrintArrayValues(apuntador, NUM_ROWS(arreglo),1);
    PrintArrayMemoryAddress(apuntador, NUM_ROWS(arreglo),1);

	apuntador = &matrix; //Asigno la dirección de memoria de la variable arreglo al apuntador
   	PrintArrayValues(apuntador, NUM_ROWS(matrix), NUM_COLUMNS(matrix));
   	PrintArrayMemoryAddress(apuntador, NUM_ROWS(matrix),NUM_COLUMNS(matrix));

    PrintTitles("By: Gabriela Flores Bracamontes");
    return 0;
}
