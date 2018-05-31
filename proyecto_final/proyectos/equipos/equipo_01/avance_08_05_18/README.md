## Avance_08_05_18

Los comentarios de Erick sobre la entrega del 2 de mayo se atenderán en la siguiente semana. (Monitorear la norma del gradiente, usar while en vez de for)

**Cristian**  
Para este avance implementé un método de búsqueda en grid para encontrar el mejor parámetro de 'learning rate' para sgd, adam y amsgrad. Esto es necesario ya que cada algoritmo puede tener hiperparametros optimos distintos. Estos programas se basan en el codigo desarrollado anteriormente. Se ejecuta cada algoritmo de optimizacion con 10 learning rates distintas y se reporta el train loss alcanzado en la iteracion 100. Por ultimo, estos generan una tabla 'reporte' al final de su ejecución. Estos reportes se encuentran en la carpeta del código bajo el nombre "\<modelo>_grid.txt".

**Daniel**  
Para esta entrega implementé el algorítmo de descenso en gradiente que teníamos para su ejecución en CUDA. Utilicé la imagen nvidia/cuda de Docker para tener el toolkit de CUDA y además, para facilitar la adaptación del código que teníamos, realicé la implementación con la librería de cuBLAS. Dos referencias de gran utilidad fueron [la documentación oficial](https://docs.nvidia.com/cuda/cublas/index.html) y un [libro](https://developer.nvidia.com/sites/default/files/akamai/cuda/files/Misc/mygpu.pdf) de ejemplos desarrollado por NVIDIA. Los resultados de la ejecución se muestran en la carpeta de código.   
La preguna específica del unified memory era si se podía utilizar en C. Intenté hacerlo, pero para memoria unificada tiene que tener terminación .cu (o eso entendí)
 y por default NVCC lo intenta compilar como C++ lo que genera otros errores en el código. Al final lo logré implementar con el método 'normal' o 'tradicional' de CUDA. El atractivo de la memoria unificada es que su programación es mucho más sucinta y sencilla.


**Elizabeth**  
Realicé algunas mejoras para la obtención y preprocesamiento de los datos de *flights* como la descarga automática de los datos, instalación o verificación de paquetes necesarios. Además dado que deseamos obtener los mejores parámetros en cada algoritmo, consideramos que una buena manera de notarlo sería mediante una visualización gráfica para lo cual implementamos un script en R que leyera los resultados, graficara y guardara la imagen. Si esto resulta util será implementado para el resto de los algoritmos.

## Trabajo escrito

Los avances en el trabajo escrito se encuentran en: 
https://www.sharelatex.com/read/kbgxbypyfjvk


