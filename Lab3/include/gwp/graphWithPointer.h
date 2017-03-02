/**
* @author Robin Gonzalez - B43011
* @author Giancarlo Marin - B54099
* @date 25-02-2017
* @brief Libreria de la clase Graph que genera Grafos
*/
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include "Edge.h"
#include "ListWithPointer.h"

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
	* Metodo que agrega Nodos a la lista de Nodos del grafo
	* @param a		Puntero a Nodos que es agregado a la lista
	*/
	void addNode(Data d){
		Node<Data>* n = new Node<Data>(new Data(d));
		if(!this->nodes) this->nodes = new ListWithPointer<Node<Data>,Cell<Node<Data>>*>();
		this->nodes->insert(*n);
		++nodos;
	}
		
	/**
	* Metodo que agrega conexiones entre nodos creando un objeto arista
	* @param b		double peso de la conexion
	* @param c		puntero a nodo origen
	* @param d		puntero a nodo destino
	*/
	void addEdge(double w, Node<Data>* p,Node<Data>* s){
		Edge<Data> e = Edge<Data>(w,p,s);
		p->nodos->insert(*s);
		if(!this->edges) this->edges = new ListWithPointer<Edge<Data>,Cell<Edge<Data>>*>();
		this->edges->insert(e);
		++aristas;
	}
	/**
	* Metodo que elimina una arista
	* @param e		Puntero a Nodos que son extremos de arista a eliminar
	*/
	void delEdge(Node<Data>* p,Node<Data>* s){
		Edge<Data> buscado = Edge<Data>(0,p,s);
		p->nodos->remove(*s);
		Cell<Edge<Data>>* ctemp = this->edges->find(buscado);
		this->edges->remove(*(ctemp->data));			
		--aristas;
	}
	/**
	* Metodo que elimina un nodo
	* @param f		Puntero a Nodos que es eliminido
	*/
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
	/**
	* Metodo que retorna primer nodo
	* @param g	
	*/
	Node <Data>* firstNode(){
		return this->nodes->first->data;
	}
	/**
	* Metodo que retorna el siguiente nodo
	* @param h		Puntero a Nodos
	*/
	Node <Data>* nextNode(Node<Data> *n){
		return (this->nodes->next(this->nodes->find(*n))->data);
	}
	/**
	* Metodo que reotrna nodo
	* @param i		int posicion
	*/
	Node <Data>* getNode(int i){
		Cell<Node<Data>>* temp = this->nodes->first;
			cout << i << endl;
		for(int c = 0; c < i; c++){
			temp = temp->next;
			cout << "se mueve " << c<< endl;
		}
		return temp->data;
	}
		/**
	* Metodo retorna data
	* @param j		
	*/
	Data* getData(Node<Data>* n){
		return n->data;
	}
	/**
	*  Algoritmo dfs
	* @param k
	*/
	Node <Data>* dfs(int i){
	}
	/**
	*  Algoritmo bfs
	* @param m
	*/
	Node <Data>* bfs(int i){
		Node<Data> camino [this->nodos];
		Cell<Node<Data>>* temp = this->nodes->first;
		Cell<Node<Data>>* temp2;
		ListWithPointer<Node<Data>,Cell<Node<Data>*>>* visitados;
		for(int c = 0; c < i; c++){
			temp = temp->next;
		}
		int conta = 1;
		while(conta!=nodos){
			temp2 = temp->data->nodos->first;
			for(int i= 0;i < temp->data->nodos->getSize();i++){
				temp2 = temp2->next;
				if(!visitados->find(*(temp2->data))){
					visitados->insert(*(temp2->data));
					conta++;
					camino[conta] = temp2->data;
				}
			}	
		}
		return camino;
	}
	/**
	* Algoritmo Dijsktra
	* @param n	
	*/
	double* dijkstra(){
		
	}
	/**
	* Algoritmo Floyd
	* @param l		
	*/
	double** floyd(){
		
	}
};

#endif /* Graph */
