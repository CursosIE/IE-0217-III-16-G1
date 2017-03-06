/**
* @author Luis Adrian Aguilar Cascante - B00092
* @author Robin Gonzalez - B43011	
* @author Giancarlo Marin - B54099
* @date 01-03-2017
* @brief Libreria de la clase GraphAhoCorasick que implementa un grafo con una representacion matricial de un diccionario determinado y una lista de estados
*/

#ifndef GRAPHAHOCORASICK_H
#define GRAPHAHOCORASICK_H

#include "List.h"
#include "ListWithArray.h"
#include "Stade.h"

using namespace std;

class GraphAhoCorasick{
public:
	/**
	* Constructor de la clase GraphAhoCorasick
	*/
	GraphAhoCorasick(){
		int**StadeMat = nullptr;
		this->Stades = new ListWithArray<Stade, int>();
		this->numStades = 0;
		this->numWords = 0;
	}

	/**
	* Constructor sobrecargado de la clase GraphAhoCorasick
	* @param totStates		Entero que indica la cantidad de estados del grafo
	* @param dictionary		Array de char que contiene el diccionario de caracteres por utilizar
	* @param Y				Matriz de char que contiene cada una de los elementos de cada palabra a insertar al grafo y que representa cada estado
	* @param countWords		int que indica el numero de palabras que se desean mapear en la Matriz de transicion de estados
	*/
	GraphAhoCorasick(int totStates, string dictionary, string* Y, int countWords){
		this->Stades = new ListWithArray<Stade, int>();
		this->numStades = totStates + 1;							//Se anade un estado mas, el neutro
		insertStades();												//Se agregan todos los estados a la lista
		this->Dicc = dictionary;
		this->numWords = countWords;								
		this->firstChar = getFirstChar(Y);							
		setStadeMat(Y);	
	}

	/**
	 * Destructor de la clase GraphAhoCorasick
	*/
	~GraphAhoCorasick(){
		delete *StadeMat;
		delete StadeMat;
		delete Stades;
	}

	/**
	 * Metodo que agrega todos los estados a la lista de estados
	*/
	void insertStades(){
		for (int i = 0; i < this->numStades; i++){
			Stade* temp = new Stade(new int(i));
			if (i == 5 || i == 10 || i == 14){
				temp->success100 = true;
			}
			else if (i == 4 || i == 9 || i == 13){
				temp->successLes100 = true;
			}
			this->addState(*temp);
		}
	}

	/**
	* Metodo que genera la matriz de transicion vacia inicializando todo en 0
	*/
	void initMat(){
		this->StadeMat = new int*[this->Dicc.length()];
		for (unsigned int i = 0; i < this->Dicc.length(); i++){ //Se asiga el tamano de diccionario como cantidad de filas
			this->StadeMat[i] = new int[this->numStades];
			for (int j = 0; j <this->numStades; j++){ //Se asigna la cantidad de estados como columnas
				this->StadeMat[i][j] = 0;
			}
		}
	}

	/**
	* Metodo que rellena la matriz de transicion con los estados de las palabras completas para modelar el grafo sin incluir conexiones entre sufijos y prefijos
	* @param words	Puntero a string que contiene las palabras a buscar
	*/
	void wordsToMat(string* words){
		int actualState = 0;	//Estado el que me encuentro asignando arista
		bool prefijo = false;
		for (int j = 0; j < this->numWords; j++){
			for (unsigned int k = 0; k < words[j].length(); k++){
				prefijo = false;
				if (j != 0 && k == 0){
					for (int m = 0; m < j; m++){
						if (m != j && this->firstChar[j] == this->firstChar[m]){
							for (unsigned int n = 1; n < words[m].length(); n++){
								if (words[m][n] != words[j][m]){ //n lleva la cuenta de letras que coinciden
									k = n;
									prefijo = true;
									break;
								}
							}
						}
					}
				}
				if (!prefijo){
					this->addTran(actualState, words[j][k], actualState + 1);//ingreso ordenado de palabras
				}
				actualState++;
			}
		}
	}

	/**
	 * Metodo que genera una matriz booleana donde genera valores true en las palabras que comienzan con el mismo caracter del diccionario
	 * @return bool** con valor true en los campos de las palabras que comienzan con el caracter c
	 */
	bool** sameFirstChar(){
		bool** temp = new bool*[this->numWords];
		for (int i = 0;i<this->getSizeDicc();i++){
			temp[i] = new bool[this->numWords];
			for (int j = 0; j < this->numWords; j++){
				if (firstChar[j] == this->Dicc[i]){
					temp[i][j] = true;
				}
				else{
					temp[i][j] = false;
				}
			}
		}
		return temp;
	}

