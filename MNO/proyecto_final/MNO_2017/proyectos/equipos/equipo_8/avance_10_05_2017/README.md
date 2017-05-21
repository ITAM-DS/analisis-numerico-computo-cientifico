Avance 4
Walter Martínez Santana

Revisé el libro de Golub y Van Loan en lo referente al agoritmo por bloques para llevar a cabo la factorización Cholesky.
Encontré tres algoritmos uno por bloques recursivo, otro por bloques no recursivo y uno por bloques con  operaciones de outer product.
El primero, el recursivo,no es una opción viable para implementarlo en paralelo debido asu naturaleza recursiva, es decir, existen dependencias
entre las diversas llamadas recursivas.
El segundo,no recursivo, presenta dependencia entre etapas, además dellevar a cabo la factorización Cholesky normal de una submatriz (bloque), lo cual
no resuelve nuestra problemática inicial dependencia.
El tercero, prácticamente es muy parecido al algoritmo secuencial en cuanto a dependencias se refiere entre las operaciones.
Por otro lado, expone una forma de almacenar una matriz simétrica en un vector. Define dos formas en general, la forma "vec" y la forma "symvec".
Además introduce una nueva forma de operar con este tipo de almacenamiento. Define a los algoritmos anteriores, pero en una versiónque llaman "Packed", para tratar de aprovechar
la forma en que están almacenados los datos y aprovechar el flujo de datos dentro de la jerarquía de memoria e implementar operaciones que aprovechen el flujo de datos y maximizar
los caché hits
