/*
 *@author Giancarlo Marin 
 *@date   01-24-2017
 *@brief  Archivo encabezado con la definicion de la clase Animal
*/

#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Animal.hpp"
#include "Leon.hpp"
#include "Zorro.hpp"


#include "print.hpp"

using namespace std;

/*
 * Definicion de clase Animal
*/
class Animal{
public:
	//Metodos
	Animal(); //Constructor de la clase
	~Animal(); //Destructor de la clase
	//Sobrecarga de operadores para funcionamiento de funciones
	Animal& operator^(const Animal& animal)=0;//Moverse
	Animal& operator+(const Animal& animal)=0;//Comer
	Animal& operator*(const Animal& animal)=0;//Reproducirse 
	Animal& operator/(const Animal& animal)=0;//Morir
	//obtencion de datos del ser vivo
	string print();
	//metodos set y get de los atributos
	void setEnergia(short int nuevaEnergia);
	short int getEnergia();
	bool getSexo();
	short int getContador();
private:
	//Atributos
	short int energia;
	bool sexo;
	short int zacate;
	short int contador;		
};

#endif /* ANIMAL_HPP */