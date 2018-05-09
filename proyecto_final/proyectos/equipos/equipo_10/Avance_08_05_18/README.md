**Abraham:** 
`instalación de cuda versión 9.1 LOCAL para compilar el programa svd.cu, existe un error a la hora de ejecutar dicho programa para obtener las matrices U,V.T y d_s para la descomposición, el error que muestra es : GPUassert: unknown error Utilities.cu 37, el detalle de ejcución se puede ver en esta imagen.` 
[Ejecucion] (https://drive.google.com/open?id=1-QiBuk11H_ZwF_7gMZWzC30Q8CI_ineU).
`El error viene de de uno de los archivos de dependencias que es Utilities.cu donde se define la función gpuAssert  la cual se explica en esta liga` [gpuAssert] (https://stackoverflow.com/questions/14038589/what-is-the-canonical-way-to-check-for-errors-using-the-cuda-runtime-api) `que es una función que verifica si hay errores en el código de la API runtime, si existe un error se envía un mensaje de texto que describe el error y la línea donde ocurrió, ene este caso parece ser en archivo Utilities.cu ene esta linea "extern "C" void gpuErrchk(cudaError_t ans) { gpuAssert((ans), __FILE__, __LINE__); }", todo se esta ejecutando a nivel local.`  


**Roberto:**

`Se profundizó en el código svd.cu y se elaboró un reporte del proceso de cómputo para realizar la descomposición de valores singulares en CUDA y como se interactúa entre el CPU y la GPU. El reporte se puede ver` [aquí](https://drive.google.com/open?id=1DQtzUqefoYp6oyAw3vjYBY7O5bBp3z62)

`Por otra parte, se buscaron ejemplos de implementación de códigos de CUDA en AWS y se encontró el siguiente` [video]( https://www.youtube.com/watch?v=dov5IUfJlkc)

`En el vídeo se ve como se configura una imagen a partir de una búsqueda de la palabra “nvidia” en AWS Marketplace, y lo más importante, se elige una instancia de tipo “g2.2xlarge” para realizar el demo.`


**Rodrigo;**

`Se continuó con le trabajo escrito, desarrollando la parte de la descomposción SVD y los pasos a seguir para poder entender mejor como se realiza de manera matemática este tipo de descomposicíon. En el trabajo escrito también se puede visualizar a grandes rasgos el algoritmo "one sided" Jacobi. Conforme vayamos haciendo progreso en la programación del mismo, continuaré profunidzando este tema para poder explicar de manera más detallada como lo hicimos. También se anexó una referencia a los algoritmos que hemos encontrado hasta el momento de cuSolver, de esta manera, una vez que desarrollemos la implementación podremos detallar el proceso que pasamos y la estructura de nuestro algoritmo.`


**Equipo:** 
`Avanzamos en la documentación del proyecto y estamos probando la ejecución del código svd.cu aunque con algunos problemas, el objetivo de usar ese código(original y/o modificado) es que se haga la descomposición sobre la matriz de movilens, estamos investigando sobre el error del programa svd.cu.`  

