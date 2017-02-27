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
