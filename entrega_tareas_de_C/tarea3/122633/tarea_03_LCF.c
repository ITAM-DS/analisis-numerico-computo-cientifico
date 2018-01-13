//Lizbeth Contreras Figueroa
//Tarea 03
//Fecha de entrega: 20/02/2017

#include<stdio.h>
#define n_row(matrix) (sizeof(matrix) / sizeof(matrix[0]))
#define n_col(matrix) (sizeof(matrix[0]) / sizeof(matrix[0][0]))

void imprime_valores(int *puntero, int rows, int columnas);
void imprime_direccion(int *puntero, int renglones, int cols);

    void imprime_valores(int *puntero, int rows, int cols)
    {
    	int total= rows*cols;
			   	
    	    for(int i=0;i<total;i++)
    	    {
    	    	i+=1;
    	    	printf("p[%d]: %d\n", i, *(puntero+i));
    	    }
    }   

    void imprime_direccion(int *puntero, int rows, int cols)
    {
		int total= rows*cols;
    	 
    	    for(int i=0;i<total;i++)
    	    {
    	    	i+=1;
    	    	printf("&p[%d]: %p \n", i,puntero+i);
    	    }
    }  

  
int main(){ 	
    int arreglo[10] = {-10, -9, -8, -7, -6, -5, -4, -3, -2, -1};
    int matrix[2][3]={{-1,-2,-3},{-4,-5,-6}};
    void *apuntador; 
    apuntador = &arreglo; 

    imprime_valores(apuntador, n_row(arreglo),1);
    imprime_direccion(apuntador, n_row(arreglo),1);

	apuntador = &matrix; 
   	imprime_valores(apuntador, n_row(matrix), n_col(matrix));
   	imprime_direccion(apuntador, n_row(matrix),n_col(matrix));
    return 0;
}
