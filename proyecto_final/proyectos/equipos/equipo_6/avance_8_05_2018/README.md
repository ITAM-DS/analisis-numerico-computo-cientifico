Avance 1-0-2018
Integrantes:

    Mario Vazquez Corte
    Saúl Caballero Ramírez

Trabajo: Realizamos instalación de MAGMA y MKL, arreglo de errores con las dos librerias y optimización de código.

Individual

Saúl:
  Instalación de MKL
  Solución a errores de MAGMA y MKL.
  Investigación de como alocar memoria usando MAGAMA para la rutina magma_dgeqrf_gpu



  Saul-Fuente:
MKL:https://software.intel.com/en-us/forums/intel-math-kernel-library/topic/545280
MAGMA:https://developer.nvidia.com/sites/default/files/akamai/cuda/files/Misc/mygpu.pdf

Mario:
  Instalación de MAGMA y solución de errores no dependientes de MKL
  Código qr3c.c
  Intente arreglar erroes de compilación que aparecen respecto a la libreria de OpenBLAS. Logré solucionarlo, pero falta investigación de por que ocurren y un entendimiento más a fondo.
  Investigué sobre los tres tipos de rutina que existen  magma_dgeqrf_gpu:  magma_dgeqrf_gpu 	 magma_dgeqrf2_gpu 	 magma_dgeqrf3_gpu. Encontré post en el foro de MAGMA que hablan sobre la estabilidad y velocidad de esta rutina. Ahí encontramos un código que compará la versión en CPU y en GPU de la rutina. 	Algunas pruebas viene en la carpeta de codigo/MAGMA/dgeqrf.txt . Faltan realizar más pruebas.


	Mario-Fuente:
MAGMA :https://developer.nvidia.com/sites/default/files/akamai/cuda/files/Misc/mygpu.pdf
RUTINA dgeqrf :
http://icl.cs.utk.edu/magma/forum/viewtopic.php?f=2&t=321&p=1094&hilit=magma_dgeqrf2_gpu#p1094
http://icl.cs.utk.edu/magma/forum/search.php?keywords=dgeqrf

Equipo:
La carpeta de código esta separada en 2: Nuestro código base, y la carpeta de MAGMA que trae las rutinas, pruebas y un tutorial que realizamos los dos para la instalación apropiada de las librerias necesarias en Ubuntu.
Nos enfrentamos al error de MAGMA y los problemas de instalación.
Decidimos realizar las pruebas con la rutina 2 y 3 dado los resultados que se mencionan en la fuente de RUTINA dgeqrf. Faltan realizar más pruebas.

Fuente:

https://developer.nvidia.com/sites/default/files/akamai/cuda/files/Misc/mygpu.pdf
