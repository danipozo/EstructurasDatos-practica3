#include <iostream>
#include "lista.h"
#include "VD.h"
#include "Pila_max.h"

#ifdef USACOLA
#define Cont Cola
#elif USALISTA
#define Cont Lista
#elif USAVD
#define Cont VD
#else
#error "No se ha pasado una bandera válida."
#endif

using namespace std;

int main(){

  PilaMax<Cont> p;
  int i;

  for ( i=10; i>=0; i--) 
    p.insertar(i);
  
  while (!p.vacia() ){
    PilaMax<Cont>::Par x = p.tope();
    cout << x.elemento << ' ' << x.maximo <<endl;
    p.borrar();
  }     
  
  return 0;
}
