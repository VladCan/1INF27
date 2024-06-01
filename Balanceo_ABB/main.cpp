/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: VLADYMIR
 * 
 * Created on 30 de mayo de 2024, 11:18
 */
#include "Utils.hpp"
#include "ArbolBinarioBusqueda.h"
#include "funcionesArbolesBinarios.h"
#include "funcionesArbolesBB.h"
#include "Cola.h"
#include "funcionesCola.h"
#include "Pila.h"
#include "funcionesPila.h"
#include <cmath>
using namespace std;

void dibujarArbol(NodoArbol* raiz, int espacio, int incremento) {
    if (raiz == nullptr) return;

    espacio += incremento;

    dibujarArbol(raiz->derecha, espacio, incremento);

    cout << endl;
    for (int i = incremento; i < espacio; i++) cout << " ";
    cout << raiz->elemento << endl;

    dibujarArbol(raiz->izquierda, espacio, incremento);
}

void recorrerEnOrdenRecursivo2(struct NodoArbol * nodo, int *arr2, int &n) {
    if (not esNodoVacio(nodo)) {
        recorrerEnOrdenRecursivo2(nodo->izquierda, arr2, n);
        arr2[n] = nodo->elemento;
        n++;
        recorrerEnOrdenRecursivo2(nodo->derecha, arr2, n);
    }
}

void almacenaOrdenado(ArbolBinarioBusqueda ABB, int *arr2) {
    int n = 0;
    recorrerEnOrdenRecursivo2(ABB.arbolBinario.raiz, arr2, n);

}

void insertaBalanceado(ArbolBinarioBusqueda &ABB, int *arr2, int ini, int med, int fin) {
    med = (ini + fin) / 2;
    if (ini >= fin) return;
    insertar(ABB, arr2[med]);
    //imprimeNodo(ABB.arbolBinario.raiz);
    insertaBalanceado(ABB, arr2, ini, 0, med);
    insertaBalanceado(ABB, arr2, med + 1, 0, fin);
}

void balanceo(ArbolBinarioBusqueda &ABB) {
    int arr2[20]{};
    almacenaOrdenado(ABB, arr2);
    destruirArbolBB(ABB);
    int n = 0;
    while (arr2[n] != 0) n++;
    insertaBalanceado(ABB, arr2, 0, 0, n);
}

void siguienteNivel(NodoArbol *nodo, Cola &cola) {

}

void porNivel(NodoArbol *nodo) {
    NodoArbol *vacio;
    vacio = new NodoArbol{};
    vacio->elemento = 0;
    if (esNodoVacio(nodo)) {
        cout << "El arbol esta vacio" << endl;
        return;
    }
    int i = 0;
    int nivel = 0;
    int j = 0;
    Cola cola;
    construir(cola);
    encolar(cola, nodo);
    //encolar(cola, nullptr);
    while (!esColaVacia(cola) /*and cola.lista.longitud != 1*/) {
        NodoArbol *nodo2;
        nodo2 = desencolar(cola);
        //        if (nodo2 == nullptr) {
        //            cout << endl;
        //            encolar(cola, nodo2);
        //        } else {
        cout << nodo2->elemento << "  ";
        if (i == nivel) {
            cout << endl;
            j++;
            i = 0;
        }
        if (nodo2->izquierda != nullptr)
            encolar(cola, nodo2->izquierda);
        if (nodo2->derecha != nullptr)
            encolar(cola, nodo2->derecha);
        nivel = pow(2, j);
        i++;
        //}
    }
    cout << endl;
}

void Nivel(ArbolBinarioBusqueda ABB) {
    porNivel(ABB.arbolBinario.raiz);
}

NodoArbol *obtenerRaiz(ArbolBinarioBusqueda ABB) {
    return ABB.arbolBinario.raiz;
}

int main(int argc, char** argv) {
    ArbolBinarioBusqueda ABB;
    construir(ABB);
    int arr[20] = {3, 1, 5, 2, 4, 8, 13, 18, 0};
    for (int i = 0; arr[i] != 0; i++)
        insertar(ABB, arr[i]);

    enOrden(ABB);
    cout << endl;
    preOrden(ABB);
    cout << endl;
    postOrden(ABB);
    dibujarArbol(ABB.arbolBinario.raiz, 0, 5);
    Nivel(ABB);
    balanceo(ABB);
    cout << "=========================================================================" << endl;
    dibujarArbol(ABB.arbolBinario.raiz, 0, 5);
    Nivel(ABB);
    postOrden(ABB);
    cout<<endl;
        Pila pila;
        Pila pila2;
        construir(pila);
        construir(pila2);
        NodoArbol * raiz=obtenerRaiz(ABB);
        apilar(pila,raiz);
        NodoArbol *nodo3;
        while(!esPilaVacia(pila)){
            nodo3=desapilar(pila);
            apilar(pila2,nodo3);
            raiz=nodo3;
            if(raiz->izquierda!=nullptr)
                apilar(pila,raiz->izquierda);
            if(raiz->derecha!=nullptr)
                apilar(pila,raiz->derecha);
        }
        cout<<endl;
        imprimir(pila2);
    return 0;
}



