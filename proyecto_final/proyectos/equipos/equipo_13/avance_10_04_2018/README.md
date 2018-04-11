# Avances 10-04-2018

# Integrantes
- Alejandro Hernández 87806
- Federico Riveroll 105898
- Pablo Soria 111969

# Individual

Consideramos tres posibles alternativas para la implementación del cálculo del AUC:
- Utilizando sumas de Riemman, regla del punto medio o del trapezio.
- Urilizando el método de Simpson.
- Utilizando MCMC.

Cada uno de los integrantes procedió a investigar sobre cada una de las alternativas planteadas y su factibilidad de implementación, así como comenzar a analizar de qué forma podría desarrollarse dicha implementación.

- Alejandro Hernández

Busqué algunos ejemplos de paralelización en la siguiente [referencia](http://heather.cs.ucdavis.edu/~matloff/158/PLN/ParProcBook.pdf), para intentar comprender como se realizariá la paralelización en el caso puntual del cálculo de AUC y revisé las secciones relativas a OpenMP y a CUDA para ver qué plataforma podríamos usar para el desarrollo del proyecto. Asimismo, analicé el siguiente trabajo  [referencia](http://www.ece.utah.edu/~ece6340/LECTURES/Jan30/Numerical%20Integration.pdf) en el que se describen algunos métodos numéricos para calcular la integral. El primero es usando sumas de Riemman tanto por la derecha como por la izquierda, que en esencia es segmentar el dominio, formar rectángulos considerando la altura a partir del punto de la derecha o de la izquierda y sumarlos; el segundo, utilizando la regla de punto medio, que comprende básicamente la misma idea de Riemman, pero la altura se considera a partir del punto medio y la regla del trapecio en donde el área se aproxima segmentando en tapecios en lugar de rectángulos. 
En el trabajo [referencia](http://www.shodor.org/media/content//petascale/materials/UPModules/AreaUnderCurve/AUC_Module_Document_pdf.pdf) se incluye un algoritmo híbrido para el cálculo del AUC utilizando Riemman por la izquierda; es decir, una mezca de memoria distribuida y memoria compartida; sin embargo, indica que se puede ajustar a un algoritmo de memoria compartida asumiendo un proceso con multiples threads, o bien, a una versión con memoria distribuida asumiendo multiples procesos, cada uno con un thread. En esencia el pseudocódigo que incluyen realiza los siguientes pasos: 1) Calcular el ancho del dominio y ancho del rectángulo, 2) Calcular el número de rectangulos, 3) Calcular el límite izquierdo , 4) Para cada rectangulo paralelizado por thread, hacer: a) Calcular el valor x del lado izquierdo, b) Calcular la altura del rectángulo y c) Calcular el área del rectángulo; 5) Calcular la suma total del proceso y 6) Calcular la suma total global.



- Federico Riveroll

Leí la siguiente [referencia](http://genepi.med.utah.edu/~alun/teach/stats/week09.pdf), para determinar como se podría impementar el algoritmo utilizando caminatas aleatorias, en específico la integración vía MCMC. Considero que esta opción es particularmente interesante por que la paralelización hace mucho sentido. Se pueden realizar diversas caminatas aleatorias en paralelo ya que no depende una de otra y al final juntar todos los puntos y poder ver la distribución.

Es interesante particularmente por que las diversas caminatas no dependen la una de la otra y de esta forma la paralelización hace mucho sentido.


- Pablo Soria

Como parte de la investigación sobre el método de Simpson: En términos de integración numérica, una forma de aproximar una integral definida en un intervalo [a,b] podemos subdividir el intervalo y aproximar f  por medio de un polinomio de primer grado. El método utilizado por la regla de Simpson sigue la misma filosofía de aproximación pero lo hace aproximando f en el sub-intervalo por medio de un polinomio de 2° grado.
La implementación de forma paralela más sencilla es del estilo SIMD Single instruction multiple data que implica particionar el intervalo [a,b] en función de la cantidad de cores, realizar el cálculo de forma separada para cada core y finalmente sumar todas las partes dentro de uno mismo. Actualmente me encuentro consiguiendo el siguiente artículo científico.
Se ha localizado un artículo que parece implementar esta situación en CUDA actualmente me encuentro consiguiendo el artículo por medio de las bases de datos del ITAM, __I. W. A. Swardiana, T. Wirahman and R. Sadikin, "An Efficient Parallel Algorithm for Simpson Cumulative Integration on GPU," 2015 Third International Symposium on Computing and Networking (CANDAR), Sapporo, 2015, pp. 346-349.__



# Equipo
Comentamos sobre cuál de las tres alternativas resulta más viable de implementar; sin embargo, como no nos hemos decantado por alguna en particular, inicialmente estamos pensando implementar las tres para comparar su desempeño. Asimimsmo, tenemos planteado realizar la implementación en CUDA.

Finalmente, para estructurar los avances decidimos generar el siguiente cronograma para las primeras tres entregas:

- 10-04-2018: Entrega primer avance.

- 11-04-2018: Revisión del docker file que servirá para desarrollar el proyecto, o en su caso, levantar las instancias en AWS para iniciar la implementación cuanto antes.

- 12-04-2018: Revisión de investigación relativa a implementaciones más a detalle.

- 14-04-2018: Pruebas iniciales de implementación y revisión de alternativas.

- 17-04-2018: Entrega segundo avance.

- 20-04-2018: En caso de implementación exitosa de las tres alternativas, realizar comparativo de desempeño. En otro caso, buscar soluciones a problematica puntual.

- 22-04-2018: Revisión de algoritmos y fallas detectadas en el mismo.

- 24-04-2018: Entrega tercer avance.


