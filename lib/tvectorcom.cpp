#include <iostream>
#include <math.h>
#include "tvectorcom.h"

/**INICIO FORMA CANÓNICA**/
using namespace std;


//Constructor por defecto sin parametros.
TVectorCom::TVectorCom(){
	this->c = NULL;
	this->tamano = 0;
}

//Constructor a partir de un tamaño.
//DUDA-> Si el constructor solo le pasamos el tamaño y no el vector (TVector)
// ¿Los llamamos a los vectores con el constructor por defecto de tcomplejo?
TVectorCom::TVectorCom(int a){
	if(a < 0){
		this->c = NULL;
		this->tamano = 0;
	}else{
		this->c = new TComplejo[a];
		for(int i=0; i<a;i++){
			c[i] = TComplejo();
		}
		this->tamano = a;
	}
}

//Constructor de copia.
TVectorCom::TVectorCom(const TVectorCom & vector){

	this->tamano = vector.tamano;
	this->c = new TComplejo[this->tamano];

	if (!c)
		cout << "Error" << endl;
	else {
		for (int i = 0; i < tamano; i++) {
			this->c[i] = vector.c[i];
		}
	}
}


//Destructor - Libera toda la memoria que ocupa el vector, dejandolo en un vector de dimension 0.
TVectorCom::~TVectorCom(){
	if(c){
	delete [] c; //Borro sólo el objeto creado en el vector c.
	this->tamano = 0; //Le pongo como tamaño 0
	c = NULL;
	}
	/* ----------- ¿Así estaría bien hecho? Ya que borro uno a uno los elementos del vector
	y después borro el objeto creado del vector----
	for(int i=0;i< this->tamano ; i++ ) {
		delete c[i];
	}
	delete c;
	*/
}

//Sobrecarga del operador de asignación.
TVectorCom &TVectorCom::operator=(const TVectorCom &vector){

	//¿Le copio el puntero (la dirección a la que apunta) o el valor en un nuevo array de TVectorCom?
	//¿O comparo uno a uno los valores y si no son iguales le pongo un flag y los copio?
	//¿Serviría compararlo así? ¿El compilador hace una comparación profunda elemento a elemento?
	if (this != &vector) {
		this->~TVectorCom();

		this->tamano = vector.tamano;
		this->c = new TComplejo[vector.tamano];

		if (!c)
			cout << "Error" << endl;
		else {
			for (int i = 0; i < tamano; i++) {
				c[i] = vector.c[i];
			}
		}
	}

	return *this;
}

////////////////FIN DE FORMA CANONICA///////////////////////////


///////////////////////METODOS//////////////////////
//Sobrecarga del operador de igualdad.
bool TVectorCom::operator==(const TVectorCom & t) const {
	bool dentroIguales = false;
	if(this->tamano == t.tamano){

		for(int i=0;i<t.tamano;i++){
			if(this->c[i]==t.c[i]){
				dentroIguales = true;
			}else{
				dentroIguales = false;
			}
		}

		if(dentroIguales){
			return true;
		}else{
			return false;
		}

	}else{ 
		return false;
	}

}

//Sobrecarga del operador de desigualdad
bool TVectorCom::operator!=(const TVectorCom & t) const {
	return !(*this == t);
}

//Sobrecarga del operador corchete (parte izquierda)
TComplejo & TVectorCom::operator[](int a){
//devolver a 00 el actual
	if (a < 1 || a > this->tamano) {
		error.Re(0);
		error.Im(0);
		return error;
	} else {
		return this->c[a - 1];
	}

}

//Sobrecarga del operador corchete (parte derecha)
TComplejo TVectorCom::operator[](int a) const {
	TComplejo aux;
	if (a < 1 || a > this->tamano) {
		aux.Re(0);
		aux.Im(0);
		return aux;
	} else {
		return this->c[a - 1];
	}

}

//Tamaño del vector (posiciones totales)
int TVectorCom::Tamano(){
	return tamano;
}

/*                                 
En los operadores "Ocupadas()” , “TVectorCom()" :
Se consideran “posiciones vacías” del vector, aquellas que contengan un TComplejo con valor por
defecto (0 0), por ejemplo los recién inicializados con el Constructor por defecto de TComplejo, o
bien recién destruido con el Destructor de TComplejo.*/

//Cantidad de posiciones OCUPADAS (TComplejo NO VACIO) en el vector
int TVectorCom::Ocupadas(){
	int ocupadas = 0;

	TComplejo comp;

	for (int i = 0; i < this->tamano; i++) {
		if ((this->c[i] != comp) && !(this->c[i].Re() == 0 && this->c[i].Im() ==0 ))
			ocupadas++;
	}

	return ocupadas;

}

//Devuelve TRUE si existe TComplejo en el vector.
bool TVectorCom::ExisteCom(const TComplejo & t) const{
	bool encontrado = false;

	for (int i = 0; (i < this->tamano) && (encontrado == false); i++) {
		if (this->c[i] == t)
			encontrado = true;
	}

	return encontrado;

}

//Mostrar por pantalla los elementos TComplejo del vector con PARTE REAL IGUAL 
// O POSTERIOR al argumento.
void TVectorCom::MostrarComplejos(double d){
int cuantos = 0;

	for (int i = 0; i < this->tamano; i++) {
		if (this->c[i].Re() >= d) {
			cuantos++;
		}
	}

	cout << "[";

	for (int i = 0; i < this->tamano; i++) {
		if (this->c[i].Re() >= d && cuantos > 1) {
			cout << this->c[i] << ", ";
			cuantos--;
		}
		else {
			if (this->c[i].Re() >= d) {
				cout << this->c[i];
			}
		}
	}

	cout << "]";

}

//REDIMENSIONAR el vector TComplejo.
bool TVectorCom::Redimensionar(int newtam){

// Si el entero es menor o igual que 0, el método devolverá FALSE, sin hacer nada más.
// Si el entero es de igual tamaño que el actual del vector, el método devolverá FALSE, sin hacer
//nada más.	if (newtam <= 0)
	if (newtam <= 0)
		return false;
	else {
		if (newtam == this->tamano)//El nuevo tamaño es igual
			return false;
		else {
			if (newtam > 0 && newtam > this->tamano) {//Nuevo tamaño mayor al que tenemos
				TVectorCom aux(*this);
				this->~TVectorCom();
				this->tamano = newtam;
				this->c = new TComplejo[newtam];
				for (int i = 0; i < aux.tamano; i++) {
					this->c[i] = aux.c[i];
				}

				return true;

			} else {
				if (newtam > 0 && newtam < this->tamano) {//Nuevo tamaño menor al que tenemos
					TVectorCom aux(*this);
					this->~TVectorCom();
					this->tamano = newtam;
					this->c = new TComplejo[newtam];
					for (int i = 0; i < newtam; i++) {
						this->c[i] = aux.c[i];
					}
				}

				return true;
			}
		}
	}

}


ostream & operator<<(ostream &salida, const TVectorCom &vector) {
	salida << "[";

	if (vector.tamano == 0) {
		salida << "]";
	} else {
		for (int i = 0; i < vector.tamano - 1; i++) {
			salida << "(" << i + 1 << ") ";
			salida << vector.c[i];
			salida << ", ";
		}
		salida << "(" << vector.tamano << ") ";
		salida << vector.c[vector.tamano - 1];
		salida << "]";
	}

	return salida;
}