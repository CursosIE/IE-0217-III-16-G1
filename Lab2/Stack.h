#ifndef STACK_H
#define STACK_H
#include <iostream>
#include "List.h"
#include "Cell.h"
using namespace std;

//Pila implementada con punteros  

template <typename D, typename P>
class Stack : public List<D, P> {
public:

Stack() {
		this->n = 0;
		this->first = nullptr;
		this->last = nullptr;
}

~Stack() {
	int x = this->getSize();
	if (x != 0){
		for (int i = 0; i < x; i++){
			Cell<D>* temp = this->first;
			this->first = temp->next;
			delete temp;
		}
	}
	delete this;
}

void push(D d) { //insertar
	if (this->getSize() == 0) //lista vacia
	{
		Cell<D>* c = new Cell<double>(new D(d), nullptr);
		this->first = this->last = c;
	}
	else { //lista con algo
		this->last->next = new Cell<double>(new D(d), nullptr);
		this->last = this->last->next;
	}
	this->n++;
}

Cell<D>* pop() { //remover
	Cell<D>* temp = this->last;
	if (temp != nullptr) {
		if (temp != this->first){
			last = prev(last);
		}
		else{
			last = nullptr;
		}
		return temp;
	}
}

void top(){ //Ultimo Elemento
		cout << *(this->last->data) << endl;
	}

void emptyStack() { //vaciar e imprimir
	Cell<double>* temp = this->pop();
	while (temp != this->first){
		cout << *(temp->data) << endl;
		temp = this->pop();
	}
	cout << *(temp->data) << endl;
}

//Metodos que hereda de List.h
P find(D d) { //buscar
	Cell<D>* temp = this->first;
	if (first != nullptr){
		for (int i = 0; i < this->getSize(); i++) {
			if (d == *(temp->data))
				return temp;
			else
				temp = temp->next;
		}
	}
	return nullptr;
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

D get(P k) { //obtener
	return *(this->last->data);
}

void assign(P k, D d) {//asignar
	*(k->data) = d;
}

int getSize() { //tamaño
	return this->n;
}

//Metodos que pierden su sentido en una Pila
void insert(D d) { //insertar
}

void remove(D d) { //remover
}

void sort() { //ordenar
}

void printList() { //imprimir
}

void emptyList() { //vaciar
}

private:
	int n; //num. elementos
	P last; //ultimo
	P first; //primero
};

#endif /* STACK_H */