#!/bin/bash
#Cargamos las llaves para aws
export MACHINE_DRIVER=amazonec2
export AWS_ACCESS_KEY_ID=
export AWS_SECRET_ACCESS_KEY=
export AWS_DEFAULT_REGION=us-west-2
export AWS_INSTANCE_TYPE=m4.2xlarge
export AWS_SUBNET_ID=subnet-c321398b
export AWS_VPC_ID=vpc-1e4bca67

docker-machine create nodo
docker-machine ssh nodo sudo usermod -aG docker ubuntu
sudo docker-machine ssh nodo git clone https://github.com/patricio-hdz/ProyectoFinal.git
sudo docker-machine ssh nodo sudo apt install -y build-essential
sudo docker-machine ssh nodo gcc -Wall -fopenmp ProyectoFinal/Codigo/GeneraMatrices.c -o GeneraMatrices.out
sudo docker-machine ssh nodo gcc -Wall -fopenmp ProyectoFinal/Codigo/multip_secuencial.c ProyectoFinal/Codigo/funciones.c -o multip_secuencial.out
sudo docker-machine ssh nodo gcc -Wall -fopenmp ProyectoFinal/Codigo/multip_paralela.c ProyectoFinal/Codigo/funciones.c -o multip_paralela.out
sudo docker-machine ssh nodo bash ProyectoFinal/Codigo/loop_tiempos.sh
sudo docker-machine ssh nodo bash ProyectoFinal/Codigo/loop.sh
sudo docker-machine ssh nodo curl "https://raw.githubusercontent.com/andreafabrizi/Dropbox-Uploader/master/dropbox_uploader.sh" -o dropbox_uploader.sh
sudo docker-machine ssh nodo chmod +x dropbox_uploader.sh
sudo docker-machine ssh nodo cp resultados.csv resultados_$(date +%Y-%m-%d).csv
sudo docker-machine ssh nodo cp resultados_general.csv resultados_general_$(date +%Y-%m-%d).csv
sudo docker-machine ssh nodo ./dropbox_uploader.sh upload "resultados_general_$(date +%Y-%m-%d).csv" "Resultados_$(date +%Y-%m-%d)/"
sudo docker-machine ssh nodo ./dropbox_uploader.sh upload "resultados_$(date +%Y-%m-%d).csv" "Resultados_$(date +%Y-%m-%d)/"
