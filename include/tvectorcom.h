#ifndef _TVECTORCOM_H_
#define _TVECTORCOM_H_

#include "tcomplejo.h"

using namespace std;

class TVectorCom{

	private:
		TComplejo *c;
		int tamano;
		TComplejo error;
	public:
	/////FORMA CANONICA//////
		//Constructor por defecto.
		TVectorCom();
		//Constructor que se le pasa un int (tamano)
		TVectorCom(int);
		//Constructor copia
		TVectorCom(const TVectorCom &);
		//Destructor
		~TVectorCom();
		//Operador de asignacion
		TVectorCom & operator=(const TVectorCom &);
	/////FIN FORMA CANONICA///////


	/////////METODOS//////////////
		//Sobrecarga del operador de igualdad.
		bool operator==(const TVectorCom &) const;
		//Sobrecarga del operador de desigualdad
		bool operator!=(const TVectorCom &) const;
		//Sobrecarga del operador corchete (parte IZQUIERDA)
		TComplejo & operator[](int);
		//Sobrecarga del operador corchete (parte DERECHA)
		TComplejo operator[](int) const;
		//Tamaño del vector (posiciones TOTALES)
		int Tamano();
		//Cantidad de posiciones OCUPADAS (TComplejo NO VACIO) en el vector.
		int Ocupadas();
		//Devuelve TRUE si existe el TComplejo en el vector.
		bool ExisteCom(TComplejo &);
		//Mostrar por pantalla los elementos TComplejo del vector con PARTE REAL IGUAL O POSTERIOR
		// al argumento.
		void MostrarComplejos(double);
		//REDIMENSIONAR el vector de TComplejo
		bool Redimensionar(int);
	/////////FIN DE METODOS///////

		friend ostream & operator<<(ostream &, const TVectorCom &);
};

#endif