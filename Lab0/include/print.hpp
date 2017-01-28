/*
 *Template de impresion de seres vivos 
*/ 

#ifndef PRINT_HPP
#define PRINT_HPP
#include <iostream>
#include <cstdlib>

using namespace std;

template <typename T> 

void printVivo(T *serVivo){
	cout << "Sexo: " << serVivo->getSexo() << 
	" Energia: " << serVivo->getEnergia() <<
	" Energia: " << serVivo->getEnergia() << endl; 
}

#endif /*PRINT_HPP*/