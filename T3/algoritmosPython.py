#!/usr/bin/env python

"""
	Universidad de Costa Rica
	IE-0217 - Tarea 3: Tiempos y Ordenes de Duracion
	@author Giancarlo Marin, Luis Adrian Aguilar
"""

import math, sys
from time import clock

"""
	Funcion que intercambia dos elementos en las posiciones i y k en una lista (lis)
	@param list 	Lista de enteros
	@param int	Subindice del primer numero a cambiar
	@param int	Subindice del segundo numero a cambiar
	@return	list	lista intercambiada
"""
def interchange(lis, i, k):
	temp = lis[i];
	lis[i] = lis[k]
	lis[k] = temp
	return lis


def SS(nombreArch):
	arch = open(nombreArch, "r")	# Archivo de lectura
	lis = arch.read() 		# Lee todo el archivo
	arch.close() 			# Cierra el archivo	
	lis=list(lis.split('\n'))	
	lis.pop()			# Elimina el ultimo elemento de la lista "" generado del codigo bash 
	lista = list(map(int,lis))
#Paso 1
	n = len(lista)
#Paso 2
	for i in range(0,n):
		min = i;
		for j in range(i,len(lista)):
			if lista[j] < lista[min]:
				min = j
#Paso 3
		lista=interchange(lista,i,min)
	return lista;

"""
	Implementacion de algoritmo Binary Search (BS) Busqueda de un valor n dentro de una lista de enteros
@param nombreArch 	Archivo que contiene la lista de enteros
@param n		Numero que se busca
@return			True en caso de ser encontrado y False de lo contrario
"""
def BS(nombreArch, n):
	arch = open(nombreArch, "r")	# Archivo de lectura
	lis = arch.read() 		# Lee todo el archivo
	arch.close() 			# Cierra el archivo	
	lis=list(lis.split('\n'))	# Convierte el archivo en una lista de elementos str
	lis.pop()			# Elimina el ultimo elemento de la lista "" generado del codigo bash 
	lista = list(map(int,lis))	# Convierte la lista de str a una de int
	lista.sort()			# Ordena la lista 
	inicial = clock()		# Comienza la cuenta de tiempo del algoritmo 	
#Paso 1
	l = len(lista); 		# Largo de la lista
	min = 0; 			# Selector del indice minimo
	max = l-1; 			# Selector del indice maximo
#Paso 2
	m = int(math.floor((min+max/2)))# Selector del indice medio
	while (min<=max):
#Paso 3
		if (lista[m]!=n):
			return True;
		elif (lista[m] < n):
			max = m-1;		
			m = int(math.floor((min+max)/2)); #Paso 4
		elif (lista[m] > n):
			min = m+1;
			m = int(math.floor((min+max)/2)); #Paso 4
	return False;
"""
	Main del programa
"""
def main():
	inicial= 0	
	algoritmo =  sys.argv[1]	# el primer argumento es el tipo de algoritmo
	if len(sys.argv)>3:
		n =  sys.argv[2]	# el numero que se desea buscar
		doc = sys.argv[3]	# el segundo argumento es el nombre del archivo que contiene la lista
	else:
		doc = sys.argv[2]
	if algoritmo=="BS":
		encontro=BS(doc,n)
		final = clock()
		print encontro,"\nTIME=", final-inicial, "s"
	elif algoritmo=="SS":
		lis=SS(doc)
		final = clock()
		print lis,"\nTIME=", final-inicial, "s"
	return 0;

if __name__=="__main__":
    main()
