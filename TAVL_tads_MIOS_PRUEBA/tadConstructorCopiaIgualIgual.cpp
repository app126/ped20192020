//probar == y Preorde e insertar.
//Constructor copia.
#include <iostream>
#include "tavlcom.h"

using namespace std;

int
main(void)
{
  TAVLCom a,b;
  TComplejo c1(1,1);
  TComplejo c2(1,2);
  TComplejo c3(1,3);
  TComplejo c4(1,4);
  TComplejo c5(1,5);



  a.Insertar(c1);
  a.Insertar(c2);
  a.Insertar(c3);
  a.Insertar(c4);
  TAVLCom c(a);
  
  b.Insertar(c1);
  b.Insertar(c2);
  b.Insertar(c3);
  b.Insertar(c4);

  if ( a==c )
  	cout << "IGUALES" << endl;
  else 
	cout << "DISTINTOS" << endl;

  if ( c==b )
  	cout << "IGUALES" << endl;
  else 
	cout << "DISTINTOS" << endl;

  b = a;
cout << b.Preorden() <<endl;
  a.Insertar(c5);
  if ( a==b )
  	cout << "IGUALES" << endl;
  else 
	cout << "DISTINTOS" << endl;

  cout << "Altura: " << b.Altura() << endl;
  cout << b.Preorden() <<endl;
 return 0;
}
