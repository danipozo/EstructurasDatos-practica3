#include <iostream>
#include "lista.h"
#include "VD.h"
#include "Pila_max.h"

#define Cont VD

using namespace std;

int main(){

  PilaMax<Cont> p;
  int i;

  int v[] = {5,3,6,9,2,7};
  for ( i=0; i<6; i++) 
    p.insertar(v[i]);
  
  while (!p.vacia() ){
    PilaMax<Cont>::Par x = p.tope();
    cout << x.elemento << ' ' << x.maximo <<endl;
    p.borrar();
  }     
  
  return 0;
}
