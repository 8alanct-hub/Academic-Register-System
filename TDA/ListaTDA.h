#ifndef LISTA_TDA_H
#define LISTA_TDA_H

#include <stdexcept>

template <typename T>
struct ListaTDA {
    T* datos;
    int capacidad;
    int cantidad;
};

template <typename T>
void crearLista(ListaTDA<T>& lista, int capacidadInicial = 4) {
    lista.capacidad = capacidadInicial;
    lista.cantidad = 0;
    lista.datos = new T[lista.capacidad];
}

template <typename T>
void destruirLista(ListaTDA<T>& lista) {
    delete[] lista.datos;
    lista.datos = nullptr;
    lista.capacidad = 0;
    lista.cantidad = 0;
}

template <typename T>
void redimensionar(ListaTDA<T>& lista) {
    int nuevaCapacidad = lista.capacidad * 2;
    T* nuevoArreglo = new T[nuevaCapacidad];

    for (int i = 0; i < lista.cantidad; i++) {
        nuevoArreglo[i] = lista.datos[i];
    }

    delete[] lista.datos;
    lista.datos = nuevoArreglo;
    lista.capacidad = nuevaCapacidad;
}

template <typename T>
void agregar(ListaTDA<T>& lista, const T& dato) {
    if (lista.cantidad == lista.capacidad) {
        redimensionar(lista);
    }
    lista.datos[lista.cantidad] = dato;
    lista.cantidad++;
}

template <typename T>
void eliminar(ListaTDA<T>& lista, int indice) {
    if (indice < 0 || indice >= lista.cantidad) {
        throw std::out_of_range("Indice fuera de rango en eliminar()");
    }

    for (int i = indice; i < lista.cantidad - 1; i++) {
        lista.datos[i] = lista.datos[i + 1];
    }
    lista.cantidad--;
}

template <typename T>
T consultar(const ListaTDA<T>& lista, int indice) {
    if (indice < 0 || indice >= lista.cantidad) {
        throw std::out_of_range("Indice fuera de rango en consultar()");
    }
    return lista.datos[indice];
}

template <typename T>
int tamano(const ListaTDA<T>& lista) {
    return lista.cantidad;
}

template <typename T>
int capacidadActual(const ListaTDA<T>& lista) {
    return lista.capacidad;
}

template <typename T>
bool estaVacia(const ListaTDA<T>& lista) {
    return lista.cantidad == 0;
}

#endif
