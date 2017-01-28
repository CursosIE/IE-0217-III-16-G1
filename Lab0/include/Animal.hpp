/*
 *@author Giancarlo Marin 
 *@date   01-24-2017
 *@brief  Archivo encabezado con la definicion de la clase Animal
*/

#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>

using namespace std;

unsigned int identificador=0; //variable global para generar ID de cada animal

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
private:
	//Atributos
	unsigned int ID;
	string especie;
	short int energia;
	bool sexo;
};

#endif /* ANIMAL_HPP */