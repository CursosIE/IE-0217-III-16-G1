#include "Flying.hpp"

Flying::Flying()
{
}

string Flying::type(){
	return "Fire";
}

string Flying::strongVs(){
	return "Grass, Ice, Bug, Steel";
}

string Flying::weakVs(){
	return "Fire, Water, Rock, Dragon";
}

Flying::~Flying()
{
}


