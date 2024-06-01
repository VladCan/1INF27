/* 
 * File:   funcionesLista.h
 * Author: ANA RONCAL
 * Created on 26 de septiembre de 2023, 04:52 PM
 */

#ifndef FUNCIONESLISTA_H
#define FUNCIONESLISTA_H

#include "NodoArbol.h"


void construir(struct Lista &);

void insertarAlInicioArchivo(const char *, struct Lista &);

void insertarAlInicio(struct Lista &, NodoArbol *elemento);
void insertarAlFinal(struct Lista &, NodoArbol *elemento);
void insertarEnOrden(struct Lista &, NodoArbol *elemento);

struct NodoCola * crearNodo(NodoArbol *elemento, struct NodoCola *);
struct NodoCola * obtenerUltimoNodo(const struct Lista &);
struct NodoCola * obtenerNodoAnterior(const struct Lista &, NodoArbol*);
struct NodoCola * seEncuentra(const struct Lista &, NodoArbol *);
NodoArbol *retornaCabeza(const struct Lista &);
void insertarencola(struct Lista & tad, NodoArbol *elemento);
const bool esListaVacia(const struct Lista &);
int longitud(const struct Lista &);

void eliminaNodo(struct Lista &, NodoArbol *elemento);
void eliminaCabeza(struct Lista &);
void eliminaCola(struct Lista);

void destruir(struct Lista &);
void imprime(const struct Lista &);

#endif /* FUNCIONESLISTA_H */

