## Avance_24_04_18


### Equipo:

Para esta entrega, una alta proporción del trabajo se llevó a cabo de forma colaborativa pues nos reunimos para trabajar en la implementación en C del Algorítmo de Descenso en Gradiente Estocástico secuencial. Lograr esta implementación es de alta importancia, pues es el precursor (la base) de los algorítmos que detallamos en el trabajo escrito, y cuya implementación en CUDA es nuestro objetivo final. Como te comentamos, Erick, tenemos un error que no nos permite avanzar en la implementación. En la sección del código detallamos las particularidades del problema y describimos nuestros intentos para solucionarlo


### Integrantes:

**Daniel Sharp**

Además de trabajar en equipo en la implementación del código, para esta semana agregué contenido al trabajo escrito en la sección de introducción. Detallé el algorítmo de Descenso en Gradiente e incluí una sección para explicar CUDA y sus utilidades, pues hemos decidido que nuestra implementación final se desarrollará en esta plataforma de GPGPU. También detalle la información del código trabajado en equipo, incluyendo la descripción de los errores que nos encontramos y los intentos para solucionarlos.

**Christian Challu**



Para este avance respondi la duda correspondiente a la seccion que redacte para el avance anterior (ver escrito). Redacte ademas una introduccion general sobre metodos de optimizacion al inicio del segundo capitulo. En ella se menciona los dos tipos de metodos generales: iterativos y analiticos. Por ultimo, investigue sobre la implementacion de los metodos con momento (ver bibliografia en escrito). Esta se realizara una vez que tengamos descenso estocastico funcionando.


**Elizabeth Solis**

Incorporé el detalle del programa de min_cuadrados_basico.c y algunas modificaciones en el programa.


El objetivo del programa min_cuadrados_basico.c es tener una interfaz interactiva con la finalidad de entender mejor el tema de mínimos cuadrados, en el cual dados unos datos (experimentales) se encontrará la relación entre la variable explicativa y la variable respuesta a través de un polinomio de grado n y minizando el error cuadrático. 


El programa tiene como inputs:

+ el número de datos 

+ los valores para la variable explicativa y la variable respuesta

+ el grado del polinomio que se desea ajustar


El resultado de programa es un sistema de ecuaciones a resolver y el sistema resuelto; así como la ecuación del polinomio del grado deseado ajustado por mínimos cuadrados. 

Dado que este programa tenía como finalidad objetivos didácticos no se buscó la comparación con el programa de descenso_gradiente_secuencial.c

En la carpeta `datos` se encuentran los datos de prueba de la semana pasada.  Finalmente, hice algunas modificaciones en el código para que el programa leyera un archivo txt sin necesidad de introducir los datos de forma interactiva en la terminal.

`datos.txt` es el archivo con los datos a ingresar en el programa con la siguiente estructura:

+ número de datos

+ orden del polinomio

+ valores de x1 y1 ... xn yn (separados por espacio y en ese orden)



### Nota:

Los avances en el trabajo escrito mencionados se encuentran en: 
https://www.sharelatex.com/read/kbgxbypyfjvk









