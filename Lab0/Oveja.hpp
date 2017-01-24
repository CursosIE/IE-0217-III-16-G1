/*
 *@author Giancarlo Marin 
 *@date   01-24-2017
 *@brief  Archivo encabezado con la definicion de la clase Oveja
*/

#ifndef OVEJA_HPP
#define OVEJA_HPP
#include <iostream>

using namespace std;

/*
 * Definicion de clase Oveja
*/
class Oveja{
public:
	//Metodos
	Oveja(); //Constructor de la clase
	Oveja(bool nuevoSexo); //Constructor sobrecargado de la clase
	~Oveja(); //Destructor de la clase
	//Sobrecarga de operadores para funcionamiento de funciones
	Oveja& operator^(const Vivos& zacate);//Moverse
	Oveja& operator+(const Vivos& zacate);//Comer
	Oveja& operator*(const Oveja& Oveja);//Reproducirse 
	Oveja& operator/(const Oveja& Oveja);//Morir
private:
};

#endif /* OVEJA_HPP */