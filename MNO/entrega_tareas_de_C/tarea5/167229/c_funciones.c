/*c) Modifica el archivo funciones.c para que alojes e inicialices a las matrices matriz1, matriz2 y matriz_resultado con malloc y apuntadores. Modifica main.c para que llame a una función dentro del archivo funciones.c que inicialice y aloje a las matrices anteriores y llame a otra función para que las desaloje una vez hecha la multiplicación (usa free)*/

#include<stdio.h>
#include<stdlib.h>
#include"c_definiciones.h"

static int i=0,j=0,k=0,l=0,m=0, n=0, o=0; //definiciones de variables que serán externas
static double matriz_resultado[NUM_REN_MAT1][NUM_COL_MAT2];
double (*mall_matriz1) [NUM_REN_MAT1][NUM_COL_MAT1];
double (*mall_matriz2) [NUM_REN_MAT2][NUM_COL_MAT2];
double (*mall_matriz_resultado) [NUM_REN_MAT2][NUM_COL_MAT2];

void aloja_espacio_e_incializa_matrices(void)
{
//////////////////////////////////////MATRIZ1////////////////////////////////////////////////
	static double matriz1[NUM_REN_MAT1][NUM_COL_MAT1]=
	{
		{0, 1.5}, 
		{4, -5},
		{-1, 2.5}
	};

	//Alojar espacio en memoria con malloc
	mall_matriz1=malloc(8*NUM_COL_MAT1*NUM_COL_MAT1); //8 bytes para el double
	//Asigna a la dirección que dio malloc el valor que le corresponde de la matriz	
	for(l=0; l<NUM_REN_MAT1; l++)
	{
		for (m=0; m<NUM_COL_MAT1; m++)
		(*mall_matriz1)[l][m]=matriz1[l][m]; 
	}
	
//////////////////////////////////////MATRIZ2////////////////////////////////////////////////
	static double matriz2[NUM_REN_MAT2][NUM_COL_MAT2]=
	{
		{1, 0, 0},
		{0, -1, 1}
	};
//	printf("matriz2:%f",matriz2[1][1]);
	mall_matriz2 = malloc(8*NUM_REN_MAT2*NUM_COL_MAT2);
	
	for(n=0; n<NUM_REN_MAT2; n++)
	{
		for (o=0; o<NUM_COL_MAT2; o++)
		(*mall_matriz2)[n][o]=matriz2[n][o]; 
	}
	
//////////////////////////////////////MATRIZ RESULTADO////////////////////////////////////////////////
	static double matriz_resultado[NUM_REN_MAT1][NUM_COL_MAT2];
	mall_matriz_resultado = malloc(8*NUM_REN_MAT1*NUM_COL_MAT2);

}

void imprime_matrices(void)
{
printf("Matriz1\n");
	for(i=0;i<NUM_REN_MAT1;i++) //el nombre: NUM_REN_MAT1 está definido en "definiciones.h"
	{ 
		for(j=0;j<NUM_COL_MAT1;j++)
		{
			if(j<NUM_COL_MAT1-1)
			printf("matriz1[%d][%d]=%4.2f\t",i,j,(*mall_matriz1)[i][j]);
			else
			printf("matriz1[%d][%d]=%4.2f\n",i,j,(*mall_matriz1)[i][j]);
		}
	}
	printf("\n");
	printf("Matriz2\n");
	for(i=0;i<NUM_REN_MAT2;i++)
	{
		for(j=0;j<NUM_COL_MAT2;j++)
		{
			if(j<NUM_COL_MAT2-1)
			printf("matriz2[%d][%d]=%4.2f\t",i,j,(*mall_matriz2)[i][j]);
			else
			printf("matriz2[%d][%d]=%4.2f\n",i,j,(*mall_matriz2)[i][j]);
		}
	}
	printf("\n");
}

void multiplica_matrices(void)
{
	for(i=0;i<NUM_REN_MAT1;i++)
	{
		for(k=0;k<NUM_COL_MAT2;k++)
		{
	 		(*mall_matriz_resultado)[i][k]=0;
 			for(j=0;j<NUM_COL_MAT1;j++)
  			(*mall_matriz_resultado)[i][k]=(*mall_matriz_resultado)[i][k]+(*mall_matriz1)[i][j]*(*mall_matriz2)[j][k];
		}
	}
}

void imprime_matriz_resultado(void)
{
	printf("Matriz resultado\n");
	for(i=0;i<NUM_REN_MAT1;i++)
	{
		for(j=0;j<NUM_COL_MAT2;j++)
		{
			if(j<NUM_COL_MAT2-1)
			printf("matriz_res[%d][%d]=%4.2f\t",i,j,(*mall_matriz_resultado)[i][j]);
			else
			printf("matriz_res[%d][%d]=%4.2f\n",i,j,(*mall_matriz_resultado)[i][j]);
		}
	}

	printf("\n");

}

void libera_espacio(void)
{
	free(mall_matriz1);
	free(mall_matriz2);
	free(mall_matriz_resultado);
}
