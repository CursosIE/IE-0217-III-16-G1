/*
 *@author Giancarlo Marin 
 *@date   01-24-2017
 *@brief  Archivo encabezado con la definicion de la clase Lobo
*/

#ifndef LOBO_HPP
#define LOBO_HPP
#include <iostream>
#include "Celda.hpp"

using namespace std;

/*
 * Definicion de clase Lobo
*/
class Lobo : public Animal{
public:
	//Metodos
	Lobo(); //Constructor de la clase
	Lobo(bool nuevoSexo, Celda** nuevoTablero); //Constructor sobrecargado de la clase
	virtual ~Lobo(); //Destructor de la clase
	//Sobrecarga de operadores para funcionamiento de funciones
	bool operator!();
	bool operator++();
	bool operator~();
	void operator--();
private:
	Celda** tablero;
};

#endif /* LOBO_HPP */