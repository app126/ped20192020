#include "tlistacom.h"

/////////////////////////////////TLISTANODO
/**INICIO FORMA CANÓNICA**/
//Constructor por defecto.
TListaNodo::TListaNodo(){
	//Reservo memoria dinamicamente con new TComplejo();
	//this->e = new TComplejo();

	//¿QUé hago con los punteros anterior y siguiente?
	//this->anterior = NULL;
	//this->siguiente = NULL;

	TComplejo init;
	e=init;
	anterior=NULL;
	siguiente=NULL;
}

//Constructor copia
TListaNodo::TListaNodo(const TListaNodo & copia){
	//¿Lo llamo así o con el constructor copia de TComplejo?
	this->e = copia.e;

	//¿Qué hago con los punteros anterior y siguiente?
	this->anterior = copia.anterior;
	this->siguiente = copia.siguiente;

}

//Destructor
TListaNodo::~TListaNodo(){
	//this->e = ~TComplejo();

	//¿Los pongo a NULL para que no apunten a nada?
	this->anterior = NULL;
	this->siguiente = NULL;

}

//Sobrecarga del operador de asignacion.
TListaNodo & TListaNodo::operator=(const TListaNodo & t){

	if(this != &t){
		//¿Lo hago así o lo copio con el constructor copia?
		this->e = TComplejo(e);
		//this->e = t.e;
		this->anterior = t.anterior;
		this->siguiente = t.siguiente;
	}
}
/////////////////////////////////FINAL TLISTANODO














/////////////////////////////////TLISTAPOS
/////////////////////////////////INICIO FORMA CANONICA
//Constructor por defecto.
TListaPos::TListaPos(){
	//¿Lo defino a NULL? Para después asignarle una lista? o se asigna con alguna lista dinámica?
	this->pos = NULL;
}


//Constructor copia
TListaPos::TListaPos(const TListaPos & copia){
	this->pos = copia.pos;
}

//Destructor
TListaPos::~TListaPos(){
	if(pos){ //Si existe..
		//delete [] pos; //pos lo borro con delete.
		pos = NULL; // y despues lo asigno a null para que no se me quede apuntando a ninguna direcicon de memoria rara
	}
}

//Sobrecarga del operador de asignacion.
TListaPos & TListaPos::operator=( const TListaPos & t){
	if(this != &t){
		this->pos = t.pos;
	}
}
//////////////            FIN FORMA CANONICA


/////////////           INICIO METODOS
//Sobrecarga del operador de igualdad
bool TListaPos::operator==(const TListaPos & t) const{
	if(this->pos == t.pos){
		return true;
	}
}

//Sobrecarga del operador de desigualdad
bool TListaPos::operator!=(const TListaPos & t) const{
	return !(*this == t);
}

//Devuelve la posición anterior
TListaPos TListaPos::Anterior() const{
	if(this->EsVacia() || this->pos->anterior == NULL){
		TListaPos aux;
		return aux;
	}else{
		TListaPos aux;
		aux.pos = this->pos->anterior;
		return aux;
	}
}

//Devuelve la posicion siguiente
TListaPos TListaPos::Siguiente() const{

	if(this->EsVacia() || this->pos->siguiente == NULL){
		TListaPos aux;
		return aux;
	}else{
		TListaPos aux;
		aux.pos = this->pos->siguiente;
		return aux;
	}

}

//Devuelve TRUE si la posición no apunta a una lista, FALSE en caso contrario.
bool TListaPos::EsVacia() const{
		if(this->pos == NULL){
			return true;
		}
		return false;
}

///////////////////////////////FINAL TLISTAPOS











//////////////////////////////INICIO TLISTACOM
//Forma canonica
//Constructor por defecto.
TListaCom::TListaCom(){
	this->primero = NULL;
	this->ultimo = NULL;

}

//Constructor copia
TListaCom::TListaCom(const TListaCom & lista){

	primero = ultimo = NULL;
	TListaPos pos = lista.Ultima();

	while(!pos.EsVacia()){
		this->InsCabeza(pos.pos->e);
		pos = pos.Anterior();
	}

	//this->Copia(t);

}

//Destructor
TListaCom::~TListaCom(){

	//Creo dos auxiliares para recorrerlos
	TListaPos prim = this->Primera();
	TListaPos ult = prim.Siguiente();

	//Uno se asigna a primera y cogemos como ultimo el siguiente.
	//prim = this->Primera();
	//ult = prim->Siguiente();

	//Mientras que el siguiente no sea vacio..
	while(!ult.EsVacia()){

		//Borramos el pos del ultimo
		delete prim.pos;

		//Y lo asignamos al primero
		prim = ult;

		//Despues asignamos 
		ult = prim.Siguiente();

	}

	this->primero = NULL;
	this->ultimo = NULL;
}

