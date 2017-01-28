

#Introducción

En las operaciones podemos realizar asignaciones
con la expresión: `operador``signo`:

```
#include<stdio.h>
main(){
	double variable =1;
	printf("variable %f\n", variable);
	variable /=2;//se realiza:variable = variable /2;
	printf("variable: %0.4e\n",variable);
}
```

Un ejemplo entre conversión y una suma de un número tipo `double` y un número tipo `int`
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


