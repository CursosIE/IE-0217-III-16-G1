/*
 *@author Giancarlo Marin
 *@date   01-25-2017
 *@brief  Implementacion de metodos de las clase Celda
*/

#include "Celda.hpp"

/*
 * Constructor por defecto de la clase Celda
*/ 
Celda::Celda(){
	cout << "Creando Celda" << endl;
}

/*
 * Constructor sobrecargado de la clase Celda
*/ 
Celda::Celda(int nuevaColumna, int nuevaFila, short int nivelZacate, char animal='x', bool sexo=0){
	this->columna=nuevaColumna;
	this->fila=nuevaFila;
	this->zacate=nivelZacate;
	if (animal=='L'){
		this->animal=new Lobo(sexo);
	}
	else if(animal == 'O'){
		this->animal=new Oveja(sexo);
	}
	else if(animal == 'Z'){
		this->animal=new Zorro(sexo);
	}
	else if(animal == 'R'){
		this->animal=new Raton(sexo);
	}
	this->contadorDias=0;
}

/*
 * Destructor por defecto de la clase Celda
*/ 
Celda::~Celda(){
	cout << "Destruyendo Celda " << fila << " " << columna << " y sus componentes:" << endl;
	delete this->animal;
}

/*
 * Metodo get de la fila de la Celda
 *@return int 	fila de la Celda
*/ 
int Celda::getFila(){
	return fila;
}

/*
 * Metodo get de la columna de la Celda
 *@return int 	columna de la Celda
*/ 
int Celda::getFila(){
	return columna;
}

/*
 * Metodo set del atributo zacate
 * @param short int 	Nuevo valor de zacate de la Celda 
*/ 
void Celda::setZacate(short int nivelZacate){
	this->zacate=nivelZacateEnergia;
}

/*
 * Metodo get del atributo zacate
 *@return short int 	Nivel de zacate de la Celda 
*/ 
short int Celda::getZacate(){
	return zacate;
}

/*
 * Metodo get del atributo contador de dias
 *@return short int 	Numero de dias que ha estado sin cambios la celda
*/ 
short int Celda::getContadorDias(){
	return contadorDias;
}

/*
 * Metodo set del atributo animal
 * @param *Animal 	Puntero a una instancia Animal 
*/ 
void Celda::setAnimal(Animal* nuevoAnimal){
	this->animal=nuevoAnimal;
}

/*
 * Metodo get del atributo animal
 *@return &Animal 	Direccion de memoria del Puntero Animal en la celda
*/ 
Animal& Celda::getAnimal()(){
	return *(this->animal);
}