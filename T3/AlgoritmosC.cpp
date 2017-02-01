/*
 *Universidad de Costa Rica - Escuela de Ingenieria Electrica
 *IE-0217 - Tarea3 - Grupo01
 *@author Robin Gonzalez Ricz @authorLuis Adrian Aguilar Cascante 
 *@date   01-31-2017
 *@brief  implementación del algoritmo Selection sort y Binary search en c++
*/
#include <iostream>//cout cin
#include <fstream>//archivos de entrada/ salida
#include <cstdlib>//atoi
#include <vector>//vectores
#include <algorithm>//poder usar la función iter_swap


using namespace std;

string leido;
vector <int> lista;

void printVec(vector<int> a, int largo){
	for(int i = 0; i<largo;i++)cout << a[i] << endl;
}

int main (int argc, char** argv){
	string algoritmo = argv[1];//Primer argumento es el tipo de algoritmo
	ifstream archivo(argv[2]);//Segundo argumento es el nombre del archivo para leer la lista de numeros
	cout << algoritmo << endl;
	cout << argv[2] << endl;
	if(!(algoritmo.compare("ss"))||!(algoritmo.compare("SS"))){//la función compare retorna 0 si los strings son iguales, por eso ponemos ! para que sea 1 de ser el caso
//	if(!(algoritmo.compare("ss"))){
		int i = 0;
		while(getline(archivo, leido,' ')){
//			entrada[i] = atoi(leido.c_str());
			lista.push_back(atoi(leido.c_str()));//añade de último elemento el número leido
			cout <<"Entrada "<< i<< ":" << lista[i] << endl;
			i++;
		}//en este punto ya tengo el vector listo para ser ordenado
		printVec(lista, i);
		int menor;
		for(int c = 0;c<i;c++){
			menor = c;
			for(int d = c+1;d<i;d++){
				if(lista[d] < lista[menor])menor = d;
			iter_swap(lista.begin() + menor, lista.begin() + c);//intercambia dos elementos de un vector en las posiciones dadas: de pos menor a c
			}
		}
		printVec(lista, i);//aquí el vector ya debería estar ordenado
	}

//	if(!(algoritmo.compare("bs"))||!(algoritmo.compare("BS"))){//la función compare retorna 0 si los strings son iguales, por eso ponemos ! para que sea 1 de ser el caso
		int min    = 0;
		int max   = lista.size();//uso vector previamente ordenado por el SS
		int mitad;
		int buscado;
		cout << "Ingrese el número a buscar: " << endl;
		cin >> buscado;
		int waaa = (min + max) >> 1;
		while (min +1 != max) {//mientras el min y max sean diferentes:
			mitad = ((min + max) >> 1);//forma de sacar el promedio
			if (lista[mitad] > buscado) {
				max = mitad;
			} else {
				min = mitad;
			}
		}
		if (lista[min] == buscado) {
			cout << "Buscado: " << buscado << " encontrado en: " << min << endl;
		} else {
			cout << "Buscado: " << buscado << " NO encontrado" << endl;
		}
//	}
	return 0;
}

