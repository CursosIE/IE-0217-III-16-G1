# Makefile - Giancarlo Marin IE-0217
CXX= g++
CXXFLAGS= -Wall -g 
INCLUDES= 
SOURCES= main.cpp pokemon.cpp
OBJECTS= $(SOURCES:.cpp=.o)
MAIN= build
EXEC= pokemon

.PHONY: depend clean

all:	$(MAIN) run clean
	

$(MAIN): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(EXEC).out
	@echo ----- PROYECTO COMPILADO ARCHIVO EJECUTABLE POKEMON.OUT GENERADO -----

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $<  -o $@

run: 
	@echo ----- EJECUTANDO POKEMON.OUT -----
	./$(EXEC).out
	
clean:
	@echo ----- LIMPIANDO ARCHIVOS INTERMEDIOS Y ARCHIVO EJECUTABLE -----
	rm -f *.o *~ *.out $(EXEC)


