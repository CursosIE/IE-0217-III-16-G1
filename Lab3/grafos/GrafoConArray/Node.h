/**
* @author Giancarlo Marin - B54099
* @author Robin Gonzalez Ricz - B43011
* @date 25-02-2017
* @brief Biblioteca de la clase Node que genera nodos para grafos
*/
#ifndef NODE_H
#define NODE_H

#include <iostream>
#include "MyData.h"

template <typename data>
class Node{
public:
	MyData<data>* d;
	
	Node(){
	
	}
	
	Node(data e){
		d = new MyData<data>(e);
	}

	~Node(){
	}
};

#endif
