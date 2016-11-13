#ifndef PILA_MAX_H
#define PILA_MAX_H

#include <iostream>
#include <limits>

template <template  <typename> class T>
class PilaMax
{
  public:
    struct Par
    {
        int elemento;
        int maximo;
    };

  private:
    T<Par> contenedor;

  public:
    // --- Constructor/destructor.
    PilaMax() = default;
    ~PilaMax() = default;

    // --- Métodos que no modifican el estado.
    Par tope() const;
    bool vacia() const;

    // --- Métodos que modifican el estado.
    void insertar(int elem);
    void borrar();
};

#include "PilaMax.cpp"

#endif // PILA_MAX_H
