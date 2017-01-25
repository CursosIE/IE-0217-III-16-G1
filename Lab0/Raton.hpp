/*
 *@author Giancarlo Marin 
 *@date   01-24-2017
 *@brief  Archivo encabezado con la definicion de la clase Raton
*/

#ifndef RATON_HPP
#define RATON_HPP
#include <iostream>

using namespace std;

/*
 * Definicion de clase Raton
*/
class Raton, public Animal{
public:
	//Metodos
	Raton(); //Constructor de la clase
	Raton(bool nuevoSexo); //Constructor sobrecargado de la clase
	~Raton(); //Destructor de la clase
	//Sobrecarga de operadores para funcionamiento de funciones
	Raton& operator^(const Vivos& zacate);//Moverse
	Raton& operator+(const Vivos& zacate);//Comer
	Raton& operator*(const Raton& Raton);//Reproducirse 
	Raton& operator/(const Raton& Raton);//Morir
private:
};

#endif /* RATON_HPP */