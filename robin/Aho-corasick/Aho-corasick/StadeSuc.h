/**
* @author Giancarlo Marin - B54099
* @date 02-03-2017
* @brief Biblioteca la clase StadeSuc que representa la definicion de un estado de exito
*/
#ifndef STADESUC_H
#define STADESUC_H

using namespace std;
class StadeSuc{
public:
	int index;			///Atrib. publico de tipo int que indica el indice donde sucedio el exito///
	int numWord;		///Atrib. publico de tipo int que indica el numero de palabra que corresponde el estado de exito///

	/**
	* Constructor de la clase StadeSuc
	*/
	StadeSuc(){
		this->index = -1;
		this->numWord = -1;
	}

	/**
	* Constructor sobrecargado de la clase StadeSuc
	* @param i 	Tipo int con el index de la Seq donde sucedio el exito
	* @param n	Numero de palabra a la que corresponde el exito
	*/
	StadeSuc(int i, int n){
		this->index = i;
		this->numWord = n;
	}

	/**
	* Destructor de la clase Stade
	*/
	~StadeSuc(){
	}
};

#endif /* STADESUC_H */