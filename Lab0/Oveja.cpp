/*
 *@author Luis Adrian Aguilar Cascante
 *@date   01-25-2017
 *@brief  Implementacion de metodo Oveja
*/

#include "Oveja.hpp"

Oveja::Oveja() {
    
}

Oveja::Oveja(bool nuevoSexo) {
    this-> ID = identificador;
    this-> energia = 75;
    this-> sexo = nuevoSexo;
    this-> especie = "Oveja";       
}

Oveja::~Oveja() {
}

Oveja& operator^(const int fila, const int columna);//Mover
Zacate& operator+(const int fila, const int columna);//Comer
Oveja& operator*(const int fila, const int columna);//Reproducirse 
Lobo& operator/(const int fila, const int columna);//Morir

