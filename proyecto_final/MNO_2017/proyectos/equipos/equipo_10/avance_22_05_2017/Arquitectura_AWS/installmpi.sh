#!/bin/bash

sudo apt-get update -y
sudo apt-get install -y build-essential
sudo apt-get install -y nano
sudo apt-get install -y man
sudo apt-get install -y openssh-server

sudo groupadd mpi_user

sudo useradd mpi_user -g mpi_user -m -s /bin/bash

wget https://www.open-mpi.org/software/ompi/v2.0/downloads/openmpi-2.0.2.tar.gz

sudo tar xf openmpi-2.0.2.tar.gz -C /opt/

cd /opt

sudo chown -hR mpi_user:mpi_user openmpi-2.0.2

mkdir -p /var/run/sshd

cd /opt/openmpi-2.0.2

sudo ./configure --prefix=/opt/openmpi-2.0.2 --enable-orterun-prefix-by-default -with-sge

sudo make all install

