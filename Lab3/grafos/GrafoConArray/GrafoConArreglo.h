/**
* @author Giancarlo Marin - B54099
* @author Robin Gonzalez Ricz - B43011
* @author Giancarlo Marin - B54099
* @date 25-02-2017
* @brief Biblioteca de la clase Graph que genera Grafos
*/
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include "MyData.h"
#include "ListWithArray.h"

using namespace std;
template<typename D>/**Biblioteca de la clase Graph que genera Grafos*/
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
	void addNode(Data d){

	}
	
	/**
	* Metodo que agrega Edges a la lista de Aristas del grafo
	* @param e		Puntero a Edge que es agregado a la lista
	*/
	void addEdge(double w, Node<Data>* s,Node<Data>* d){
		gA->insert(e);	
	}

	void delEdge(){
		
	}

	void delNode(){
		
	}

	Node <Data>* firstNode(){
		
	}

	Node <Data>* nextNode(Node<Data> n){
		
	}

	Node <Data>* Node(int i){
		
	}
	
	Node <Data>* dfs(int i){
		
	}

	Node <Data>* bfs(int i){
		
	}

	Data* getData(Node<Data>* n){
			
	}
	
	double* dijkstra(){
		
	}

	double** floyd(){
		
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
