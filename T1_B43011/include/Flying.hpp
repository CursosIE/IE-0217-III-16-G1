#ifndef FLYING_HPP
#define FLYING_HPP
#include <iostream>
#include <string>
#include "Pokemon.hpp"

using namespace std;

class Flying : virtual public Pokemon
{

	public:
		static string type();
		static string strongVs();
		static string weakVs();
	
		Flying();
		virtual ~Flying();
/*
		virtual void atk1(Pokemon &other);
		virtual void atk2(Pokemon &other);
		virtual void atk3(Pokemon &other);
		virtual void atk4(Pokemon &other);*/

	private:
	protected:

};
	
#endif
