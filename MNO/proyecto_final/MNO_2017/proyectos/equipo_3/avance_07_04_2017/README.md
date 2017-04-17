
Integrantes:

	Camilo Abdoud
    
	Marin Leblanc




**I. Trabajo Individual**



*Marin:*


Revisé el curso de Mauricio sobre  los metodos de Monte Carlo y Markov chain.
Después, para tener un idea clara del procesamiento de MCMC,
lei el documento en wikipedia sobre MCMC- Hasting-Metropolis.
 


*Camilo:*


* Repaso de teoría de MC integración.

* Repaso la teoría simulación MCMC.
 
* Ideas básicas programación OpenMPI parallel




**II. Trabajo en Equipo**



Nos reunimos para delimitar el alcance del trabajo. Se discutieron ideas básicas de los métodos MC y MCMC.


Objetivos próxima clase: 

- Algoritmo Secuencial de integración MC en un contenedor de Docker.




*Referencias:*

[Metropolis–Hastings algorithm wikipedia](https://en.wikipedia.org/wiki/Metropolis%E2%80%93Hastings_algorithm)
 
[Curso de Mauricio Garcia Tec Estadistica computacional](https://1drv.ms/b/s!AtYhTtvZ1LiEg9ZfLV-dAw_uLrInpw)

[OpenMP básico](http://www.cs.cornell.edu/~bindel/class/cs5220-s10/slides/lec06.pdf)


## Comentario sobre avance:

* Es mala idea poner de nombre README_Eq3_2017_04_07.md pues no se despliega en github y hay que dar click. Consideren este comentario como estética. Mismo comentario para el README del nivel equipo_3.

*  No se ve que haya habido edición de este README pues nuevamente aparece título de proyecto, objetivo adicional, objetivo básico aquí.

* Los dos comentarios anteriores hacen referencia a estos README's. Fui a la liga https://github.com/mleblanc03/analisis-numerico-computo-cientifico/tree/master/MNO/proyecto_final/MNO_2017/proyectos y se ven bien ahí. Qué sucedió entonces ? Hagan nuevamente el pull request con los cambios porfa.

* Una presentación sólo te da una idea. Mejor si tienen una referencia que sea un texto o paper. 

* Entonces se realizará en paralelo la aproximación a una integral con openMP o con MPI? Pues en su objetivo del proyecto dicen openMPI y objetivos próxima clase mencionan a openMP (?¿) quizás no han determinado la extensión de C a usar. Si es el caso pongan algo como "extensión de C por determinar".

* Debe haber más explicación de su trabajo individual. Sólo fue revisión y repaso, falta que cubran el objetivo básico, en este caso hay que buscar referencias para ejecución en paralelo de los métodos de generación de números aleatorios. Esto es más importante que revisar o repasar aquello que ya está resuelto. Observen lo que han hecho los equipos 6, 10 u 11. Debe de haber un primer avance fuerte en alguno de los siguientes rubros: estudio de la teoría e implementación pero no he visto esto en este primer avance :(

* Revisen las siguientes referencias y definan cuáles les son útiles. Elijan qué método usar. Aquellas que sean útiles colóquenlas en el README debajo del nivel equipo_3:

* Texto: [W. Petersen, P. Arbenz Introduction to Parallel Computing: A Practical Guide with Examples in C](https://www.researchgate.net/publication/268617797_Introduction_to_parallel_computing_A_practical_guide_with_examples_in_C)

* Un paper introductorio para generación de números aleatorios con cómputo en paralelo: [P. D. Coddington. Random Number Generators for Parallel Computers](http://surface.syr.edu/cgi/viewcontent.cgi?article=1012&context=npac). Otro: [M. Mascagni. Parallel Pseudorandom Number Generation](http://www.cs.fsu.edu/~mascagni/papers/IIP1.pdf)

* Un paper introductorio de requerimientos para good uniform random number generators y mencionan referencias al trabajo en paralelo: [R. P. Brent. Fast and Reliable Random Number Generators for Scientific Computing](http://maths-people.anu.edu.au/~brent/pd/rpb217a.pdf)

* Un paper para uniform and normal distributions en paralelo: [R. P. Brent. Random Number Generation and Simulation on Vector and Parallel Computers](http://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.2.8988&rep=rep1&type=pdf)




