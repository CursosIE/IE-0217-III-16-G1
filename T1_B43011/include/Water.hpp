#ifndef WATER_HPP
#define WATER_HPP
#include <iostream>
#include <string>
#include "Pokemon.hpp"
	
using namespace std;

class Water : virtual public Pokemon
{

	public:
		static string type();
		static string strongVs();
		static string weakVs();
		
		Water();
		virtual ~Water();
/*
		virtual void atk1(Pokemon &other);
		virtual void atk2(Pokemon &other);
		virtual void atk3(Pokemon &other);
		virtual void atk4(Pokemon &other);*/

	private:
	protected:

};
	
#endif
