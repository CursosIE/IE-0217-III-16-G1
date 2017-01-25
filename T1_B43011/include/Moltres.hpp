#include <iostream>
#include <string>
#include "Pokemon.hpp"
#include "Fire.hpp"
#include "Flying.hpp"
#ifndef MOLTRES_HPP
#define MOLTRES_HPP

using namespace std;

class Moltres : virtual public Pokemon,public Fire,public Flying{

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
	Moltres();
	Moltres(string nombre);
	//destructor
	virtual ~Moltres();
private:
protected:

};

#endif

/*HALLAR SUBSTRINGS
if (s1.find(s2) != std::string::npos) {
    std::cout << "found!" << '\n';
}
*/


