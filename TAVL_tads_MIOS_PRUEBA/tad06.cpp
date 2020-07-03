/************************************************************
** ALTURA, NODOS, NODOSHOJA, =, != 
*************************************************************/
#include <iostream>
#include "tavlcom.h"

using namespace std;

int
main()
{
  TAVLCom arb1, arb2;

  TComplejo bd(1,1);
  TComplejo bc(1,2);
  TComplejo be(1,3);
  TComplejo bn(1,4);
  TComplejo ba(1,5);
  TComplejo bm(1,6);

  arb1.Insertar(ba);
  arb1.Insertar(bc);
  arb1.Insertar(bd);
  arb1.Insertar(be);
  arb1.Insertar(bm);
  

  arb2 = arb1;
  if(arb2 != arb1)
    cout << "No iguales" <<endl;
  else
    cout << "Iguales" << endl;

  cout << "Altura: " << arb2.Altura() << endl;
  cout << "Nodos: " << arb2.Nodos() << endl;
  cout << "NodosHoja: " << arb2.NodosHoja() << endl;

  return 0;
}
