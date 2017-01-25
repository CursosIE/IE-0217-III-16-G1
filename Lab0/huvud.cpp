#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstddef>
#include <string>

//#include "celda.hpp"

using namespace std;

int main (int argc, char** argv){
	int filas, columnas,dias;
	dias = atoi(argv[1]);
	ifstream file(argv[2]);
	string str,temp;
	getline(file, str);
	filas = atoi(str.c_str());//.c_srt() método para convertir string a vector de caracteres
	getline(file, str);
	columnas = atoi(str.c_str());
	int tablero[filas][columnas];
	short int zacate;
	bool feMale;
	char animal, sexo;
//	Celda** tablero;
//	tablero = nullptr;
	while (getline(file, str))
	{
		getline(str, temp,'\t');
		filas = atoi(temp.c_str());
	//	getline(str, temp,'\t');
		columnas = atoi(temp.c_str());
	//	getline(str, temp,'\t');
		zacate = atoi(temp.c_str());
	//	getline(str, temp,'\n');
		/*Celda.animal = temp[0];
		Celda.sexo = temp[1];
		Celda* c;
		c = new Celda;
		c.zacate = zacate;
		tablero[filas][columnas] = celda;*/
		animal = temp[0];
		sexo = temp[1];
		if(sexo == 49 ){//el char '1' tiene el valor entero:  49
		feMale = 1;
		}
		else{
		feMale = 0;
		}
		cout << filas << endl;
		cout << columnas << endl;
		cout << animal << endl;
		cout << sexo << endl;
		cout << str << endl;
	
	}
	cout << "Cantidad de dias: " << dias << endl;
	cout << "Cantidad de dias: " << dias << endl;
	cout << "Cantidad de dias: " << dias << endl;
	cout << "Cantidad de dias: " << dias << endl;
	cout << "Cantidad de dias: " << dias << endl;
	cout << "Cantidad de dias: " << dias << endl;
	cout << "Cantidad de dias: " << dias << endl;
	cout << "funca " << dias << endl;
	return 0;
}

/*
std::stringstream test("this_is_a_test_string");
std::string segment;
std::vector<std::string> seglist;

while(std::getline(test, segment, '_'))
{
   seglist.push_back(segment);
}*/
