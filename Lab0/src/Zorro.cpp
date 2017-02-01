/*
 *@author Luis Adrian Aguilar Cascante, @autor Giancarlo Marin Hernandez
 *@date   01-26-2017
 *@brief  Implementacion de los metodos de la clase Zorro
*/

#include "../include/Zorro.hpp"
#include "../include/Raton.hpp"

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
 * Metodo moverse del Zorro
 * @return bool		Indicacion de si existio o no movimiento del Zorro
*/ 
bool Zorro::operator!(){
	Celda* vacia=Celda::find(this, tablero, tableroColum, tableroFilas, "N");
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

/*
* Metodo comer del Zorro utilizando un operador unario segun regla 11
* @return Animal*		El puntero al Zorro
*/
Animal* Zorro::operator++(){
	Celda* comida = Celda::find(this, tablero, tableroColum, tableroFilas, "R");
	if (comida != NULL){
		this->setEnergia(this->getEnergia() + 2);
		if (this->getEnergia() > 100){ //Regla 7
			this->setEnergia(100);
		}
		comida->setAnimal(NULL); //se elimina el raton comido
	}
	return tablero[getFila()][getColumna()].getAnimal();
}

bool Zorro::operator~(){
	return true;
}

void Zorro::operator--(){

}
