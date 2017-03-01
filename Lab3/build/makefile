# Makefile - Lab3 IE-0217
CXX= g++
RM= rm -f
CXXFLAGS= -Wall -g -std=c++11
SRCBST= ../src/bst/*.cpp
SRCGWA= ../src/gwa/*.cpp
SRCGWP= ../src/gwp/*.cpp
OBJSBST= $(SRCBST:.cpp=.o)
OBJSGWA= $(SRCGWA:.cpp=.o)
OBJSGWP= $(SRCGWP:.cpp=.o)
#Nombre del archivo ejecutable
BST= bst
GWA= gwa
GWP= gwp

.PHONY: depend clean

all:	$(BST) $(GWA) $(GWP) run clean
	

$(BST): $(OBJSBST)
	$(CXX) $(OBJSBST) -o $(BST) 
	@echo ----- COMPILACION DE ARBOL BST ARCHIVO EJECUTABLE bst GENERADO -----

$(GWA): $(OBJSGWA)
	$(CXX) $(OBJSGWA) -o $(GWA) 
	@echo ----- COMPILACION DE GRAFO CON ARREGLO ARCHIVO EJECUTABLE gwa GENERADO -----

$(GWP): $(OBJSGWP)
	$(CXX) $(OBJSGWP) -o $(GWP) 
	@echo ----- COMPILACION DE GRAFO CON PUNTEROS ARCHIVO EJECUTABLE gwp GENERADO -----

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $<  -o $@

run: 	runBST runGWA runGWP
	

runBST: 
	@echo ----- EJECUTANDO BST -----
	./$(BST) 

runGWA: 
	@echo ----- EJECUTANDO GWA -----
	./$(GWA)

runGWP: 
	@echo ----- EJECUTANDO GWP -----
	./$(GWP) 
	
clean:
	@echo ----- LIMPIANDO ARCHIVOS INTERMEDIOS Y ARCHIVOS EJECUTABLE -----
	$(RM) ../src/bst/*.o ../src/gwa/*.o ../src/gwp/*.o $(BST) $(GWA) $(GWP) 


