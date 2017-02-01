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
 * Metodo moverse del Lobo utilizando un operador unario 
 *@return bool	Indicacion de si existio o no movimiento del Lobo
*/ 
bool Lobo::operator!(){
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
 * Metodo comer del Lobo utilizando un operador unario segun regla 12
 * @return Animal*		El puntero al Lobo
 */
Animal* Lobo::operator++(){
	int randNum = this->getID() + this->getColumna() + rand() % 100; //numero random para determinar la preferencia de alimento del lobo
	string pref = "x";
	Celda* comida = NULL;
	if (randNum < 40){
		pref = 'R';
		comida = Celda::find(this, tablero, tableroColum, tableroFilas, pref);
	}
	else if (randNum < 80){
		pref = 'Z';
		comida = Celda::find(this, tablero, tableroColum, tableroFilas, pref);
	}
	else {
		pref = 'O';
		comida = Celda::find(this, tablero, tableroColum, tableroFilas, pref);
	}
	int i = 0;//indice del ciclo de busqueda
	while (comida == NULL && i < 2){
		if (pref == "R"){
			pref = 'Z';
			comida = Celda::find(this, tablero, tableroColum, tableroFilas, pref);
		}
		else if (pref == "Z"){
			pref = 'O';
			comida = Celda::find(this, tablero, tableroColum, tableroFilas, pref);
		}
		else{
			pref = 'R';
			comida = Celda::find(this, tablero, tableroColum, tableroFilas, pref);
		}
		i++;
	}
	if (comida != NULL){
		if (pref == "R"){
			this->setEnergia(this->getEnergia() + 2);
		}
		else if (pref == "Z"){
			this->setEnergia(this->getEnergia() + 5);
		}
		else {
			this->setEnergia(this->getEnergia() + 10);
		}
		if (this->getEnergia() > 100){ //Regla 7
			this->setEnergia(100);
		}
		comida->setAnimal(NULL); //se elimina el animal comido
	}
	return tablero[getFila()][getColumna()].getAnimal();
}

bool Lobo::operator~(){
	return true;
}

void Lobo::operator--(){

}
