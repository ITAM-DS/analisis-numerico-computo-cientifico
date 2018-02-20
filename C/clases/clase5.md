# Introducción

##  Macros

Un programa se traduce en distintas fases. Las primeras fases están relacionadas con transformaciones léxicas a partir de `directivas` que involucran líneas que empiezan con el caracter `#` y permiten comunicarse con el preprocesador y realizar sustituciones macro, inclusión de archivos o compilación condicional. Al finalizar el preprocesamiento, el programa ha sido reducido a una secuencia de `tokens`, entre los que se encuentran los `identificadores` o nombres.

Una línea de la forma: `#define identificador secuencia-token` como se vio en la [clase2](/C/clases/clase2.md) realiza una sustitución del identificador con la `secuencia-token`. Y una línea de la forma `#define identificador(lista-de-identificadores) secuencia-token` es una definición macro con parámetros dados en `lista-de-identificadores`.


Ejemplo1:

```
#include<stdio.h>
#define TAMANIO 100
main(){
		int arreglo[TAMANIO]; //definimos y declaramos un arreglo de
							//tamaño igual a TAMANIO que es 100
							//TAMANIO es el identificador, 100 es la secuencia-token
}
```

Cada ocurrencia de `TAMANIO` en el código será reemplazada por `100`.


Es posible definir `macros` con argumentos, de modo que el texto reemplazado sea distinto para diferentes llamados a la macro.

Ejemplo2:

```
#include<stdio.h>
#define MAX(A,B) ((A) > (B) ? (A) : (B))
//MAX es el identificador
//A,B es la lista de identificadores separados por comas
//((A) > (B) ? (A) : (B)) es la secuencia-token
main(){
}

```

Cada ocurrencia en el código de:

```
...
	x = MAX(p+q, r+s);
...

```

Será reemplazada por la línea:

```
...
   x = ((p+q) > (r+s) ? (p+q) : (r+s));
...

```

y no es necesario especificar el tipo de dato (`int`, `char`, `double`) en la macro `MAX` siempre que sea consistente el llamado con argumentos correctos. Los argumentos de la macro y lo que regresa la misma pueden ser de cualquier tipo o incluso ser apuntadores.

Algunas notas en la definición de una macro:

1) Observa que para el ejemplo de `MAX` siguiente, se incrementa dos veces la `variable1` y la `variable2`:

```
#include<stdio.h>
#define MAX(A,B) ((A) > (B) ? (A) : (B))
main(){
	int variable1=15;
	int variable2=8;
	int variable3;
	printf("variable1: %d\n", variable1);
	printf("variable2: %d\n", variable2);
	variable3=MAX(++variable1,++variable2);
	printf("variable3=MAX(++variable1,++variable2) :%d\n",variable3);
	printf("variable1: %d\n", variable1);
	printf("variable2: %d\n", variable2);
}

```

Y este doble incremento, no tiene que ver con el orden `++variable1` o `variable1++`:

```
#include<stdio.h>
#define MAX(A,B) ((A) > (B) ? (A) : (B))
main(){
	int variable1=15;
	int variable2=8;
	int variable3;
	printf("variable1: %d\n", variable1);
	printf("variable2: %d\n", variable2);
	variable3=MAX(variable1++,variable2++);
	printf("variable3=MAX(variable1++,variable2++) :%d\n",variable3);
	printf("variable1: %d\n", variable1);
	printf("variable2: %d\n", variable2);
}

```

Los argumentos son evaluados dos veces, uno para la prueba del operador `>` y otro para producir el resultado de la condición del `if` en la definición de la macro.

2) El uso de paréntesis es necesario:

```
#include<stdio.h>
#define SQUARE(x) x*x
#define SQUARE2(x) (x)*(x)
main(){
	int variable1;
	int variable2;
	int variable3;
	int variable4;
	int variable5;
	int variable6;
	variable1 = SQUARE(3);
	variable2 = SQUARE(variable1);
	variable3 = SQUARE(variable1 + 1);
	printf("variable1 = SQUARE(3):%d\n", variable1);
	printf("variable2 = SQUARE(variable1):%d\n", variable2);
	printf("variable3 = SQUARE(variable1 + 1): %d\n", variable3);
	variable4 = SQUARE2(3);
	variable5 = SQUARE2(variable1);
	variable6 = SQUARE2(variable1 + 1);
	printf("variable4 = SQUARE2(3):%d\n", variable4);
	printf("variable5 = SQUARE2(variable4):%d\n", variable5);
	printf("variable6 = SQUARE2(variable4 + 1): %d\n", variable6);
}

```

**(Observa que si se llama a la macro SQUARE con el argumento `(variable+1)` obtenemos para `variable3` un valor de 100)**

3) Podemos llamar más de una vez a la macro:

```
#include<stdio.h>
#define VALOR_ABS_DIFERENCIA(x,y) ((x)>(y) ? (x)-(y):(y)-(x))
main(){
        int variable1=-10;
        int variable2=-5;
        int variable3=1;
        printf("variable1:%d\n",variable1);
        printf("variable2:%d\n",variable2);
        printf("variable3:%d\n",variable3);
        printf("abs(variable1-variable2):%d\n",VALOR_ABS_DIFERENCIA(variable1, variable2));
        printf("abs(variable3-abs(variable1-variable2)):%d\n",VALOR_ABS_DIFERENCIA(variable3,VALOR_ABS_DIFERENCIA(variable1, variable2)));
}
```

Si quisiéramos revisar el reemplazamiento de texto que se realiza sin compilar y crear un ejecutable, podemos para el programa siguiente:

