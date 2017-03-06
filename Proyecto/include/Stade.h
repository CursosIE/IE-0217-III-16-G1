/**
* @author Luis Adrian Aguilar Cascante - B00092
* @author Robin Gonzalez - B43011	
* @author Giancarlo Marin - B54099
* @date 01-03-2017
* @brief Biblioteca de la clase Stade que contiene un dato de tipo emplantillado
*/
#ifndef STADE_H
#define STADE_H

using namespace std;
class Stade{
public:
	int* tag; ///Atrib. publico de tipo int que contiene el tag del estado///
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
	* @param d 	Tipo int con el tag a guardar
	*/
	Stade(int* t){
		this->tag = t;
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
