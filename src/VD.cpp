template <class T> T VD<T>::obtener_elemento(int pos) const
{
    return vector[pos];
}

template <class T> bool VD<T>::vacia() const
{
    return usados == 0;
}

template <class T> void VD<T>::insertar(const T& elem, int pos)
{
    if(usados == longitud_)
        redimensionar(longitud_ == 0 ? 1 : longitud_*2);

    for(int i=(usados); i>=pos; i--)
    {
        vector[i+1] = vector[i];
    }

    vector[pos] = elem;

    usados++;
}

template <class T> void VD<T>::borrar(int pos)
{
    for(int i=pos; i<usados; i++)
    {
        vector[i] = vector[i+1];
    }

    usados--;

    if(usados < longitud_/2)
        redimensionar(longitud_/2);
}

template <class T> void VD<T>::redimensionar(int longitud)
{
    T* v = new T[longitud];

    int pos_a_copiar = longitud;
    if(pos_a_copiar > usados)
        pos_a_copiar = usados;

    for(int i=0; i<pos_a_copiar; i++)
    {
        v[i] = vector[i];
    }

    delete[] vector;

    vector = v;
    longitud_ = longitud;
}
