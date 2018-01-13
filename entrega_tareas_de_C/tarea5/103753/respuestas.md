# Respuestas 

## a)

Los archivos 'header' tanto los definidos en sistema como los definidos por el usuario son incluidos usando la directiva de preprocesamiento ```#include```, la cual tiene dos formas dependiendo si es un archivo system header o un user header. 

En el caso de ser un header del sistema se incluye con <> de modo que se busca en las librerías del sistema.

```
#include <file>
```

En el caso que sean headers definidos por el usuario se incluye con "", en cuyo caso se busca en el directorio el archivo de nombre 'file'

```
#include "file"
```

En cualquier caso los archivos header se puede agregar usando la option -I al momento de compilar el codigo fuente. 

## b)

El keyword ```static``` se utiliza en la declaración de funciones para que únicamente sean visibles a otras funciones definidas en el mismo archivo. En particular se puede decir que se limita el scope de la función a lo definido en el archivo en el que está definida.