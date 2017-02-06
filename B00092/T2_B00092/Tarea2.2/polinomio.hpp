
/* 
 * File:   polinomio.hpp
 * Author: adrian
 *
 * Created on January 24, 2017
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
	polinomio& operator*(const polinomio &pDer);
	polinomio& operator+(const polinomio &sumando);
        polinomio& operator=(const polinomio &orig);
	polinomio& operator-(const polinomio &sustraendo);
	polinomio& operator/(const polinomio &dividendo);
         polinomio(const polinomio& orig);
         virtual ~polinomio();
         int a, b, c, d;
//         
polinomio& operator +(const polinomio &grado); 

    
private:

};


 
#endif /* POLINOMIO_HPP */

 