# Docker-machine
# Equipo 9

# Creamos variables globales
export MACHINE_DRIVER=amazonec2
export AWS_ACCESS_KEY_ID=AKIAJLGCVQR763WQ23TQ
export AWS_SECRET_ACCESS_KEY=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
export AWS_DEFAULT_REGION=us-west-1
export AWS_VPC_ID=vpc-0dfe5569
export AWS_INSTANCE_TYPE=g2.2xlarge
export AWS_AMI=ami-2afbde4a

#Creamos instancia con docker-machine 
docker-machine create cuda 

#Nos conectamos e instalamos los drives de Nvidia
docker-machine ssh cuda
sudo apt-key adv --fetch-keys http://developer.download.nvidia.com/compute/cuda/repos/ubuntu1604/x86_64/7fa2af80.pub
sudo sh -c 'echo "deb http://developer.download.nvidia.com/compute/cuda/repos/ubuntu1604/x86_64 /" > /etc/apt/sources.list.d/cuda.list'
sudo apt-get update && sudo apt-get install -y --no-install-recommends linux-headers-generic dkms cuda-drivers

# Instalamos los dockers
wget -P /tmp https://github.com/NVIDIA/nvidia-docker/releases/download/v1.0.1/nvidia-docker_1.0.1-1_amd64.deb
sudo dpkg -i /tmp/nvidia-docker*.deb && rm /tmp/nvidia-docker*.deb

# Reseteamos la maquina
exit
docker-machine restart cuda
