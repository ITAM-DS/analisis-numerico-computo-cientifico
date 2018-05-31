
## Descripción de la ejecución del código.

##__Descripción General__

El algoritmo del método está programado en C++ bajo el paradigma de Programación Orientada a Objetos. A partir de un archivo de texto que contiene la línea de producción, las duraciones de las actividades y sus precedencias, regresa todas las matrices que denotan las posibles soluciones óptimas. Específicamente, el kernel de CUDA, mediante el cual se lleva a cabo el mezclador en paralelo está progamado en C.

### __Procesamiento de las Entradas__

A partir de la lectura del input, se crea una instancia del grafo de actividades, la línea de producción y una matriz con relaciones de precedencia.
Luego se obtiene el tiempo del ciclo ideal, dividiendo el tiempo total de ejecución de las actividades entre el número de estaciones deseadas. Se calcula el máximo común divisor para las duraciones de las actividades. 

### __Proceso de Simplificación__

Mediante el objeto Simplifier, se eliminan las restricciones redundantes tomando en cuenta los tiempos antecedentes y los consecuentes de cada una de las actividades. Este objeto regresa otro objeto, denominado Allcandidatestations, que contiene para cada estación sus posibles actividades candidatas. Si existe una estación sin actividades o actividades sin estación, se incrementa el ciclo ideal con el máximo común divisor y se repite el Simplifier.

### __Generador de Restricciones__

El problema tiene tres tipos de restricciones algebraicas. El objeto Restrictiongenerator , a partir de Allcandidatestations, se encarga de generar las restricciones de duración, precedencia y unicidad. Estas restricciones se empaquetan en un objeto llamado Model, que las guarda en memoria.
Desde Model, se convierten las restricciones algebraicas mencionadas anteriormente en restricciones booleanas. A través del método Getnegation, se obtienen las restricciones negadas. No es necesario negar las restricciones de unicidad.

### __Mezclador Binario Secuencial__

El conjunto de restricciones negadas se representa en tablas binarias las cuales se procesan a través de un objeto llamado Binarymixer. Este objeto, a partir de un proceso que realiza iteraciones sobre las tablas binarias obtenidas en las restricciones, genera un vector de matrices con las asignaciones óptimas para el balanceo de línea.
El proceso ocurre de la siguiente forma: Primero, se instancia un vector de tablas binarias, el cual se denomina vector de soluciones temporales. Se inserta la tabla binaria correspondiente a la primera restricción de duración en el mismo. A partir de un ciclo for, el vector de soluciones temporales realiza la operación booleana ‘and’ con cada uno de las tablas generadas de las restricciones de duración. Antes de insertar la tabla como asignación posible al vector de soluciones temporales, se verifica que ésta sea válida y no haya sido insertada previamente en el vector. Este último proceso se lleva a cabo mediante una tabla hash. Posteriormente se toma el vector de soluciones temporales para repetir el proceso con las restricciones de precedencia y las de unicidad. Una vez que este proceso termina, se verifica la cantidad de tablas en el vector de soluciones temporales. Si no existe al menos una solución, se le incrementa el máximo común divisor al ciclo ideal y se repite el algoritmo. Por otra parte, si el vector de soluciones temporales contiene tablas, estas últimas constituyen las soluciones óptimas.
Vale la pena mencionar que conforme se van añadiendo las restricciones, el número de tablas crece y luego se reduce al incluir más restricciones. 

### __Mezclador Binario en Paralelo__
Primero se ejecuta la función Runtest, la cual instancia apuntadores de cuatro gigas para las restricciones booleanas y 1GB para el vector de soluciones temporales, estos apuntadores son copiados a la GPU. Se calculan los threads necesarios, los cuales son tantos como tablas existan en el vector de soluciones temporales. Previo a la invocación del kernel, se calcula el tamaño posible que se puede asignar en el sistema de la GPU tratando de asignar el mínimo entre 4GB/entre el número de tablas o 500 MB. Si no se puede asignar el espacio, se reduce en un MB y se vuelve a intentar hasta que se pueda asignar. A partir del tamaño que quedó sin alocar del vector de soluciones temporales se lleva a cabo un sistema de batches mediante el cual se invoca al kernel para que procese tantos threads/tablas del batch en cuestión. Este proceso, al igual que en el método secuencial, se lleva a cabo con todas las tablas de los 3 tipos de restricciones booleanas. La verificación de que las tablas adosadas al vector de soluciones temporales sean válidas se realiza dentro del device/gpu, no así, la verificación de que éstas no estén duplicadas, proceso que se lleva a cabo en el host. Una vez terminado el proceso, el flujo es análogo al método secuencial. En caso de que el vector de soluciones temporales contenga tablas, estas constituyen las asignaciones óptimas. De otra forma, se incrementa el máximo común divisor y se repite el proceso.
Éste se encarga de procesar en paralelo las tablas de restricciones. Para problemas grandes, si el GPU se queda sin memoria, el resultado temporal se copia al Host para liberar memoria y se prosigue con el proceso. 