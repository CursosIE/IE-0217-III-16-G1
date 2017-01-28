/*
 *@author Luis Adrian Aguilar Cascante
 *@date   01-25-2017
 *@brief  Implementacion de metodo Ratón
*/


#include "Raton.hpp"

Raton::Raton() {
}

Rat:on:Raton(bool nuevoSexo) {
    this-> ID = identificador;
    this-> energia = 100;
    this-> sexo = nuevoSexo;
    this-> especie = "Zorro";       
}

Raton::~Raton() {
}

Raton& operator^(const int fila, const int columna);//Mover
Zacate& operator+(const int fila, const int columna);//Comer
Raton& operator*(const int fila, const int columna);//Reproducirse 
Lobo& operator/(const int fila, const int columna);//Morir
       


