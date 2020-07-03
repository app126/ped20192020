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

    ins(10, 10);
    ins(10, 5);
    ins(10, 15);

    cout << tabbCom << endl;
}
