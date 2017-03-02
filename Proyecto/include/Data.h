/**
* @author Giancarlo Marin - B54099
* @date 22-02-2017
* @brief Libreria de la clase Data que contiene un dato de tipo emplantillado
*/
#ifndef DATA_H
#define DATA_H

#include <iostream>
using namespace std;

template<typename D>/**Libreria de la clase Data emplantillada */
class Data{
public:
	D* data; ///Atrib. publico de tipo D que contiene el dato a guardar///

	/**
	* Constructor de la clase Data
	*/
	Data(){
	}

	/**
	* Constructor sobrecargado de la clase Data
	* @param d 	Puntero a D con el dato a guardar
	*/
	Data(D* d){
		this->data = d;
	}

	/**
	* Destructor de la clase Data
	*/
	~Data(){
	}
};

#endif /* Data_H */