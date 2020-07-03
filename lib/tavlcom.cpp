//Alejandro Pareja Penalva - 15419139P

#include "tavlcom.h"

//Clase TNODOAVL


TNodoAVL::TNodoAVL() {
	this->fe = 0;
}

TNodoAVL::TNodoAVL(const TNodoAVL &t) {
	this->item = t.item;
	this->iz = t.iz;
	this->de = t.de;
	this->fe = t.fe;
}

TNodoAVL::~TNodoAVL() {
	this->fe = 0;
}

TNodoAVL & TNodoAVL::operator=(const TNodoAVL &t) {
	if (this != &t) {
		this->~TNodoAVL();

		TNodoAVL(t);
	}

	return *this;
}










//CLASE TAVLCOM
// Constructor por defecto
TAVLCom::TAVLCom() {
	this->raiz = NULL;
}

void TAVLCom::CopiarAVL(const TAVLCom &arbol) {
	if (!arbol.EsVacio()) {
		TNodoAVL *aux = new TNodoAVL;
		aux->fe = arbol.raiz->fe;
		aux->item = arbol.raiz->item;
		this->raiz = aux;
		this->raiz->iz.CopiarAVL(arbol.raiz->iz);
		this->raiz->de.CopiarAVL(arbol.raiz->de);
	} else{
		this->raiz = NULL;
	}
}

// Constructor de copia
TAVLCom::TAVLCom(const TAVLCom &t) {
	this->CopiarAVL(t);
}

// Destructor
TAVLCom::~TAVLCom() {
	while (!this->EsVacio()) {
		TNodoAVL *aux;
		aux = this->raiz;

		this->raiz->iz.~TAVLCom();
		this->raiz->de.~TAVLCom();

		delete this->raiz;
		this->raiz = NULL;
	}
}

// Sobrecarga del operador asignación
TAVLCom & TAVLCom::operator=(const TAVLCom & t) {
	if(this!= &t){
		(*this).~TAVLCom();//si son distintos se copian
		CopiarAVL(t);
	}
	return *this;
}

// Sobrecarga del operador igualdad
bool TAVLCom::operator==(const TAVLCom & arbol) const {

	if(this->raiz==NULL && arbol.raiz==NULL)//Si alguno de lso dos es null, es true
		return true;//si los dos son nulos true
	else{//sino, si...
		if((this->raiz==NULL && arbol.raiz!=NULL)||(this->raiz!=NULL&&arbol.raiz==NULL))//Si uno es nulo y el otro no, es false
			return false;//devuelvo false
		else{
			if((this->raiz->item == arbol.raiz->item) && (this->raiz->fe == arbol.raiz->fe)){//si el primer nodo es igual y el factorequilibrio tambien
				if((this->raiz->iz == arbol.raiz->iz) && (this->raiz->de == arbol.raiz->de))//si las dos raices son iguales true
					return true;//devuelvo true
				else
					return false;//si no,devuelvo false
			}
			else//si el primer nodo no es igual o el factor equilibrio es distinto false
				return false;
		}
	}
	return false;
}

// Sobrecarga del operador desigualdad
bool TAVLCom::operator!=(const TAVLCom & t) const {
	return !this->operator==(t);
}

// Devuelve TRUE si el árbol está vacío, FALSE en caso contrario
bool TAVLCom::EsVacio() const {
		if (this->raiz){//false si está lleno si es TRUE se devuelve FALSE
			return false;
		}else{//devuelvo true si no está lleno.
			return true;
		}	
}

// Inserta el elemento TComplejo en el árbol
bool TAVLCom::Insertar(const TComplejo & t) {

	bool crece = false;
	return InsertarAux(t,crece);

}

bool TAVLCom::InsertarAux(const TComplejo & tc, bool & crece) {

	bool creceHijoIz=false, creceHijoDe=false, insercionOK=false;
	TAVLCom a,b,c,d;
	TComplejo tc_aux;

	if(this->EsVacio()){ //Si es vacio, 
		this->raiz = new TNodoAVL(); //directamente creo un nuevo TNodoAVL y lo asigno a la raíz.
		this->raiz->item = tc; // y el complejo actual lo asigno tambien al que he creado
		crece = true;
		return true;
	}else{
		if(tc == this->raiz->item){//si ya existe no anado
			crece = false;
			return false;
		}else{
			if(this->esMayor(tc)){//si es mayor va a la derecha
				if(raiz->de.Insertar(tc)){//llamada recursiva hasta llegar a esvacio
					raiz->fe=raiz->de.Altura()-raiz->iz.Altura();//calcular fe
					if(raiz->fe>1){//si fe es mayor q 1 hay que rotar
						if(raiz->de.raiz->fe==1)
							moverDD(a,b,c,d,tc_aux);

						if(raiz->de.raiz->fe==-1)
							moverDI(a,b,c,d,tc_aux);
					}
					crece = true;
					return true;
				}
				crece = false;
				return false;
			}
			else{//si es menor va a la izquierda
				if(raiz->iz.Insertar(tc)){//llamada recursiva hasta llegar a esvacio
					raiz->fe=raiz->de.Altura()-raiz->iz.Altura();//calcular fe
					if(raiz->fe<-1){//si fe es menor q -1 hay que rotar
						if(raiz->iz.raiz->fe==-1)
							moverII(a,b,c,d,tc_aux);
						if(raiz->iz.raiz->fe==1)
							moverID(a,b,c,d,tc_aux);
					}
					crece = true;
					return true;
				}else{
					return false;
				}
			}
		}
	}

}

