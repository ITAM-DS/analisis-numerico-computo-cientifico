
# Tarea 5

---

**CU:** 105720

**Nombre:** Sonia Mendizábal Claustro

27 de marzo de 2017

---




#### a. Investiga por qué se usan `""` en la línea que tiene include en `main.c` y en `funciones.c` en lugar de usar `< >`.

Se usa para incluir *header files* o *source files* con la terminación
`.h`. Ésto permite incluir el contenido del archivo referenciado entre `""`
en el programa en el que se hace el llamado. 


---

#### b. Investiga el uso de static en la definición de variables externas de funciones.c.

El uso de `static` puede implementarse dentro de 
una función, dentro de la definición 
de una clase, o bien, al declarar un variable global o externa en 
un archivo usando programas de archivos externos. 

El uso que nos interesa es este último, en el que el objetivo 
de declarar `static` de la variable indica que otros archivos
parte del programa, 
no pueden acceder ni modificar la variable. Únicamente 
el código en la que se define la variable puede 
*verla*.

---
 
 
 
#### c. Modifica el archivo `funciones.c` para que alojes e inicialices a las matrices matriz1, matriz2 y matriz_resultado con `malloc` y apuntadores. Modifica `main.c` para que llame a una función dentro del archivo `funciones.c` que inicialice y aloje a las matrices anteriores y llame a otra función para que las desaloje una vez hecha la multiplicación (usa `free`):


En el archivo `funciones.c` se agregan las funciones 
`aloja_espacio_e_incializa_matrices()` que aloja e inicializa las 
matrices necesarias. También se crea la función `libera_espacio()` que 
desaloja las matriz después de realizar la multiplicación e imprimirlas. 


En la archivo `main.c` se agregan las funciones antes mencionadas. 
En este mismo archivo se hace referencia a las definiciones 
de las variables y funciones del archivo `definiciones.h`. 
En este último archivo se agrega la definición `void` de 
las dos nuevas variables creadas. 

Finalmente, se ejecutan las funciones y se tiene el siguiente 
resultado. 
```
$gcc main.c funciones.c -o programa.out
$./programa.out

Matriz1
matriz1[0][0]=0.00	matriz1[0][1]=1.50
matriz1[1][0]=4.00	matriz1[1][1]=-5.00
matriz1[2][0]=-1.00	matriz1[2][1]=2.50

Matriz2
matriz2[0][0]=1.00	matriz2[0][1]=0.00	matriz2[0][2]=0.00
matriz2[1][0]=0.00	matriz2[1][1]=-1.00	matriz2[1][2]=1.00

Matriz resultado
matriz_res[0][0]=0.00	matriz_res[0][1]=-1.50	matriz_res[0][2]=1.50
matriz_res[1][0]=4.00	matriz_res[1][1]=5.00	matriz_res[1][2]=-5.00
matriz_res[2][0]=-1.00	matriz_res[2][1]=-2.50	matriz_res[2][2]=2.50
```

---


#### d. Compara tu resultado usando la subrutina de Fortran dgemm y los siguientes archivos `definiciones2.h`, `main2.c`, `funciones2.c` .

En los archivos `definiciones2.h`, `main2.c` y `funciones2.c` 
se encuentra la adaptación de las funciones necesarias 
para este inciso. 

A continuación se muestra el resultado al 
ejecutar el nuevo programa. 
Los resultados obtenidos son los mismos. La función `dgemm`
realiza la multiplicación de matrices. 

```
$ gcc main2.c funciones2.c -o programa2.out -lblas
$./programa2.out

Matriz1
matriz1[0][0]=0.00	matriz1[0][1]=1.50
matriz1[1][0]=4.00	matriz1[1][1]=-5.00
matriz1[2][0]=-1.00	matriz1[2][1]=2.50

Matriz2
matriz2[0][0]=1.00	matriz2[0][1]=0.00	matriz2[0][2]=0.00
matriz2[1][0]=0.00	matriz2[1][1]=-1.00	matriz2[1][2]=1.00

Matriz resultado
matriz_res[0][0]=0.00	matriz_res[0][1]=-1.50	matriz_res[0][2]=1.50
matriz_res[1][0]=4.00	matriz_res[1][1]=5.00	matriz_res[1][2]=-5.00
matriz_res[2][0]=-1.00	matriz_res[2][1]=-2.50	matriz_res[2][2]=2.50
```

---


#### e. Investiga sobre LAPACK, BLAS y ATLAS y la subrutina de Fortran dgemm y reporta sobre esta investigación que realizas. Es una investigación corta que contiene principalmente una descripción sobre los paquetes anteriores y la subrutina.



- **LAPACK:** (Linear Algebra Package) Es una librería estándar para 
cálculos de álgebra lineal. Tiene rutinas para resolver 
sistemas de ecuaciones lineales y mínimos cuadrados, problemas
de eigen valores y descomposición de valores singulares. 
También implementa la factorización de matriz asociada como 
LU, QR o la descomposición de Cholesky y Schur.
Las rutinas de este paquete aceptan matrices de valores reales y 
complejos de doble precisión. 


- **BLAS:** (Basic Linear Algebra Subprograms) Es una 
especificación que hace referencia a rutinas de bajo nivel 
para realizar operaciones de álgebra común, como:
suma de vectores, multiplicación escalar, producto 
punto, combinaciones lineales y multiplicación de 
matrices. 

- **ATLAS:** (Automatically Tuned Linear Algebra Software) Es una 
librería para álgebra lineal. Es similar a BLAS pero 
con la característica de ser *open source*.

- **Subrutina de Fortran dgemm:** La función `dgemm` es una 
sub rutina que pertenece al
paquete LAPACK cuyo propósito es realizar la operación 
de matrices `C` definida como:

$$
C := \alpha \cdot \texttt{op}( A ) \cdot \texttt{op}( B ) + \beta \cdot C
$$
donde 
$$
\texttt{op}( X) = X  \quad \text{o bien} \quad   \texttt{op}( X) = X^{T}
$$
y sean  $\alpha$ y $\beta$ escalares,  $A$, $B$ y $C$
matrices, $\texttt{op}(A)$ una matriz de dimensión $(m,k)$ y 
$\texttt{op}(B)$  una matriz de dimensión $(k,n)$. Entonces, en 
consecuencia $C$ es una matriz $(m,n)$


La función se define, 
```
dgemm_(&TRANSA, &TRANSB, &N, &M, &K, &ALPHA, *matriz2, &N, *matriz1, &K, &BETA, *matriz_resultado, &N);
```
donde $M$ es el número de renglones de $\texttt{op}(A)$ y de $C$. $N$ el número
de columnas de $\texttt{op}(B)$ y $C$. $K$ el número de columnas de 
$\texttt{op}(A)$ y renglones de $\texttt{op}(B)$.
Los parámetros `TRANSA` y `TRANSB` especifican transformaciones
de las matrices siguientes. 

$$
TRANSA = \text{N} \quad \text{entonces} \quad \texttt{op}(A) = A
\quad \text{y} \quad
TRANSA = \text{T} \quad \text{entonces} \quad \texttt{op}(A) = A^{T}
$$

Sea $ALPHA$ y $BETA$ son variables de los escalares  $\alpha$ y $\beta$
respectivamente. 


---

