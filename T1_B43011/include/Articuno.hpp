#include <iostream>
#include <string>
#include "Pokemon.hpp"
#include "Ice.hpp"
#include "Flying.hpp"
#ifndef ARTICUNO_HPP
#define ARTICUNO_HPP

using namespace std;

class Articuno : virtual public Pokemon,public Ice,public Flying{

public:
	//atributos	
	 string Type;
	 string strongVs;
	 string weakVs;
	
	//metodos
	void atk1(Pokemon &other);
	void atk2(Pokemon &other);
	void atk3(Pokemon &other);
	void atk4(Pokemon &other);
	string getType();	
	void print();
	
	//constructor
	Articuno();
	Articuno(string nombre);
	//destructor
	virtual ~Articuno();
private:
protected:

};

#endif

