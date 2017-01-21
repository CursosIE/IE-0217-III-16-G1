/*
 *Universidad de Costa Rica - Escuela de Ingenieria Electrica
 *Tarea 1 - IE-0217
 *@author Giancarlo Marin 
 *@date   01-20-2017
 *@brief  Clase main que prueba el funcionamiento del proyecto pokemon 
*/
#include "pokemon.hpp"

using namespace std;

/*
 * Crea dos pokemones: Zapdos y Articulo
 * Inicia una pelea entre ellos e imprime la info de cada pokemon por turno
*/
int main(int argc, char* argv[]){
	//Creacion de pokemones
	Zapdos *z0 = new Zapdos("Drake");
	z0->infoZapdos();
	Articuno *a0 = new Articuno("Pedrito");
	a0->infoArticuno();
	Moltres *m0 = new Moltres("Robertico");
	m0->infoMoltres();
	//Lucha entre Articuno vs Zapdos
	cout << "Lucha entre Articuno y Zapdos" << endl;
	a0->attack1(*z0);
	z0->infoPelea();
	z0->attack2(*a0);
	z0->infoPelea();
	a0->attack4(*z0);
	a0->infoPelea();
	z0->attack3(*a0);
	a0->infoPelea();
	cout << "Fin de Lucha" << endl;
	//Liberacion de memoria dinamica
	delete z0; 
	delete a0;
	delete m0;
	return 0;
}