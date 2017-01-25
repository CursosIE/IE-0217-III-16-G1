#include "Zapdos.hpp"
#include "Pokemon.hpp"
#include <cmath>   

Zapdos::Zapdos(string nombre){
	this->name  =  nombre;
	cout << "Ha nacido un Zapdos llamado: " << this->name << endl;
	this->HP = 100;
	this->EXP = 100;
	this->Type = "Flying, Electric";
	this->strongVs = "Water, Grass, Ice, Bug, Steel";// strongVs();
	this->weakVs = "Electric, Grass, Dragon, Fire, Water, Rock, Dragon";//weakVs();
}

Zapdos::Zapdos(){
	this->Type = "Flying, Electric";
	this->strongVs = "Water, Grass, Ice, Bug, Steel";// strongVs();
	this->weakVs = "Electric, Grass, Fire, Water, Rock, Dragon";//weakVs();
}

void Zapdos::atk1(Pokemon &other){
	cout << "¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤" << endl;
	cout << this->name <<" ataca a " <<other.name << endl;
	cout << this->name <<" usa cuadernazo"<< endl;
	float powa = 1;
	float ataque = this->ATK;
	if (this->strongVs.find(other.getType()) != std::string::npos) {//busca tipo de pokemon para ver 	efectividad de ataque
	   // std::cout << "found!" << '\n';
		powa = 2;
	cout << "Es muy efectivo" << endl;
	}else{
	
		if (this->weakVs.find(other.getType()) != std::string::npos) {
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

void Zapdos:: atk2(Pokemon &other){
	cout << "§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§" << endl;
	cout << this->name <<" ataca a " <<other.name << endl;
	cout << this->name <<" usa descarga de capacitor"<< endl;
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

void Zapdos:: atk3(Pokemon &other){
	cout<< "«««««««««««««««««««««««««««««««««««««««««" <<endl;
	cout << this->name <<" ataca a " <<other.name << endl;
	cout << this->name <<" usa apagón"<< endl;
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

void Zapdos:: atk4(Pokemon &other){
	cout<< "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" <<endl;
	cout << this->name <<" ataca a " <<other.name << endl;
	cout << this->name <<" usa trueno"<< endl;
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

string Zapdos:: getType(){
return "Flying, Electric";
}

void Zapdos::print(){
	this->printInfo();
}

Zapdos::~Zapdos()
{
}

/*HALLAR SUBSTRINGS
if (s1.find(s2) != std::string::npos) {
    std::cout << "found!" << '\n';
}
*/

