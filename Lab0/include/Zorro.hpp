/*
 *@author Giancarlo Marin 
 *@date   01-24-2017
 *@brief  Archivo encabezado con la definicion de la clase Zorro
*/

#ifndef ZORRO_HPP
#define ZORRO_HPP
#include <iostream>
#include "Animal.hpp"
#include "Celda.hpp"

using namespace std;

/*
 * Definicion de clase ZORRO
*/
class Zorro : public Animal{
public:
	//Metodos
	Zorro(); //Constructor de la clase
	Zorro(bool nuevoSexo, Celda** nuevoTablero); //Constructor sobrecargado de la clase
	virtual ~Zorro(); //Destructor de la clase
	//Sobrecarga de operadores para funcionamiento de funciones
	bool operator!();
	bool operator++();
	bool operator~();
	void operator--();
private:
	Celda** tablero;
};

#endif /* ZORRO_HPP */