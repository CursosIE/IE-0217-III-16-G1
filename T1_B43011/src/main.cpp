//#include "Pokemon.hpp"
//#include "Fire.hpp"
//#include "Flying.hpp"
//#include "Water.hpp"
//#include "Electric.hpp"
#include "Zapdos.hpp"
#include "Articuno.hpp"
#include "Moltres.hpp"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{

	int i  = 0;
	while(i < 25000){
		cout << "             _                              "<< endl;
		cout << "            | |                             "<< endl;
		cout << " _ __   ___ | | _____ _ __ ___   ___  _ __  "<< endl;
		cout << "| '_ \\ / _ \\| |/ / _ \\ '_ ` _ \\ / _ \\| '_ \\ "<< endl;
		cout << "| |_) | (_) |   <  __/ | | | | | (_) | | | |"<< endl;
		cout << "| .__/ \\___/|_|\\_\\___|_| |_| |_|\\___/|_| |_|"<< endl;
		cout << "| |   "      << endl;                                
		cout << "|_| "<< endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		i++;
	}

	Zapdos* chayote;
	chayote = new Zapdos("Chayote");
	chayote->name = "Chayote";
	chayote->species = "Zapdos";
	chayote->HP = 100;
	chayote->EXP = 100;
	chayote->ATK = 30;
	chayote->sATK = 50;
	chayote->sDEF = 50;
	chayote->DEF = 50;

	Articuno* queso;
	queso = new Articuno("queso");
	queso->name = "queso";
	queso->species = "Articuno";
	queso->HP = 100;
	queso->EXP = 100;
	queso->ATK = 30;
	queso->sATK = 50;
	queso->sDEF = 50;
	queso->DEF = 50;

	Moltres* tostada;
	tostada = new Moltres("tostada");
	tostada->name = "tostada";
	tostada->species = "Moltres";
	tostada->HP = 100;
	tostada->EXP = 100;
	tostada->ATK = 30;
	tostada->sATK = 50;
	tostada->sDEF = 50;
	tostada->DEF = 50;

	chayote->printInfo();
	queso->printInfo();
	tostada->printInfo();

	chayote->atk1(*tostada);
	chayote->atk2(*tostada);
	chayote->atk3(*tostada);
	chayote->atk4(*tostada);

	chayote->printInfo();
	queso->printInfo();
	tostada->printInfo();

	tostada->atk1(*chayote);
	tostada->atk2(*chayote);
	tostada->atk3(*chayote);
	tostada->atk4(*chayote);

	chayote->printInfo();
	queso->printInfo();
	tostada->printInfo();

	tostada->atk1(*queso);
	tostada->atk2(*queso);
	tostada->atk3(*queso);
	tostada->atk4(*queso);

	chayote->printInfo();
	queso->printInfo();
	tostada->printInfo();

	chayote->atk1(*queso);
	chayote->atk2(*queso);
	chayote->atk3(*queso);
	chayote->atk4(*queso);

	chayote->printInfo();
	queso->printInfo();
	tostada->printInfo();

	queso->atk1(*tostada);
	queso->atk2(*tostada);
	queso->atk3(*tostada);
	queso->atk4(*tostada);
	
	chayote->printInfo();
	queso->printInfo();
	tostada->printInfo();

	queso->atk1(*chayote);
	queso->atk2(*chayote);
	queso->atk3(*chayote);
	queso->atk4(*chayote);
	
	chayote->printInfo();
	queso->printInfo();
	tostada->printInfo();
	
	delete chayote;
	delete queso;
	delete tostada;
	return 0;
}
