#!/bin/bash 
COUNTER=10
echo "tiempo,renglones,columnas,threads">resultados.csv
while [  $COUNTER -le 200 ]; do
    ./GeneraMatrices.out $COUNTER $COUNTER A.txt
    ./GeneraMatrices.out $COUNTER $COUNTER B.txt
    ./multip_paralela.out $COUNTER $COUNTER $COUNTER $COUNTER 4
    ./multip_secuencial2.out $COUNTER $COUNTER $COUNTER $COUNTER
    if [ $COUNTER -lt 1000 ];then
       let COUNTER=$COUNTER+10
       else if [ $COUNTER -ge 10000 ];then
	       let COUNTER=$COUNTER+1000
	       else
		   let COUNTER=$COUNTER+100
	    fi
    fi
done
