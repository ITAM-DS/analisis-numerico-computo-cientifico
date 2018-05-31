#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXROWS 500
#define MAXCOLS 500
#define MAXITERS 10000

/*
	En este programa se calcula el equilibrio de Nash-Cournot del
	juego de Cournot por medio del método de descenso en gradiente.
	El equilibrio consiste en las cantidades x que los jugadores
	escogen como su mejor respuesta a las estrategias de los otros
	jugadores.

	Como se plantea en el documento escrito, el problema de Cournot
	es equivalente a solucionar el problema cuadrático convexo:

	min_X (1/2)X'QX + (gamma - alpha)'X

	donde X es el vector de x_i's que queremos encontrar,
	Q es una matriz simétrica positiva definida y, por lo
	tanto, el problema tiene una solución óptima, que es
	el equilibrio de Nash-Cournot.
*/

// Declaración de funciones
void fill_matrix_Q(double Q[][MAXCOLS],int n, int beta);
void transpose(double A[][MAXCOLS], double At[][MAXCOLS], int n);
void mat_mul(double A[][MAXCOLS], double B[][MAXCOLS], double C[][MAXCOLS], int n);
void vec_mat_mul(double x[], double A[][MAXCOLS], double y[], int n);
void subs_vec_scal(double x[], double scal, double y[], int n);
void mult_vec_scal(double x[], double scal, double y[], int n);
void fill_array_x(double x[], double val, int n);
void vector_add(double x[], double y[], double add[], int n);
void vector_subs(double x[], double y[], double subs[], int n);
void df(double x[], double A[][MAXCOLS], double dfx[], double alpha, double gamma[], int n);
void gd(int n, double lr, double alpha, double beta, double gamma[]);


/* 
Función para rellenar la matriz Q con los valores de la pendiente
de la demanda inversa (beta).
*/
void fill_matrix_Q(double Q[][MAXCOLS],int n, int beta){
    int i, j;

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(i == j){
                Q[i][j] = 2*beta;
            } else{
                Q[i][j] = beta;
            }
        }
    }
}

/*
Función para transponer los elementos de una matriz A.
El resultado de la función se guarda en una matriz At.
*/
void transpose(double A[][MAXCOLS], double At[][MAXCOLS], int n){
    int i, j;

    for (i = 0; i<n; i++){
        for (j = 0; j<n; j++){
            At[i][j] = A[j][i];
        }
    }
}

/*
Función para multiplicar la matriz A por la B.
El resultado de la función se guarda en una matriz C.
*/
void mat_mul(double A[][MAXCOLS], double B[][MAXCOLS], double C[][MAXCOLS], int n){
    int i, j, k;

    // Primero rellenamos la matriz con ceros.
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            C[i][j] = 0;
        }
    }

    // Aquí se lleva a cabo la multiplicación.
    for(i = 0; i<n; i++){
        for(j = 0; j<n; j++){
            for(k = 0; k<n; k++){
                C[i][j] += A[i][k]* B[k][j];
            }
        }
    }
}

/*
Función para multiplicar un vector x por una matriz A.
El resultado se guarda en un vector y.
*/
void vec_mat_mul(double x[], double A[][MAXCOLS], double y[], int n){
    int i, j;

    for(i = 0; i<n; i++){
        y[i] = 0;
        for(j = 0; j<n; j++){
            y[i] += A[i][j] * x[j];
        }
    }
}

/*
Función para restarle un escalar scal a un vector x.
El resultado se guarda en el vector y.
*/
void subs_vec_scal(double x[], double scal, double y[], int n){
    int i;

    for(i = 0; i < n; i++){
        y[i] = x[i] - scal;
    }
}

/*
Función para multiplicar un vector x por un escalar scal.
El resultado se guarda en el vector y.
*/
void mult_vec_scal(double x[], double scal, double y[], int n){
    int i;

    for(i = 0; i < n; i++){
        y[i] = x[i] * scal;
    }
}

/*
Función que llena un arreglo x con un valor val.
*/
void fill_array_x(double x[], double val, int n){
    int i;

    for(i = 0; i < n; i++){
        x[i] = val;
    }
}

/*
Función que suma un vector x con un vector y.
El resultado se guarda en el vector add.
*/
void vector_add(double x[], double y[], double add[], int n){
    int i;

    for(i=0; i<n; i++){
        add[i] = x[i] + y[i];
    }
}

/*
Función que resta un vector x con un vector y.
El resultado se guarda en el vector subs.
*/
void vector_subs(double x[], double y[], double subs[], int n){
    int i;

    for(i=0; i<n; i++){
        subs[i] = x[i] - y[i];
    }
}

/*
Función que calcula la derivada del problema cuadrático.
Toma como inputs un vector x, una matriz A, un escalar alpha 
(ordenada al origen de la demanda), un vector gamma (cada elemento
es el costo de una empresa).
El resultado se guarda en un vector dfx.
*/
void df(double x[], double A[][MAXCOLS], double dfx[], double alpha, double gamma[], int n){
    double x_h[MAXCOLS];
    double gamma_h[MAXCOLS];

    // x'Q
    vec_mat_mul(x, A, x_h, n);

    // gamma - alpha
    subs_vec_scal(gamma, alpha, gamma_h, n);

    // x'Q + (alpha - gamma)'
    vector_add(x_h, gamma_h, dfx, n);
}

/*
Función con la que se realiza el descenso en gradiente.
Toma como inputs el número de empresas n, la tasa de
aprendizaje lr, el valor de la ordenada al origen de la 
función de demanda alpha, el valor de la pendiente de la función 
de demanda beta, y un vector gamma que contiene los costos
marginales de cada empresa.
*/
void gd(int n, double lr, double alpha, double beta, double gamma[]){
    double Q[MAXROWS][MAXCOLS];
    double cur_x[MAXCOLS];
    int epoch = 0;
    int prev_x[MAXCOLS];

    fill_matrix_Q(Q, n, beta);
    fill_array_x(cur_x, 0.5, n); // Se inicializa un vector x de tamaño n con valores de 0.5.

    while(epoch < MAXITERS){
        double aux_df[MAXCOLS];
        double aux_mul[MAXCOLS];

        // Copiamos la x(t) a x(t-1). 
        memcpy(prev_x, cur_x, n*sizeof(double));

        // Se calcula el gradiente de x(t-1).
        df((void*)prev_x, Q, aux_df, alpha, gamma, n);

        // Se multiplica el gradiente por la tasa de aprendizaje.
        mult_vec_scal(aux_df, lr, aux_mul, n);

        // Se resta lo obtenido anteriormente a x(t)
        // y se asigna a x(t).
        vector_subs(cur_x, aux_mul, cur_x, n);

        epoch += 1;
    }

    for(int i = 0; i < n; i++){
        if(i != (n-1)){
            printf("%f, ", cur_x[i]);
        } else{
            printf("%f ", cur_x[i]);
        }
    }
}

int main(int argc, char *argv[]){
    int n = atoi(argv[1]);
    double lr = atof(argv[2]);
    double alpha = atof(argv[3]);
    double beta = atof(argv[4]);
    double gamma = atof(argv[5]);

    double X[n];
    fill_array_x(X, gamma, n);

    printf("El equilibrio de Nash-Cournot es:\n");
    gd(n, lr, alpha, beta, X);

    return 0;
}
