/*
 *@author Giancarlo Marin 
 *@date   01-24-2017
 *@brief  Archivo encabezado con la definicion de la clase Celda
*/

#ifndef CELDA_HPP
#define CELDA_HPP
#include <iostream>
#include <cstdlib>
#include "print.hpp"

using namespace std;

/*
 * Definicion de clase Celda
*/
class Celda{
public:
	//Metodos
	Celda(); //Constructor de la clase
	Celda(int newColumna, int newFila, short int nivelZacate, char animal, bool sexo);
	~Celda(); //Destructor de la clase
	//metodos set y get de los atributos
	int getFila();
	int getColumna();
	void setZacate(short int nivelZacate);
	short int getZacate();
	void setAnimal(Animal* nuevoAnimal);
	Animal& getAnimal();
private:
	//Atributos
	int columna;
	int fila;
	short int zacate;
	Vivos* animal;		
};

#endif /* CELDA_HPP */