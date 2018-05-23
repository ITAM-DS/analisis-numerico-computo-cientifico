
**Rodrigo:**
`De acuerdo con las recomendaciones de Erick comenzamos con la parte introductoria del trabajo escrito que se puede ver en esta liga` [Trabajo escrito](https://drive.google.com/open?id=1umhS7cKuaOsY3cjQhn4BFUijz9AncHO_). 

**Abraham:**
`Sobre el tema de Cuda se instaló cuda  version 7.5 de forma local y se hizo la prueba de correr el programa de` [hello_world.cu](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/master/C/extensiones_a_C/CUDA/ejemplos) `que viene dentro del repo para revisar que el ambiente funcione las pantallas de las ejecuciones se pueden ver en el documento`[doc](https://drive.google.com/open?id=14fvFwO2YiefmB7jLa_57Mrcya4LJp9U5) 
`Se encontró en la siguiente liga` [SVD_cu](https://github.com/OrangeOwlSolutions/Linear-Algebra/blob/master/SVD/SVD.cu) `el cual nos muestra la programación del svd en cuda, se intentó ejecutar el programa pero hay algunos detalles por arreglar en la versión lo cual nos queda como tarea pendiente, la parte importante de este programa, este genera como salida las marices U,S,VT.

**Roberto:**
`De acuerdo con el programa svd.cu lo que encontramos que existe una función clave “cusolverDnDgesvd“ que es la que hace la descomposición svd  e investigamos los parámetros que se llaman en esta función` [cusolverDnDgesvd](https://drive.google.com/open?id=10aRstbsBOadzWACAoH1dtRCZBcBAmjd5) `con el fin de entender la lógica de la misma`.


**Equipo:**
`Se comienza con el trabajo escrito y se documenta función cusolverDnDgesvd.`
`svd.cu será nuestra guía para hacer la implementación del proyecto, primero trataremos de ejecutar el programa y después ver como se adecúa para lo que queremos lograr. Con este programa hemos encontrado que hay varios pasos que debemos revisar el primer tema son las dependencias, la versión 7.5 de cuda parece que no es la mejor para la compilación del programa ya que este manda errores, pero cuando se compiló con cuda 9 la compilación se realizó pero parece que hay problemas con los drivers.`[errores](https://drive.google.com/open?id=1X8OZytXac6IIF05bNcSYYLqMt_Wx48nR) `se vieron algunas referencias del tipo de error`[ref](https://devtalk.nvidia.com/default/topic/1027413/cuda-setup-and-installation/linux-installation-error-cudagetdevicecount-returned-30-gt-unknown-error/).
`Los siguientes pasos serán continuar con el trabajo escrito y la preparación del ambiente haciendo pruebas de cusolver`
