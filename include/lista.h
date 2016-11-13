
#ifndef LISTA_H
#define LISTA_H

#include <iostream>

template <class T>
class Lista
{
    // --- TDA Celda. Servirá como la celda enlazada de la lista.
    struct Celda
    {
        T elemento;
        Celda *siguiente;
        Celda* anterior;
    };

  private:
    Celda* cabecera;

  public:

    struct Iterador
    {
      private:
        Celda** puntero; //< Puntero a un elemento de la lista enlazada.

      public:
        // -- Constructor
        Iterador() : puntero(nullptr) { }
        Iterador(Celda** puntero) : puntero(puntero) { }
        // -- Operadores
        bool operator==(const Iterador& otro) const;
        bool operator!=(const Iterador& otro) const;
        Iterador& operator++(int);
        Iterador& operator--(int);
        T& operator*();

        friend class Lista;
    };

    // --- Constructor/destructor.
    Lista();
    ~Lista();

    // --- Métodos que no modifican el estado
    Iterador inicio();
    Iterador final();
    T obtener_elemento(int pos);

    // --- Métodos que modifican el estado
    void insertar(const T& elem, int pos);
    void borrar(int pos);

    void insertar(const T& elem, const Iterador& pos);
    void borrar(const Iterador& pos);
};

#include "lista.cpp"

#endif // LISTA_H
