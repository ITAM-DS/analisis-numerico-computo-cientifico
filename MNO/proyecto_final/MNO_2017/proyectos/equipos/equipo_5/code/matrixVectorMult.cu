//#include<stdio.h>
#include <iostream>
#include <vector>

__global__ void gaxpy(int *y, int *a, int *x, int m, int n){
	int bid = blockIdx.x;
        int tid = threadIdx.x;
	extern __shared__ int dots_s[];
	if(bid<m)
		if(tid<n){

			dots_s[bid*n+tid] = a[bid*n+tid] * *(x+tid);
	__syncthreads();
	if(tid == 0){
		for(int i=1;i<n;i++){
			dots_s[bid*n] +=dots_s[bid*n+i];
//			printf("y=%d, dots_s=%d, bid=%d, tid=%d, i=%d, n=%d\n",dots_s[bid*n], dots_s[bid*n+i],bid,tid,i,n);
		}
		*(y+bid)=dots_s[bid*n];
//		printf("y[%d]=%d, bid=%d, tid=%d\n",bid,y[bid],bid,tid);
		}
	}
}

std::vector<int> matrixVectorMultiplication(int* a, int mc, int nc, int* x){
	int* m, *n;
	m = &mc;
	n = &nc;
	std::vector<int> y(mc,0);
	int *device_y, *device_a, *device_x;
	int *device_m, *device_n;
	//alojando en device
	cudaMalloc((void **)&device_y, sizeof(int)*mc);
	cudaMalloc((void **)&device_a, sizeof(int)*mc*nc);
	cudaMalloc((void **)&device_x, sizeof(int)*nc);
	cudaMalloc((void **)&device_m, sizeof(int));
	cudaMalloc((void **)&device_n, sizeof(int));
	//copiamos arreglos a, x a la GPU
	cudaMemcpy(device_a,a,mc*nc*sizeof(int), cudaMemcpyHostToDevice);
	cudaMemcpy(device_x,x,nc*sizeof(int), cudaMemcpyHostToDevice);
	cudaMemcpy(device_y,y.data(),mc*sizeof(int), cudaMemcpyHostToDevice);
	cudaMemcpy(device_m,m,sizeof(int), cudaMemcpyHostToDevice);
	cudaMemcpy(device_n,n,sizeof(int), cudaMemcpyHostToDevice);
	//mandamos a llamar a suma_vect:
	gaxpy<<<mc,nc,sizeof(int)*mc*nc>>>(device_y,device_a,device_x,mc,nc);
//	for(unsigned i=0; i<y.size();i++)
//		std::cout << "yi[i] = " << y[i] << "\n";
	//copia del resultado al arreglo y:
	cudaMemcpy(y.data(),device_y,mc*sizeof(int),cudaMemcpyDeviceToHost);
//	for(unsigned i=0; i<y.size();i++)
//		std::cout << "yf[i] = " << y[i] << "\n";
	cudaFree(device_y);
	cudaFree(device_a);
	cudaFree(device_x);
	cudaFree(device_m);
	cudaFree(device_n);
	return y;
}

