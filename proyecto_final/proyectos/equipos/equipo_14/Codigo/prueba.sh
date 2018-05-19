#!/bin/bash
#Cargamos las llaves para aws
export MACHINE_DRIVER=amazonec2
export AWS_ACCESS_KEY_ID=
export AWS_SECRET_ACCESS_KEY=
export AWS_DEFAULT_REGION=us-west-2

docker-machine create --amazonec2-instance-type=t2.micro nodosecuencial 
docker-machine ssh nodosecuencial sudo usermod -aG docker ubuntu
sudo docker-machine ssh nodosecuencial git clone https://github.com/patricio-hdz/ProyectoFinal.git
