#ifndef "NODE_H"
#define "NODE_H"

#include <iostream>
	
#include <Data.h>

class Node() : public Data<dato>{
	
	Node* izq;
	Node* der;
	Node* padre;
	Data<dato> datos;

	Node(){
		this->izq = nullptr;
		this->der = nullptr;
		this->padre = nullptr;
		this->datos = NULL;
	}	

	Node(Node* i, Node* d; Node* p, Data<dato> x){
		this->izq = i;
		this->der = d;
		this->padre = p;
		this->datos = x;
	}

	virtual ~node(){
		delete izq;
		delete der;
		delete padre;
//		delete datos;
	}

}

#endif
