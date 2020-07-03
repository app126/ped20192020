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
    {
        TABBCom arbol = tabbCom;
        TComplejo tComplejo(50, 1);

        assert(arbol.Borrar(tComplejo));
        assert(!arbol.Borrar(tComplejo));

        cout << arbol << endl;
    }
    {
        TABBCom arbol = tabbCom;
        TComplejo tComplejo(30, 1);

        assert(arbol.Borrar(tComplejo));
        assert(!arbol.Borrar(tComplejo));

        cout << arbol << endl;
    }
    {
        TABBCom arbol = tabbCom;
        TComplejo tComplejo(70, 1);

        assert(arbol.Borrar(tComplejo));
        assert(!arbol.Borrar(tComplejo));

        cout << arbol << endl;

        TABBCom arbol2 = arbol;

        TComplejo tComplejo2(60, 1);

        assert(arbol2.Borrar(tComplejo2));
        assert(!arbol2.Borrar(tComplejo2));

        cout << arbol2 << endl;
    }
    {
        TABBCom arbol = tabbCom;
        TComplejo tComplejo(300, 1);

        assert(!arbol.Borrar(tComplejo));

        cout << arbol << endl;
    }
}
