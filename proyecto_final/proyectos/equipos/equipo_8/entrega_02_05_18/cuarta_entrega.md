Cuarta Entrega
===============

Luis Fernando Cantú

Eduardo Hidalgo

Mónica Vargas

El juego de Cournot
-------------------

El trabajo escrito se puede encontrar en esta [carpeta de Dropbox](https://www.dropbox.com/sh/j43sr790kcdl5lf/AACYIRnGhhEvhlVdk7-iG9Wqa?dl=0).

Estas fueron las contribuciones individuales:
* Luis Fernando Cantú: continúo con la elaboración del trabajo escrito. Específicamente escribió la parte del modelo del juego de Cournot y al ejemplo del caso lineal.
* Mónica Vargas González:

int Steepest_Descent( double (*f)(double *), void (*df)(double *, double *), int (*stopping_rule)(double*, double, double*, double, double*, int, int), double a[], double *fa, double *dfa, double cutoff, double cutoff_scale_factor, double tolerance, int n )
Esta rutina de C utiliza el método del descenso de gradiente más empinado para localizar el mínimo local de una función f(x) que provee el usuario. El proceso empieza con x=a un valor inicial. El gradiente es calculado usando la función df(x, dfa) donde dfa es el arreglo dimensional cuyo componente i es la derivada parcial de f(x) con respecto a esa xi. Los parámetros cutoff, cutoff_scale_factor and tolerance son usados para minimizar la función, en el sentido contrario al gradiente dado
Los argumentos para la regla de parado proporcionada por el programador son: punto inicial x0,  la función evaluada en el punto inicial f(x0), el nuevo estimador f(x), el gradiente de la función evaluada en el nuevo punto dfa, el total de número de interacciones realizadas y la dimensión n de x.
La regla de parado debe regresar un número entero diferente de zero, para parar el proceso y regresar 0 para continuar iterando. Los valores restantes -1, -2, -3, -4, and -5 son valores intrínsecos usados por la rutina. Al existir la función regresa alguno de estos:
	0 Éxito
	-1 Tres puntos son colineares
	-2 El extremo de la parábola entre los 3 puntos es el máximo
	-3 Los puntos iniciales fracasaron para satisfacer la condición que: x1 < x2 < x3 and fx1 > fx2 < fx3
	-4 No hay memoria suficiente
	-5 El gradiente evaluado en el punto inicial desaparece
	Otro especificado por el usuario en stopping_rule()

El siguiente archivo contiene la version de Steepest_Descent( ) escrito en C:
http://www.mymathlib.com/c_source/optimization/nonlinear/unconstrained/steepest_descent.c

* Eduardo Hidalgo García: modificación del archivo escrito (cambio de imágenes por tablas y explicación de la tabla 1.1). Especificación de los distintos métodos para la estimación de mínimos locales por modificaciones al descenso en gradiente.
