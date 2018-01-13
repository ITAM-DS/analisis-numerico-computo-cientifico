# Investigación Conceptos C

## LAPACK (Linear Algebra Package)

Es un librería para algebra lineal númerica. Provee de rutinas para resolver sistemas de ecuaciones lineales, mínimos cuadrados, descomposición de valores singulares y problemas de valores propios. Incluye también rutinas de factorización de matrices como son LU, QR y descomposiciones de Cholesky y Schur y está actualmente escrito en Fortran 90. Esta rutinas manejan matrices tanto de valores reales como complejos de simple o doble precisión, también es posible manejar matrices densas y en bandas pero en general no de forma adecuada matrices ralas. 

## BLAS (Basic Linear Algebra Subprograms)

Esta paquetería de software está constituida por rutinas que proveen los bloques estándares de construcción para realizar operaciones vectoriales y matriciales básicas. El nivel 1 de BLAS realiza operaciones escalares, vectoriales y vector-vector, el nivel 2 se encarga de operaciones matriz vector y el nivel 3 se encarga de operaciones matriz-matriz. Gracias a que es estas rutinas son eficientes, portables y altamente disponibles son usadas comunmente en el desarrollo de software de algebra lineal de alta calidad como lo es LAPACK. 

## ATLAS (Automatically Tuned Linear Algebra Software)

Esta paquetería es un esfuerzo en curso que se enfoca en aplicar técnicas empíricas para proveer un desempeño portátil de alto rendimiento. En cierto sentido ATLAS, define varias operaciones de BLAS y LAPACK en términos de rutinas 'core' y luego intenta ajustar estas rutinas a que tengan un buen desempeño. Una forma en la que se persigue este objetivo es a través de una búsqueda para elegir tamaños adecuados para los bloques, los cuales dependen del tamaño del caché así como de la arquitectura de la computadora. 

## La subrutina ```dgemm``` de Fortran 

Esta subrutina escrita en fortran forma parte de la paquetería BLAS del nivel 3, que se agrega a la compilación con la banderas ```-lf2c -lm ``` y ejecuta una de las operaciones matriz-matriz 

```C:= alpha*op(A)*op(B) + beta*C```

donde 

- op(X) = X o op(X) = X' 
- alpha y beta son escalares
- A, B, C son matrices con 
	- op(A) matriz de m x k
	- op(B) matriz de k x n
	- C matriz de m x n 

Fue escrita el 8 de Febrero de 1989 por 
	   - Jack Dongarra, Argonne National Laboratory.   
       - Iain Duff, AERE Harwell.   
       - Jeremy Du Croz, Numerical Algorithms Group Ltd.   
       - Sven Hammarling, Numerical Algorithms Group Ltd.  

### Biblio

http://www.netlib.org/
https://en.wikipedia.org/wiki/