/*
 *@author Giancarlo Marin 
 *@date   01-24-2017
 *@brief  Archivo encabezado con la definicion de la clase Zorro
*/

#ifndef ZORRO_HPP
#define ZORRO_HPP
#include <iostream>

using namespace std;

/*
 * Definicion de clase ZORRO
*/
class Zorro{
public:
	//Metodos
	Zorro(); //Constructor de la clase
	Zorro(bool nuevoSexo, short int nivelZacate); //Constructor sobrecargado de la clase
	~Zorro(); //Destructor de la clase
	//Sobrecarga de operadores para funcionamiento de funciones
	Zorro& operator^(const Vivos& zacate);//Moverse
	Zorro& operator+(const Vivos& raton);//Comer
	Zorro& operator*(const Zorro& Zorro);//Reproducirse 
	Zorro& operator/(const Zorro& Zorro);//Morir
private:
};

#endif /* ZORRO_HPP */