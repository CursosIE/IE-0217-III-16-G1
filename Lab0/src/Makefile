CC=gcc
CXX=g++
RM=rm -f
LDLIBS=$(shell root-config --libs)
CFLAGS = -Wall -g -lm -std=c++11
LFLAGS = 
INCLUDES =  -I../include
CONFIG = ../config.txt
DAYS = 50

SRCS= Celda.cpp Animal.cpp Juego.cpp Lobo.cpp Oveja.cpp Raton.cpp Zorro.cpp main.cpp
OBJS=$(subst .cc,.o,$(SRCS))

MAIN = ../build/gameOn

all:    $(MAIN)
	@echo  "Compilación terminada"

$(MAIN): $(OBJS)
	$(CXX) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)

run:
	../build/./gameOn $(DAYS) $(CONFIG)

clean:
	$(RM) ../build/*.o ../build/*~ ../build/../build/fight
	$(RM) *.o *~ ../build/fight

# If the first argument is "run"...
#ifeq (run,$(firstword $(MAKECMDGOALS)))
  # use the rest as arguments for "run"
#  RUN_ARGS := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
  # ...and turn them into do-nothing targets
#  $(eval $(RUN_ARGS):;@:)
#endif

#prog: # ...
    # ...

#.PHONY: run
#run : prog
#    @echo prog $(RUN_ARGS)

