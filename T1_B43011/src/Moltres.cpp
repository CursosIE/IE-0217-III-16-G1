#include "Moltres.hpp"
#include "Pokemon.hpp"
#include <cmath>  

Moltres::Moltres(string nombre){
	this->name  =  nombre;
	cout << "Ha nacido un Moltres llamado: " << this->name << endl;
	this->HP = 100;
	this->EXP = 100;
	this->Type = "Flying, Fire";
	this->strongVs = "Grass, Ice, Bug, Steel, Grass, Ice, Bug, Steel";
	this->weakVs = "Fire, Water, Rock, Dragon, Fire, Water, Rock, Dragon";
}

Moltres::Moltres(){
	this->Type = "Flying, Fire";
	this->strongVs = "Grass, Ice, Bug, Steel, Grass, Ice, Bug, Steel";
	this->weakVs = "Fire, Water, Rock, Dragon, Fire, Water, Rock, Dragon";
}

void Moltres::atk1(Pokemon &other){
	cout << "¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤" << endl;
	cout << this->name <<" ataca a " <<other.name << endl;
	cout << this->name <<" usa aruñazo"<< endl;
	float powa = 1;
	float ataque = this->ATK;
	if (this->strongVs.find(other.getType())) {//busca tipo de pokemon para ver 	efectividad de ataque
	   // std::cout << "found!" << '\n';
		powa = 2;
	cout << "Es muy efectivo" << endl;
	}else{
		if (this->weakVs.find(other.getType())) {
			// std::cout << "found!" << '\n';
			powa = 0.5;
			cout << "No es muy efectivo" << endl;
		}
	}
	ataque = ataque - other.EXP/50 +this->EXP/50;
	ataque = ataque*powa;
	other.HP = other.HP - ataque;
	this->EXP = this->EXP + ataque/(abs(other.HP)/10);
	cout << "¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤" << endl << endl;
}

void Moltres:: atk2(Pokemon &other){
	cout << "§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§" << endl;
	cout << this->name <<" ataca a " <<other.name << endl;
	cout << this->name <<" usa horno"<< endl;
	float powa = 1;
	float ataque = this->ATK;
	if (this->strongVs.find(other.getType())) {//busca tipo de pokemon para ver 	efectividad de ataque
	   // std::cout << "found!" << '\n';
		powa = 2;
	cout << "Es muy efectivo" << endl;
	}else{
	
		if (this->weakVs.find(other.getType())) {
		   // std::cout << "found!" << '\n';
			powa = 0.5;
		cout << "No es muy efectivo" << endl;
		}
	}
	ataque = ataque - other.EXP/50 +this->EXP/50;
	ataque = ataque*powa;
	other.HP = other.HP - ataque;
	this->EXP = this->EXP + ataque/(abs(other.HP)/10);
	cout << "§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§" << endl << endl;
}

void Moltres:: atk3(Pokemon &other){
	cout<< "«««««««««««««««««««««««««««««««««««««««««" <<endl;
	cout << this->name <<" ataca a " <<other.name << endl;
	cout << this->name <<" usa quemazón"<< endl;
	float powa = 1;
	float ataque = this->ATK;
	if (this->strongVs.find(other.getType())) {//busca tipo de pokemon para ver 	efectividad de ataque
	   // std::cout << "found!" << '\n';
		powa = 2;
	cout << "Es muy efectivo" << endl;
	}else{
	
		if (this->weakVs.find(other.getType())) {
		   // std::cout << "found!" << '\n';
			powa = 0.5;
		cout << "No es muy efectivo" << endl;
		}
	}
	ataque = ataque - other.EXP/50 +this->EXP/50;
	ataque = ataque*powa;
	other.HP = other.HP - ataque;
	this->EXP = this->EXP + ataque/(abs(other.HP)/10);
	cout << "«««««««««««««««««««««««««««««««««««««««««" << endl << endl;
}

void Moltres:: atk4(Pokemon &other){
	cout<< "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" <<endl;
	cout << this->name <<" ataca a " <<other.name << endl;
	cout << this->name <<" usa tornado de fuego"<< endl;
	float powa = 1;
	float ataque = this->sATK;
	if (this->strongVs.find(other.getType())) {//busca tipo de pokemon para ver 	efectividad de ataque
	   // std::cout << "found!" << '\n';
		powa = 2;
	cout << "Es muy efectivo" << endl;
	}else{
	
		if (this->weakVs.find(other.getType())) {
		   // std::cout << "found!" << '\n';
			powa = 0.5;
		cout << "No es muy efectivo" << endl;
		}
	}
	ataque = ataque - other.EXP/50 +this->EXP/50;
	ataque = ataque*powa;
	other.HP = other.HP - ataque;
	this->EXP = this->EXP + ataque/(abs(other.HP)/10);
	cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl << endl;
}

string Moltres:: getType(){
	return "Flying, Fire";
}

void Moltres::print(){
	this->printInfo();
}


Moltres::~Moltres()
{
}
/*HALLAR SUBSTRINGS
if (s1.find(s2) != std::string::npos) {
    std::cout << "found!" << '\n';
}
*/

