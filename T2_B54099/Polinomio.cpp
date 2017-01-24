/*
 *@author Giancarlo Marin 
 *@date   01-20-2017
 *@brief  Archivo de implementacion de los metodos de la clase Polinomio
*/
#include "Polinomio.hpp"

/*
 *Metodo constructor por defecto de la clase
*/
Polinomio::Polinomio(){
	cout << "Creando Polinomio" << endl;
}

/*
 *Metodo constructor sobrecargado de la clase
 * @param int 		Grado del polinomio
*/
Polinomio::Polinomio(int newGrado){
	this->grado=newGrado;
	this->datos=new double[newGrado+1];
	for (int i=0;i<=newGrado;i++){
		this->datos[i]=0;
	}
}

/*
 *Metodo constructor sobrecargado de la clase
 * @param int 		Grado del polinomio
 * @param double* 	Vector de datos del polinomio d[0]: Mayor grado d[n]: Grado 0 
*/
Polinomio::Polinomio(int newGrado, double* newDatos){
	this->grado=newGrado;
	this->datos=newDatos;
	for (int i=0;i<=newGrado;i++){
		this->datos[i]=newDatos[i];
	}
}

/*
 *Metodo constructor por copia
 * @param const Polinomio& 	Polinomio por copiar
*/
Polinomio& Polinomio::operator=(const Polinomio& orig){
	grado=orig.grado;
	datos=new double[grado];
	for (int i=0;i<=grado;i++){
		datos[i]=orig.datos[i];		
	}
	return *this;
}

/*
 *Metodo destructor de polinomios
*/
Polinomio::~Polinomio(){
	delete this->datos;
	cout << "Destruyendo Polinomio" << endl;
}

/*
 * Metodo set de grado
 * @param int Nuevo grado que se le asignara al polinomio
*/
void Polinomio::setGrado(int newGrado){
	this->grado = newGrado;
}

/*
 * Metodo que retorna el grado del polinomio
 * @return int 	Grado del polinomio
*/
int Polinomio::getGrado(){
	return this->grado;
}

/*
 * Metodo set de los datos del polinomio
 * @param double*	Nuevo array con los terminos del polinomio
 * @param int		Numero de terminos que contiene el array 		
*/
void Polinomio::setDatos(double* newDatos, int grado){
	if (this->grado == grado){
		for (int i=grado;i>=0;i--){
			this->datos[i-1]=newDatos[i-1];		
		}
	}
}

/*
 * Metodo que retorna los datos en el polinomio
 * @return 	double* 	
*/
double* Polinomio::getDatos(){
	return this->datos;
}

/*
 * Metodo que imprime los datos de un Polinomio
*/
void Polinomio::poliPrint(){
	for (int i=0;i<=this->getGrado();i++){
		if (i!=this->getGrado()){
			cout << datos[i] << "x^" << this->getGrado()-i << "+";
		}
		else{
			cout << datos[i] << "x^" << this->getGrado()-i << endl;
		}
	}
}

/*
 *Metodo de sobrecarga de la suma en polinomios
 * @return Polinomio	Resultado de la suma de los polinomios 
*/
Polinomio& Polinomio::operator+(const Polinomio& sumando){
	int gradoSuma=sumando.grado;
	double* datosSuma;
	int diferencia=sumando.grado-grado;
	if (grado>sumando.grado){
		diferencia*=-1;
		gradoSuma=grado;
		datosSuma=new double[gradoSuma+1];
	}
	else{
		datosSuma=new double[gradoSuma+1];
	}
	for (int i=0;i<=gradoSuma;i++){
		if (gradoSuma==grado && diferencia-i>0){
			datosSuma[i]=datos[i];
		}
		else if(gradoSuma==sumando.grado && diferencia-i>0){
			datosSuma[i]=sumando.datos[i];
		}
		else{
			datosSuma[i]=sumando.datos[i-diferencia]+datos[i];
		}
	}
	Polinomio* suma=new Polinomio(gradoSuma, datosSuma);
	return *suma;
}

/*
 *Metodo de sobrecarga de la resta en polinomios
 * @return Polinomio	Resultado de la resta de los polinomios 
*/
Polinomio& Polinomio::operator-(const Polinomio& sustraendo){
	int gradoResta=sustraendo.grado;
	double* datosResta;
	int diferencia=sustraendo.grado-grado;
	if (grado>sustraendo.grado){
		diferencia*=-1;
		gradoResta=grado;
		datosResta=new double[gradoResta+1];
	}
	else{
		datosResta=new double[gradoResta+1];
	}
	for (int i=0;i<=gradoResta;i++){
		if (gradoResta==grado && diferencia-i>0){
			datosResta[i]=datos[i];
		}
		else if(gradoResta==sustraendo.grado && diferencia-i>0){
			datosResta[i]=-1*sustraendo.datos[i];
		}
		else{
			datosResta[i]=datos[i]-sustraendo.datos[i-diferencia];
		}
	}
	Polinomio* resta=new Polinomio(gradoResta, datosResta);
	return *resta;
}

/*
 *Metodo de sobrecarga de la multiplicacion en polinomios
 * @return Polinomio	Resultado de la multiplicacion de los polinomios 
*/
Polinomio& Polinomio::operator*(const Polinomio& producto){
	int gradoMult=grado+producto.grado;
	Polinomio* mult=new Polinomio(gradoMult);
	for (int i=0;i<=grado;i++){
		for (int j=0;j<=producto.grado;j++){
			mult->datos[i+j]+=datos[i]*producto.datos[j];
		}
	}
	return *mult;
}

/*
 *Metodo de sobrecarga de la multiplicacion en polinomios
 * @return Polinomio	Resultado de la division de los polinomios 
*/
Polinomio& Polinomio::operator/(const Polinomio& divisor){
	int gradoDiv=grado-divisor.grado; 
	int diferencia=gradoDiv;
	Polinomio* div=new Polinomio(gradoDiv);
	//Aplicando division sintetica para P(X)>Q(x)
	Polinomio *Res=this; //Polinomio Residuo
	int i=0; //Contador para asignacion de terminos del cociente
	while (diferencia>=0){
		//Asignando el termino i-esimo del cociente
		div->datos[i]=Res->datos[i]/divisor.datos[0];
		//Creando Polinomio Residuo
		double* aux=new double[gradoDiv+diferencia];
		for (int j=0;j<=divisor.grado+diferencia;j++){
			if (j<divisor.grado){
				aux[j]=div->datos[i]*divisor.datos[j];
			}
			else{
				aux[j]=0;
			}
			Res->datos[j+i]-=aux[j];
		}
		diferencia--;
		i++;
	}
	return *div;
}