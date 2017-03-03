/**
* @brief Libreria que genera un template de una clase ListWithArray (lista implementada con arreglos) que hereda de la clase List
* @author Luis Adrian Aguilar - B00092
* @author Robin Gonzalez Ricz - B43011
* @author Giancarlo Marin - B54099
* @date 21-02-2017
*/

#ifndef LISTWITHARRAY_H
#define LISTWITHARRAY_H
#include <iostream>
#include "List.h"
using namespace std;

template <typename D, typename P> /**Libreria que genera un template de una clase ListWithArray (lista implementada con arreglos) que hereda de la clase List y que toma un tipo de dato para los datos contenidos en la lista (D) y otro para los indices de las misma (P)*/
class ListWithArray : public List<D, P> {
public:

	/**
	* Constructor de la clase ListWithArray
	*/
	ListWithArray() {
		data = nullptr;
		this->n = 0;
		this->maxElements = 0;
	}

	/**
	* Constructor sobrecargado de la clase ListWithArray
	* @param t 	Entero que determina la cantidad maxima de elementon que puede contener la lista
	*/
	ListWithArray(int t) {
		data = new D[t];
		this->n = 0;
		this->maxElements = t;
	}

	/**
	* Destructor de la clase ListWithArray
	*/
	~ListWithArray() {
	}

	/**
	* Metodo que implementa la insercion para ListWithArray
	* @param d 	Dato de tipo D que se desea insertar en List
	*/
	void insert(D d) {
		if (this->getSize() == 0) //lista vacia
		{
			this->data = new D[10];
			this->n = 1;
			this->last = 1;
			this->maxElements = 10;
			this->data[0] = d;
		}
		else { //lista con algo
			if (this->getSize() - 1 != last) { //arreglo con espacio
				this->data[last] = d;
				this->last++;
				this->n++;
			}
			else { //arreglo sin espacio
				D* tmp = new D[this->getSize() * 2];
				for (int i = 0; i<this->getSize(); i++) {
					tmp[i] = this->get(i);
				}
				this->maxElements = this->getSize() * 2;
				delete[] this->data;
				this->data = tmp;
				this->data[last] = d;
				this->last++;
				this->n++;
			}
		}
	}

	/**
	* Metodo que implementa la remocion para ListWithArray
	* @param d 	Dato de tipo D que se desea remover de List
	*/
	void remove(D d) {
		int i = this->find(d); /**<entero que indica la posicion donde se debe remover*/
		if (i != -1) {
			for (i; i< this->getSize() - 1; i++) {
				this->assign(i, this->get(i + 1));
			}
			this->n--;
			this->last--;
		}
	}

	/**
	* Metodo que implementa la busqueda para ListWithArray
	* @param d 	Dato que se desea buscar en List
	* @return 	Indice de tipo P dentro de List
	*/
	P find(D d) {
		/*for (int i = 0; i < this->getSize(); i++) {
			if (*(d.data) == *(this->get(i).data))
				return i;
		}*/
		return -1; /**Indicacion de que el dato no fue encontrado en la lista*/
	}

	/**
	* Metodo que implementa el obtener un dato para ListWithArray
	* @param k 	Indice de tipo P dentro de List del que se desea obtener dato
	* @return 	Dato contenido en k de tipo D
	*/
	D get(P k) {
		return data[k];
	}

	/**
	* Metodo que implementa el asignar un valor especifico a un dato en ListWithArray
	* @param k 	Indice de tipo P dentro de list donde se asignara el nuevo valor
	* @param d	Dato de tipo D que se asigna en la posicion k
	*/
	void assign(P k, D d) {//asignar
		this->data[k] = d;
	}

	/**
	* Metodo que implementa el ordenar para ListWithArray
	*/
	void sort() {
		/**Implementacion por medio de Selection Sort*/
		/*
		for (int i = 0; i < this->getSize() - 1; i++) {
			int min = i;
			for (int j = i + 1; j < this->getSize(); j++){
				if (this->data[j] < this->data[min]){
					min = j;
				}
			}
			D temp = this->data[i];
			this->data[i] = this->data[min];
			this->data[min] = temp;
		}
		*/
	}

	/**
	* Metodo que implementa el obtener tamaño de ListWithArray
	*/
	int getSize() {
		return this->n;
	}

	/**
	* Metodo que implementa el imrprimir lista para ListWithArray
	*/
	void printList() {
		/*for (int i = 0; i < this->getSize(); i++) {
			cout << *(this->get(i).data) << "\t";
		}
		cout << endl;*/
	}

	/**
	* Metodo que implementa el obtener siguiente elemento de una posicion especifica de ListWithArray
	* @param k 	Indice de tipo P dentro de List del que se desea el siguiente elemento
	* @return 	Siguiente elemento de k de tipo P
	*/
	P next(P k) {
		if (k < this->getSize())
			return k + 1;
		else
			return -1; /**Indicacion de que no hay dato siguiente en la lista*/
	}

	/**
	* Metodo que implementa el obtener elemento anterior de una posicion especifica de ListWithArray
	* @param k 	Indice de tipo P dentro de List del que se desea el elemento anterior
	* @return 	Elemento anterior de k de tipo P
	*/
	P prev(P k) {
		if (k > 0)
			return k - 1;
		else
			return -1; /**Indicacion de que no hay dato anterior en la lista*/
	}

	/**
	* Metodo que implementa el vaciar Lista que Deja sin ningun elemento a ListWithArray
	*/
	void emptyList() {
		this->n = 0;
	}

private:
	int n; /**<Atrib. privado de tipo entero que indica el numero de elementos en list*/
	int maxElements; /**<Atrib. privado de tipo entero que indica el numero maximo de elementos en list*/
	P last; /**<Atrib. privado de tipo P que indica el indice del ultimo elemento de list*/
	D* data; /**<Atrib. privado de tipo puntero D que apunta a los datos de ListWithArray*/
};

#endif /* LISTWITHARRAY_H */