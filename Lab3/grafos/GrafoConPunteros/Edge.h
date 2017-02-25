/**
* @author Giancarlo Marin - B54099
* @date 22-02-2017
* @brief Libreria de la clase Edge que contiene la especificacion de una arista del grafo
*/
#ifndef EDGE_H
#define EDGE_H

#include <iostream>
#include "Vertex.h"
#include "MyData.h"

using namespace std;

template<typename D>/**Libreria de la clase Edge que contiene la especificacion de una arista del grafo*/
class Edge{
public:
	double weight; /**Atrib. publico de tipo double que indica el peso de la arista*/
	Vertex<MyData<D>, Edge<D>>* orig;  /**Atrib. publico de tipo puntero a Vertex que apunta al vertice origen de la arista*/
	Vertex<MyData<D>, Edge<D>>* dest; /**Atrib. publico de tipo puntero a Vertex que apunta al vertice destino de la arista*/

	/**
	* Constructor de la clase Edge
	*/
	Edge(){
		this->weight = 0.0;
		this->orig = nullptr;
		this->dest = nullptr;
	}

	/**
	* Constructor sobrecargado de la clase Edge
	* @param w 	Double con el peso de la arista
	* @param o	Puntero de Vertex que indica el vertice de origen
	* @param d	Puntero de Vertex que indica el vertice de destino
	*/
	Edge(double w, Vertex<MyData<D>, Edge<D>>* o, Vertex<MyData<D>, Edge<D>>* d){
		this->weight = w;
		this->orig = o;
		this->dest = d;
	}

	/**
	* Destructor de la clase Edge
	*/
	~Edge(){
	}
};

#endif /* EDGE_H */
