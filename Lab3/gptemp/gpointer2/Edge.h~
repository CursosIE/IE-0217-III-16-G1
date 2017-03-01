/**
* @author Robin Gonzalez - B43011
* @author Giancarlo Marin - B54099
* @date 22-02-2017
* @brief Libreria de la clase Edge que contiene la especificacion de una arista del grafo
*/
#ifndef EDGE_H
#define EDGE_H

#include <iostream>
#include "Node.h"
#include "MyData.h"
#include "ListWithPointer.h"

using namespace std;

template<typename D>/**Libreria de la clase Edge que contiene la especificacion de una arista del grafo*/
class Edge{
public:
	double peso; /**Atrib. publico de tipo double que indica el peso de la arista*/
	Node<D>* orig;//<MyData<D>, Edge<D>>* orig;  /**Atrib. publico de tipo puntero a Vertex que apunta al vertice origen de la arista*/
	Node<D>* dest;//<MyData<D>, Edge<D>>* dest; /**Atrib. publico de tipo puntero a Vertex que apunta al vertice destino de la arista*/

	/**
	* Constructor de la clase Edge
	*/
	Edge(){
		this->peso = 0.0;
		this->orig = nullptr;
		this->dest = nullptr;
	}

	/**
	* Constructor sobrecargado de la clase Edge
	* @param w 	Double con el peso de la arista
	* @param o	Puntero de Vertex que indica el vertice de origen
	* @param d	Puntero de Vertex que indica el vertice de destino
	*/
	Edge(double w, Node<D>* p, Node<D>* s){
		this->peso = w;
		this->orig = p;
		this->dest = s;
	}

	/**
	* Destructor de la clase Edge
	*/
	~Edge(){
	}
	
	bool operator==(Edge<D> n){
			return (this->peso==n.peso&&this->orig==n.orig &&this->dest==n.dest);
	}
	
	ostream& operator<<(ostream& s)
//ostream& operator<<(ostream& os, const Date& dt) 
	{
		//ostream& s;
	    s << "direccion: " << &this <<" data: "<< *(this.data);
	    return s;
	}
};

#endif /* EDGE_H */
