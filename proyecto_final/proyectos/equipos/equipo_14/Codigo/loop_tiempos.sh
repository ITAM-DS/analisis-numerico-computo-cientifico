#!/bin/bash 
echo "tiempo,renglones,columnas,threads">resultados.csv
./multip_secuencial2.out 1000 1000 1000 1000 >>resultados.csv
for i in {2..32}; do
	./GeneraMatrices.out 1000 1000 A.txt
	./GeneraMatrices.out 1000 1000 B.txt
	./multip_paralela.out 1000 1000 1000 1000 $i >>resultados.csv
done
