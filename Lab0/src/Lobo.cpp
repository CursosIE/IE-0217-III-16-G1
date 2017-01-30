/*
 *@author Luis Adrian Aguilar Cascante, @autor Giancarlo Marin Hernandez
 *@date   01-26-2017
 *@brief  Implementacion de los metodos de la clase Lobo
*/

#include "../include/Lobo.hpp"

/*
 *Constructor por defecto de la clase Lobo
*/ 
Lobo::Lobo() {
}

/*
 * Constructor sobrecargado de la clase Lobo
 * @param bool 	Sexo del Lobo
*/ 
Lobo::Lobo(bool nuevoSexo, Celda** nuevoTablero, int tColumnas, int tFilas){
	this->tableroColum=tColumnas;
	this->tableroFilas=tFilas;
    setEnergia(100); //Definido por el enunciado Regla 1
    setSexo(nuevoSexo);
    setEspecie("Lobo");       
	this->tablero = nuevoTablero;
}

/*
 * Destructor por defecto de la clase Lobo
*/ 
Lobo::~Lobo() {
}

/*
 * Metodo moverse del Lobo definido por las regla  
*/ 
bool Lobo::operator!(){
	cout << "Si entre a moverme";
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

bool Lobo::operator++(){
	return true;
}

bool Lobo::operator~(){
	return true;
}

void Lobo::operator--(){

}
