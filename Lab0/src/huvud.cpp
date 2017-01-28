#include <iostream>//cout cin
#include <fstream>//para poder usar istream y leer el archivo
#include <cstdlib>
#include <sstream>//para poder usar getline(stringstream,string, char)
#include <cstddef>
#include "Celda.cpp"

using namespace std;

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
//	Celda** tablero = new Celda*[filas];
//	tablero = nullptr;
//	for(int f = 0; f < filas;f++ ){
//		tablero[f] = new Celda[columnas];
//	}
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
//		Celda* casilla;// creamos un puntero a Celda cada iteracion del while 
//		casilla = new Celda(filas, columnas, zacate, animal, feMale);//creamos una instancia a la que apunta el puntero
//		tablero[filas][columnas] = *casilla;//guardamos ese objeto en una casilla de la matriz
		proba[filas][columnas] = filas + columnas;
		cout << str << endl;
		cout << filas << endl;
		cout << columnas << endl;
	//	cout << zacate << endl;
	//	cout << animal << endl;
	//	cout << sexo << endl;
	//	cout << feMale << endl;	
	cout << "corre" << endl;
	}
//	casilla
	//cout << proba[1][1] << endl;
cout << "corre" << endl;//bla bla
	cout << "Cantidad de dias: " << dias << endl;
	for(int i = 0; i< 5; i++){
		for(int l = 0; l< 5; l++){
			cout << proba[i][l] << endl;
		}
	}
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
