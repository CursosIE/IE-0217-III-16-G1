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
	if(!(algoritmo.compare("ss")||algoritmo.compare("SS"))){//la función compare retorna 0 si los strings son iguales, por eso ponemos ! para que sea 1 de ser el caso
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
		printVec(lista, i);//aquí el vector ya debería estar ordenado
	}

	if(!(algoritmo.compare("bs")||algoritmo.compare("BS"))){//la función compare retorna 0 si los strings son iguales, por eso ponemos ! para que sea 1 de ser el caso
		//AQUI VA EL BINARY SORT EN C++
	}



//Algoritmo binary search

l = lista.size(); 
int min = 0;
int max = l-1;
y = (min+max/2);
m = int(floor(y));


print m;
print l;

cout << "Inserte un número";
cin >> int n >> endl ;

while (l!=0)
	{
	if lista[m]==n:
		print m;
	}	

	else if (lista[m] > n)
		{
		max = m-1;
		lista = lista[min:max];
		l = lista.size();
		m = int(floor((min+max)/2));
		}

	else if (lista[m] < n)
	{
		min = m+1;
		lista = lista[min:max];
		l = lista.size();
		m = int(floor((min+max)/2)); 
	}



	else if (lista(m) < n)
		{
		min = m+1;
		lista = lista[min:max];
		l = lista.lenght;
		m = floor((min+max)/2); 
		}




	return 0;
}

