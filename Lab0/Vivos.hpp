/*
 *@author Giancarlo Marin 
 *@date   01-24-2017
 *@brief  Archivo encabezado con la definicion de la clase Vivos
*/

#ifndef VIVOS_HPP
#define VIVOS_HPP
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Vivos.hpp"
#include "Leon.hpp"
#include "Zorro.hpp"


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
	void setEnergia(short int nuevaEnergia);
	short int getEnergia();
	bool getSexo();
	short int getContador();
private:
	//Atributos
	short int energia;
	bool sexo;
	short int contador;		
};

#endif /* VIVOS_HPP */