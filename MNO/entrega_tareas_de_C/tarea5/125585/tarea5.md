# Tarea 5
## 125585

Al ejecutar programa.out se imprimen tres matrices, la tercera es el resultado de la multiplicación de las otras dos matrices.     
      
a) Investiga por qué se usan "" en la línea que tiene include en main.c y en funciones.c en lugar de usar < >.

##### Cuando se utilizan las comillas se le da la instrucción al compilador de primero buscar este programa en el mismo directorio y si no lo encuentra pasa a buscar en el resto. En el caso de hacerlo con <> se busca en todos los directorios que se han llamado. (Usualmente se usa para indicar que un archivo.h se desarrollo por el programador)

b) Investiga el uso de static en la definición de variables externas de funciones.c.

##### Una variable static solo es conocida dentro de la función en la que es declarada o dentro del "ambiente" de las funciones del archivo en el que es declarada mientras que una variable extern es conocida para todas las funciones del programa no solo para las que pertenecen al archivo en el que es declarada. 

c) Modifica el archivo funciones.c para que alojes e inicialices a las matrices matriz1, matriz2 y matriz_resultado con malloc y apuntadores. Modifica main.c para que llame a una función dentro del archivo funciones.c que inicialice y aloje a las matrices anteriores y llame a otra función para que las desaloje una vez hecha la multiplicación (usa free):

#### Respuesta en código funciones_respuesta.c

d)Compara tu resultado usando la subrutina de Fortran dgemm y los siguientes archivos definiciones2.h, main2.c, funciones2.c:

####La respuesta se encuentra en funciones_2.c y  el output es el mismo pero me cuesta trabajo trabajar sobre los archivos proporcionados porque yo había encontrado otra solución utilizando doble apuntador y no un arreglo de apuntadores. Entonces tuve que hacer algunos cambios para que fuera posible compilar el programa sin errores. Anexo los .txt con los outputs. 


Investiga sobre LAPACK, BLAS y ATLAS y la subrutina de Fortran dgemm y reporta sobre esta investigación que realizas. Es una investigación corta que contiene principalmente una descripción sobre los paquetes anteriores y la subrutina.

#####LAPACK Linear Algebra Package
Es una librería que se utiliza para algebra lineal, hace cosas como resolver sistemas de ecuaciones, encuentra eigenvalores y algunas factorizaciones como la LU, QR. 

#####BLAS Basic Linear Algebra Subprograms
Es una "especificación" de algebra lineal que se utiliza para cosas más sencillas que LAPACK como suma de vectores, multiplicación por escales y cosas por el estilo. 

#####ATLAS Automatically Tuned Linear Algebra Software 
Es una librería que provee de una implementación Open source de BLAS ademas de algunas funciones adicionales provenientes de LAPACK. 

#####DGEMM 


