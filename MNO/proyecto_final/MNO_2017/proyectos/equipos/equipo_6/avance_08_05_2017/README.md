# Avance_08_05_2017

## Integrantes:

* Ricardo Lastra

* Adrián Vázquez

## Trabajo:

### Individual

Adrián Vázquez (120028):


__Implementación de arquitectura__

Se configuro un cluster en AWS utilizando la implementación de la arquitectura para distribucion MPI el cual controla la distribucion y paralelizacion de los datos "Chunk" usando la herramienta [Sun Grid Engine.](sge.md)
____


Ricardo Lastra (160167):

__Metodo para calculo de SVD__

Finalmente se desarrollo la Fase 3 del metodo thin segun las notas de clase [3.2.2 Factorizaciones matriciales: SVD, Cholesky, QR.](https://www.dropbox.com/sh/azwz5p69bnbamtw/AAB5t2SafFK_1XvthNT9Tflda?dl=0)

Este avance detalla de forma muy sencilla la [Fase 3 en el siguiente documento "Multiplicacion_U_V.html"](https://drive.google.com/drive/folders/0B5eQQH_TPIY-YjVmSE5NS3BSYzQ).
La Fase 3 unicamente detalla la multiplicacion de las matrices U y V  obtenidas en las 2 fases anteriores para asi obtener la matriz `A` en su forma de `SVD`.

Tambien se sigue leyendo el libro `Matrix Computations` de H. Golub y F. Van Loan en el capitulo 8.6.3 "The SVD Algorithm" en la fase 3. donde habla de las rotaciones de Givens y como una matriz bidiagonal se puede transformar en otra con diferentes entradas. Esto nos llamo la atencion por que antecede al algoritmo de Golub-Kahan que como lo vimos anteriormente habla de aplicar SVD a una matriz bidiagonal.

Tenindo ya mas claro el algoritmo `SVD` en sus diferentes aplicaciones (matrices pequeñas o grandes) empezamos a documentar el [metodo implementado en CUDA-C](avance_17_04_2017/metodos-cuda.md) que generamos en el avance del 17 de Abril.
Esta documentacion se sigue elaborando y consistira en un documento que explique a detalle el metodo en `CUDA/CUBLAS`.

### Equipo
Activamos nuevamente un par de EC2 de Amazon, y estuvimos batallando un rato con Star Cluster. Hubo varias cosas que encontramos que nos gustaria detallar mas en el proximo avance. 
Siguieron las dificultades para la configuracion del Docker. 
Tambien logramos un buen avance con la comprension del metodo Thin y para los casos Large & Sparse. Asi mismo comprendimos mas el metodo `Qr` y algunas transformaciones adiconales matriciales. Le dedicamos mucho tiempo al libro de `Matrix Computations` que desde capitulos anteriores al sugerido es muy interesante.
Queriamos subir el avance de la explicacion del metodo de `CUDA/CUBLAS` pero, deseamos detallarlo un poco mas y dejarlo muy bien para la proxima semana.
Intentamos hacer el computo de matrices Bidiagonales y Tridiagonales en R o Python, pero no es tan sencillo. Logramos un avance muy sencillo, sin embargo decidimos leer un poco mas toda la teoria que tenemos ya. Asi como leer la documentacion a fondo de LAPACK y algunas subrutinas como EISPACK. Tambien revisamos la siguiente [tesis](ftp://ece.buap.mx/pub/profesor/academ48/Libros/TesisDavid.pdf) que nos parecio muy interesante, por la descripcion de como se alojan las matrices en memoria.


## Comentarios sobre avance:

## (Respuestas) Comentarios sobre avance:
