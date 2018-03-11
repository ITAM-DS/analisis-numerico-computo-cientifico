int main(){
int arreglo[5]={1,2,3,4,5};
int i;
int total = sizeof(arreglo)/4;

printf("Elementos: %d\n",total);
printf("Función 1\n");

for(i=0;i<total;i++){
        if(i%2!=0){
                printf("Posición %d, valor %d\n",i,*(arreglo+i));
        }
}
printf("\nFunción 2\n");

for(i=0;i<total;i++){
        if(i%2!= 0){
                printf("posición %d, memoria: %p\n", i, arreglo+i);
        }
}
return 0;

}