	/**
	* Metodo que rellena la matriz con las relaciones de sufijos y prefijos entre palabras
	* @param words	Puntero a string que contiene las palabras a buscar
	*/
	void fixMat(string* words){
		int actualStade = 0;	//estado actual
		int nextStade = 0;		//estado siguiente
		bool** mat = sameFirstChar();
		for (int i = 0; i < this->numStades; i++){
			actualStade = i;
			for (int j = 0; j < this->numWords; j++){
				if (this->StadeMat[Dicc.find(this->firstChar[j])][actualStade]==0 && j==0){
					addTran(actualStade, this->firstChar[j],1);
				}
				else if (j !=0 && this->StadeMat[Dicc.find(this->firstChar[j])][i] == 0){
					addTran(actualStade, this->firstChar[j], 6);
				}

				//voy por aqui
			}
		}
	}

	/**
	* Metodo que rellena la matriz de transicion
	* @param words	Puntero a string que contiene las palabras a buscar
	*/
	void setStadeMat(string* words){
		initMat();				//Se crea la matriz de estados en 0s del tamano correcto
		wordsToMat(words);		//Rellena la matriz con las transiciones entre palabras
		fixMat(words);				//Rellena las relaciones de sufijos y prefijos en la matriz de transicion
	}

	/**
	* Metodo que imprime la matriz de estados
	*/
	void printStadeMat(){
		for (unsigned int i = 0; i < this->Dicc.length(); i++){
			for (int j = 0; j < this->numStades; j++){
				cout << this->StadeMat[i][j] << "\t";
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
		return this->Dicc.length();
	}

	/**
	* Metodo get del atributo Stades (Lista de estados)
	* @return	List<Stade, int>* con la lista de estados del grafo AhoCorasick
	*/
	List<Stade, int>* getStades(){
		return this->Stades;
	}

	/**
	* Metodo que agrega un estado a la lista de estados del grafo
	* @param n		Stade Que contiene el estado a agregar
	*/
	void addState(Stade n){
		this->Stades->insert(n);
	}

	/**
	* Metodo que agrega conexiones entre estados en la matriz de transicion de estados
	* @param prevStade	int que indica el estado en el que me encuentro
	* @param letter		int indice de la lista de diccionario que representa el caracter que me lleva al siguiente estado a partir del estado actual
	* @param nextStade	int que indica el proximo estado
	*/
	void addTran(int prevStade, int letter, int nextStade){
		for (int i = 0; i < this->getSizeDicc();i++){
			if (Dicc[i] == letter){
				this->StadeMat[i][prevStade] = nextStade;
				return;
			}
		}	
	}

	/**
	* Metodo que devuelve el primer estado de la lista de estados
	* @return Stade con el estado inicial
	*/
	Stade firstStade(){
		return this->Stades->get(0);
	}

	/**
	* Metodo que devuelve el siguiente estado de la lista de estados a partir de un estado dado
	* @param s	 Stade que se utiliza como indice
	* @return	 Stade con el estado siguiente de s
	*/
	Stade nextStade(Stade s){
		int temp = this->Stades->next(this->Stades->find(s));
		if (temp != -1){
			return this->Stades->get(temp);
		}
		else{
			return firstStade();
		}
	}

	/**
	* Metodo que devuelve la matriz de transicion del grafo
	* @return	 Stade pertenencente a la posicion i de la lista de estados
	*/
	int** getStateMat(){
		return this->StadeMat;
	}

	/**
	* Metodo que devuelve el estado en la posicion i de la lista
	* @param i	 int indice de la lista
	* @return	 Stade pertenencente a la posicion i de la lista de estados
	*/
	Stade getState(int i){
		return this->Stades->get(i);
	}

	/**
	* Metodo que devuelve la etiqueta del estado contenido en un Stade especifico n
	* @param n	 Stade que se desea obtener etiqueta
	* @return	 D que representa la etiqueta del estado en el Stade
	*/
	int getTag(Stade s){
		int temp = this->Stades->find(s);
		if (temp != -1){
			return *(s.tag);
		}
		return -1;
	}

	/**
	 * Metodo que devuelve una cadena de caracteres con la primer letra de cada palabra
	 * @param words		String* con las palabras por buscar
	 * @return	 char* que contiene la primera letra de cada palabra
	 */
	char* getFirstChar(string* words){
		char*temp=new char[this->numWords];
		for (int i = 0; i < this->numWords; i++){
			temp[i] = words[i][0];
		}
		return temp;
	}

private:
	int numStades;		///Cantidad de estados representados en el grafo///
	int** StadeMat;		///Matriz de Transicion de Estados que representa los movimientos en el grafo de estados de tipo entero///
	List<Stade, int>* Stades;///Lista de estados que contiene como Dato una etiqueta del estado (int) y como indice un entero (int)///
	string Dicc;		///Cadena de caracteres diccionario///
	int numWords;		///Cantidad de palabras a mapear en la matriz de transicion///
	char* firstChar;	//Cadena de caracteres de tamano numWords con el primer caracter de cada palabra
};

#endif /* GRAPHAHOCORASICK_H */
