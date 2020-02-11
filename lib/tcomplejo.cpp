#include <iostream>

/**INICIO FORMA CANÓNICA**/


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

///////////////////////////////////// getters y setters //////////////////////////////
//Get parte real - Coge parte real.
double TComplejo::Re() const{
	return this->re;
}

//Get parte imaginaria - Coge parte imaginaria.
const double TComplejo::Im() const{
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