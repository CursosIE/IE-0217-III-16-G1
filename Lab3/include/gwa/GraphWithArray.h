/**
 * @author Giancarlo Marin Hernandez - B54099
 * @author Robin Gonzalez Ricz - B43011
 * @date 27-02-2017	
 * @brief Libreria de la clase GraphWithArray que implementa un grafo con una representacion matricial que contiene datos de tipo Data
*/

#ifndef GRAPHWITHARRAY_H
#define GRAPHWITHARRAY_H

#include "List.h"
#include "ListWithArray.h"

using namespace std;

template<typename D, typename C>/**Biblioteca de la clase GraphWithArray que genera Grafos por medio de arreglos*/
#define NODE Data<D>/// Definicion de NODE como un objeto Data emplantillado///
class GraphWithArray{
public:
	int cantNodos;///Cantidad de nodos del grafo///
	C** mA;///Matriz de Adyacencia de costo tipo C para representacion del Grafo///
	List<NODE, int>* nodos;///Lista de nodos con indice de enteros ///

	/**
	* Constructor de la clase GraphWithArray
	*/
	GraphWithArray(){
		C** mA = nullptr;
		this->nodos = new ListWithArray<NODE, int>(10);
		this->cantNodos = 0;
	}

	/**
	* Destructor de la clase Graph
	*/
	~GraphWithArray(){
		delete *mA;
		delete mA;
		delete nodos;
	}

	/**
	* Metodo que genera la matriz de adyacencia para modelar el grafo despues de cada insercion de vertices
	* @return	Puntero doble de tipo C que representa la matriz de pesos en las aristas de conexion donde -1 indica que no hay conexion 
	*/
	C** buildM(){//crea la matriz de adyacencias
		C** temp = new C*[cantNodos];
		temp = inicMat(temp, this->cantNodos);
		if (this->mA && cantNodos > 1){
			for (int i = 0; i < cantNodos-1; i++){
				if (this->mA[i]){
					for (int j = 0; j < cantNodos-1; j++){
						if (this->mA[i][j] != temp[i][j]){
							temp[i][j] = mA[i][j];
						}
					}
				}
			}
		}
		return temp;
	}

	/**
	 * Metodo que genera una matriz de inicializada en -1 
	 * @return	Puntero doble a tipo C que contiene una matriz llena de -1 de tamaño del array que contiene los nodos
	 */
	C** inicMat(C** m, int tam){
		for (int i = 0; i < tam; i++){
			m[i] = new C[cantNodos];
			for (int j = 0; j < tam; j++){
				m[i][j] = -1.0; 
			}
		}
		return m;
	}

	/**
	* Metodo que imprime la matriz de adyacencia
	*/
	void printM(){
		for (int i = 0; i < cantNodos; i++){
			for (int j = 0; j < cantNodos; j++){
				cout << mA[i][j] << "\t";
			}
			cout << endl;
		}
	}

	/**
	* Metodo que agrega Vertices a la lista de Vertices del grafo
	* @param n		Que contiene el nodo a agregar
	*/
	void addNode(NODE n){
		this->nodos->insert(n);
		++cantNodos;
		this->mA = this->buildM();
	}

	/**
	* Metodo que agrega conexiones entre nodos en la matriz de adyacencias
	* @param costo		Tipo C que indica el costo de la arista donde -1 representa sin conexion
	* @param s			Nodo source (origen) de la arista
	* @param d			Nodo destination (destino) de la arista
	*/
	void addEdge(C costo, NODE s, NODE d){
		mA[this->nodos->find(s)][this->nodos->find(d)] = costo;
	}

	/**
	* Metodo que elimina conexiones entre nodos en la matriz de adyacencias. Asigna un -1 al campo [s][d]
	* @param s			Nodo source (origen) de la arista
	* @param d			Nodo destination (destino) de la arista
	*/
	void delEdge(NODE s, NODE d){
		mA[this->nodos->find(s)][this->nodos->find(d)] = -1;
	}

	/**
	* Metodo que elimina nodos del grafo. Primero elimina todas sus conexiones origen y destino y luego reacomoda la lista de nodos y reacomoda la matriz de adyacencia
	* @param s			Nodo source (origen) de la arista
	* @param d			Nodo destination (destino) de la arista
	*/
	void delNode(NODE d){
		//Eliminar mis aristas con destino a d y correccion de matriz de adyacencia
		int pos = this->nodos->find(d);
		for (int i = 0; i < cantNodos; i++){
			for (int j = 0; j < cantNodos; j++){
				if (j>pos && mA[i][j]!=-1){
					mA[i][j-1] = mA[i][j];
					mA[i][j] = -1;
				}
				else if (i>pos && mA[i][j]){
					mA[i - 1][j] = mA[i][j];
					mA[i][j] = -1;
				}
				else if (mA[i][j] != -1 && i == pos){
					delEdge(d, this->nodos->get(i));
				}
				else if (j == pos && mA[i][j] != -1){
					delEdge(this->nodos->get(i), d);
				}
			}
		}
		//Eliminar nodo y recrear matriz de adyacencia
		this->nodos->remove(d);
		this->mA = this->buildM();
		cantNodos--;
	}

