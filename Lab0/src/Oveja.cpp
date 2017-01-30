/*
 *@author Luis Adrian Aguilar Cascante, @autor Giancarlo Marin Hernandez
 *@date   01-26-2017
 *@brief  Implementacion de los metodos de la clase oveja
*/

#include "../include/Oveja.hpp"

/*
 *Constructor por defecto de la clase oveja
*/ 
Oveja::Oveja() {
}

/*
 * Constructor sobrecargado de la clase oveja
 * @param bool 	Sexo del oveja
*/ 
Oveja::Oveja(bool nuevoSexo, Celda** nuevoTablero, int tColumnas, int tFilas){
	this->tableroColum=tColumnas;
	this->tableroFilas=tFilas;
    setEnergia(75); //Definido por el enunciado Regla 1
    setSexo(nuevoSexo);
    setEspecie("Oveja");       
	this->tablero = nuevoTablero;
}

/*
 * Destructor por defecto de la clase Oveja
*/ 
Oveja::~Oveja() {
}

/*
 * Metodo moverse de la oveja
*/ 
bool Oveja::operator!(){
	Celda* vacia=Celda::findEmpty(this, tablero, tableroColum, tableroFilas);
	if (vacia==NULL){
		return false;
	}
	else{
		tablero[getColumna()][getFila()].setAnimal(NULL);
		vacia->setAnimal(this);
		setColumna(vacia->getColumna());
		setFila(vacia->getFila());
		return true;	
	}
}

bool Oveja::operator++(){
	return true;
}

bool Oveja::operator~(){
	return true;
}

void Oveja::operator--(){

}
