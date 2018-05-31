from PIL import Image, ImageDraw
from numpy import genfromtxt

g = open('archivo.csv','r')
temp = genfromtxt(g, delimiter = ',')
im = Image.fromarray(temp).convert('RGB')
im.show()

