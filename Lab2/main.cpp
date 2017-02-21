#include <iostream>
#include "ListWithArray.h"
#include "ListWithPointer.h"
#include "Cell.h"

using namespace std;

int main(int argc, char** argv) {
    ListWithArray<double, int>* l0 = new ListWithArray<double, int>(5);
    ListWithPointer<double, Cell<double>*>* l1 = new ListWithPointer<double, Cell<double>*>();
    
	//Impresion en pantalla de las listas
	cout << "----- CREACION DE LISTAS -----" << endl;
	cout << "----- ListWithArray -----" << endl;
	l0->printList();
	cout << "----- ListWithPointer -----" << endl;
	l1->printList();

	//Inserciones en ambas listas
	l0->insert(1.1);
	l1->insert(1.1);
	l0->insert(2.2);
	l1->insert(2.2);
	l0->insert(3.3);
	l1->insert(3.3);
	l0->insert(4.4);
	l1->insert(4.4);
	l0->insert(5.5);
	l1->insert(5.5);
	
	//Impresion en pantalla de las listas 
	cout << "----- INSERCION -----" << endl;
	cout << "----- ListWithArray -----" << endl;
	l0->printList();
	cout << "----- ListWithPointer -----" << endl;
	l1->printList();

	//Remover elementos de las listas listas
	l0->remove(1.1);
	l1->remove(1.1);
	l0->remove(3.3);
	l1->remove(3.3);

	//Impresion en pantalla de las listas 
	cout << "----- REMOCION -----" << endl;
	cout << "----- ListWithArray -----" << endl;
	l0->printList();
	cout << "----- ListWithPointer -----" << endl;
	l1->printList();

	//Asignar valores en las listas
	l0->assign(0,11.1);
	l1->assign(l1->find(2.2),11.1);
	l0->assign(2,33.3);
	l1->assign(l1->find(5.5), 33.3);

	//Impresion en pantalla de las listas 
	cout << "----- ASIGNACION -----" << endl;
	cout << "----- ListWithArray -----" << endl;
	l0->printList();
	cout << "----- ListWithPointer -----" << endl;
	l1->printList();

	//Agregar valores y tamaños diferentes
	l0->insert(12.12);
	l1->insert(12.12);
	l0->insert(8.8);
	l1->insert(8.8);
	l1->insert(9.9);
	l1->insert(7.9);

	//Impresion en pantalla de las listas 
	cout << "----- TAMAÑOS -----" << endl;
	cout << "----- ListWithArray y su tamaño -----" << endl;
	l0->printList();
	cout << l0->getSize() << endl;
	cout << "----- ListWithPointer y su tamaño -----" << endl;
	l1->printList();
	cout << l1->getSize() << endl;
//PRUEBAS PARA ORDENAR
//	cout << "Primero" << l1->first << endl;	
//	cout << "último" << l1->last << endl;	
	//ordenar lista con punteros	
	l1->sort();
	cout << "----- lista con púnteros ordenada y su tamaño -----" << endl;
	l1->printList();
	cout << l0->getSize() << endl;

    return 0;
}

