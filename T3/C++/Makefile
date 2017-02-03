# Makefile - Giancarlo Marin IE-0217
CXX= g++
CXXFLAGS= -Wall -g 
INCLUDES= 
SOURCES= algoritmosC++.cpp
OBJECTS= $(SOURCES:.cpp=.o)
MAIN= compile
EXEC= test

.PHONY: depend clean

all:	$(MAIN) run clean
	

$(MAIN): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(EXEC).out
	@echo ----- PROYECTO COMPILADO ARCHIVO EJECUTABLE TEST.OUT GENERADO -----

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $<  -o $@

run: 
	@echo ----- EJECUTANDO TEST.OUT -----
	./$(EXEC).out
	
clean:
	@echo ----- LIMPIANDO ARCHIVOS INTERMEDIOS Y ARCHIVO EJECUTABLE -----
	rm -f *.o *~ *.out $(EXEC)


