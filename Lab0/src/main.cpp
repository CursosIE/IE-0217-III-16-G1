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
int main(int argc, char *argv[]){
	int filas, columnas, dias;
	short int zacate;
	bool genero;
	char animal, sexo;
	dias = atoi(argv[1]);
	//lectura del archivo de configuracion del juego
	ifstream file(argv[2]); 
	string str,temp;
	getline(file, str);
	filas = atoi(str.c_str());//.c_srt() método para convertir string a vector de caracteres
	getline(file, str);
	columnas = atoi(str.c_str());
	//inicializacion de la matriz de objetos tipo celda
	Celda** tablero = new Celda*[filas];
	for(int i=0; i<filas;i++ ){
		tablero[i] = new Celda[columnas];
	}
	while (getline(file, str))//Mientras se encuentre texto al leer el archivo guardar cada linea en el string str
	{
		stringstream test(str);
		//separa el stringstream cada caracter por un tab y lo guarda en temp
		getline(test, temp,'\t');
		filas = atoi(temp.c_str());
		getline(test, temp,'\t');
		columnas = atoi(temp.c_str());
		getline(test, temp,'\t');
		zacate = atoi(temp.c_str());
		getline(test, temp,'\n');
		if(temp != "\0"){
			//si existe animal
			animal = temp[0];
			sexo = (int) temp[1];
			if(sexo == 72){
				//el char 'H' tiene el valor entero:  72 que indica genero femenino (TRUE)
				genero = 1;
			}
			else{
				genero = 0;
			}
		}
		else{
			//caso en que no haya un animal en una celda
			animal='x';
			genero=0;
		}
		//Asignacion de informacion a cada celda
		Celda* nuevaCelda= new Celda(columnas, filas, zacate,  tablero, animal, sexo);
		tablero[filas][columnas]=*nuevaCelda;
		cout << filas  << "\t" <<  columnas <<  "\t" << zacate << "\t" << 
		animal << sexo << endl;
	}
	cout << "Dias que no faltan de transcurrir: " << dias << endl;
	dias--;
	return 0;
}