//Sobrecarga del operador de asignacion
TListaCom & TListaCom::operator=(const TListaCom & lista){

		if(this != &lista){
			this->~TListaCom();

			primero = ultimo = NULL;
			TListaPos pos = lista.Ultima();

			while(!pos.EsVacia()){
				this->InsCabeza(pos.pos->e);
				pos = pos.Anterior();
			}
		}

		return *this;

	/*
	if(&t != NULL && this != &t){
		this->Copia(t);
	}
	*/

}
//Final forma canonica.

//Metodos

//Sobrecarga del operador de igualdad
bool TListaCom::operator==(const TListaCom & t) const{

	//Inicio un aux iguales a true, para controlar si es true o false, si son iguales o no.
	bool iguales = true;

	//Si tienen la misma longitud, empezamos a hacer cosas, eso es que en principio
	// podrían ser iguales..
	if(this->Longitud() == t.Longitud()){
		//Me hago una auxiliar para comparar la actual
		TListaPos auxEsta = this->Primera();

		//Me hago otro auxiliar para coger el primer elemento que se me envia por parametros
		TListaPos auxT = t.Primera();

		do{ //Tengo que comparar una con otra, mientras que no sean 

			if(auxEsta != auxT){
				iguales = false;
			}else{
				auxEsta.Siguiente();
				auxT.Siguiente();
			}

		}while(!auxEsta.EsVacia()); //Se para cuándo sea vacía
	}else{
		iguales = false;
	}

return iguales;
}

//Sobrecarga del operador de desigualdad
bool TListaCom::operator!=(const TListaCom & t)const{
	return !(*this == t);
}

//Sobrecarga del operador suma
TListaCom TListaCom::operator+(const TListaCom & t)const{
	//Creo una copia de la lista que me mandan
    TListaCom auxCom(t);

    //Me guardo el último de la lista para ir de atrás para alante.
    TListaPos pos = this->Ultima();

    //Si no es vacio, lo inserto en la copia que me he hecho, una vez por si es uno.
    if(!pos.EsVacia()){
    	//Lo inserto en el top de la copia que me he hecho.
    	auxCom.InsCabeza(pos.pos->e);
    }

    //Mientras que la anterior no sea vacia,
    while(!pos.Anterior().EsVacia()){
    	//Me asigno la anterior.
    	pos = pos.Anterior();
    	//Y la vuelvo a poner en la lista.
    	auxCom.InsCabeza(pos.pos->e);
    }
    
    return auxCom;
}

//Sobrecarga del operador resta.
TListaCom TListaCom::operator-(const TListaCom & t) const{

	//Me hago la lista nueva para meter los que no contienen.
	TListaCom nueva;

	//Me cojo el último elemento
	TListaPos ultimo = this->Ultima();

	//Si la lista que me pasan, es vacía, devuelvo la que ya tengo.
	if(t.EsVacia()){
		nueva = *this;
	}else{ //Si no es vacia
		//Compruebo que NO lo encuentre y que no sea vacia, si no está y es vacia,
		if(!t.EsVacia() && !t.Buscar(ultimo.pos->e)){
			//Lo inserto.
			nueva.InsCabeza(ultimo.pos->e);
		}

		//Ahora vuelvo a iterar, pero de atrás para alante,
		// si el anterior del que tenemos no es vacio....
		while(!ultimo.Anterior().EsVacia()){
			//Asigno el anterior para tenerlo actualmente.
			ultimo = ultimo.Anterior();
			//Compruebo que NO lo encuentre 
			if(!t.Buscar(ultimo.pos->e)){
			//Lo inserto.
			nueva.InsCabeza(ultimo.pos->e);
		}

		}
	}
	return nueva;	
}

//Devuelve true si la lista está vacía,false en caso contrario.
bool TListaCom::EsVacia() const{

	if(this->primero == NULL || this->ultimo == NULL){
    	return true;
	}
    return false;

}

