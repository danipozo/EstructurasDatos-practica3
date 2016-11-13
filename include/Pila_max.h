#ifndef PILA_MAX_H
#define PILA_MAX_H

#include "cola.h"

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

template<>
class PilaMax<Cola>
{
  public:
    struct Par
    {
        int elemento;
        int maximo;
    };

  private:
    Cola<Par> cola;

  public:
    // --- Constructor/destructor.
    PilaMax() = default;
    ~PilaMax() = default;

    // --- Métodos que no modifican el estado.
    Par tope()
    {
        for(int i=0; i<cola.num_elementos()-1; i++)
        {
            cola.poner(cola.frente());
            cola.quitar();
        }

        Par ret = cola.frente();
        cola.poner(ret);
        cola.quitar();

        return ret;
    }
    bool vacia() const {return cola.vacia();}

    // --- Métodos que modifican el estado.
    void insertar(int elem)
    {
        int max = std::numeric_limits<int>::min();

        if(!vacia())
            max = tope().maximo;
        Par par = {elem, max > elem ? max : elem};

        cola.poner(par);
    }
    void borrar()
    {
        for(int i=0; i<cola.num_elementos()-1; i++)
        {
            cola.poner(cola.frente());
            cola.quitar();
        }

        cola.quitar();
    }
};

#include "PilaMax.cpp"


#endif // PILA_MAX_H
