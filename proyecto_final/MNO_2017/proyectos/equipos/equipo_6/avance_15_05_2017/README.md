# Avance_15_05_2017

## Integrantes:

* Ricardo Lastra

* Adrián Vázquez

## Trabajo:

### Individual

Adrián Vázquez (120028):


__Implementación de arquitectura__

Concluimos el desarrollo de la arquitectura local para leer una imagen y hacer SVD con __cusolverDnDgesvd__. 
____


Ricardo Lastra (160167):

__SVD en cusolverDnDgesvd__

Al tener ya en mente muy claro el metodo thin de `SVD`, documentamos lo que hace la funcion cusolverDnDgesvd  en  el siguiente [documento "SVD_cusolverDnDgesvd.html"](https://drive.google.com/drive/folders/0B5eQQH_TPIY-YjVmSE5NS3BSYzQ).

Asi mismo empezamos a escribir en `Python` nuestro caso de uso para lectura de imagenes, descomposicion y reconstruccion de imagenes de siniestros de automoviles. Este ejemplo estara listo la proxima semana en el avance del 22 de Mayo.



### Equipo
Definimos correr de forma local (en la GPU de la maquina de Adrian) nuestro modelo.
Estuvimos revisando a detalle lo que hace la funcion `cusolverDnDgesvd` y despues de documentarla observamos los parametros de entrada.
Asi mismo empezamos con la definicion final del caso de uso, es decir, introducir al modelo matrices reales. 
El avance de Python asi como la validacion de resultados reales entre `cusolverDnDgesvd` de CUDA y `np.linalg.svd` de Python estaran listos la proxima semana. 


## Comentarios sobre avance:

## (Respuestas) Comentarios sobre avance:
