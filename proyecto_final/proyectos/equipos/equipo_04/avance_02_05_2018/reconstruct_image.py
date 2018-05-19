#Importmos modulos para manipulacion de imagenes
from PIL import Image, ImageDraw
from numpy import genfromtxt

#Cargamos archivo csv en memoria, convertimos a imagen y guardamos
g = open('foo.csv','r')
temp = genfromtxt(g, delimiter = ',')
im = Image.fromarray(temp).convert('RGB')
im.save('gray.jpg')

