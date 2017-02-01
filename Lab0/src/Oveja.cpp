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
 * @param char 		Sexo del oveja
 * @param Celda**	Tablero en el que se encuentra la Oveja
 * @param int		Cantidad total de columnas del tablero
 * @param int		Cantidad de filas del tablero
*/ 
Oveja::Oveja(char nuevoSexo, Celda** nuevoTablero, int nuevaFila, int nuevaColumna, int tColumnas, int tFilas){
	this->setFila(nuevaFila);
	this->setColumna(nuevaColumna);
	this->tableroFilas = tFilas;
	this->tableroColum = tColumnas;
    setEnergia(75); //Definido por el enunciado Regla 2
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
		tablero[getFila()][getColumna()].setAnimal(NULL);
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
