ITAM 
Resumen: Convex Optimization for Big Data
Uriel Miranda Miñon 
177508

El artículo revisado es una compilación sobre los avances para aprovechar las nuevas tecnologías aplicadas a la optimización convexa de algoritmos para Big Data, los cuales representan una gran parte del procesamiento para evitar cuellos de botella en el pipeline de los proyectos.

Con el avance de desarrollo de los algoritmos para resolver problemas de análisis de señales (que se traduce a la gran mayoría de problemas que se busca resolver con Big Data) se pudo trascender el tan conocido problema de mínimos cuadrados para dar paso a modelos estadísticos complejos que requieren de los beneficios del computo eficiente y resolución de problemas para obtener mínimos globales mediante el uso de geometría convexa por sus ventajas.

Big Data ha llamado la atención de las investigaciones y por tanto la optimización convexa se ha reinventado para explorar las ventajas y alcances que antes no eran medibles o aplicables por las limitaciones computacionales y la dispersión de las tecnologías. Entre las tecnologías que se pueden aprovechas se encuentra el cómputo distribuido y el hecho de que no se requiere un foco centrado en la precisión tanto como en la eficiencia y la posibilidad de procesar la información requerida.

En un repaso por la optimización convexa tenemos la formulación:

 
					Img.1

Donde f y g son funciones convexas y los pilares para Big Data son:
-	First-order methods: Se obtienen soluciones utilizando únicamente la información de primer orden , un ejemplo es el estimado en gradientes. Los algoritmos son con base en primitivos computacionales y son ideales para computo distribuido o paralelo.
-	Randomization: Permiten mejorar la escalabilidad de los modelos de primer orden ya que se pude controlar el comportamiento esperado. Las ideas principales incluyen actualizaciones parciales aleatorias de variables de optimización y reemplazar un gradiente determinista por una estimación de menor costo.
-	Parallel and distributed computation: Los métodos de primer orden son flexibles y por tanto se pueden mejorar y aumentar estos métodos para mejores niveles de escalabilidad pro medio de de algoritmos síncronos paralelos con comunicación centralizada par algoritmos de sincronizados con comunicación descentralizada de gran escalabilidad.

En el campo de los métodos de primer orden el problema de Big Data tenemos que las observaciones lineales tienen la forma:

 
Img. 2

La forma de resolver este problema con mínimos cuadrados es:
 
Img. 3

Se generan también soluciones con regularización como Lasso:
 
Img. 4

Donde la regularización permite disminuir la varianza y tener un modelo mas generalizado, las ventajas son diversas y dependen en gran medida de utilizar ubn valor lambda correcto.

Se puede observar las bondades de resolver con métodos de primer orden versus la aplicación clásica de resolución con el método del punto interior dado que se puede converger sin importar el tamaño de la matriz. Se pueden mejorar aún mas si se utilizan métodos estocásticos para aproximar. 

# Métodos de Primer orden para Optimización convexa (Smooth/Non-Smooth)

Para el caso de objetivos Smooth se utilizan métodos de bajas iteraciones y bajo costo por iteraciones. El modelo de gradiente es el siguiente:

 
Img. 5

Donde k es el número de iteraciones y alfa es el tamaño de paso. Haciendo ciertas asunciones acerca de la función podemos analizar el número de iteraciones necesarias para alcanzar el error esperado. 

En esta sección se describe el algoritmo Nesterov para gradiente acelerado:

 Img. 6

Es la mejor estimación del error del peor escenario, muchas funciones contienen estructuras adicionales probabilísticas que provern beneficios adicionales.

Es importante mencionar que en el documento se menciona que podemos transformar cualquier problema convexo en un problema fuertemente conexo simplemente por incluir un elemento de regularización al cuadrado.

 
Img. 7

Es la representación de ridge que provén beneficios estadísticos adicionales. Cuando f es doblemente diferenciable una condición suficiente para convexidad fuerte es que el eigenvalor de la Hessiana esté contenido por mu para toda x. 

Se menciona que para ls problemas fuertemente convexos con gradiente Lipschitz como ridge el método geométrico converge a un minimizador único cuando el paso es de tamaño 1/L:

 
Img. 8

Para el caso del problema compuesto canónico están lejos de ser problemas de optimización convexa non-Smooth. Son extensiones naturales del método del gradiente. Para este caso se explica el algoritmo acelerado proximal del gradiente.
	 
Img. 9 

También se revisa el caso de objetivos próximos que son aplicables a problemas mas reales, en los cuales se utilizan métodos de multiplicadores (ADMM) mediante el uso de Lagrangiano y descomposición dual.

 
Img. 10

Una parte importante es el uso de la aleatoriedad para escalar los problemas de Big Data.  Un ejemplo es el uso en el problema de PageRank de nodos en un grafo. Asumiendo que los nodos mas importantes son los que tienen mas conexiones el problema, se puede traducir a encontrar los vectores singulares de la matríz estocástica.

  
Img. 11

Para resolver este problema evitando la cantidad de multiplicaciones de matriz vector se puede utilizar un algoritmo de descenso coordinado para minimizar:
 
Img. 12

En otro apartado de elementos importantes para resolver estos problemas está el uso de métodos de gradiente estocástico en el cual se utilizan batches para poder realizar un descenso sin la necesidad de ocupar el total de datos para cada iteración. La importancia radica en que la selección de los batches sea aleatoria para evitar sesgos.

 
Img. 13

Las operaciones lilneales simples como descomposición en valores singulares o Cholesky pueden ser causa de cuellos de botella debido a la dependencia super lineal de las dimensiones.

La idea de aleatorizar trata de aproximar M _ Q(QTM) con Q en los reales pxr. Se describen algoritmos como el de aproximación de rango bajo aleatorio:
 
Img. 14

Operadores de funciones al utilizar métodos aleatorios se puede acelerar el computo de la proximidad de operadores de funciones que dependen de valores espectrales de la matriz; la idea también funciona para obtener estimaciones  gradientes sin restricciones para matrices y se puede utilizar para modelar funciones objetivo para aproximar buscando iteraciones menos costosas con métodos de primer orden.

En el caso de cómputo en paralelo y distribuido gracias a la ley de moore ha sido posible incrementar la capacidad de los procesadores y la creación de nuevos elementos como las GPU para realizar cómputo en paralelo.
Las limitaciones con respecto a los métodos de primer orden para la paralelizarían son la comunicación y la sincronización ya que juegan un papel importante en la correcta implantación.

En resumen los nuevos descubrimientos y aplicaciones se deben en gran medida a los elementos disponibles actualmente, ya sea grandes cantidades de datos así como tecnología y capacidad de cómputo. Los nuevos paradigmas de la programación presentan una oportunidad de actualizar los métodos de optimización convexa  y poder utilizarlos de mejor manera.


