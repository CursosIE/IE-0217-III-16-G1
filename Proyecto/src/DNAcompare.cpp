/**
* @author Giancarlo Marin - B54099
* @date 01-03-2017
* @brief Implementacion de los metodos de la clase clase DNAcompare
*/
#include "../include/DNAcompare.h"

/**
 * Constructor de la clase DNAcompare
 */
DNAcompare::DNAcompare(){
	this->dicc = "";
	this->X = "";
	this->Y = nullptr;
	this->numWords = 0;
	this->checkPerc = 0;
	this->graph = new GraphAhoCorasick<Data<int>>();
}

/**
* Constructor sobrecargado de la clase DNAcompare
* @param dictionary		Array de char que contiene todos los caracteres que representan el diccionario
* @param stringX 		const char* Secuencia que se quiere comparar
* @param words			const char** Palabras que se quieren buscar en la secuencia
* @param percentage		int que representa el valor minimo de comparacion acertada. Se toma como porcentaje del prefijo de la palabra desde
*/
DNAcompare::DNAcompare(char dictionary[], const char* stringX, const char** words, int percentage, int countWords){
	this->dicc = dictionary;
	this->X = stringX;
	this->Y = words;
	this->numWords = countWords;
	this->checkPerc = percentage;
	int stades = countStades(words);
	this->graph = new GraphAhoCorasick<Data<int>>(stades, dictionary, words);
}

/**
 * Destructor de la clase DNAcompare
 */
DNAcompare::~DNAcompare(){
	delete graph;
}

/**
 * Metodo que cuenta la longitud de las palabras para deteminar cuantos estados existen
 * @param sequences		char** que contiene cada caracter de cada palabra
 * @return int que contiene la cantidad de estados por crear en el grafo
 */
int DNAcompare::countStades(const char** sequences){
	int temp = 0;
	char* firstChar = new char[this->numWords];
	int count = 0; //Suma de caracteres que tienen la misma raiz de diferentes palabras
	for (int i = 0; i < this->numWords; i++){
		firstChar[i] = sequences[i][0];
		temp += int(sizeof(sequences[i]) / sizeof(sequences[i][0]));
	}
	//Comparacion de prefijos de las palabras
	for (int j = 1; j < this->numWords; j++){
		for (int k = 0; k < this->numWords; k++){
			if (j != k && firstChar[j] == firstChar[k]){
				for (int m = 1; m<int(sizeof(sequences[j]) / sizeof(sequences[j][0])); m++){
					if (sequences[j][m] != sequences[k][m]){
						count += m;
						break;
					}
				}
			}
		}
	}
	return temp - count;
}

/**
* Metodo get del atributo dicc
* @return char* que contiene el diccionario
*/
char* DNAcompare::getDicc(){
	return this->dicc;
}

/**
* Metodo get del atributo numWords
* @return int que contiene el numero de palabras de busqueda
*/
int DNAcompare::getNumWords(){
	return this->numWords;
}

/**
* Metodo get del atributo graph
* @return GraphAhoCorasick que contiene el grafo que representa las palabras de busqueda
*/
GraphAhoCorasick<Data<int>>* DNAcompare::getGraph(){
	return this->graph;
}
