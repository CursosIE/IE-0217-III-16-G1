#ifndef ELECTRIC_HPP
#define ELECTRIC_HPP
#include <iostream>
#include <string>
#include "Pokemon.hpp"

using namespace std;

class Electric : virtual public Pokemon
{

	public:
		static string type();
		static string strongVs();
		static string weakVs();
	
		Electric();
		virtual ~Electric();
/*
		virtual void atk1(Pokemon &other);
		virtual void atk2(Pokemon &other);
		virtual void atk3(Pokemon &other);
		virtual void atk4(Pokemon &other);*/

	private:
	protected:

};
	
#endif
