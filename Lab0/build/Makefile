# Makefile - Lab0 IE-0217
CXX= g++
RM= rm -f
CXXFLAGS= -Wall -g
CONFIG_FILE= ../include/config.txt 
DAYS= 50
SRCS= ../src/main.cpp ../src/Animal.cpp ../src/Celda.cpp ../src/Lobo.cpp ../src/Oveja.cpp ../src/Raton.cpp ../src/Zorro.cpp
OBJS= $(SRCS:.cpp=.o)
#Nombre del archivo ejecutable
MAIN= Juego

.PHONY: depend clean

all:	$(MAIN) run clean
	

$(MAIN): $(OBJS)
	$(CXX) $(OBJS) -o $(MAIN) 
	@echo ----- PROYECTO COMPILADO ARCHIVO EJECUTABLE JUEGO GENERADO -----

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $<  -o $@

run: 
	@echo ----- EJECUTANDO JUEGO -----
	./$(MAIN) $(DAYS) $(CONFIG_FILE)
	
clean:
	@echo ----- LIMPIANDO ARCHIVOS INTERMEDIOS Y ARCHIVO EJECUTABLE -----
	$(RM) ../src/*.o ../src/*~ $(MAIN)


