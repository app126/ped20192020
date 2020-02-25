#include <iostream> 
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>


using namespace std;

class TVectorCom{

	private:
		TComplejo *c;
		int tamano;
	public:
	/////FORMA CANONICA//////
		//Constructor por defecto.
		TVectorCom();
		//Constructor que se le pasa un int (tamano)
		TVectorCom(int);
		//Constructor copia
		TVectorCom(TVectorCom &);
		//Destructor
		~TVectorCom();
		//Operador de asignacion
		TVectorCom & operator=(TVectorCom &);
	/////FIN FORMA CANONICA///////


};
