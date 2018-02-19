#include<stdio.h>
main(){


	int arr_1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9 ,10};
	int arr_2[2][3] = {-1, -2, -3, -4, -5, -6};
	int i, n, n2;
    	int *apuntador, *apuntador2;

apuntador = arr_1;
n = sizeof(arr_1)/sizeof(arr_1[0]);

apuntador2 = arr_2;
n2 = sizeof(arr_2)/sizeof(arr_2[0][0]);

printf("\n Tamaño arreglo 1: %i \n Tamaño arreglo 2: %i \n",n, n2);


int funcion_1(int *apuntador, int n){
	printf("\n ========Función 1 \n  \n\n");
	for (i=1;i<n;i=i+2){
		printf("Entrada %i: %i \n", i, apuntador[i]);
	}
}
int funcion_2(int *apuntador, int n){
        printf("\n ========Función 2 \n  \n\n");
	for (i=1;i<n;i=i+2){
		printf("Direccion %i: %p \n", i, (apuntador+i));
	}

}

printf("\n\n\n\n ARREGLO 1 ==================================\n\n\n");
funcion_1(arr_1, n);
funcion_2(arr_1, n);

printf("\n\n\n\n ARREGLO 2 ==================================\n\n\n");
funcion_1(arr_2, n2);
funcion_2(arr_2, n2);
//
//int funcion_2(int *apuntador2, int n2){
//        printf("\n ======== \n Función 2 \n\n");
//        for (i=1;i<n2;i=i+2){
//                printf("Entrada %i: %i \n", i, apuntador2[i]);
//        }
//
//        for (i=1;i<n2;i=i+2){
//                printf("Direccion %i: %p \n", i, (apuntador2+i));
//        }
//
//}
//funcion_2(arr_2, n2);

}
