#include "tabbcom.h"



/////////////////////////////////CLASE TABBCOM
// AUXILIAR : Devuelve el recorrido en inorden
void TABBCom::InordenAux( TVectorCom & t,  int & a) const {

	if(!this->EsVacio()){
		if(this->nodo->de.EsVacio() && this->nodo->iz.EsVacio()){//Si los dos nodos de los lados son vacios, es un nodo hoja
			t[a] = this->nodo->item; //Si es nodo hoja, lo añado al vector de complejos.
			a = a+1; //incremento el flag para el vector.
		}else{ //si el de la izquierda o derecha no son vacíos
			this->nodo->iz.InordenAux(t,a);//pruebo por la izquierda
			t[a] = this->nodo->item;///Lo asigno
			//incremento a
			a = a+1;
			this->nodo->de.InordenAux(t,a);//pruebo por la derecha ahora
		}
	}
}


// AUXILIAR : Devuelve el recorrido en preorden
void TABBCom::PreordenAux( TVectorCom & t,  int & a) const {

	if(!this->EsVacio()){
		if(this->nodo->de.EsVacio() && this->nodo->iz.EsVacio()){ //Si es hoja
			t[a] = this->nodo->item; //lo añado al vector y acabo recurerncia
			a = a+1;
		}else{
			t[a] = this->nodo->item;
			a = a+1;
			this->nodo->iz.PreordenAux(t,a);
			this->nodo->de.PreordenAux(t,a);
		}
	}else{

	}

} 

// AUXILIAR : Devuelve el recorrido en postorden
void TABBCom::PostordenAux( TVectorCom &t,  int &a) const {

	if(!this->EsVacio()){
		if(this->nodo->de.EsVacio() && this->nodo->iz.EsVacio()){
			t[a] = this->nodo->item;
			a = a+1;
		}else{
			this->nodo->iz.PostordenAux(t,a);
			this->nodo->de.PostordenAux(t,a);
			t[a] = this->nodo->item;
			a = a+1;
		}
	}else{

	}

}

//////////////////FROMA CANÓNICA
// Constructor por defecto
TABBCom::TABBCom(){
	// Creo el constructor por defecto a null o lo creo que apunte a TNodoABB
	//this->nodo = new TNodoABB();
	this->nodo = NULL;

}

// Constructor de copia
TABBCom::TABBCom(const TABBCom &t){
	Copiar(t);
}

// Destructor
TABBCom::~TABBCom(){

	while (!this->EsVacio()) {
		TNodoABB *aux = new TNodoABB();
		aux = this->nodo;

		this->nodo->iz.~TABBCom();
		this->nodo->de.~TABBCom();

		delete this->nodo;
		this->nodo = NULL;


	}

}

TABBCom & TABBCom::operator=(const TABBCom &t){
	this->~TABBCom();
	Copiar(t);
	return *this;
}


void TABBCom::Copiar(const TABBCom &t){

	if(t.nodo != NULL){ //Si no es null..

		//creo un nodo auxiliar (que luego será el nodo principal (raiz))
		TNodoABB *aux = new TNodoABB();

		//asigno el nodo del actual, al aux
		aux->item = t.nodo->item;

		//Hago que el nodo de t (que es el que me han pasado, sea el de aux (el nuevo))
		this->nodo = aux;

		//Hago que sea recursivo, primero por la izquierda.
		nodo->iz.Copiar(t.nodo->iz);
		nodo->de.Copiar(t.nodo->de);

	}else{//Si es null, devuelvo NULL en el nodo raíz.
		this->nodo = NULL;
	}

}

//METODOS
// Sobrecarga del operador igualdad
bool TABBCom::operator==( const TABBCom & t) const {

if(this->Nodos() == t.Nodos()){
	for(int i=0;i<t.Nodos();i++ ){
		if(!this->Buscar(t.nodo->item)){
			return false;
		}
	}
}else{
	return false;
}
	return true;
}


