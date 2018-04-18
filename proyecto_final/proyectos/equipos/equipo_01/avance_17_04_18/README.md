### Equipo 1:

* Daniel Sharp

* Christian Challu

* Elizabeth Solis

## Avance_17_04_18:

- Elizabeth:

Se realizó una investigación de mínimos cuadrados con la finalidad de dar un *overview* del proyecto y una base teórica del problema, lo cual fue plasamado en el escrito. Las referencias bibliográficas han sido incorporadas en el escrito. 
Para un mejor entendimiento del problema de mínimos cuadrados fue implementado en C (la idea es que sea lo más didáctico y explícito posible), fue ejecutado con distintos valores y se encuentra en la carpeta de `código`. 

- Daniel:

Con base en la investigación desarrollada la semana pasada, revisando los materiales de la clase y de BLAS, implementé el código en C para la ejecución del algorítmo de descenso en gradiente mencionado en las notas. Para poder probar la correcta ejecución de este, se utilizaron los datos de Boston Housing. Las particularidades del programa se especifican todas dentro de la carpeta de `código` para el avance de esta semana. Dado que uno de los objetivos de esta implementación fue una lograr una mayor familiaridad con la biblioteca y funciones de BLAS, se implementó el modelo `básico` de descenso en gradiente. Será en las semanas posteriores que trabajaremos con modelos más sofisticados.


 - Cristian:

Decidimos incluir otros métodos de búsqueda de línea aparte de SGD, como métodos con probabilidades adaptativas y métodos de momentos adaptativos. Estos últimos incluyen a los algoritmos más utilizados en la actualidad, sobre todo en ML. Para este avance investigué sobre los distintos métodos de búsqueda de línea estocásticos para implementarlos. En particular, investigué sobre métodos con probabilidades adaptativas (AP-SGD en el escrito), ADAGrad, ADAM y AMSGrad. Luego de esta investigación redacté la sección “Métodos de optimización” en el escrito, que incluye una sección de notación, el algoritmo 1 (Métodos Generales de Búsqueda de Línea Estocásticos) y como se especifican todos los otros métodos a partir de este algoritmo general. La bibliografia consultada se encuentra en la seccion de Bibliografia en el escrito. Se intentará en un comienzo implementar SGD y ADAM, para luego pasar a AP-SGD y AMSGrad.
