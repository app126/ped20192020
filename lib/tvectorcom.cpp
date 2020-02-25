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
TVectorCom::TVectorCom(int a){

}