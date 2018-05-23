// Tarea 3 Federico RIveroll 105898

#include <stdio.h>

void valores(int *ap,int dim){
        int i;
        for (i = 0; i < dim; i ++){
		i++;
                printf("p[%d]=%d\n", i, *(ap+i));
        }
}

// Funcion para imprimir direcciones de memoria que recibe apuntador y dimension.
void direcciones_de_memoria(int *ap, int dim){
        int i;
        for (i = 0; i < dim; i ++){
		i ++;
                printf("&p[%d]=%p\n", i, (ap+i));
        }
}


main()
{

	int arreglo[10]={-1,-2,-3,-4,-5,-6,-7,-8,-9,-10};
        int *ap=arreglo;
        int dim=sizeof(arreglo)/sizeof(arreglo[0]);
        valores(ap, dim);
        printf("\n");
        direcciones_de_memoria(ap, dim);

        printf("\n\n");


	int matriz[2][3];
        matriz[0][0] = -1;
        matriz[0][1] = -2;
        matriz[0][2] = -3;
        matriz[1][0] = -4;
        matriz[1][1] = -5;
        matriz[1][2] = -6;
        int *ap2 = matriz[0];
        int dim2 = sizeof(matriz)/sizeof(matriz[0])+sizeof(matriz[0])/sizeof(matriz[0][0])+1;
        valores(ap2, dim2);
        printf("\n");
        direcciones_de_memoria(ap2, dim2);
}
