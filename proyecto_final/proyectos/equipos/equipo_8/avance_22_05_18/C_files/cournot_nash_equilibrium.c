#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXROWS 500
#define MAXCOLS 500
#define MAXITERS 10000

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


void fill_matrix_Q(double Q[][MAXCOLS],int n, int beta){
    // double Q[n][n];
    int i, j;

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(i == j){
                Q[i][j] = 2*beta;
            } else{
                Q[i][j] = beta;
            }
            // printf("Q[%i][%i] = %f\n",i,j, Q[i][j]);
        }
    }
    // return Q;
}

void transpose(double A[][MAXCOLS], double At[][MAXCOLS], int n){
    int i, j;

    for (i = 0; i<n; i++){
        for (j = 0; j<n; j++){
            At[i][j] = A[j][i];
            // printf("Q[%i][%i] = %f\n",i,j, A[i][j]);
        }
    }
}

void mat_mul(double A[][MAXCOLS], double B[][MAXCOLS], double C[][MAXCOLS], int n){
    int i, j, k;

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            C[i][j] = 0;
            // printf("Q[%i][%i] = %f\n",i,j, C[i][j]);
        }
    }

    for(i = 0; i<n; i++){
        for(j = 0; j<n; j++){
            for(k = 0; k<n; k++){
                C[i][j] += A[i][k]* B[k][j];
            }
            // printf("Q[%i][%i] = %f\n",i,j, C[i][j]);
        }
    }
}

void vec_mat_mul(double x[], double A[][MAXCOLS], double y[], int n){
    int i, j;

    for(i = 0; i<n; i++){
        y[i] = 0;
        for(j = 0; j<n; j++){
            y[i] += A[i][j] * x[j];
        }
        // printf("%f\n", y[i]);
    }
}

void subs_vec_scal(double x[], double scal, double y[], int n){
    int i;

    for(i = 0; i < n; i++){
        y[i] = x[i] - scal;
        // printf("%f\n", y[i]);
    }
}

void mult_vec_scal(double x[], double scal, double y[], int n){
    int i;

    for(i = 0; i < n; i++){
        y[i] = x[i] * scal;
        // printf("%f\n", y[i]);
    }
}

void fill_array_x(double x[], double val, int n){
    int i;

    for(i = 0; i < n; i++){
        x[i] = val;
        // printf("%f\n", x[i]);
    }
}

void vector_add(double x[], double y[], double add[], int n){
    int i;

    for(i=0; i<n; i++){
        add[i] = x[i] + y[i];
        // printf("%f\n", add[i]);
    }
}

void vector_subs(double x[], double y[], double subs[], int n){
    int i;

    for(i=0; i<n; i++){
        subs[i] = x[i] - y[i];
        // printf("%f\n", add[i]);
    }
}

void df(double x[], double A[][MAXCOLS], double dfx[], double alpha, double gamma[], int n){
    double x_h[MAXCOLS];
    double gamma_h[MAXCOLS];
    // double dfx[MAXCOLS];
    vec_mat_mul(x, A, x_h, n);
    subs_vec_scal(gamma, alpha, gamma_h, n);
    vector_add(x_h, gamma_h, dfx, n);
    // printf("%f\n", dfx[1]);
}

void gd(int n, double lr, double alpha, double beta, double gamma[]){
    double Q[MAXROWS][MAXCOLS];
    double cur_x[MAXCOLS];
    int epoch = 0;
    int prev_x[MAXCOLS];

    fill_matrix_Q(Q, n, beta);
    fill_array_x(cur_x, 0.5, n);

    while(epoch < MAXITERS){
        double aux_df[MAXCOLS];
        double aux_mul[MAXCOLS];
        // prev_x = cur_x;
        memcpy(prev_x, cur_x, n*sizeof(double));

        df((void*)prev_x, Q, aux_df, alpha, gamma, n);
        mult_vec_scal(aux_df, lr, aux_mul, n);
        // cur_x = cur_x - aux_mul;
        vector_subs(cur_x, aux_mul, cur_x, n);

        epoch += 1;
        // if()
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
    // int n = 10;
    int n = atoi(argv[1]);
    double lr = atof(argv[2]);
    double alpha = atof(argv[3]);
    double beta = atof(argv[4]);
    double gamma = atof(argv[5]);

    // double Q[MAXROWS][MAXCOLS];
    // double C[MAXROWS][MAXCOLS];
    // double x[2] = {8.,8.};
    // double y[n];
    // fill_matrix_Q(Q, n, 2);
    // mat_mul(Q,Q,C,n);
    // vec_mat_mul(x,Q,y,n);
    // mult_vec_scal(x,2,y,2);

    // Si no sirve argv, usar estas dos líneas:
    double X[n];
    fill_array_x(X, gamma, n);

    // vector_add(x,X,y,n);
    // df(x, Q, y, 50, X, n);
    //
    // for(int i = 0; i<n; i++){
    //     printf("%f\n", y[i]);
    // }

    // gd(int n, double lr, double alpha, double beta, double gamma[])

    // gd(n, 0.0004, 50.0, 2.0, X);
    printf("El equilibrio de Nash-Cournot es:\n");
    gd(n, lr, alpha, beta, X);


    return 0;
}
