/*
 *Universidad de Costa Rica - Escuela de Ingenieria Electrica
 *IE-0217 - Tarea3 - Grupo01
 *@author Robin Gonzalez Ricz
 *@date   01-31-2017
 *@brief  implementación del algoritmo Selection sort y Binary search en c++
*/
#include <iostream>//cout cin
#include <fstream>//archivos de entrada/ salida
#include <cstdlib>//aoti
#include <vector>//vectores

using namespace std;

string leido;
vector <int> entrada;

int main (int argc, char** argv){
	string algoritmo = argv[1];
	ifstream archivo(argv[2]); 
	if(!algoritmo.compare("ss")){//la función compare retorna 0 si los strings son iguales, por eso ponemos ! para que se 1 de ser el caso
		int i = 0;
		while(getline(archivo, leido,' ')){
//			entrada[i] = atoi(leido.c_str());
			entrada.push_back(atoi(leido.c_str()));//añade de último elemento el número leido
			cout <<"Entrada "<< i<< ":" << entrada[i] << endl;
			i++;
		}//en este punto ya tengo el vector listo para ser ordenado
		int temp;
		int menor = entrada[0];
		for(int c = 0;c<i;c++){
			for(int d = 0;c<i;d++){
				if(entrada[c] < entrada[d])
					int menor =  entrada[c];
			}
		}
	}

	return 0;
}
