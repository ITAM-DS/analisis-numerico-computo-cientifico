## Instrucciones para compilar y ejecutar las implementaciones en paralelo

Para compilar se utilizaron los siguientes valores:

- Número de procesos: 3

- Límite inferior: 0

- Limite superior: 1

- Número de segmentos: 10:

En la ejecución, el número de procesos es el valor que se define despues de `-np`, y los tres valores al final de la misma son el límite inferior, el límite superior y el número de segmentos, en ese orden.

__Simpson__

- X^2

Para compilar: `$HOME/opt/usr/local/bin/mpicc -o simpson_x2 ~/Documents/compartida/proyecto_final_mno/simpson_x2.c`

Para ejecutar: `$HOME/opt/usr/local/bin/mpirun --oversubscribe -np 3 ./simpson_x2 0 1 10`




- cos(x)

Para compilar: `$HOME/opt/usr/local/bin/mpicc -o simpson_cos ~/Documents/compartida/proyecto_final_mno/simpson_cos.c`

Para ejecutar: `$HOME/opt/usr/local/bin/mpirun --oversubscribe -np 3 ./simpson_cos 0 1 10`


- exp(x)

Para compilar: `$HOME/opt/usr/local/bin/mpicc -o simpson_exp ~/Documents/compartida/proyecto_final_mno/simpson_exp.c`

Para ejecutar: `$HOME/opt/usr/local/bin/mpirun --oversubscribe -np 3 ./simpson_exp 0 1 10`



__Riemann__

- X^2

Para compilar: `$HOME/opt/usr/local/bin/mpicc -o riemann_x2 ~/Documents/compartida/proyecto_final_mno/riemann_x2.c`

Para ejecutar: `$HOME/opt/usr/local/bin/mpirun --oversubscribe -np 3 ./riemann_x2 0 1 10`


- cos(x)

Para compilar: `$HOME/opt/usr/local/bin/mpicc -o riemann_cos ~/Documents/compartida/proyecto_final_mno/riemann_cos.c`

Para ejecutar: `$HOME/opt/usr/local/bin/mpirun --oversubscribe -np 3 ./riemann_cos 0 1 10`


- exp(x)

Para compilar: `$HOME/opt/usr/local/bin/mpicc -o riemann_exp ~/Documents/compartida/proyecto_final_mno/riemann_exp.c`

Para ejecutar: `$HOME/opt/usr/local/bin/mpirun --oversubscribe -np 3 ./riemann_exp 0 1 10`


__MCMC__

- X^2

Para compilar: `$HOME/opt/usr/local/bin/mpicc -o mcmc_x2 ~/Documents/compartida/proyecto_final_mno/mcmc_x2.c`

Para ejecutar: `$HOME/opt/usr/local/bin/mpirun --oversubscribe -np 3 ./mcmc_x2 0 1 10`


- cos(x)

Para compilar: `$HOME/opt/usr/local/bin/mpicc -o mcmc_cos ~/Documents/compartida/proyecto_final_mno/mcmc_cos.c`

Para ejecutar: `$HOME/opt/usr/local/bin/mpirun --oversubscribe -np 3 ./mcmc_cos 0 1 10`


- exp(x)

Para compilar: `$HOME/opt/usr/local/bin/mpicc -o mcmc_exp ~/Documents/compartida/proyecto_final_mno/mcmc_exp.c`

Para ejecutar: `$HOME/opt/usr/local/bin/mpirun --oversubscribe -np 3 ./mcmc_exp 0 1 10`
