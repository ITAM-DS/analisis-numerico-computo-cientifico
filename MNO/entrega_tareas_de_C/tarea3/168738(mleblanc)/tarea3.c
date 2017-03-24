#include <stdio.h>

void funcion_uno(int *arreglo,int size_arr,int size_arr_pointeur);
void funcion_dos(int *arreglo,int size_arr,int size_arr_pointeur);


main () {


    int arreglo[6]={1,23,56,8,98,45};
    int arreglo_multi[3][3]={{1,2,52},{3,56,42},{75,8,14}};
    
    printf("essai_function_uno_arreglo------------------------\n"); 
    funcion_uno(arreglo,sizeof(arreglo),sizeof(*arreglo));
    printf("\n");

    printf("essai_function_uno_arreglo_multi------------------------\n");
    funcion_uno(arreglo_multi,sizeof(arreglo_multi),sizeof(*arreglo_multi));
    printf("\n");

    printf("essai_function_dos_arreglo------------------------\n"); 
    funcion_dos(arreglo,sizeof(arreglo),sizeof(*arreglo));
    printf("\n");
    
    printf("essai_function_dos_arreglo_multi------------------------\n");
    funcion_dos(arreglo_multi,sizeof(arreglo_multi),sizeof(*arreglo_multi));
    printf("\n");    
}

void funcion_uno(int *arreglo,int size_arr,int size_arr_pointeur) {

    int i,j;
    if(size_arr_pointeur/sizeof(int)!=1){

        for (j=0;j<size_arr_pointeur/sizeof(int);j++){

            for (i=0;i<size_arr/size_arr_pointeur;i++){

                if ((i+j)%2!=0) {printf("p[%d][%d]=%d\n",i,j,*(arreglo+(i+j*(size_arr_pointeur/sizeof(int))) ) );} // aqui j*(size_arr_pointeur/sizeof(int)) para jump cada columna
            }                                                                                                      //realizamos una deferencia lineal 
        }
    } 
    
    else {

        for (i=0;i<size_arr/size_arr_pointeur;i++){

                if (i%2!=0) {printf("p[%d]=%d\n",i,*(arreglo+i) );}
        }
    }       
}

void funcion_dos(int *arreglo,int size_arr,int size_arr_pointeur) {

    int i,j;

    if(size_arr_pointeur/sizeof(int)!=1){

        for (j=0;j<size_arr_pointeur/sizeof(int);j++){

            for (i=0;i<size_arr/size_arr_pointeur;i++){

                if ((i+j)%2!=0) {printf("&p[%d][%d]=%p\n",i,j,(arreglo+(i+j*(size_arr_pointeur/sizeof(int))) ) );}
            }
        }
    } 
    
    else {

        for (i=0;i<size_arr/size_arr_pointeur;i++){

                if (i%2!=0) {printf("&p[%d]=%p\n",i,(arreglo+i));}
        }
    }       
}


    



