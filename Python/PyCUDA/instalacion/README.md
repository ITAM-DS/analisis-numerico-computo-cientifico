Lo siguiente se realiza en AWS para un sistema operativo Ubuntu 18.04 en alguna instancia [CUDA capable](https://docs.aws.amazon.com/dlami/latest/devguide/gpu.html).

Siguiendo las instrucciones de [Installing PyCUDA on Linux](https://wiki.tiker.net/PyCuda/Installation/Linux) lo primero es instalar el toolkit NVIDIA CUDA, lo cual se realiza con [estas instrucciones](https://github.com/ITAM-DS/analisis-numerico-computo-cientifico/tree/master/C/extensiones_a_C/CUDA/instalacion#amazon-web-services)


Una vez en la máquina es útil tener un ambiente virtual con [virtualenv](https://virtualenv.pypa.io/en/latest/) en el que se instalarán diferentes dependencias y paquetes incluyendo PyCUDA:

```
sudo apt-get install -y python3-dev python3-pip python3-venv
sudo pip3 install --upgrade pip 
```

usamos [virtualenvwrapper](https://virtualenvwrapper.readthedocs.io/en/latest/) para trabajar en el ambiente virtual de una forma sencilla:

```
user=ubuntu
echo 'export VIRTUALENVWRAPPER_PYTHON=/usr/bin/python3 && source /usr/local/bin/virtualenvwrapper.sh' >> /home/$user/.bash_aliases
#echo "alias python=python3" >> /home/$user/.bash_aliases #<--- check this one
sudo pip3 install virtualenvwrapper
```

Salir y entrar de la instancia.


Creamos el ambiente virtual `pycuda_ve` e instalamos numpy, [jupyterlab](https://jupyterlab.readthedocs.io/en/stable/) en tal ambiente:

```
alias python=python3
mkvirtualenv pycuda_ve
sudo apt-get install -y nodejs
workon pycuda_ve
pip3 install numpy scipy nose mako setuptools
pip3 install jupyter jupyterlab --upgrade
jupyter notebook --generate-config
```



Podemos crear un password para entrar al jupyterlab entrando a python y copiando el resultado de `passwd`:

```
from notebook.auth import passwd
passwd('millave')

'sha1:1f925h17t3p1:....' #esto se utiliza en el siguiente comando de sed
```

```
sed -i "s/#c.NotebookApp.password = .*/c.NotebookApp.password = u'sha1:1f925h17t3p1:....'/" /home/$user/.jupyter/jupyter_notebook_config.py
```


Iniciamos el jupyterlab:

```
jupyter lab --ip=0.0.0.0 --no-browser &
```

Y habilitamos los grupos de seguridad en AWS para que nuestra IP pueda acceder en un browser:

```
<Public DNS IPV4>:8888
```

Instalamos [Pycuda](https://documen.tician.de/pycuda/) en el ambiente virtual `py_ve`:

```
pip3 install pycuda
```

Si se desea utilizar las librerías `CUSOLVER`, `CUBLAS` se recomienda instalar [scikit-cuda](https://scikit-cuda.readthedocs.io/en/latest/)


```
pip3 install scikit-cuda	
```



