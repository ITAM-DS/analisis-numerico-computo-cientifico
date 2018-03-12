#include <stdio.h>





void imp_num( int intarray[] , int n){
 int i;
 for (i = 0 ; i < n; i++){
     if ( i % 2 != 0){
         printf(" El elemento %d del arreglo es : %d \n",i,intarray[i]);


     }
 
 }

}

void imp_dir( int intarray[] , int n){
 int i;
 for (i = 0 ; i < n; i++){
     if ( i % 2 != 0){
         printf(" La direccion del elemento %d del arreglo es : %d \n",i,&intarray[i]);


     }
 
 }

}




int main(){


printf("----Arreglo 1d----- \n");
int array_1[] = {1,2,3,4,5,6,7,8,9,10};
int n = sizeof(array_1)/sizeof(array_1[0]);
imp_num(array_1,n);
imp_dir(array_1,n);

printf("----Arreglo md-----\n");
int array_m[2][3] = {
    {1,2,3},
    {4,5,6}
};
int m = sizeof(array_m)/sizeof(array_m[0][0]);
imp_num(array_m,m);
imp_dir(array_m,m);


}
