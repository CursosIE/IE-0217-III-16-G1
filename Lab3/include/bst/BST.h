/**
 * @author Robin Gonzalez Ricz - B43011
 * @author Giancarlo Marin - B54099
 * @date 25-02-2017	
 * @brief Libreria del Binary Search Tree (BST) emplantillado
 */
#ifndef BST_H
#define BST_H

#include <iostream>
#include <string>
#include "Node.h"
#include "Data.h"

using namespace std;

template <typename Data>
class BST{
public:

/**
 * Constructor de la clase BST
 */
    BST() {
    }

/**
 * Constructor sobrecargado de la clase BST
 * @param r 	Puntero a la raiz del arbol
 */ 
    BST(Node<Data>* r) {
        this->root = r;
    }

/**
 * Constructor sobrecargado de la clase BST
 * @param d 	Puntero al dato que se asignara como raiz del arbol
 */
    BST(Data* d) {
        this->root = new Node<Data>(nullptr, nullptr, d, nullptr);
    }

/**
 * Destructor de la clase BST
 */
    virtual ~BST() {
    }

/**
 * Metodo insertar del arbol BST: Agrega una nueva hoja y en caso de no existir raiz tambien la agrega
 * @param d 	Puntero al dato que se asignara al nuevo nodo hoja 
 */
    void insert(Data* d) {
        if (this->root == nullptr) {
            root = new Node<Data>(nullptr, nullptr, d, nullptr);
        } else {
            Node<Data>* t = root;
            bool end = 0;
            while (!end) {
                if (*d < *(t->d)) {
                    if (t->l == nullptr) {
                        t->l = new Node<Data>(nullptr, nullptr, d, t);
                        end = 1;
                    }
					else if (t->l != nullptr) {
                            t = t->l;
                    }
				}
				else if (t->r == nullptr) {
					t->r = new Node<Data>(nullptr, nullptr, d, t);
					end = 1;
                } else if (t->r != nullptr) {
					t = t->r;
				}
			}
		}
		this->nodes++;
	}

/**
 * Metodo removiendo del arbol BST: Elimina un Nodo del arbol y reasigna algun nodo a su posicion en caso de ser un nodo intermedio o raiz
 * @param n 	Puntero al nodo que se desea eliminar
 */
    void removing(Node<Data>* n) {
        if (n && n->l == n->r && n->r == nullptr) //Determina si es hoja
        {
            delete n;
			this->nodes--;
        } else {
            Node<Data>* t = replacementFor(n);
            if (t) {
                *(n->d) = *(t->d);
                removing(t);
            }
        }
    }

/**
 * Metodo remover del arbol BST: Busca si el dato por eliminar es parte del arbol y si lo encuentra lo elimina utilizando removing
 * @param n 	Puntero al dato que se desea eliminar
 */
    void remove(Data* d) {
        removing(find(d));
    }

/**
 * Metodo obtener del arbol BST: Busca si un nodo es parte del arbol y si lo encuentra devuelve el dato que contiene
 * @param n 	Puntero al nodo que se desea obtener el dato
 * @return 	Puntero al dato del nodo n 
 */
    Data* get(Node<Data>* n) {
		Node<Data>* temp = find(n);
		if (temp != nullptr){
			return temp->d;
		}
		return nullptr;
    }

/**
 * Metodo asignar del arbol BST: Busca si un nodo es parte del arbol y si lo encuentra asigna un nuevo dato a este
 * @param n 	Puntero al nodo que se desea asignar dato
 * @param d	Puntero al dato que se asignara al nodo n 
 */
    void set(Node<Data>* n, Data * d) {
		Node<Data>* temp = find(n);
		if (temp != nullptr){
			temp->d = d;
		}
    }

/**
 * Metodo encontrando del arbol BST: Busca si un dato es parte del subarbol que tiene como raiz el nodo n
 * @param d	Puntero al dato que se desea buscar
 * @param n 	Puntero al nodo que se toma como raiz del subarbol
 * @return 	Puntero al nodo que posee el dato d
 */
    Node<Data>* finding(Data* d, Node<Data>* n) {
        if (n && *(n->d) == *d) {

            return n;
        } else {
            if (n && *(n->d) > *d) {
                return finding(d, n->l);
            } else {
                if (n) {
                    return finding(d, n->r);
                } else {
                    return nullptr;
                }
            }
        }
    }

/**
 * Metodo buscar del arbol BST: Busca si un dato es parte del arbol
 * @param d	Puntero al dato que se desea buscar
 * @return 	Puntero al nodo que posee el dato d
 */
    Node<Data>* find(Data* d) {
        return finding(d, this->root);
    }

/**
 * Metodo imprimir arbol BST, imprime EnOrden el arbol
 */
    void printTree() {
		cout << "--- InOrder ---" << endl;
        this->inOrder(root, "");
    }

/**
 * Metodo recorrido EnOrden del arbol BST
 * @param n	Puntero a la raiz del arbol que se desea recorrer
 * @param s	String donde se escribira el recorrido del arbol
 * @return 	String del recorrido del arbol donde cada nodo se separa por un tab
 */
    string inOrder(Node<Data>* n, string s) {
		if (n) {
			s = inOrder(n->l, s);
			s = s + to_string(*(n->d)) + "\t";
			cout << s << endl;
			s = inOrder(n->r, s);
		}
		return s;
    }

/**
 * Metodo recorrido EnPreOrden del arbol BST
 * @param n	Puntero a la raiz del arbol que se desea recorrer
 * @param s	String donde se escribira el recorrido del arbol
 * @return 	String del recorrido del arbol donde cada nodo se separa por un tab
 */
	string preOrder(Node<Data>* n, string s) {
		if (n) {
			s = s + to_string(*(n->d)) + "\t";
			cout << s << endl;
			s = preOrder(n->l, s);
			s = preOrder(n->r, s);
			return s;
		}
		return s;
	}

/**
 * Metodo recorrido EnPostOrden del arbol BST
 * @param n	Puntero a la raiz del arbol que se desea recorrer
 * @param s	String donde se escribira el recorrido del arbol
 * @return 	String del recorrido del arbol donde cada nodo se separa por un tab
 */
	string postOrder(Node<Data>* n, string s) {
		if (n) {
			s = postOrder(n->l, s);
			s = postOrder(n->r, s);
			s = s + to_string(*(n->d)) + "\t";
			cout << s << endl;
		}
		return s;
	}

/**
 * Metodo sustitucionPor para nodos del arbol BST
 * @param n	Puntero al nodo que se le desea remplazar el dato
 * @return 	Puntero al nodo que posee el dato por el que se sustituira 
 */
    Node<Data>* replacementFor(Node<Data>* n) {
        if (n) {
            if (n->l) {
                return maxLesser(n);
            } else {
                if (n->r) {
                    return minGreater(n);
                }
            }
        }
        return nullptr;
    }

/**
 * Metodo minimo de los mayores hijos de un nodo del arbol BST
 * @param n	Puntero al nodo que se desea encontrar el minimo de los mayores
 * @return 	Puntero al nodo que posee el dato minimo de los mayores hijos de n
 */
    Node<Data>* minGreater(Node<Data>* n) {
        Node<Data>* t = n->r;
        while (t->l) {
            t = t->l;
        }
        return t;
    }

/**
 * Metodo maximo de los menores hijos de un nodo del arbol BST
 * @param n	Puntero al nodo que se desea encontrar el maximo hijo
 * @return 	Puntero al nodo que posee el dato del hijo maximo de los menores
 */
    Node<Data>* maxLesser(Node<Data>* n) {
        Node<Data>* t = n->l;
        while (t->r) {
            t = t->r;
        }
        return t;
    }
///Atributos de la clase///
    Node<Data>* root;///Puntero al nodo raiz del arbol BST///
    int level, nodes;
};

#endif /* BST_H */
