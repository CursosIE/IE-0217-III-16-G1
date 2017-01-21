/*
 *@author Giancarlo Marin 
 *@date   01-20-2017
 *@brief  Archivo de implementacion de metodos de las diferentes clases
 *Contiene la implementacion de los constructores y metodos de las clases:
 * 1) Pokemon 2) Electric 3) Fire 4) Ice 5) Flying 6) Zapdos 7) Articuno 8) Moltress
*/
#include "pokemon.hpp"

/*
 *Metodo constructor por defecto de Pokemon 
*/
Pokemon::Pokemon(){
	cout << "Creando Pokemon" << endl;
	this->name="";
	this->specie="";
	this->cry="";
	this->HP=0;
	this->Atk=0;
	this->Def=0;
	this->SAtk=0;
	this->SDef=0;
	this->exp=0;
}

/*
 *Metodo destructor de la clase Pokemon 
*/
Pokemon::~Pokemon(){
}

/*
 *Metodo que retorna la informacion basica de un pokemon
 *@return string (Formato "<name>:<specie>	exp:<val>" 
*/
string Pokemon::info(){
	//cast de int a string por medio de la libreria sstream
	string exp;
	ostringstream temp;
	temp<<(this->exp);
	exp=temp.str(); 
	return this->name + ":" + this->specie + "\texp: " + exp;
}

/*
 *Metodo que retorna la informacion en una pelea de un pokemon
 *@return string (Formato "<name>:<specie> HP:<HP> SATK:<STAK> SDEF:<SDEF>" 
*/
void Pokemon::infoPelea(){
	cout << this->name << ":" << this->specie << " HP: " << this->HP <<
	" SATK:" << this->SAtk << " SDEF:" << this->SDef << endl;
}

/*
 *Metodo que retorna el canto del pokemon
 *@return string Canto 
*/
string Pokemon::getCry(){
	return this->cry;
}

/*
 *Metodo que chequea si los puntos de defensa DEF son menores que 0 y en 
 * dado caso los setea a 0
*/
void Pokemon::checkDef(){
	if (this->Def<0){
		this->Def=0;
	}
	else if(this->Def>100){
		this->Def=100;
	}
}

/*
 *Metodo que chequea si los puntos de SDef son menores que 0 o mayores a 100 
 * y en dado caso los setea a 0 o 100
*/
void Pokemon::checkSDef(){
	if (this->SDef<0){
		this->SDef=0;
	}
	else if(this->SDef>100){
		this->SDef=100;
	}
}

/*
 *Metodo que chequea si los puntos de defensa SATK son menores que 0 o 
 * mayores a 100 y en dado caso los setea a 0 o 100
*/
void Pokemon::checkSAtk(){
	if (this->SAtk<0){
		this->SAtk=0;
	}
	else if(this->SAtk>100){
		this->SAtk=100;
	}
}

/*
 *Metodo que chequea si los puntos de pelea HP son menores que 0 y en 
 * dado caso los setea a 0
*/
void Pokemon::checkHP(){
	if (this->HP<0){
		this->HP=0;
	}
	else if(this->HP>100){
		this->HP=100;
	}
}

/*
 *Constructor por defecto de la clase Pokemon 
*/
Electric::Electric(){
}

/*
 *Metodo destructor de la clase Electric
*/
Electric::~Electric(){
}

/*
 *Metodo que retorna el tipo Electric
 * @return string "Electric"
*/
string Electric::type(){
	return "Electric";
}

/*
 *Metodo que retorna los tipos que Electric es mas fuerte versus 
 * @return string 
*/
string Electric::strongVs(){
	return "Water & Flying";
}

/*
 *Metodo que retorna los tipos que Electric es mas debil versus 
 * @return string 
*/
string Electric::weakVs(){
	return "Rock";
}

/*
 *Constructor por defecto de la clase Fire
*/
Fire::Fire(){
}

