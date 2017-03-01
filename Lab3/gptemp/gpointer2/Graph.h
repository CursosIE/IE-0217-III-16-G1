/**
* @author Robin Gonzalez - B43011
* @author Giancarlo Marin - B54099
* @date 25-02-2017
* @brief Libreria de la clase Graph que genera Grafos
*/
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include "MyData.h"
#include "Edge.h"
#include "Node.h"
#include "ListWithPointer.h"
#include "Cell.h"

using namespace std;
template<typename Data>/**Libreria de la clase Graph que genera Grafos*/ //E es lo que
class Graph{
public:
	
	ListWithPointer<Edge<Data>*,Cell<Edge<Data>*>>* edges; ///Atrib. publico de tipo puntero a lista que contiene la lista de vertices del grafo///
	int nodos;
//	ListWithPointer<Edge<D>, Cell<Edge<D>>*>* gA; ///Atrib. publico de tipo puntero a lista que contiene la lista de aristas del grafo///
	/**
	* Constructor de la clase Graph
	*/
	Graph(){
		this->edges = nullptr;
//		this->gA = nullptr;
	}

	/**
	* Destructor de la clase Graph
	*/
	~Graph(){
		delete edges;
//		delete gA;
	}

	/**
	* Metodo que agrega Vertices a la lista de Vertices del grafo
	* @param v		Puntero a Vertex que es agregado a la lista
	*/
	void addNode(Data d){
		Edge<Data>* e = new Edge<Data>(-1,new Node<Data>(&d),nullptr);
		this->edges->insert(e);
		++nodos;
	}
	
	/*void  addNode(Node<Data>* n){
		this->nodos->insert(n);
		++nTotales;
	}*/
	
	/**
	* Metodo que agrega conexiones entre nodos en matriz de adyacencias
	* @param e		int 1 es agregado a matriz
	*/
	void addEdge(double w, Node<Data>* p,Node<Data>* s){
		Edge<Data>* e = new Edge<Data>(w,p,s);
		this->edges->insert(e);
		++nodos;
	}

	void delEdge(Node<Data>* s,Node<Data>* d){
		
	//	adyacencias[this->nodos->find(s)][this->nodos->find(d)] = 0;
	}

	void delNode(Node<Data>* d){
	//	this->nodos->remove(d);
//		--nTotales;
	}

	Node <Data>* firstNode(){
//		return this->nodos->get(0);
	}

	Node <Data>* nextNode(Node<Data> *n){
//		return this->nodos->next(n);
	}

	Node <Data>* getNode(int i){
//		return this->nodos->get(i);		
	}
	
	Node <Data>* dfs(int i){
//		int cuenta = 0;
//		while(cuenta < nTotales){
//			for(int c =0;c<nTotales;c++){
//				if(adyacencias[i][c]==1){
//					i = c;
//					cout <<this->getNode(i) << endl;
//					cuenta++;
//				}
//			}
//		}
	}

	Node <Data>* bfs(int i){
		
	}

	Data* getData(Node<Data>* n){
//		return n->d->data;	
	}
	
	double* dijkstra(){
		
	}

	double** floyd(){
		
	}
};

#endif /* Graph */
