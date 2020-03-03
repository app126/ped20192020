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
		this->~TComplejo();
		re = t.re;
		im = t.im;
	}

}
/*FIN DE FORMA CANÓNICA*/


////////////////////////SOBRECARGA DE OPERADORES ARITMETICOS.////////////////////////
TComplejo TComplejo::operator+(const TComplejo &complejo) const{

	TComplejo aux;
	aux.Re(complejo.re + this->re);
	aux.Im(complejo.im + this->im);
	return aux;
}


TComplejo TComplejo::operator-(const TComplejo &complejo) const{
	TComplejo aux;
	aux.Re(complejo.re - this->re);
	aux.Im(complejo.im - this->im);
	return aux;
}

TComplejo TComplejo::operator*(const TComplejo &a) const{
	/*TComplejo aux;
	aux.Re(a.re * this->re);
	aux.Im(a.im * this->im);
	return aux;*/
	TComplejo aux;
	aux.Re((Re()*a.Re())-(im*a.Im()));
	aux.Re((Re()*a.Im())+(im*a.Re()));

	return aux;
}


TComplejo TComplejo::operator+(const double d) const{
	TComplejo aux(d);
	aux.Re(this->re + d);
	return aux;
}

TComplejo TComplejo::operator-(const double d) const{
	TComplejo aux(d);
	aux.Re(this->re - d);
	return aux;
}

TComplejo TComplejo::operator*(const double d) const{
/*
	double ac;
	double bd;
	double ad;
	double bc;
	double real;
	double imaginario;

	ac = aux.re * this->re;
	bd = aux.im * this->im;
	ad = aux.re * this->im;
	bc = aux.im * this->re;

	real = ac-bd;
	imaginario = ad+bc;*/
	TComplejo t(d);
	TComplejo aux;
	aux = *this*t;
	return aux;
}

///////////////////////////////////// OTROS OPERADORES//////////////////////////////
bool TComplejo::operator==( const TComplejo &complejo) const{
	/*bool igual = false;
	if(complejo.re == this->re){
		if(complejo.im == this->im){
			igual = true;
		}
	}else{
		igual = false;
	}

	return igual;*/

	
	if(this->re == complejo.re && this->im == complejo.im){
		return true;
	}else{
		return false;
	}
	
}

bool TComplejo::operator!=( const TComplejo &complejo) const{
	return !(*this == complejo);
}


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
	double total;
	total = atan2(parteimaginaria,partereal);
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


////////////////////FUNCIONES AMIGAS////////////////////////////

ostream & operator<<(ostream &salida, const TComplejo &t) {
	salida << "(";
	salida << t.Re();
	salida << " ";
	salida << t.Im();
	salida << ")";
	return salida;
}

TComplejo operator+(double d, const TComplejo &complejo) {
	TComplejo aux(d);
	aux.operator+(complejo);
	return aux;
}

TComplejo operator-(double d, const TComplejo &complejo) {
	TComplejo aux(d);
	aux.operator-(complejo);
	return aux;
}

TComplejo operator*(double d, const TComplejo &complejo) {
	TComplejo aux(d);
	aux.operator*(complejo);
	return aux;
}