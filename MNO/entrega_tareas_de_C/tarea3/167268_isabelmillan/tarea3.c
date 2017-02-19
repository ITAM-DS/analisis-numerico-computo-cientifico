#include <stdio.h>

// Este programa  imprime las entradas impares de un arreglo unidimensional y multidimensional así como sus direcciones de memoria

void imprime_adress(int*,int, int);
void imprime_valores(int*,int,int);

int main(){
	int arreglo[10] = {1,2,3,4,5,6,7,8,9,10};
	int arreglo2[2][3] = {{1,2,3},{4,5,6}};
	int len = 0;
	int len2 = 0;

	len = sizeof(arreglo)/sizeof(arreglo[0]);
	printf("Los valores del arreglo son: \n");
	imprime_valores(&arreglo[0],len, len2);
	printf("El adress del arreglo: \n");
	imprime_adress(&arreglo[0],len, len2);
	len = sizeof(arreglo2)/sizeof(arreglo2[0]);
	len2 = sizeof(arreglo2[0])/sizeof(arreglo2[0][0]);
	printf("Los valores del arreglo multidimensional son: \n");
	imprime_valores(&arreglo2[0][0], len, len2);
	printf("El adress del arreglo multidimensional: \n");
	imprime_adress(&arreglo2[0][0], len, len2);
}

void imprime_valores (int *loc, int lon, int lon2){
	int i,j;
	int contador = 0;
	int n = lon;
//arreglo unidimensional
	if (lon2==0){
		for (i=0 ; i<n; i++){
			if(i%2 == 1)
				printf("p[%d] : %d \n",i, *(loc + i));
		}
//arreglo multidimensional
	}else{
		for (i=0; i<lon; i++){
			for(j=0; j<lon2; j++){
				if(contador%2==1){
					printf("p[%d] : %d\n", contador, *(loc + contador));
				}
				contador++;
			}
		}
	}
}

void imprime_adress (int *loc, int lon, int lon2){
        int i,j;
        int contador =0;
        int n = lon;
//arreglo unidimensional
        if (lon2 == 0){
                for (i = 0 ; i<n; i++){
                        if(i%2 == 1)
                                printf("p[%d] : %p \n",i, loc + i);
                }
//arreglo multidimensional
        }else{
                for (i=0; i<lon; i++){
                        for(j=0; j<lon2; j++){
                                if(contador%2==1){
                                        printf("p[%d] : %p\n", contador, loc + contador);
                                }
				contador++;
                        }
                }
	}
}
