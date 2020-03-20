#ifndef _TLISTACOM_H_
#define _TLISTACOM_H_

#include <iostream> 
#include "tcomplejo.h"


class TListaNodo{
	friend class TListaPos;
	friend class TListaCom;

private:
	//El elemento del nodo
	TComplejo e;

	//El nodo anterior.
	TListaNodo *anterior;

	//El nodo siguiente.
	TListaNodo *siguiente;
public:
	//Constructor por defecto.
	TListaNodo();

	//Constructor copia
	TListaNodo(const TListaNodo &);

	//Destructor
	~TListaNodo();

	//Sobrecarga del operador de asignacion.
	TListaNodo & operator=(const TListaNodo &);

};






class TListaPos{
	friend class TListaCom;
	friend class TListaNodo;

private:
	//Puntero a un nodo de la lista
	TListaNodo *pos;

public:

////////             INICIO FORMA CANONICA
	//Constructor por defecto.
	TListaPos();

	//Constructor copia.
	TListaPos(const TListaPos &);

	//Destructor
	~TListaPos();

	//Sobrecarga del operador de asignacion.
	TListaPos & operator=( const TListaPos &);
////////////////       FIN FORMA CANONIAyes

///////////////        INICIO METODOS

	//Sobrecarga del operador de igualdad
	bool operator==(const TListaPos &) const;

	//Sobrecarga del operador de desigualdad
	bool operator!=(const TListaPos &) const;

	//Devuelve la posicion anterior
	TListaPos Anterior() const;

	//Devuelve la posicion siguiente.
	TListaPos Siguiente() const;

	//Devuelve TRUE si la posición no apunta a una lista, FALSE en caso contrario.
	bool EsVacia() const;
//////////////          FIN METODOS

};







class TListaCom{

	friend class TListaNodo;
	friend class TListaPos;

//////////// INICIO PARTE PRIVADA.
private:
//Primer elemento de la lista.
TListaNodo *primero;

//Ultimo elemento de la lista.
TListaNodo *ultimo;

////////////  FINAL PARTE PRIVADA
public:
////////////      

//Constructor por defecto.
TListaCom();

//Constructor copia
TListaCom(const TListaCom &);

//Destructor
~TListaCom();

//Sobrecarga del operador de asignacion.
TListaCom & operator=( const TListaCom &);

///////////       FIN PARTE PRIVADA.

///////////         INICIO METODOS.

//Sobrecarga del operador de igualdad
bool operator==(const TListaCom &) const;

//Sobrecarga del operador de desigualdad
bool operator!=(const TListaCom &)const;

//Sobrecarga del operador SUMA.
TListaCom operator+(const TListaCom &)const;

//Sobrecarga del operador RESTA.
TListaCom operator-(const TListaCom &) const;

//Devuelve true si la lista esta vacia, false en caso contrario.
bool EsVacia() const;

//Inserta el elemento en la cabeza de la lista
bool InsCabeza(const TComplejo &);

//Inserta el elemento a la izquierda de la posición indicada.
bool InsertarI(const TComplejo &, const TListaPos &);

//Inserta el elemento a la derecha de la posición indicada.
bool InsertarD(const TComplejo &, const TListaPos &);

//Borra y busca la primera ocurrencia del elemento.
bool Borrar(const TComplejo &);

//Busca y borra todas las ocurrencias del elemento
bool BorrarTodos(const TComplejo &);

//Borra el elemento que ocupa la posición indicada.
bool Borrar(TListaPos &);

//Obtiene el elemento que ocupa la posición indicada.
TComplejo Obtener(const TListaPos &) const;

//Devuelve true si el elemento está en la lista, false en caso contrario.
bool Buscar(const TComplejo &) const;

//Devuelve la longitud de la lista
int Longitud() const;

//Devuelve la primera posicion en la lista
TListaPos Primera() const;

//Devuelve la última posicion de la lista.
TListaPos Ultima() const;

///////////           FIN METODOS.

TListaPos BuscarPosicion(const TComplejo &);

///////////        FUNCIONES AMIGAS.

//Sobrecarga del operador de salida.
friend ostream & operator<<(ostream &, const TListaCom &);
//////////          FIN FUNCIONES AMIGAS.



bool Copia( const TListaCom &);
};

#endif