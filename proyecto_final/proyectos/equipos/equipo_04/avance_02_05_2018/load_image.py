import torch
import numpy as np

#Importamos Image del modulo PIL para poder convertir imagenes a un arreglo numpy
from PIL import Image

#Cargamos imagen y convertimos a arreglo de numpy
img = Image.open('naturaleza.jpg')
arr = np.array(img)

#Convertimos de arrego de numpy a tensor de pytorch
matriz_color = torch.from_numpy(arr)
matriz_color = matriz_color.type(torch.float32)

#Si cuda esta disponible
if torch.cuda.is_available():

    #Instanciamos el device de cuda
    device = torch.device("cuda")

    #Transferimos de memoria local a memoria de GPU
    matriz_color_cuda = matriz_color.to(device)                       # Copiamos el tensor a cuda

    #Sacamos las tonalidades RGB
    matriz_color_cuda = matriz_color_cuda[:,:,0:3]

    #Declaramos los pesos para poder hacer la conversion a blanco y negro como tensores de un elemento dentro de la memoria
    #del GPU
    r_c = torch.tensor([0.2989],dtype=torch.float32,device=device)
    g_c = torch.tensor([0.587],dtype=torch.float32,device=device)
    b_c = torch.tensor([0.114],dtype=torch.float32,device=device)

    #Hacemos la operacion como tal de conversion a blanco y negro de forma paralela con cuda
    matriz_blanco_negro = r_c*matriz_color_cuda[:,:,0] + g_c*matriz_color_cuda[:,:,1] + g_c*matriz_color_cuda[:,:,2]

    #Transferimos matriz blanco y negro de la memoria de cuda a la memoria del CPU
    matriz_blanco_negro_cpu = matriz_blanco_negro.to("cpu", torch.double)       # ``.to`` can also change dtype together!

    #Guardamos esta matriz en un archivo separado por coma
    np.savetxt("foo.csv", matriz_blanco_negro_cpu, fmt='%d', delimiter=",")

