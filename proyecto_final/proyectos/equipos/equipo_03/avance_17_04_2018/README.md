# Avance 17/04/2018

## Integrantes:

* Diego Alejandro Estrada Rivera    

* Rafael Larrazolo de la Cruz       

* Victor Quintero Mármol González   

## Título del proyecto: Factorización de Matriz usando factorización QR

### Individual

Diego: 

Para iniciar, y con el fin de coordinarme mejor con mis compañeros de equipo, revisé los métodos de Householder y Givens para la factorización QR, enfocándome en las varias de las referencias ya provistas por ellos en el primer avance. Para el método Householder revisé la [implementación en R](https://rpubs.com/aaronsc32/qr-decomposition-householder) que nos compartio Victor la semana pasada y también realicé los ejercicios a mano. En cuanto al método de rotaciones de Givens, leí las [notas](https://www.dropbox.com/s/q096hjt7ah1nd4q/Givens.pdf?dl=0) que nos compartio Rafael esta semana, en cuyas conclusiones deja muy en claro las ventajas de escoger este método sobre Householder, ya que su paralelización suena más práctica y natural de realizar.  

Habiendo leído ya los dos métodos que me faltaban para realizar factorización QR, podría considerar que por temas de estabilidad y quizá facilidad de implementación, convendría más enfocarnos en rotaciones de Givens, pero me gutaría en los siguientes días explorar la implementación en C de forma secuencial de estos tres métodos (he visto muchas implementaciones hechas en MATLAB en los artículos de wikipedia que me parece serían fáciles de traducir en C), a fin de tener más claridad y empezar a explorar ideas acerca de como podríamos paralelizar cualquiera de los tres métodos. 

Para finalizar, leí la referencia proporcionada por el maestro sobre la [factorización QR implementada en MapReduce](http://www.cs.cornell.edu/~arb/papers/mrtsqr-bigdata2013.pdf). En este paper se habla más especificamente acerca de la factorización QR para matrices "Tall and snkinny, TS" las cuales tienen la cualidad de tener muchas más filas que columnas, m >> n. A fin de comparar métricas objetivo con el método "Directo" el cual se propone; se analizan otras implementaciones en MapReduce, como Cholesky y un método "Indirecto", así como métodos para refinar Q iterativamente. Se concluye que el método directo es la mejor opción en cuando a estabilidad númerica, ya que no sacrifica tanta velocidad cuando se compara con lo otros métodos más inestables. Todas las implementaciones vistas son bien desarroladas y con la ayuda de diagramas quedan bastante claras, incluso se agrega una liga a la implementación del método "Directo", sin embargo, ocuparíamos revisar ampliamente todo el tema referente a MapReduce, ya que nuestra experiencia usándolo es poca en este punto.  

Como comenté anteriormente, para el próximo avance, me gustaría empezar a implementar alguno de estos algoritmos de forma secuencial en C, a fin de ayudarme a idear formas en que podríamos paralelizarlos dado el conocimiento y referencias con que ya contamos.

Rafael:

En el avance pasado había revisado el algoritmo de las rotaciones de Givens, por lo que ahora me dediqué a estudiar lo que mis compañeros investigaron previamente. Primeramente leí el [paper](https://www.dropbox.com/s/dpdgawz2berehb9/Parallel%20Implementation%20of%20Classical%20Gram-SchmidtOrthogonalization%20on%20CUDA%20Graphics%20Cards.pdf?dl=0) que Diego nos recomendó sobre el proceso de Gram-Schmidt implementado en parelelo utilizando CUDA; por otro lado, profundizando más en este tema leí esta [referencia](http://homepage.divms.uiowa.edu/~oliveira/PAPERS/mgs-journal.pdf) donde aprendí que el proceso de Gram-Schmidt tiene una variante llamada *Modified Gram-Schmidt* el cual es más conveniente que el método clásico por tener mayor estabilidad numérica y este procedimiento tiene dos enfoques (orientado por filas o por columnas).	

En lo que respecta a Householder, hice el [ejemplo](https://rpubs.com/aaronsc32/qr-decomposition-householder) que recomendó Víctor la semana pasada para realizar a mano una factorización bajo este método y entender cómo funciona el algoritmo. También para este tema encontré esta [presentación](http://www.ece.neu.edu/groups/nucar/GPGPU/GPGPU-2/Kerr.pdf) donde también explican Householder y un algoritmo alternativo llamado *Block Householder* e incluso presentan un ejemplo en CUDA y el `performance` obtenido en varias pruebas realizadas. Por lo que leí, este algoritmo es menos sensible a error de redondeo que Gram-Schmidt, además de que es el más usado para realizar la factorización QR en varios programas.

Finalmente, compartí estas [notas](https://www.dropbox.com/s/q096hjt7ah1nd4q/Givens.pdf?dl=0) con mis compañeros de equipo para que tuvieran referencia sobre el algoritmo usado para las rotaciones de Givens (del cual investigué en mi avance anterior), además de que incluye un ejemplo de una matriz a la que le aplican la factorización QR usando Givens y Householder. Aquí mencionan a grandes rasgos que Givens es preferible realizarlo en paralelo y que es más eficiente cuando la matriz a factorizar contiene muchos ceros. 

También leí la [referencia](https://arxiv.org/pdf/1301.1071.pdf) que nos recomendó Erick sobre la factorización QR para matrices *altas y delgadas* en arquitecturas MapReduce donde se utilizan dos funciones `map` y una función `reduce`. 

Para el próximo avance quiero centrarme en documentar los algoritmos en paralelo utilizados para la factorización QR

Victor:

Para este segundo avance leí los métodos que revisaron mis compañeros para la primera revisión y también quise leer un poco más sobre paralelización que fue algo que no revisé para el avance anterior. Para esto último revise el [repositorio del equipo 2 del 2017](https://www.dropbox.com/s/q096hjt7ah1nd4q/Givens.pdf?dl=0) que nos recomendó Erick, ahí encontré un [paper](http://www.netlib.org/utk/people/JackDongarra/PAPERS/206_2009_A%20Class-of-Parallel-Tiled-Linear-Algebra-Algorithms-for-Multicore-Architectures.pdf) en las referencias en el cual se presentan algoritmos para factorización Cholesky, LU y QR en paralelo. También encontré ahí mismo otro [documento](https://drive.google.com/file/d/0BxMtevFKwTW_OW5wZVF5dFdiV2c/view) donde se habla únicamente de paralelización para factorización QR.

Para la parte de los otros métodos, comencé leyendo un [paper](https://www.dropbox.com/s/dpdgawz2berehb9/Parallel%20Implementation%20of%20Classical%20Gram-SchmidtOrthogonalization%20on%20CUDA%20Graphics%20Cards.pdf?dl=0) sobre una implementación en paralelo del proceso de Gram-Schmidt en CUDA, el cuál Diego nos recomendó. Posteriormente leí las [notas](https://www.dropbox.com/s/q096hjt7ah1nd4q/Givens.pdf?dl=0) que Rafael nos compartió para el método de rotaciones de Givens, aquí se concluye que este método es mejor que Householder para ralizar y paralelizar factorización QR, a pesar de ser este último el más popular.

Además leí la [referencia QR en Map Reduce](https://arxiv.org/pdf/1301.1071.pdf) que Erick nos recomendó en la primera revisión. Aquí se enfocan en matrices *"tall-and-skinny"* y se hace una comparación con el método de Householder y factorización de Cholesky. Se concluye que si se quiere un método estable numéricamente, el método directo (propuesto) es la mejor opción. Fue un enfoque interesante aunque me preocupa que mi base en MapReduce no es muy fuerte, por lo que no estoy seguro que quiera un enfoque de MapReduce para el proyecto.

Como siguiente avance me gustaría intenar una pequeña implementación en C para empezar a ver las dificulatades y así documentarme mejor ya en temas de programación.


### Equipo

Para este avance decidimos intercambiar entre los miembros del equipo lo que habíamos leído/investigado en el avance pasado con el fin de que los tres estuviéramos en sintonía y que entendiéramos los algoritmos de Gram-Schmidt, Householder Reflections y Givens Rotations. También nos pusimos de acuerdo con el equipo 9, que igualmente escogió QR como proyecto final, para no tener el mismo enfoque.
De igual modo, los tres revisamos la referencia de QR en MapReduce que nos dejó Erick.

Consideramos que para el siguiente avance debemos centrarnos en los algoritmos hechos en paralelo y las posibles ventajas que presentan cada una de las alternativas, así como ir familizarizandonos con la forma en que se implementarían. Con lo anterior podremos delimitar nuestro proyecto y poder encaminarnos hacia qué tipo de implementación de programación en paralelo usaremos.
