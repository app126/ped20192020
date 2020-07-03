/* Prueba:
    - CONSTR. COPIA , "=" ; posible copia de punteros
*/

#include <iostream>
#include "tabbcom.h"
#include "tcomplejo.h"

#define ins(re)a=TComplejo(re,1);tabbCom.Insertar(a)
using namespace std;

int
main(void) {
    TABBCom tabbCom;

    TComplejo a;
    int nodes[] = {50, 30, 20, 40, 70, 60, 80, 10, 25, 35, 45, 55, 65, 75, 85};
    int n = 15;

    for (int i = 0; i < n; ++i) {
        ins(nodes[i]);
    }

    cout << tabbCom << endl;
}
