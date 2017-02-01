/*
 *Template de impresion de seres vivos 
*/ 

#ifndef PRINT_HPP
#define PRINT_HPP
#include <iostream>
#include <cstdlib>

using namespace std;

template <typename T> 

void printVivo(T* serVivo){
	cout << "Celda: [" << serVivo->getFila() << "][" << 
		serVivo->getColumna() << "] ID: " << serVivo->getID() << 
		" " << serVivo->getEspecie()[0] << serVivo->getSexo() <<
		" Energia: " << serVivo->getEnergia() << endl; 
}

#endif /*PRINT_HPP*/