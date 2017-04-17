# Avance_17_04_2017

## Trabajo:

### Indivudual

#### Ollin:
Comencé con el desarrollo de un script en C que lea los archivos de grafos y genere la estructura con nodos y aristas.


#### Isabel y Raul:  
Levantamos una máquina en AWS (p2 con ubuntu), para lo que fue necesario mandar un correo a aws pidiendo permiso para levantar este tipo de máquina.   
A ésta máquina, la que le instalamos CUDA con ayuda de [esta referencia](http://docs.aws.amazon.com/AWSEC2/latest/UserGuide/accelerated-computing-instances.html#install-nvidia-driver) y de [esta otra](http://docs.nvidia.com/cuda/cuda-installation-guide-linux/index.html#abstract) y algunas otras ya que no se encontró un tutorial que resolviera todos los problemas que surgen al instalar CUDA en una máquina AMI p2 de amazon. 
Se probó que funcionara CUDA en esta máquina corriendo [un hello world](hello_world.cu) y  [este otro ejemplo](producto.cu)
También leímos [esta referencia](LNCS-ICA3PP2016.pdf) que nos pareció interesante ya que habla de un algoritmo para problemas de combinatoria permutativa basados en estructura de datos IVM (Integer-Vector-Matrix). Aunque nuestro problema es distinto, nos pareció interesante la forma en que los autores abordaron el problema.  


