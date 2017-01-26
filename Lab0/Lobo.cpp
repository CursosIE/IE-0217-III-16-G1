/*
 *@author Luis Adrian Aguilar Cascante
 *@date   01-25-2017
 *@brief  Implementacion de metodo Lobo
*/

#include "Lobo.hpp"


Lobo::Lobo() {
}

Lobo::Lobo(bool nuevoSexo) {
    this-> ID = identificador;
    this-> energia = 25;
    this-> sexo = nuevoSexo;
    this-> especie = "Raton";       
}

Lobo::~Lobo() {
}
Lobo& operator^(const int fila, const int columna);//Mover
Zorro& operator+(const int fila, const int columna);//Comer
Lobo& operator*(const int fila, const int columna);//Reproducirse 
Lobo& operator/(const int fila, const int columna);//Morir

