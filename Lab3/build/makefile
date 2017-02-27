CC=gcc
CXX=g++
RM=rm -f
CFLAGS = -Wall -g -lm
LFLAGS = 
LIBS = 
INCLUDES =  -I*.hpp

SRCS= polinomios.cpp main.cpp
OBJS=$(subst .cc,.o,$(SRCS))

MAIN = operaciones

all:    $(MAIN)
	@echo  "Felicidades ya compiló :)"

$(MAIN): $(OBJS)
	$(CXX) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)

run:
	@echo  ">>>Ejecutando..."
	./operaciones

clean:
	@echo  ">>>Limpiando..."
	$(RM) *.o *~ operaciones
