/*
AUTOR: WALTER MARTINEZ SANTANA
Tarea 3
Métodos numéricos y optimización
*/

#include <stdio.h>

void imprimirValores(int*,int*);
void imprimirDirecciones(int*,int*);

int main(){
	
	int arreglo[]={1,2,3,4,5,6,7,8,9,10};
	int arreglo2[][4]={{1,2,3,4},{4,5,6,7},{4,5,6,7},{4,5,6,7},{4,5,6,7}};
	int dimension[2]={0};
	int n,m;
	
	dimension[0]=sizeof(arreglo)/sizeof(arreglo[0]);
	n=sizeof(arreglo2)/sizeof(arreglo2[0]);
	m=sizeof(arreglo2[0])/sizeof(arreglo2[0][0]);

	printf("\n\n");

	imprimirValores(&arreglo[0],&dimension[0]);
	imprimirDirecciones(&arreglo[0],&dimension[0]);
	dimension[1]=m;
	dimension[0]=n;
	imprimirValores(&arreglo2[0][0], &dimension[0]);
	imprimirDirecciones(&arreglo2[0][0], &dimension[0]);
	return 0;
}

void imprimirValores(int *ptr,int *dimension){
	int i,j;
	int n= *(dimension);
	int m=*(dimension+1);
	if(m==0){
		for(i=0;i<n;i++)
			if(i%2==1)
				printf("p[%d]=%d \n",i,*(ptr+i));
		
	}else{

		for (i = 0; i < n; ++i){
			for ( j = 0; j < m; j++){
				if((i*m+j)%2==1)
					printf("p[%d] = %d\n",i*m+j,*(ptr +i*m +j));
			}
		}
	}
	printf("\n\n");
}

void imprimirDirecciones(int *ptr,int *dimension){
	int i,j;
	int n= *(dimension);
	int m=*(dimension+1);
	if(m==0){
		for(i=0;i<n;i++)
			if(i%2==1)
				printf("%cp[%d]: %p\n",38,i, (ptr+i) );
	}else{
		for (i = 0; i < n; ++i){
			for ( j = 0; j < m; j++){
				if((i*m+j)%2==1)
					printf("%cp[%d]: %p\n",38,i*m+j,(ptr +i*m +j));
			}
		}
	}
	printf("\n\n");
}