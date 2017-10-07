# Ejemplos con openMP

Para los siguientes ejemplos suponemos un sistema ubuntu 14.04 (o más reciente) y que está instalado el paquete build-essential o hacemos:

```
$sudo apt-get update -y && sudo apt-get install -y build-essential
```

para instalar el compilador **gcc**.


## Parallel for directive.

OpenMP provee una directive con el nombre **parallel for**. Esta directive ayuda a paralelizar ciclos for que tienen una forma canónica (ver [imagen](https://www.dropbox.com/s/qw1dui3gfewl2jx/for_canonico_openmp.jpg?dl=0) para saber qué es un ciclo for en forma canónica). Por ejemplo, para la regla del trapecio en su forma secuencial se tienen los statements:

```
double h=(b-a)/n;
int i;
double suma_global;
suma_global = (f(a)+f(b))/2.0;
    for(i=0;i<=n-1;i++){
        suma_global += f(a+i*h);
    }
suma_global = h*suma_global;
```

y al colocar la directive **parallel for** antes del ciclo for:

```
double h=(b-a)/n;
int i;
double suma_global;
suma_global = (f(a)+f(b))/2.0;
#pragma omp parallel for num_threads(conteo_threads) reduction(+: suma_global)
    for(i=0;i<=n-1;i++){
        suma_global += f(a+i*h);
    }
suma_global = h*suma_global;
```

es posible realizar en paralelo la regla del trapecio compuesta.

Puntos a señalar:

* La directive **parallel for** realiza el proceso de fork para que un team de threads ejecuten el **structured block** que continúa a la directive, pero este structured block **debe ser un ciclo for**.

* Con la directive **parallel for** se dividen **las iteraciones del loop entre los threads** y no el trabajo. En la directive parallel se divide **el trabajo entre los threads** (ver el tipo de tareas que se tienen que realizar para la regla del trapecio en las [Notas del curso MNO](https://www.dropbox.com/s/vcxbrqkk6x946d7/2.4.Sistemas_de_memoria_compartida_openMP.pdf?dl=0)).

* Obsérvese en el ejemplo anterior que se utilizó la **reduction clause** para definir a la variable suma_global como una **reduction_variable** y de esta forma no tener una critical section pues si el código hubiera sido:

```
double h=(b-a)/n;
int i;
double suma_global;
suma_global = (f(a)+f(b))/2.0;
#pragma omp parallel for num_threads(conteo_threads)
    for(i=0;i<=n-1;i++){
        suma_global += f(a+i*h); //esta es una critical section no protegida
    }
suma_global = h*suma_global;

```

entonces suma_global es **shared** y cada thread la actualiza generando una **race condition**. Para race condition y critical section, ver [Notas del curso MNO](https://www.dropbox.com/s/vcxbrqkk6x946d7/2.4.Sistemas_de_memoria_compartida_openMP.pdf?dl=0) para una explicación de esto.


* Por default todas las variables definidas antes de una directive parallel son compartidas **pero en la directiva parallel for**, la variable del ciclo i es **private**, cada thread tiene su propia copia de la variable **i**.


Así, el programa para realizar la regla compuesta del Trapecio con una directive parallel for es:

```trapecio_parallel_for.c```:

```
#include<stdio.h>
#include<stdlib.h>
#include<math.h> //header para funciones de mate
double f(double node);
int main(int argc, char *argv[]){
    double suma_global = 0.0;
    double a=-1.0, b=3.0;
    int n=1e7; //número de subintervalos
    double objetivo=19.717657482016225;
	double h=(b-a)/n;
	int conteo_threads;//conteo_threads debe dividir de forma exacta a n
	int i;
	suma_global = (f(a)+f(b))/2.0;
	conteo_threads = strtol(argv[1], NULL, 10);
# pragma omp parallel for num_threads(conteo_threads) reduction(+: suma_global)
    for(i=0;i<=n-1;i++){
        suma_global += f(a+i*h);
    }
	suma_global = h*suma_global;
    printf("Integral de %f a %f = %1.15e\n", a,b,suma_global);
    printf("Error relativo de la solución: %1.15e\n", fabs(suma_global-objetivo)/fabs(objetivo));
    return 0;
}
double f(double nodo){
    double valor_f;
    valor_f = exp(nodo);
    return valor_f;
}

```

Compilamos:

```
$gcc -Wall -fopenmp trapecio_parallel_for.c -o trapecio_parallel_for.out -lm

```


Ejecutamos:

```
./trapecio_parallel_for.out 10
```

Resultado:

```
Integral de -1.000000 a 3.000000 = 1.971765762916819e+01
Error relativo de la solución: 7.462953721242119e-09
```

Obsérvese el error relativo y compárese con el programa secuencial en [1_parallel_and_critical_directives](../1_parallel_and_critical_directives).


## Consideraciones en el uso de la directive parallel for.

* OpenMP sólo paraleliza ciclos for, no paraleliza ciclos while o do-while.

* OpenMP sólo paraleliza los ciclos for en los que pueda determinarse el número de iteraciones:

	* con el statement del for (la línea de código que involucra: **for(...;...;...)**).

	* previamente a la ejecución del ciclo.

	* Los ciclos:

	```
	for(;;){
		...
	}
	```

	```
	for(i=0;i<n;i++){
		if(...) break;
		...
	}
	```

	**no** pueden paralelizarse pues no hay una forma de determinarse el número de iteraciones con sólo el statement del for.

* OpenMP sólo paraleliza ciclos for que se encuentren en su forma canónica (ver [imagen](https://www.dropbox.com/s/qw1dui3gfewl2jx/for_canonico_openmp.jpg?dl=0) para saber qué es un ciclo for en forma canónica).

* Para la [imagen](https://www.dropbox.com/s/qw1dui3gfewl2jx/for_canonico_openmp.jpg?dl=0) se debe cumplir:

	* La variable **indice** debe ser tipo ```int``` o ```pointer```.

	* Las variables **inicio**, **fin**, e **incr** deben tener tipo compatible. Por ejemplo, si **indice** es ```int```, entonces **incr** debe ser tipo ```int```.

	* Las expresiones **inicio**, **fin** e **incr** no deben cambiar durante la ejecución del ciclo.

	* Durante la ejecución del ciclo, la variable **indice** sólo puede ser modificada por la expresión que la incrementa.

* Es posible tener llamadas a **exit** en el cuerpo del ciclo.

Con estas consideraciones, el run-time system determina el número de iteraciones antes de que se ejecute el ciclo.

También es indispensable saber que si un cálculo en una iteración de un ciclo **depende** del resultado de una o más iteraciones anteriores, no será posible utilizar la directive parallel for sin obtener resultados diferentes. Por ejemplo, el siguiente código calcula los números de fibonacci:

```fibonacci.c```:

```
#include<stdio.h>
int main(){
	int n=12;
	int fibo[12];
	int i;
	fibo[0] = fibo[1] = 1;
	for(i = 2; i<n; i++)
		fibo[i] = fibo[i-1] + fibo[i-2];
	for(i=0;i<n;i++)
		printf("fibo[%d] = %d\n", i,fibo[i]);

return 0;
}
```

Compilamos:

```
$gcc -Wall fibonacci.c -o fibonacci.out
```

Ejecutamos:

```
./fibonacci.out
```

Con **n=12** obtenemos:

```
fibo[0] = 1
fibo[1] = 1
fibo[2] = 2
fibo[3] = 3
fibo[4] = 5
fibo[5] = 8
fibo[6] = 13
fibo[7] = 21
fibo[8] = 34
fibo[9] = 55
fibo[10] = 89
fibo[11] = 144
```

Pero si usamos la directive parallel for:

```
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[]){
	int n=12;
	int fibo[12]={0};
	int i;
	long conteo_threads;
	fibo[0] = fibo[1] = 1;
	conteo_threads = strtol(argv[1], NULL, 10);
	#pragma omp parallel for num_threads(conteo_threads)
	for(i = 2; i<n; i++)
		fibo[i] = fibo[i-1] + fibo[i-2];
	for(i=0;i<n;i++)
		printf("fibo[%d] = %d\n", i,fibo[i]);

return 0;
}
```

Compilamos:

```
$gcc -Wall -fopenmp fibonacci_parallel_for.c -o fibonacci_parallel_for.out
```

Ejecutamos:

```
$./fibonacci_parallel_for.out 4
```

Resultado:

```
fibo[0] = 1
fibo[1] = 1
fibo[2] = 2
fibo[3] = 3
fibo[4] = 5
fibo[5] = 8
fibo[6] = 13
fibo[7] = 21
fibo[8] = 0
fibo[9] = 0
fibo[10] = 0
fibo[11] = 0
```

entonces es probable que el último thread haya iniciado los cálculos antes que el tercer thread termine su trabajo.

Se tiene entonces:

* Los compiladores de openMP no checan dependencias entre las iteraciones.

* Un ciclo en el que los resultados de una o más iteraciones dependen de otras iteraciones **no se puede** paralelizar de forma correcta con openMP.

* En este ejemplo del cálculo de números de fibonacci, la dependencia de fibo[5] en el cálculo de fibo[4] se le llama **dependencia en los datos** y dado que el valor de fibo[4] es calculado en una iteración y su resultado se utiliza en una iteración subsecuente, se dice que la dependencia es del tipo **loop-carried dependence**.

## ¿Cómo encontrar loop-carried dependences?

Una forma es identificar que aunque existan **dependencia en los datos** en las líneas del código, puede ser que no sean **loop-carried dependences** por ejemplo:

```
for(i=0;i<n;i++){
	x[i] = a + i*h;
	y[i] = exp(x[i]);
}
```

Se observa en el código anterior que la última línea del for depende de la primera, sin embargo, no hay problema con utilizar la directive parallel for, pues el cálculo de **x[i]** y su subsecuente uso serán siempre realizados por el mismo thread:

```
#pragma omp parallel num_threads(conteo_threads)
	for(i=0;i<n;i++){
	x[i] = a + i*h;
	y[i] = exp(x[i]);
}
```

Otra forma de identificar loop-carried dependences es encontrar las variables que son escritas o actualizadas por el código, es decir, se deben encontrar aquellas variables que son leídas o escritas en una iteración y escritas en otra iteración. En el ejemplo de los números de fibonacci la línea de código que se realiza lo anterior es:

```
fibo[i] = fibo[i-1] + fibo[i-2];
```

## Ejemplo de estimación del número pi.

Un código secuencial para estimar al número pi es el siguiente:

```estimacion_pi_secuencial.c```:

```
#include<stdio.h>
#include<math.h>
int main(){
	double aprox;
	double factor = 1.0;
	double sum = 0.0;
	double objetivo = M_PI;
	int k;
	int n=1000;
	for(k=0;k<n;k++){
		sum+=factor/(2*k+1);
		factor = -factor;
	}
	aprox = 4.0*sum;
	printf("estimación de pi %.15e\n", aprox);
	printf("error relativo: %.15e\n", fabs(objetivo-aprox)/fabs(objetivo));
return 0;
}
```

Compilamos:

```
$gcc -Wall estimacion_pi_secuencial.c -o estimacion_pi_secuencial.out -lm
```

Ejecutamos:

```
$./estimacion_pi_secuencial.out
```

Resultado:

```
estimación de pi 3.140592653839794e+00
error relativo: 3.183098066059948e-04
```

Si quisiéramos paralelizar este código, podríamos pensar que una forma de hacerlo es:

```
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(int argc, char *argv[]){
	double aprox;
	double factor = 1.0;
	double sum = 0.0;
	double objetivo = M_PI;
	int k;
	int n=1000;
	long conteo_threads;
	conteo_threads = strtol(argv[1], NULL, 10);
	# pragma omp parallel for num_threads(conteo_threads) reduction(+:sum)
	for(k=0;k<n;k++){
		sum+=factor/(2*k+1);
		factor = -factor;
	}
	aprox = 4.0*sum;
	printf("estimación de pi %.15e\n", aprox);
	printf("error relativo: %.15e\n", fabs(objetivo-aprox)/fabs(objetivo));
return 0;
}
```

Compilamos:

```
$gcc -Wall -fopenmp estimacion_pi_parallel_for_1.c -o estimacion_pi_parallel_for_1.out -lm
```

Ejecutamos con 2 threads:

```
./estimacion_pi_parallel_for_1.out 2
```

Resultado:

```
estimación de pi 3.140592653839795e+00
error relativo: 3.183098066058534e-04
```

y si usamos 200 threads, tenemos de resultado:

```
estimación de p 3.529323649726084e+00
error relativo: 1.234186092500706e-01
```

pero en otra ejecución con 200 threads se obtuvo:

```
estimación de p -2.977077292895603e+00
error relativo: 1.947633134261947e+00
```

Lo que estamos observando es una **loop-carried dependence**. Esta dependencia surge para la variable **factor** en la segunda línea del ciclo for y su subsecuente uso en la primer línea de este ciclo. Podríamos pensar que si la iteración k se asigna a un thread y la iteración k+1 es asignado a otro thread, entonces no hay garantía que el valor de la variable **factor** esté correcto.

### ¿Cómo podríamos arreglar lo anterior?

Si analizamos el código y en particular observamos que para valores pares de **k**, la variable **factor** debería ser **+1** y para valor impares de **k**, **factor** tendría que ser **-1**. Una posibilidad sería reemplazar:

```
sum+=factor/(2*k+1);
factor=-factor;
```

por:

```
factor=(k%2==0)?1.0:-1.0;
sum+=factor/(2*k+1);
```

y al probar el código:

```estimacion_pi_parallel_for_2.c```:

```
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(int argc, char *argv[]){
	double aprox;
	double factor = 1.0;
	double sum = 0.0;
	double objetivo = M_PI;
	int k;
	int n=1000;
	long conteo_threads;
	conteo_threads = strtol(argv[1], NULL, 10);
	# pragma omp parallel for num_threads(conteo_threads) reduction(+:sum)
	for(k=0;k<n;k++){
		factor=(k%2==0)?1.0:-1.0;
		sum+=factor/(2*k+1);
	}
	aprox = 4.0*sum;
	printf("estimación de pi %.15e\n", aprox);
	printf("error relativo: %.15e\n", fabs(objetivo-aprox)/fabs(objetivo));
return 0;
}

```

Compilamos:

```
$gcc -Wall -fopenmp estimacion_pi_parallel_for_2.c -o estimacion_pi_parallel_for_2.out -lm
```

Ejecutamos:

```
./estimacion_pi_parallel_for_2.out 800
```

Resultado:

```
estimación de pi 3.140592653839793e+00
error relativo: 3.183098066062775e-04
```

y en otras ejecuciones obtenemos:

```
estimación de pi 3.105658156023199e+00
error relativo: 1.143830583049419e-02
```

### Private clause.

Otro detalle que no se ha considerado, es que la variable **factor** al ser declarada antes de la directive parallel for implica que es **shared** por lo que si un thread la actualiza antes que otro thread la utilice, podría tenerse un error. Entonces la variable **factor** debe de ser privada para cada thread, esto se logra con la **private clause**. Así se tiene el código:


```estimacion_pi_parallel_for_3.c```:

```
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(int argc, char *argv[]){
	double aprox;
	double factor = 1.0;
	double sum = 0.0;
	double objetivo = M_PI;
	int k;
	int n=1000;
	long conteo_threads;
	conteo_threads = strtol(argv[1], NULL, 10);
	# pragma omp parallel for num_threads(conteo_threads) reduction(+:sum) \
		private(factor)
	for(k=0;k<n;k++){
		factor=(k%2==0)?1.0:-1.0;
		sum+=factor/(2*k+1);
	}
	aprox = 4.0*sum;
	printf("estimación de pi %.15e\n", aprox);
	printf("error relativo: %.15e\n", fabs(objetivo-aprox)/fabs(objetivo));
return 0;
}
```

Compilamos:

```
$gcc -Wall -fopenmp estimacion_pi_parallel_for_3.c -o estimacion_pi_parallel_for_3.out -lm
```

Ejecutamos:

```
$./estimacion_pi_parallel_for_3.out 800
```

Resultado:

```
estimación de pi 3.140592653839794e+00
error relativo: 3.183098066061361e-04
```

**Nota**:

* El valor de una variable **private** no está especificado antes del parallel block ni después del parallel block (de igual forma para el parallel for block) a diferencia de una variable **shared** que tienen el mismo valor definido antes del parallel o parallel for block y su valor después del block es aquel que se le asignó en el último paso del block.

### default clause.

Es buena práctica utilizar la **default clause** para obligarnos a definir si las variables que serán utilizadas en un parallel block o en un parallel for block son **shared** o son **private**.

Añadiendo la clause:

```
default(none)
```

a nuestra directive parallel o a la directive parallel for, el compilador exigirá que se defina si las variables a utilizar en el block y que fueron definidas **antes** del block si son **shared** o **private**. Por ejemplo, debemos para las 4 variables que se utilizarán en el ciclo for, definir lo anterior:

```estimacion_pi_parallel_for_4.c```:

```
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(int argc, char *argv[]){
	double aprox;
	double factor = 1.0;
	double sum = 0.0;
	double objetivo = M_PI;
	int k;
	int n=1000;
	long conteo_threads;
	conteo_threads = strtol(argv[1], NULL, 10);
	# pragma omp parallel for num_threads(conteo_threads) default(none) \
		reduction(+:sum) private(k, factor) shared(n)
	for(k=0;k<n;k++){
		factor=(k%2==0)?1.0:-1.0;
		sum+=factor/(2*k+1);
	}
	aprox = 4.0*sum;
	printf("estimación de pi %.15e\n", aprox);
	printf("error relativo: %.15e\n", fabs(objetivo-aprox)/fabs(objetivo));
return 0;
}

```

Compilamos:

```
$gcc -Wall -fopenmp estimacion_pi_parallel_for_4.c -o estimacion_pi_parallel_for_4.out -lm
```

Ejecutamos:

```
./estimacion_pi_parallel_for_4.out 800
```

Resultado:

```
estimación de pi 3.140592653839793e+00
error relativo: 3.183098066062775e-04
```

Obsérvese, que si no se define si son **shared** o **private** se obtiene al momento de compilar:

```
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(int argc, char *argv[]){
	double aprox;
	double factor = 1.0;
	double sum = 0.0;
	double objetivo = M_PI;
	int k;
	int n=1000;
	long conteo_threads;
	conteo_threads = strtol(argv[1], NULL, 10);
	# pragma omp parallel for num_threads(conteo_threads) default(none) \
		reduction(+:sum)
	for(k=0;k<n;k++){
		factor=(k%2==0)?1.0:-1.0;
		sum+=factor/(2*k+1);
	}
	aprox = 4.0*sum;
	printf("estimación de pi %.15e\n", aprox);
	printf("error relativo: %.15e\n", fabs(objetivo-aprox)/fabs(objetivo));
return 0;
}
```

los errores:

```
estimacion_pi_parallel_for_5.c: In function 'main':
estimacion_pi_parallel_for_5.c:13:11: error: 'n' not specified in enclosing parallel
  # pragma omp parallel for num_threads(conteo_threads) default(none) \
           ^
estimacion_pi_parallel_for_5.c:13:11: error: enclosing parallel
estimacion_pi_parallel_for_5.c:16:9: error: 'factor' not specified in enclosing parallel
   factor=(k%2==0)?1.0:-1.0;
         ^
estimacion_pi_parallel_for_5.c:13:11: error: enclosing parallel
  # pragma omp parallel for num_threads(conteo_threads) default(none) \
```












