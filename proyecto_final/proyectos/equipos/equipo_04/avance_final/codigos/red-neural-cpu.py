#Importamos modulos de pytorch
import torch
import torchvision
import torchvision.transforms as transforms

#Importamos modulo de visualizacion de matplotlib y numpy
import matplotlib.pyplot as plt
import numpy as np


#Importamos el modulo de redes neuronales de pytorch y funciones adicionales
import torch.nn as nn
import torch.nn.functional as F

#Importamos el modulo de optimizacion de pytorch
import torch.optim as optim


#Hacemos un conjunto de trasnformaciones 
#1. Transformamos a tensor
#2. Normalizamos las imagenes
transform = transforms.Compose(
    [transforms.ToTensor(),
     transforms.Normalize((0.5, 0.5, 0.5), (0.5, 0.5, 0.5))])


#Descargamos el dataset de entrenamiento precaragdo de pytorch de CIFAR10 y guardamos en carpeta data
entrenamiento = torchvision.datasets.CIFAR10(root='./data', train=True,
                                        download=False, transform=transform)

#Cargamos en memoria las imagenes de entrenamiento, definimos tamanio del lote = 4 y cantidad de paralelismo = 2
trainloader = torch.utils.data.DataLoader(entrenamiento, batch_size=5,
                                          shuffle=False, num_workers=2)

#Descargamos el dataset de prueba de pytorch de CIFAR10 y lo guardamos en carpeta data
prueba = torchvision.datasets.CIFAR10(root='./data', train=False,
                                       download=False, transform=transform)

#Caragmos en memoria los datos de prueba
testloader = torch.utils.data.DataLoader(prueba, batch_size=5,
                                         shuffle=False, num_workers=2)

#Definimos una tupla con distintas categorias
categorias = ('plane', 'car', 'bird', 'cat',
           'deer', 'dog', 'frog', 'horse', 'ship', 'truck')




#Definimos una funcion que nos muestre un conjunto de imagenes y que tambien la guarde en el directorio local
def mostrar_imagen(img):
    img = img / 2 + 0.5     
    npimg = img.numpy()
    plt.imshow(np.transpose(npimg, (1, 2, 0)))
    plt.savefig('myfig.png')


# get some random training images
#Obtenemos imagenes aleatorias de entrenamiento para hacer una evaluacion
dataiter = iter(trainloader)

#Obtenemos las imagenes y las etiquetas de cada imagen
images, labels = dataiter.next()

#Llamamos la funcion mostrar_imagen para que nos muestre las imagenes selecciondas
mostrar_imagen(torchvision.utils.make_grid(images))

#Imprimimos las etiquetas para verificar que correspondan a las imagenes seleccionadas
print(' '.join('%5s' % categorias[labels[j]] for j in range(4)))



#Construimos la clase Net que hereda de nn.Module que contiene la estructura base de una red neuronal

class Net(nn.Module):
    def __init__(self):
    	#Mandamos llamar al constructor del padre
        super(Net, self).__init__()
        #Asignamos como atributo de la clave una red neuronal convolucional
        #torch.nn.Conv2d(in_channels, out_channels, kernel_size, stride=1, padding=0, dilation=1, groups=1, bias=True)
        #in_channels (int) – Number of channels in the input image
        #out_channels (int) – Number of channels produced by the convolution
		#kernel_size (int or tuple) – Size of the convolving kernel

        self.conv1 = nn.Conv2d(3, 50, 5)
        self.pool = nn.MaxPool2d(2, 2)
        self.conv2 = nn.Conv2d(50, 8, 5)        
        self.fc1 = nn.Linear(8 * 5 * 5, 120)
        self.fc2 = nn.Linear(120, 84)
        self.fc3 = nn.Linear(84, 10)
        #self.fc1 = nn.Linear(8 * 5 * 5, 100)
        #self.fc2 = nn.Linear(100, 84)        
        #self.fc3 = nn.Linear(84, 50)
        #self.fc4 = nn.Linear(50, 40)
        #self.fc5 = nn.Linear(40, 10)



    def forward(self, x):
    	#Definimos funciones de activacion RELU de la red neuronal 
        x = self.pool(F.relu(self.conv1(x)))
        x = self.pool(F.relu(self.conv2(x)))
        #x = self.pool(F.relu(self.conv3(x)))
        x = x.view(-1, 8 * 5 * 5)
        x = F.relu(self.fc1(x))
        x = F.relu(self.fc2(x))
        x = F.relu(self.fc3(x))
        #x = F.relu(self.fc4(x))        
        #x = F.sigmoid(self.fc1(x))
        #x = F.sigmoid(self.fc2(x))
        #x = self.fc5(x)
        return x

#Instanciamos la red neuronal definida previamente

#device = torch.device("cuda:0" if torch.cuda.is_available() else "cpu")

net = Net()
#net.to(device)

#Definimos criterion y optimizer que son muy relevantes para la optimizacion de la red
criterion = nn.CrossEntropyLoss()
optimizer = optim.SGD(net.parameters(), lr=0.001, momentum=0.9)


#Etapa de entrenamiento de la red neuronal
#Definimos cantidad de epochs o pasadas al dataset completo
#Mientras mayor sea la cantidad de epochs mejor sera la prediccion, aunque se requerira mayor capacidad de computo
for epoch in range(20):

    running_loss = 0.0
    for i, data in enumerate(trainloader, 0):

        #Obtenemos la imagen y su categoria
        inputs, labels = data
        inputs, labels = inputs.to(device), labels.to(device)
        #print(type(inputs))
        #print(inputs.size())
        #print(inputs)
        #print(labels)
        #print(inputs)

        #Inicializamos el gradiente
        optimizer.zero_grad()

        # forward + backward + optimize
        outputs = net(inputs)
        loss = criterion(outputs, labels)
        loss.backward()
        optimizer.step()

        #Imprimimos desempenio del modelo en epoch correspondiente
        running_loss += loss.item()
        if i % 2000 == 1999:    # print every 2000 mini-batches
            print('[%d, %5d] loss: %.3f' %
                  (epoch + 1, i + 1, running_loss / 2000))
            running_loss = 0.0

print('Entrenamiento Finalizado')


#Evaluacion de la red neuronal: 

#Seleccionamos una muestra al azar
dataiter = iter(testloader)
images, labels = dataiter.next()


#Mostramos las imagenes y observamos sus categorias
mostrar_imagen(torchvision.utils.make_grid(images))
print('categorias reales: ', ' '.join('%5s' % categorias[labels[j]] for j in range(4)))



#Predecimos las categorias con la red neuronal entrenada
outputs = net(images)


_, predicted = torch.max(outputs, 1)

#Imprimimos las predicciones
print('Prediccion: ', ' '.join('%5s' % categorias[predicted[j]]
                              for j in range(4)))

correct = 0
total = 0
with torch.no_grad():
    for data in testloader:
        images, labels = data
        outputs = net(images)
        _, predicted = torch.max(outputs.data, 1)
        total += labels.size(0)
        correct += (predicted == labels).sum().item()

print('Exactitud de la red en 1000 imagenes de prueba : %d %%' %(
    100 * correct / total))
