#include "Ice.hpp"

Ice::Ice(){
}

string Ice::type(){
	return "Ice";
}

string Ice::strongVs(){
	return "Ground, Grass, Flying, Dragon";
}

string Ice::weakVs(){
	return "Fire, Water, Ice, Steel";
}

Ice::~Ice()
{
}
