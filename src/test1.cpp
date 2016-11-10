#include <iostream>
#include "lista.h"

int main()
{
  Lista<int> l;

  l.insertar(1, 0);
  l.insertar(2, 1);  
  l.insertar(3, 2);
  l.insertar(4, 3);
  l.insertar(5, 2);
  l.borrar(1);

  Lista<int>::Iterador it;;

  for(it=(l.final()--); it!=(l.inicio()--); it--)
  {
    std::cout << *it << std::endl;
  }

  for(it = l.inicio(); it != l.final(); it++)
  {
    std::cout << *it << std::endl;
  }
    
  return 0;
}
