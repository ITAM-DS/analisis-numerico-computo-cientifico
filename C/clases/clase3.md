#Introducción

Dos tipos de datos que nos ayudan a agrupar datos: structs y arrays


##Structs

Ejemplo de definición y declaración de un struct:

```
#include<stdio.h>

main(){
		struct fraccion{
			int numerador;
			char denominador;
		}; //declaramos el nombre del struct con dos miembros: un int y un char

		struct fraccion f; //definimos y declaramos f: struct fraccion
		f.numerador = -5;//inicializamos al miembro int
		f.denominador = 'E'; //inicializamos al miembro char
		printf("struct fraccion numerador: %d\n", f.numerador);
		printf("struct fraccion caracter: %c\n",f.denominador);
}
```
Podemos hacer copias entre structs con el símbolo de =:

```
#include<stdio.h>

main(){
		struct fraccion{
			int numerador;
			char denominador;
		}; //declaramos el nombre del struct con dos miembros: un int y un char

		struct fraccion f1,f2; //definimos y declaramos f: struct fraccion
		f1.numerador = -5;//inicializamos al miembro int
		f1.denominador = 'E'; //inicializamos al miembro char
		f2=f1;
		printf("struct fraccion numerador: %d\n", f2.numerador);
		printf("struct fraccion caracter: %c\n",f2.denominador);

}
```
##Arrays

Ejemplo sencillo de definición y declaración de un arreglo de enteros:

```
#include<stdio.h>
main(){
	int arreglo1[5]; //declaración y definición
	int arreglo2[3] = {0}; //inicializamos al arreglo2 con ceros
	int i;
	//inicializamos al arreglo1:
		for(i=0;i<5;i++)
			arreglo1[i]=i;
		
	//imprimimos arreglo1:
		for(i=0;i<5;i++)
			printf("arreglo1[%d]=%d\n",i,arreglo1[i]);
	printf("----------------\n");
	//imprimimos arreglo2:
		for(i=0;i<3;i++)
			printf("arreglo2[%d]=%d\n",i,arreglo2[i]);
}

```


Podemos obtener la longitud de un arreglo con la función `sizeof`

```
#include<stdio.h>
main(){
	int arreglo[7];
	printf("Tamaño en bytes de arreglo: %ld\n", sizeof(arreglo));
	printf("Tamaño en bytes de arreglo posición 0: %ld\n", sizeof(arreglo[0]));
	printf("Longitud de arreglo: %ld\n", sizeof(arreglo)/sizeof(arreglo[0]));

}

```

Arreglo multidimensionaL

```
#include<stdio.h>
main(){
	
	int arreglo_multidimensional[4][3];
	printf("Total de bytes alojados para arreglo_multidimensional %ld\n",sizeof(arreglo_multidimensional));
	printf("Total de bytes alojados para arreglo_multidimensional[0] %ld\n",sizeof(arreglo_multidimensional[0]));
	printf("Total de bytes alojados para arreglo_multidimensional[0][0] %ld\n", sizeof(arreglo_multidimensional[0][0]));
	printf("Número de renglones: %ld\n", sizeof(arreglo_multidimensional)/sizeof(arreglo_multidimensional[0]));
	printf("Número de columnas: %ld\n", sizeof(arreglo_multidimensional[0])/ sizeof(arreglo_multidimensional[0][0]));
}

```

##Apuntadores:

Un apuntador es una variable que contiene el address de una variable.

Ejemplo para definición y declaración de un apuntador hacia una variable `int`:

```
#include<stdio.h>
main(){
	int *p;// int * p // int* p
}
```

```
#include<stdio.h>
main(){
	int *p;
	int c;
	printf("Total de bytes para apuntador: %ld\n",sizeof(p));
	printf("Total de bytes para int:%ld\n",sizeof(c));
}
```
Con el operador `&`podemos obtener el address de una variable:

```
#include<stdio.h>
main(){
	int variable;
	printf("address de variable: %p\n", &variable);
}
```

Es fundamental `inicializar`a un apuntador. Una forma es con `&`:

```
#include<stdio.h>
main(){
	int variable;
	int *p;
	double *p2;
	p = &variable;//inicializamos al apuntador p
	printf("Address de variable int: %p\n", &variable);
	printf("Address de apuntador: %p\n", p);
	printf("sizeof double p2: %ld\n",sizeof(p2));
}

```


```
#include<stdio.h>
main(){
	int variable;
	int *p = &variable;
	double *p2;
	printf("Address de variable int: %p\n", &variable);
	printf("Address de apuntador: %p\n", p);
	printf("sizeof double p2: %ld\n",sizeof(p2));
}

```
































