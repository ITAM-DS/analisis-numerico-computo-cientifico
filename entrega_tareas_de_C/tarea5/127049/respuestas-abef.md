Respuestas a, b, e y f
a) Cuando usamos signos de menor y mayor, el compilador busca el archivo en la lista de ruta de acceso. Cuando usamos comillas dobles, primero busca en el directorio actual (es decir, el directorio donde se compila el módulo) y si no esta busca la lista de ruta de acceso de inclusión.

Entonces por convención, se utilizan los signos m y m para las inclusiones estándar y las comillas para todo lo demás. Esto asegura que en caso de tener un encabezado local con el mismo nombre que un encabezado estándar, se elegirá la correcta en cada caso.

b)Static envía la variable al archivo, entonces al aplicarle static a una variable externa será inicializada una sola vez y estará presente en todo el programa

e)Investiga sobre LAPACK, BLAS y ATLAS 
  -LAPACK (Linear Algebra Package) es una colección de subrutinas escritas en FORTRAN 77 para resolver los problemas matemáticos más comunes que surgen a partir del modelamiento y que se enmarcan en el campo del álgebra lineal numérica.
  
  -BLAS (Bioaccumulation and Aquatic System Simulator) Es un programa de simulación de Fortran 95 que predice la población y la dinámica de la bioacumulación de las asociaciones de peces estructuradas por edades que están expuestas a contaminantes orgánicos hidrófobos ya los metales limítrofes de la clase B que se complejan con grupos sulfhidrilo (cadmio, cobre, plomo, mercurio, Plata y zinc). Los algoritmos de bioacumulación del modelo se basan en la cinética de difusión y están acoplados a un modelo basado en procesos para el crecimiento de peces individuales. Estos algoritmos consideran tanto los atributos biológicos de los peces como las propiedades físico-químicas de los productos químicos que determinan el intercambio difusivo a través de las membranas branquiales y la mucosa intestinal.
  
  -ATLAS (Automaticly Tuned Linear Algebra Software) es un sistema para generar bibliotecas matemáticas de alto rendimiento. Genera una biblioteca que está ajustada específicamente a su procesador y compilador. El objetivo de ATLAS es proporcionar un software de álgebra lineal óptimo. En particular interfaces ANSI C y Fortran 77 al BLAS, y un subconjunto de LAPACK.

f) subrutina de Fortran dgemm

Calcula el producto de las matrices de doble precisión, además la rutina dgemm puede realizar varios cálculos. Por ejemplo, puede realizar esta operación con la transposición o la transposición conjugada de A y B.














