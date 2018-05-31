/**************************** Arturo Torre Gonzalez - 90226 - Tarea 3 ************************/

#include <stdio.h>

main()
{
	int p[10]; 
	for(int k=0; k<10; k++){p[k] = (k+1)*(-1);}	
	int mat[2][3];
	int cont = 1;	
	for(int k=0; k<2; k++){ for(int y=0; y<3; y++) {mat[k][y] = cont; cont++;}}
	
	datos(p, (sizeof(p)/sizeof(p[0]))*(sizeof(p[0])/sizeof(int)));	
	memoria(p, (sizeof(p)/sizeof(p[0]))*(sizeof(p[0])/sizeof(int)));
	

	datos(mat, (sizeof(mat)/sizeof(mat[0]))*(sizeof(mat[0])/sizeof(int)));	
	memoria(mat, (sizeof(mat)/sizeof(mat[0]))*(sizeof(mat[0])/sizeof(int)));
}

void datos(int *apuntador,int tamanio){	
	printf("Contenido del apuntador\n");
	for(int z=1; z<tamanio; z=z+2){printf("p[%d] = %d\n",z,apuntador[z]);}
}

void memoria(int *apuntador,int tamanio){
	printf("Referencias de memoria del apuntador\n");		
	for(int z=1; z<tamanio; z=z+2){printf("&p[%d] = %p\n",z,&apuntador[z]);}
}