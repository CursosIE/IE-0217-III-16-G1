/*
 *@author Luis Adrian Aguilar Cascante, @autor Giancarlo Marin Hernandez
 *@date   01-26-2017
 *@brief  Implementacion de los metodos de la clase Raton
*/

#include "../include/Raton.hpp"

/*
 *Constructor por defecto de la clase Raton
*/ 
Raton::Raton() {
}

/*
 * Constructor sobrecargado de la clase Raton
 * @param bool 	Sexo del Raton
*/ 
Raton::Raton(bool nuevoSexo, Celda** nuevoTablero, int tColumnas, int tFilas){
	this->tableroColum=tColumnas;
	this->tableroFilas=tFilas;
    setEnergia(25); //Definido por el enunciado Regla 1
    setSexo(nuevoSexo);
    setEspecie("Raton");       
	this-> tablero = nuevoTablero;
}

/*
 * Destructor por defecto de la clase Raton
*/ 
Raton::~Raton() {
}

/*
 * Metodo moverse del Raton definido por las regla  
*/ 
bool Raton::operator!(){
	Celda* vacia=Celda::findEmpty(this, tablero, tableroColum, tableroFilas);
	if (vacia==NULL){
		cout<<"No hay espacios vacios ";
		return false;
	}
	else{
		tablero[getColumna()][getFila()].setAnimal(NULL);
		vacia->setAnimal(this);
		setColumna(vacia->getColumna());
		setFila(vacia->getFila());
		cout<<"Me movi";
		return true;	
	}
}

bool Raton::operator++(){
	return true;
}

bool Raton::operator~(){
	return true;
}

void Raton::operator--(){

}