bool TAVLCom::esMayor(const TComplejo & complejo) const {

	bool may = false;

	if (complejo.Mod() == this->raiz->item.Mod()) {
		if (complejo.Re() == this->raiz->item.Re()) {
			if (complejo.Im() == this->raiz->item.Im()) //si mod, re e im son iguales -> false
				may = false;
			else {
				if (complejo.Im() < this->raiz->item.Im())
					may = false;
				if (complejo.Im() > this->raiz->item.Im())
					may = true;;
			}
		} else {
			if (complejo.Re() < this->raiz->item.Re())
				may = false;
			if (complejo.Re() > this->raiz->item.Re())
				may = true;
		}
	} else {
		if (complejo.Mod() < this->raiz->item.Mod())
			may = false;
		if (complejo.Mod() > this->raiz->item.Mod())
			may = true;
	}

	return may;
}

// Devuelve TRUE si el elemento está en el árbol, FALSE en caso contrario
bool TAVLCom::Buscar(const TComplejo &t) const {

if(!this->EsVacio()){
	if(this->raiz->item == t){
		return true;
	}else{
		if(this->raiz->iz.Buscar(t)){// si t es mayor que el actual,  es por la derecha
			return true;
		}else if(this->raiz->de.Buscar(t)){// si no, es por la izquierda
			return true;
		}else{
			return false;
		}
	}

}else{
	return false;
}

}

TComplejo TAVLCom::mayorIzquierda(const TAVLCom & arbolAVL){
	if(arbolAVL.raiz->de.raiz != NULL){ // si el de la derecha, es diferente de null
		mayorIzquierda(arbolAVL.raiz->de); //llamo recursivamente al método otra vez.
	}else{
		return arbolAVL.raiz->item;
	}
}

TComplejo TAVLCom::mayorDerecha(const TAVLCom & arbolAVL){
	if(arbolAVL.raiz->iz.raiz != NULL){ // si el de la derecha, es diferente de null
		mayorDerecha(arbolAVL.raiz->iz); //llamo recursivamente al método otra vez.
	}else{
		return arbolAVL.raiz->item;
	}
}


// Borra un TComplejo del árbol AVL
bool TAVLCom::Borrar(const TComplejo &complejo) {
	bool borrado = false;
	borrado = BorrarAux(complejo);
	if (!this->EsVacio()) {
		//actualizacionFactorEquilibrio();
		//comprobarFe();
	}
	return borrado;

}

void TAVLCom::actualizacionFactorEquilibrio() {

	if (!this->EsVacio()) {

		this->raiz->fe = raiz->de.Altura() - this->raiz->iz.Altura();

		if (!this->raiz->de.EsVacio()){

			this->raiz->de.actualizacionFactorEquilibrio();

		}else if (!this->raiz->iz.EsVacio()){

			this->raiz->iz.actualizacionFactorEquilibrio();
		}
	}
}




