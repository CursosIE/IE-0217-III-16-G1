/*
 *	Universidad de Costa Rica
 *	IE-0217 - Tarea 3: Tiempos y Ordenes de Duracion
 *	@author Giancarlo Marin, Luis Adrian Aguilar, Robin Gonzalez
 *      @date 01-02-2016
 * 	@brief Implementacion de los algoritmos Selection Sort (SS) y Binary Search (BS)
*/
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <fstream>
#include <math.h>
#include <string>

using namespace std;
// variable global tipo clock_t para iniciar el conteo de tiempo de ejecucion de cada algoritmo
static clock_t inicio;		

/*
 *	Funcion que intercambia dos elementos en las posiciones i y k en un arreglo (lista)
 *	@param int* 	Puntero a un arreglo de enteros
 *	@param int	Subindice del primer numero a cambiar
 *	@param int	Subindice del segundo numero a cambiar
*/
void interchange(int* lis, int i, int k){
	int temp = lis[i];
	lis[i] = lis[k];
	lis[k] = temp;
}

/*
 * Implementacion de algoritmo Slection Sort (SS) 
 * @param string 	Nombre del archivo que contiene la lista de elementos a ordenar
 * @param int		Cantidad de elemento en la lista
 * @return int*		Puntero a la lista ordenada de elementos
*/
int* SS(string nombreArch, int n){
	int* lis = new int[n];				// Puntero a array de enteros de tamaño n	
	string temp = "";				// String vacio para guardar valores del archivo leido
	ifstream arch(nombreArch.c_str());		// Abre el archivo
	ofstream archOr("listaOrdenada.txt");
	if (arch.is_open()){ 				// Pregunta si el archivo esta abierto
		int i=0;				
		while (getline(arch,temp) && i<n){	// Ciclo de lectura de todo el archivo
			lis[i] = atoi(temp.c_str());	// Convierte en entero y la agrega a la lista	
			i++;
		}
	}
	arch.close();
	inicio = clock();		 		//Inicia el conteo del tiempo para el algoritmo
	//Paso #1: Largo del array n
	//Paso #2: Recorrido de la lista para encontrar el menor valor
	for (int i=0;i<n;i++){
		int min = i;
		for (int j=i+1;j<n;j++){
			if (lis[j]<lis[min]){
				min = j;			
			}
		}
	//Paso #3: Mover el minimo a la posicion i
		interchange(lis,i,min);
		archOr << lis[i] << endl;
	}
	archOr.close();
	return lis;
}

/*
 * Implementacion de algoritmo Binary Search (BS) Busqueda de un valor n dentro de una lista de enteros
 * @param string  	Archivo que contiene la lista de enteros
 * @param int		Numero que se quiere encontrar
 * @param int		Tamaño de la lista
 * @return bool		True en caso de ser encontrado y False de lo contrario
*/
bool BS(string nombreArch, int val, int n){	
	int* lista = new int[n];			// Puntero a array de enteros de tamaño n	
	string temp = "";				// String vacio para guardar valores del archivo leido
	ifstream arch(nombreArch.c_str());		// Abre el archivo
	if (arch.is_open()){ 				// Pregunta si el archivo esta abierto
		int i=0;				
		while (getline(arch,temp) && i<n){	// Ciclo de lectura de todo el archivo
			lista[i] = atoi(temp.c_str());	// Convierte en entero y la agrega a la lista	
			i++;
		}
	}
	arch.close();
	inicio = clock();				// Comienza la cuenta para el tiempo del algoritmo
	// Paso #1: Asignaciones
	int min = 0; 				// Indice inferior de la busqueda en la lista
	int max = n-1; 				// Indice superior de la busqueda en la lista
	// Paso #2: Indice medio 
	int m = (double) floor((min+max)/2);	// Redondea hacia abajo en caso de ser una sublista impar
	while (min<=max){			// Ciclo mientras los indices no se crucen
	// Paso #3: Determinar si encontro el valor
		if (lista[m]==val){
			return 1;
		}
		else if (lista[m] > val){
			max = m-1;
		}
		else{
			min = m+1;
		}
// Paso #4: Reasignar el m en caso de no encontrarlo y volver al paso #2		
		m = (double) floor((min+max)/2); 
	}
	return 0;
}

/*
 * Main del programa
 */
int main(int argc, char** argv){
	string algoritmo =  argv[1];		// el primer argumento es el tipo de algoritmo
	int n =  atoi(argv[2]);			// largo de la lista
	clock_t inicio;				// Crea la lectura inicial de tiempo de ejecucion
	if (algoritmo=="BS"){			// Determina que algoritmo se va a ejecutar BS o SS
		int val = atoi(argv[3]);	// Valor que se desea buscar
		string doc = argv[4];		// nombre del archivo que contiene la lista
		bool encontro = BS(doc,val,n);	
		clock_t final = clock();	// Detiene el tiempo de ejecucion en BS
		// tiempo transcurrido entre ciclos de reloj en un segundo para obtener los segundos
		double tiempo = double(abs(final-inicio))/CLOCKS_PER_SEC; 
		cout << encontro << "\nTIME=" << tiempo << "s" << endl;
	}
	else if (algoritmo=="SS"){
		string doc(argv[3]);		// nombre del archivo que contiene la lista		
		int* lis=SS(doc,n);
		clock_t final = clock();
		// tiempo transcurrido entre ciclos de reloj en un segundo para obtener los segundos
		double tiempo = double(abs(final-inicio))/CLOCKS_PER_SEC; 
		for (int i=0;i<n;i++){
			cout << lis[i] << " ";
		}
		cout << "\nTIME=" << tiempo << "s" << endl;
	}
	return 0;
}

