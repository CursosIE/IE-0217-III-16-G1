#ifndef STACK_H
#define STACK_H
#include <iostream>
#include "ListWithPointer.h"
#include "Cell.h"
using namespace std;

//Pila implementada con punteros  

template <typename D, typename P>
class Stack : public ListWithPointer<D, P> {
public:

/**
 * Constructor de la clase Stack
 */ 
Stack() {
		this->n = 0;
		this->first = nullptr;
		this->last = nullptr;
}

/**
 * Destructor de la clase Stack
 */
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

/**
 * Metodo que implementa el insertar (push) del Stack
 * @param d 	Elemento de tipo D que se inserta al STACK
 */
void push(D d) {
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

/**
 * Metodo que implementa el sacar elemento del STACK (pop)
 * @return  	Puntero a la celda que contiene el dato sacado el STACK
 */
Cell<D>* pop() {
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

/**
 * Metodo que implementa el obtener el ultimo elemento del LIFO. Imprime el ultimo elemento añadido 
 */
void top(){
		cout << *(this->last->data) << endl;
	}

/**
 * Metodo que implementa el vaciar Pila que Deja sin ningun elemento el Stack e imprime cada elemento que retira
 */
void emptyStack() { 
	Cell<double>* temp = this->pop();
	while (temp != this->first){
		cout << *(temp->data) << endl;
		temp = this->pop();
	}
	cout << *(temp->data) << endl;
}

/**Metodos que se heredan de ListWithPointer.h*/

/**
 * Metodo que implementa la busqueda en un ListWithPointer
 * @param d 	Dato que se desea buscar en List
 * @return 	Indice de tipo P dentro de List
 */
P find(D d) {
	Cell<D>* temp = this->first;
	if (first != nullptr){
		for (int i = 0; i < this->getSize(); i++) {
			if (d == *(temp->data))
				return temp;
			else
				temp = temp->next;
		}
	}
	return nullptr; /**Indicacion de que el dato no fue encontrado en la lista*/
}

/**
 * Metodo que implementa el obtener siguiente elemento de una posicion especifica del Stack
 * @param k 	Indice de tipo P dentro de List del que se desea el siguiente elemento 
 * @return 	Siguiente elemento de k de tipo P
 */
P next(P k) {
	return k->next;
}

/**
 * Metodo que implementa el obtener elemento anterior en Stack
 * @param k 	Indice de tipo P dentro de la list del que se desea el elemento anterior
 * @return 	Elemento anterior de k de tipo P
 */
P prev(P k) {
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

/**
 * Metodo que implementa el obtener tamaño del Stack
 */
int getSize() {
	return this->n;
}

private:
	int n; /**<Atrib. privado de tipo entero que indica el numero de elementos en el Stack*/
	P last; /**<Atrib. privado de tipo P que indica el indice del ultimo elemento del Stack*/
	P first; /**<Atrib. privado de tipo P que indica el indice del primer elemento del Stack*/
};

#endif /* STACK_H */
