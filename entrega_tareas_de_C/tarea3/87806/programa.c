// Alejandro Hernandez Farias, Clave Unica: 87806
// Tarea 3

#include <stdio.h>

// Funcion para imprimir el valor que recibe apuntador y dimension.
void imprime_valor(int *ap,int dim){
        int i;
        for (i=1;i<dim;i=i+2){
                printf("p[%d]=%d\n",i,*(ap+i));
        }
}

// Funcion para imprimir direcciones de memoria que recibe apuntador y dimension.
void imprime_direccion(int *ap, int dim){
        int i;
        for (i=1;i<dim;i=i+2){
                printf("&p[%d]=%p\n",i,(ap+i));
        }
}


main()
{
				// Probamos las funciones con el arreglo p.
				int p[10]={-1,-2,-3,-4,-5,-6,-7,-8,-9,-10};
        int *ap=p;
        int dim=sizeof(p)/sizeof(p[0]);
        imprime_valor(ap,dim);
        printf("\n");
        imprime_direccion(ap,dim);

        printf("\n\n");

				// Probamos las funciones con el arreglo multidimensional.
				int arreglo_mult[2][3];
        arreglo_mult[0][0]=-1;
        arreglo_mult[0][1]=-2;
        arreglo_mult[0][2]=-3;
        arreglo_mult[1][0]=-4;
        arreglo_mult[1][1]=-5;
        arreglo_mult[1][2]=-6;
        int *ap2=arreglo_mult[0];
        int dim2=sizeof(arreglo_mult)/sizeof(arreglo_mult[0])+sizeof(arreglo_mult[0])/sizeof(arreglo_mult[0][0])+1;
        imprime_valor(ap2,dim2);
        printf("\n");
        imprime_direccion(ap2,dim2);
}
