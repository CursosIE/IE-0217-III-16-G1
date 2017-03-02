# Makefile - PROYECTO IE-0217 - G1 - III2016
CXX= g++
RM= rm -f
CXXFLAGS= -Wall -g -std=c++11
SRC= ../src/main.cpp ../src/DNAcompare.cpp
OBJS= $(SRC:.cpp=.o)
#Nombre del archivo ejecutable
PROY= ADN
#Archivo de secuencia de ADN por ejecutar
SEQ= ../include/DNA/Seq1.txt
#Cadenas por buscar dentro de la secuencia
FIND= ../include/DNA/find.txt
#Diccionario de las secuencias
DICC= ACGT
#Porcentaje de aceptacion para dar un check de encontrado en el algoritmo
PORC= 80


.PHONY: depend clean

all:	build run clean
	

build: $(OBJS)
	$(CXX) $(OBJS) -o $(PROY) 
	@echo ----- COMPILACION DE PROYECTO ARCHIVO EJECUTABLE ADN GENERADO -----

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $<  -o $@

run: 	
	@echo ----- EJECUTANDO ADN -----
	./$(PROY) $(DICC) $(SEQ) $(FIND) $(PORC)
	
clean:
	@echo ----- LIMPIANDO ARCHIVOS INTERMEDIOS Y ARCHIVO EJECUTABLE -----
	$(RM) ../src/*.o $(PROY)