```
#define VALOR_ABS_DIFERENCIA(x,y) ((x)>(y) ? (x)-(y):(y)-(x))
main(){
	VALOR_ABS_DIFERENCIA(2,3);
}

```

ejecutar:

```
$gcc -E ejemplo_sustitucion_texto.c
```

para observar la sustitución de texto que realiza C. Output de la compilación:

```
# 1 "ejemplo_sustitucion_texto.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "ejemplo_sustitucion_texto.c"

main(){
 ((2)>(3) ? (2)-(3):(3)-(2));
}

```


## Funciones

Ejemplo de definición y declaración de funciones:

```
#include<stdio.h>
//Declaración de la función calcula_epsilon_maquina:
double calcula_epsilon_maquina(double variable); //esta línea se llama prototipo de la función									
//Declaración de la función imprime_resultado:
void imprime_resultado(double res);//esta línea se llama prototipo de la función
//definición de la función main:
int main(){
        double epsilon=1.0;
        double resultado;
        resultado=calcula_epsilon_maquina(epsilon);
        imprime_resultado(resultado);
    return 0;
}
//definición de la función imprime_resultado:
void imprime_resultado(double result){
	printf("Valor del epsilon de la máquina: %e\n", result);
}
//definición de la función calcula_epsilon_maquina:
double calcula_epsilon_maquina(double var){ 
	double respuesta;
        while(1.0+var != 1.0)
        var = var/2.0;
    	respuesta = var;
        return respuesta;
}
```
El prototipo de una función declara los parámetros que recibe con su tipo de dato y nombres y el tipo de dato que regresa la función.

El prototipo debe coincidir con la definición de la función, pero los nombres no son necesarios que coincidan.

De acuerdo al ejemplo anterior, los nombres usados por los parámetros y variables de una función son locales a la función y no son visibles para otra función. No entran en conflicto nombres declarados en funciones distintas, por lo que pueden usar dos funciones, por ejemplo, mismos nombres sin problemas. En la función `calcula_epsilon_maquina` el parámetro `var` y la variable `respuesta` son locales a esta función y su tiempo de vida es temporal, mientras se ejecuta la función.

El tipo `void` denota un valor no existente o el hecho de que ningún valor es regresado por la función. No es necesario que las funciones tengan un `return`. Es posible ignorar el valor regresado por una función.

La definición de una función puede aparecer en cualquier orden.


## Paso de argumentos por valor

Todos los argumentos para una función son `pasados por valor`. Esto se refiere a que la función que es llamada no puede modificar directamente una variable que se definió en la función que la llamó.

Ejemplo:

```
#include<stdio.h>
void cambia(int x, int y);
int main(){
	int a=1; //variable declarada y definida en main
	int b=2; //variable declarada y definida en main
	cambia(a,b);
	printf("valor de a: %d, valor de b: %d\n", a,b);
	return 0;
}
void cambia(int x, int y){
	int temporal;
	temporal = x;
	x=y;
	y=temporal;
}

```
Entonces la función `cambia` modifica los argumentos `a, b` de manera local, pero tales modificaciones no se comunican a la función `main` que fue la que llamó a la función `cambia`. Los parámetros de `cambia` realizan copias locales de los valores de `a,b` de `main`. Al terminar la ejecución de `cambia`, la memoria local para esta función desaparece y con ella `x, y, temporal`.

## Paso de argumentos por referencia

Si se desea modificar los valores de `a, b` definidos y declarados en `main` en la función `cambia` del ejemplo anterior, utilizamos lo que se conoce como paso de argumentos por referencia:

```
#include<stdio.h>
void cambia(int *x, int *y); //utilizamos apuntadores
int main(){
	int a=1;
	int b=2;
	cambia(&a,&b); //utilizamos las direcciones de memoria de a,b
	printf("valor de a: %d, valor de b: %d\n", a,b);
	return 0;
}
void cambia(int *x, int *y){
	int temporal;
	temporal = *x;
	*x=*y;
	*y=temporal;
}
```

De esta forma no se copian los valores de `a, b` definidos y declarados en `main` en la función `cambia`.


## La función main

La función main se define por convención como:

```
int main(){

	return 0;
}

```

Un valor de `0` implica una finalización normal. Este valor se le regresa al ambiente en el que el programa fue ejecutado.


Si la función recibe argumentos de la línea de comandos, entonces el nombre de sus parámetros es `argc` y `argv`:

```
int main(int argc, char *argv[]){
	//argc es el número de argumentos
	//argv son los argumentos
	return 0;
}

```

Ejemplo:

```
#include<stdio.h>
int main(int argc, char *argv[]){
	printf("argc: %d\n", argc);
	printf("argv[0]: %s\n", argv[0]);
	printf("argv[1]: %s\n", argv[1]);
	printf("argv[2]: %s\n", argv[2]);
	return 0;
}

```
Compilamos:

```
$gcc ejemplo.c -o ejemplo.out

```

Ejecutamos:

```
./ejemplo.out -18 "Ejemplo para paso de argumentos a main"
```

Para convertir el argumento `-18` a `int` podemos usar `atoi`:

```
#include<stdio.h>
int main(int argc, char *argv[]){
	printf("argc: %d\n", argc);
	printf("argv[0]: %s\n", argv[0]);
	printf("argv[1]: %s\n", argv[1]);
	printf("argv[2]: %s\n", argv[2]);
	printf("argv[1]: %d\n",atoi(argv[1]));
	return 0;
}

```

Compilamos:

```
$gcc ejemplo.c -o ejemplo.out

```

Ejecutamos:

```
./ejemplo.out -18 "Ejemplo para paso de argumentos a main"
```