	/**
	* Metodo que devuelve el primer nodo de la lista de nodos
	* @return NODE con el nodo inicial
	*/
	NODE firstNode(){
		return this->nodos->get(0);
	}

	/**
	* Metodo que devuelve el siguiente nodo a primer de un nodo de la lista de nodos
	* @param n	 NODE que se utiliza como indice
	* @return	 NODE con el nodo siguiente de n
	*/
	NODE nextNode(NODE n){
		int temp = this->nodos->next(this->nodos->find(n));
		if (temp != -1){
			return this->nodos->get(temp);
		}
		else{
			return firstNode();
		}
	}

	/**
	* Metodo que devuelve el nodo en la posicion i de la lista
	* @param i	 int indice de la lista 
	* @return	 NODE pertenencente a la posicion i de la lista de nodos
	*/
	NODE Node(int i){
		return this->nodos->get(i);
	}

	/**
	* Metodo que devuelve el dato contenido en un nodo especifico n
	* @param n	 NODE que se desea obtener dato
	* @return	 Dato de tipo D contenido en el Nodo
	*/
	D getData(NODE n){
		int temp = this->nodos->find(n);
		if (temp != -1){
			return *(n.data);
		}
		return -1;
	}

	/**
	* Funcion apendice de la busquedas dfs y bfs que devuelve un array de bool que representa los nodos recorridos 
	* @param valIni	 bool que indica que valor se va a inicializar el array
	* @return	 Puntero a bool que apunta al array de recorrido
	*/
	bool* mRecoBuild(bool valIni){
		//Utilizando un vector de recorrido de nodos para determinar los visitados y evitar ciclos
		bool* mRecorrido = new bool[this->cantNodos];
		for (int i = 0; i < this->cantNodos; i++){
			mRecorrido[i] = valIni;
		}
		return mRecorrido;
	}

	/**
	* Metodo apendice de la busquedas dfs que devuelve el NODE con el dato buscado d o un NODE con -1 de lo contrario
	* @param d	NODE con el dato buscado
	* @param n	NODE donde comienza la busqueda 
	* @param mReco	Puntero a bool con el array de los nodos ya recorridos
	* @return	NODE con el dato d buscado
	*/
	NODE dfsFinding(NODE d, NODE n, bool* mReco){
		if (this->getData(d) == this->getData(n)){
			return n;
		}
		int pos = this->nodos->find(n);
		mReco[pos] = true;
		for (int j = 0; j < cantNodos; j++){
			if (!mReco[j] && this->mA[pos][j]!=-1){
				return dfsFinding(d, this->nodos->get(j), mReco);
			}
		}
		return NODE(new D(-1));
	}

	/**
	* Metodo de busqueda en profundidad (dfs) que devuelve el NODE con el dato buscado d o un NODE con -1 de lo contrario utilizando un recorrido primero en profundidad
	* @param d	NODE con el dato buscado
	* @return	NODE con el dato d buscado
	*/
	NODE dfs(NODE d){
		return dfsFinding(d, this->firstNode(), mRecoBuild(false));
	}

	/**
	* Metodo apendice de la busquedas bfs que devuelve el NODE con el dato buscado d o un NODE con -1 de lo contrario
	* @param d	NODE con el dato buscado
	* @param n	NODE donde comienza la busqueda
	* @param mReco	Puntero a bool con el array de los nodos ya recorridos
	* @return	NODE con el dato d buscado
	*/
	NODE bfsFinding(NODE d, NODE n, bool* mReco){
		if (this->getData(n)==this->getData(d)){
			return n;
		}
		int pos = this->nodos->find(n);
		mReco[pos] = true;
		double* level1 = mA[pos];
		for (int i = 0; i < cantNodos; i++){
			if (level1[i] != -1 && this->getData(d) == this->getData(this->Node(i))){
				return this->Node(i);
			}
			else if(level1[i] !=-1){
				return bfsFinding(d, this->nodos->get(i), mReco);
			}
		}
		return NODE(new D(-1));
	}

	/**
	* Metodo de busquedas en anchura (bfs) que devuelve el NODE con el dato buscado d o un NODE con -1 de lo contrario, utilizando un recorrido primero en anchura del grafo
	* @param d	NODE con el dato buscado
	* @return	NODE con el dato d buscado
	*/
	NODE bfs(NODE d){
		return bfsFinding(d, this->firstNode(), mRecoBuild(false));
	}

	double* dijkstra(){

	}

	double** floyd(){

	}
};

#endif /* GRAPHWITHARRAY_H */