//Borrar Aux
bool TAVLCom::BorrarAux(const TComplejo & t){
	bool completado;
	TAVLCom a,b,c,d;
	TNodoAVL *aux_nodo;
	TComplejo tc_aux;

	if(EsVacio())
		return false;
	else{//si arbol vacio no puedo borrar nada
		if(raiz->item==t){
			if(this->raiz->de.EsVacio() && this->raiz->iz.EsVacio()){//si estamos en una hoja lo podemos quitar si mas
				delete raiz;
				this->raiz=NULL;
				return true;
			}
			else{//si no es hoja sustituimos x el mayor de la izquierda
				if(!raiz->iz.EsVacio()){//si tiene hijo a la izq
					aux_nodo=raiz->iz.raiz;
					while(!aux_nodo->de.EsVacio()){//mientras que no lleguemos al mayor del iz
						aux_nodo=aux_nodo->de.raiz;
					}
					tc_aux=raiz->item;
					raiz->item=aux_nodo->item;
					aux_nodo->item=tc_aux;
					completado=raiz->iz.BorrarAux(t);
				}
				else{//si no tiene hijo iz, solo tiene uno derecho si no es hoja
					aux_nodo=raiz->de.raiz;
					tc_aux=raiz->item;
					raiz->item=aux_nodo->item;
					aux_nodo->item=tc_aux;
					completado=raiz->de.BorrarAux(t);
				}
			}

		}
		else{
			if(t.Mod()>raiz->item.Mod() ||//si el modulo es mayor o si el modulo es igual i la parte real es mayor
					(t.Mod()==raiz->item.Mod()&&t.Re()>raiz->item.Re())//busco a la derecha pq el tc es mayor
			){
				completado=raiz->de.BorrarAux(t);
			}
			else
				completado=raiz->iz.BorrarAux(t);
		}

		if(completado){
			//comprobar que sigue ordenado

			raiz->fe=raiz->de.Altura()-raiz->iz.Altura();
			if((raiz->fe==2 && raiz->de.raiz->fe==0)||(raiz->fe==2 && raiz->de.raiz->fe==1)){
				moverDD(a,b,c,d,tc_aux);
			}
			if(raiz->fe==2&&raiz->de.raiz->fe==-1){
				moverDI(a,b,c,d,tc_aux);
			}

			if((raiz->fe==-2 && raiz->iz.raiz->fe==0)||(raiz->fe==-2 && raiz->iz.raiz->fe==-1)){
				moverII(a,b,c,d,tc_aux);
			}
			if(raiz->fe==-2&&raiz->iz.raiz->fe==1){
				moverID(a,b,c,d,tc_aux);
			}
		}
		return completado;
	}

}

// Devuelve la altura del árbol (la altura de un árbol vacío es 0)
int TAVLCom::Altura() const {

	if(this->EsVacio()){
		return 0;
	}else{
		return 1+max(this->raiz->de.Altura(),this->raiz->iz.Altura());
	}
}

// Devuelve el elemento TComplejo raíz del árbol AVL
TComplejo TAVLCom::Raiz() const {

	if (this->EsVacio()){
		TComplejo a;
		return a;
	}else{
		return raiz->item;
	}
}

// Devuelve el número de nodos del árbol (un árbol vacío posee 0 nodos)
int TAVLCom::Nodos() const {
	if(this->EsVacio()){
		return 0;
	}else{
		return 1+this->raiz->de.Nodos()+this->raiz->iz.Nodos();
	}
}

// Devuelve el número de nodos hoja en el árbol (la raíz puede ser nodo hoja)
int TAVLCom::NodosHoja() const {
	if(!EsVacio()){ 
		if(!this->raiz->de.EsVacio() || !this->raiz->iz.EsVacio()){
			return this->raiz->de.NodosHoja()+this->raiz->iz.NodosHoja();
		}else{
			return 1;
		}
	}else{
		return 0;
	}
}

// Devuelve el recorrido en inorden sobre un vector
TVectorCom TAVLCom::Inorden() const {
	int posicion = 1;

	TVectorCom v(this->Nodos());

	InordenAux(v,posicion);
	return v;
}

// Devuelve el recorrido en preorden sobre un vector
TVectorCom TAVLCom::Preorden() const {

	int posicion = 1;

	TVectorCom v(this->Nodos());
	PreordenAux(v,posicion);
	return v;

}

// Devuelve el recorrido en postorden sobre un vector
TVectorCom TAVLCom::Postorden() const {

	int posicion = 1;

	TVectorCom v(this->Nodos());
	PostordenAux(v,posicion);
	return v;
}

void TAVLCom::InordenAux(TVectorCom &t, int &a) const {
	if(!this->EsVacio()){
		if(this->raiz->de.EsVacio() && this->raiz->iz.EsVacio()){//Si los dos raiz de los lados son vacios, es un nodo hoja
			t[a] = this->raiz->item; //Si es raiz hoja, lo añado al vector de complejos.
			a = a+1; //incremento el flag para el vector.
		}else{ //si el de la izquierda o derecha no son vacíos
			this->raiz->iz.InordenAux(t,a);//pruebo por la izquierda
			t[a] = this->raiz->item;///Lo asigno
			//incremento a
			a = a+1;
			this->raiz->de.InordenAux(t,a);//pruebo por la derecha ahora
		}
	}
}

void TAVLCom::PreordenAux(TVectorCom & t, int & a) const {

	if(!this->EsVacio()){
		if(this->raiz->de.EsVacio() && this->raiz->iz.EsVacio()){ //Si es hoja
			t[a] = this->raiz->item; //lo añado al vector y acabo recurerncia
			a = a+1;
		}else{
			t[a] = this->raiz->item;
			a = a+1;
			this->raiz->iz.PreordenAux(t,a);
			this->raiz->de.PreordenAux(t,a);
		}
	}else{

	}
}

