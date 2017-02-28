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
/*	EN ESTE CODIGO SE USA LA CLASE GRAFOCONARREGLO QUE TIENE COMO ATRIBUTOS UNA LISTACONARREGLOS DONDE SE GUARDAN LOS PUNTEROS DE CADA NODO CREADO Y UNA MATRIZ CUADRADA DE ENTEROS, DONDE LAS ENTRADAS SON 1 SI HAY UNA CONEXION ENRE NODOS Y LOS NODOS SON EL NUMERO DE FILA Y COLUMNA, EN CONCORDANCIA CON SU POSICION EN LA LISTACONARREGLOS ANTERIORMENTE MENCIONADA, PARA ACCEDER A PROPIEDADES DE LOS NODOS SE USAN FUNCIONES DE LIST.H PARA UTILIZAR TODAS LAS DEMAS FUNCIONES SOLO HAY QUE LEER LA MARTIZ (4 ALGORITMOS) O CAMBIAR SUS VALORES PARA PONER O QUITAR CONEXIONES ENTRE NODOS, PARA QUITAR UN NODO SE HACE REMOVE(DE LA LISTACONARREGLOS) Y LUEGO SE CREA LA MATRIZ OTRA VEZ, PARA QUE SE ACTUALICE QUITANDO LA FILA Y COLUMNA DEL NODO ELIMINADO DONDE AHORA IRA OTRO NODO*/
	return 0;
}


