#include <iostream>//cout cin
#include <fstream>//para poder usar istream y leer el archivo
#include <cstdlib>
#include <sstream>//para poder usar getline(stringstream,string, char)
#include <cstddef>
#include "Celda.cpp"

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
	short int zacate;
	bool feMale;
	char animal, sexo;
	Celda** tablero = new Celda*[filas];
//	tablero = nullptr;
	for(int f = 0; f < filas;f++ ){
		tablero[f] = new Celda[columnas];
	}
	while (getline(file, str))
	{
		getline(file, str);
		stringstream test(str);
		getline(test, temp,'\t');
		filas = atoi(temp.c_str());
		getline(test, temp,'\t');
		columnas = atoi(temp.c_str());
		getline(test, temp,'\t');
		zacate = atoi(temp.c_str());
		getline(test, temp,'\n');
		animal = temp[0];
		sexo = temp[1];
		if(sexo == 49 ){//el char '1' tiene el valor entero:  49
			feMale = 1;
		}
		else{
			feMale = 0;
		}
		Celda* casilla;// creamos un puntero a Celda cada iteracion del while 
		casilla = new Celda(filas, columnas, zacate, animal, feMale);//creamos una instancia a la que apunta el puntero
		tablero[filas][columnas] = *casilla;//guardamos ese objeto en una casilla de la matriz
		cout << str << endl;
		cout << filas << endl;
		cout << columnas << endl;
		cout << zacate << endl;
		cout << animal << endl;
		cout << sexo << endl;
		cout << feMale << endl;	
	}
//	casilla
	cout << "Cantidad de dias: " << dias << endl;
	/*cout << "Cantidad de dias: " << dias << endl;
	cout << "Cantidad de dias: " << dias << endl;
	cout << "Cantidad de dias: " << dias << endl;
	cout << "Cantidad de dias: " << dias << endl;
	cout << "Cantidad de dias: " << dias << endl;
	cout << "Cantidad de dias: " << dias << endl;
	cout << "funca " z< endl;*/
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
