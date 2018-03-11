# Introducción

##  Storage classes.

Para una definición de main del tipo:

```
int main(void){
	return 0;
}

```

al compilar y ejecutar el programa, el sistema operativo designa un espacio en memoria que será utilizado por el proceso (programa en ejecución) y en particular para la función `main`. Típicamente la implementación para este espacio de memoria por el sistema es una estructura de datos que es un stack.

Al definir y declarar una variable dentro de `main` se utiliza un bloque de memoria que previamente el sistema designó para `main`. Por ejemplo:

```
int main(void){
	int variable; //definición y declaración de variable
	return 0;
}
```

se ha utilizado un bloque de memoria de tamaño `int` para la variable local `variable` en el espacio designado por el sistema para `main` y este bloque de memoria guardará el valor de variable. 

Se dice que una variable es `allocated` o alojada cuando se le da un bloque de memoria para almacenar su valor. Una variable es `deallocated` o desalojada cuando el sistema reclama la memoria de la variable y no tiene por más tiempo un bloque designado para guardar su valor. El periodo de tiempo para una variable en el que un bloque de memoria es alojado hasta ser desalojado se le llama `tiempo de vida` de la variable.

Hay diferentes tipos de storage classes; para el ejemplo anterior, el bloque de memoria que a `variable` se le ha asignado, tiene un tiempo de vida que es local a la ejecución de `main` y el bloque de memoria es desalojado al finalizar la ejecución `main`. Entonces decimos que el tipo de storage class que tiene `variable` es `automatic`.

El tipo `automatic` es designado para todas las variables que son locales a una función, no es necesario utilizar el keyword: `auto` para especificar este tipo de storage class, es decir, para el ejemplo anterior, el tiempo de vida de `variable` es el mismo con el programa anterior que si hubiéramos especificado el tipo de storage class `auto` en el programa:

```
int main(void){
	auto int variable; //auto es un keyword que indica un tipo de 
					//storage class automatic
	return 0;
}

```

Otro ejemplo:

```
int f(double var);
int main(){
	double variable_main;
	f(variable_main);
	return 0;
}
int f(double variable_f){
	int variable2_f;
	return variable2_f;
}
```

Al ejecutar el programa anterior, se aloja un bloque de memoria para la variable local `variable_main` cuyo tiempo de vida es hasta el statement `return 0;`, es decir, se desaloja el bloque en el momento que se ejecuta este statetment, tiene un storage class de tipo `automatic`.

Asimismo, al llamar a la función `f`, se alojan bloques de memoria para su parámetro `variable_f` y para la variable local `variable2_f` (el bloque de memoria alojado para `variable_main` continúa existiendo). Los tiempos de vida de `variable_f`, `variable2_f` finalizan con el statement `return variable2_f;`, es decir los bloques de memoria alojados para cada una de estas variables son desalojados en el momento que se ejecuta el statement `return variable2_f;` tienen un storage class de tipo `automatic`


Si se declara una variable afuera de una función sin ningún keyword, tal variable es compartida por el programa entero, son globales en el sentido que están disponibles para más de una función, incluso para funciones que hayan sido compiladas por separado, y se hace referencia a ella con el mismo nombre, esto se le llama external linkage.

Las variables externas (externas: declaradas afuera de una función) tienen un tiempo de vida permanente entre llamados de una función a otra. Pueden ser modificados sus valores por el uso que hagan de ellas las funciones:

Ejemplo:

```
#include<stdio.h>
int variable_externa = -2; //definición, declaración e inicialización de variable externa
							//es global para todas las funciones 
							//definidas en este programa
int funcion(int var); //declaración de funcion
int main(void){
	int variable_main=10;
	int respuesta;
	printf("variable_externa:%d\n", variable_externa);
	respuesta=funcion(variable_main);
	printf("respuesta:%d\n", respuesta);
	printf("variable_externa:%d\n", variable_externa);
	return 0;
}
//definición de funcion:
int funcion(int variable_funcion){
	int variable2_funcion=5;
	variable_externa = 1;
	return (variable_funcion - variable2_funcion)/variable_externa;
}

```

