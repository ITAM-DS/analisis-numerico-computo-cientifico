{\rtf1\ansi\ansicpg1252\cocoartf1561\cocoasubrtf400
{\fonttbl\f0\fnil\fcharset0 Menlo-Regular;}
{\colortbl;\red255\green255\blue255;\red0\green0\blue0;\red255\green255\blue255;}
{\*\expandedcolortbl;;\csgray\c0;\csgray\c100000;}
\margl1440\margr1440\vieww28600\viewh16600\viewkind0
\pard\tx560\tx1120\tx1680\tx2240\tx2800\tx3360\tx3920\tx4480\tx5040\tx5600\tx6160\tx6720\pardirnatural\partightenfactor0

\f0\fs22 \cf2 \cb3 \CocoaLigature0 #include <stdio.h>\
#include <stdlib.h>\
#include <math.h>\
#include <time.h>\
 \
double *cholesky(double *A, int n) \{\
    double *L = (double*)calloc(n * n, sizeof(double));\
    if (L == NULL)\
        exit(EXIT_FAILURE);\
 \
    for (int i = 0; i < n; i++)\
        for (int j = 0; j < (i+1); j++) \{\
            double s = 0;\
            for (int k = 0; k < j; k++)\
                s += L[i * n + k] * L[j * n + k];\
            L[i * n + j] = (i == j) ?\
                           sqrt(A[i * n + i] - s) :\
                           (1.0 / L[j * n + j] * (A[i * n + j] - s));\
        \}\
 \
    return L;\
\}\
 \
void show_matrix(double *A, int n) \{\
    for (int i = 0; i < n; i++) \{\
        for (int j = 0; j < n; j++)\
            printf("%2.5f ", A[i * n + j]);\
        printf("\\n");\
    \}\
\}\
 \
int main() \{\
    int n = 5;\
    double time_p=0;\
    double m1[] = \{29,5,9,5,6,\
					5,29,10,8,7,\
					9,10,23,4,5,\
					5,8,4,26,6,\
					6,7,5,6,30\};\
\
    clock_t start = clock();\
    double *c1 = cholesky(m1, n);\
    clock_t end = clock();\
    show_matrix(c1, n);\
    time_p = (double)(end-start);\
    printf("Tiempo: %f\\n",time_p);\
    free(c1);\
 \
    n = 4;\
    double m2[] = \{18, 22,  54,  42,\
                   22, 70,  86,  62,\
                   54, 86, 174, 134,\
                   42, 62, 134, 106\};\
    double *c2 = cholesky(m2, n);\
    show_matrix(c2, n);\
    free(c2);\
 \
    return 0;\
\}\
}