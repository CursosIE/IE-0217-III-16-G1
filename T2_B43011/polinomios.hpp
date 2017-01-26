#include <iostream>

using namespace std;

class Polinomio
{
	//privado
	double* datos;

	public:
		//constructor
		Polinomio();
		Polinomio(int grado, double coeficientes[] = nullptr);		

		//atributos
		int largo;
		double* coefi;

		//metodos
		void print();
		Polinomio& operator+( Polinomio &p);
		Polinomio& operator-( Polinomio &p);
		Polinomio& operator*( Polinomio &p);
		Polinomio& operator/( Polinomio &p);
		Polinomio& operator=( Polinomio &p);

		virtual ~Polinomio();
	
};
