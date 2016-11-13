/**
 * @file   lista.h
 * @author Daniel Pozo Escalona
 * 
 * @brief  Fichero de cabecera del TDA *Lista*.
 * 
 * 
 */


#ifndef LISTA_H
#define LISTA_H

#include <iostream>

/**
 * @brief TDA *Lista*
 *
 * Una instancia del TDA *Lista* sobre un dominio T representa una
 * lista de elementos de T. Está implementada como una lista
 * doblemente enlazada con cabecera. Expone iteradores, que han
 * sido implementados con propósito meramente didáctico.
 */

template <class T>
class Lista
{
  /**
   * @brief TDA *Celda*. Servirá como la celda enlazada de la lista.
   * 
   */

    struct Celda
    {
        T elemento;		/**< El elemento contenido en el nodo. */
        Celda *siguiente;	/**< Puntero al siguiente elemento. */
        Celda* anterior;	/**< Puntero al elemento anterior. */
    };

  private:
    Celda* cabecera;		/**< Puntero a la cabecera de la lista. */

  public:
  /**
   * @brief TDA *Iterador*. Sirve como iterador de la lista. 
   * 
   */

    struct Iterador
    {
      private:
        Celda** puntero; //< Puntero a un elemento de la lista enlazada.

      public:
        // -- Constructor
        Iterador() : puntero(nullptr) { } /**< Constructor por defecto. */
      /** 
       * @brief Constructor.
       * Crea un iterador que apunta al elemento de la lista al que apunte \*puntero.
       * 
       * @param puntero 
       * 
       */
        Iterador(Celda** puntero) : puntero(puntero) { }
        // -- Operadores
        bool operator==(const Iterador& otro) const; /**< Operador de igualdad. */
        bool operator!=(const Iterador& otro) const; /**< Operador de desigualdad. */
        Iterador& operator++(int); /**< Avanza al siguiente elemento de la lista. */
        Iterador& operator--(int); /**< Retrodece al elemento anterior de la lista. */
        T& operator*();

        friend class Lista;
    };

    // --- Constructor/destructor.
    Lista();			/**< Constructor por defecto. */
    ~Lista();			/**< Destructor por defecto. */

    // --- Métodos que no modifican el estado
    Iterador inicio() const;	/**< Devuelve un iterador al inicio de la lista. */
    Iterador final();		/**< Devuelve un iterador al final de la lista. */
  /** 
   * 
   * 
   * @param pos 
   * 
   * @return El elemento en la posición *pos* de la lista. 
   */
    T obtener_elemento(int pos) const;
  /** 
   * @return *true* si la pila está vacía, *false* en otro caso. 
   */
    bool vacia() const;

    // --- Métodos que modifican el estado
  /** 
   * Inserta *elem* en la posición *pos*.
   * Eficiencia *O(n)*.
   * 
   * @param elem 
   * @param pos 
   */
    void insertar(const T& elem, int pos);
  /** 
   * Borra el elemento en la posición *pos*.
   * Eficiencia *O(n)*.
   * 
   * @param pos 
   */
    void borrar(int pos);
  /** 
   * Inserta *elem* en la posición *pos*.
   * Eficiencia *O(1)*.
   * 
   * @param elem 
   * @param pos 
   */
    void insertar(const T& elem, const Iterador& pos);
  /** 
   * Borra el elemento en la posición *pos*.
   * Eficiencia *O(1)*.
   * 
   * @param pos 
   */
    void borrar(const Iterador& pos);
};

#include "lista.cpp"

#endif // LISTA_H
