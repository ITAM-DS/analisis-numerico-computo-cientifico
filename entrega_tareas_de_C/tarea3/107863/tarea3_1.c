
#include <stdio.h>

int main()
{
    int arreglo[10][1] ;
    int i;
    int k = 1;
    int j;
    int renglones;
    int columnas;
    renglones = sizeof(arreglo)/sizeof(arreglo[0]);
    columnas = sizeof(arreglo[0])/sizeof(arreglo[0][0]);

    for(i=0;i<renglones;i++){
                for(j=0;j<columnas;j++){
                        arreglo[i][j] = (k * -1);
            k = k + 1;
                }
        }

    /* Start loop from 1 and increment it by 1 */


    k = 0;
    for(i=0;i<renglones;i++){
        for(j=0;j<columnas;j++){
            if(i%2!=0){
            printf("&p[%d] = %d\n",k,arreglo[i][j]);
            }
            k = k + 1;
        }
    }    

    
  k = 0;
    for(i=0;i<renglones;i++){
           for(j=0;j<columnas;j++){
        if(i%2!=0){
                printf("&p[%d] = %p\n",k,&arreglo[i][j]);
                }
        k = k + 1;
           }
    }


}