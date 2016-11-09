#include <iostream>
#include "lista.h"

int main()
{
  Lista<int> l;

  l.insertar(1, 0);
  l.insertar(2, 1);  
  l.insertar(3, 2);
  l.insertar(4, 3);
  l.insertar(5, 4);
    
  return 0;
}
