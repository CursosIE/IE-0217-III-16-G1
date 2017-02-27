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
#include "Node.h"

using namespace std;
template<typename Data>/**Biblioteca de la clase Graph que genera Grafos*/
class Graph{
public:
	//ListWithPointer<Vertex<MyData<D>, Edge<D>>, Cell<Vertex<MyData<D>,Edge<D>>>*>* gV; ///Atrib. publico de tipo puntero a lista que contiene la lista de vertices del grafo///
	//ListWithPointer<Edge<D>, Cell<Edge<D>>*>* gA; ///Atrib. publico de tipo puntero a lista que contiene la lista de aristas del grafo///
	
	int nTotales;
	int** adyacencias;
	ListWithArray<Node<Data>*, int>* nodos;

	/**
	* Constructor de la clase Graph
	*/
	Graph(){
		int** adyacencias = nullptr;
		nodos = new ListWithArray<Node<Data>*,int>();
	}

	/**
	* Destructor de la clase Graph
	*/
	~Graph(){

	}
	
	int** creaM(){
		int** adyaTemp;
		if(adyacencias){
			adyaTemp = allocMat(nTotales,nTotales);//new int[nTotales][nTotales];
			for(int i = 0;i<nTotales;i++){
				if(this->adyacencias[i]){
					for(int j = 0; j<nTotales;j++){
						if(this->adyacencias[i][j]){
						adyaTemp[i][j] = adyacencias[i][j];
						}
					
					}
				}
			}
		}
		else{
			adyaTemp = allocMat(nTotales,nTotales);//new int[nTotales][nTotales];
		}
		return adyaTemp;
	}	
	
	static int** allocMat(int row, int col){
		int** arr = new int*[row];
		for(int i = 0; i < row; i++)arr[i] = new int[col];
		return arr;
	}
	
	void printMat(){
		for(int i=0;i<nTotales;i++){
			for(int j=0;j<nTotales;j++){
				cout << adyacencias[i][j] << "\t";
			}
			cout << "\n";	
		}	
	}
	/**
	* Metodo que agrega Vertices a la lista de Vertices del grafo
	* @param v		Puntero a Vertex que es agregado a la lista
	*/
	void addNode(Data d){
		if(!adyacencias)adyacencias = new int[5][5];
		Node<Data>* n= new Node<Data>(d);
		this->nodos->insert(n);
		++nTotales;
	}
	
	void  addNode(Node<Data>* n){
		this->nodos->insert(n);
		++nTotales;
	}
	
	/**
	* Metodo que agrega conexiones entre nodos en matriz de adyacencias
	* @param e		int 1 es agregado a matriz
	*/
	void addEdge( Node<Data>* s,Node<Data>* d){
		adyacencias[this->nodos->find(s)][this->nodos->find(d)] = 1;
	}

	void delEdge(Node<Data>* s,Node<Data>* d){
		adyacencias[this->nodos->find(s)][this->nodos->find(d)] = 0;
	}

	void delNode(Node<Data>* d){
		this->nodos->remove(d);
		--nTotales;
	}

	Node <Data>* firstNode(){
		return this->nodos->get(0);
	}

	Node <Data>* nextNode(Node<Data> *n){
		return this->nodos->next(n);
	}

	Node <Data>* getNode(int i){
		return this->nodos->get(i);		
	}
	
	Node <Data>* dfs(int i){
		
	}

	Node <Data>* bfs(int i){
		
	}

	Data* getData(Node<Data>* n){
		return n->d->data;	
	}
	
	double* dijkstra(){
		
	}

	double** floyd(){
		
	}
	

	
};

#endif /* Graph */
