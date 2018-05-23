Avance 1-0-2018
Integrantes:

    Mario Vazquez Corte
    Saúl Caballero Ramírez

Trabajo: Realizamos avances en el trabajo escrito y investigación de descomposición QR en libreria MGAMA.

Individual

Saúl:

Realicé una descripción específica de Chevyshev Center para el pdf.
Realicé puruebas finales de lp_solver.
Realicé investigación sobre descomposición QR y como utilizarla para la matriz de proyección.

https://en.wikipedia.org/wiki/Householder_transformation
http://icl.cs.utk.edu/projectsfiles/magma/doxygen/group__magma__geqrf.html
Parker, Geophysical Inverse Theory, Ch1.13
Press, WH; Teukolsky, SA; Vetterling, WT; Flannery, BP (2007), "Section 2.10. QR Decomposition", Numerical Recipes: The Art of Scientific Computing (3rd ed.), New York: Cambridge University Press, ISBN 978-0-521-88068-8
Stoer, Josef; Bulirsch, Roland (2002), Introduction to Numerical Analysis (3rd ed.), Springer, ISBN 0-387-95452-X.

Mario:

Realicé una descripción del algoritmo Hit and Run, y de la metodologia Box-Muller. 
Investigue sobre la libreria MAGMA que esta disponble para CUDA.
Investigue sobre los métodos de descomposición QR -> Graham-Schmidt vs Descomposición Householder.

	Fuente: 
http://icl.cs.utk.edu/projectsfiles/magma/doxygen/group__magma__geqrf.html#ga472ce8a0ffb5cfdaa1d84b356671adb7
https://en.wikipedia.org/wiki/QR_decomposition
Parker, Geophysical Inverse Theory, Ch1.13
http://icl.cs.utk.edu/projectsfiles/magma/doxygen/group__magma__geqrf.html
Press, WH; Teukolsky, SA; Vetterling, WT; Flannery, BP (2007), "Section 2.10. QR Decomposition", Numerical Recipes: The Art of Scientific Computing (3rd ed.), New York: Cambridge University Press, ISBN 978-0-521-88068-8
Stoer, Josef; Bulirsch, Roland (2002), Introduction to Numerical Analysis (3rd ed.), Springer, ISBN 0-387-95452-X.

Equipo:
Realizamos una descripción general del algoritmo, y pulimos el pdf del trabajo escrito en equipo.
Acordamos utilizar la descoposición QR para la matriz de projección utilizando la librería MAGMA y el método de Householder, ya que la estabilidad númerica es más importante que el tiempo de ejecución. Además, este se ve compensado pues le calculo se realiza una sola vez al inicio del algoritmo.
La liga al PDF es la siguiente: https://www.dropbox.com/s/0ew8h8fxuuom1u7/Hit___Run.pdf?dl=0     

Fuente:
http://www.ece.neu.edu/groups/nucar/GPGPU/GPGPU-2/Kerr.pdf
Parker, Geophysical Inverse Theory, Ch1.13
