/*
 *@author Giancarlo Marin 
 *@date   01-24-2017
 *@brief  Archivo encabezado con la definicion de la clase Raton
*/

#ifndef RATON_HPP
#define RATON_HPP
#include <iostream>
#include "Celda.hpp"

using namespace std;

/*
 * Definicion de clase Raton
*/
class Raton : public Animal{
public:
	//Metodos
	Raton(); //Constructor de la clase
	 //Constructor sobrecargado de la clase
	Raton(char nuevoSexo, Celda** nuevoTablero, int nuevFila, int nuevaColumna, int tColumnas, int tFilas);
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