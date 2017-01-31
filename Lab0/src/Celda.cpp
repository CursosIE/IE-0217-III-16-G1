/*
 *@author Giancarlo Marin
 *@date   01-25-2017
 *@brief  Implementacion de metodos de las clase Celda
*/

#include "../include/Celda.hpp"
#include "../include/Lobo.hpp"
#include "../include/Oveja.hpp"
#include "../include/Raton.hpp"
#include "../include/Zorro.hpp"

/*
 * Constructor por defecto de la clase Celda
*/ 
Celda::Celda(){
}

/*
 * Constructor sobrecargado de la clase Celda
*/ 
Celda::Celda(int cantColumnas, int cantFilas, int nuevaColumna, int nuevaFila, short int nivelZacate,  Celda** nuevoTablero, char animal, bool sexo){
	this->columna=nuevaColumna;
	this->fila=nuevaFila;
	this->zacate=nivelZacate;
	if (animal=='L'){
		Lobo* nuevoLobo = new Lobo(sexo, nuevoTablero, cantColumnas, cantFilas); 
		setAnimal(nuevoLobo);
	}
	else if(animal == 'O'){
		Oveja* nuevaOveja = new Oveja(sexo, nuevoTablero, cantColumnas, cantFilas); 
		setAnimal(nuevaOveja);
	}
	else if(animal == 'Z'){
		Zorro* nuevoZorro = new Zorro(sexo, nuevoTablero, cantColumnas, cantFilas); 
		setAnimal(nuevoZorro);
	}
	else if(animal == 'R'){
		Raton* nuevoRaton = new Raton(sexo, nuevoTablero, cantColumnas, cantFilas); 
		setAnimal(nuevoRaton);
	}
	else{
		this->animal=NULL;
	}
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
int Celda::getColumna(){
	return columna;
}

/*
 * Metodo set del atributo zacate
 * @param short int 	Nuevo valor de zacate de la Celda 
*/ 
void Celda::setZacate(short int nivelZacate){
	this->zacate=nivelZacate;
}

/*
 * Metodo get del atributo zacate
 *@return short int 	Nivel de zacate de la Celda 
*/ 
short int Celda::getZacate(){
	return zacate;
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
 *@return Animal& 	Direccion de memoria del Puntero Animal en la celda
*/ 
Animal* Celda::getAnimal(){
	return (this->animal);
}

/*
 * Metodo publico que busca la primera celda vacia con respecto a un animal
 * @param Animal* 	Puntero del animal que llama la funcion
 * @param Celda**	Puntero al tablero sobre el que se juega
 * @param int 		Cantidad de columnas en el tablero
 * @param int 		Cantidad de filas en el tablero
 * @return Celda* 	Puntero a la celda vacia
*/
Celda* Celda::findEmpty(Animal* animal, Celda** tableroJuego, int tableroColumnas, int tableroFilas){
	Celda* vacia=NULL;
	if (animal->getColumna()==0){
		if (tableroJuego[animal->getFila()][1].getAnimal()==NULL){
			vacia=&tableroJuego[animal->getFila()+1][1];
		}
		else if(animal->getFila()!=tableroFilas){
			if (tableroJuego[animal->getFila()+1][0].getAnimal()==NULL){
				vacia=&tableroJuego[animal->getFila()+1][0];
			}
			else if (tableroJuego[animal->getFila()+1][1].getAnimal()==NULL){
				vacia=&tableroJuego[animal->getFila()+1][0];
			}
		}
		else if(animal->getFila()!=0){
			if (tableroJuego[animal->getFila()-1][0].getAnimal()==NULL){
				vacia=&tableroJuego[animal->getFila()-1][0];
			}
			else if(tableroJuego[animal->getFila()-1][1].getAnimal()==NULL){
				vacia=&tableroJuego[animal->getFila()-1][1];
			}
		}
	}
	else if (animal->getColumna()==tableroColumnas){
		if (tableroJuego[animal->getFila()][tableroColumnas-1].getAnimal()==NULL){
			vacia=&tableroJuego[animal->getFila()][tableroColumnas-1];
		}
		else if(animal->getFila()!=tableroFilas){
			if (tableroJuego[animal->getFila()+1][tableroColumnas].getAnimal()==NULL){
				vacia=&tableroJuego[animal->getFila()+1][tableroColumnas];
			}
			else if (tableroJuego[animal->getFila()+1][tableroColumnas-1].getAnimal()==NULL){
				vacia=&tableroJuego[animal->getFila()+1][tableroColumnas-1];
			}
		}
		else if(animal->getFila()!=0){
			if (tableroJuego[animal->getFila()-1][tableroColumnas].getAnimal()==NULL){
				vacia=&tableroJuego[animal->getFila()-1][tableroColumnas];
			}
			else if(tableroJuego[animal->getFila()-1][tableroColumnas-1].getAnimal()==NULL){
				vacia=&tableroJuego[animal->getFila()-1][tableroColumnas-1];
			}
		}
	}
	else if (animal->getFila()==0){
		if (tableroJuego[1][animal->getColumna()].getAnimal()==NULL){
			vacia=&tableroJuego[1][animal->getColumna()];
		}
		else if(tableroJuego[1][animal->getColumna()+1].getAnimal()==NULL){
			vacia=&tableroJuego[1][animal->getColumna()+1];
		}
		else if(tableroJuego[1][animal->getColumna()-1].getAnimal()==NULL){
			vacia=&tableroJuego[1][animal->getColumna()-1];
		}
		else if(tableroJuego[0][animal->getColumna()+1].getAnimal()==NULL){
			vacia=&tableroJuego[0][animal->getColumna()+1];
		}
		else if(tableroJuego[0][animal->getColumna()-1].getAnimal()==NULL){
			vacia=&tableroJuego[0][animal->getColumna()-1];
		}
	}
	else if (animal->getFila()==tableroFilas){
		if (tableroJuego[tableroFilas-1][animal->getColumna()].getAnimal()==NULL){
			vacia=&tableroJuego[tableroFilas-1][animal->getColumna()];
		}
		else if(tableroJuego[tableroFilas-1][animal->getColumna()+1].getAnimal()==NULL){
			vacia=&tableroJuego[tableroFilas-1][animal->getColumna()+1];
		}
		else if(tableroJuego[tableroFilas-1][animal->getColumna()-1].getAnimal()==NULL){
			vacia=&tableroJuego[tableroFilas-1][animal->getColumna()-1];
		}
		else if(tableroJuego[tableroFilas][animal->getColumna()+1].getAnimal()==NULL){
			vacia=&tableroJuego[tableroFilas][animal->getColumna()+1];
		}
		else if(tableroJuego[tableroFilas][animal->getColumna()-1].getAnimal()==NULL){
			vacia=&tableroJuego[tableroFilas][animal->getColumna()-1];
		}
	}
	else{
		if(tableroJuego[animal->getFila()-1][animal->getColumna()-1].getAnimal()==NULL){
			vacia=&tableroJuego[animal->getFila()-1][animal->getColumna()-1];
		}
		else if(tableroJuego[animal->getFila()-1][animal->getColumna()].getAnimal()==NULL){
			vacia=&tableroJuego[animal->getFila()-1][animal->getColumna()];
		}
		else if(tableroJuego[animal->getFila()-1][animal->getColumna()+1].getAnimal()==NULL){
			vacia=&tableroJuego[animal->getFila()-1][animal->getColumna()+1];
		}
		else if(tableroJuego[animal->getFila()][animal->getColumna()-1].getAnimal()==NULL){
			vacia=&tableroJuego[animal->getFila()][animal->getColumna()-1];
		}
		else if(tableroJuego[animal->getFila()][animal->getColumna()+1].getAnimal()==NULL){
			vacia=&tableroJuego[animal->getFila()][animal->getColumna()+1];
		}
		else if(tableroJuego[animal->getFila()+1][animal->getColumna()-1].getAnimal()==NULL){
			vacia=&tableroJuego[animal->getFila()+1][animal->getColumna()-1];
		}
		else if(tableroJuego[animal->getFila()+1][animal->getColumna()].getAnimal()==NULL){
			vacia=&tableroJuego[animal->getFila()+1][animal->getColumna()];
		}
		else if(tableroJuego[animal->getFila()+1][animal->getColumna()+1].getAnimal()==NULL){
			vacia=&tableroJuego[animal->getFila()+1][animal->getColumna()+1];
		}
	}
	return vacia;
}
