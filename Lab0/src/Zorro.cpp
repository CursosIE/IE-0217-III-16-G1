/*
 *@author Luis Adrian Aguilar Cascante, @autor Giancarlo Marin Hernandez
 *@date   01-26-2017
 *@brief  Implementacion de los metodos de la clase Zorro
*/

#include "../include/Zorro.hpp"

/*
 *Constructor por defecto de la clase Zorro
*/ 
Zorro::Zorro() {
}

/*
 * Constructor sobrecargado de la clase Zorro
 * @param char 		Sexo del Zorro
 * @param Celda**	Tablero en el que se encuentra el Zorro
 * @param int		Cantidad total de columnas del tablero
 * @param int		Cantidad de filas del tablero
 */
Zorro::Zorro(char nuevoSexo, Celda** nuevoTablero, int nuevFila, int nuevaColumna, int tColumnas, int tFilas){
	this->setFila(nuevFila);
	this->setColumna(nuevaColumna);
	this->tableroFilas = tFilas;
	this->tableroColum = tColumnas;
    setEnergia(50); //Definido por el enunciado Regla 3
    setSexo(nuevoSexo);
    setEspecie("Zorro");       
	this-> tablero = nuevoTablero;
}

/*
 * Destructor por defecto de la clase Zorro
*/ 
Zorro::~Zorro() {
}

/*
 * Metodo moverse del Zorro definido por las regla  
*/ 
bool Zorro::operator!(){
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

bool Zorro::operator++(){
	return true;
}

bool Zorro::operator~(){
	return true;
}

void Zorro::operator--(){

}
