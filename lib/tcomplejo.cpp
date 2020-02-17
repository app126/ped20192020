#include <iostream>
#include <math.h>
#include "tcomplejo.h"

/**INICIO FORMA CANÓNICA**/
using namespace std;

//Constructor por defecto sin parámetros, inicializa re e im a cero.
TComplejo::TComplejo(){
	this->re = 0;
	this->im = 0;
}

//Constructor que inicializa la parte imaginaria a 0 y la real con un valor que le hemos pasado.
TComplejo::TComplejo(double x){
	this->re = x;
	this->im = 0;
}

//Constructor a partir de la parte real e imaginaria.
TComplejo::TComplejo(double r, double i){
	this->re = r;
	this->im = i;
}

//Constructor copia.
TComplejo::TComplejo(TComplejo & copia){
	this->re = copia.re;
	this->im = copia.im;
	/*
	this->re = copia.Re();
	this->im = copia.Im();
	*/
}

//Desctructor que deja la parte real e imaginaria a 0
TComplejo::~TComplejo(){
	this->re = 0;
	this->im = 0;
}


//Sobrecarga del operador de asignación
TComplejo &TComplejo::operator=(const TComplejo &t){
	if(this != &t){

	}

}
/*FIN DE FORMA CANÓNICA*/


////////////////////////SOBRECARGA DE OPERADORES ARITMETICOS.////////////////////////
TComplejo TComplejo::operator+(const TComplejo &complejo){

	TComplejo aux;
	aux->re = complejo.re + this->re;
	aux->im = complejo.im + this->im;
	return aux;
}

TComplejo TComplejo::operator-(const TComplejo &complejo){
	TComplejo aux;
	aux->re = complejo.re - this->re;
	aux->re = complejo.im - this.im;
	return aux;

}

///////////////////////////////////// getters y setters //////////////////////////////
//Get parte real - Coge parte real.
double TComplejo::Re() const{
	return this->re;
}

//Get parte imaginaria - Coge parte imaginaria.
double TComplejo::Im() const{
	return this->im;
}

//Set parte real - Modifica parte real.
void TComplejo::Re(double r){
	this->re = r;
}

//Set para parte imaginaria - Modifica parte imaginaria
void TComplejo::Im(double i){
	this->im = i;
}

//Calcular el argumento (en Radianes)
double TComplejo::Arg(){
	double partereal = this->re;
	double parteimaginaria = this->im;

	//double partereal = copia.Re();
	//double parteimaginaria = copia.Im();

	double total;
	total = atan2(partereal,parteimaginaria);
	return total;
}

//Calcula el módulo
double TComplejo::Mod(){
	double partereal = this->re;
	double parteimaginaria = this->im;

	double realelevada = pow(partereal,2);
	double imaginariaelevada = pow(parteimaginaria,2);
	double total = realelevada+imaginariaelevada;

	double modulo;
	modulo = sqrt(total);
	return modulo;
}

//IGUALDAD de números complejos.
bool TComplejo::operator==(TComplejo & copia){

}

//DESIGUALDAD de números complejos.
bool TComplejo::operator!=(TComplejo & copia){

}


