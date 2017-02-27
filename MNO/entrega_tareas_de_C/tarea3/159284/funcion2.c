/*
Tarea 3
Manuel Rios - 159284

Funcion 2
Imprimir entradas de memoria de los indices impares de un arreglo de una o dos dimensiones
La funcion recibe el arreglo, el numero de filas y el numero de columnas

Aqui usamos como ejemplo un arreglo de 2 x 5. 
*/

#include <stdio.h>
#include <math.h>


// Poner valores en indice = 1
// Regresa valores en indice = 0
void imprimir_memoria(int *array, int num_rows, int num_cols)
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
        for (j = 0; j < cols; j++)
        {
            printf("&p[%d] = %u\n", j, *(&array + j));
        }
    }
    else
    {
        for (i = 0; i < rows; i++)
        {
            for (j = 0; j < cols; j++)
            {
                if(n % 2 == 1)
                {
                    printf("&p[%d,%d] = %u\n", i, j, *(&array + n));
                }
                n++;
            }
        }
    }
}


int main()
{
    int arreglo[2][5] = {
        {4,6,18,10,12},
        {5,23,43,78,98}
    };

    // Imprimiendo memoria
    imprimir_memoria(&arreglo,2,5);
    return 0;
}