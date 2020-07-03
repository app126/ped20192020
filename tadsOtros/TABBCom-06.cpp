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
        TComplejo tComplejo(20, 1);
        assert(arbol.Borrar(tComplejo));
        assert(!arbol.Borrar(tComplejo));

        TComplejo tComplejo2(10, 1);
        assert(arbol.Borrar(tComplejo2));
        assert(!arbol.Borrar(tComplejo2));

        TComplejo tComplejo3(25, 1);
        assert(arbol.Borrar(tComplejo3));
        assert(!arbol.Borrar(tComplejo3));

        cout << arbol << endl;

        TComplejo tComplejo4(30, 1);
        assert(arbol.Borrar(tComplejo4));
        assert(!arbol.Borrar(tComplejo4));

        cout << arbol << endl;

        TComplejo tComplejo5(45, 1);
        assert(arbol.Borrar(tComplejo5));
        assert(!arbol.Borrar(tComplejo5));

        cout << arbol << endl;
        TComplejo tComplejo6(35, 1);
        assert(arbol.Borrar(tComplejo6));
        assert(!arbol.Borrar(tComplejo6));

        cout << arbol << endl;
        TComplejo tComplejo7(40, 1);
        assert(arbol.Borrar(tComplejo7));
        assert(!arbol.Borrar(tComplejo7));

        cout << arbol << endl;

    }
}
