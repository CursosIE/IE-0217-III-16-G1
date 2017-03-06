/**
* @author Luis Adrian Aguilar Cascante - B00092
* @author Robin Gonzalez - B43011	
* @author Giancarlo Marin - B54099
* @date 01-03-2017
* @brief Implementacion de los metodos de la clase clase DNAcompare
*/
#include "../include/DNAcompare.h"

/**
 * Constructor de la clase DNAcompare
 */
DNAcompare::DNAcompare(){
	this->Dicc = "";
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
	this->Dicc = dictionary;
	this->X = stringX;
	this->Y = words;
	this->numWords = countWords;
	this->checkPerc = percentage;
	int stades = countStades(words);
	this->graph = new GraphAhoCorasick(stades, dictionary, words, countWords);
	this->stade100 = new ListWithArray<StadeSuc, int>();
	this->stadePerc = new ListWithArray<StadeSuc, int>();
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
* Metodo que agrega el indice de la secuencia a la lista correcta de exito en caso de un estado de exito
* @param s	Objeto Stade del estado actual
* @param i int que indica el indice sobre la secuencia X
* @param suc100 bool que indica que tipo de exito se dio en el estado si true es suc100 de lo contrario sucLes100
* @param int que indica el numero de palabra que tuvo exito
*/
void DNAcompare::output(Stade s, int i, bool suc100, int numP){
	if (suc100){
		this->stade100->insert(StadeSuc(i,numP));
		cout << "SUCCESS 100" << endl;
	}
	else{
		this->stadePerc->insert(StadeSuc(i, numP));
		cout << "SUCCESS 80" << endl;
	}
}

/**
* Metodo que obtiene el siguiente estado a partir de un estadoa actual y un caracter de entrada pertenneciente al diccionario
* @param s	Objeto Stade del estado actual
* @param a  char del diccionario que se obtiene como entrada
* @return	Objeto Stade del estado siguiente
*/
Stade DNAcompare::nextS(Stade s, char c){
	int row = this->Dicc.find(c);
	int nextStade = this->graph->getStateMat()[row][*s.tag];
	return this->graph->getStades()->get(nextStade);
}

/**
 * Metodo que realiza la comparacion de la secuencia X con las palabras de entrada Y
 */
void DNAcompare::compareXY(){
	Stade actualStade = this->getGraph()->getStades()->get(0); //siempre comienza en estado 0
	for (unsigned int i = 0; i < this->X.length();i++){
		actualStade = this->nextS(actualStade, X[i]);
		if (actualStade.success100 && *actualStade.tag == 5){
			output(actualStade, i, actualStade.success100, 0);
		}
		else if (actualStade.success100 && *actualStade.tag == 10){
			output(actualStade, i, actualStade.success100, 1);
		}
		else if (actualStade.success100 && *actualStade.tag == 14){
			output(actualStade, i, actualStade.success100, 2);
		}
		else if (actualStade.successLes100 && *actualStade.tag == 4){
			output(actualStade, i, actualStade.successLes100, 0);
		}
		else if (actualStade.successLes100 && *actualStade.tag == 9){
			output(actualStade, i, actualStade.successLes100, 1);
		}
		else if (actualStade.successLes100 && *actualStade.tag == 13){
			output(actualStade, i, actualStade.successLes100, 2);
		}
		cout << *actualStade.tag;
	}
	cout << endl;
}

/**
* Metodo get del atributo dicc
* @return string que contiene el diccionario
*/
string DNAcompare::getDicc(){
	return this->Dicc;
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

/**
* Metodo get de la lista suc100 graph
* @return lista de exito 100 
*/
List<StadeSuc,int>* DNAcompare::getStade100(){
	return this->stade100;
}

/**
* Metodo get de la lista suc100 graph
* @return lista de exito 100
*/
List<StadeSuc, int>* DNAcompare::getStadePerc(){
	return this->stadePerc;
}
