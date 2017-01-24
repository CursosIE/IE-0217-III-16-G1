/*
 *@author Giancarlo Marin 
 *@date   01-24-2017
 *@brief  Archivo encabezado con la definicion de la clase Leon
*/

#ifndef LEON_HPP
#define LEON_HPP
#include <iostream>

using namespace std;

/*
 * Definicion de clase Leon
*/
class Leon{
public:
	//Metodos
	Leon(); //Constructor de la clase
	Leon(bool nuevoSexo); //Constructor sobrecargado de la clase
	~Leon(); //Destructor de la clase
	//Sobrecarga de operadores para funcionamiento de funciones
	Leon& operator^(const Vivos& zacate);//Moverse
	Leon& operator+(const Vivos& animal);//Comer
	Leon& operator*(const Leon& leon);//Reproducirse 
	Leon& operator/(const Leon& leon);//Morir
private:
};

#endif /* LEON_HPP */