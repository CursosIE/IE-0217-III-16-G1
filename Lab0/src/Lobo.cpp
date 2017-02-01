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
 * @param char 		Sexo del Lobo
 * @param Celda**	Tablero en el que se encuentra el Lobo
 * @param int		Cantidad total de columnas del tablero
 * @param int		Cantidad de filas del tablero
 */
Lobo::Lobo(char nuevoSexo, Celda** nuevoTablero, int nuevFila, int nuevaColumna, int tColumnas, int tFilas){
	this->setFila(nuevFila);
	this->setColumna(nuevaColumna);
	this->tableroFilas = tFilas;
	this->tableroColum = tColumnas;
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

bool Lobo::operator++(){
	return true;
}

bool Lobo::operator~(){
	return true;
}

void Lobo::operator--(){

}
