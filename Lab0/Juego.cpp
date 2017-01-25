/*
 *@author Luis Adrian Aguilar Cascante, @autor Giancarlo Marin Hernandez
 *@date   01-25-2017
 *@brief  Implementacion de funciones para el funcionamiento del juego ecologico
*/

#include <fstream>
#include <cstdlib>
#include "Animal.hpp"
#include "Celda.hpp"
#include "Lobo.hpp"
#include "Oveja.hpp"
#include "Raton.hpp"
#include "Zorro.hpp"
#include "print.hpp"

using namespace std;

/*
 * Constructor por defecto de la clase Animal
*/ 
Animal::Animal(){
	cout << "Creando Animal" << endl;
	identificador++;
}

/*
 * Destructor por defecto de la clase Animal
*/ 
Animal::~Animal(){
	cout << "Destruyendo Animal" << endl;
}

/*
 * Metodo get del identifiacor del animal
 *@return unsigned int 	ID del Animal
*/ 
unsigned int Animal::getID(){
	return this->ID;
}

/*
 * Metodo get del atributo especie 
 *@return string 	Nombre de la especie del animal
*/
string Animal::getEspecie(){
	return this->especie;
}

/*
 * Metodo set del atributo energia
 *@param short int 	Nuevo valor de energia asignado al animal 
*/ 
void Animal::setEnergia(short int nuevaEnergia){
	this->energia=nuevaEnergia;
}

/*
 * Metodo get del atributo energia
 *@return short int 	Valor de energia asignado al animal 
*/ 
short int Animal::getEnergia(){
	return this->energia;
}

/*
 * Metodo get del atributo sexo
 *@return bool 	Retorna el sexo del animal de la siguiente forma:
 * False=Macho True=Hembra
*/ 
bool Animal::getSexo(){
	return this->sexo;
}






/*
 *Método de alimentación del zorro
*/

    
Z::ComerZ()
{
 if (campo = Raton)    
    {
    Morir(Raton);
    this-> EnergiaZ = EnergiaR + EnergiaZ;        
    } 
 else if (campo = Zorro2)
 {
     if (Zorro = Zm)
     {
         if (energiaZ1 = energiaZ2)
         {
             MorirZ(Z1);
             MorirZ(Z2);
         }
         else if (energiaZ1 > energiaZ2)
         {
             this-> energiaZ = energiaZ1 + energiaZ2;
         }
         
         else;
         
     }
 }
        
    return;
}          


/*
 * Método de muerte del zorro
*/
 
Z::MorirZ()
{
    energia = 0;
    return;
            
}

/*
 * Método de desplazamiento del zorro
*/
 Z::MoverZ()
{
    
    return;
            
}

/*
 Método de reproducción del Zorro
*/
 
Z::ReprodZ()
{
    
    return;
            
}


/*
Método de alimentación del Oveja
*/
O::ComerO()
{
    
    return;
            
}

/*
 * Método de muerte del Oveja
*/
  
O::MorirO()
{
    energía = 0;
    return;
            
}

/*
Método de desplazamiento del Oveja
*/
O::MoverO()
{
    
    return;
            
}

/*
Método de reproducción del Oveja
*/

O::ReprodO()
{
    
    return;
            
}

/*
 * Método de alimentación del Ratón
*/

 R::ComerR()
{
    
    return;
            
}

/* 
Método de muerte del Ratón
*/
 
R::MorirR()
{
    energía = 0;
    return;
            
}

/*
Método de desplazamiento del Ratón
*/

R::MoverR()
{
    
    return;
            
}

/*
Método de reproducción del Ratón
*/

R::ReprodR()
{
    
    return;
            
}

/*
 * Método de alimentación del Leon
 */

L::ComerL()
{
    
     if (campo = Raton)    
        {
        MorirR(Raton);
        this-> EnergiaL = EnergiaR + EnergiaL;        
        } 
     
     else if (campo = Oveja)     
        {
        MorirO(Oveja);
        this-> EnergiaL = EnergiaO + EnergiaL;        
        } 
    
    else if (campo = Zorro)
        {
        MorirZ(Zorro);
        this-> EnergiaL = EnergiaZ + EnergiaL;        
        } 
     
 
         
         
     
            
    return;
            
}

/*
 * Método de muerte del Leon
*/

L::MorirL()
{
    
    return;
            
}


/*
 * Método de desplazamiento del Lobo
*/

L::MoverL()
{
    
    return;
            
}

/*
Método de reproducción del Lobo
*/

L::ReprodL()
{
    
    return;
            
}



/*
Método constructor de la clase
*/

Juego::Juego(const Juego& orig) {
}

Juego::~Juego() {
}
