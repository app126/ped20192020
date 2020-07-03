#ifndef TABBCOM_CPP_
#define TABBCOM_CPP_


#include <iostream> 
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <queue> 
#include "tvectorcom.h"

using namespace std;

class TNodoABB;

/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
///////////TABBCOM///////////////////////////////////////

class TABBCom{

friend class TNodoABB;

/////////////Parte publica:
private:
void NivelesAux(TVectorCom &, int &) const;

// Puntero al nodo
TNodoABB *nodo;

//Metodo para copiar
void Copiar(const TABBCom &);



// Sobrecarga del operador >
bool esMayor(const TComplejo &);

public:
// FORMA CANÓNICA

// Constructor por defecto
TABBCom ();

// Constructor de copia
TABBCom (const TABBCom &);

// Destructor
~TABBCom ();

// Sobrecarga del operador asignación
TABBCom & operator=(const TABBCom &);

// FIN FORMA CANÓNICA


// MÉTODOS
// Sobrecarga del operador igualdad
bool operator==(const TABBCom &) const;

// Devuelve TRUE si el árbol está vacío, FALSE en caso contrario
bool EsVacio() const;

// Inserta el elemento en el árbol
bool Insertar(const TComplejo &);

// Borra el elemento en el árbol
bool Borrar(const TComplejo &);

// Devuelve TRUE si el elemento está en el árbol, FALSE en caso contrario
bool Buscar(const TComplejo &) const;

// Devuelve el elemento en la raíz del árbol
TComplejo Raiz() const;

// Devuelve la altura del árbol (la altura de un árbol vacío es 0)
int Altura() const;

// Devuelve el número de nodos del árbol (un árbol vacío posee 0 nodos)
int Nodos() const;

// Devuelve el número de nodos hoja en el árbol (la raíz puede ser nodo hoja)
int NodosHoja() const;

// Devuelve el recorrido en inorden
TVectorCom Inorden() const ;

// Devuelve el recorrido en preorden
TVectorCom Preorden() const ;

// Devuelve el recorrido en postorden
TVectorCom Postorden() const ;

// Devuelve el recorrido en niveles
TVectorCom Niveles() const ;







// AUXILIAR : Devuelve el recorrido en inorden
void InordenAux(TVectorCom &,int &) const;

// AUXILIAR : Devuelve el recorrido en preorden
void PreordenAux( TVectorCom &,  int &) const;

// AUXILIAR : Devuelve el recorrido en postorden
void PostordenAux( TVectorCom &,  int &) const;


// Sobrecarga del operador salida
friend ostream & operator<<(ostream &, const TABBCom &);



};

/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
///////////TNodoABB//////////////////////////////////////

class TNodoABB{

friend class TABBCom;

//////////Parte privada:
private:
//El elemento del nodo
TComplejo item;

// Subárbol izquierdo y derecho
TABBCom iz,de;

public:
//Constructor por defecto
TNodoABB();

// Constructor de copia
TNodoABB (const TNodoABB &);


// Destructor
~TNodoABB ();


// Sobrecarga del operador asignación
TNodoABB & operator=(const TNodoABB &);

};

/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
///////////FIN TNodoABB//////////////////////////////////


#endif