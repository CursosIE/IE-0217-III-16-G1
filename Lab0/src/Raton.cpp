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
 * @param char 		Sexo del Raton
 * @param Celda**	Tablero en el que se encuentra el Raton
 * @param int		Cantidad total de columnas del tablero
 * @param int		Cantidad de filas del tablero
 */
Raton::Raton(char nuevoSexo, Celda** nuevoTablero, int nuevFila, int nuevaColumna, int tColumnas, int tFilas){
	this->setFila(nuevFila);
	this->setColumna(nuevaColumna);
	this->tableroFilas = tFilas;
	this->tableroColum = tColumnas;
    setEnergia(25); //Definido por el enunciado Regla 4
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

bool Raton::operator++(){
	return true;
}

bool Raton::operator~(){
	return true;
}

void Raton::operator--(){

}
