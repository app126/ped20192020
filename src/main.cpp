#include <iostream>

using namespace std;

#include "tcomplejo.h"

int main(){




TComplejo complejo1(5,3);
double salidaComplejo;

salidaComplejo = complejo1.Re();

cout << "Real >" << complejo1.Re() << "\n" ;
cout << "Imaginario >" << complejo1.Im() << "\n" ;
cout << "Arg >" << complejo1.Arg() << "\n" ;
cout << "Mod >" << complejo1.Mod() << "\n" ;

}
