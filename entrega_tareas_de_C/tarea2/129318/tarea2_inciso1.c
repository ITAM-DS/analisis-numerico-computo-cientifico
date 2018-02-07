//MNO: tarea 2, inciso1
//Autor: Mónica Vargas
//CU. 129318

/*1) Investiga lo que quieren decir las letras EOF. ¿Por qué se debe definir c como int?:
EOF significa "End of file"; tiene un valor de -1 para que no se confunda con los bytes de getchar() que van del 0 al 255 inclusivo.
Una nueva linea (que es lo que pasa cuando le das enter) no es el final de un archivo (o "file"); por lo tanto, una nueva linea no termina este loop. Debes terminarlo con el ctrl + c.
Se debe definir como un int ya que el comando getchar convierte el valor del caracter a un entero no-negativo; en otras palabras, es el tipo de variable que resulta de getchar().*/

