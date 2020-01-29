#include <iostream> 
using namespace std;
 
class TComplejo {
   private:// Datos privados de la clase tcomplejo
      double re, im; 

    //Constructor por defecto.
      void TComplejo() {
      }

    //Constructor a partir de la parte real.
      void TComplejo (double){
      }

    //Constructor a partir de la parte real e imaginaria
      void TComplejo (double, double){
      }

    //Constructor copia
      void TComplejo(Tcomplejo &){
      }
      
    //Destructor      
      ~TComplejo();

//////////////////////METODOS///////////////////////////////////



};


/*int main() {
   pareja par1;
   int x, y;
   
   par1.Guarda(12, 32);
   par1.Lee(x, y);
   cout << "Valor de par1.a: " << x << endl;
   cout << "Valor de par1.b: " << y << endl;

   return 0;
}*/