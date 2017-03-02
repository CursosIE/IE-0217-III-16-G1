/**
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
#include "Data.h"
#include "GraphAhoCorasick.h"
using namespace std;

class DNAcompare{
public:
	/**
	 * Constructor de la clase DNAcompare
	 */
	DNAcompare();
	/**
	* Constructor sobrecargado de la clase DNAcompare
	* @param dictionary		Array de char que contiene todos los caracteres que representan el diccionario
	* @param stringX 		const char* Secuencia que se quiere comparar
	* @param words			const char** Palabras que se quieren buscar en la secuencia
	* @param percentage		int que representa el valor minimo de comparacion acertada. Se toma como porcentaje del prefijo de la palabra desde
	* @param countWords		int que indica la cantidad de palabras contenidas en Y
	*/
	DNAcompare(char dictionary[], const char* stringX, const char** words, int percentage, int countWords);
	/**
	* Destructor de la clase DNAcompare
	*/
	~DNAcompare();
	/**
	 * Metodo que cuenta la longitud de las palabras para deteminar cuantos estados existen
	 * @param sequences		const char** que contiene cada caracter de cada palabra
	 * @return int que contiene la cantidad de estados por crear en el grafo
	 */
	int countStades(const char** sequences);
	/**
	* Metodo get del atributo dicc
	* @return char* que contiene el diccionario
	*/
	char* getDicc();
	/**
	* Metodo get del atributo numWords
	* @return int que contiene el numero de palabras de busqueda
	*/
	int getNumWords();
	/**
	* Metodo get del atributo graph
	* @return GraphAhoCorasick que contiene el grafo que representa las palabras de busqueda
	*/
	GraphAhoCorasick<Data<int>>* getGraph();
private:
	char* dicc; ///Cadena de caracteres con los elementos del diccionario///
	const char* X;	///Cadena de caracteres por leer. Input X Aho-Corasick(1975)///
	const char** Y;	///Lista de cadenas de caracteres por buscar en X. Input Y Aho-Corasick(1975)///
	int numWords; ///Cantidad de palabras por buscar///
	GraphAhoCorasick<Data<int>>* graph;///Grafo que representa los estados de Y. Modelado del algoritmo Aho-Corasick///
	int checkPerc; ///Porcentaje de chequeo para determinar si una y se encuentra en X/// 
};
#endif /* DNACOMPARE_H */