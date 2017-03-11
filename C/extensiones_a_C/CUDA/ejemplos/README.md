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