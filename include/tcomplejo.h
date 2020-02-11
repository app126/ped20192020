#include <iostream> 
#include <stdio.h>
#include <string.h>


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
		TComplejo &operator = (TComplejo &); //Sobrecarga del operador de asignación.

		/********Getters y setters******************/
		double Re() const; //Get parte real - Devuelve la parte real.
		double Im() const; //Get parte imaginario - Devuelve la parte imaginaria.
		void Re(double); //Set parte real - Modifica la parte real.
		void Im(double); //Set parte imaginaria - Modifica la parte imaginaria.

}