bool TABBCom::esMayor(const TComplejo & complejo) {

	bool may = false;

	if (complejo.Mod() == this->nodo->item.Mod()) {
		if (complejo.Re() == this->nodo->item.Re()) {
			if (complejo.Im() == this->nodo->item.Im()) //si mod, re e im son iguales -> false
				may = false;
			else {
				if (complejo.Im() < this->nodo->item.Im())
					may = false;
				if (complejo.Im() > this->nodo->item.Im())
					may = true;;
			}
		} else {
			if (complejo.Re() < this->nodo->item.Re())
				may = false;
			if (complejo.Re() > this->nodo->item.Re())
				may = true;
		}
	} else {
		if (complejo.Mod() < this->nodo->item.Mod())
			may = false;
		if (complejo.Mod() > this->nodo->item.Mod())
			may = true;
	}

	return may;
}

// Devuelve TRUE si el árbol está vacío, FALSE en caso contrario
bool TABBCom::EsVacio() const{

		if (this->nodo){//false si está lleno si es TRUE se devuelve FALSE
			return false;
		}else{//devuelvo true si no está lleno.
			return true;
		}	
}

// Inserta el elemento en el árbol
bool TABBCom::Insertar(const TComplejo &t) {

if(!this->Buscar(t)){// Si no está
	if(!this->EsVacio()){// y no es vacío
		if(this->esMayor(t)){//compruebo cuál es el mayor
			this->nodo->de.Insertar(t);
		}else{
			this->nodo->iz.Insertar(t);
		}
	}else{
		TNodoABB *aux = new TNodoABB();
		aux->item = t;
		this->nodo = aux;
		return true;
	}

}else{
	return false;
}

}


// Borra el elemento en el árbol
bool TABBCom::Borrar(const TComplejo & complejo){
	bool borrado = false;

	if (this->Buscar(complejo)) {
		if (this->nodo->item == complejo) {
			if (this->nodo->de.EsVacio() && this->nodo->iz.EsVacio()) {
				delete nodo;
				nodo = NULL;

				borrado = true;
			} else {
				if (this->nodo->iz.EsVacio() || this->nodo->de.EsVacio()) {
					if (this->nodo->iz.EsVacio()) { //Sin subarbol izq
						TNodoABB *aux;

						aux = nodo;
						nodo = nodo->de.nodo;
						aux->de.nodo = NULL;
						delete aux;
						aux = NULL;

						borrado = true;
					} else { //Sin subarbol der
						TNodoABB *aux;

						aux = nodo;
						nodo = nodo->iz.nodo;
						aux->iz.nodo = NULL;
						delete aux;
						aux = NULL;

						borrado = true;
					}
				} else { //Cuando tiene dos subarboles hijo.
					TNodoABB *anterior, *posterior, *actual;

					actual = this->nodo;
					posterior = this->nodo->iz.nodo; //Tenemos que sustituir por algun nodo del subarbol iz
					anterior = this->nodo;

					if (posterior->de.EsVacio()) { //No hay subarbol der por lo tanto este es el mayor.
						actual->item = posterior->item;
						actual->iz.nodo = posterior->iz.nodo;
					} else { //Buscamos iterativamente el mayor de la ezquierda (estara en una hoja lo mas a la derecha posible).
						while (!posterior->de.EsVacio()) {
							anterior = posterior;
							posterior = posterior->de.nodo;
						}

						anterior->de.nodo = posterior->iz.nodo;
						actual->item = posterior->item;
					}

					borrado = true;
				}
			}

			borrado = true;
		} else {
			if (this->esMayor(complejo))
				borrado = this->nodo->de.Borrar(complejo);
			else
				borrado = this->nodo->iz.Borrar(complejo);
		}
	}

	return borrado;


}


// Devuelve TRUE si el elemento está en el árbol, FALSE en caso contrario
bool TABBCom::Buscar(const TComplejo & t) const {
if(!this->EsVacio()){
	if(this->nodo->item == t){
		return true;
	}else{
		
		if(this->nodo->iz.Buscar(t)){// si t es mayor que el actual,  es por la derecha
			return true;

		}else if(this->nodo->de.Buscar(t)){// si no, es por la izquierda
			return true;
		}else{
			return false;
		}
	}

}

}

