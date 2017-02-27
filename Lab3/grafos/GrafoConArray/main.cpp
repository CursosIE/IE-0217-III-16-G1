#include <iostream>
#include "GrafoConArreglo.h"
#include "MyData.h"


#define D int

using namespace std;

int main(int argc, char** argv) {
	//Creacion del grafo
	Graph<int> *g1 = new Graph<int>();
	//Creacion de vertices y asignacion de datos
	//Vertex<MyData<int>, Edge<int>>* v2 = new Vertex<MyData<int>, Edge<int>>();
cout << "Vieja konfiable debugger " << endl;
	Node<D>* n1 = new Node<D>(2);
	Node<D>* n2 = new Node<D>(5);
	Node<D>* n3 = new Node<D>(1);
	Node<D>* n4 = new Node<D>(8);
	Node<D>* n5 = new Node<D>(33);
cout << "Vieja konfiable debugger " << endl;
	
	g1->addNode(n1);
	g1->addNode(n2);
	g1->addNode(n3);
	g1->addNode(n4);
	g1->addNode(n5);
cout << "Vieja konfiable debugger " << endl;

	g1->adyacencias = g1->creaM();
cout << "Vieja konfiable debugger " << endl;
	
	g1->addEdge(n1,n2);
	g1->addEdge(n1,n3);
	g1->addEdge(n1,n5);
	g1->addEdge(n2,n4);
	g1->addEdge(n4,n5);
	g1->addEdge(n3,n2);
cout << "Vieja konfiable debugger " << endl;

	g1->printMat();

cout << "Vieja konfiable debugger " << endl;
/*	v1->data = new MyData<int>(2);
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


