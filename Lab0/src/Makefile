CC=gcc
CXX=g++
RM=rm -f
LDLIBS=$(shell root-config --libs)
CFLAGS = -Wall -g -lm -std=c++11
LFLAGS = 
INCLUDES =  -I../include

SRCS= Celda.cpp Animal.cpp Juego.cpp Lobo.cpp Oveja.cpp Raton.cpp Zorro.cpp main.cpp
OBJS=$(subst .cc,.o,$(SRCS))

MAIN = ../build/gameOn

all:    $(MAIN)
	@echo  "Compilación terminada"

$(MAIN): $(OBJS)
	$(CXX) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)

run:
	../build/./gameOn 50 ../config.txt

clean:
	$(RM) ../build/*.o ../build/*~ ../build/../build/fight
	$(RM) *.o *~ ../build/fight
