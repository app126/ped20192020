#include <iostream> 
#include <stdio.h>
#include <string.h>
#include <math.h>


using namespace std;

class TComplejo{

	private:
		double re; //parte real.
		double im; //parte imaginaria.
	public:
		/*******Forma canónica********/
		TComplejo(); //constructor por defecto.
		TComplejo(double); //constructor a partir de la parte real.
		TComplejo(double,double); //Constructor a partir de la parte real e imaginaria.
		TComplejo(TComplejo &); //Constructor copia.
		~TComplejo(); //Destructor.
		TComplejo &operator = (const TComplejo &); //Sobrecarga del operador de asignacion

		/*SOBRECARGA DE OPERADORES ARITMETICOS*/
		TComplejo operator+(const TComplejo &) const; //Sobrecarga operator+
		TComplejo operator-(const TComplejo &) const; //Sobrecarga operator-
		TComplejo operator*(const TComplejo &) const; //Sobrecarga operator*
		TComplejo operator+(const double) const; //Sobrecarga operator+
		TComplejo operator-(const double) const; //Sobrecarga operator-
		TComplejo operator*(const double) const; //Sobrecarga operator*
		///////////////////////////////////////////////////////////////////////////*/
		/*OTROS OPERADORES*/
		bool operator==(const TComplejo &) const; //operator==
		bool operator!=(const TComplejo &) const; //operator!=
		/********Getters y setters******************/
		double Re() const; //Get parte real - Devuelve la parte real.
		double Im() const; //Get parte imaginario - Devuelve la parte imaginaria.
		void Re(double); //Set parte real - Modifica la parte real.
		void Im(double); //Set parte imaginaria - Modifica la parte imaginaria.
		/*************Otros métodos*******************************************/
		double Arg(); // Calcula el argumento (En radianes)
		double Mod(); //Calcula el módulo
		///////////////////////////////////////////////////////////////////////////
		/*FUNCIONES AMIGAS*/
		//Sobrecarga del operador salida
		friend ostream & operator <<(ostream &, TComplejo &);  //Hecho - constante tcomplejo

		friend TComplejo operator+(double, const TComplejo &); //Hecho
		friend TComplejo operator-(double, const TComplejo &); //Hecho
		friend TComplejo operator*(double, const TComplejo &); //Hecho
};
