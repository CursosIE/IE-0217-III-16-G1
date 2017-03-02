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
	
	ListWithPointer<Edge<Data>,Cell<Edge<Data>>*>* edges; ///Atrib. publico de tipo puntero a lista que contiene la lista de aristas del grafo///
	int nodos;
	int aristas;
	ListWithPointer<Node<Data>, Cell<Node<Data>>*>* nodes; ///Atrib. publico de tipo puntero a lista que contiene la lista de nodos del grafo///
	/**
	* Constructor de la clase Graph
	*/
	Graph(){
		this->edges = nullptr;
		this->nodes = nullptr;
	}

	/**
	* Destructor de la clase Graph
	*/
	~Graph(){
		delete edges;
		delete nodes;
	}

	/**
	* Metodo que agrega Vertices a la lista de Vertices del grafo
	* @param v		Puntero a Vertex que es agregado a la lista
	*/
	void addNode(Data d){
		Node<Data>* n = new Node<Data>(new Data(d));
		if(!this->nodes) this->nodes = new ListWithPointer<Node<Data>,Cell<Node<Data>>*>();
		this->nodes->insert(*n);
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
		if(!this->edges) this->edges = new ListWithPointer<Edge<Data>,Cell<Edge<Data>>*>();
		this->edges->insert(e);
		++aristas;
	}

	void delEdge(Node<Data>* s,Node<Data>* d){
		Edge<Data> buscado = Edge<Data>(0,s,d);
		Cell<Edge<Data>>* ctemp = this->edges->find(buscado);
		this->edges->remove(*(ctemp->data));			
		--aristas;
	}

	void delNode(Node<Data>* d){
		Cell<Edge<Data>>* pos = this->edges->first;
		while(pos!=this->edges->last){
			if(*(pos->data->orig)==*d || *(pos->data->dest)==*d){
				this->delEdge(pos->data->orig,pos->data->dest);
			}
			pos = this->edges->next(pos);
		}
		if(*(pos->data->orig)==*d || *(pos->data->dest)==*d){
			this->delEdge(pos->data->orig,pos->data->dest);
		}
		this->nodes->remove(*d);
		--nodos;
	}

	Node <Data>* firstNode(){
		return this->nodes->first->data;
	}

	Node <Data>* nextNode(Node<Data> *n){
		return (this->nodes->next(this->nodes->find(*n))->data);
	}

	Node <Data>* getNode(int i){
//		return this->nodos->get(i);		
	}
	
	Data* getData(Node<Data>* n){
//		return n->d->data;	
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

	double* dijkstra(){
		
	}

	double** floyd(){
		
	}
};

#endif /* Graph */
