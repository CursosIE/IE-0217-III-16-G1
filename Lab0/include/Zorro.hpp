/*
 *@author Giancarlo Marin 
 *@date   01-24-2017
 *@brief  Archivo encabezado con la definicion de la clase Zorro
*/

#ifndef ZORRO_HPP
#define ZORRO_HPP
#include <iostream>
#include "Celda.hpp"


using namespace std;

/*
 * Definicion de clase ZORRO
*/
class Zorro : public Animal{
public:
	//Metodos
	Zorro(); //Constructor de la clase
	//Constructor sobrecargado de la clase
	Zorro(char nuevoSexo, Celda** nuevoTablero, int nuevFila, int nuevaColumna, int tColumnas, int tFilas);
	virtual ~Zorro(); //Destructor de la clase
	//Sobrecarga de operadores para funcionamiento de funciones
	bool operator!();
	Animal* operator++();
	bool operator~();
	void operator--();
private:
	Celda** tablero;
};

#endif /* ZORRO_HPP */