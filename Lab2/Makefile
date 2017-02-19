# Makefile - Lab2 IE-0217
CXX= g++
RM= rm -f
CXXFLAGS= -Wall -g -std=c++11
SRCS= *.cpp
OBJS= $(SRCS:.cpp=.o)
#Nombre del archivo ejecutable
MAIN= estructuras

.PHONY: depend clean

all:	$(MAIN) run clean
	

$(MAIN): $(OBJS)
	$(CXX) $(OBJS) -o $(MAIN) 
	@echo ----- PROYECTO COMPILADO ARCHIVO EJECUTABLE GENERADO -----

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $<  -o $@

run: 
	@echo ----- EJECUTANDO -----
	./$(MAIN
	
clean:
	@echo ----- LIMPIANDO ARCHIVOS INTERMEDIOS Y ARCHIVO EJECUTABLE -----
	rm *.o $(MAIN)


