/*
 *@author Giancarlo Marin
 *@date   01-25-2017
 *@brief  Implementacion de metodos de las clase Animal
*/

#include "Animal.hpp"

unsigned int identificador=0; //variable global para generar ID de cada animal

/*
 * Constructor por defecto de la clase Animal
*/ 
Animal::Animal(){
	cout << "Creando Animal #" << identificador << endl;
	identificador++;
}

/*
 * Destructor por defecto de la clase Animal
*/ 
Animal::~Animal(){
	cout << "Destruyendo Animal #" << getID() << endl;
}

/*
 * Metodo get del identifiacor del animal
 *@return unsigned int 	ID del Animal
*/ 
unsigned int Animal::getID(){
	return ID;
}

/*
 * Metodo get del atributo especie 
 *@return string 	Nombre de la especie del animal
*/
string Animal::getEspecie(){
	return especie;
}

/*
 * Metodo set del atributo energia
 *@param short int 	Nuevo valor de energia asignado al animal 
*/ 
void Animal::setEnergia(short int nuevaEnergia){
	this->energia=nuevaEnergia;
}

/*
 * Metodo get del atributo energia
 *@return short int 	Valor de energia asignado al animal 
*/ 
short int Animal::getEnergia(){
	return energia;
}

/*
 * Metodo get del atributo sexo
 *@return bool 	Retorna el sexo del animal de la siguiente forma:
 * False=Macho True=Hembra
*/ 
bool Animal::getSexo(){
	return sexo;
}
