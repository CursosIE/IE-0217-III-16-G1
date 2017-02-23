/**
*@brief Archivo header que contiene la implementacion de la clase Queue (cola) en c++
* @author Luis Adrian Aguilar - B00092
* @author Robin Gonzalez Ricz - B43011
* @author Giancarlo Marin - B54099
*@date 22 - 02 - 2017
*/
#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include "ListWithPointer.h"
#include "Cell.h"
using namespace std;

template <typename D, typename P>/**Biblioteca que genera un template de la clase Stack (Pila) que hereda de la clase ListWithPointer y que toma un tipo de dato D para los datos contenidos con indices P*/
class Queue : public List<D, P> {
public:
/**
 * Constructor de la clase Stack
 */ 
Queue() {
    this->n = 0;
	this->first= nullptr;//es un tipo de ojeto vacio
	this->last= nullptr;
}
/**
 * Destructor de la clase Stack
 */
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

/**
 * Metodo que implementa el insertar (push) del Queue
 * @param d 	Elemento de tipo D que se inserta al Queue
 */
void push(D* d) { //insertar
	this->first = Cell<D>(d, this->first->next);//estos first en realidad son los last del queue
}

/**
 * Metodo que implementa el sacar elemento del Queue (pop)
 * @return  	Puntero a la celda que contiene el dato sacado el Queue
 */
void pop(D d) { //remover
  Cell<D>* ant = prev(this->last);//estos last son en relidad los first del queue
  Cell<D>* borrar = this->last;
  this->last = ant;
  delete borrar;
}

/**
 * Metodo que implementa la busqueda en un ListWithPointer
 * @param d 	Dato que se desea buscar en List
 * @return 	Indice de tipo P dentro de List
 */
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

/**
 * Metodo que implementa el obtener tamaño del Queue
 */
int getSize() {
    return this->n;
}

/**
 * Metodo para imprimir los elementos de la cola 
 */
void printQueue() {
    Cell<double>* temp = this->first;
	for (int i = 0; i < this->getSize(); i++) {
        if (temp!=nullptr){
			cout << *(temp->data) << endl;
			temp=temp->next;
		}
	}
}

/**
 * Metodo que implementa el obtener siguiente elemento de una posicion especifica del Queue
 * @param k 	Indice de tipo P dentro de List del que se desea el siguiente elemento 
 * @return 	Siguiente elemento de k de tipo P
 */
P next(P k) { //siguiente
    return k->next;
}

/**
 * Metodo que implementa el obtener elemento anterior en Queue
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
 * Metodo que implementa el vaciar Cola que Deja sin ningun elemento el Queue e imprime cada elemento que retira
 */
void emptyQueue() {
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
	int n; /**<Atrib. privado de tipo entero que indica el numero de elementos en la cola*/
	P last; /**<Atrib. privado de tipo P que indica el indice del primer elemento de la cola*/
	P first; /**<Atrib. privado de tipo P que indica el indice del ultimo elemento de la cola*/
};

#endif


