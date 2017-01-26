#include "polinomios.hpp"
#include <iostream>
using namespace std;

Polinomio::Polinomio(){
}

Polinomio::Polinomio(int grado,double coeficientes[]){
	largo = grado;
	coefi = coeficientes;
	datos = new double[largo];
	for(int e = 0; e <= grado;e++)
	{
		datos[e] = coeficientes[e];
	}
}

void Polinomio::print(){
	int l = largo;
	for(int e = l-1; e >= 0;e--)
	{
		if(datos[e] != 0)
		{
		if(datos[e] > 0 && e != l-1)cout << "+ ";
			if(e == 0)
			{
				cout << datos[e];
			}else
			{
				cout<< datos[e] << "x^" << e;
			}
		}
		cout << "  ";
	}
	cout << endl;
}

Polinomio& Polinomio::operator+(Polinomio &p){//ampersand es una referencia al objeto no el de direccion
	int l1 = largo;
	int l2 = p.largo;
	double *ind;//(l1>l2 ? l1:l2)
	if(largo < l2){
		ind = p.coefi;
		for(int i = 0; i < l1; i++){
			ind[i] = coefi[i] +p.coefi[i];
		}
	}
	else{
		ind = coefi;
		for(int i = 0; i < l2; i++)
		{
			ind[i] = coefi[i] +p.coefi[i];
		}
		l2 = l1;
	}
	Polinomio* polonio = new Polinomio(l2,ind);
	return *polonio;
}

Polinomio& Polinomio::operator-(Polinomio &p){//se le resta la objeto de la izquierda con que se llama la fucion
	Polinomio* papalote;
	for(int i = 0;i < p.largo; i++){ 
		p.coefi[i] = -p.coefi[i];
	}
	papalote = &(*this+p);
	return *papalote;
}

Polinomio& Polinomio::operator*(Polinomio &p){
	double arr[largo + p.largo -1];//largo + p.largo -1 ya que el largo maximo resultante es la suma de los anteriores -1
	for(int c = 0; c < largo; c++){
		for(int b = 0; b < p.largo; b++){
			arr[c+b] = coefi[c]*p.coefi[b] + arr[c+b];//iteramos multiplicaciones de coeficientes por cada casilla de ambos vectores
		}
	}
	Polinomio* peluca = new Polinomio(largo +p.largo-1,arr);
return *peluca;
}

Polinomio& Polinomio::operator/(Polinomio &p){
	double cucumber[largo-p.largo];
	Polinomio* cociente = new Polinomio(largo-p.largo,cucumber);
	Polinomio* residuo;
	int c = largo;
	int div = p.largo;
	while(c>=p.largo)
	{
cout << "corriendo" << endl;
cout << "coefi " << coefi[c-1] << endl;
cout << "p.coefi " << p.coefi[div-1] << endl;
cout << "coefi/p.coefi " << coefi[c-1]/p.coefi[div-1] << endl;
		cociente->coefi[c-div -1] = coefi[c-1]/p.coefi[div-1];
cout << cociente->coefi[c-div-1] << endl;
		residuo = &((*cociente)*(p));
cout << "cociente" << endl;
	cociente->print();
cout << "residuo" << endl;
	residuo->print();
		(*this) = (*this)-(*residuo);
		--c;
	}		
cout << "corriendo1" << endl;
	return *cociente;
}

/*
Polinomio& Polinomio::operator/(Polinomio &p){//v2
	double coci[largo-p.largo];
	double divide[p.largo];//para restar
	int pos = largo -1;
	while(pos >= p.largo){
		coci[pos-p.largo] = coefi[pos]/p.coefi[p.largo-1];
		for(int i = 0; i<p.largo;i++){
			divide[i] = p.coefi[i]*coci[pos-p.largo];
		}
		for(int i = 0; i<p.largo;i++){
			coefi[pos-i] = coefi[pos-i] - divide[p.largo-1-i];
		}
		--pos;
	}
	Polinomio* cociente = new Polinomio(largo-p.largo, coci);
	return *cociente;
}*/

Polinomio& Polinomio::operator=(Polinomio &p){
	Polinomio* poliatomico = new Polinomio(p.largo,p.coefi);
	largo = p.largo;
	coefi = p.coefi;
	return *poliatomico;
return p;
}

Polinomio::~Polinomio() {
    delete[] datos;
}

