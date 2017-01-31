/*
 *Universidad de Costa Rica - Escuela de Ingenieria Electrica
 *IE-0217 - Tarea3 - Grupo01
 *@author Robin Gonzalez Ricz
 *@date   01-31-2017
 *@brief  implementación del algoritmo Selection sort y Binary search en c++
*/
#include <iostream>
#include <vector>

using namespace std;

string leido;
vector <int> entrada;

int main (int argc, char** agrv){
	string algoritmo = argv[1];
	string archivo = argv[2];
	if(!algoritmo.compare("ss")){//la función compare retorna 0 si los strings son iguales, por eso ponemos ! para que se 1 de ser el caso
		int i = 0;
		while(getline(archivo, leido,' ')){
			entrada[i] = atoi(leido.c_str());		
			cout <<"Entrada "<< i<< ":" << entrada[i] << endl;
			i++;
		}
	}

	return 0;
}
