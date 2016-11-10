// --- Métodos de Iterador

template <class T> bool Lista<T>::Iterador::operator==(const Iterador& otro) const
{
    return *puntero == *otro.puntero;
}

template <class T> bool Lista<T>::Iterador::operator!=(const Iterador& otro) const
{
    return !(*this == otro);
}

template <class T> typename Lista<T>::Iterador& Lista<T>::Iterador::operator++(int)
{
    puntero = &((*puntero)->siguiente);

    return *this;
}

template <class T> typename Lista<T>::Iterador& Lista<T>::Iterador::operator--(int)
{
  puntero = &((*puntero)->anterior);

    return *this;
}

template <class T> T& Lista<T>::Iterador::operator*()
{
  return (*puntero)->elemento;
}

// --- Métodos de Lista

template <class T> Lista<T>::Lista()
{
    cabecera = new Celda();
    cabecera->anterior = cabecera;
    cabecera->siguiente = cabecera;
}

template <class T> typename Lista<T>::Iterador Lista<T>::inicio()
{
    return Iterador(&(cabecera->siguiente));
}

template <class T> typename Lista<T>::Iterador Lista<T>::final()
{
    Celda** p = &cabecera;
    return Iterador(p);
}

template <class T> void Lista<T>::insertar(const T &elem, int pos)
{
  Celda* it = cabecera->siguiente;
  Celda* nueva = new Celda;
  nueva->elemento = elem;

    for(int i=0; i<pos; i++)
    {
      it = it->siguiente;
    }

    nueva->siguiente = it;
    nueva->anterior = it->anterior;
    
    it->anterior->siguiente = nueva;
    it->anterior = nueva;

    
}

template <class T> void Lista<T>::borrar(int pos)
{
  Celda* it = cabecera->siguiente;

  for(int i=0; i<pos; i++)
    {
      it = it->siguiente;
    }

  it->anterior->siguiente = it->siguiente;
  it->siguiente->anterior = it->anterior;

  delete it;
}
