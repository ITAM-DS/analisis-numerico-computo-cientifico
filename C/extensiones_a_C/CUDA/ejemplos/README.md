#Ejemplos

##Programa de hello world:

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

##Programa hello world 2:

```
#include<stdio.h>
__global__ void func(void){
	printf("Hello world del bloque %d del thread %d!\n", blockIdx.x, threadIdx.x);
}
int main(void){
	func<<<10,10>>>();
	cudaDeviceSynchronize();
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

##Programa de suma:

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


















