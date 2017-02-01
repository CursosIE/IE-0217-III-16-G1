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
Celda::Celda(int cantColumnas, int cantFilas, int nuevaColumna, int nuevaFila, short int nivelZacate,  Celda** nuevoTablero, char animal, char sexo){
	this->columna=nuevaColumna;
	this->fila=nuevaFila;
	this->zacate=nivelZacate;
	if (animal=='L'){
		Lobo* nuevoLobo = new Lobo(sexo, nuevoTablero, nuevaFila, nuevaColumna, cantColumnas, cantFilas); 
		setAnimal(nuevoLobo);
	}
	else if(animal == 'O'){
		Oveja* nuevaOveja = new Oveja(sexo, nuevoTablero, nuevaFila, nuevaColumna, cantColumnas, cantFilas);
		setAnimal(nuevaOveja);
	}
	else if(animal == 'Z'){
		Zorro* nuevoZorro = new Zorro(sexo, nuevoTablero, nuevaFila, nuevaColumna, cantColumnas, cantFilas);
		setAnimal(nuevoZorro);
	}
	else if(animal == 'R'){
		Raton* nuevoRaton = new Raton(sexo, nuevoTablero, nuevaFila, nuevaColumna, cantColumnas, cantFilas);
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
	cout << "Destruyendo Celda " << fila << " " << columna << endl;
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
 * Metodo publico que busca un selec en especifico: 
 * a) NULL = Primer Celda Vacía adyacente		b) Raton* = Primer Raton adyacente	c) Animal* = Primer Animal adyacente
 * @param Animal* 	Puntero del animal que llama la funcion
 * @param Celda**	Puntero al tablero sobre el que se juega
 * @param int 		Cantidad de columnas en el tablero
 * @param int 		Cantidad de filas en el tablero
 * @param char		Selector del tipo de selec que se busca: 0->NULL, 1->R, 2->Z, 3->O, 4->LM, 5->RM, 6->ZM, 8->OM, 9->LH, 10->RH, 11->ZH, 12->OH 
 * @return Celda* 	Puntero a la celda buscada y en caso de no encontrarla NULL
