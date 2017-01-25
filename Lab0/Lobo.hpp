/*
 *@author Giancarlo Marin 
 *@date   01-24-2017
 *@brief  Archivo encabezado con la definicion de la clase Lobo
*/

#ifndef LOBO_HPP
#define LOBO_HPP
#include <iostream>

using namespace std;

/*
 * Definicion de clase Lobo
*/
class Lobo, public Animal{
public:
	//Metodos
	Lobo(); //Constructor de la clase
	Lobo(bool nuevoSexo); //Constructor sobrecargado de la clase
	~Lobo(); //Destructor de la clase
	//Sobrecarga de operadores para funcionamiento de funciones
	Lobo& operator^(const Vivos& zacate);//Moverse
	Lobo& operator+(const Vivos& animal);//Comer
	Lobo& operator*(const Lobo& Lobo);//Reproducirse 
	Lobo& operator/(const Lobo& Lobo);//Morir
private:
};

#endif /* LOBO_HPP */