Observa que si se define y declara `variable_externa` después de `main` entonces antes de main hay que declarar con el keyword `extern` a `variable_externa`, es decir, tenemos un **error** al compilar el programa:

```
#include<stdio.h>
int funcion(int var);//declaración de funcion
//no hay declaraciones de variable_externa
int main(void){
	int variable_main=10;
	int respuesta;
	printf("variable_externa:%d\n", variable_externa); //el nombre variable_externa no ha sido declarado previamente a main
	respuesta=funcion(variable_main);
	printf("respuesta:%d\n", respuesta);
	printf("variable_externa:%d\n", variable_externa);
	return 0;
}
int variable_externa = -2; //definición, declaración e inicialización de variable externa
							//es global para todas las funciones 
							//definidas en este programa
//definición de funcion				
int funcion(int variable_funcion){
	int variable2_funcion=5;
	variable_externa = 1;
	return (variable_funcion - variable2_funcion)/variable_externa;
}

```

Arreglamos este error, haciendo:

```
#include<stdio.h>
int funcion(int var);//declaración de funcion
extern int variable_externa; //declaración de variable_externa
int main(void){
	int variable_main=10;
	int respuesta;
	printf("variable_externa:%d\n", variable_externa);
	respuesta=funcion(variable_main);
	printf("respuesta:%d\n", respuesta);
	printf("variable_externa:%d\n", variable_externa);
	return 0;
}
int variable_externa = -2; //definición y declaración de variable externa
							//es global para todas las funciones 
							//definidas en este programa
//definicion de funcion
int funcion(int variable_funcion){
	int variable2_funcion=5;
	variable_externa = 1;
	return (variable_funcion - variable2_funcion)/variable_externa;
}
```

Una diferencia entre las palabras declaración y definición es que con la declaración no se crean a las variables o se reserva almacenamiento para ellas, sólo se le indica al compilador que tal variable se encuentra definida en otro lugar. Con definición se reserva almacenamiento y también sirve para la declaración.

Se tiene entonces que una definición es:

```
#include<stdio.h>
int variable_externa = -2; //definición, declaración e inicialización de variable externa
							//es global para todas las funciones 
							//definidas en este programa. Se reserva almacenamiento para variable_externa.
```

Y una declaración es:

```
#include<stdio.h>
extern int variable_externa; //declaración de variable_externa, no se reserva almacenamiento para variable_externa
```

La inicialización de una variable externa sólo es correcta en la definición de la variable. Es decir, tenemos un warning al compilar:

```
#include<stdio.h>
int funcion(int var);
extern int variable_externa; //declaración de variable_externa
int main(void){
	int variable_main=10;
	int respuesta;
	printf("variable_externa:%d\n", variable_externa);
	respuesta=funcion(variable_main);
	printf("respuesta:%d\n", respuesta);
	printf("variable_externa:%d\n", variable_externa);
	return 0;
}
int variable_externa; //definición y declaración de variable externa
							//es global para todas las funciones
							//definidas en este programa

variable_externa=-2; //esta línea genera un warning al compilar
int funcion(int variable_funcion){
	int variable2_funcion=5;
	variable_externa = 1;
	return (variable_funcion - variable2_funcion)/variable_externa;
}
```

y también un warning en el ejemplo:


```
#include<stdio.h>
int funcion(int var);
extern int variable_externa=-2; //declaración de variable_externa, tenemos un warning por haber inicializado la variable extern
int main(void){
	int variable_main=10;
	int respuesta;
	printf("variable_externa:%d\n", variable_externa);
	respuesta=funcion(variable_main);
	printf("respuesta:%d\n", respuesta);
	printf("variable_externa:%d\n", variable_externa);
	return 0;
}
int variable_externa; //definición y declaración de variable externa
							//es global para todas las funciones
							//definidas en este programa

int funcion(int variable_funcion){
	int variable2_funcion=5;
	variable_externa = 1;
	return (variable_funcion - variable2_funcion)/variable_externa;
}
```



En el caso de arreglos externos, en la definición se especifica su tamaño, en la declaración su tamaño es opcional, es decir:

