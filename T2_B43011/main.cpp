#include "polinomios.hpp"

int main () {
	Polinomio* p;
	double c[] = {1,99,-3,5,-8,1};
	p = new Polinomio(6,c);
cout << "p: " << endl;
	p->print();

	double cosi[] = {1,0,-3,5,-8,1,3,3,3};
	Polinomio* poli;
	poli = new Polinomio(9,cosi);
	Polinomio* polaaa;
	polaaa = poli;
cout << "polaaa:" << endl;
	polaaa->print();

cout << "poli: " << endl;
	poli->print();
	Polinomio* fuuu;
	fuuu = &(*p+*poli);
cout << "fuuu: " << endl;
	fuuu->print();

cout << "b = z = d = p: " << endl;
	Polinomio* a;
	Polinomio* b;
	Polinomio* z;
	Polinomio* d;
	b = z = d = p;

	b->print();
	z->print();
	d->print();
	p->print();
cout << "a: " << endl;
	a->print();
cout << "resto: fuuu - a:  " << endl;
	a = &(*fuuu-*p);

	double arr[] = {6, 1};
	Polinomio *pepe = new Polinomio(2,arr);
	double tri[] = {2 ,1 ,7};
	Polinomio *pipa = new Polinomio(3,tri);
	Polinomio* mul;
	
	mul = &((*pepe)*(*pipa));

cout << "pepe" << endl;
	pepe->print(); 
cout << "pipa" << endl;
	pipa->print();

cout << mul->largo << endl;	
cout << "multiplicacion: de pepe * pipa: " << endl;
	mul->print();
cout << "division: pepe/pip: " << endl;
	double arrr[] = {1,-7,4,0,1,6};
	Polinomio *pep = new Polinomio(6,arrr);
	double trir[] = {-3,1,2};
	Polinomio *pip = new Polinomio(3,trir);
	Polinomio* div;
	div = &((*pep)/(*pip));

	cout << "pep" << endl;
	pep->print(); 
	cout << "pip" << endl;
	pip->print();
	cout << pep->coefi[5] << endl;
	cout << pip->coefi[2] << endl;
	cout << pep->coefi[5]/pip->coefi[2] << endl;
	cout << "divi" << endl;
	div->print();
//  delete[] p;
	
	delete p;
	delete poli;
	delete pipa;
	delete pepe;
	delete pep;
	delete pip;
	return 0;
}
