/* Prueba:
    - CONSTR. COPIA , "=" ; posible copia de punteros 
*/

#include <iostream>
#include "tabbcom.h"
#include "tcomplejo.h"
#include "tvectorcom.h"

#define ins(re, im)a=TComplejo(re,im);tabbCom.Insertar(a)
using namespace std;

int
main(void) {
    TABBCom tabbCom;

    TComplejo a;

    ins(10, 1);
    ins(1, 10000);
    ins(15, 1);

    cout << tabbCom << endl;
}
