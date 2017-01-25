#ifndef ICE_HPP
#define ICE_HPP
#include <iostream>
#include <string>
#include "Pokemon.hpp"

using namespace std;

class Ice : virtual public Pokemon
{

	public:
		static string type();
		static string strongVs();
		static string weakVs();
		
		Ice();
		virtual ~Ice();
/*
		virtual void atk1(Pokemon &other);
		virtual void atk2(Pokemon &other);
		virtual void atk3(Pokemon &other);
		virtual void atk4(Pokemon &other);*/

	private:
	protected:

};
	
#endif
