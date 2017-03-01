/**
* @author Robin Gonzalez - B43011
* @author Giancarlo Marin - B54099
* @date 22-02-2017
* @brief Biblioteca de la clase Vertex que genera vertices de grafos
*/
#ifndef NODE_H
#define NODE_H

#include <iostream>
#include "MyData.h"
#include "ListWithPointer.h"

using namespace std;
template<typename D>/**Biblioteca de la clase Vertex que genera los vertices de un grafo*/
class Node{
public:
	D* data; ///Atrib. publico de tipo MyData que contiene el puntero al dato a guardar///
	ListWithPointer<Node<D>, Cell<Node<D>>*>* aristas;///Atrib. publico de tipo puntero a Edge que contiene l alista de aristas que contiene el vertice del grafo///
	/**
	* Constructor de la clase MyChar
	*/
	Node(){
		this->data = nullptr;
		this->aristas = nullptr;
	}

	/**
	* Constructor sobrecargado de la clase Vertex
	* @param d 	Puntero a D con el dato a guardar
	* @param e	Puntero a Lista de aristas a asignar al vertice
	*/
	Node(D* d){
		this->data = d;
		this->aristas = nullptr;//new ListWithPointer<Node<D>,Cell<Node<D>>*>();
	}

	/**
	* Destructor de la clase Vertex
	*/
	~Node(){
		delete data;
	}

	bool operator==(Node<D> n){
			return *(this->data) == *(n.data);
	}
	
	ostream& operator<<(ostream& s)
//ostream& operator<<(ostream& os, const Date& dt) 
	{
		//ostream& s;
	    s << "direccion: " << &this <<" data: "<< *(this.data);
	    return s;
	}
};

#endif /* VERTEX_H */