/*
 *Metodo destructor de la clase Fire
*/
Fire::~Fire(){
}

/*
 *Metodo que retorna el tipo Fire
 * @return string "Fire"
*/
string Fire::type(){
	return "Fire";
}

/*
 *Metodo que retorna los tipos que Fire es mas fuerte versus 
 * @return string 
*/
string Fire::strongVs(){
	return "Flying, Normal & Plant";
}

/*
 *Metodo que retorna los tipos que Fire es mas debil versus 
 * @return string 
*/
string Fire::weakVs(){
	return "Rock, Water & Ice";
}

/*
 *Constructor por defecto de la clase Fire
*/
Ice::Ice(){
}

/*
 *Metodo destructor de la clase Ice
*/
Ice::~Ice(){
}

/*
 *Metodo que retorna el tipo Ice
 * @return string "Ice"
*/
string Ice::type(){
	return "Ice";
}

/*
 *Metodo que retorna los tipos que Ice es mas fuerte versus 
 * @return string 
*/
string Ice::strongVs(){
	return "Flying, Grass, Ground & Dragon";
}

/*
 *Metodo que retorna los tipos que Ice es mas debil versus 
 * @return string 
*/
string Ice::weakVs(){
	return "Fire, Fight, Rock & Steal";
}

/*
 *Constructor por defecto de la clase Flying
*/
Flying::Flying(){
}

/*
 *Metodo destructor de la clase Flying
*/
Flying::~Flying(){
}

/*
 *Metodo que retorna el tipo Ice
 * @return string "Flying"
*/
string Flying::type(){
	return "Flying";
}

/*
 *Metodo que retorna los tipos que Flying es mas fuerte versus 
 * @return string 
*/
string Flying::strongVs(){
	return "Grass & Fight";
}

/*
 *Metodo que retorna los tipos que Flying es mas debil versus 
 * @return string 
*/
string Flying::weakVs(){
	return "Electric, Rock & Ice";
}

/*
 *Metodo constructor sobrecargado de Pokemon que genera un Zapdos con sus caracteristicas 
 * @param string newName 	(Indica el nombre que llevara el pokemon) e.g Juan
*/
Zapdos::Zapdos(string newName){
	cout << "Creando un Zapdos" << endl;
	this->name=newName;
	this->specie="Zapdos";
	this->cry="zapppp";
	this->type=Electric::type() + ", " + Flying::type();
	this->strongVs=Electric::strongVs() + ", " + Flying::strongVs();
	this->weakVs=Electric::weakVs() + ", " + Flying::weakVs();
	//valores pseudoaleatorios entre 1-100
	this->HP=1+rand() %100;
	this->Atk=1+rand() %100;
	this->Def=1+rand() %100;
	this->SAtk=1+rand() %100;
	this->SDef=1+rand() %100;
	this->exp=1+rand() %100;
}

/*
 *Metodo destructor de la clase Zapdos
*/
Zapdos::~Zapdos(){
	cout << "Eliminando un Zapdos" << endl;
}

void Zapdos::attack1(Pokemon &other){
	cout << this->name << ": " << "impactrueno a " << other.name << endl;
	cout << this->getCry() << endl;
	other.Def-=10;
	other.HP-=1;
	other.checkDef();
	other.checkHP();
}

void Zapdos::attack2(Pokemon &other){
	cout << this->name << ": " << "Onda Trueno a " << other.name << endl;
	cout << this->getCry() << endl;
	other.Def-=20;
	other.HP-=1;
	other.checkDef();
	other.checkHP();
}

void Zapdos::attack3(Pokemon &other){
	cout << this->name << ": " << "Pico Taladro a " << other.name << endl;
	cout << this->getCry() << endl;
	other.Def-=20;
	other.HP-=1;
	other.checkDef();
	other.checkHP();
}

