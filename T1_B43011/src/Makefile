CC=gcc
CXX=g++
RM=rm -f
#CPPFLAGS=-g $(shell root-config --cflags)
#LDFLAGS=-g $(shell root-config --ldflags)
LDLIBS=$(shell root-config --libs)
CFLAGS = -Wall -g -lm
LFLAGS = 
INCLUDES =  -I../include

SRCS= Pokemon.cpp Fire.cpp Flying.cpp Water.cpp Electric.cpp Zapdos.cpp Moltres.cpp Articuno.cpp Ice.cpp main.cpp
OBJS=$(subst .cc,.o,$(SRCS))

MAIN = ../build/fight

#all: tool

all:    $(MAIN)
	@echo  "Felicidades ya compiló :)"

$(MAIN): $(OBJS)
	$(CXX) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)

#tool: $(OBJS)
#    $(CXX) $(LDFLAGS) -o tool $(OBJS) $(LDLIBS) 

#depend: .depend

#.depend: $(SRCS)
#	$(RM) ./.depend
#	$(CXX) $(CPPFLAGS) -MM $^>>./.depend;

#clean:
#    $(RM) $(OBJS)

run:
	
	../build/./fight

clean:
	rm -f ../build/*.o ../build/*~ ../build/../build/fight
	rm -f *.o *~ ../build/fight


#distclean: clean
#	$(RM) *~ .depend

#include .depend
