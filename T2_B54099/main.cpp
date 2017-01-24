/*
 *Universidad de Costa Rica - Escuela de Ingenieria Electrica
 *Tarea 2 - IE-0217
 *@author Giancarlo Marin 
 *@date   01-19-2017
 *@brief  Clase main que prueba el funcionamiento de la sobrecarga de operadores
*/
#include "Polinomio.hpp"

int main(int argc, char **argv)
{
	//Creando polinomio P y Q: 
	int gradoP=4;
	double* datosP=new double[gradoP+1];
	datosP[0]=2;
	datosP[1]=3;
	datosP[2]=5;
	datosP[3]=0;
	datosP[4]=9;
	Polinomio* P=new Polinomio(gradoP,datosP);
	cout << "P(x)="; 
	P->poliPrint();
	int gradoQ=3;
	double* datosQ=new double [gradoQ+1];
	datosQ[0]=11;
	datosQ[1]=3;
	datosQ[2]=5;
	datosQ[3]=0;
	Polinomio* Q=new Polinomio(gradoQ,datosQ);
	cout << "Q(x)="; 
	Q->poliPrint();
	//Operaciones entre Polinomios
	cout << "----SUMA de P y Q----" << endl;
	Polinomio* suma = new Polinomio(*P+*Q);
	suma->poliPrint();
	cout << "----RESTA de P y Q----" << endl;
	Polinomio* resta = new Polinomio(*P-*Q);
	resta->poliPrint();
	cout << "----PRODUCTO de P y Q----" << endl;
	Polinomio* mult = new Polinomio((*P)*(*Q));
	mult->poliPrint();
	cout << "----DIVISION de P y Q----" << endl;
	Polinomio* div = new Polinomio((*P)/(*Q));
	div->poliPrint();
	//Eliminar memoria dinamica
	delete[] datosP;
	delete[] datosQ;
	return 0;
}
