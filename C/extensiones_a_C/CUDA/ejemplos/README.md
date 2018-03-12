# Ejemplos

Asumimos que tenemos un sólo device.


## Programa de hello world:

```
#include<stdio.h>
__global__ void func(void){
	
}
int main(void){
	func<<<1,1>>>();
	printf("Hello world!\n");
	return 0;
}
```

Compilamos:

```
$nvcc hello_world.cu -o hello_world.out
```

Ejecutamos:

```
./hello_world.out
```

## Programa hello world 2:

Usamos la función `cudaDeviceSynchronize` para que el CPU-thread espere hasta que el device haya completado todos los tasks previos.


```
#include<stdio.h>
__global__ void func(void){
	printf("Hello world del bloque %d del thread %d!\n", blockIdx.x, threadIdx.x);
}
int main(void){
	func<<<3,3>>>(); //3 bloques de 3 threads cada uno
	cudaDeviceSynchronize();
	printf("Hola del cpu thread\n");
	return 0;
}

```

Compilamos:

```
$nvcc hello_world_2.cu -o hello_world_2.out
```

Ejecutamos:

```
./hello_world_2.out
```

Salida:

```
Hello world del bloque 1 del thread 0!
Hello world del bloque 1 del thread 1!
Hello world del bloque 1 del thread 2!
Hello world del bloque 0 del thread 0!
Hello world del bloque 0 del thread 1!
Hello world del bloque 0 del thread 2!
Hello world del bloque 2 del thread 0!
Hello world del bloque 2 del thread 1!
Hello world del bloque 2 del thread 2!
Hola del cpu thread

```

En la [documentación](http://docs.nvidia.com/cuda/cuda-runtime-api/group__CUDART__DEVICE.html#group__CUDART__DEVICE_1g10e20b05a95f638a4071a655503df25d) de la función `cudaDeviceSynchronize` se menciona que para que el cpu-thread espere teniendo un 0% de uso hay que definir una flag llamada `cudaDeviceScheduleBlockingSync`:


```
#include<stdio.h>
__global__ void func(void){
	printf("Hello world del bloque %d del thread %d!\n", blockIdx.x, threadIdx.x);
}
int main(void){
	cudaSetDeviceFlags(cudaDeviceScheduleBlockingSync);
	func<<<3,3>>>();
	cudaDeviceSynchronize();
	printf("Hola del cpu thread\n");
	return 0;
}

```


## Programa de suma:

```
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

```

Compilamos:

```
$nvcc suma.cu -o suma.out
```

Ejecutamos:

```
./suma.out
```

## Programa de suma vectorial:

Lanzamos `N` bloques de 1 thread que ejecuten el kernel.


```
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

```

















