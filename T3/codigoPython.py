# -*- coding: utf-8 -*-
import math, sys, time

#print algoritmo
#print archivo

"""
with open(archivo) as f:
	lista = f.readlines()
lista = [x.strip() for x in lista] 

doc = open(archivo, 'r')

print('>>> Lectura completa del fichero: ')
print(doc.read())

#lis = doc.readline() # GUARDO LINEAS EN VARIABLE cad
#lista = list(lis.split( )) # TRANSFORMO A LISTA
if algoritmo == 'ss' or algoritmo == 'SS':
	inicial = time()
	for i in xrange(len(lista)):#Selection sort
		mi = i
		for j in range((i+1),len(lista)-1):
			if lista[j] < lista[i]:
				mi = j
		temp = lista[mi]
		lista[mi] = lista[i] 
		lista[i] = temp
#		lista[mi],lista[i] = lista[i],lista[mi]#intercambio de elementos de una lista
	print "Lista ordenada: \t", lista
	final = time() 
	ejecucion = final - inicial
	print 'Tiempo de ejecucion de selection sort en python: ', ejecucion

if algoritmo == 'bs' or algoritmo == 'BS':
	inicial = time()
	#AQUI VA EL CODIGO DEL BINARY SEARCH
	final = time() 
	ejecucion = final - inicial
	print 'Tiempo de ejecucion de binary search en python: ', ejecucion








#f=file("lista.txt", "r")

#content=f.read().splitlines()
"""


"""
	Algoritmo BS python

"""
def BS(nombreArch, n):
	arch = open(nombreArch, "r")		# Archivo de lectura
	lis = arch.read() 		# GUARDO LINEAS EN VARIABLE lis 
	lista = list(lis.split(' ')) 	# TOMA LOS DATOS SEPARADOS POR UN ESPACIO
#Paso 1
	l = len(lista); 		# Largo de la lista
	min = 0; 			# Selector del indice minimo
	max = l-1; 			# Selector del indice maximo
#Paso 2
	m = int(math.floor((min+max/2)))# Selector del indice medio
	while (l!=0):
#Paso 3
		if lista[m]==n:
			return True;
		elif lista[m] > n:
			max = m-1;
			lista = lista[min:max]; #Crea una sublista de la lista original
			l = len(lista);		
			m = int(math.floor((min+max)/2)); #Paso 4
		elif lista[m] < n:
			min = m+1;
			lista = lista[min:max];
			l = len(lista);
			m = int(math.floor((min+max)/2)); #Paso 4
	return False;
"""
	Main del programa
"""
def main(argc, argv*):
	algoritmo =  sys.argv[1]	# el primer argumento es el tipo de algoritmo
	if len(sys.argv)>3:
		n =  sys.argv[2]	# el segundo argumento es el nombre del archivo que contiene la lista
		doc = sys.argv[3]
	else:
		doc = sys.argv[2]
	if algoritmo=="BS":
		encotro=BS(doc,n)
	if encontro:
		print "Digito no encontrado"
	else:
		print "Digito encontrado"
	return 0;

if __name__=="__main__":
    main()

