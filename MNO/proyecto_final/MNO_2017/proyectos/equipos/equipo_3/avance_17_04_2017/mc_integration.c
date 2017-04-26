#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


double unif(double a,double b);
double f(double x, double y,double z) ;

int main(int argc, char *argv[]){

int i=0;
int N;

double sim_x;
double sim_y;
double sim_z;

double sim;

double a_x,a_y,a_z;
double b_x,b_y,b_z;


printf("\nCalculamos el integral de x+y+z con MC \n\n");
printf("Entrar la primer limita del integral para x: a_x=");
scanf("%lf",&a_x);

printf("Entrar la segunda limita del integral para x: b_x= ");
scanf("%lf", &b_x);

printf("Entrar la primer limita del integral para y: a_y=");
scanf("%lf",&a_y);

printf("Entrar la segunda limita del integral para y: b_y= ");
scanf("%lf", &b_y);

printf("Entrar la primer limita del integral para z: a_z=");
scanf("%lf",&a_z);

printf("Entrar la segunda limita del integral para z: b_z= ");
scanf("%lf", &b_z);

printf("Entar el numero de simulacion : N=");
scanf("%d",&N);


srand(time(NULL)); //aqui para empezar de un nuevo punto (ver explicacion unif())

for (i=0;i<N;i++){
	sim_x=unif(a_x,b_x);
	sim_y=unif(a_y,b_y);
	sim_z=unif(a_z,b_z);

	sim+=f(sim_x,sim_y,sim_z);

;}

// Tipo 1: La parallizacion puede hacerse donde cada proceso simula el f(X,Y,Z) con:
// Paralelización sobre la región de integración
// X~unif(a_x_local,b_x_local)
// Y~unif(a_y_local,b_y_local)
// Z~unif(a_z_local,b_z_local)

// Tipo 2: Paralelización por cada simulación, pero sobre el intervalo completo (a,b no local) de f(X,Y,Z) y juntar  
// todos las simulaciones en un simulación global, porque estamos en el caso de simulaciones independientes teóricamente.

// Según la literatura, esta es la forma de paralelizar más robusta (Si se pierde un proceso, la estimación de la integral, 
// se aproxima en una proporción (N*k-1)/(N*k) respecto a la desdeada. k procesos y N simulaciones por proceso. 

// Ver en el párrafo 4 de la explicación de la funcion unif() el peligro de utilizar diferentes procesos dentro de una misma computadora
// para la noción de independancia entre los simulaciones de cada proceso.

//En los 2 casos mejoramos la precisión de la simulación porque al lugar de hacer N simulaciones hacemos k*N simulaciones 
//en un tiempo limite (k:numeros de procesos (MPI) trabajando simultaneamente)


printf("Integral de x+y+z:%1.4f\n",(b_x-a_x)*(b_y-a_y)*(b_z-a_z)*(1/(double)N)*sim);

//Teoría de MC :(1/N)*sim~=E(f(X,Y,Z)) pero E(volumen*f(X,Y,Y))~=integral(f(X,Y,Z)) porque creamos 3 densidades uniformes  
//dentro del integral de f.

} //end main()


//Explicacion unif :

//rand() genera un número aleatorio entero entre 0 y RAND_MAX de manera pseudo-aleatoria
//RAND_MAX en mi máquina es iqual a  2 147 483 647
//De hecho, rand() devuelve una secuencia de números que fue extraida de una sequencia de numeros de gran tamano que 
//fue generada de manera pseudo-aleatoria pero necesitamos empezar a cada vez en un nuevo punto cuando lanzamos el algoritmo para no repetir la secuencia.
//Es por eso por ejemplo que utilizamos time(NULL) dentro sran() que da el numero de segundo desde 1970 (Ref:OpenClassroom).

//rand()/(double)RAND_MAX  genera un numero aleatoria double entre 0 y 1 y pusimos /(double) para tener un division real
//(rand()/(double)RAND_MAX)*(b-a) genere un numero aleatoria entre (b-a)/RAND_MAX y b-a.En general b-a << 2 147 483 647 (RAND_MAX)
//Sin embargo si no es el caso debemos cambiar de metodos para generar numeros aleatorios.

//En este caso de MC integration simular la ley uniform permite de aplicar directamente la theoria MC para los integrales.

//Sin embargo si utilizamos diferentes processos con los contenedores de docker dentro nuestra maquina tenemos que ser muy prudente
//con la posibilidad que entre ellos pueden con rand() leer parte identica en la sequencia de numeros y en consequencia 
//perder totalemente la independancia de los simulcaciones.(referencia : Fast and reliable Random Number Generators for scientific computing de Richard P Brent)
//Entonces como el algorithmo secuencial tenemos que buscar esta vez una maneja de cambiar el srand para cada processo 
//al utilizar por ejemplo el rank del processo que caracterisa cada processo dentro un communicator.Habia pensado a utilizar para cada processo: 
//srand(time(NULL)+N*rank_processo) con N el mismo numero de simulciones que queremos realizar en cada processo.

//Si pasemos a MCMC:Hastings-Metropolis necesitamos crear un algorithmo o utilizar una libreria que permite de simular por ejemplo un ley normal multidimensonal (dimension del integral)(difficil)
//dado un vector_esperanza y un matrix de covariancia en el objetivo de dar a cada torno un nuevo elemento a comparar con el elemento anterior.

double unif(double a, double b){
    return ( rand()/(double)RAND_MAX ) * (b-a) + a ;
}

double f(double x, double y,double z) { return x+y+z; }
//Nos gustaria mucho que el usuario puede entrar cuando llame el executive en el terminal su propio funcion f.
//pero no logramos a buscar un funcion de tipo eval() (como en Python y R) que permiteria de transcribir un string en codigo.