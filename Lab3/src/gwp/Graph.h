/**
* @author Robin Gonzalez Ricz - B43011
* @author Giancarlo Marin - B54099
* @author Luis Adrian Aguilar Cascante
* @author Giancarlo Marin - B54099
* @date 25-02-2017
* @brief Libreria de la clase Graph que genera Grafos
*/
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include "MyData.h"
#include "Edge.h"
#include "Vertex.h"
#include "ListWithPointer.h"
#include "Cell.h"

using namespace std;
template<typename D>/**Libreria de la clase Graph que genera Grafos*/
class Graph{
public:
	ListWithPointer<Vertex<MyData<D>, Edge<D>>, Cell<Vertex<MyData<D>,Edge<D>>>*>* gV; ///Atrib. publico de tipo puntero a lista que contiene la lista de vertices del grafo///
	ListWithPointer<Edge<D>, Cell<Edge<D>>*>* gA; ///Atrib. publico de tipo puntero a lista que contiene la lista de aristas del grafo///
	/**
	* Constructor de la clase Graph
	*/
	Graph(){
		this->gV = nullptr;
		this->gA = nullptr;
	}

	/**
	* Destructor de la clase Graph
	*/
	~Graph(){
		delete gV;
		delete gA;
	}

	/**
	* Metodo que agrega Vertices a la lista de Vertices del grafo
	* @param v		Puntero a Vertex que es agregado a la lista
	*/
	void addV(Vertex<MyData<D>, Edge<D>> v){
		gV->insert(v);
	}

	/**
	* Metodo que agrega Edges a la lista de Aristas del grafo
	* @param e		Puntero a Edge que es agregado a la lista
	*/
	void addE(Edge<D> e){
		gA->insert(e);
	}

	/**
	* Metodo que agrega una arista que conecta un vertice origen con su destino
	* @param e		Puntero a Edge que asigna dicha arista de forma dirigida entre el vertice origen y el destino
	*/
	void assignEdge(Edge<D> e){
		e->orig->aristas->insert(e);
	}
};

#endif /* Graph */
