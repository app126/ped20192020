/* Prueba:
    - ALTURA, NODOS, NODOSHOJA   
*/

#include <iostream>
#include "tabbcom.h"
#include "tcomplejo.h"
#include "tvectorcom.h"
using namespace std;

int
main(void)
{

  
  TABBCom a;

  TABBCom b;
 
  TComplejo c100(100, 1);
  TComplejo c50(50, 1);
  TComplejo c20(20, 1);
  TComplejo c110(110, 1);
  TComplejo especial(30, 0);

 
  a.Insertar(c100);
  a.Insertar(c50);
  a.Insertar(c20);
  a.Insertar(c110);

  b.Insertar(c110);
  b.Insertar(c50);
  b.Insertar(c100);
  b.Insertar(c20);


  if(a==b){
    cout<<"SON IGUALES"<<endl;
  }


  return 1; 

}
