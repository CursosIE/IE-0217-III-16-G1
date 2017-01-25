#include "Fire.hpp"

Fire::Fire(){
}

string Fire::type(){
	return "Fire";
}

string Fire::strongVs(){
	return "Grass, Ice, Bug, Steel";
}

string Fire::weakVs(){
	return "Fire, Water, Rock, Dragon";
}

Fire::~Fire()
{
}
