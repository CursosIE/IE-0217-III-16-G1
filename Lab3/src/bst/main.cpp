/**
 * Universidad de Costa Rica - Escuela de Ingenieria ELectrica
 * IE-0217 - Lab3: Estructuras de datos no lineales
 * @author Giancarlo Marin - B54099
 * @date 26-02-2017	
 * @brief Programa de prueba para la implementacion de arboles BST
 */

#include <iostream>
#include "../../include/bst/Node.h"
#include "../../include/bst/BST.h"
#include "../../include/bst/Data.h"
#define D int

using namespace std;

/**
 * Main del programa que realiza las pruebas del arbol BST
 * @param int 		Indicador de la cantidad de argumentos pasados en la ejecucion del programa
 * @param char**	Vector de char* que contiene los argumentos enviados al ejecutar el programa
 * @return 
 */
int main(int argc, char** argv) {
	cout << "------ ARBOL BST -----" << endl;
	cout << "--- CREANDO ARBOL ---" << endl;
    BST<D>* bst1 = new BST<D>(new D(10));
    bst1->insert(new D(15));
    bst1->insert(new D(5));
    bst1->insert(new D(8));
    bst1->printTree();
	cout << "--- PreOrden ---" << endl;
	bst1->preOrder(bst1->root, "");
	cout << "--- PostOrden ---" << endl;
	bst1->postOrder(bst1->root, "");
	//Prueba de busqueda
	int* temp = new int(15);
	cout << "--- PRUEBA DE BUSQUEDA ---" << endl << "Buscando: " << *temp << endl;
    Node<D>* r = bst1->find(new D(15));
    if (r) {
        cout << *(r->d) << " Encontrado en el arbol" << endl;
    } else {
        cout << "Nodo no encontrado" << endl;
    }

	//Impresion del mayor de lo menores
	cout << "--- MAYOR DE LOS MENORES ---" << endl;
    r = bst1->maxLesser(bst1->root);
    if (r) {
        cout << *(r->d) << endl;
    } else {
        cout << "No existe" << endl;
    }
	//Impresion del menor de los mayores
	cout << "--- MENOR DE LOS MAYORES ---" << endl;
    r = bst1->minGreater(bst1->root);
    if (r) {
        cout << *(r->d) << endl;
    } else {
        cout << "No existe" << endl;
    }
	//Prueba de eliminacion de hoja
	temp = new int(8);
	cout << "--- PRUEBA DE ELIMINACION DE HOJA ---" << endl;
	cout << "Eliminando " << *temp << "..." << endl;
    bst1->remove(temp);
    bst1->printTree();
	//Nuevas inserciones
	cout << "Insertando mas valores al arbol..." << endl;
	bst1->insert(new int(12));
	bst1->insert(new int(3));
	bst1->insert(new int(6));
	bst1->printTree();
	//Prueba de eliminacion de la raiz
	temp = new int(10);
	cout << "--- PRUEBA DE ELIMINACION DE LA RAIZ---" << endl;
	bst1->remove(temp);
	bst1->printTree();
	//Liberando memoria dinamica
	cout << "ELIMINANDO EL ARBOL..." << endl;
	delete temp;
	delete bst1;
    return 0;
}

