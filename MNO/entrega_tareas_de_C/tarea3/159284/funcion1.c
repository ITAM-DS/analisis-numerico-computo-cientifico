/*
Tarea 3
Manuel Rios - 159284

Funcion 1
Imprimir valores de los indices impares de un arreglo de una o dos dimensiones.
La funcion recibe el arreglo, el numero de filas y el numero de columnas

Aqui usamos como ejemplo un arreglo de 2 x 5.
*/

#include <stdio.h>
#include <math.h>

// Poner valores en indice = 1
// Regresa valores en indice = 0
void imprimir_valores(int *array, int num_rows, int num_cols)
{

    int i;
    int j;
    int rows;
    int cols;
    int n = 0;
    

    rows = num_rows;
    cols = num_cols;
    
    if(rows == 1)
    {
        for (j = 1; j < cols; j = j + 2)
        {
            printf("p[%d] = %d\n", j, *(array + j));
        }
    }
    else
    {
        for (i = 0; i < rows; i++)
        {
            for (j = 0; j < cols; j++)
            {
                if(n%2 == 1)
                {
                    printf("p[%d,%d] = %d\n", i, j, *(array + n));
                }
                n++;
            }
        }
    }
}


int main()
{
    int arreglo[][17] = {
        {4,6,18,10,12,45,67,54,32,45,32,34,32,45,54,65,78},
        {16,17,18,19,110,45,76,23,56,45,65,76,45,32,34,43,45}
    };

    // Imprimiendo valores
    imprimir_valores(&arreglo,2,17);
    return 0;
}