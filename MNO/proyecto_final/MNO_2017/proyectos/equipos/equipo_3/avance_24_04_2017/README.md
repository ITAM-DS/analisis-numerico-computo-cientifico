
**Equipo 3**

En estos días nos propusimos, como equipo, garantizar la infraestructura para poder hacer pruebas de código en paralelo. Levantar un cluster de datos fue, dadas las limitaciones de tiempo, un reto.

Decidimos trabajar de forma independiente esperando que alguno de los dos encontrara resultados y al final encontramos dos formas diferentes: Docker-Compose(Marin) y Dockerfile_git_MNO(Camilo). La parte de la paralelización del código quedará para la próxima entrega.

Al final nos reunimos para discutir nuestros resultados y redactar el avance.

**Camilo**

En estos días nos propusimos generar las condiciones necesarias para generar cómputo en paralelo. 
Así que tomé como base la referencia de tú Git Erick para levantar un cluster de máquinas.
Perdí muchas horas porque la máquina se quejaba mucho, pero al final del día lo logré.

El principal problema era que en algún paso, "docker build" descomprime parciamente: 
De *openmpi-2.0.2.tar.gz* a *openmpi-2.0.2.tar*, mientras que el flujo de datos esperaría una descompresión total, razón por la cual no localizaba la carpeta *openmpi-2.0.2*.   

La versión de código es la siguiente: [Dockerfile](Dockerfile)

**Marin:**

Para crear un cluster en MPI con los contenedores de docker sigui tu guia, logré a levantar y ligar el contenedor maestro y nodo1.Sin embargo no logré a executar mpirun --prefix /opt/openmpi-2.0.2/ -n 2 -H master,nodo1 hello_clase.out en el nodo maestro pero no buscé el error porque al lugar de dar un error preciso en el terminal el command me envio una lista de errores possibles.Probé tambien de hacer la llamada de mpirun en el terminal principal pero no fue possible de me conectar a estes contenedores por un problema de hostname no conocido.Probé de hacer muchas cosas: 
.empezar de nuevo con cuidado el guia.
.configurar bien los ssh en mi ordinator para que repera estas nodos.
.buscar soluciones en internet.
Pero me pusé muchisimo tiempo y abandoné la idea de hacer con tu technica porque me falta demasiado conicimientos para manejar manualmente una architectura con ssh en unix.

En consequencia pensé que Docker compose podria ser muy util para manejar un grupo de contenedores y buscé en internet si habia un trabajo sobre MPI y docker compose. Suertamente encontré un sitio [Using Docker container Alpine-MPICH to develop MPI programs](https://asciinema.org/a/93067) y su [github associada](https://github.com/NLKNguyen/alpine-mpich) del autor Nikyle Nguyen ,autor tambien de "Distributed MPI cluster with Docker Swarm mode," 2017 IEEE 7th Annual Computing and Communication Workshop and Conference (CCWC), Las Vegas, NV, USA, 2017, pp. 1-7.

Gracias a sus explicaciones y sus programos logré a leventar un cluster muy rapidemente con un quantitad importante de contenedores.

Propuse un tutorial [Levantar un cluster de 10 contenedores para ejecutar el programo hello_clase.c de Erick](tutorial_cluster_MPI.md) para que sea mas directo de applicar los programas de Nikyle Nguyen.
Espero realmente que este pequeño tutorial podria ayudar otros equipos que trabajan en MPI para levantar rapidamente un cluster eficiente.

Proximo avance:
Probar el integracion de MC en MPI(quizas mañana en equipo).

Objetivo de los proximos avances:

Si logramos vamos a pasar a MCMC:Hasting-Metropolis en el cuarto avance porque necesitamos MC integration para construir una probabilidad, es decir, pasar de f(x) a h(x)p(x)*C dentro la integral de f con C el constante de integracion de p y probar simulación de probabilad muchos más complejos, ie pasar de un ley uniforme multidimensional a un ley normal multidimensional para construir una cadena. Vimos que para simular la ley normal multidimensional podemos aplicar conceptos de matrices como la factorisacion de Cholesky.
