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
 * Definicion de clase Vivos
*/
class Vivos{
public:
	//Metodos
	Vivos(); //Constructor de la clase
	~Vivos(); //Destructor de la clase
	//Sobrecarga de operadores para funcionamiento de funciones
	Vivos& operator^(const Vivos& animal)=0;//Moverse
	Vivos& operator+(const Vivos& animal)=0;//Comer
	Vivos& operator*(const Vivos& animal)=0;//Reproducirse 
	Vivos& operator/(const Vivos& dividendo)=0;//Morir
	//obtencion de datos del ser vivo
	string print();
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