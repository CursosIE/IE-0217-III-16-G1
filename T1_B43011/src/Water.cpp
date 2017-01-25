#include "Water.hpp"

Water::Water(){
}

string Water::type(){
	return "Water";
}

string Water::strongVs(){
	return "Rock, Flying, Fire";
}

string Water::weakVs(){
	return "Water, Grass, Dragon";
}

Water::~Water()
{
}