// Devuelve el elemento en la raíz del árbol
TComplejo TABBCom::Raiz() const{

	if (this->EsVacio()){
		TComplejo a;
		return a;
	}else{
		return nodo->item;
	}

}

// Devuelve la altura del árbol (la altura de un árbol vacío es 0)
int TABBCom::Altura() const {

	if(this->EsVacio()){
		return 0;
	}else{
		return 1+max(this->nodo->de.Altura(),this->nodo->iz.Altura());
	}

}

// Devuelve el número de nodos del árbol (un árbol vacío posee 0 nodos)
int TABBCom::Nodos() const {

	if(this->EsVacio()){
		return 0;
	}else{
		return 1+this->nodo->de.Nodos()+this->nodo->iz.Nodos();
	}

}

// Devuelve el número de nodos hoja en el árbol (la raíz puede ser nodo hoja)
int TABBCom::NodosHoja() const {
	if(!EsVacio()){ 
		if(!this->nodo->de.EsVacio() || !this->nodo->iz.EsVacio()){
			return this->nodo->de.NodosHoja()+this->nodo->iz.NodosHoja();
		}else{
			return 1;
		}
	}else{
		return 0;
	}
}

// Devuelve el recorrido en inorden.
TVectorCom TABBCom::Inorden() const {

	int posicion = 1;

	TVectorCom v(this->Nodos());
	InordenAux(v,posicion);
	return v;

}

// Devuelve el recorrido en preorden
TVectorCom TABBCom::Preorden() const {

	int posicion = 1;

	TVectorCom v(this->Nodos());
	PreordenAux(v,posicion);
	return v;

}

// Devuelve el recorrido en postorden
TVectorCom TABBCom::Postorden() const {

	int posicion = 1;

	TVectorCom v(this->Nodos());
	PostordenAux(v,posicion);
	return v;

}

// Devuelve el recorrido en niveles
TVectorCom TABBCom::Niveles() const {
	TVectorCom v(this->Nodos());
	int posicion = 1;

	NivelesAux(v, posicion);

	return v;
}


void TABBCom::NivelesAux(TVectorCom &v, int &pos) const {

	if(!this->EsVacio()){
		std::queue<TNodoABB*> mycola;
		TNodoABB *aux = this->nodo;
		mycola.push(aux);

		while(!mycola.empty()){
			TNodoABB *temp = mycola.front();
			v[pos] = (*temp).item;
			pos++;

			mycola.pop();

			if(!(*temp).iz.EsVacio()){
				mycola.push((*temp).iz.nodo);
			}
			if(!(*temp).de.EsVacio()){
				mycola.push((*temp).de.nodo);
			}
		}
	}

}

// Sobrecarga del operador salida
ostream & operator<<(ostream &salida, const TABBCom &t) {
	salida << t.Niveles();

	return salida;
}



/////////////////////////////////FINAL CLASE TABBCOM
















/////////////////////////////////CLASE TNodoABB
// Constructor por defecto.
TNodoABB::TNodoABB(){

/*
	this->item = new TComplejo();
	this->iz = new TABBCom();
	this->de = new TABBCom();
*/

}

// Constructor de copia
TNodoABB::TNodoABB(const TNodoABB & t){

	this->item = t.item;
	this->iz = t.iz;
	this->de = t.de;

}

// Destructor
TNodoABB::~TNodoABB(){

}

// Sobrecarga del operador asignación
TNodoABB &TNodoABB::operator=(const TNodoABB &t){

	if(this != &t){
		this->~TNodoABB();//Hago que no haya nada (llamo al destructor)

		this->item = t.item;
		this->de = t.de;
		this->iz = t.iz;
	}
}


/////////////////////////////////FINAL CLASE TNodoABB