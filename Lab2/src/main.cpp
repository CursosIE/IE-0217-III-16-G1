/**
 * Universidad de Costa Rica - Escuela de Ingenieria ELectrica
 * IE-0217 - Lab2: Estructuras de datos lineales
 * @author Giancarlo Marin - B54099
 * @date 21-02-2017	
 * @brief Programa de prueba para la implementacion de listas, pilas y colas
 */
#include <iostream>
#include "../include/ListWithArray.h"
#include "../include/ListWithPointer.h"
#include "../include/Cell.h"
#include "../include/Stack.h"
#include "../include/Queue.h"

using namespace std;

/**
 * Main del programa que realiza las pruebas de las estructuras lineales
 * @param int 		Indicador de la cantidad de argumentos pasados en la ejecucion del programa
 * @param char**	Vector de char* que contiene los argumentos enviados al ejecutar el programa
 * @return 
 */
int main(int argc, char** argv) {
    ListWithArray<double, int>* l0 = new ListWithArray<double, int>(5); /**<Lista implementada con arreglos */
    ListWithPointer<double, Cell<double>*>* l1 = new ListWithPointer<double, Cell<double>*>(); /**<Lista implementada con punteros */
    
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

	//Impresion en pantalla de las listas 
	cout << "----- TAMAÑOS -----" << endl;
	cout << "----- ListWithArray y su tamaño -----" << endl;
	l0->printList();
	cout << l0->getSize() << endl;
	cout << "----- ListWithPointer y su tamano -----" << endl;
	l1->printList();
	cout << l1->getSize() << endl;

	//Ordenar listas
	l0->sort();
	l1->sort();
	
	//Impresion en pantalla de las listas 
	cout << "----- LISTAS ORDENADAS -----" << endl;
	cout << "----- ListWithArray -----" << endl;
	l0->printList();
	cout << "----- ListWithPointer -----" << endl;
	l1->printList();

	//Crear Pila
	cout << "----- CREANDO STACK -----" << endl;
	Stack<double, Cell<double>*>* p0 = new Stack<double, Cell<double>*>();/**<Pila implementada con punteros tomando como base una lista de punteros*/

	//Agregando valor por valor e imprimiendo su top
	cout << "----- INSERTANDO VALORES (PUSH) -----" << endl;
	p0->push(5.5);
	p0->top();
	p0->push(1.1);
	p0->top();
	p0->push(88.8);
	p0->top();
	p0->push(77.7);
	p0->top();
	p0->push(101.01);
	p0->top();
	p0->push(99.9);
	p0->top();
	p0->push(31.31);
	p0->top();

	//POP de varios valores
	cout << "----- SACANDO ELEMENTOS (POP) -----" << endl;
	Cell<double>* d0 = p0->pop();
	Cell<double>* d1 = p0->pop();
	cout << "Elementos retirados: " << *(d0->data) << ", " << *(d1->data) << endl;
	cout << "Top del Stack: ";
	p0->top();

	//POP de varios valores
	cout << "----- VACIAR STACK (EMPTY) -----" << endl;
	p0->emptyStack();

//Crear Cola
	cout << "----- CREANDO COLA -----" << endl;
	Queue<double, Cell<double>*>* q0 = new Queue<double, Cell<double>*>();/**<Cola implementada con punteros tomando como base una lista de punteros

/*	//Agregando valor por valor
	cout << "----- INSERTANDO VALORES (PUSH) -----" << endl;
	q0->push(5.5);
	q0->push(1.1);
	q0->push(88.8);
	q0->push(77.7);
	q0->push(101.01);
	q0->push(99.9);
	q0->push(31.31);
	
	q0->printQueue();
	
	//POP de varios valores
	cout << "----- SACANDO ELEMENTOS (POP) -----" << endl;
	Cell<double>* q0 = q0->pop();
	Cell<double>* q1 = q0->pop();
	cout << "Elementos retirados: " << *(q0->data) << ", " << *(q1->data) << endl;
	cout << "Top del Stack: ";

	//POP de varios valores
	cout << "----- VACIAR QUEUE (EMPTY) -----" << endl;
	q0->emptyQueue();*/

    return 0;
}

