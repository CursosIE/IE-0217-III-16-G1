#include "Electric.hpp"

Electric::Electric(){
}

string Electric::type(){
	return "Electric";
}

string Electric::strongVs(){
	return "Water, Flying";
}

string Electric::weakVs(){
	return "Electric, Grass, Dragon";
}

Electric::~Electric()
{
}
