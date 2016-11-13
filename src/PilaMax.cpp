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

// --- Métodos de la especialización.

// template<> typename PilaMax<Cola>::Par PilaMax<Cola>::tope()
// {
//     for(int i=0; i<cola.tamanio()-1; i++)
//     {
//         cola.poner(cola.frente());
//         cola.quitar();
//     }

//     Par ret = cola.frente();
//     cola.poner(aux);
//     cola.quitar();

//     return ret;
// }

// template<> bool PilaMax<Cola>::vacia() const
// {
//     return cola.vacia();
// }

// template<> void PilaMax<Cola>::insertar(int elem)
// {
//     cola.poner(elem);
// }

// template<> void PilaMax<Cola>::borrar()
// {
//     for(int i=0; i<cola.tamanio()-1; i++)
//     {
//         cola.poner(cola.frente());
//         cola.quitar();
//     }

//     cola.quitar();
// }