void Zapdos::attack4(Pokemon &other){
	cout << this->name << ": " << "Respiro" << endl;
	cout << this->getCry() << endl;
	this->SDef+=10;
	this->SAtk+=5;
	other.checkSDef();
	other.checkSAtk();
}

/*
 *Metodo que retorna el tipo de Zapdos 
 * @return string 
*/
string Zapdos::getType(){
	return this->type;
}

/*
 *Metodo que retorna los tipos que Zapdos es fuerte versus 
 * @return string 
*/
string Zapdos::getStrongVs(){
	return this->strongVs;
}

/*
 *Metodo que retorna los tipos que Zapdos es debil versus 
 * @return string 
*/
string Zapdos::getWeakVs(){
	return this->weakVs;
}

/*
 *Metodo que retorna la informacion de Zapdos
 *@return string (Formato "<name>:<specie>	exp:<val>	Tipo:<type>"	 FuerteVs:<strongVs>	DebilVs:<weakVs>"
*/
void Zapdos::infoZapdos(){	
	cout << this->info() << "\tTipo:" << this->getType() <<
 "\tFuerteVs: " << this->getStrongVs() << "\tDebilVs: " <<
 this->getWeakVs() << endl; 
}

/*
 *Metodo constructor sobrecargado de Pokemon que genera un Articuno con sus caracteristicas 
 * @param string newName 	(Indica el nombre que llevara el pokemon) e.g Juan
*/
Articuno::Articuno(string newName){
	cout << "Creando un Articuno" << endl;
	this->name=newName;
	this->specie="Articuno";
	this->cry="ttt urhhh aghh";
	this->type=Ice::type() + ", " + Flying::type();
	this->strongVs=Ice::strongVs() + ", " + Flying::strongVs();
	this->weakVs=Ice::weakVs() + ", " + Flying::weakVs();
	//valores pseudoaleatorios entre 1-100
	this->HP=1+rand() %100;
	this->Atk=1+rand() %100;
	this->Def=1+rand() %100;
	this->SAtk=1+rand() %100;
	this->SDef=1+rand() %100;
	this->exp=1+rand() %100;
}

/*
 *Metodo destructor de la clase Articuno
*/
Articuno::~Articuno(){
	cout << "Eliminando un Articuno" << endl;
}

void Articuno::attack1(Pokemon &other){
	cout << this->name << ": " << "Canto helado a " << other.name << endl;
	cout << this->getCry() << endl;
	other.Def-=25;
	other.HP-=5;
	other.SDef-=10;
	other.SAtk-=10;
	other.checkDef();
	other.checkHP();
	other.checkSAtk();
	other.checkSDef();
}

void Articuno::attack2(Pokemon &other){
	cout << this->name << ": " << "Vendaval a " << other.name << endl;
	cout << this->getCry() << endl;
	other.Def-=20;
	other.HP-=10;
	other.SDef-=5;
	other.SAtk-=5;
	other.checkDef();
	other.checkHP();
	other.checkSAtk();
	other.checkSDef();
}

void Articuno::attack3(Pokemon &other){
	cout << this->name << ": " << "Granizo a " << other.name << endl;
	cout << this->getCry() << endl;
	other.Def-=15;
	other.HP-=3;
	other.SDef-=5;
	other.SAtk-=5;
	other.checkDef();
	other.checkHP();
	other.checkSAtk();
	other.checkSDef();
}

void Articuno::attack4(Pokemon &other){
	cout << this->name << ": " << "Respiro" << endl;
	cout << this->getCry() << endl;
	this->SDef+=10;
	this->SAtk+=5;
	other.checkSDef();
	other.checkSAtk();
}

/*
 *Metodo que retorna el tipo de Articuno 
 * @return string 
*/
string Articuno::getType(){
	return this->type;
}

/*
 *Metodo que retorna los tipos que Articuno es fuerte versus 
 * @return string 
*/
string Articuno::getStrongVs(){
	return this->strongVs;
}

