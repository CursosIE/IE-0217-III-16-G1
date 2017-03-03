/**
* @author Giancarlo Marin - B54099
* @date 01-03-2017
* @brief Implementacion de los metodos de la clase clase DNAcompare
*/
#include "stdafx.h"
#include "DNAcompare.h"

/**
 * Constructor de la clase DNAcompare
 */
DNAcompare::DNAcompare(){
	this->dicc = "";
	this->X = "";
	this->Y = nullptr;
	this->numWords = 0;
	this->checkPerc = 0;
	this->graph = new GraphAhoCorasick();
}

/**
* Constructor sobrecargado de la clase DNAcompare
* @param dictionary		Cadena de caracteres que contiene los elementos que representan el diccionario
* @param stringX 		String Secuencia que se quiere comparar
* @param words			String* Palabras que se quieren buscar en la secuencia
* @param percentage		int que representa el valor minimo de comparacion acertada. Se toma como porcentaje del prefijo de la palabra desde
* @param countWords		int que indica la cantidad de palabras contenidas en Y
*/
DNAcompare::DNAcompare(string dictionary, string stringX, string* words, int percentage, int countWords){
	this->dicc = dictionary;
	this->X = stringX;
	this->Y = words;
	this->numWords = countWords;
	this->checkPerc = percentage;
	int stades = countStades(words);
	this->graph = new GraphAhoCorasick(stades, dictionary, words, countWords);
	this->stade100 = new ListWithArray<StadeSuc, int>();
	this->stadePerc = new ListWithArray<StadeSuc, int>();
	compareXY();
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
int DNAcompare::countStades(string* sequences){
	int temp = 0;
	char* firstChar = new char[this->numWords];
	int count = 0; //Suma de caracteres que tienen la misma raiz de diferentes palabras
	for (int i = 0; i < this->numWords; i++){
		firstChar[i] = sequences[i][0];
		temp += sequences[i].length();
	}
	//Comparacion de prefijos de las palabras
	for (int j = 1; j < this->numWords; j++){
		for (int k = 0; k < this->numWords-1; k++){
			if (j != k && firstChar[j] == firstChar[k]){
				for (unsigned int m = 1; m < sequences[j].length(); m++){
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
 * Metodo que realiza la comparacion de la secuencia X con las palabras de entrada Y
 */
void compareXY(){

}

/**
* Metodo get del atributo numWords
* @param a string que contiene un char que se usa para representar las condiciones actuales 
* @return Data<D> que sigue al estado recibido en la matriz de transicion de estados
*/
stade* nextE(stade* d, string a){
	int pos = this->dicc.find(a);
	int nexts = this->graph->stadeMat[pos][*d->tag];
	&this->graph->stades->get(nexts);
}


/**
* Metodo get del atributo dicc
* @return string que contiene el diccionario
*/
string DNAcompare::getDicc(){
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
GraphAhoCorasick* DNAcompare::getGraph(){
	return this->graph;
}
