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

template <class T> Lista<T>::~Lista()
{
    Celda* it = cabecera->siguiente;

    while(it != cabecera)
    {
        Celda* aux = it->siguiente;;
        delete it;
        it = aux;
    }

    delete cabecera;
}

template <class T> typename Lista<T>::Iterador Lista<T>::inicio() const
{
    return Iterador(&(cabecera->siguiente));
}

template <class T> typename Lista<T>::Iterador Lista<T>::final()
{
    Celda** p = &cabecera;
    return Iterador(p);
}

template <class T> T Lista<T>::obtener_elemento(int pos) const
{
    Iterador it = inicio();

    for(int i=0; i<pos; i++)
        it++;

    return *it;
}

template <class T> bool Lista<T>::vacia() const
{
    return cabecera->siguiente == cabecera;
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

template <class T> void Lista<T>::insertar(const T& elem, const Iterador& pos)
{
    Celda* it = *pos.puntero;
    Celda* nueva = new Celda;
    nueva->elemento = elem;

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

template <class T> void Lista<T>::borrar(const Iterador& pos)
{
    Celda* it = *pos.puntero;

    it->anterior->siguiente = it->siguiente;
    it->siguiente->anterior = it->anterior;

    delete it;
}
