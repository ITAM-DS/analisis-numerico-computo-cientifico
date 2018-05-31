## Implementación de Descenso en Gradiente Estocástico Secuencial  

Ejemplo de Regresión Lineal utilizando los datos de Boston Housing  

### Contenido
Esta carpeta contiene el código de la implementación de descenso en gradiente estocástico en modo secuencial.  
Para compilar el código se requieren los siguientes archivos:  
  
* definiciones.h  
  
* funciones.c  
  
* SGD_secuencial.c  
  
  Los datos utilizados y su limpieza funcionan de la misma manera que para el Descenso en Gradiente. Para encontrar su descripción se puede acceder a la carpeta de la entrega pasada o en esta [liga](../avance_17_04_18/codigo/README.md)  

### Compilado y Ejecución  
  
De nuevo, todos los documentos necesarios para ejecutar el programa se encuentran en el repositorio paralelo, [aquí](https://github.com/lizsolisd/optimizacion_convexa_minimos_cuadrados/tree/master/codigo/avance_24_04_18).  
  
Para compilar el programa se ejecuta la siguiente instrucción en la consola:  
  
* gcc -Wall SGD_secuencial.c funciones.c -o programa.out -lblas -lm

La ejecucución del programa se hace de la siguiente forma:  

* ./programa.out <renglones_entrenamiento> <columnas_entrenamiento> <renglones_validación> <tamano_de_batch> <iteraciones> <-tasa_aprendizaje> 
  
Desafortunadamente tenemos un problema en el código que no hemos podido resolver exitosamente. El problema se presenta cuando se busca inicializar la matriz de batch, a través de la siguiente función. Está función se encuentra dentro del archivo 'funciones.c'.  

```
void inicializa_batch(arreglo_2d_T b, arreglo_2d_T X, arreglo_1d_T y_b, arreglo_1d_T y){
	int m_b = renglones(b);
	int m = renglones(X);
	int n = columnas(b);
	int r;
	for(i=0; i<m_b; i++){ // Iteramos hasta el tamaño de batch
		r = rand() % m; // generamos números aleatorios entre 0 y el número de renglones de X para obtener los indices aleatorios del batch
		
    // Esta intrucción funciona correctamente
		entrada_vector(y_b,i)=entrada_vector(y, r);
		for(j=0; j<n; j++){
		
		// Creemos que en esta operación es donde se genera el error. Si imprimimos las entradas dentro del for si tienen el valor correcto, pero fuera del for ya no. Solo se tiene un 1 (el sesgo) en la primera entrada de cada renglón y el resto son ceros.
			entrada(b,i,j) = entrada(X,r,j);
		}
	}
}
```  

Ejemplo de ejecución con este error (Aunque en realidad sucede en todas):  
  
* ./programa.out 222 14 111 8 1 -0.02  

Ejemplo del error:  
matriz[0][0]=1.00000	matriz[0][1]=0.00000	matriz[0][2]=0.00000	matriz[0][3]=0.00000	matriz[0][4]=0.00000	matriz[0][5]=0.00000	matriz[0][6]=0.00000	matriz[0][7]=0.00000	matriz[0][8]=0.00000	matriz[0][9]=0.00000	matriz[0][10]=0.00000	matriz[0][11]=0.00000	matriz[0][12]=0.00000	matriz[0][13]=0.00000
matriz[1][0]=1.00000	matriz[1][1]=0.00000	matriz[1][2]=0.00000	matriz[1][3]=0.00000	matriz[1][4]=0.00000	matriz[1][5]=0.00000	matriz[1][6]=0.00000	matriz[1][7]=0.00000	matriz[1][8]=0.00000	matriz[1][9]=0.00000	matriz[1][10]=0.00000	matriz[1][11]=0.00000	matriz[1][12]=0.00000	matriz[1][13]=0.00000
matriz[2][0]=1.00000	matriz[2][1]=0.00000	matriz[2][2]=0.00000	matriz[2][3]=0.00000	matriz[2][4]=0.00000	matriz[2][5]=0.00000	matriz[2][6]=0.00000	matriz[2][7]=0.00000	matriz[2][8]=0.00000	matriz[2][9]=0.00000	matriz[2][10]=0.00000	matriz[2][11]=0.00000	matriz[2][12]=0.00000	matriz[2][13]=0.00000


Pensando que quizás la instrucción
```
entrada(b,i,j) = entrada(X,r,j);
```
era la que producía problemas (aunque es prácticamente equivalente a la del vector de y's, pero esa no genera problema), intentamos modificar la función a la siguiente, al crear un vector temporal donde se almacenaran las observaciones para el batch y luego copiarlas con la función memcpy, pero tampoco fue efectivo este método.  

```
void inicializa_batch(arreglo_2d_T b, arreglo_2d_T X, arreglo_1d_T y_b, arreglo_1d_T y){
	int m_b = renglones(b);
	int m = renglones(X);
	int n = columnas(b);
	double *temp = malloc((m_b*n)*(sizeof(double)));
	int r;
	for(i=0; i<m_b; i++){
		r = rand() % m;
		entrada_vector(y_b,i)=entrada_vector(y, r);
		for(j=0; j<n; j++){

			stemp[j*m+i] = entrada(X,r,j);
		}
		printf("Entrada x[%d][%d] = %f\n", r, 1,entrada(X,r,1));
		printf("Entrada b[%d][%d] = %f\n", i, 1,entrada(b,i,1));
	}
	memcpy(entradas(b),temp, (m_b*n)*(sizeof(double)));
	free(temp);
}
```

Ejecutando el código inicial con la siguiente instrucción:  
  
* ./programa.out 222 14 111 16 5 -0.02

Obtenemos el siguiente error:
```
*** Error in `./programa.out': free(): invalid next size (normal): 0x00000000007a3e60 ***

```  

Interpretamos que sería un error de asigación de memoria, pero verificamos que todos los 'objetos' tuvieran asignada la cantidad correcta de memoria y no encontramos el error.  

Pasos siguientes:  

* Aunque la probabilidad por lo general será baja, debemos de adaptar el algoritmo para eliminar la probabilidad que al inicializar el batch elija la misma observación más de una vez.  

* Investigar e implementar el funcionamiento de CUDA y resolver como se deben de adaptar los algoritmos secuenciales para ser ejecutados en paralelo.  