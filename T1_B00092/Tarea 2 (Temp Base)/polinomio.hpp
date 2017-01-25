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

class polinomio {
    public:
        void resultado();
         int polinomio[4];
         polinomio();
         polinomio(const polinomio& orig);
         virtual ~polinomio();
         int a, b;
         
    
private:

};


 polinomio& operator +(const polinomio &grado) 
 {
     return *(new(grado.a + grado.b));
 }
 
 
#endif /* POLINOMIO_HPP */

 