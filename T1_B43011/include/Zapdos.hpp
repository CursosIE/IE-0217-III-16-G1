#include <iostream>
#include <string>
#include "Pokemon.hpp"
//#include "Articuno.hpp"
//#include "Moltres.hpp"
#include "Electric.hpp"
#include "Flying.hpp"
#ifndef ZAPDOS_HPP
#define ZAPDOS_HPP

using namespace std;

class Zapdos : virtual public Pokemon,public Electric,public Flying{

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
/*	void atk1(Articuno &other);
	void atk2(Articuno &other);
	void atk3(Articuno &other);
	void atk4(Articuno &other);
	void atk1(Moltres &other);
	void atk2(Moltres &other);
	void atk3(Moltres &other);
	void atk4(Moltres &other);*/
	void print();
	string getType();
	//constructor
	Zapdos();
	Zapdos(string nombre);
	//destructor
	virtual ~Zapdos();
private:
protected:

};

#endif

/*HALLAR SUBSTRINGS
if (s1.find(s2) != std::string::npos) {
    std::cout << "found!" << '\n';
}
*/


