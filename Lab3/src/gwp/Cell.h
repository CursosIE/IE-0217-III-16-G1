/**
* @author Giancarlo Marin - B54099
* @author Robin Gonzalez Ricz - B43011
* @author Giancarlo Marin - B54099
* @date 21-02-2017
* @brief Libreria que genera un template de una clase Cell (Celda que contiene datos)
*/
#ifndef CELL_H
#define CELL_H

#include <iostream>
using namespace std;

template <typename D> /**Libreria que genera un template de una clase Cell que contiene datos de tipo D*/
class Cell{
public:
	Cell* next; /**<Atrib. publico de tipo puntero a Cell que indica la siguiente celda*/
	D data; /**<Atrib. publico de tipo D que indica el dato incluido en la celda*/

	/**
	* Constructor de la clase Cell
	*/
	Cell(){
		data = nullptr;
		this->next = nullptr;
	}

	/**
	* Constructor sobrecargado de la clase Cell
	* @param d 	Puntero al dato de tipo D que se asigna a la celda
	* @param n	Puntero a la celda siguiente de la celda que se crea
	*/
	Cell(D d, Cell* n){
		this->data = d;
		this->next = n;
	}

	/**
	* Destructor de la clase Cell
	*/
	~Cell(){
		delete data;
	}
};

#endif /* CELL_H */
