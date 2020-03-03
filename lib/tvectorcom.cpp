#include <iostream>
#include <math.h>
#include "tcomplejo.h"
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
TVectorCom::TVectorCom(TVectorCom & t){
	this->tamano = t.tamano;
	this->c = new TComplejo[t.tamano];

	//Faltaria operar el operador corchete [] 
}

//Destructor - Libera toda la memoria que ocupa el vector, dejandolo en un vector de dimension 0.
TVectorCom::~TVectorCom(){
	delete [] c; //Borro sólo el objeto creado en el vector c.
	
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
	bool dentroIguales = FALSE;
	if(this->tamano == t.tamano){

		for(int i=0;i<t.tamano;i++){
			if(this->c[i]==t.c[i]){
				dentroIguales = TRUE;
			}else{
				dentroIguales = FALSE;
			}
		}

		if(dentroIguales){
			return TRUE;
		}else{
			return FALSE;
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
TComplejo TVectorCom::operator[](int a){

}

//Sobrecarga del operador corchete (parte derecha)
TComplejo TVectorCom::operator[] (int a) const{

}

//Tamaño del vector (posiciones totales)
int TVectorCom::Tamano(){

}

//Cantidad de posiciones OCUPADAS (TComplejo NO VACIO) en el vector
int TVectorCom::Ocupadas(){

}

//Devuelve TRUE si existe TComplejo en el vector.
bool TVectorCom::ExisteCom(TComplejo & t){

}

//Mostrar por pantalla los elementos TComplejo del vector con PARTE REAL IGUAL 
// O POSTERIOR al argumento.
void TVectorCom::MostrarComplejos(double d){

}

//REDIMENSIONAR el vector TComplejo.
bool TVectorCom::Redimensionar(int a){

}
























































































