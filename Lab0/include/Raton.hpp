/*
 *@author Giancarlo Marin 
 *@date   01-24-2017
 *@brief  Archivo encabezado con la definicion de la clase Raton
*/

#ifndef RATON_HPP
#define RATON_HPP
#include <iostream>
#include "Animal.hpp"
#include "Celda.hpp"

using namespace std;

/*
 * Definicion de clase Raton
*/
class Raton : public Animal{
public:
	//Metodos
	Raton(); //Constructor de la clase
	Raton(bool nuevoSexo, Celda** nuevoTablero); //Constructor sobrecargado de la clase
	virtual ~Raton(); //Destructor de la clase
	//Sobrecarga de operadores para funcionamiento de funciones
	bool operator!();
	bool operator++();
	bool operator~();
	void operator--();
private:
	Celda** tablero;
};

#endif /* RATON_HPP */