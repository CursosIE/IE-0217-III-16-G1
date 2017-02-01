/*
 *@author Giancarlo Marin
 *@date   01-25-2017
 *@brief  Implementacion de metodos de las clase Animal
*/

#include "../include/Animal.hpp"

/*
 * Constructor por defecto de la clase Animal
*/ 
Animal::Animal(){
	ID=identificador; 
	identificador++;
}

/*
 * Destructor por defecto de la clase Animal
*/ 
Animal::~Animal(){
	cout << "Destruyendo Animal #" << getID() << endl;
}

/*
 * Metodo get del identifiacor del animal
 *@return unsigned int 	ID del Animal
*/ 
unsigned int Animal::getID(){
	return ID;
}
/*
 * Metodo set del atributo especie
 *@param string 	Definicion del Nuevo valor de energia asignado al animal 
*/ 
void Animal::setEspecie(string nuevaEspecie){
	especie=nuevaEspecie;
}

/*
 * Metodo get del atributo especie 
 *@return string 	Nombre de la especie del animal
*/
string Animal::getEspecie(){
	return especie;
}

/*
 * Metodo set del atributo energia
 *@param short int 	Nuevo valor de energia asignado al animal 
*/ 
void Animal::setEnergia(short int nuevaEnergia){
	this->energia=nuevaEnergia;
}

/*
 * Metodo get del atributo energia
 *@return short int 	Valor de energia asignado al animal 
*/ 
short int Animal::getEnergia(){
	return energia;
}

/*
 * Metodo set del atributo sexo
 *@param char 	Sexo por asignar al animal 
*/ 
void Animal::setSexo(char nuevoSexo){
	sexo=nuevoSexo;
}

/*
 * Metodo get del atributo sexo
 * @return char* 	Retorna el sexo del animal de la siguiente forma:
 * M=Macho H=Hembra
*/ 
char Animal::getSexo(){
	return sexo;
}

/*
 * Metodo set del atributo fila
 *@param int 	Nueva asignacion del espacio fila donde se encuentra el animal
*/ 
void Animal::setFila(int nuevaFila){
	this->fila=nuevaFila;
}

/*
 * Metodo set del atributo columna
 *@param int 	Nueva asignacion del espacio columna donde se encuentra el animal
*/ 
void Animal::setColumna(int nuevaColumna){
	this->columna=nuevaColumna;
}

/*
 * Metodo get del atributo fila
 *@return int 	Retorna la fila en la que se encuentra el animal
*/ 
int Animal::getFila(){
	return fila;
}

/*
 * Metodo get del atributo columna
 *@return int 	Retorna la columna en la que se encuentra el animal
*/ 
int Animal::getColumna(){
	return columna;
}
