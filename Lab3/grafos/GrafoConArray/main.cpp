#include <iostream>
#include "GrafoConArreglo.h"
#include "MyData.h"

#define D int

using namespace std;

int main(int argc, char** argv) {
	//Creacion del grafo
	Graph<int> *g1 = new Graph<int>();
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
	system("Pause");
	return 0;
}


