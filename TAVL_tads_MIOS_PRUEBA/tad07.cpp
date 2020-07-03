/************************************************************
** BUSCAR
*************************************************************/
#include <iostream>
#include "tavlcom.h"

using namespace std;

int
main()
{
  TAVLCom arb1;

  TComplejo c1(1,1);
  TComplejo c2(1,2);
  TComplejo c3(1,3);
  TComplejo c4(1,4);
  TComplejo c5(1,5);
  TComplejo c6(1,6);
  TComplejo otro(1,10);

  arb1.Insertar(c5);
  arb1.Insertar(c2);
  arb1.Insertar(c3);
  arb1.Insertar(c1);
  arb1.Insertar(c6);

  if(arb1.Buscar(otro))
    cout << "Encontrado" << endl;
  else
    cout << "No encontrado" << endl;

  if(arb1.Buscar(c1))
    cout << "Encontrado" << endl;
  else
    cout << "No encontrado" << endl;

  return 0;
}
