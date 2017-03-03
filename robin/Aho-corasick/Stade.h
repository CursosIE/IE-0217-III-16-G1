/**
* @author Giancarlo Marin - B54099
* @date 22-02-2017
* @brief Libreria de la clase Data que contiene un dato de tipo emplantillado
*/
#ifndef STADE_H
#define STADE_H

#include <iostream>
using namespace std;
template <typename D>
class Stade{
public:
	D* tag; ///Atrib. publico de tipo D que contiene el tag del estado///
	bool success100;///Atrib. publico que indica si es un caso de exito del 100%///
	bool successLes100;//////Atrib. publico que indica si es un caso de exito mayor al % definido///

	/**
	* Constructor de la clase Stade
	*/
	Stade(){
		this->tag = nullptr;
		this->success100 = false;
		this->successLes100 = false;
	}

	/**
	* Constructor sobrecargado de la clase Data
	* @param d 	Tipo D con el tag a guardar
	*/
	Stade(D t){
		this->tag = &t;
		this->success100 = false;
		this->successLes100 = false;
	}

	/**
	* Destructor de la clase Stade
	*/
	~Stade(){
	}
};

#endif /* STADE_H */