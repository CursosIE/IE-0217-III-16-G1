/*
 *Universidad de Costa Rica - Escuela de Ingenieria Electrica
 *IE-0217 - Lab0 - Grupo01
 *@author Giancarlo Marin, @author Luis Adrian Aguilar, @author Robin Gonzalez
 *@date   01-26-2017
 *@brief  Clase main que prubea el funconamiento del juego de ecologia
*/

#include "../include/Celda.hpp"
#include "../include/print.hpp"

//Variables globales que indican las filas, columnas y tablero de juego
static int tFilas=0;
static int tColumnas=0;
static Celda** tablero=NULL;

/*
 * Metodo main que prueba el funcionamieno del juego de ecologia
 * @param int 		Cantidad de parametros obtenidos en la ejecucion del programa
 * @param char**	Vector de char* con los parametros enviados en la ejecucion
*/ 
int main(int argc, char *argv[]){
	int dias, fila, columna;
	short int zacate;
	bool genero;
	char animal, sexo;
	dias = atoi(argv[1]);
	//lectura del archivo de configuracion del juego
	ifstream file(argv[2]); 
	string str,temp;
	getline(file, str);
	tFilas = atoi(str.c_str());//.c_srt() método para convertir string a vector de caracteres
	getline(file, str);
	tColumnas = atoi(str.c_str());
	//inicializacion de la matriz de objetos tipo celda
	tablero = new Celda*[tFilas];
	for(int i=0; i<tFilas;i++){
		tablero[i] = new Celda[tColumnas];
	}
	while (getline(file, str))//Mientras se encuentre texto al leer el archivo guardar cada linea en el string str
	{
		stringstream test(str);
		//separa el stringstream cada caracter por un tab y lo guarda en temp
		getline(test, temp,'\t');
		fila = atoi(temp.c_str());
		getline(test, temp,'\t');
		columna = atoi(temp.c_str());
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
		Celda* nuevaCelda= new Celda(tColumnas, tFilas, columna, fila, zacate, tablero, animal, sexo);
		tablero[fila][columna]=*nuevaCelda;
		cout << fila  << "\t" <<  columna <<  "\t" << zacate << "\t" << 
		animal << sexo << endl;
	}
	//Ciclo del juego
	int contDias=0;
	while (dias>0){
		cout << "estoy en el while: " << dias << endl;
		contDias++;
		for (int i=0;i<tFilas;i++){
			for (int j=0;j<tColumnas;j++){
				Animal* animal=tablero[i][j].getAnimal(); //puntero al animal de la celda
				cout << "tengo al animal: " << animal->getID() << endl;
				if (animal!=NULL){ //si hay un animal
				//determinar la especie y realizar sus cuatro funciones
					if (animal->getEspecie()=="Lobo"){
						if (!animal){
							!animal; //los lobos se mueven 3 espacios al dia
							!animal;
							cout << "Los lobos se mueven" << endl;
						}
					}
					else if (animal->getEspecie()=="Oveja"){
						if (!animal){
							!animal; //las ovejas se mueven 2 espacios al dia
						}
					}
					else if(animal->getEspecie()=="Zorro"){
						if (!animal){
							!animal; //los zorros se mueven 2 espacios al dia
						}
					}
					else{
						cout << "Soy un Raton" << endl;
						!animal; //los ratones se mueven 1 espacio al dia
					}
					
				//Regla 5: La energia del animal se disminuye en 1 por dia
					animal->setEnergia(animal->getEnergia()-1);
					cout << "Tengo menos energia";
				}
			//Regla 6: El zacate aumenta en 5 su nivel cada 3 dias	
				if (contDias == 3 && tablero[i][j].getZacate()>0){ //Regla 8
					tablero[i][j].setZacate(tablero[i][j].getZacate()+5);
				//Regla 7: El nivel de Zacate no puede ser mayor a 100
					if (tablero[i][j].getZacate()>100){
						tablero[i][j].setZacate(100);
					}
				}
			}
		}
		cout << "--- RESUMEN DIA " << dias << " ---" << endl;
		for (int i=0;i<tFilas;i++){
			for (int j=0;j<tColumnas;j++){
				cout << i << "\t" << j << "\t" << tablero[i][j].getZacate() << "\t" << 
				(tablero[i][j].getAnimal())->getEspecie() << 
				(tablero[i][j].getAnimal())->getSexo() << endl;
			}
		}
		cout << "--- RESUMEN ANIMALES " << dias << " ---" << endl;
		for (int i=0;i<tFilas;i++){
			for (int j=0;j<tColumnas;j++){
				Animal* animal=tablero[i][j].getAnimal(); //puntero al animal de la celda
				if (animal!=NULL){
					printVivo(animal);
				}
			}
		}
		dias--;
	}
	return 0;
}
