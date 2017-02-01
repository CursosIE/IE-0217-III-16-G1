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
#include <cstddef>
#include <string>
#include <sstream>

using namespace std;

//variable global para generar ID de cada animal
static unsigned int identificador=0; 

/*
 * Definicion de clase Animal
*/
class Animal{
public:
	int tableroColum;
	int tableroFilas;
	bool actueHoy=false;
	//Metodos
	Animal(); //Constructor de la clase
	virtual ~Animal(); //Destructor de la clase
	//Sobrecarga de operadores para funcionamiento de funciones
	//True=Si realizo la funcion o FALSE de lo contrario
	virtual bool operator!()=0;//Moverse
	virtual bool operator++()=0;//Comer
	virtual bool operator~()=0;//Reproducirse 
	virtual void operator--()=0;//Morir
	//metodos set y get de los atributos
	unsigned int getID();
	void setEspecie(string nuevaEspecie);
	string getEspecie();
	void setEnergia(short int nuevaEnergia);
	short int getEnergia();
	void setSexo(char nuevoSexo);
	char getSexo();
	void setFila(int nuevaFila);
	void setColumna(int nuevaFila);
	int getFila();
	int getColumna();
private:
	//Atributos
	unsigned int ID;
	string especie;
	short int energia;
	char sexo;
	int fila;
	int columna;
};

#endif /* ANIMAL_HPP */