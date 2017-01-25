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
	//metodos set y get de los atributos
	unsigned int getID();
	string getEspecie();
	void setEnergia(short int nuevaEnergia);
	short int getEnergia();
	bool getSexo();
	short int getContador();
private:
	//Atributos
	unsigned int ID;
	string especie;
	short int energia;
	bool sexo;
	short int contador;		
};

#endif /* ANIMAL_HPP */