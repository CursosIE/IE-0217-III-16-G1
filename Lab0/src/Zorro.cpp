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
 * @param bool 	Sexo del Zorro
*/ 
Zorro::Zorro(bool nuevoSexo, Celda** nuevoTablero) {
    setEnergia(100); //Definido por el enunciado Regla 1
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

/*
 * Metodo moverse del Zorro definido por las regla  
*/ 
bool Zorro::operator!(){
	return true;
}

bool Zorro::operator++(){
	return true;
}

bool Zorro::operator~(){
	return true;
}

void Zorro::operator--(){

}
