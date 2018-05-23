#include<stdio.h>

void funcion1(int *p, int n, int k){
        int i;
        for(i=1;i<n;i++){
                printf("arreglo%d[%d]=%d\n",k,i,*(p+i));
                i=i+1;
        }
}


void funcion2(int *p, int n, int k){
        int i;
        for(i=1;i<n;i++){
                printf("arreglo%d[%d]=%p\n",k,i,(p+i));
                i=i+1;
        }
}

int main(){
	int arreglo1[10]; //declaración y definición
	int i;
	//inicialización del arreglo1:
	for(i=0;i<10;i++){
		arreglo1[i] =-i-1;
	}
	//Inicialización del arreglo2:
        int arreglo2[2][3] = {{-1,-2,-3}, {-4,-5,-6}};

	//Imprimimos todo el arreglo1 y su apuntador
	for(i=0;i<10;i++){
		printf("arreglo1[%d] = %d\n",i,arreglo1[i]);
		printf("arreglo1[%d] = %p\n",i,&arreglo1[i]);
	}
	//Imprimimos el valor de las posiciones impares
	for(i=1;i<10;i++){
		printf("arreglo1[%d] = %d\n",i, arreglo1[i]);
		i=i+1;
	}
	//Imprimimos el apuntador de las posiciones impares
	for(i=1;i<10;i++){
		printf("arreglo1[%d] = %p\n",i,&arreglo1[i]);
		i=i+1;
	}

	//Llamamos a la función del arreglo1
	int *p;
	p = arreglo1;
	int n = sizeof(arreglo1) / sizeof(arreglo1[0]);
	int k = 1;
	funcion1(p,n,k);
	funcion2(p,n,k);

	//Llamamos a la función del arreglo2
	p = arreglo2[0];
	n = sizeof(arreglo2) / sizeof(arreglo2[0][0]);
	k = 2;
	funcion1(p,n,k);
	funcion2(p,n,k);


}



