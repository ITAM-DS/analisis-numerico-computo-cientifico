#include<stdio.h>

void values(int *p, int length){
	int i;
	for(i=0;i<=length;i++){
	   if(i%2!= 0){
	     printf("p[%i]:%i\n", i, *(p+i));
		}
	}
}

void direcciones(int *p, int length){
	int i;
	for(i=0;i<=length;i++){
	   if(i%2!= 0){
             printf("&p[%d]:%p\n", i, (p+i));
		}
	}
}

main(){

	int array[10]={0,-1,-2,-3,-4,-5,-6,-7,-8,-9};
	int *p = array;
	int length = sizeof(array)/sizeof(array[0]);
	values(p, length);
	direcciones(p, length);
	printf("\n");

	int array_2[2][5];
         array_2[0][0]=0;
         array_2[0][1]=-1;
         array_2[0][2]=-2;
	 array_2[0][3]=-3;
	 array_2[0][4]=-4;
         array_2[1][0]=-5;
         array_2[1][1]=-6;
         array_2[1][2]=-7;
	 array_2[1][3]=-8;
	 array_2[1][4]=-9;
        int *p_2=array_2[0];
        int length_2=sizeof(array_2)/sizeof(array_2[0])+sizeof(array_2[0])/sizeof(array_2[0][0])+1;
         values(p_2,length_2);
         direcciones(p_2,length_2);
  
}

