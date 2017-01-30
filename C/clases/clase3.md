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





















