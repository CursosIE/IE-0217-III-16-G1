/**
* Universidad de Costa Rica - Escuela de Ingenieria ELectrica
* IE-0217 - Lab3: Estructuras de datos no lineales
* @author Robin Gonzalez - B43011	
* @author Giancarlo Marin - B54099
* @date 26-02-2017
* @brief Programa de prueba para la implementacion de Grafos con punteros
*/
#include <iostream>
#include "Graph.h"
#include "MyData.h"
#include "ListWithPointer.h"
#include "Edge.h"
#include "Node.h"

//#include "../../include/gwp/graphWithPointer.h"

#include <iostream>

#define D int

using namespace std;


int main(int argc, char** argv) {
	//Creacion del grafo
//	Graph<int> *g1 = new Graph<int>();
/*	g1->addNode(23);
	g1->addNode(33);
	g1->addNode(2);
	g1->addNode(3);/*/
	
	MyData<D> datito = MyData<D>(2342);
	cout << "dato en MyData " << &datito << " es :"<< datito.data <<endl;//flecha cuando es puntero, punto cuando es objeto.
	Cell<D> celda = Cell<D>(new D(123), nullptr);
	cout << "dato en Celda " << &celda << " es :"<< *celda.data << " y next es: " <<celda.next << endl;//flecha cuando es puntero, punto cuando es objeto.	
	Cell<D> celda2 = Cell<D>();
	celda2.data = new D(321);
	celda2.next = &celda;
	cout << "dato en Celda " << &celda2 << " es :"<< *celda2.data << " y next es: " <<celda2.next << endl;//flecha cuando es puntero, punto cuando es objeto.	
	celda.~Cell();
	celda2.~Cell();
	datito.~MyData();
	ListWithPointer<D,Cell<D>*> listita = ListWithPointer<D,Cell<D>*>();
	listita.insert(1);
	listita.insert(2);
	listita.insert(3);
	listita.insert(4);
	listita.insert(5);
	listita.printList();
	Node<D> nodito = Node<D>(new D(2509));
	cout << "Dato en Nodo " << &nodito << " es :"<< *nodito.data << endl;
	Node<D> nodito2 = Node<D>(new D(250));
	cout << "Dato en Nodo " << &nodito2 << " es :"<< *nodito2.data << endl;
	Node<D> nodito3 = Node<D>(new D(33));
	Node<D> nodito4 = Node<D>(new D(457));
	//cout << nodito << endl;
	ListWithPointer<Node<D>,Cell<Node<D>>*>* l = new ListWithPointer<Node<D>,Cell<Node<D>>*>();
	l->insert(nodito);
	l->insert(nodito2);
	//cout << l->find(nodito) << endl;//se cae
	cout << "funca" << endl;
	Edge<D>* arista;
	arista = new Edge<D>();
	arista->peso = 1.2;
	arista->orig = &nodito;
	arista->dest = &nodito2;
	cout << arista->peso << endl;
	cout << arista->orig << endl;
	cout << arista->dest << endl;
	Edge<D>* arista2;
	arista2 = new Edge<D>(0.9 ,&nodito2,&nodito4);
	Edge<D>* arista3 = new Edge<D>(0.9 ,&nodito2,&nodito3);
	ListWithPointer<Edge<D>,Cell<Edge<D>*>* l2 = new ListWithPointer<Edge<D>,Cell<Edge<D>>*>();
	l2->insert(*arista);
	l2->insert(*arista2);
	l2->insert(*arista3);
	Graph<D> g = Graph<D>();
	g.addNode(777);
	g.addNode(7);
	g.addNode(77);
	g.addNode(7777);
	g.addNode(77777);
	g.addNode(777777);
	g.addEdge(12, g.getNode(3),g.getNode(6));
	g.addEdge(12, g.getNode(3),g.getNode(1));
	g.delEdge(g.getNode(3),g.getNode(1));
	g.delNode(g.getNode(2));
	g.firstNode();
	g.nextNode(g.getNode(3));
	g.getData(g.getNode(3));
	g.dfs(32);
/*	Node <Data>* bfs(int i)
	double* dijkstra()
	double** floyd()*/

	//g1->edges->printList();
/*
	//Creacion de vertices y asignacion de datos
	Vertex<MyData<int>, Edge<int>>* v1 = new Vertex<MyData<int>, Edge<int>>();
	Vertex<MyData<int>, Edge<int>>* v2 = new Vertex<MyData<int>, Edge<int>>();
	v1->data = new MyData<int>(2);
	v2->data = new MyData<int>(5);
	//Agregar vertices a la lista de vertices del grafo
	g1->addV(*v1);
	g1->addV(*v2);
	//Creacion de aristas
	Edge<int> *e1 = new Edge<int>(1.1, v1, v2);
	Edge<int> *e2 = new Edge<int>(2.2, v2, v1);
	//Agregar aristas a la lista de aristas del grafo
	g1->addE(*e1);
	g1->addE(*e2);
	system("Pause");*/
	return 0;
}


