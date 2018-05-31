#!/bin/bash

python gen_mat.py 50
gcc chol.c -o chol.out -lm
awk '{ORS=(NR%50?FS:RS)}1' matrizSPD.txt > MATRIZ.txt
./chol.out < matrizSPD.txt > fact.txt
