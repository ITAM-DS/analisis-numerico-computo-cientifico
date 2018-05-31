#include<stdio.h>
#define N 10
__global__ void suma_vect(int *a, int *b, int *c){
	int tid = blockIdx.x;
	if(tid<N)
		c[tid] = a[tid]+b[tid];
}
int main(void){
	int a[N], b[N],c[N];
	int *device_a, *device_b, *device_c;
	int i;
	//alojando en device
	cudaMalloc((void **)&device_a, sizeof(int)*N);
	cudaMalloc((void **)&device_b, sizeof(int)*N);
	cudaMalloc((void **)&device_c, sizeof(int)*N);
	//llenando los arreglos:
	for(i=0;i<N;i++){
		a[i]=i;
		b[i]=i*i;
	}
	//copiamos arreglos a, b a la GPU
	cudaMemcpy(device_a,a,N*sizeof(int), cudaMemcpyHostToDevice);
	cudaMemcpy(device_b,b,N*sizeof(int), cudaMemcpyHostToDevice);
	//mandamos a llamar a suma_vect:
	suma_vect<<<N,1>>>(device_a,device_b,device_c);
	//copia del resultado al arreglo c:
	cudaMemcpy(c,device_c,N*sizeof(int),cudaMemcpyDeviceToHost);
	for(i=0;i<N;i++)
		printf("%d+%d = %d\n",a[i],b[i],c[i]);
	cudaFree(device_a);
	cudaFree(device_b);
	cudaFree(device_c);
	return 0;
}