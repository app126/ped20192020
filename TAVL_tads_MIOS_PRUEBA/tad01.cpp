/************************************************************
** CONSTRUCTORES, = CON ARBOLES VACIOS
*************************************************************/
#include <iostream>
#include "tavlcom.h"

using namespace std;

int
main(void)
{
  TAVLCom a,c;
  TAVLCom b(a);

  c=b;
  
  cout << "No hace nada" << endl;
  return 0;
}
