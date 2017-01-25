/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   polinomio.cpp
 * Author: adrian
 * 
 * Created on January 24, 2017, 9:31 PM
 */

#include "polinomio.hpp"
#include <iostream>

using namespace std;

int polinomio::suma()
{}
int polinomio::resta()
{}
int polinomio::división()
{}
int polinomio::multiplicación()
{}


void polinomio::resultado()
{
      cout << "Resultado" << this <<", ";
	cout << polinomio <<", ";
	cout << endl;
	return;
}

polinomio::polinomio() {
    
}

polinomio::polinomio(const polinomio& orig) {
}

polinomio::~polinomio() {
}

