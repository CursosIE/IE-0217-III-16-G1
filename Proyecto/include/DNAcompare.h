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
	* Metodo para obtener el siguiente estado de la matriz de estados
	* @param d puntero a estado
	* @return Data<D> que sigue al estado recibido en la matriz de transicion de estados
	*/
	Stade* nextE(Stade* d, string a);
	/**
	* Metodo para conocer cuando se hallam coincidencias
	* @return lista que contiene los elementos encontrados
	*/
	ListWithArray<int*,int> output(Stade* d);
	/**
	* Metodo get del atributo graph
	* @return GraphAhoCorasick que contiene el grafo que representa las palabras de busqueda
	*/
	GraphAhoCorasick* getGraph();
private:
	string dicc; ///Cadena de caracteres con los elementos del diccionario///
	string X;	///Cadena de caracteres por leer. Input X Aho-Corasick(1975)///
	string* Y;	///Lista de cadenas de caracteres por buscar en X. Input Y Aho-Corasick(1975)///
	int numWords; ///Cantidad de palabras por buscar///
	GraphAhoCorasick* graph;///Grafo que representa los estados de Y. Modelado del algoritmo Aho-Corasick///
	int checkPerc; ///Porcentaje de chequeo para determinar si una y se encuentra en X///
	List<StadeSuc, int>* stade100; ///Lista de estados exito 100%///
	List<StadeSuc, int>* stadePerc; ///Lista de estados exito >=perc///
};
#endif /* DNACOMPARE_H */
