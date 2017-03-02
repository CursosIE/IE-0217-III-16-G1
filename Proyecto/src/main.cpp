/**
* Universidad de Costa Rica - Escuela de Ingenieria ELectrica
* IE-0217 - PROYECTO: Comparacion de secuencias de nucleotidos de ADN utilizando el algoritmo Aho-Corasick
* @author Giancarlo Marin - B54099
* @date 26-02-2017
* @brief Programa de prueba para el funcionamiento de la comparacion de nucleotidos
*/
#include "../include/DNAcompare.h"
#define D int

using namespace std;

/**
* Main del programa que realiza las pruebas del Algoritmo Aho-Corasick implementado en comparacion de cadenas de nucleotidos de ADN
* @param int 		Indicador de la cantidad de argumentos pasados en la ejecucion del programa
* @param char**		Vector de char* que contiene los argumentos enviados al ejecutar el programa
* @return
*/
int main(int argc, char** argv) {
	cout << "-- ALGORITMO AHO-CORASICK PARA COMPARACION DE CADENAS DE NUCLEOTIDOS DE ADN --" << endl << endl;
	string dicc;//diccionario de caracteres
	string X="";//Cadena de caracteres por comparar
	string* Y;//Array de cadenas de caracteres por comparar
	int perce;//Porcentaje de comparacion de prefijos
	int numWords;//Cantidad de palabrasde busqueda
	string temp; //String temporal para copia de elementos tipo const char*
	string* temp2 = new string[10];//array de strings para copia de lectura de archivos
	if (argc != 5){
		cout << "FALTAN ARGUMENTOS PARA EL FUNCIONAMIENTO" << endl;
		return 0;
	}
	else{
		//Lectura de archivos pasados por parametros
		dicc = argv[1];
		ifstream fileX(argv[2]);
		if (fileX){//Si lee el archivo de sequencia
			cout << "Leyendo archivo " << argv[2] << endl;
			string tit; //Titulo de la secuencia de ADN formato FASTA
			getline(fileX, tit);
			int i = 0;
			while (getline(fileX, temp)){
				temp2[i] = temp;
				X += temp2[i];
				i++;
			}
			fileX.close();
		}
		ifstream fileY(argv[3]);
		if (fileY){
			cout << "Leyendo archivo " << argv[3] << endl;
			int i = 0;
			while (getline(fileY, temp)){
				temp2[i] = temp;
				i++;
			}
			fileY.close();
			numWords = i;
			Y = new string[numWords];
			i = 0;
			while (i<3){
				Y[i] = temp2[i];
				i++;
			}
		}
		perce = atoi(argv[4]);
		//Generar comparacion
		DNAcompare* cp1 = new DNAcompare(dicc, X, Y, perce, numWords);
		cout << "----- DATOS DE ENTRADA -----" << endl << endl;
		cout << "Diccionario = {" << dicc << "}" << endl;
		cout << "X = " << X << endl;
		for (int k = 0; k < cp1->getNumWords(); k++){
			cout << "y" << k << "= " << Y[k] << endl;
		}
		cout << "% = " << perce << endl;
		//Impresion de la matriz que representa el grafo de las palabras de busqueda
		cout << "----- CREANDO GRAFO -----" << endl;
		cout << "--- MATRIZ DE TRANSICION -----" << endl;
		cp1->getGraph()->printStadeMat();
		cout << "ELIMINANDO EL GRAFO..." << endl;
		delete cp1;
	}
	return 0;
};
