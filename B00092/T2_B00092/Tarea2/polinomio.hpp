/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   polinomio.hpp
 * Author: adrian
 *
 * Created on January 24, 2017, 9:31 PM
 */

#ifndef POLINOMIO_HPP
#define POLINOMIO_HPP
#include <iostream>

class polinomio
{
    public:
      void resultado();
         int base[4] = {2,3,1,4};
         int nuevo[4];
         polinomio();
         int suma();
         int resta();
         int division();
         int multiplicacion();
         polinomio(const polinomio& orig);
         virtual ~polinomio();
         int a, b, c, d;
//         
polinomio& operator +(const polinomio &grado); 

    
private:

};


 
#endif /* POLINOMIO_HPP */

 