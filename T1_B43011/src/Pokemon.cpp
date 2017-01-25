#include "Pokemon.hpp"

Pokemon::Pokemon()
{
}
Pokemon::Pokemon(string n)
{
	cout<<"Creando pokemon "<< n <<endl;	
	this->cry = "qwuñrkjij";
	this->species = "Zapdos";
	this->HP = 100;
	this->ATK = 30;
	this->DEF = 40;
	this->sATK = 25;
	this->sDEF = 45;
	this->SPD = 50;
	this->EXP = 300;
	this->Type = "p";
	name = n;
}

void Pokemon:: atk1(Pokemon &other){
	this->atk1(other);
}

void Pokemon:: atk2(Pokemon &other){
	this->atk2(other);
}

void Pokemon:: atk3(Pokemon &other){
	this->atk3(other);
}

void Pokemon:: atk4(Pokemon &other){
	this->atk4(other);
}

void Pokemon::call(){
	cout<< cry << endl;
}

string Pokemon:: getType(){
	return ":v";
}

void Pokemon::printInfo(){
	cout << name << "↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ "<< endl;//this muestra dir de memoria
	cout <<"Especie: " <<species <<  endl;
	cout <<"Type: "<< this->getType() << endl;
	cout <<"HP: " <<HP <<", ";
	cout <<"ATk: " <<ATK <<", ";
	cout <<"DEF: " <<DEF <<", ";
	cout <<"sATK: " <<sATK <<", ";
	cout <<"sDEF: " <<sDEF <<", ";
	cout <<"EXP: " <<EXP <<".";
	cout << endl << endl;
}

Pokemon::~Pokemon()
{
}
