#ifndef "DATA_H"
#define "DATA_H"

#include <iostream>

template <typename dato>
class Data{
	
	dato info;
	
	Data(){
	}
	
	Data(dato x){
	this->info = x;
	}
	
	virtual ~Data(){
	}
};

#endif