/*
 *Metodo que retorna los tipos que Articuno es debil versus 
 * @return string 
*/
string Articuno::getWeakVs(){
	return this->weakVs;
}

/*
 *Metodo que retorna la informacion de Articuno
 *@return string (Formato "<name>:<specie>	exp:<val>	Tipo:<type>"	 FuerteVs:<strongVs>	DebilVs:<weakVs>"
*/
void Articuno::infoArticuno(){	
	cout << this->info() << "\tTipo:" << this->getType() <<
 "\tFuerteVs: " << this->getStrongVs() << "\tDebilVs: " <<
 this->getWeakVs() << endl; 
}

/*
 *Metodo constructor sobrecargado de Pokemon que genera un Moltres con sus caracteristicas 
 * @param string newName 	(Indica el nombre que llevara el pokemon) e.g Juan
*/
Moltres::Moltres(string newName){
	cout << "Creando un Moltres" << endl;
	this->name=newName;
	this->specie="Moltres";
	this->cry="tttrggg iahhh";
	this->type=Ice::type() + ", " + Flying::type();
	this->strongVs=Ice::strongVs() + ", " + Flying::strongVs();
	this->weakVs=Ice::weakVs() + ", " + Flying::weakVs();
	//valores pseudoaleatorios entre 1-100
	this->HP=1+rand() %100;
	this->Atk=1+rand() %100;
	this->Def=1+rand() %100;
	this->SAtk=1+rand() %100;
	this->SDef=1+rand() %100;
	this->exp=1+rand() %100;
}

/*
 *Metodo destructor de la clase Moltres
*/
Moltres::~Moltres(){
	cout << "Eliminando un Moltres" << endl;
}

void Moltres::attack1(Pokemon &other){
	cout << this->name << ": " << "Lanza llamas a " << other.name << endl;
	cout << this->getCry() << endl;
	other.Def-=30;
	other.HP-=5;
	other.SDef-=20;
	other.checkDef();
	other.checkHP();
	other.checkSDef();
}

void Moltres::attack2(Pokemon &other){
	cout << this->name << ": " << "Dia Soleado a " << other.name << endl;
	cout << this->getCry() << endl;
	other.Def-=10;
	other.HP-=5;
	other.SDef-=15;
	other.SAtk-=15;
	other.checkDef();
	other.checkHP();
	other.checkSAtk();
	other.checkSDef();
}

void Moltres::attack3(Pokemon &other){
	cout << this->name << ": " << "Tajo Aereo a " << other.name << endl;
	cout << this->getCry() << endl;
	other.Def-=15;
	other.HP-=1;
	other.SDef-=5;
	other.SAtk-=5;
	other.checkDef();
	other.checkHP();
	other.checkSAtk();
	other.checkSDef();
}

void Moltres::attack4(Pokemon &other){
	cout << this->name << ": " << "Respiro" << endl;
	cout << this->getCry() << endl;
	this->SDef+=10;
	this->SAtk+=5;
	other.checkSDef();
	other.checkSAtk();
}

/*
 *Metodo que retorna el tipo de Moltres 
 * @return string 
*/
string Moltres::getType(){
	return this->type;
}

/*
 *Metodo que retorna los tipos que Moltres es fuerte versus 
 * @return string 
*/
string Moltres::getStrongVs(){
	return this->strongVs;
}

/*
 *Metodo que retorna los tipos que Moltres es debil versus 
 * @return string 
*/
string Moltres::getWeakVs(){
	return this->weakVs;
}

/*
 *Metodo que retorna la informacion de Moltres
 *@return string (Formato "<name>:<specie>	exp:<val>	Tipo:<type>"	 FuerteVs:<strongVs>	DebilVs:<weakVs>"
*/
void Moltres::infoMoltres(){	
	cout << this->info() << "\tTipo:" << this->getType() <<
 "\tFuerteVs: " << this->getStrongVs() << "\tDebilVs: " <<
 this->getWeakVs() << endl; 
}