#ifndef TAVLCOM_H_
#define TAVLCOM_H_

#include "tvectorcom.h"

class TNodoAVL;


////////////////////////CLASE TAVLCom////////////////////
class TAVLCom {
	friend class TNodoAVL;
	friend ostream & operator<<(ostream &, TAVLCom &);
public:
	//Constructor por defecto.
	TAVLCom();

	//Constructor copia
	TAVLCom(const TAVLCom &);

	//Desttructor
	~TAVLCom();

	//Operador de asignación
	TAVLCom & operator=(const TAVLCom &);

	//Sobrecarga del operadord e igualdad
	bool operator==(const TAVLCom &) const;

	//Sobrecarga del operador desigualdada.
	bool operator!=(const TAVLCom &) const;

	//Devuelve TRUE si el árbol está vacío, false en caso contrario.
	bool EsVacio() const;

	//Inserta el elemento TComplejo en el árbol.
	bool Insertar(const TComplejo &);

	//Devuelve true si el lemento está en el arbol, false en caso contrario.
	bool Buscar(const TComplejo &) const;

	//Borra un TComplejo del árbol AVL
	bool Borrar(const TComplejo &);

	//Devuelve la altura del árbol (/la altura de un árbol vacío es 0)
	int Altura() const;

	//Devuelve el elemento TComplejo raíz del árbol AVL.
	TComplejo Raiz() const;

	//Devuelve el número de nodos
	int Nodos() const;

	//Devuelve el número de nodos hoja en el árbol (la raiz puede ser nodo hoja)
	int NodosHoja() const;

	//Deuelve el recorrido en inorden sobre un vector.
	TVectorCom Inorden() const;

	//Devuelve el recorrido en preorden sobre un vector.
	TVectorCom Preorden() const;

	//Devuelve el recorrido en postorden de un vector.
	TVectorCom Postorden() const;


private:
	//Puntero al nodo.
	TNodoAVL *raiz;

	//Auxiliar: devuelve el recorrido en inorden.
	void InordenAux(TVectorCom &, int &) const;

	//Auxiliar: devuelve el recorrido en preorden.
	void PreordenAux(TVectorCom &, int &) const;

	//Auxiliar: devuelve el recorrido en postorden.
	void PostordenAux(TVectorCom &, int &) const;

	//Metodo propio para copiar
	void CopiarAVL(const TAVLCom &);

	//Metodo propio para saber cuál es mayor.
	bool esMayor(const TComplejo &) const ;

	//Metodo InsertarAux recomendado.
	bool InsertarAux(const TComplejo &,bool &) ;


	void moverDD(TAVLCom &,TAVLCom &,TAVLCom &,TAVLCom &, TComplejo &);
	void moverDI(TAVLCom &,TAVLCom &,TAVLCom &,TAVLCom &, TComplejo &);
	void moverII(TAVLCom &,TAVLCom &,TAVLCom &,TAVLCom &, TComplejo &);
	void moverID(TAVLCom &,TAVLCom &,TAVLCom &,TAVLCom &, TComplejo &);
	bool BorrarAux(const TComplejo &);

	TComplejo mayorIzquierda(const TAVLCom &);
	TComplejo mayorDerecha(const TAVLCom &);
	void actualizacionFactorEquilibrio();


};




///////////////////////CLASE TNovodAVL////////////////////
class TNodoAVL{
	friend class TAVLCom;

public:
	//Constructor por defecto.
	TNodoAVL();

	//Constructor de copia.
	TNodoAVL(const TNodoAVL &);

	//Destructor
	~TNodoAVL();

	//Sobrecarga del operador de asignación.
	TNodoAVL & operator=(const TNodoAVL &);

private:
	//El elemento del nodo
	TComplejo item;

	//Subarbol izquierdo y derecho.
	TAVLCom iz, de;

	//Factor de equilibrio.
	int fe;
};
#endif 