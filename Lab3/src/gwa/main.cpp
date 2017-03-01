/**
* Universidad de Costa Rica - Escuela de Ingenieria ELectrica
* IE-0217 - Lab3: Estructuras de datos no lineales
* @author Giancarlo Marin - B54099
* @date 26-02-2017
* @brief Programa de prueba para la implementacion de Grafos con arreglos
*/
#include <iostream>
#include "../../include/gwa/Data.h"
#include "../../include/gwa/GraphWithArray.h"
#define D int

using namespace std;

/**
* Main del programa que realiza las pruebas del Grafo con arreglos
* @param int 		Indicador de la cantidad de argumentos pasados en la ejecucion del programa
* @param char**	Vector de char* que contiene los argumentos enviados al ejecutar el programa
* @return
*/
int main(int argc, char** argv) {
	cout << "------ GRAPHWITHARRAY (GRAFO CON ARREGLO) -----" << endl;
	cout << "--- CREANDO GRAFO ---" << endl;
	GraphWithArray<D, double>* g1 = new GraphWithArray<D, double>();
	cout << "--- AGREGANDO VERTICES ---" << endl;
	g1->addNode(Data<D>(new int(5)));
	g1->addNode(Data<D>(new int(10)));
	g1->addNode(Data<D>(new int(15)));
	g1->addNode(Data<D>(new int(20)));
	g1->addNode(Data<D>(new int(25)));
	g1->addNode(Data<D>(new int(30)));
	cout << "--- VERTICES DEL GRAFO ---" << endl;
	g1->nodos->printList();
	cout << "--- AGREGANDO ARISTAS ---" << endl;
	g1->addEdge(1.1, g1->nodos->get(0), g1->nodos->get(3));
	g1->addEdge(2.2, g1->nodos->get(0), g1->nodos->get(5));
	g1->addEdge(3.3, g1->nodos->get(1), g1->nodos->get(0));
	g1->addEdge(4.4, g1->nodos->get(1), g1->nodos->get(4));
	g1->addEdge(5.5, g1->nodos->get(1), g1->nodos->get(5));
	g1->addEdge(6.6, g1->nodos->get(2), g1->nodos->get(4));
	g1->addEdge(7.7, g1->nodos->get(2), g1->nodos->get(5));
	g1->addEdge(8.8, g1->nodos->get(3), g1->nodos->get(1));
	g1->addEdge(9.9, g1->nodos->get(3), g1->nodos->get(4));
	g1->addEdge(10.1, g1->nodos->get(3), g1->nodos->get(5));
	g1->addEdge(11.2, g1->nodos->get(5), g1->nodos->get(2));
	cout << "--- MATRIZ DE ADYACENCIA ---" << endl;
	g1->printM();
	//Eliminar Nodos
	cout << "--- PRUEBA DE ELIMINACION DE VERTICES ---" << endl;
	Data<D> temp = Data<D>(new int(20));
	cout << "Eliminando Vertice: " << *(temp.data) << endl;
	g1->delNode(temp);
	cout << "--- VERTICES DEL GRAFO ---" << endl;
	g1->nodos->printList();
	cout << "--- MATRIZ DE ADYACENCIA ---" << endl;
	g1->printM();
	//Eliminar Aristas
	cout << "--- PRUEBA DE ELIMINACION DE ARISTAS ---" << endl;
	temp = Data<D>(new int(15));
	Data<D> temp2 = Data<D>(new int(25));
	cout << "Eliminando Arista de: " << *(temp.data) << " a " << *(temp2.data) << endl;
	g1->delEdge(g1->nodos->get(g1->nodos->find(temp)), g1->nodos->get(g1->nodos->find(temp2)));
	cout << "--- MATRIZ DE ADYACENCIA ---" << endl;
	g1->printM();
	//Prueba de busqueda
	temp = Data<D>(new int(15));
	cout << "--- PRUEBA DE BUSQUEDA EN PROFUNDIDAD ---" << endl << "Buscando: " << *(temp.data) << endl;
	Data<D> a = g1->dfs(temp);
	if (*(a.data)!=-1){
		cout << *(a.data) << " Encontrado en el grafo" << endl;
	}
	else{
		cout << "Vertice no encontrado" << endl;
	}
	temp = Data<D>(new int(30));
	cout << "--- PRUEBA DE BUSQUEDA EN ANCHURA ---" << endl << "Buscando: " << *(temp.data) << endl;
	a = g1->bfs(temp);
	if (*(a.data) != -1){
		cout << *(a.data) << " Encontrado en el grafo" << endl;
	}
	else{
		cout << "Vertice no encontrado" << endl;
	}
	cout << "ELIMINANDO EL GRAFO..." << endl;
	delete g1;
	return 0;
}
