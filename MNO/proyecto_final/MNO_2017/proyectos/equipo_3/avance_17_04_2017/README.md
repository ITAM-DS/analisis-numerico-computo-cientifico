
Trabajo individual:

*Marin:*

Trabajé sobre el simulación de números aleatorios en c en el sitio OpenClassroom MOOC francés reconocido por el estado Francés y en Europa[L'aleatoire en C et C++ con rand()](https://openclassrooms.com/courses/l-aleatoire-en-c-et-c-se-servir-de-rand-1).

Leí al mismo tiempo la referencia que nos diste [R. P. Brent. Fast and Reliable Random Number Generators for Scientific Computing](http://maths-people.anu.edu.au/~brent/pd/rpb217a.pdf) para ver si tenemos que ser cuidado con la paralelisacion de los simulaciones de numeros aleatorios.

Trabajé despues sobre MC integracion en el mismo sitio OpenClassroom [A la découverte de l'aléatoire et des probabilités](https://openclassrooms.com/courses/a-la-decouverte-de-l-aleatoire-et-des-probabilites)

Empecé un parte del codigo [mc_integration.c](mc_integration.c) codigo secuencial de estimacion de integral por Monte Carlo.

Puse mis estudios en los comentarios en el codigo mc_integration.c en explication de unif() donde expliqué como funciona la simulacion y donde tendramos de ser cuidado en el futuro parallelisacion de este algorithmo.


*Camilo:*

Yo trabajé principalmente las lecturas recomendadas por Erick de tal forma que se pueda, enfocándome en generar texto que sirva para la presentación final, así como para generar inquietudes, por ejemplo:
¿Debemos generar nuestra propia función generadora de números aleatorios? 
¿Cómo vamos a evitar correlaciones entre número aleatorios en los diferentes procesos? (ver código Marin truco-time)
¿Cómo vamos a diseñar el código para paralelizar (inner loops vs outer loops)?
¿Cómo hacemos para ingresar al código una función elegida por el usuario (simplificada por ahora)?

[Camilo_semana_2](https://1drv.ms/b/s!AtYhTtvZ1LiEg-Rt1C10p7BtTuSHYg)



*Trabajo en equipo:*

Terminamos el codigo juntos y pensamos como vamos a parallelizar este algoritmo.Todos nuestros ideas estan en los comentarios del codigo [mc_integration.c](mc_integration.c).

Objetivo de la proxima avance :
Crear 5 contenedores en una maquina y probar el integracion de MC en MPI sobre este 5 maquinas.

Objetivo de los proximos avances:

Si logramos vamos a pasar a MCMC:Hasting-Metropolis en el cuarto avance porque necesitamos MC integration para construir una probabilidad, es decir, pasar de f(x) a h(x)p(x)*C dentro la integral de f con C el constante de integracion de p y probar simulación de probabilad muchos más complejos, ie pasar de un ley uniforme multidimensional a un ley normal multidimensional para construir una cadena. Vimos que para simular la ley normal multidmensional podemos aplicar conceptos de matrices como la factorisacion de Cholesky.