Definición:

```
#include<stdio.h>
int arreglo[10];//definición y declaración de arreglo. Se debe de especificar su tamaño en la definición

```


Declaración:

```
#include<stdio.h>
extern int arreglo[]; //declaración de arreglo. El tamaño del arreglo es opcional escribirlo, podría haber sido: extern int arreglo[10]; 
```

Debe sólo haber una definición para una variable externa entre todos los archivos que conforman al programa y puede haber más de una declaración en el mismo archivo para la misma variable. En los archivos entonces se usa el keyword `extern` para declaraciones, también en el mismo archivo donde está la definición es posible usar el keyword `extern`



Ejemplo de dos archivos:

ejemplo_variables_externas.c:

```
#include<stdio.h>
int variable_externa = -2; //definición y declaración de variable externa
							//es global para todas las funciones 
							//definidas en este programa
int funcion(int var);
extern void funcion2(void);
int main(void){
	int variable_main=10;
	int respuesta;
	printf("variable_externa:%d\n", variable_externa);
	respuesta=funcion(variable_main);
	printf("respuesta:%d\n", respuesta);
	printf("variable_externa:%d\n", variable_externa);
	printf("llamando a funcion2:\n");
	funcion2();
	return 0;
}
int funcion(int variable_funcion){
	int variable2_funcion=5;
	variable_externa = 1;
	return (variable_funcion - variable2_funcion)/variable_externa;
}
```

ejemplo2_variables_externas.c:

```
#include<stdio.h>
extern int variable_externa;
void funcion2(void){
	printf("variable_externa: %d\n", variable_externa);
}
```

compilamos:

```
gcc -Wall ejemplo_variables_externas.c ejemplo2_variables_externas.c -o ejemplo_variables_externas.out

```

##  Heap memory

La memoria heap o memoria dinámica es una alternativa para la local stack memory (ver inicio de esta clase), la cual es alojada **automáticamente** al llamar a una función y es desalojada ****automáticamente al terminar la ejecución de la misma, otras características de la stack memory es que este alojamiento y desalojamiento está **optimizado en tiempo y espacio** y hay un **límite** para el tamaño de las variables que pueden ser alojadas en el stack.

En la memoria heap, explícitamente **se solicita al sistema el alojamiento** de un bloque de memoria de tamaño particular, y este bloque continúa siendo alojado hasta que de forma explícita se **solicite su desalojo**. Lo anterior representa como mínimo **dos ventajas**:

1) La primera es que el tiempo de vida de las variables es modificado pues **persisten** entre llamados a funciones, así la función caller puede recibir de la función callee una estructura de datos creada en la función callee en la memoria heap. 2) La segunda es que el **tamaño** de la memoria alojada en la memoria heap puede ser controlada con más detalle, por ejemplo en lugar de definir y declarar un string como sigue:


```
char string[100];
```

podemos con la memoria heap, definir at run time, el tamaño exacto del string.

La memoria heap es un área de memoria que está **disponible para el uso del programa** con **límite en tamaño** para las variables **de acuerdo a las limitaciones físicas de cada máquina**.

Entre las **desventajas** al usar la memoria heap, es que la lectura y escritura en esta memoria es lento en comparación con la memoria stack pues los alojamientos de bloques de memoria para **variables distintas** en la memoria heap **no necesariamente son contiguos** (como en la memoria stack), otra desventaja es que **explícitamente** en el código se tienen que **alojar y desalojar** a los bloques de memoria y por ello potencialmente más bugs podrían existir en el código; un **memory leak** es un bloque de memoria alojado en la memoria heap que nunca fue desalojado por un programa, el resultado de esto es que la memoria heap puede **gradualmente llenarse** por lo que el programa puede dejar de funcionar o "crash" si se ejecuta por un tiempo indeterminado.

En C usamos las funciones `malloc` y `free` para alojar y desalojar bloques de memoria respectivamente:

```
void* malloc(size_t size);
```

