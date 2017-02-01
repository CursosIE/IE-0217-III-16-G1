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
	//Constructor sobrecargado de la clase
	Lobo(char nuevoSexo, Celda** nuevoTablero, int nuevFila, int nuevaColumna, int tColumnas, int tFilas);
	virtual ~Lobo(); //Destructor de la clase
	//Sobrecarga de operadores para funcionamiento de funciones
	bool operator!();
	Animal* operator++();
	bool operator~();
	void operator--();
private:
	Celda** tablero;
};

#endif /* LOBO_HPP */