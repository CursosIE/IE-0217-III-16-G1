/*
 * @author Luis Adrian Aguilar Cascante - B00092
 * @author Robin Gonzalez Ricz - B43011
 * @author Giancarlo Marin - B54099
 * @date 21-02-2017	
 * @brief Libreria que genera Nodos de un arbol
 */
#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;
//BST node

template <typename D>
class Node {
public:
///Atributos de la clase Nodo///
    Node* l; ///l Puntero a Nodo izquierdo///	
    Node* r; ///r Puntero a Nodo derecho///
    Node* f; ///f Puntero a Nodo padre///
    D* d; ///l Puntero al dato tipo D del nodo///

/**
 * Constructor de la clase Nodo
 */ 	
    Node() {
    }

/**
 * Constructor sobrecargado de la clase Nodo
 * @param l 	Puntero al nodo izquierdo
 * @param r	Puntero al nodo derecho
 * @param d	Puntero al dato del nodo
 * @param f	Puntero al nodo padre
 */ 
    Node(Node* l, Node* r, D* d, Node* f) {
        this->l = l;
        this->d = d;
        this->r = r;
        this->f = f;
    }

/**
 * Destructor de la clase Nodo
 */
    virtual ~Node() {
        if (*(this->f->d) > *(this->d)) {
            this->f->l = nullptr;
        } else {
            this->f->r = nullptr;
        }
        delete d;
		cout << "Nodo Eliminado" << endl;
    }
};

#endif /* NODE_H */
