/*
 *Universidad de Costa Rica - Escuela de Ingenieria Electrica
 *IE-0217 - Lab0 - Grupo01
 *@author Giancarlo Marin, @author Luis Adrian Aguilar, @author Robin 
 *@date   01-26-2017
 *@brief  Clase main que prubea el funconamiento del juego de ecologia
*/

#include "../include/Celda.hpp"
#include "../include/Animal.hpp"
#include "../include/Lobo.hpp"
#include "../include/Oveja.hpp"
#include "../include/Raton.hpp"
#include "../include/Zorro.hpp"
#include "../include/print.hpp"

/*
 * Metodo main que prueba el funcionamieno del juego de ecologia
 * @param int 		Cantidad de parametros obtenidos en la ejecucion del programa
 * @param char**	Vector de char* con los parametros enviados en la ejecucion
*/ 
int main (int argc, char** argv){
	//variables necesarias
	int filas, columnas,dias;
	short int zacate;
	bool feMale;
	char animal, sexo;
	int proba[filas][columnas];
	dias = atoi(argv[1]);//tomar cantidad de dias como primer argumento al correr el programa
	ifstream file(argv[2]);//lectura del archivo de texto como segundo argumento al correr el programa
	string str,temp;
	//asignaciones
	getline(file, str);
	filas = atoi(str.c_str());//.c_srt() método para convertir string a vector de caracteres
	getline(file, str);
	columnas = atoi(str.c_str());
	//inicializacion de la matriz de objetos tipo celda
	Celda** tablero = new Celda*[filas];
	
	for(int f = 0; f < filas;f++ ){
		tablero[f] = new Celda[columnas];
	}
	while (getline(file, str))//Mientras se encuentre texto al leer el archivo guardar cada linea en el string str
	{
		stringstream test(str);//construir un objeto stringstream ya que se necesita para leer de el con la funcion getline;
		getline(test, temp,'\t');//separa el stringstream cada caracter \t y fuardarlo en el string temp
		filas = atoi(temp.c_str());//atoi convierte en int el vector de caracteres retornado por .c_str()
		getline(test, temp,'\t');
		columnas = atoi(temp.c_str());
		getline(test, temp,'\t');
		zacate = atoi(temp.c_str());
		getline(test, temp,'\n');
		if(temp != "\0"){//si el string no está vacio
			animal = temp[0];//el primer caracter es el tipo de animal
			sexo = (int) temp[1];//el segundo es el sexo
			if(sexo == 49 ){//el char '1' tiene el valor entero:  49
				feMale = 1;
			}
			else{
			feMale = 0;
			}
		}	
		proba[filas][columnas] = filas + columnas;
		cout << str << endl;
		cout << filas << endl;
		cout << columnas << endl;
		cout << zacate << endl;
		cout << animal << endl;
		cout << sexo << endl;
		cout << feMale << endl;
	}
	cout << "Cantidad de dias: " << dias << endl;

	return 0;
}
