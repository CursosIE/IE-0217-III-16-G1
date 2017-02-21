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

~ListWithPointer() {//dudas
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

void assign(P k, D d) {
    *(k->data) = d;
}

/*
void sort() { //ordenar
	Cell<D>* actual = this->first;
	cout << actual << endl;
	cout << this->first << endl;
	Cell<D>* temptr = nullptr;
	int contador = 0;
	while(contador<this->n){
		//this->first = ;
		//this->last = ;
		for(int i =0; i < this->n;i++,contador++){
			if((*(actual->data) > *(actual->next->data)) && actual->next){//entonces hay que hacer un swap
				cout <<"primer elemento mayor que el siguiente, cambio" << endl;
				cout <<this->n << endl;
				cout << actual->next << endl;
				temptr = actual->next->next;
				actual->next->next = actual;
				actual->next = temptr;
				this->printList();
				--contador;
			}
			else{
				cout <<"primer elemento menor que el siguiente" << endl;
				actual = actual->next;
			}
		}
	}
}
*/ 

void sort(){
cout << "sort llamado" << endl;
cout << "Primero" << *(this->first->data) << endl;	
cout << "último" << *(this->last->data) << endl;
	Cell<D>* min = this->first;
	Cell<D>* actual = this->first->next;
	Cell<D>* temp = mullptr;
	Cell<D>* tempnext = mullptr;
	
cout << "siguiente de first" << *(this->first->next->data) << endl;
	for(int i = 1; i < this->n; i++){
		if(*(min->data) > *(actual->data)){
			min = actual;
		}
		cout << *(min->data) << endl;
		if(actual->next){
			cout << "sí hay algo más en mi bola de cristal: " << i << endl;
			actual = actual->next;
		}
	}
cout << "im out bitch" << endl;
	temp = this->first;
	tempnext = this->first->next;
	this->first = min;
	Cell<D>* max = nullptr;
	for(int i = 1; i < this->n; i++){
		if(*(max->data) < *(actual->data)){
			max = actual;
		}
		if(actual->next)actual = actual->next;
	}
	this->last = max;
	cout << "First" << *(this->first->data) << endl;
	cout << "Last" << *(this->last->data) << endl;
/*	min = new Cell<D>(this->first->data,this->first->next);
	for(int i = 1; i < this->n; i++){
		for(int ii = 1; ii < this->n; ii++){
			if(*(min->data) > *(min->next->data)){
				*(this->first->data) = *(min->next->data);
			}
		}
	}*/
//delete min;	
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

