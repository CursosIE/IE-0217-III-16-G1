#include "Articuno.hpp"
#include "Pokemon.hpp"
#include <cmath>   

Articuno::Articuno(string nombre){
	this->name  =  nombre;
	cout << "Ha nacido un Articuno llamado: " << this->name << endl;
	this->HP = 100;
	this->EXP = 100;
	this->Type = "Flying, Ice";
	this->strongVs = "Grass, Ice, Bug, Steel,Ground, Grass, Dragon"; //this->strongVs();
	this->weakVs = "Fire, Water, Rock, Dragon,Fire, Water, Ice, Steel" ;//this->weakVs();
}

Articuno::Articuno(){
	this->Type = "Flying, Ice";
	this->strongVs = "Grass, Ice, Bug, Steel,Ground, Grass, Dragon"; //this->strongVs();
	this->weakVs = "Fire, Water, Rock, Dragon,Fire, Water, Ice, Steel" ;//this->weakVs();
}

void Articuno::atk1(Pokemon &other){
	cout << "¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤" << endl;
	cout << this->name <<" ataca a " <<other.name << endl;
	cout << this->name <<" usa picotazo"<< endl;
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


void Articuno:: atk2(Pokemon &other){
	cout << "§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§" << endl;
	cout << this->name <<" ataca a " <<other.name << endl;
	cout << this->name <<" usa vientos alisios"<< endl;
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

void Articuno:: atk3(Pokemon &other){
	cout<< "«««««««««««««««««««««««««««««««««««««««««" <<endl;
	cout << this->name <<" ataca a " <<other.name << endl;
	cout << this->name <<" usa cubito de hielo"<< endl;
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

void Articuno:: atk4(Pokemon &other){
	cout<< "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" <<endl;
	cout << this->name <<" ataca a " <<other.name << endl;
	cout << this->name <<" usa frozen ¡la película!"<< endl;
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

string Articuno:: getType(){
	return "Flying, Ice";
}

void Articuno::print(){
	this->printInfo();
}

Articuno::~Articuno()
{
}
/*HALLAR SUBSTRINGS
if (s1.find(s2) != std::string::npos) {
    std::cout << "found!" << '\n';
}
*/

