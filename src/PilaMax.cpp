template <template  <typename> class T> typename PilaMax<T>::Par PilaMax<T>::tope() const
{
    return contenedor.obtener_elemento(0);
}

template <template  <typename> class T> bool PilaMax<T>::vacia() const
{
    return contenedor.vacia();
}

template <template  <typename> class T> void PilaMax<T>::insertar(int elem)
{
  int max = std::numeric_limits<int>::min();

    if(!vacia())
      max = tope().maximo;
    
    Par par = {elem, max > elem ? max : elem};
    contenedor.insertar(par, 0);
}

template <template  <typename> class T> void PilaMax<T>::borrar()
{
    contenedor.borrar(0);
}
