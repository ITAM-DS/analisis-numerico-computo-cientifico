# Equipo 8

Integrantes:

+ Luis Fernando Cantú Díaz de León
+ Eduardo Hidalgo García
+ Mónica Vargas González

Título del proyecto: `Método de descenso en gradiente en juegos de Cournot`

Objetivo del proyecto: Implementar el método de descenso en gradiente para encontrar el equilibrio de Cournot-Nash de un juego de Cournot.

Liga a trabajo escrito: [Dropbox](https://www.dropbox.com/s/0966eupkrlqmzg2/escrito.pdf?dl=0)

Presentación: [Dropbox](https://www.dropbox.com/s/x6herlud9tx8x9c/Implementacion%20de%20Cournot%20en%20C.pptx?dl=0)

Implementación en C: [Github](avance_30_05_18/C_files/cournot_nash_equilibrium.c)

Ya una vez compilado el archivo de C, por ejemplo con el nombre `cournot.out`, lo único que resta por hacer es correrlo en la terminal especificando, en el orden descrito, los siguientes argumentos:

1. Número de empresas. Debe de ser de tipo `int`.
2. Tasa de aprendizaje. Es de tipo `double`.
3. Alpha: ordenada al origen de la función inversa de la demanda. Es de tipo `double`.
4. Beta: pendiente de la función inversa de la demanda. Es de tipo `double`.
5. Gamma: costo marginal de las empresas. La implementación en C solo permite que todas las empresas tengan el mismo costo marginal. Es de tipo `double`.

Ejemplo de una simulación con 500 empresas. Correr en terminal:
`./cournot.out 500 0.0005 50 2 2`

Ejemplo de corrida de C: [Dropbox](https://www.dropbox.com/s/3s3l7x9tsyy2v9f/ejemplo_100_empresas.txt?dl=0)



Avances:

+ [10 de abril de 2018](avance_10_04_18/entrega1_1.md): definimos el problema a resolver. Primero buscamos encontrar soluciones de Stackelberg, pero es un problema demasiado complicado como para resolverlo en tan poco tiempo. Entonces fue que nos decidimos por encontrar máximos en el juego de Cournot y, además, nos adentramos en la literatura del tema.

+ [17 de abril de 2018](avance_17_04_18/segunda_entrega.md): continuó la revisión de la literatura y, además, se hicieron las primeras implementaciones tanto en R como en Python.

+ [24 de abril de 2018](avance_24_04_18/): se empezó con la elaboración del trabajo escrito. Específicamente:
  * Luis Fernando Cantú: escribió una parte de modelo de competencia de Cournot en el capítulo de revisión de la literatura y también el capítulo en el que se describe el modelo.
  * Mónica Vargas González: añadió la introducción, el objetivo y una descripción general de Cournot en el capítulo de revisión de la literatura.
  * Eduardo Hidalgo García: escribió la explicación del algoritmo de descenso por gradiente, el contexto teórico sobre su uso y su aplicación a problemas con funciones objetivos doblemente diferenciables y continuas.

+ [02 de mayo de 2018](entrega_02_05_18/): se empezó con la elaboración del trabajo escrito. Específicamente:
  * Luis Fernando Cantú: continúo con la elaboración del trabajo escrito. Específicamente, contribuyó a la parte del modelo del juego de Cournot y al ejemplo del caso lineal..
  * Mónica Vargas González: Investigación sobre implementación de descenso de gradiente en C.
  * Eduardo Hidalgo García: Modificaciones al md de inicio de la carpeta del equipo, modificacion del archivo escrito. En especifico, continuo con el sustento teórico de los métodos de descenso por gradiente

+ [08 de mayo de 2018](avance_08_05_18/): se empezó con la elaboración del trabajo escrito. Específicamente:
  * Luis Fernando Cantú: escribió la sección 3.2: La rutina Minimize_Down_the_Line, que contiene la descripción de una de las rutinas de C para implementar descenso en gradiente.
  * Mónica Vargas González: escribió la sección 3.1: La rutina Steepest_Descent, que contiene la descripción de una de las rutinas de C para implementar descenso en gradiente.
  * Eduardo Hidalgo García: escribio la seección 3.3, que contiene la investiagación sobre la libreia en C MPFIT, la cual implementa el metodo de Levenberg-Marquard para resolver el problema de mínimos cuadrados. Lo que hará es ajustar una función provista por el usuario (el "modelo") a un conjunto de datos tambien provistos por el usuario.

+ [22 de mayo de 2018](avance_22_05_18/sexta_entrega.md): se terminaron los modelos en los lenguajes C y Julia. Se corrieron y ambos funcionan correctamente: hay ejemplos en archivos de texto dentro de las carpetas correspondientes. Falta comentar el código de C. Las contribuciones individuales en el md de la sexta entrega.

+ [30 de mayo de 2018](avance_30_05_18/ultima_entrega.md): se terminó de comentar el código de los lenguajes C y Julia. Se terminaron la presentación y el trabajo escrito.



Referencias:

1.  Kolstad, Charles D. and Mathiesen, Lars. (1987). "Necessary and Sufficient Conditions for Uniqueness of a Cournot Equilibrium", The Review of Economic Studies, v.54, No.4, p.681-690. <https://www.jstor.org/stable/2297489?seq=1#page_scan_tab_contents>

2.  Miranda, M. J., & Fackler, P. L. (2004). Applied computational economics and finance. MIT press. <https://mitpress.mit.edu/books/applied-computational-economics-and-finance>

3.  Quoc, Tran Dinh and Muu Le, Dung. (2011). "A splitting proximal point method for Nash-cournot equilibrium models involving nonconvex cost functions",Journal of Nonlinear and Convex Analysis, v.12, p.519--533. <https://arxiv.org/abs/1105.2632>

4. Schmedders, Karl. (2008). Numerical Optimization Methods in Economics. 1-27. 10.1057/978-1-349-95121-5\_2232-1. <https://www.researchgate.net/publication/313867455_Numerical_Optimization_Methods_in_Economics?enrichId=rgreq-d983e8a6585dd0a533e66b02013921c9-XXX&enrichSource=Y292ZXJQYWdlOzMxMzg2NzQ1NTtBUzo0NzkzMTkxMzU5MjAxMzNAMTQ5MTI4OTk5NTg2OA%3D%3D&el=1_x_3&_esc=publicationCoverPdf>

4. MPFIT documentation  http://cow.physics.wisc.edu/~craigm/idl/cmpfit.html

