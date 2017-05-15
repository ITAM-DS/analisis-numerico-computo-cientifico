//#include<stdio.h>
#include <iostream>
#include <vector>

__global__ void gaxpymm(int *y, int *a, int *b, int m, int n, int p){
	int bid = blockIdx.x;
        int tid = threadIdx.x;
	extern __shared__ int dots_s[];
	if(bid<m)
		if(tid<n){
			for(int c=0;c<p;c++)
				dots_s[bid*n*p+tid*p+c] = a[bid*n+tid] * *(b+(tid*p+c));
	__syncthreads();
	if(tid == 0){
		for(int c=0;c<p;c++)
			for(int i=1;i<n;i++){
				dots_s[bid*n*p+c] +=dots_s[bid*n*p+i*p+c];
//			printf("y=%d, dots_s=%d, bid=%d, tid=%d, i=%d, n=%d\n",dots_s[bid*n], dots_s[bid*n+i],bid,tid,i,n);
			}
		for(int c=0;c<p;c++)
			*(y+(bid*p+c))=dots_s[bid*n*p+c];
//		printf("y[%d]=%d, bid=%d, tid=%d\n",bid,y[bid],bid,tid);
		}
	}
}

std::vector<int> matrixMatrixMultiplication(int* a, int* b, int mc, int nc, int pc){
	int* m, *n, *p;
	m = &mc;
	n = &nc;
	p = &pc;
	std::vector<int> y(mc*pc,0);
	int *device_y, *device_a, *device_b;
	int *device_m, *device_n, *device_p;
	//alojando en device
	cudaMalloc((void **)&device_y, sizeof(int)*mc*pc);
	cudaMalloc((void **)&device_a, sizeof(int)*mc*nc);
	cudaMalloc((void **)&device_b, sizeof(int)*nc*pc);
	cudaMalloc((void **)&device_m, sizeof(int));
	cudaMalloc((void **)&device_n, sizeof(int));
	cudaMalloc((void **)&device_p, sizeof(int));
	//copiamos arreglos a, x a la GPU
	cudaMemcpy(device_a,a,mc*nc*sizeof(int), cudaMemcpyHostToDevice);
	cudaMemcpy(device_b,b,nc*pc*sizeof(int), cudaMemcpyHostToDevice);
	cudaMemcpy(device_y,y.data(),mc*pc*sizeof(int), cudaMemcpyHostToDevice);
	cudaMemcpy(device_m,m,sizeof(int), cudaMemcpyHostToDevice);
	cudaMemcpy(device_n,n,sizeof(int), cudaMemcpyHostToDevice);
	cudaMemcpy(device_p,p,sizeof(int), cudaMemcpyHostToDevice);
	//mandamos a llamar a suma_vect:
	gaxpymm<<<mc,nc,sizeof(int)*mc*nc*pc>>>(device_y,device_a,device_b,mc,nc,pc);
//	for(unsigned i=0; i<y.size();i++)
//		std::cout << "yi[i] = " << y[i] << "\n";
	//copia del resultado al arreglo y:
	cudaMemcpy(y.data(),device_y,mc*pc*sizeof(int),cudaMemcpyDeviceToHost);
//	for(unsigned i=0; i<y.size();i++)
//		std::cout << "yf[i] = " << y[i] << "\n";
	cudaFree(device_y);
	cudaFree(device_a);
	cudaFree(device_b);
	cudaFree(device_m);
	cudaFree(device_n);
	cudaFree(device_p);
	return y;
}

