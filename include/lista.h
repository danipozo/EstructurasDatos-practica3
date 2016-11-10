
#ifndef LISTA_H
#define LISTA_H

#include <iostream>

template <class T>
class Lista
{
    /* public: */

    // --- TDA Celda. Servirá como la celda enlazada de la lista.
    struct Celda
    {
        /* private: */
        // --- Datos miembro
        T elemento;
        Celda *siguiente;
        Celda* anterior;

        /* public: */
        /*   // --- Constructores */
        /*   Celda() : siguiente(nullptr), anterior(nullptr) { } */
        /*   Celda(T elem, Celda* sig, Celda* ant) : elemento(elem), siguiente(sig), anterior(ant) { } */

        /*   // --- Operadores */
        /* bool operator==(const Celda& otra); */
        /* bool operator!=(const Celda& otra); */
        /*   Celda& operator++(int); */
        /*   Celda& operator--(int); */
        /*   T& operator*(); */

        /*   friend class Lista; */
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
    };


    Lista();

    // --- Funciones que no modifican el estado
    Iterador inicio();

    Iterador final();

    // --- Funciones que modifican el estado
    void insertar(const T& elem, int pos);
    void borrar(int pos);
};

#include "lista.cpp"

#endif // LISTA_H
