{\rtf1\ansi\ansicpg1252\cocoartf1561\cocoasubrtf200
{\fonttbl\f0\fswiss\fcharset0 Helvetica;\f1\fmodern\fcharset0 Courier;}
{\colortbl;\red255\green255\blue255;\red0\green0\blue0;\red250\green251\blue252;}
{\*\expandedcolortbl;;\cssrgb\c0\c0\c0;\cssrgb\c98431\c98824\c99216;}
\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\pard\tx566\tx1133\tx1700\tx2267\tx2834\tx3401\tx3968\tx4535\tx5102\tx5669\tx6236\tx6803\pardirnatural\partightenfactor0

\f0\fs24 \cf0 1.- El uso de las \'93\'94 en un include indica que se est\'e1n utilizando librer\'edas definidas por el usuario, mientras que al usar <> se est\'e1n utilizando librer\'edas del sistema.\
Static en la definici\'f3n de variables externas sirve para limitar el alcance de una variable \'fanicamente al archivo en el cual est\'e1 contenido.\
\
2.- BLAS (Basic Linear Algebra Subprogram) es un conjunto de rutinas para realizar operaciones b\'e1sicas entre vectores y matrices. Se divide en niveles dependiendo de los elementos que operan, en el nivel 1 las operaciones se realizan entre escalares y vectores, tanto escalar-escalar, escalar-vector y vector-vector. El uso de las librer\'edas es libre e inclusive se puede utilizar librer\'edas optimizadas para hardware espec\'edfico. CBLAS es la implementaci\'f3n en C de las rutinas de BLAS.\
\
LAPACK (Linear Algebra PACKage) es una serie de rutinas enfocadas a resolver diferentes problemas como ecuaciones lineales, soluciones con m\'ednimos cuadrados para sistemas lineales de ecuaciones, problemas de eigenvectores, SVP. Tambi\'e9n contiene rutinas para factorizaci\'f3n de matrices en precisi\'f3n y doble precisi\'f3n. Las rutinas est\'e1n escritas de forma que se hagan llamado a BLAS para optimizar los procesos y c\'e1lculos.\
\
ATLAS (Automatically Tuned Linear Algebra Software): es un proyecto que se enfoca en aprovechar ls rutinas de BLAS y las implementa en C y Fortran 77 co la finalizad de ofrecer rutinas optimizadas para el hardware utilizado.\
\
4.- La sub rutina dgemm() realiza la operaci\'f3n con matrices 
\f1 \cf2 \cb3 \expnd0\expndtw0\kerning0
\outl0\strokewidth0 \strokec2   C := alpha*op( A )*op( B ) + beta*C. Los par\'e1metros que cacepta son :\
\
TRANSA: c\
TRANSB: zv\
M: n\'famero de filas en A\
N: n\'famero de filas en B\
K: n\'famero de columnas\
ALPHA: Precisi\'f3n 12\
}