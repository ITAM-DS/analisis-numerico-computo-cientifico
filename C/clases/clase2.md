# Introducción

En las operaciones podemos realizar asignaciones con la expresión: `operador` `=`:

```
#include<stdio.h>
main(){
	double variable =1;
	printf("variable %f\n", variable);
	variable /=2;//se realiza:variable = variable /2;
	printf("variable: %0.4e\n",variable);
}
```

Un ejemplo entre conversión y una suma de un número tipo `double` y un número tipo `int`, en la operación de `double + int` el `int` se convierte a `double`, esto se llama **promotion**:

```
#include<stdio.h>
main(){
	int variable_int;
	double variable_double = -5291.485;
	printf("variable double=%0.5f\n", variable_double);
	variable_int = variable_double;
	printf("variable_int = %d\n",variable_int);
	printf("variable_double+variable_int=%f\n",variable_double+variable_int);
}
```

La función de printf considera variables double con `%f` e int con `%d`, no importando si son de un tamaño menor.

Una expresión utilizada es con el doble signo `+`, y doble signo `-`

```
#include<stdio.h>
main(){
	int i,j;
	i=3;
	printf("Valor de i inicial :%d\n",i);
	i++; //i = i+1;
	printf("Valor de i con i++: %d\n", i);
	i=3;
	//++i; //i = i+1;
	printf("Valor de i con i++: %d\n", ++i);
	i=12;
	printf("Valor de i antes de dar valor a j: %d\n", i);
	j=i++ + 5;
	printf("Valor de i después de dar valor a j con i++: %d\n", i);
	printf("Valor de j con i++: %d\n", j);
	i=12;
	printf("Valor de i antes de dar valor a j: %d\n", i);
	j=++i + 5;
	printf("Valor de i después de dar valor a j con ++i: %d\n", i);
	printf("Valor de j con i++: %d\n", j);
	i=0;
	printf("Valor de i antes de dar valor a j: %d\n", i);
	j = i-- + 5;
	printf("Valor de i con i--: %d\n", i);
	printf("Valor de j = i--+5: %d\n", j);
	i=0;
	printf("Valor de i antes de dar valor a j: %d\n", i);
	j = --i + 5;
	printf("Valor de i con --i: %d\n", i);
	printf("Valor de j = --i+5: %d\n", j);
}
```

Ejemplo para operadores lógicos y relacionales:

```
#include<stdio.h>
main(){
	printf("Comparamos 4<5: %d\n", 4<5);
	printf("Comparamos 1<3 && 2 <0: %d\n", 1<3 && 2<0);
}
```

##  Uso de for:

Con `#define`definimos una constante. Lo usamos así: `define nombre texto`, `texto` es una secuencia de caracteres.

```
#include<stdio.h>
#define LIMITE_INFERIOR 0
#define LIMITE_SUPERIOR 5
main(){
	int contador;
	double variable1=3485.7, variable2=-4.01;
	printf("variable1 = %4.2f \t variable2 = %1.2f\n", variable1,variable2);
	printf("limite inferior: %d\n",LIMITE_INFERIOR);
	printf("limite superior: %d\n",LIMITE_SUPERIOR);
	printf("Iteracion \t variable1 \t variable2 \t División variable1 entre variable2\n");
	for(contador=LIMITE_INFERIOR; contador < LIMITE_SUPERIOR; contador = contador+1){
		printf("%d \t \t %4.1f \t \t %2.2f \t \t %1.3f\n", contador, variable1,variable2,variable1/variable2);
		variable2/=2;
	}
}

```

##  Uso de while:

```
#include<stdio.h>
main(){
		int variable;
		variable=10;
		printf("Variable antes de while: %d\n", variable);
		while(variable-1){
			printf("valor de variable = %d\n", variable);
			--variable;
		}
		printf("Fin de while\n");
		printf("Variable después del while: %d\n",variable);
	}

```

¿Cuál es la diferencia entre los siguientes programas?:

```
#include<stdio.h>
main(){
	int variable=10;
	printf("Variable antes de while: %d\n", variable);
	while(--variable){
		printf("valor de variable = %d\n", variable);
		--variable;
	}
	printf("Fin de while\n");
	printf("Variable después del while: %d\n",variable);
}
```

```
#include<stdio.h>
main(){
	int variable =10;
	printf("Variable antes de while: %d\n", variable);
	while(variable--){
		printf("valor de variable = %d\n", variable);
		--variable;
	}
	printf("Fin de while\n");
	printf("Variable después del while: %d\n",variable);
}
```

##  Uso de if:

```
#include<stdio.h>
main(){
	int variable=-437, variable2;
	if(variable1<=10)printf("Primer if: variable1 menor o igual a 10\n");
	if(variable1>10){
		printf("Segundo if: variable1 mayor a 10\n");//no es necesario el uso de llaves
	}
	else
		printf("Segundo if: variable1 menor o igual que 10\n");

	printf("Otra forma es con ?:\n");

	variable2=(variable1 <= 10)?variable1:0;
	printf("Usando signo ? para asignar el valor de variable2: %d\n",variable2);

}
```

##  Uso de switch:

```
#include<stdio.h>
main(){
	int variable1 = -5;
	int variable2;

	switch(variable1){
		case 0:
			variable2 = -variable1;
			printf("Primer caso se cumplió, variable2=%d\n",variable2);
		case -10:
			variable2 = variable1;
			printf("Segundo caso se cumplió, variable2=%d\n",variable2);
		default:
		variable2 = variable1*10;
		printf("Caso default se cumplió, variable2=%d\n",variable2);

	}
}


```
