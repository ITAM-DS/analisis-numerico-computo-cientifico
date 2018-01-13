#include<stdio.h>
#define MAX_FILAS(vector) (sizeof(vector)/sizeof(vector[0]))
#define MAX_COLS(vector) (sizeof(vector[0])/sizeof(vector[0][0]))

void imprime_valores(int *apuntador, int cols, int filas, int todas); 
void imprime_direcciones(int *dires, int cols, int filas, int todas);

main()
{
    int i, long_arreglo, filas, cols;
	//int arreglo[10] = {-1,-2,-3,-4,-5,-6,-7,-8,-9,-10};
	//int arreglo[20] = {-1,-2,-3,-4,-5,-6,-7,-8,-9,-10,1,2,3,4,5,6,7,8,9,10};
	int arreglo[3] = {10,20,-16};
	//int matriz[2][3] = {{-1,-2,-3},{-4,-5,-6}};
	//int matriz[4][3] = {{-1,-2,-3},{-4,-5,-6},{1,2,3},{4,5,6}};
	int matriz[2][2] = {{-1,-2},{-4,-5}};

	long_arreglo = MAX_FILAS(arreglo);
	filas = MAX_FILAS(matriz);
	cols = MAX_COLS(matriz);

    imprime_valores(arreglo,long_arreglo,1,1);
    imprime_direcciones(arreglo,long_arreglo,1,1);
    imprime_valores(arreglo,long_arreglo,1,0);
    imprime_direcciones(arreglo,long_arreglo,1,0);
    imprime_valores(matriz[0],cols,filas,1);
    imprime_direcciones(matriz[0],cols,filas,1);
    imprime_valores(matriz[0],cols,filas,0);
    imprime_direcciones(matriz[0],cols,filas,0);
    return 0;
}	
///definición de la función imprime_valores:
void imprime_valores(int *apuntador, int cols, int filas, int todas)
{
	int i,j,cont;
	printf("-----------:\n");
  	printf("- Valores -:\n");
	printf("-----------:\n");
	i=0,j=0,cont=0;

	if(filas == 1)
		if(todas == 1)
			for(i=0;i<cols*filas;i++)
				printf("Pos[%d]=%d\n", i,apuntador[i]);
		else
			for(i=0;i<cols*filas;i++)
				if(i % 2 != 0)
					printf("Pos[%d]=%d\n", i,apuntador[i]);
	if(filas != 1)
	{
		while(cont < filas*cols)
		{
			while(i<filas)
			{
				while(j<cols)
                {
                    if(todas == 1)
                            printf("Pos[%d][%d]=%d\n", i,j,apuntador[cont]);  
                    else
                        if((i+j) % 2 != 0)
                            printf("Pos[%d][%d]=%d\n",i,j,apuntador[cont]);
                j++;cont++;
                }
                i++;j=0;
			}
			cont++;
		}
	}
}

//definición de la función imprime_direcciones:
void imprime_direcciones(int *apuntador, int cols, int filas, int todas)
{
	int i=0,j=0,cont=0;
	printf("---------------:\n");
  	printf("- Direcciones -:\n");
	printf("---------------:\n");
	if(filas == 1)
		if(todas == 1)
			for(i=0;i<cols*filas;i++)
				printf("Pos[%d]=%p\n", i,apuntador+i);
		else
			for(i=0;i<cols*filas;i++)
				if(i % 2 != 0)
					printf("Pos[%d]=%p\n", i,apuntador+i);
	if(filas != 1)
	{
		while(cont < filas*cols)
		{
			while(i<filas)
			{
				while(j<cols)
                {
                    if(todas == 1)
                            printf("Pos[%d][%d]=%p\n", i,j,apuntador+cont);  
                    else
                        if((i+j) % 2 != 0)
                            printf("Pos[%d][%d]=%p\n",i,j,apuntador+cont);
                j++;cont++;
                }
                i++;j=0;
			}
			cont++;
		}
	}
}