//Inserta el elemento en la cabeza de la lista.
bool TListaCom::InsCabeza(const TComplejo & t){

	/*
	//inserta elemento a la cabeza de la lista
	TListaNodo *aux;
	aux=new TListaNodo();
	if(!aux)
		return false;


	aux->siguiente=primero;

	if(primero!=NULL)
		primero->anterior=aux;//apunto el nodo anterior del primero a aux
	else
		ultimo=aux;
	aux->e=tc;
	primero=aux;
	return true;	
	*/

/*
    TListaNodo *nuevo;
    nuevo = new TListaNodo();
    
    if(nuevo){
    	nuevo->e = complejo;

        if(this->EsVacia()){//La lista esta vacia.
           	nuevo->anterior = NULL;
       	   	nuevo->siguiente = NULL;
       	   	this->ultimo = nuevo;
       	   	this->primero = nuevo;

       	    return true;
        }
        else{//La lista contiene nodos.
            TListaPos aux = this->Primera();

        	nuevo->anterior = NULL;
        	nuevo->siguiente = aux.pos;
        	aux.pos->anterior = nuevo;
        	this->primero = nuevo;

        	return true;
        }
    }
    else
    	return false;*/


	
	TListaNodo *n;
	n = new TListaNodo();

	if(!n){
		cerr << "Error al reservar memoria" << endl;
		return false;
	}else{ 

		n->siguiente = this->primero;
	//aux->siguiente=primero;

	if(this->primero!=NULL)
		primero->anterior=n;//apunto el nodo anterior del primero a aux
	else
		ultimo=n;
	n->e=t;
	primero=n;
	return true;

	}
	
}

//Inserta el elemento a la izquierda de la posición indicada.
bool TListaCom::InsertarI(const TComplejo & tc, const TListaPos & t){


	TListaPos auxPos = this->Primera();

	//Compruebo que el objeto TListaPos no es vacio y que la lista actual sea vacia.
	//al haber sólo uno, se inserta con InsCabeza
	if(t.EsVacia() || this->EsVacia()){
		return false;
		/*
		this->InsCabeza(tc);
		return true;
		*/
	}else if(this->Longitud() == 1){ //Si la lista tiene un solo elemento

		return this->InsCabeza(tc); //lo inserto directamente en cabeza

	}else{
		//Si la posicion que me pasan es la primera, la inserto en la cabeza
		if(t == auxPos){
			return this->InsCabeza(tc);
		}else{ //Si no, muevo para insertarlo.

			//Creo un nuevo nodo
			TListaNodo *nodo = new TListaNodo();

			//se comprueba si se ha podido reservar memoria para tlistanodo nodo
			if(nodo){
				//asigno el tcomplejo al nodo
				nodo->e = tc;

				//al nodo anterior (tlistanodo) le asigno el anterior, para hacer hueco
				nodo->anterior = t.pos->anterior;

				//al siguiente asigno el actual, para que corra la lista
				nodo->siguiente = t.pos;

				//asigno el nodo al anterior del siguiente (actual)
				t.pos->anterior->siguiente = nodo;

				//asigno el nodo al anterior
				t.pos->anterior = nodo;

				return true;

			}else{//Si no se ha podido reservar memoria para un nuevo nodo, se devuelve false
				return false;
			}
		}
	}

}

//Inserta el elemento a la derecha de la posicion indicada.
bool TListaCom::InsertarD(const TComplejo & tc,const TListaPos & t){


	TListaPos auxPos = this->Primera();

	//Compruebo que el objeto TListaPos no es vacio y que la lista actual sea vacia.
	//al haber sólo uno, se inserta con InsCabeza
	if(t.EsVacia() || this->EsVacia()){
		return false;
		/*
		this->InsCabeza(tc);
		return true;
		*/
	}else if(this->Longitud() == 1){ //Si la lista tiene un solo elemento

		return this->InsCabeza(tc); //lo inserto directamente en cabeza

	}else{//Si no, muevo para insertarlo

		//Creo un nuevo nodo
		TListaNodo *nodo = new TListaNodo();

		//se comprueba si se ha podido reservar memoria para tlistanodo nodo
		if(nodo){

			//Asigno el tcomplejo al nodo
			nodo->e = tc;

			//al anterior, le asigno el que me pasan
			nodo->anterior = t.pos;

			//Al siguiente le asigno el siguiente del que nos pasan
			nodo->siguiente = t.pos->siguiente;

			//Lo pongo a la derecha del t actual que nos mandan.
			t.pos->siguiente = nodo;

			//Si el siguiente no es el ultimo.
			if(t.pos->siguiente != NULL){
				//Asigno al actual el nodo
				t.pos->siguiente->anterior = nodo;

				//Asigno al siguiente el actual
				t.pos->siguiente = nodo;
			}else{
				//Si es el último, lo asigno, por que es el último y no quedan mas
				this->ultimo = nodo;
			}

		}

	}


}

