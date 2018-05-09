## Avance_08_05_18


**Cristian**  
Implementé un método de búsqueda en grid para encontrar el mejor parámetro de 'learning rate' en cada uno de los modelos. Esto para hacerlos comparables entre ellos en esta etapa y en posteriores. Estos generan una tabla 'reporte' al final de su ejecución para poder capturar los resultados.

**Daniel**  
Para esta entrega implementé el algorítmo de descenso en gradiente que teníamos para su ejecución en CUDA. Utilicé la imagen nvidia/cuda de Docker para tener el toolkit de CUDA y además, para facilitar la adaptación del código que teníamos, realicé la implementación con la librería de cuBLAS. Dos referencias de gran utilidad fueron [la documentación oficial](https://docs.nvidia.com/cuda/cublas/index.html) y un [libro](https://developer.nvidia.com/sites/default/files/akamai/cuda/files/Misc/mygpu.pdf) de ejemplos desarrollado por NVIDIA. Los resultados de la ejecución se muestran en la carpeta de código.  

**Elizabeth**  
Realicé algunas mejoras para la obtención y preprocesamiento de los datos de *flights* como la descarga automática de los datos, instalación o verificación de paquetes necesarios. Además dado que deseamos obtener los mejores parámetros en cada algoritmo, consideramos que una buena manera de notarlo sería mediante una visualización gráfica para lo cual modifiqué los archivos de los algoritmos en secuencial de sgd.c que implementaron mis compañeros y en lugra de imprimir los datos en la consola se guardarán los datos con los errores y un resumen de learning rate y loss y fueran leídos por un script de R y graficados. Dicha gráfica se guarda como png.

## Trabajo escrito

Los avances en el trabajo escrito se encuentran en: 
https://www.sharelatex.com/read/kbgxbypyfjvk


