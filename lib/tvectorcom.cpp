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
TVectorCom &TVectorCom::operator=(const TVectorCom &t){

	//¿Le copio el puntero (la dirección a la que apunta) o el valor en un nuevo array de TVectorCom?
	//¿O comparo uno a uno los valores y si no son iguales le pongo un flag y los copio?
	//¿Serviría compararlo así? ¿El compilador hace una comparación profunda elemento a elemento?
	if(this != &t){
		this->tamano = t.tamano;
		for(int i=0;i<this->tamano;i++){
			c[i] = t.c[i];
		}
	}
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
	TComplejo aux;
	for(int i=0;i<tamano;i++){
		if((c[i].Re() != 0 && c[i].Im() != 0) && (this->c[i] != aux)){
			ocupadas = ocupadas + 1;
		}

	}

}

//Devuelve TRUE si existe TComplejo en el vector.
bool TVectorCom::ExisteCom(TComplejo & t){

	for(int i=0;i<this->tamano;i++){
		if(c[i] == t){
			return true;
		}
	}
	return false;

}

//Mostrar por pantalla los elementos TComplejo del vector con PARTE REAL IGUAL 
// O POSTERIOR al argumento.
void TVectorCom::MostrarComplejos(double d){
	int cont = 0;

	cout << "[";

	for(int i = 0 ; i < this->tamano ; i++){

		if(c[i].Re() >= d){
			cont=cont + 1;
			if(cont>1){
				cout << c[i] << ",";
			}else{
				cout << c[i]; //No sé si estará bien esto...
			}
	}

	}
	cout << "]";

}

//REDIMENSIONAR el vector TComplejo.
bool TVectorCom::Redimensionar(int a){

// Si el entero es menor o igual que 0, el método devolverá FALSE, sin hacer nada más.
// Si el entero es de igual tamaño que el actual del vector, el método devolverá FALSE, sin hacer
//nada más.
	if(a <= 0 || a == tamano){
		return false;
	}

	if(a > 0 && a > tamano){
		//Me creo un tamanio auxiliar igual al que me han pasado.
		int aux = a;

		//Me creo un vector auxiliar igual al actual.
		TVectorCom vectorAux(*this);

		//Redimensiono el vector actual
		this->tamano = a;

		//Recorro un vector hasta aux (el anterior valor de a) y lo asigno gracias al vectorAux
		for(int i = 0;i < aux;i++){
			this->c[i] = vectorAux.c[i];
		}

		//Recorro desde el tamanio anterior hasta el tammanio total
		for(int i = aux;i < a;i++){
			this->c[i] = TComplejo();
		}

		//Devuelvo verdadero, ya que se ha hecho la redimension
		return true;
	}

	// Si el entero es mayor que 0 y menor que el tamaño actual del vector, se deben eliminar los
	// TComplejo que sobren por la derecha, dejando el nuevo tamaño igual al valor del entero.
	if(a > 0 && a < tamano){
		//Me creo un vector auxiliar igual al actual.
		TVectorCom vectorAux(*this);
		//TVectorCom vectorAux(*this);
		this->~TVectorCom();
		this->tamano = a;
		this->c = new TComplejo[a];
			for (int i = 0; i < a; i++) {
				this->c[i] = vectorAux.c[i];
			}
		//this->c->erase(tamano,a);
		return true;
	}

}


ostream & operator<<(ostream &salida, const TVectorCom &vector) {

	salida << "[";
	if(vector.tamano == 0){
		salida << "]";
	}else if(vector.tamano == 1){
		salida << "(1) " << vector.c[0]; 

	}else{
		for(int i = 0 ; i < vector.tamano - 1 ; i++){
			salida << "(";
			salida << i+1;
			salida << ") ";
			salida << vector.c[i] << ", ";		
		}	

		salida << "(" << vector.tamano << ") ";
		salida << vector.c[vector.tamano - 1];
	}
	salida << "]";
	return salida;
}