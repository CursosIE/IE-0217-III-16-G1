/**
* @brief Libreria que genera un template de una clase ListWithPointer (lista implementada con punteros) que hereda de la clase List
* @author Robin Gonzalez Ricz - B43011
* @author Giancarlo Marin - B54099
* @author Luis Adrian Aguilar Cascante
* @date 21-02-2017
*/
#ifndef LISTWITHPOINTER_H
#define LISTWITHPOINTER_H
#include <iostream>
#include "List.h"
#include "Cell.h"

using namespace std;

//Lista de double con punteros  

template <typename D, typename P> /**Libreria que genera un template de una clase ListWithPointer (lista implementada con punteros) que hereda de la clase List y que toma un tipo de dato para los datos contenidos en la lista (D) y otro para los indices de las misma (P)*/
class ListWithPointer : public List<D, P> {
public:

	/**
	* Constructor de la clase ListWithPointer
	*/
	ListWithPointer() {
		this->n = 0;
		this->first = nullptr;
		this->last = nullptr;
	}

	/**
	* Destructor de la clase ListWithPointer
	*/
	~ListWithPointer() {
		int x = this->getSize();
		if (x != 0){
			for (int i = 0; i<x; i++){
				Cell<D>* temp = this->first;
				this->first = temp->next;
				delete temp;
			}
		}
		delete this;
	}

	/**
	* Metodo que implementa la insercion para ListWithPointer
	* @param d 	Dato de tipo D que se desea insertar en List
	*/
	void insert(D d) {
		if (this->getSize() == 0) //lista vacia
		{
			Cell<D>* c = new Cell<D>(d ,nullptr);
			this->first = this->last = c;
		}
		else { //lista con algo
			this->last->next = new Cell<D>(d,nullptr);
			this->last = this->last->next;
		}
		this->n++;
	}

	/**
	* Metodo que implementa la remocion para ListWithPointer
	* @param d 	Dato de tipo D que se desea remover de List
	*/
	void remove(D d) {
		Cell<D>* temp = this->find(d); /**<Celda de tipo puntero D que indica la posicion donde se debe remover*/
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

	/**
	* Metodo que implementa la busqueda para ListWithPointer
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
	* Metodo que implementa el obtener un dato para ListWithPointer
	* @param k 	Indice de tipo P dentro de List del que se desea obtener dato
	* @return 	Dato contenido en k de tipo D
	*/
	D get(P k) {
		return *(k->data);
	}

	/**
	* Metodo que implementa el asignar un valor especifico a un dato en ListWithPointer
	* @param k 	Indice de tipo P dentro de list donde se asignara el nuevo valor
	* @param d	Dato de tipo D que se asigna en la posicion k
	*/
	void assign(P k, D d) {
		*(k->data) = d;
	}

	/**
	* Metodo que implementa el ordenar para ListWithPointer
	*/
	void sort() {
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
				if (temp2->data < min->data){
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
	* Metodo que implementa el obtener tamaño de ListWithPointer
	*/
	int getSize() {
		return this->n;
	}

	/**
	* Metodo que implementa el imrprimir lista para ListWithPointer
	*/
	void printList() {
		Cell<D>* temp = this->first;
		for (int i = 0; i < this->getSize(); i++) {
			if (temp != nullptr){
				cout << temp->data << endl;
				temp = temp->next;
			}
		}
	}

	/**
	* Metodo que implementa el obtener siguiente elemento de una posicion especifica de ListWithPointer
	* @param k 	Indice de tipo P dentro de List del que se desea el siguiente elemento
	* @return 	Siguiente elemento de k de tipo P
	*/
	P next(P k) {
		return k->next;
	}

	/**
	* Metodo que implementa el obtener elemento anterior de una posicion especifica de ListWithPointer
	* @param k 	Indice de tipo P dentro de List del que se desea el elemento anterior
	* @return 	Elemento anterior de k de tipo P
	*/
	P prev(P k) {
		if (k != this->first){
			Cell<D>* temp = this->first;
			while (temp->next != k){
				temp = temp->next;
			}
			return temp;
		}
		else
			return nullptr;
	}

	/**
	* Metodo que implementa el vaciar Lista que Deja sin ningun elemento a ListWithPointer
	*/
	void emptyList() {
		int x = this->getSize();
		Cell<D>* temp = this->first;
		for (int i = 0; i<x; i++){
			temp = this->first->next;
			delete this->first;
			this->first = temp;
		}
		this->n = 0;
	}

private:
	int n; /**<Atrib. privado de tipo entero que indica el numero de elementos en list*/
	P last; /**<Atrib. privado de tipo P que indica el indice del ultimo elemento de list*/
	P first; /**<Atrib. privado de tipo P que indica el indice del primer elemento de list*/
};

#endif /* LISTWITHPOINTER_H */
