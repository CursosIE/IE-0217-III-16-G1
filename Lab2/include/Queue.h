/**
*@brief archivo header que contiene la implementacion de una cola en c++
*@author Robin Gonzalez Ricz - B43011
*@date 22 - 02 - 2017
*/
#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include "List.h"
#include "Cell.h"
using namespace std;
//queue de double con punteros

template <typename D, typename P>//aqui P es puntero a celda
lass Queue : public List<D, P> {
public:

Queue() {
    this->n = 0;
	this->first= nullptr;//es un tipo de ojeto vacio
	this->last= nullptr;
}
~Queue() {
	int x = this->getSize();
	if (x!=0){
		for (int i=0; i<x;i++){
			Cell<double>* temp = this->first;
			this->first = temp->next;
			delete temp;
		}
	}
    delete this;
}

int getSize(){
  return this->n;
}
	
void sort(){//ordena crecientemente
  /**Implementacion por medio de Selection Sort*/
  int cont = 0;
	Cell<D>* temp = this->first;
	while (temp->next != nullptr){
		Cell<D>* min = this->first;
		for (int i = 0; i < cont; i++){
			min = next(min);
		}
		Cell<D>* temp2 = min;
		while (temp2 != last){
			temp2 = next(temp2);
			if (*(temp2->data) < *(min->data)){
				min = temp2;
			}
		}
		D* temp3 = temp->data;
		temp->data = min->data;
		min->data = temp3;
		cont++;
		temp = next(temp);
	}
}

void insert(D* d) { //insertar
	this->first = Cell(d, this->first->next);//estos first en realidad son los last del queue
}

void remove(D d) { //remover
  Cell ant = prev(this->last);//estos last son en relidad los first del queue
  Cell borrar = this->last;
  this->last = ant;
  delete borrar;
}

P find(D d) { //buscar
    Cell<double>* temp = this->first;
	if (first!=nullptr){
		for (int i = 0; i < this->getSize(); i++) {
			if (d == *(temp->data))
				return temp;
			else
				temp = temp->next;
		}
	}
    return nullptr;
}

D get(P k) { //obtener
    return *(k->data);
}

void assign(P k, D d) {
    *(k->data) = d;
}


int getSize() { //tamaÃ±o
    return this->n;
}

void printList() { //imprimir
    Cell<double>* temp = this->first;
	for (int i = 0; i < this->getSize(); i++) {
        if (temp!=nullptr){
			cout << *(temp->data) << endl;
			temp=temp->next;
		}
	}
}


P next(P k) { //siguiente
    return k->next;
}

P prev(P k) { //anterior
    if (k != this->first){
		Cell<double>* temp = this->first;
		while (temp->next != k){
			temp = temp->next;
		}
		return temp;
	}
	else
		return nullptr;
}

void emptyList() { //vaciar
	int x = this->getSize();
	Cell<double>* temp = this->first;
    for(int i=0;i<x;i++){
		temp = this->first->next;
		delete this->first;
		this->first = temp;
	}
	this->n=0;
}

private:
    int n; //num. elementos
    P last; //ultimo
	   P first; //primero
};

#endif


