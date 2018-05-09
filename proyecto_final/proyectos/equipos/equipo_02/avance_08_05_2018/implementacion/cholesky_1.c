{\rtf1\ansi\ansicpg1252\cocoartf1561\cocoasubrtf400
{\fonttbl\f0\fnil\fcharset0 Menlo-Regular;}
{\colortbl;\red255\green255\blue255;\red0\green0\blue0;\red255\green255\blue255;}
{\*\expandedcolortbl;;\csgray\c0;\csgray\c100000;}
\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\pard\tx560\tx1120\tx1680\tx2240\tx2800\tx3360\tx3920\tx4480\tx5040\tx5600\tx6160\tx6720\pardirnatural\partightenfactor0

\f0\fs22 \cf2 \cb3 \CocoaLigature0 #include <stdio.h>\
#include <stdlib.h>\
#include <math.h>\
#include <omp.h>\
#include <time.h>\
void cholesky(float **A,float **L,int n);\
void printm(float **M,int n);\
\
\
int main(int argc, char **argv)\{\
/*[Tiempo] */\
\
double time_p = 0;\
\
\
/*[Test] Values */\
float tm[25] = \{29,5,9,5,6,5,29,10,8,7,9,10,23,4,5,5,8,4,26,6,6,7,5,6,30\};\
/*float tm[9] = \{25, 15, -5,15, 18,  0,-5,  0, 11\};*/\
int n =5;\
\
/*Matrix A and Matrix L */\
float  *mA = (float *)malloc(n*n*sizeof(float));\
float  *mL = (float *)calloc(n*n,sizeof(float));\
\
float **A;\
float **L;\
\
/* Assign values to the array mA*/\
int i,j, count = 0;\
for (i = 0;i<n;i++)\
        for (j = 0;j < n ;j++)\
                *(mA + i*n + j) = tm[count++];\
/* Print the matrix values */\
\
A = &mA;\
L = &mL;\
\
printf("A =\\n");\
printm(A,n);\
clock_t start = clock();\
cholesky(A,L,n);\
clock_t end = clock();\
\
time_p = (double)(end-start);\
printf("tiempo: %f\\n",time_p);\
printf("L =\\n");\
printm(L,n);\
free(mA);\
free(mL);\
return 0;\
\}\
\
\
\
void cholesky(float **A,float **L,int n)\{\
\
int k,j,i,l;\
float s=0;\
int thr =1;\
\
for(j=0;j<n;j++)\{\
        s=0;\
        for(k=0;k<j;k++)\
                s+= *(*L+j*n+k)* *(*L+j*n+k);\
        /*printf("A:%f\\n s: %f\\n",*(*A+j*n+j),s);*/\
        *(*L+j*n+j) = sqrt( *(*A+j*n+j) -s);\
        thr = n-(j+1);\
        #pragma omp parallel for num_threads(thr) private(i,l,s)\
        for (i=j+1;i<n;i++)\{\
                s =0;\
               /* printf("Thread: %d de %d para calcular L(%d,%d)\\n",omp_get_thread_num()+1,omp_get_num_threads(),i,j);*/\
                for (l=0;l<j;l++)\{\
			/*printf("s: %f ,",s);\
			printf("(%d, %d,%d,_ %d_,_%d_,_%f_,_%f_) ",i,j,l,i*n+l,j*n+l,*(*L+i*n+l),*(*L+j*n+k));*/\
                        s+= *(*L+i*n+l) * *(*L+j*n+l);\
                \}\
		/*printf("i: %d, l: %d ,s: %f :",i,l,s);*/\
                *(*L+i*n+j) = (1.0/ *(*L+j*n+j) )*( *(*A+i*n+j) - s);\
		/*printf("%f \\n",*(*L+i*n+j));*/\
        \}\
\}\
\
\}\
\
/*Print matrix values in format | | */\
void printm(float **M,int n)\{\
int i,j;\
for (i=0; i<n;i++)\{\
        printf("| ");\
        for (j=0;j<n;j++)\
                printf("%f\\t",*(*M+i*n+j));\
        printf("|\\n");\}\
\
\}}