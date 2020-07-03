
/* Prueba:
    - CONSTR. COPIA , "=" ; posible copia de punteros
*/

#include <iostream>
#include <cassert>
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

    TComplejo tComplejo(1, 1);
    for (int i = -100; i < 100; i++) {
        tComplejo.Re(i);
        bool inarr = false;


        for (int j = 0; j < n; ++j) {
            if (i == nodes[j]) {
                inarr = true;
                break;
            }
        }
        assert(tabbCom.Buscar(tComplejo) == inarr);
    }

    cout << "a";
}
