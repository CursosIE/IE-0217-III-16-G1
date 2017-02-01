/*
 *@author Giancarlo Marin 
 *@date   01-24-2017
 *@brief  Archivo encabezado con la definicion de la clase Celda
*/

#ifndef CELDA_HPP
#define CELDA_HPP
#include <iostream>
#include <cstdlib>
#include "Animal.hpp"

using namespace std;

/*
 * Definicion de clase Celda
*/
class Celda{
public:
	//Metodos
	Celda(); //Constructor de la clase
	Celda(int cantColumnas, int cantFilas, int nuevaColumna, int nuevaFila, short int nivelZacate, Celda** nuevoTablero, char animal, char sexo);
	~Celda(); //Destructor de la clase
	//metodos set y get de los atributos
	int getFila();
	int getColumna();
	void setZacate(short int nivelZacate);
	short int getZacate();
	void setAnimal(Animal* nuevoAnimal);
	Animal* getAnimal();
	//metodos para el funcionamiento del juego
	static Celda* findEmpty(Animal* animal, Celda** tableroJuego, int tableroColum, int tableroFilas);
private:
	//Atributos
	int columna;
	int fila;
	short int zacate;
	Animal* animal;
};

#endif /* CELDA_HPP */