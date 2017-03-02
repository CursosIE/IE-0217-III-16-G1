/**
* @author Giancarlo Marin Hernandez - B54099
* @date 01-03-2017
* @brief Libreria de la clase GraphAhoCorasick que implementa un grafo con una representacion matricial de un diccionario determinado y una lista de estados
*/

#ifndef GRAPHAHOCORASICK_H
#define GRAPHAHOCORASICK_H

#include "List.h"
#include "ListWithArray.h"
#include "Data.h"

using namespace std;

template<typename D>/**Biblioteca de la clase GraphAhoCorasick que genera una representacion matricial de un Grafo de estados por medio de arreglos*/
#define STADE Data<D>/// Definicion de STADE como una etiqueta para objetos de tipo Data<D> emplantillado///
class GraphAhoCorasick{
public:
	/**
	* Constructor de la clase GraphAhoCorasick
	*/
	GraphAhoCorasick(){
		int**stadeMat = nullptr;
		this->stades = new ListWithArray<STADE, int>(10);
		this->numStades = 0;
		this->stades->insert(STADE(new D(0)));//Se anade un estado neutro por default
		this->numStades = 1;
	}

	/**
	* Constructor sobrecargado de la clase GraphAhoCorasick
	* @param totStates		Entero que indica la cantidad de estados del grafo
	* @param dictionary		Array de char que contiene el diccionario de caracteres por utilizar
	* @param Y				Matriz de char que contiene cada una de los elementos de cada palabra a insertar al grafo y que representa cada estado
	*/
	GraphAhoCorasick(int totStates, string dictionary, string* Y){
		this->stades = new ListWithArray<STADE, int>(10);
		this->stades->insert(STADE(new D(0)));						//Se anade un estado neutro por default
		this->numStades = totStates+1;								//Se anade un estado mas, el neutro
		this->sizeDicc = dictionary.length();						//Se determina el tamano del diccionario  
		initMat();													//Se crea la matriz de estados en 0s del tamano correcto
		//insertStades(Y);
		//setStadeMat(Y);
	}

	/**
	* Destructor de la clase GraphAhoCorasick
	*/
	~GraphAhoCorasick(){
		delete *stadeMat;
		delete stadeMat;
		delete stades;
	}

	/**
	* Metodo que genera la matriz de transicion vacia inicializando todo en 0
	*/
	void initMat(){
		this->stadeMat = new int*[this->sizeDicc];
		for (int i = 0; i < this->sizeDicc; i++){ //Se asiga el tamano de diccionario como cantidad de filas
			this->stadeMat[i] = new int[this->numStades];
			for (int j = 0; j <this->numStades; j++){ //Se asigna la cantidad de estados como columnas
				this->stadeMat[i][j] = 0;
			}
		}
	}

	/**
	* Metodo que crea la matriz de transicion de estados para modelar el grafo despues de tener todos los estados y sus relaciones
	* @param words	Puntero a string que contiene las palabras a buscar
	*/
	void setStadeMat(string* words){
		
	}

	/**
	* Metodo que imprime la matriz de estados
	*/
	void printStadeMat(){
		for (int i = 0; i < this->sizeDicc; i++){
			for (int j = 0; j < this->numStades; j++){
				cout << this->stadeMat[i][j] << " ";
			}
			cout << endl;
		}
	}

	/**
	 * Metodo get del atributo numStade
	 * @return int con la cantidad de estados del grafo AhoCorasick
	 */
	int getNumStades(){
		return this->numStades;
	}

	/**
	* Metodo get del atributo sizeDicc
	* @return int con la cantidad de elementos del diccionario del grafo AhoCorasick
	*/
	int getSizeDicc(){
		return this->sizeDicc;
	}

	/**
	* Metodo get del atributo stades (Lista de estados)
	* @return	List<STADE, int>* con la lista de estados del grafo AhoCorasick
	*/
	List<STADE, int>* getStades(){
		return this->stades;
	}

	/**
	* Metodo que agrega un estado a la lista de estados del grafo
	* @param n		STADE Que contiene el estado a agregar
	*/
	void addState(STADE n){
		this->states->insert(n);
	}

	/**
	* Metodo que agrega conexiones entre estados en la matriz de transicion de estados
	* @param prevStade	int que indica el estado en el que me encuentro
	* @param letter		int indice de la lista de diccionario que representa el caracter que me lleva al siguiente estado a partir del estado actual
	* @param nextStade	int que indica el proximo estado
	*/
	void addTran(int prevStade, int letter, int nextStade){
		this->stadeMat[letter][prevStade] = nextStade;
	}

	/**
	* Metodo que devuelve el primer estado de la lista de estados
	* @return STADE con el estado inicial
	*/
	STADE firstStade(){
		return this->stade->get(0);
	}

	/**
	* Metodo que devuelve el siguiente estado de la lista de estados a partir de un estado dado
	* @param s	 STADE que se utiliza como indice
	* @return	 STADE con el estado siguiente de s
	*/
	STADE nextStade(STADE s){
		int temp = this->stades->next(this->stades->find(s));
		if (temp != -1){
			return this->stades->get(temp);
		}
		else{
			return firstStade();
		}
	}

	/**
	* Metodo que devuelve el estado en la posicion i de la lista
	* @param i	 int indice de la lista
	* @return	 STADE pertenencente a la posicion i de la lista de estados
	*/
	STADE getState(int i){
		return this->stades->get(i);
	}

	/**
	* Metodo que devuelve la etiqueta del estado contenido en un STADE especifico n
	* @param n	 STADE que se desea obtener etiqueta
	* @return	 D que representa la etiqueta del estado en el STADE
	*/
	D getTag(STADE s){
		int temp = this->stades->find(s);
		if (temp != -1){
			return *(s.data);
		}
		return -1;
	}

private:
	int numStades;///Cantidad de estados representados en el grafo///
	int** stadeMat;///Matriz de Transicion de Estados que representa los movimientos en el grafo de estados de tipo entero///
	List<STADE, int>* stades;///Lista de estados que contiene como Dato una etiqueta del estado (int) y como indice un entero (int)///
	int sizeDicc;///Cantidad de caracteres que contiene el diccionario a representar///
};

#endif /* GRAPHAHOCORASICK_H */
