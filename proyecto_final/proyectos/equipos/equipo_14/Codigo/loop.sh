#!/bin/bash 
echo "tiempo,renglones,columnas,threads">resultados_general.csv
for i in {2..8}; do
    COUNTER=20
    while [  $COUNTER -le 1100 ]; do
	./GeneraMatrices.out $COUNTER $COUNTER C.txt
	./GeneraMatrices.out $COUNTER $COUNTER D.txt
	./multip_paralela.out $COUNTER $COUNTER $COUNTER $COUNTER $i >>resultados_general.csv
	./multip_secuencial.out $COUNTER $COUNTER $COUNTER $COUNTER >>resultados_general.csv
	if [ $COUNTER -lt 1000 ];then
	    let COUNTER=$COUNTER+20
	else if [ $COUNTER -ge 10000 ];then
		 let COUNTER=$COUNTER+1000
	     else
		 let COUNTER=$COUNTER+100
	     fi
	fi
	rm C.txt
	rm D.txt
    done
done


