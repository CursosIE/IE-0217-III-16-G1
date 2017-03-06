/**
* @author Luis Adrian Aguilar Cascante - B00092
* @author Robin Gonzalez - B43011	
* @author Giancarlo Marin - B54099
* @date 01-03-2017
* @brief Libreria que contiene la definicion de la clase DNAcompare
*/
#ifndef DNACOMPARE_H
#define DNACOMPARE_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <istream>
#include "Stade.h"
#include "StadeSuc.h"
#include "GraphAhoCorasick.h"
#include "List.h"
using namespace std;

class DNAcompare{
public:
	/**
	 * Constructor de la clase DNAcompare
	 */
	DNAcompare();
	/**
	* Constructor sobrecargado de la clase DNAcompare
	* @param dictionary		Cadena de caracteres que contiene los elementos que representan el diccionario
	* @param stringX 		String Secuencia que se quiere comparar
	* @param words			String* Palabras que se quieren buscar en la secuencia
	* @param percentage		int que representa el valor minimo de comparacion acertada. Se toma como porcentaje del prefijo de la palabra desde
	* @param countWords		int que indica la cantidad de palabras contenidas en Y
	*/
	DNAcompare(string dictionary, string stringX, string* words, int percentage, int countWords);
	/**
	* Destructor de la clase DNAcompare
	*/
	~DNAcompare();
	/**
	 * Metodo que cuenta la longitud de las palabras para deteminar cuantos estados existen
	 * @param sequences		string* que contiene cada caracter de cada palabra
	 * @return int que contiene la cantidad de estados por crear en el grafo
	 */
	int countStades(string* sequences);
	/**
	* Metodo get del atributo dicc
	* @return string que contiene el diccionario
	*/
	string getDicc();
	/**
	* Metodo get del atributo numWords
	* @return int que contiene el numero de palabras de busqueda
	*/
	int getNumWords();
	/**
	* Metodo get del atributo graph
	* @return GraphAhoCorasick que contiene el grafo que representa las palabras de busqueda
	*/
	GraphAhoCorasick* getGraph();
	/**
	* Metodo que realiza la comparacion de la secuencia X con las palabras de entrada Y
	*/
	void compareXY();
	/**
	* Metodo que obtiene el siguiente estado a partir de un estadoa actual y un caracter de entrada pertenneciente al diccionario
	* @param s	Obketo Stade del estado actual
	* @param a  char del diccionario que se obtiene como entrada
	* @return	Objeto Stade del estado siguiente
	*/
	Stade nextS(Stade s, char c);
	/**
	* Metodo que agrega el indice de la secuencia a la lista correcta de exito en caso de un estado de exito
	* @param s	Objeto Stade del estado actual
	* @param i int que indica el indice sobre la secuencia X
	* @param suc100 bool que indica que tipo de exito se dio en el estado si true es suc100 de lo contrario sucLes100
	* @param int que indica el numero de palabra que tuvo exito
	*/
	void output(Stade s, int i, bool suc100, int numP);
	/**
	* Metodo get de la lista suc100 graph
	* @return lista de exito 100
	*/
	List<StadeSuc, int>* getStade100();
	/**
	* Metodo get de la lista suc100 graph
	* @return lista de exito 100
	*/
	List<StadeSuc, int>* getStadePerc();
private:
	string Dicc; ///Cadena de caracteres con los elementos del diccionario///
	string X;	///Cadena de caracteres por leer. Input X Aho-Corasick(1975)///
	string* Y;	///Lista de cadenas de caracteres por buscar en X. Input Y Aho-Corasick(1975)///
	int numWords; ///Cantidad de palabras por buscar///
	GraphAhoCorasick* graph;///Grafo que representa los estados de Y. Modelado del algoritmo Aho-Corasick///
	int checkPerc; ///Porcentaje de chequeo para determinar si una y se encuentra en X///
	List<StadeSuc, int>* stade100; ///Lista de estados exito 100%///
	List<StadeSuc, int>* stadePerc; ///Lista de estados exito >=perc///
};
#endif /* DNACOMPARE_H */
