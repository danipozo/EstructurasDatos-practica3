/**
 * @file   VD.h
 * @author Daniel Pozo Escalona
 * 
 * @brief  Fichero de cabecera del TDA *VD* (vector dinámico).
 * 
 * 
 */


#ifndef VD_H
#define VD_H

/**
 * @brief TDA *VD*.
 * 
 * Una instancia del TDA *VD* sobre un dominio T representa
 * un vector de elementos de tipo T, que crece y decrece de acuerdo
 * con el número de elementos que contiene.
 * 
 */

template <class T>
class VD
{
    T* vector;			/**< El vector propiamente dicho. */
    int longitud_;		/**< La capacidad máxima del vector. */
    int usados;			/**< El espacio usado en el vector. */

  public:

    // --- Constructores/destructor
    VD() : vector(0), longitud_(0), usados(0) { } /**< Constructor por defecto. */
  /** 
   * Construye un vector con la longitud especificada.
   * 
   * @param longitud 
   */
    VD(int longitud) : vector(0), longitud_(longitud), usados(0) { redimensionar(longitud); }
    ~VD() { delete[] vector; }	/**< Destructor. */

    // --- Métodos que no modifican el estado.
    int longitud() const { return usados; }  ///< Devuelve el número de elementos del vector.
    int capacidad() const { return longitud_; } /**< Devuelve la capacidad del vector. */
  /** 
   * 
   * 
   * @param pos 
   * 
   * @return El elemento en la posición *pos* del vector.
   */
    T obtener_elemento(int pos) const;
  /** 
   * @return *true* si el vector está vacío, *false* en otro caso.
   */
    bool vacia() const;

    // --- Métodos que modifican el estado.
  /** 
   * Inserta *elem* en la posición *pos* del vector.
   * 
   * @param elem 
   * @param pos 
   */
    void insertar(const T& elem, int pos);
  /** 
   * Borra el elemento en la posición *pos* del vector.
   * 
   * @param pos 
   */
    void borrar(int pos);
  /** 
   * Redimensiona el vector, eliminando los últimos elementos si *longitud*
   * es menor que la longitud del vector.
   * 
   * @param longitud 
   */
    void redimensionar(int longitud);
};

#include "VD.cpp"

#endif // VD_H