*/
Celda* Celda::find(Animal* animal, Celda** tableroJuego, int tableroColumnas, int tableroFilas, string selec){
	int filas = tableroFilas - 1;
	int columnas = tableroColumnas - 1;
	int miFila = animal->getFila();
	int miColumna = animal->getColumna();
	Celda* vacia = NULL;
	Celda* objeto = NULL;
	int opt;
	if (selec == "N"){ //Selector de tipo de busquedas
		opt = 0;
	}
	else if (selec == "R" || selec == "Z" || selec == "O"){
		opt = 1;
	}
	else{
		opt = 2;
	}
	const char* temp = selec.c_str(); //Uso en el caso 1
	switch (opt){
	case 0:
		//Busqueda de espacios vacios
		if (vacia == NULL && miFila != 0){
			if (tableroJuego[miFila - 1][miColumna].getAnimal() == NULL){
				vacia = &tableroJuego[miFila - 1][miColumna];
			}
		}
		if (vacia == NULL && miFila != filas){
			if (tableroJuego[miFila + 1][miColumna].getAnimal() == NULL){
				vacia = &tableroJuego[miFila + 1][miColumna];
			}
		}
		if (vacia == NULL && miColumna != 0){
			if (tableroJuego[miFila][miColumna - 1].getAnimal() == NULL){
				vacia = &tableroJuego[miFila][miColumna - 1];
			}
		}
		if (vacia == NULL && miColumna != columnas){
			if (tableroJuego[miFila][miColumna + 1].getAnimal() == NULL){
				vacia = &tableroJuego[miFila][miColumna + 1];
			}
		}
		if (vacia == NULL && miFila != 0 && miColumna != 0){
			if (tableroJuego[miFila - 1][miColumna - 1].getAnimal() == NULL){
				vacia = &tableroJuego[miFila - 1][miColumna - 1];
			}
		}
		if (vacia == NULL && miFila != 0 && miColumna != columnas){
			if (tableroJuego[miFila - 1][miColumna + 1].getAnimal() == NULL){
				vacia = &tableroJuego[miFila - 1][miColumna + 1];
			}
		}
		if (vacia == NULL && miFila != filas && miColumna != 0){
			if (tableroJuego[miFila + 1][miColumna - 1].getAnimal() == NULL){
				vacia = &tableroJuego[miFila + 1][miColumna - 1];
			}
		}
		if (vacia == NULL && miFila != filas && miColumna != columnas){
			if (tableroJuego[miFila + 1][miColumna + 1].getAnimal() == NULL){
				vacia = &tableroJuego[miFila + 1][miColumna + 1];
			}
		}
		return vacia;
		break;
	case 1:
		//Busqueda de animal sin impotar sexo
		if (objeto == NULL && miFila != 0){
			if (tableroJuego[miFila - 1][miColumna].getAnimal() != NULL){
				if (tableroJuego[miFila - 1][miColumna].getAnimal()->getEspecie()[0] == temp[0]){
					objeto = &tableroJuego[miFila - 1][miColumna];
				}
			}
		}
		if (objeto == NULL && miFila != filas){
			if (tableroJuego[miFila + 1][miColumna].getAnimal() != NULL){
				if (tableroJuego[miFila + 1][miColumna].getAnimal()->getEspecie()[0] == temp[0]){
					objeto = &tableroJuego[miFila + 1][miColumna];
				}
			}
		}
		if (objeto == NULL && miColumna != 0){
			if (tableroJuego[miFila][miColumna - 1].getAnimal() != NULL){
				if (tableroJuego[miFila][miColumna - 1].getAnimal()->getEspecie()[0] == temp[0]){
					objeto = &tableroJuego[miFila][miColumna - 1];
				}
			}
		}
		if (objeto == NULL && miColumna != columnas){
			if (tableroJuego[miFila][miColumna + 1].getAnimal() != NULL){
				if (tableroJuego[miFila][miColumna + 1].getAnimal()->getEspecie()[0] == temp[0]){
					objeto = &tableroJuego[miFila][miColumna + 1];
				}
			}
		}
		if (objeto == NULL && miFila != 0 && miColumna != 0){
			if (tableroJuego[miFila - 1][miColumna - 1].getAnimal() != NULL){
				if (tableroJuego[miFila - 1][miColumna - 1].getAnimal()->getEspecie()[0] == temp[0]){
					objeto = &tableroJuego[miFila - 1][miColumna - 1];
				}
			}
		}
		if (objeto == NULL && miFila != 0 && miColumna != columnas){
			if (tableroJuego[miFila - 1][miColumna + 1].getAnimal() != NULL){
				if (tableroJuego[miFila - 1][miColumna + 1].getAnimal()->getEspecie()[0] == temp[0]){
					objeto = &tableroJuego[miFila - 1][miColumna + 1];
				}
			}
		}
		if (objeto == NULL && miFila != filas && miColumna != 0){
			if (tableroJuego[miFila + 1][miColumna - 1].getAnimal() != NULL){
				if (tableroJuego[miFila + 1][miColumna - 1].getAnimal()->getEspecie()[0] == temp[0]){
					objeto = &tableroJuego[miFila + 1][miColumna - 1];
				}
			}
		}
		if (objeto == NULL && miFila != filas && miColumna != columnas){
			if (tableroJuego[miFila + 1][miColumna + 1].getAnimal() != NULL){
				if (tableroJuego[miFila + 1][miColumna + 1].getAnimal()->getEspecie()[0] == temp[0]){
					objeto = &tableroJuego[miFila + 1][miColumna + 1];
				}
			}
		}
		return objeto;
		break;
	case 2:
		//Busqueda de animal con sexo
		if (objeto == NULL && miFila != 0){
			if (tableroJuego[miFila - 1][miColumna].getAnimal() != NULL){
				if (&(tableroJuego[miFila - 1][miColumna].getAnimal()->getEspecie()[0]) + tableroJuego[miFila - 1][miColumna].getAnimal()->getSexo() == selec){
					objeto = &tableroJuego[miFila - 1][miColumna];
				}
			}
		}
		if (objeto == NULL && miFila != filas){
			if (tableroJuego[miFila + 1][miColumna].getAnimal() != NULL){
				if (&(tableroJuego[miFila + 1][miColumna].getAnimal()->getEspecie()[0]) + tableroJuego[miFila + 1][miColumna].getAnimal()->getSexo() == selec){
					objeto = &tableroJuego[miFila + 1][miColumna];
				}
			}
		}
		if (objeto == NULL && miColumna != 0){
			if (tableroJuego[miFila][miColumna - 1].getAnimal() != NULL){
				if (&(tableroJuego[miFila][miColumna - 1].getAnimal()->getEspecie()[0]) + tableroJuego[miFila][miColumna - 1].getAnimal()->getSexo() == selec){
					objeto = &tableroJuego[miFila][miColumna - 1];
				}
			}
		}
		if (objeto == NULL && miColumna != columnas){
			if (tableroJuego[miFila][miColumna + 1].getAnimal() != NULL){
				if (&(tableroJuego[miFila][miColumna + 1].getAnimal()->getEspecie()[0]) + tableroJuego[miFila][miColumna + 1].getAnimal()->getSexo() == selec){
					objeto = &tableroJuego[miFila][miColumna + 1];
				}
			}
		}
		if (objeto == NULL && miFila != 0 && miColumna != 0){
			if (tableroJuego[miFila - 1][miColumna - 1].getAnimal() != NULL){
				if (&(tableroJuego[miFila - 1][miColumna - 1].getAnimal()->getEspecie()[0]) + tableroJuego[miFila - 1][miColumna - 1].getAnimal()->getSexo() == selec){
					objeto = &tableroJuego[miFila - 1][miColumna - 1];
				}
			}
		}
		if (objeto == NULL && miFila != 0 && miColumna != columnas){
			if (tableroJuego[miFila - 1][miColumna + 1].getAnimal() != NULL){
				if (&(tableroJuego[miFila - 1][miColumna + 1].getAnimal()->getEspecie()[0]) + tableroJuego[miFila - 1][miColumna + 1].getAnimal()->getSexo() == selec){
					objeto = &tableroJuego[miFila - 1][miColumna + 1];
				}
			}
		}
		if (objeto == NULL && miFila != filas && miColumna != 0){
			if (tableroJuego[miFila + 1][miColumna - 1].getAnimal() != NULL){
				if (&(tableroJuego[miFila + 1][miColumna - 1].getAnimal()->getEspecie()[0]) + tableroJuego[miFila + 1][miColumna - 1].getAnimal()->getSexo() == selec){
					objeto = &tableroJuego[miFila + 1][miColumna - 1];
				}
			}
		}
		if (objeto == NULL && miFila != filas && miColumna != columnas){
			if (tableroJuego[miFila + 1][miColumna + 1].getAnimal() != NULL){
				if (&(tableroJuego[miFila + 1][miColumna + 1].getAnimal()->getEspecie()[0]) + tableroJuego[miFila + 1][miColumna + 1].getAnimal()->getSexo() == selec){
					objeto = &tableroJuego[miFila + 1][miColumna + 1];
				}
			}
		}
		return objeto;
		break;
	}
}
