/**
* @author Giancarlo Marin - B54099
* @date 22-02-2017
* @brief Libreria de la clase MyChar que contiene un dato nuevo 
*/
#ifndef MYDATA_H
#define MYDATA_H

#include <iostream>
using namespace std;

template<typename D>/**Libreria de la clase MyData que contiene un dato nuevo */
class MyData{
public:
	D data; ///Atrib. publico de tipo D que contiene el dato a guardar///
	
	/**
	* Constructor de la clase MyChar
	*/
	MyData(){
	}

	/**
	* Constructor sobrecargado de la clase MyData
	* @param d 	Puntero a D con el dato a guardar
	*/
	MyData(D d){
		this->data = d;
	}

	/**
	* Destructor de la clase MyData
	*/
	~MyData(){
	}
};

#endif /* MyData_H */