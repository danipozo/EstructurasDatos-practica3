#ifndef VD_H
#define VD_H

template <class T>
class VD
{
    T* vector;
    int longitud_;
    int usados;

  public:

    // --- Constructores/destructor
    VD() : vector(0), longitud_(0), usados(0) { }
    VD(int longitud) : vector(0), longitud_(longitud), usados(0) { redimensionar(longitud); }
    ~VD() { delete[] vector; }

    // --- Métodos que no modifican el estado.
    int longitud() const { return usados; }  // Para el usuario la longitud es el espacio usado.
    int capacidad() const { return longitud_; }
    T obtener_elemento(int pos) const;
    bool vacia() const;

    // --- Métodos que modifican el estado.
    void insertar(const T& elem, int pos);
    void borrar(int pos);
    void redimensionar(int longitud);
};

#include "VD.cpp"

#endif // VD_H
