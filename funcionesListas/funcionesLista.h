/* 
 * File:   funcionesLista.h
 * Author: ANA RONCAL
 * Created on 26 de septiembre de 2023, 04:52 PM
 */

#ifndef FUNCIONESLISTA_H
#define FUNCIONESLISTA_H

#include <iostream>
#include <iomanip> 
#include <fstream>

#include "Lista.h"
#include "Nodo.h"

void construir(struct Lista &);

void insertarAlInicioArchivo(const char *, struct Lista &);

void insertarAlInicio(struct Lista &, int);
void insertarAlFinal(struct Lista &, int);
void insertarEnOrden(struct Lista &, int);

struct Nodo * crearNodo(int elemento, struct Nodo *);
struct Nodo * obtenerUltimoNodo(const struct Lista &);
struct Nodo * obtenerNodoAnteriorUltimo(const struct  Lista &);
struct Nodo * obtenerNodoAnterior(const struct Lista &, int);
struct Nodo * seEncuentra(const struct Lista &, int);

const bool esListaVacia(const struct Lista &);
int longitud(const struct Lista &);

void eliminaNodo(struct Lista &, int);
void eliminaCabeza(struct Lista &);
void eliminaCola(struct Lista);

void destruir(struct Lista &);
void imprime(const struct Lista & tad);

void invertirLista(struct Lista & tad,int longitud);

#endif /* FUNCIONESLISTA_H */

