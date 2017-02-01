/*
 *Universidad de Costa Rica - Escuela de Ingenieria Electrica
 *IE-0217 - Lab0 - Grupo01
 *@author Giancarlo Marin, @author Luis Adrian Aguilar, @author Robin Gonzalez
 *@date   01-26-2017
 *@brief  Clase main que prubea el funconamiento del juego de ecologia
*/

#include "../include/Celda.hpp"
#include "../include/print.hpp"

/*
 * Metodo main que prueba el funcionamieno del juego de ecologia
 * @param int 		Cantidad de parametros obtenidos en la ejecucion del programa
 * @param char**	Vector de char* con los parametros enviados en la ejecucion
*/ 
int main(int argc, char *argv[]){
	int dias, fila, columna;
	short int zacate;
	char animal, sexo;
	dias = atoi(argv[1]);
	//lectura del archivo de configuracion del juego
	ifstream file(argv[2]); 
	string str,temp;
	getline(file, str);
	int tFilas = atoi(str.c_str());//.c_srt() método para convertir string a vector de caracteres
	getline(file, str);
	int tColumnas = atoi(str.c_str());
	//inicializacion de la matriz de objetos tipo celda
	Celda** tablero = new Celda*[tFilas];
	for(int i=0; i<tFilas;i++){
		tablero[i] = new Celda[tColumnas];
	}
	cout << "----ESTADO INICIAL----" << endl;
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
			sexo = temp[1];
			cout << fila << "\t" << columna << "\t" << zacate << "\t" <<
				animal << sexo << endl;
		}
		else{
			//caso en que no haya un animal en una celda
			animal = 'x'; //setea un valor x para que el constructor de Celda determine que no hay animal
			cout << fila << "\t" << columna << "\t" << zacate << endl;
		}
		//Asignacion de informacion a cada celda
		Celda* nuevaCelda= new Celda(tColumnas, tFilas, columna, fila, zacate, tablero, animal, sexo);
		tablero[fila][columna]=*nuevaCelda;
		
	}
	//Ciclo del juego
	int contDias=0;
	while (dias > 0){
		contDias++;
		for (int i=0;i<tFilas;i++){
			for (int j=0;j<tColumnas;j++){
				Animal* animal=tablero[i][j].getAnimal(); //puntero al animal de la celda|
				if (animal!=NULL && !(animal->actueHoy)){ //si hay un animal y no ha actuado hoy
				//determinar la especie y realizar sus cuatro funciones (Moverse, Comer, Reproducirse, Morir)
					if (animal->getEspecie()=="Lobo"){
						if (!(*animal)){
							!(*animal); 
							!(*animal);//los lobos se mueven 3 espacios al dia
						}
						animal=++(*animal);
					}
					else if (animal->getEspecie()=="Oveja"){
						if (!(*animal)){
							!(*animal); //las ovejas se mueven 2 espacios al dia
						}
						animal=++(*animal);
					}
					else if(animal->getEspecie()=="Zorro"){
						if (!(*animal)){
							!(*animal); //los zorros se mueven 2 espacios al dia
						}
						animal=++(*animal);
					}
					else{
						!(*animal); //los ratones se mueven 1 espacio al dia
						animal=++(*animal);
					}
					
				//Regla 5: La energia del animal se disminuye en 1 por dia
					animal->setEnergia(animal->getEnergia()-1);
					animal->actueHoy = true; //Setea el atributo de actuar
				}
			//Regla 6: El zacate aumenta en 5 su nivel cada 3 dias	
				if (contDias%3==0 && tablero[i][j].getZacate()>0){ //Regla 8
					tablero[i][j].setZacate(tablero[i][j].getZacate()+5);
				//Regla 7: El nivel de Zacate no puede ser mayor a 100
					if (tablero[i][j].getZacate()>100){
						tablero[i][j].setZacate(100);
					}
				}
			}
		}
		cout << "--- RESUMEN DIA " << contDias << " ---" << endl;
		for (int i=0;i<tFilas;i++){
			for (int j=0;j<tColumnas;j++){
				if (tablero[i][j].getAnimal() != NULL){
					cout << i << "\t" << j << "\t" << tablero[i][j].getZacate() << "\t" <<
						(tablero[i][j].getAnimal())->getEspecie()[0] <<
						(tablero[i][j].getAnimal())->getSexo() << endl;
				}
				else{
					cout << i << "\t" << j << "\t" << tablero[i][j].getZacate() << "\t" << endl;
				}
			}
		}
		cout << "--- RESUMEN ESTADO ANIMALES " << contDias << " ---" << endl;
		for (int i=0;i<tFilas;i++){
			for (int j=0;j<tColumnas;j++){
				Animal* animal=tablero[i][j].getAnimal(); //puntero al animal de la celda
				if (animal!=NULL){
					printVivo(animal); //llamado a template de impresion de animales
					animal->actueHoy = false; //setea la accion para el siguiente dia
				}
			}
		}
		dias--;
	}
	//Liberacion de memoria
	cout << "LIBERANDO MEMORIA..." << endl;
	for (int i = 0; i<tFilas; i++){
		for (int j = 0; j < tColumnas; j++){
			tablero[i][j].~Celda();
		}
	}
	delete tablero;
	cout << "----FINAL----" << endl;
	return 0;
}
