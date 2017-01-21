/*
 *@author Giancarlo Marin 
 *@date   01-20-2017
 *@brief  Archivo de definicion de encabezados  de las diferentes clases
 *Contiene la definicion de metodos y atributos de las clases:
 * 1) Pokemon 2) Electric 3) Fire 4) Ice 5) Flying 6) Zapdos 7) Articuno 8) Moltress
*/
#ifndef POKEMON_H	
#define POKEMON_H
#include <iostream>
#include <sstream>
#include <cstdlib>

using namespace std;

/*
 *Definicion de clase Pokemon 
*/
class Pokemon{
public:	
	//Atributos
	string name, specie, cry;
	int HP, Atk, Def, SAtk, SDef, exp;
	
	//Metodos
	Pokemon();
	virtual ~Pokemon();
	virtual void attack1(Pokemon &other)=0;
	virtual void attack2(Pokemon &other)=0;
	virtual void attack3(Pokemon &other)=0;
	virtual void attack4(Pokemon &other)=0;
	string getCry();
	string info();
	void infoPelea();
	void checkDef();
	void checkHP();
	void checkSDef();
	void checkSAtk();
};

/*
 *Definicion de clase Electric
*/
class Electric : virtual public Pokemon{
public:
	//Metodos
	Electric();
	~Electric();	
	static string type();
	static string strongVs();
	static string weakVs();
};

/*
 *Definicion de clase Fire
*/
class Fire : virtual public Pokemon{
public:
	//Metodos
	Fire();
	~Fire();	
	static string type();
	static string strongVs();
	static string weakVs();
};

/*
 *Definicion de clase Ice
*/
class Ice : virtual public Pokemon{
public:
	//Metodos
	Ice();
	~Ice();	
	static string type();
	static string strongVs();
	static string weakVs();
};

/*
 *Definicion de clase Flying
*/
class Flying : virtual public Pokemon{
public:
	//Metodos
	Flying();
	~Flying();	
	static string type();
	static string strongVs();
	static string weakVs();
};

/*
 *Definicion de clase Zapdos
*/
class Zapdos : public Electric, Flying{
public:	
	//atributos
	string type;
	string strongVs;
	string weakVs;
	//metodos
	Zapdos(string name);
	~Zapdos();
	virtual void attack1(Pokemon &other);
	virtual void attack2(Pokemon &other);
	virtual void attack3(Pokemon &other);
	virtual void attack4(Pokemon &other);
	void infoZapdos();
	string getType();
	string getStrongVs();
	string getWeakVs();
};

/*
 *Definicion de clase Articuno
*/
class Articuno : public Ice, Flying{
public:	
	//atributos
	string type;
	string strongVs;
	string weakVs;
	//metodos
	Articuno(string name);
	~Articuno();
	virtual void attack1(Pokemon &other);
	virtual void attack2(Pokemon &other);
	virtual void attack3(Pokemon &other);
	virtual void attack4(Pokemon &other);
	void infoArticuno();
	string getType();
	string getStrongVs();
	string getWeakVs();
};

/*
 *Definicion de clase Moltress
*/
class Moltres : public Electric, Flying{
public:	
	//atributos
	string type;
	string strongVs;
	string weakVs;
	//metodos
	Moltres(string name);
	~Moltres();
	virtual void attack1(Pokemon &other);
	virtual void attack2(Pokemon &other);
	virtual void attack3(Pokemon &other);
	virtual void attack4(Pokemon &other);
	void infoMoltres();
	string getType();
	string getStrongVs();
	string getWeakVs();
};


#endif /* POKEMON_HPP */