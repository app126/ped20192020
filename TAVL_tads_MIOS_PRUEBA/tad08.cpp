/************************************************************
** RAIZ, <<
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

  arb1.Insertar(c5);
  arb1.Insertar(c2);
  arb1.Insertar(c1);
  arb1.Insertar(c3);
  arb1.Insertar(c6);

  cout << arb1.Raiz()<<endl;

  cout<<arb1<<endl;

  return 0;
}
