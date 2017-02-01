# -*- coding: utf-8 -*-
import math, sys, time

args = sys.argv[1:]#lee argumentos pasados al ejecutable
algoritmo =  args[0]#el primer argumento es el tipo de algoritmo
archivo =  args[1]#el segundo argumento es el nombre del archivo que contiene la lista

print algoritmo
print archivo


doc = open('lista.txt', 'r')


listaInt = []
 
lis = doc.read() # GUARDO LINEAS EN VARIABLE cad
 
lista = list(lis.split(' ')) # TRANSFORMO A LISTA

print(lista)




l = len(lista);
min = 0;
max = l-1;
y = (min+max/2)
m = int(math.floor(y))


print m;
print l;

n = input('Escoja un numero')

while (l!=0):
	
	if lista[m]==n:
		print m;
		

	elif lista[m] > n:
		max = m-1;
		lista = lista[min:max];
		l = len(lista);
		m = int(math.floor((min+max)/2));
	

	elif lista[m] < n:
		min = m+1;
		lista = lista[min:max];
		l = len(lista);
		m = int(math.floor((min+max)/2)); 




	elif lista(m) < n:
		min = m+1;
		lista = lista[min:max];
		l = lista.lenght;
		m = floor((min+max)/2); 

"""

