/* Prueba:
    - CONSTR. COPIA , "=" ; posible copia de punteros 
*/

#include <iostream>
#include "tabbcom.h"
#include "tcomplejo.h"
#include "tvectorcom.h"

#define ins(re)a=TComplejo(re,1);tabbCom.Insertar(a);
using namespace std;

int
main(void) {
    TABBCom tabbCom;

    TComplejo a;
    ins(30);
    ins(20);
    ins(10);
    ins(25);
    ins(1);

    ins(50);
    ins(40);
    ins(60);
    ins(70);

    cout << tabbCom << endl;
    cout << tabbCom.Niveles() << endl;
    cout << tabbCom.Preorden() << endl;
    cout << tabbCom.Inorden() << endl;
    cout << tabbCom.Postorden() << endl;
}
