#include "funciones.hpp"
#include "funcionesArbolesBinarios.h"
#include "funcionesABB.h"
#include "Pila.h"
#include "funcionesPila.h" 

NodoArbol *obtenerRaiz(ArbolBinarioBusqueda ABB) {
    return ABB.arbolBinario.raiz;
}

void dibujar(NodoArbol *raiz, int espacios) {
    if (raiz == nullptr) return;
    espacios += INCREMENTO;
    dibujar(raiz->derecha, espacios);
    cout << endl;
    for (int i = espacios; i != 0; i--)
        cout << " ";
    cout << raiz->elemento;
    dibujar(raiz->izquierda, espacios);

}

int alturaABB(NodoArbol *raiz) {
    int izq, der;
    if (raiz == nullptr) return 1;

    izq = alturaABB(raiz->izquierda);
    der = alturaABB(raiz->izquierda);
    return maximoInt(izq, der) + 1;

}

int maximoInt(int a, int b) {
    return a >= b ? a : b;
}

void balanceoDerecha(ArbolBinarioBusqueda &ABB) {
    NodoArbol *aux;
    aux = obtenerRaiz(ABB);
    ABB.arbolBinario.raiz = aux->izquierda;
    aux->izquierda = nullptr;
    NodoArbol *raiz;
    raiz = obtenerRaiz(ABB);
    while (raiz->derecha != nullptr)
        raiz = raiz->derecha;
    raiz->derecha = aux;
}

void balanceoIzquierda(ArbolBinarioBusqueda &ABB) {
    NodoArbol *aux;
    aux = obtenerRaiz(ABB);
    ABB.arbolBinario.raiz = aux->derecha;
    aux->derecha = nullptr;
    NodoArbol *raiz;
    raiz = obtenerRaiz(ABB);
    while (raiz->izquierda != nullptr)
        raiz = raiz->izquierda;
    raiz->izquierda = aux;

}

void balanceo(ArbolBinarioBusqueda &ABB) {
    int izq = alturaRecursivo(ABB.arbolBinario.raiz->izquierda);
    int der = alturaRecursivo(ABB.arbolBinario.raiz->derecha);
    if (absoluto(der - izq) <= 1) {
        cout << "Balanceado" << endl;
        return;
    }
    if (izq > der) balanceoDerecha(ABB);
    else
        if (der > izq) balanceoIzquierda(ABB);
    balanceo(ABB);
}

int absoluto(int i) {
    if (i > 0)
        return i;
    if (i < 0)
        return i*-1;
    if (i == 0)
        return 0;
}

void pasarArregloOrden(NodoArbol *raiz, int *arr, int &n) {
    if (raiz == nullptr)
        return;
    pasarArregloOrden(raiz->izquierda, arr, n);
    arr[n] = raiz->elemento;
    n++;
    pasarArregloOrden(raiz->derecha, arr, n);


}

void balanceoArr(ArbolBinarioBusqueda &ABB, int *arr, int ini, int fin) {
    int med = (ini + fin) / 2;
    if (ini >= fin) return;
    insertar(ABB, arr[med]);
    balanceoArr(ABB, arr, 0, med);
    balanceoArr(ABB, arr, med + 1, fin);
}

void balanceoArreglo(ArbolBinarioBusqueda &ABB) {
    int arr[25]{};
    int n = 0;
    pasarArregloOrden(ABB.arbolBinario.raiz, arr, n);
    destruirArbolBB(ABB);
    balanceoArr(ABB, arr, 0, n);

}

void postOrdenR(ArbolBinarioBusqueda ABB) {
    Pila pila, pila2;
    NodoArbol *raiz, *aux;
    raiz = obtenerRaiz(ABB);
    construir(pila);
    construir(pila2);
    apilar(pila, raiz);
    while (!esPilaVacia(pila)) {
        aux = desapilar(pila);
        apilar(pila2, aux);
        raiz = aux;
        if (raiz->izquierda != nullptr)
            apilar(pila, raiz->izquierda);
        if (raiz->derecha != nullptr)
            apilar(pila, raiz->derecha);
    }
    imprimir(pila2);

}

void enOrdenR(ArbolBinarioBusqueda ABB) {
    Pila pila;
    construir(pila);
    NodoArbol *raiz, *aux;
    raiz = obtenerRaiz(ABB);
    while (!esPilaVacia(pila) or raiz != nullptr) {
        while (raiz != nullptr) {
            apilar(pila, raiz);
            raiz = raiz->izquierda;
        }
        raiz = desapilar(pila);
        cout << raiz->elemento << " ";
        raiz = raiz->derecha;
    }
}

void enPreOrden(NodoArbol *raiz) {
    Pila pila;
    construir(pila);
    apilar(pila, raiz->derecha);
    while (!esPilaVacia(pila)) {

        while (raiz != nullptr) {
            cout << raiz->elemento << " | ";
            if (raiz->derecha != nullptr) {
                apilar(pila, raiz->derecha);
            }
            raiz = raiz->izquierda;
        }
        raiz = desapilar(pila);
    }
}