//Busca y borra la primera ocurrencia del elemento
bool TListaCom::Borrar( const TComplejo & t){

	bool borrado = false;

	//Significa que no esta vacia y que esta el complejo.
	if(!this->EsVacia() && this->Buscar(t)){

		//Cojo el primer elemento que tengo.
		TListaPos aux = this->Primera();

		//Si hay más de uno:
		if(this->Longitud() > 1){
			//Si es el mismo que el primero, es que es el que hay que borrar.
			//Pero significa que hay más de uno, por lo tanto, modifico el puntero 
			//siguiente para que apunte al actual y viceversa
			if(aux.pos->e == t){
				//Me guardo el siguiente en pos
				TListaPos pos = aux.Siguiente();
				//Destruyo el actual
				aux.pos->~TListaNodo();

				//Asigno pos, que será el siguiente, ya que lo he guardado anteriormente
				this->primero = pos.pos;

				//Pongo el anterior de pos a NULL por que ya no me va a servir.
				pos.pos->anterior = NULL;

				return true;
			}

			//Si he llegado aqui es por que no es el primero y no es el unico.
			//Mientras que el siguiente no sea vacio
			while(!aux.Siguiente().EsVacia()){

				//Me guardo la posicion siguiente en pos, que ahora es la actual.
				aux.pos = aux.pos->siguiente;

				TListaPos auxUlt = this->Ultima();
				//Si estamos aqui, significa que hemos coincidido con uno y es el ultimo.
				if(aux.pos->e == t && aux == auxUlt){

					TListaPos pos = aux.Anterior();
					aux.pos->~TListaNodo();
					pos.pos->siguiente = NULL;
					this->ultimo = pos.pos;

					return true;

				}else{//Si no es que estamos en otro nodo
					//Y si es el mismo.
					if(aux.pos->e == t){

						//Me hago dos auxiliares para el anterior y el siguiente.
						TListaPos pre = aux.Anterior();
						TListaPos post = aux.Siguiente();

						//Destruyo el actual
						aux.pos->~TListaNodo();

						//Asigno el anterior al siguiente
						pre.pos->siguiente = post.pos;
						//Al anterior asigno el actual pre.pos
						post.pos->anterior = pre.pos;

						return true;
					}
				}

			}			
		}else if(this->Longitud() == 1 ){ //Si sólo hay uno
			//Si es el mismo que el primero, es que es el que hay que borrar.
			if(aux.pos->e == t){
				this->~TListaCom();
				return true;
			}else{
				return false;
			}
		}

	}else{
		return false;
	}

}

//Busca y borra todas las ocurrencias del elemento.
bool TListaCom::BorrarTodos( const TComplejo & t){

	//Si no es vacia
    if(!this->EsVacia()){

    	if(this->Buscar(t)){ //Si esta, paso a borrarlo

	    	//hacer mientras
			do{
				//lo borro
				this->Borrar(t);

			//Mientras que este el tcomplejo
			}while(this->Buscar(t));

	    	return true;

	    }else{//Si no esta no se puede borrar.
	    	return false;
	    }
    }
    
    return false;

}

//Borra el elemento que ocupa la posicion indicada.
bool TListaCom::Borrar(TListaPos & t){

bool borrado = false;
/*En el método “Borrar(TListaPos &)”, el paso por referencia es obligatorio, ya que una vez
eliminado el elemento, la posición tiene que pasar a estar vacía (no asignada a ninguna
lista).
Además, devuelve TRUE si el elemento se puede borrar (porque la posición apunta a un 
nodo de la lista) y FALSE en caso contrario. 
Hay que comprobar que el objeto TListaPos no es vacío.*/

	//Si la que me pasan no es vacia y la que tengo tampoco es vacia
	if(!t.EsVacia() && !this->EsVacia()){
		//Si encuentro el complejo con Buscar, lo borro y devuelvo true
		if(this->Buscar(t.pos->e)){
			//Borro el tcomplejo que le paso
			this->Borrar(t.pos->e);

			//Llamo al destructor de TListaPos, ya que pone  pos a NULL también.
			t.~TListaPos();
			borrado = true;
		}

	}else{
		borrado = false;
	}

	return borrado;

}



