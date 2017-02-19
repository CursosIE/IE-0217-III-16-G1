#ifndef CELL_H
#define CELL_H

#include <iostream>
using namespace std;

template <typename D>
class Cell{
public:
	//Atributos publicos
	Cell* next;
	D* data;
	Cell(){
		data = nullptr;
		this->next = nullptr;
	}
	Cell(D* d, Cell* n){
		this->data=d;
 		this->next=n;
	}
	~Cell(){
		delete data;
	}
};

#endif /* CELL_H */
