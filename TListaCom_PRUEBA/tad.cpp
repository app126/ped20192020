#include <iostream>

using namespace std;

#include "tvectorcom.h"
#include "tcomplejo.h"
#include "tlistacom.h"

int
main(void)
{
  TVectorCom a(2);
  TVectorCom b(4);
  TVectorCom c(6);

  cout << "a: " << a << endl;
  cout << "b: " << b << endl;
  cout << "c: " << c << endl;

{
  TComplejo a;
  TComplejo b(a);
  TComplejo c;
  c = a;
  
  if(a == b)
    cout << "SI" << endl;
  else
    cout << "NO" << endl;

  if(a == c)
    cout << "SI" << endl;
  else
    cout << "NO" << endl;


}

{
  TComplejo a(1, -7);
  TListaCom lc1, lc2;
  
  for (int i=0; i<5; i++) {
         a = a + double(i);
         lc1.InsCabeza(a);
  }
  
  lc2=lc1;
  lc1=lc1 + lc2;
  cout << "lc1 = " << lc1 << endl;
  
}

}



