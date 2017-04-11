#include<stdio.h>
__global__ void suma(int a, int b, int *c){
    *c = a+b;
}
int main(void){
    int c;
    int *device_c;
    cudaMalloc((void **)&device_c,sizeof(int));
    suma<<<1,1>>>(2,7,device_c);
    cudaMemcpy(&c, device_c, sizeof(int), cudaMemcpyDeviceToHost);
    printf("2+7 = %d\n", c);
    cudaFree(device_c);
    return 0;
}
