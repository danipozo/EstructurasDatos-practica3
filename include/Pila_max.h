/**
 * @file   Pila_max.h
 * @author Daniel Pozo Escalona
 * 
 * @brief  Fichero de cabecera del TDA *PilaMax*.
 * 
 * 
 */


#ifndef PILA_MAX_H
#define PILA_MAX_H

#include "cola.h"

#include <iostream>
#include <limits>

/*! \mainpage Práctica 3. Implementación de PilaMax.
 *
 */


/**
 * @brief TDA PilaMax.
 *
 * Una instancia de *PilaMax* representa una pila de enteros,
 * junto con el máximo de la pila.
 * 
 */

template <template  <typename> class T>
class PilaMax
{
  public:
  /**
   * @brief Estructura *Par*.
   *
   * Representa un elemento de la pila, junto con el máximo
   * en el momento en el que se introdujo el elemento.
   * 
   */

    struct Par
    {
        int elemento;
        int maximo;
    };

  private:
    T<Par> contenedor;		/**< El contenedor que usa la instancia de *PilaMax* */

  public:
    // --- Constructor/destructor.
    PilaMax() = default;	/**< Constructor por defecto. */
    ~PilaMax() = default;	/**< Destructor por defecto. */

    // --- Métodos que no modifican el estado.
  /** 
   * 
   * @return Una instancia de *Par*, el tope de la pila.
   */
    Par tope() const;
  /** 
   * 
   * 
   * 
   * @return *true* si la pila está vacía, *false* en otro caso. 
   */
    bool vacia() const;

    // --- Métodos que modifican el estado.
  /** 
   * @brief Inserta un elemento en la pila.
   * Inserta una instancia de *Par*, que contiene este elemento y el máximo
   * de este elemento y el máximo asociado al anterior.
   * @param elem 
   */
    void insertar(int elem);
  /** 
   * @brief Borra el último elemento de la pila.
   * 
   */
    void borrar();
};

/**
 * @brief Especialización de *PilaMax* para usar el TDA *Cola* en
 * la implementación.
 * 
 */

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
