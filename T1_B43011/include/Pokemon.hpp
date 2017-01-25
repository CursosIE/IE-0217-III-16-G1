#include <iostream>
#include <string>
#ifndef POKEMON_HPP
#define POKEMON_HPP

using namespace std;

class Pokemon {

public:
	//atributos
	string name;
	string species;
	int HP;
	int ATK;
	int DEF;
	int sATK;
	int sDEF;
	int SPD;
	int EXP;
	string Type;
	string cry;
	//metodos
	virtual void atk1(Pokemon &other) = 0;//estas son funciones virtuales puras
	virtual void atk2(Pokemon &other) = 0;
	virtual void atk3(Pokemon &other) = 0;
	virtual void atk4(Pokemon &other) = 0;
	virtual string getType() = 0;
	void printInfo();
	void call();
	//constructor
	Pokemon();
	Pokemon(string n);
	//destructor
	virtual ~Pokemon();

private:

protected:

};
#endif
