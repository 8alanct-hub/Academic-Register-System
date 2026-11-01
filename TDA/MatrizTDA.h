#ifndef MATRIZ_TDA_H
#define MATRIZ_TDA_H

#include <stdexcept>

template <typename T>
struct MatrizTDA {
    T** datos;
    int columnas;
    int filas;
    int capacidadFilas;
};

template <typename T>
void crearMatriz(MatrizTDA<T>& matriz, int columnas, int capacidadInicialFilas = 4) {
    matriz.columnas = columnas;
    matriz.filas = 0;
    matriz.capacidadFilas = capacidadInicialFilas;
    matriz.datos = new T*[matriz.capacidadFilas];
}

template <typename T>
void destruirMatriz(MatrizTDA<T>& matriz) {
    for (int i = 0; i < matriz.filas; i++) {
        delete[] matriz.datos[i];
    }
    delete[] matriz.datos;
    matriz.datos = nullptr;
    matriz.filas = 0;
    matriz.capacidadFilas = 0;
}

template <typename T>
void redimensionar(MatrizTDA<T>& matriz) {
    int nuevaCapacidad = matriz.capacidadFilas * 2;
    T** nuevoArreglo = new T*[nuevaCapacidad];

    for (int i = 0; i < matriz.filas; i++) {
        nuevoArreglo[i] = matriz.datos[i];
    }

    delete[] matriz.datos;
    matriz.datos = nuevoArreglo;
    matriz.capacidadFilas = nuevaCapacidad;
}

template <typename T>
void agregarFila(MatrizTDA<T>& matriz, const T* valoresFila) {
    if (matriz.filas == matriz.capacidadFilas) {
        redimensionar(matriz);
    }

    T* nuevaFila = new T[matriz.columnas];
    for (int j = 0; j < matriz.columnas; j++) {
        nuevaFila[j] = valoresFila[j];
    }

    matriz.datos[matriz.filas] = nuevaFila;
    matriz.filas++;
}

template <typename T>
void eliminarFila(MatrizTDA<T>& matriz, int indiceFila) {
    if (indiceFila < 0 || indiceFila >= matriz.filas) {
        throw std::out_of_range("Indice de fila fuera de rango en eliminarFila()");
    }

    delete[] matriz.datos[indiceFila];

    for (int i = indiceFila; i < matriz.filas - 1; i++) {
        matriz.datos[i] = matriz.datos[i + 1];
    }
    matriz.filas--;
}

template <typename T>
T consultar(const MatrizTDA<T>& matriz, int fila, int columna) {
    if (fila < 0 || fila >= matriz.filas || columna < 0 || columna >= matriz.columnas) {
        throw std::out_of_range("Indice fuera de rango en consultar()");
    }
    return matriz.datos[fila][columna];
}

template <typename T>
void modificar(MatrizTDA<T>& matriz, int fila, int columna, const T& valor) {
    if (fila < 0 || fila >= matriz.filas || columna < 0 || columna >= matriz.columnas) {
        throw std::out_of_range("Indice fuera de rango en modificar()");
    }
    matriz.datos[fila][columna] = valor;
}

template <typename T>
int filas(const MatrizTDA<T>& matriz) {
    return matriz.filas;
}

template <typename T>
int columnas(const MatrizTDA<T>& matriz) {
    return matriz.columnas;
}

template <typename T>
int capacidadActual(const MatrizTDA<T>& matriz) {
    return matriz.capacidadFilas;
}

template <typename T>
bool estaVacia(const MatrizTDA<T>& matriz) {
    return matriz.filas == 0;
}

#endif