void TAVLCom::PostordenAux(TVectorCom & t, int & a) const {

	if(!this->EsVacio()){
		if(this->raiz->de.EsVacio() && this->raiz->iz.EsVacio()){
			t[a] = this->raiz->item;
			a = a+1;
		}else{
			this->raiz->iz.PostordenAux(t,a);
			this->raiz->de.PostordenAux(t,a);
			t[a] = this->raiz->item;
			a = a+1;
		}
	}else{

	}
}

// Sobrecarga del operador salida
ostream & operator<<(ostream &salida, TAVLCom &arbol) {
	salida << arbol.Inorden();

	return salida;
}


void TAVLCom::moverII(TAVLCom &a,TAVLCom &b,TAVLCom &c,TAVLCom &d, TComplejo &tc_aux){//rotacion II

	a = raiz->iz.raiz->iz;
	b = raiz->iz.raiz->de;
	c = raiz->de;
	tc_aux = raiz->item;
	raiz->item = raiz->iz.raiz->item;

	if(raiz->de.EsVacio()){
		raiz->de.Insertar(tc_aux);
	}
	else{
		raiz->de.raiz->item = tc_aux;
	}

	raiz->iz = a;
	raiz->de.raiz->iz = b;
	raiz->de.raiz->de = c;
	raiz->de.raiz->fe = raiz->de.raiz->de.Altura()-raiz->de.raiz->iz.Altura();
	raiz->fe = raiz->de.Altura()-raiz->iz.Altura();
}

void TAVLCom::moverID(TAVLCom &a,TAVLCom &b,TAVLCom &c,TAVLCom &d, TComplejo &tc_aux){//rotacion ID

	a = raiz->iz.raiz->iz;
	b = raiz->iz.raiz->de.raiz->iz;
	c = raiz->iz.raiz->de.raiz->de;
	d = raiz->de;
	tc_aux = raiz->item;

	raiz->item = raiz->iz.raiz->de.raiz->item;

	if(raiz->de.EsVacio()){
		raiz->de.Insertar(tc_aux);
	}
	else{
		raiz->de.raiz->item = tc_aux;
	}

	raiz->iz.raiz->iz = a;
	raiz->iz.raiz->de = b;
	raiz->de.raiz->iz = c;
	raiz->de.raiz->de = d;
	raiz->iz.raiz->fe = raiz->iz.raiz->de.Altura()-raiz->iz.raiz->iz.Altura();
	raiz->de.raiz->fe = raiz->de.raiz->de.Altura()-raiz->de.raiz->iz.Altura();
	raiz->fe = raiz->de.Altura()-raiz->iz.Altura();

}


void TAVLCom::moverDI(TAVLCom &a,TAVLCom &b,TAVLCom &c,TAVLCom &d, TComplejo &tc_aux){//rotacion DI

	a = raiz->iz;
	b = raiz->de.raiz->iz.raiz->iz;
	c = raiz->de.raiz->iz.raiz->de;
	d = raiz->de.raiz->de;
	tc_aux = raiz->item;
	raiz->item = raiz->de.raiz->iz.raiz->item;

	if(raiz->iz.EsVacio()){
		raiz->iz.Insertar(tc_aux);
	}
	else{
		raiz->iz.raiz->item = tc_aux;
	}

	raiz->iz.raiz->iz = a;
	raiz->iz.raiz->de = b;
	raiz->de.raiz->iz = c;
	raiz->de.raiz->de = d;
	raiz->iz.raiz->fe = raiz->iz.raiz->de.Altura()-raiz->iz.raiz->iz.Altura();
	raiz->de.raiz->fe = raiz->de.raiz->de.Altura()-raiz->de.raiz->iz.Altura();
	raiz->fe = raiz->de.Altura()-raiz->iz.Altura();
}


void TAVLCom::moverDD( TAVLCom & a,TAVLCom & b,TAVLCom & c,TAVLCom & d, TComplejo & tc_aux ) {

	a = raiz->iz;
	b = raiz->de.raiz->iz;
	c = raiz->de.raiz->de;
	tc_aux = raiz->item;
	raiz->item = raiz->de.raiz->item;

	if(raiz->iz.EsVacio()){
		raiz->iz.Insertar(tc_aux);
	}
	else{
		raiz->iz.raiz->item = tc_aux;
	}

	raiz->de =c;
	raiz->iz.raiz->iz = a;
	raiz->iz.raiz->de = b;
	raiz->iz.raiz->fe = raiz->iz.raiz->de.Altura()-raiz->iz.raiz->iz.Altura();
	raiz->fe = raiz->de.Altura()-raiz->iz.Altura();

}