`malloc` devuelve un apuntador a un bloque de memoria heap (en bytes) **contiguo** del tamaño dado por el 
parámetro `size` o `NULL` si no pudo satisfacerse el pedido. `size_t` es un tipo de dato `unsigned long` y con el operador `sizeof` se puede calcular el tamaño en bytes de un tipo, por ejemplo `sizeof(int)`. El apuntador que devuelve malloc es del tipo `void*`.


```
void free(void* heap_block);
```

`free` recibe el apuntador al bloque de memoria heap **alojado por malloc()** y regresa este bloque al 
heap para su reuso. El apuntador que se pasa a `free` debe ser **exactamente** el apuntador que fue regresado por `malloc` no cualquier apuntador al bloque en la memoria heap. Si se llama a `free` con el apuntador que regresa `malloc` y se vuelve a llamar a `free` entonces se tiene un error. El bloque alojado en la memoria heap una vez desalojado **no debe** ser desalojado por una segunda vez.


Ejemplo:

```
#include<stdio.h>
#include<stdlib.h> //para malloc y free
int main(void){
	int *apuntador; //variable definida en el stack
	//llamamos a malloc, la cual aloja un bloque en la memoria heap. Como malloc regresa un apuntador,
	//guardamos este apuntador en el valor de p:
	apuntador = malloc(sizeof(int));
	//podemos imprimir la dirección de memoria del bloque en la memoria heap:
	printf("address de apuntador: %p\n", apuntador);
	*apuntador = 42; //damos valor al bloque de memoria en la memoria heap.
	//imprimimos el valor guardado en el bloque de memoria:
	printf("valor de *apuntador:%d\n", *apuntador);
	//desalojamos el bloque de memoria en la memoria heap con free:
	free(apuntador);
	return 0;
}

```

Ejemplo para alojar 10 bloques de memoria contiguos en la memoria heap para almacenar cada bloque un`int`, es decir, un arreglo de tamaño 10*4 = 40 bytes:

Podemos usar a la función `assert` para revisar que `malloc` nos devuelve no `NULL`:

```
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
main(void){
	int *apuntador;
	apuntador = malloc(sizeof(int)*10);
	assert( apuntador != NULL); //en caso de ser NULL con assert se muestra un mensaje de error y se aborta la
						//ejecución del programa
	apuntador[0] = 3;
	apuntador[1] = 2;
	apuntador[2] = 5;
	printf("apuntador[%d] = %d\t apuntador[%d] = %d\t apuntador[%d] = %d\n",0,apuntador[0],1,apuntador[1],2,apuntador[2]);
	printf("&apuntador[%d] = %p\t &apuntador[%d] = %p\t &apuntador[%d] = %p\n",0,&apuntador[0],1,&apuntador[1],2,&apuntador[2]);
	free(apuntador);
	return 0;
}

```

Ejemplo para alojar 20\*1e9 bloques de memoria contiguos en la memoria heap para almacenar cada bloque un `int`, es decir, un arreglo de tamaño 20\*1e9\*4 = 80 gb:

```
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
main(void){
	int *apuntador;
	printf("%ld\n",(long int)(20*1e9));
	apuntador = malloc(sizeof(int)*(long int)(20*1e9));
	assert( apuntador != NULL); //en caso de ser NULL con assert se muestra un mensaje de error y se aborta la
						//ejecución del programa
	apuntador[0] = 3;
	apuntador[1] = 2;
	apuntador[2] = 5;
	apuntador[(long int)(20*1e9)] = -10;
	printf("apuntador[%d] = %d\t apuntador[%d] = %d\t apuntador[%d] = %d\n",0,apuntador[0],1,apuntador[1],2,apuntador[2]);
	printf("&apuntador[%d] = %p\t &apuntador[%d] = %p\t &apuntador[%d] = %p\n",0,&apuntador[0],1,&apuntador[1],2,&apuntador[2]);
	printf("&apuntador[%ld] = %p\t apuntador[%ld] = %d\n", (long int)(20*1e9), &apuntador[(long int)(20*1e9)], (long int)(20*1e9),apuntador[(long int)(20*1e9)]);
	free(apuntador);
	return 0;

```