//Obtiene el elemento que ocupa la posicion indicada
TComplejo TListaCom::Obtener( const TListaPos & t) const {

	//Me hago un aux de TComplejo para devolverlo creado con el constructor por defecto
	// en caso de que haga falta.s
	TComplejo aux;

	//Cojo la primera de la lista actual.
	TListaPos auxPos = this->Primera();

	//Si cualquiera de las dos NO es vacia, tanto la mia como la que me pasan
	//hago las acciones.
	if(!t.EsVacia() && !this->EsVacia()){

		//Si el que tengo (que es el primero) es igual que TListaPos t (la que me pasan)
		if(auxPos == t){
			//Devuelvo el TComplejo dentro del TListaNodo que estoy.
			return auxPos.pos->e;
		}else{ //Si no, es que no es el primero y tengo que iterarlo.

			//Itero mientras que no sea vacía
			while( !auxPos.EsVacia()){

				
				//si aux es igual a la posicion que me envían..
				if(auxPos == t){
					//devuelvo el tcomplejo y se saldrá
					return auxPos.pos->e;
				}
				//Incremento una iteracion
				auxPos = auxPos.Siguiente();
			}
		}


	}else{//Si es vacia
		//Devuelvo el aux con el constructor de tcomplejo
		return aux;
	}

return aux;

}

//Devuelve true si el elemento está en la lista, false en caso contrario.
bool TListaCom::Buscar(const TComplejo & t) const{

	bool encontrado = false;
	TListaPos aux = this->Primera();

	if(aux.pos->e == t){
		encontrado = true;
	}else{ 

		//Que la actual no sea vacia y que no se haya encontrado ya y que la siguiente no sea vacia
		while(!aux.EsVacia() && encontrado == false && !aux.Siguiente().EsVacia() ){ 
			aux = aux.Siguiente();
			if(aux.pos->e == t){
				encontrado = true;
			}			
	 	}
 	}

 	return encontrado;
}

//Devuelve la longitud de la lista
int TListaCom::Longitud() const{
	/*
	int cont = 0;

	TListaPos aux = this->Primera();

	if(!aux.EsVacia()){ 
		while(!aux.EsVacia()){
			cont = cont + 1;
		}
	}

	return cont;*/
    int tam = 0;
    TListaPos aux = this->Primera();

    if(aux.pos)
    	tam++;

    while(!aux.Siguiente().EsVacia()){
    	tam++;
    	aux.pos = aux.pos->siguiente;
    }
    
    return tam;
}

//Devuelve la primera posicion en la lista
TListaPos TListaCom::Primera() const{


	TListaPos p;

	if(this->EsVacia()){ //Si es vacia, le devuelvo p, que es vacia tambien
		return TListaPos();
	}else{ //Si no es vacia, le devuelvo el primero, que es de TListaNodo que a su vez
			// es de TListaNodo

	p.pos = this->primero;
	return p;
	}
}

//Devuelve la ultima posicion en la lista
TListaPos TListaCom::Ultima() const{

	TListaPos p;

	if(this->EsVacia()){ //Si es vacia, le devuelvo p, que es vacia tambien
		return p;
	}else{ //Si no es vacia, le devuelvo el ultimo, que es de TListaNodo que a su vez
			// es de TListaNodo

	p.pos = this->ultimo;
	return p;

	}

}
//Final de metodos

//Funciones amigas:
//Sobrecarga del operador de salida
ostream & operator<<(ostream & salida,const TListaCom & lista){
    salida << "{";

    if(lista.EsVacia()) //Lista vacia.
    	salida << "}";
    else{
    	TListaPos pos = lista.Primera();

    	if(pos.Siguiente().EsVacia())//Solo un elemento;
    		salida << lista.Obtener(pos) << "}";
    	else{//Mas de un elemento.
    		salida << lista.Obtener(pos);
    		salida << " ";

    		while(!pos.Siguiente().EsVacia() && pos.Siguiente() != lista.Ultima()){
    			pos = pos.Siguiente();
    			salida << lista.Obtener(pos) << " ";
    		}

    		pos = pos.Siguiente();
    		salida << lista.Obtener(pos);
    		salida << "}";
    	}
    }
    
    return salida;
}
//////////////////////////////FINAL TLISTACOM


TListaPos TListaCom::BuscarPosicion(const TComplejo & t){

	TListaPos aux;

	if(this->primero->e == t){
		return this->Primera();
	}else{

		for(int i=0;i < this->Longitud(); i++){
			if(this->primero->e == t){
				return this->Primera();
			}else{
				this->primero = this->primero->siguiente;
			}
		}

		return aux;
	}

}


bool TListaCom::Copia(const TListaCom & t){

	//InsCabeza en orden inverso.
	primero = ultimo = NULL;

	TListaPos p = t.Ultima();

	while(!p.EsVacia()){
		this->InsCabeza(p.pos->e);
		p.Anterior();
	}

	return true;
}