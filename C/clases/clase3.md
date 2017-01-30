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

´´´
#include<stdio.h>
main(){
	
	int arreglo_multidimensional[4][3];
	printf("Total de bytes alojados para arreglo_multidimensional %ld\n",sizeof(arreglo_multidimensional));
	printf("Total de bytes alojados para arreglo_multidimensional[0] %ld\n",sizeof(arreglo_multidimensional[0]));
	printf("Total de bytes alojados para arreglo_multidimensional[0][0] %ld\n", sizeof(arreglo_multidimensional[0][0]));
	printf("Número de renglones: %ld\n", sizeof(arreglo_multidimensional)/sizeof(arreglo_multidimensional[0]));
	printf("Número de columnas: %ld\n", sizeof(arreglo_multidimensional[0])/ sizeof(arreglo_multidimensional[0][0]));
}

´´´



























