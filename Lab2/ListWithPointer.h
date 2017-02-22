#ifndef LISTWITHPOINTER_H
#define LISTWITHPOINTER_H
#include <iostream>
#include "List.h"
#include "Cell.h"

using namespace std;

//Lista de double con punteros  

template <typename D, typename P>
class ListWithPointer : public List<D, P> {
public:
    
ListWithPointer() {
    this->n = 0;
	this->first= nullptr;
	this->last= nullptr;
}

~ListWithPointer() {
	int x = this->getSize();
	if (x!=0){
		for (int i=0; i<x;i++){
			Cell<D>* temp = this->first;
			this->first = temp->next;
			delete temp;
		}
	}
    delete this;
}

void insert(D d) { //insertar
    if (this->getSize() == 0) //lista vacia
    {
		Cell<D>* c= new Cell<double>(new D(d), nullptr);
        this->first = this->last = c;
    } else { //lista con algo
        this->last->next = new Cell<double>(new D(d), nullptr);
		this->last = this->last->next;
    }
	this->n++;
}

void remove(D d) { //remover
    Cell<D>* temp = this->find(d);
    if (temp != nullptr) {
		if (temp == this->first){
			this->first = this->first->next;
		}
		else{
			Cell<D>* temp2 = prev(temp);
			temp2->next = temp->next;
		}
		delete temp;
        this->n--;
    }
}

P find(D d) { //buscar
    Cell<D>* temp = this->first;
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

void assign(P k, D d) {//asignar
    *(k->data) = d;
}

void sort() { //ordenar
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

int getSize() { //tamaño
    return this->n;
}

void printList() { //imprimir
    Cell<D>* temp = this->first; 
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

#endif /* ListWithPointer_H */

