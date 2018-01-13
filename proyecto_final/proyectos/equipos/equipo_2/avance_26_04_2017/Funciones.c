#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
typedef struct {
	int m, n;
	double ** e;
} *matriz;
 

matriz nueva_matr(int m, int n)
{
	x->e = malloc(sizeof(double) * m);
	x->e[0] = calloc(sizeof(double), m * n);
	for (int i = 0; i < m; i++)
		x->e[i] = x->e[0] + n * i;
	x->m = m;
	x->n = n;
	return x;
}

/* Calcula la norma de x */

double norma(double x[], int n)
{
	double suma = 0;
	for (int i = 0; i < n; i++) sum += x[i] * x[i];
	return sqrt(suma);
}



/* Calcula la norma de x */

double norma2(double x[], int n)
{
	double suma = 0;
	for (int i = 1; i < n; i++) sum += x[i] * x[i];
	return suma;
}



/* Multiplica matrices */

matriz mult_matriz(matriz x, matriz y)
{
	if (x->n != y->m) return 0;
	matriz r = nueva_matr(x->m, y->n);
	for (int i = 0; i < x->m; i++)
		for (int j = 0; j < y->n; j++)
			for (int k = 0; k < x->n; k++)
				r->e[i][j] += x->e[i][k] * y->e[k][j];
	return r;
}

