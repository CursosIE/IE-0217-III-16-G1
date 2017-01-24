/*
 *@author Giancarlo Marin 
 *@date   01-23-2017
 *@brief  Archivo encabezado con la definicion de la clase polinomios 
*/

#ifndef POLINOMIO_HPP
#define POLINOMIO_HPP
#include <iostream>

using namespace std;

/*
 * Definicion de clase Polinomio
*/
class Polinomio{
public:
	//Metodos
	Polinomio(); //Constructor de la clase
	Polinomio(int grado); //Constructor sobrecargado
	Polinomio(int grado, double* datos); //Constructor sobrecargado
	~Polinomio(); //Destructor de la clase
	//Sobrecarga de operadores para funcionamiento de polinomios
	Polinomio& operator=(const Polinomio &orig);
	Polinomio& operator+(const Polinomio &sumando);
	Polinomio& operator-(const Polinomio &sustraendo);
	Polinomio& operator*(const Polinomio &pDer);
	Polinomio& operator/(const Polinomio &dividendo);
	//impresion en pantalla del polinomio
	void poliPrint();
	//metodos set y get de los atributos
	void setGrado(int newGrado);
	int getGrado();
	void setDatos(double* newDatos, int grado);
	double* getDatos();
private:
	//Atributos
	int grado;
	double* datos;
		
};

#endif /* POLINOMIO_HPP */