#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include "List.h"
#include "Cell.h"
using namespace std;

template <typename D, typename P>
class Queue: public List<D, P> {
	
	P* primero;
	P* ultimo;
	int n = 0;//cantidad de elementos
   
	Queue() {
		primero = ultimo = nullptr;
	}
	
	Queue(){
		
	}
	
	~Queue(){
		
	}
/*
virtual void insert(double d) = 0; //insertar al inicio
    virtual void remove(D d) = 0; //remover al final
    virtual P find(D d) = 0; //buscar
    virtual D get(P k) = 0; //obtener
    virtual void assign(P k, D d) = 0; //asignar
    virtual void sort() = 0; //ordenar
    virtual int getSize() = 0; //tamaño
    virtual void printList() = 0; //imprimir
    virtual P next(P k) = 0; //siguiente
    virtual P prev(P k) = 0; //anterior
    virtual void emptyList() = 0; //vaciar
*/
}

#endif
