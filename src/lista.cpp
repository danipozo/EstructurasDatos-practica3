// --- Métodos de Celda

template <class T> bool Lista<T>::Celda::operator==(const Celda& otra)
{
  return siguiente == otra.siguiente;
}

template <class T> bool Lista<T>::Celda::operator!=(const Celda& otra)
{
  return !(*this == otra);
}

template <class T> typename Lista<T>::Celda& Lista<T>::Celda::operator++(int)
{
  *this = *(this->siguiente);

    return *this;
}

template <class T> typename Lista<T>::Celda& Lista<T>::Celda::operator--(int)
{
  *this = *(this->anterior);

    return *this;
}

template <class T> T& Lista<T>::Celda::operator*()
{
    return elemento;
}

// --- Métodos de Lista

template <class T> Lista<T>::Lista()
{
  cabecera = new Celda();
  cabecera->anterior = cabecera;
  cabecera->siguiente = cabecera;
}

template <class T> typename Lista<T>::Celda& Lista<T>::inicio() const
{
    Celda& ret = (*cabecera)++;
    std::cout << "Inicio: " << ret.siguiente << std::endl;
    (*cabecera)--;

    return ret;
}

template <class T> const typename Lista<T>::Celda& Lista<T>::inicio_const() const
{
    Celda& ret = (*cabecera)++;
    (*cabecera)--;

    return ret;
}

template <class T> typename Lista<T>::Celda& Lista<T>::final() const
{
  std::cout << "Final: " << cabecera << std::endl;
  return *cabecera;
}

template <class T> const typename Lista<T>::Celda& Lista<T>::final_const() const
{
  return *cabecera;
}

template <class T> void Lista<T>::insertar(const T &elem, int pos)
{
    Celda& it = inicio();
    Celda *nueva = new Celda(elem, nullptr, nullptr);

    for(int i = 0; i<pos; i++)
        it++;

    std::cout << "Posición: " << &it << std::endl;

    Celda* aux = it.anterior->siguiente;
    Celda* aux2 = it.anterior;
    
    it.anterior->siguiente = nueva;
    it.anterior = nueva;

    nueva->siguiente = aux;
    nueva->anterior = aux2;
    
    for(Celda& i = inicio(); i!=final(); i++)
    {
      std::cout << *i << ' ';
    }
    std::cout << std::endl;
}
