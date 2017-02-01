/*
 *@author Giancarlo Marin 
 *@date   01-24-2017
 *@brief  Archivo encabezado con la definicion de la clase Oveja
*/

#ifndef OVEJA_HPP
#define OVEJA_HPP
#include <iostream>
#include "Celda.hpp"


using namespace std;

/*
 * Definicion de clase Oveja
*/
class Oveja : public Animal{
public:
	//Metodos
	Oveja(); //Constructor de la clase
	//Constructor sobrecargado de la clase
	Oveja(char nuevoSexo, Celda** nuevoTablero, int nuevFila, int nuevaColumna, int tColumnas, int tFilas);
	virtual ~Oveja(); //Destructor de la clase
	//Sobrecarga de operadores para funcionamiento de funciones
	bool operator!();
	bool operator++();
	bool operator~();
	void operator--();
private:
	Celda** tablero;
};

#endif /* OVEJA_HPP */