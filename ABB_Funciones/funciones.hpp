/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funciones.hpp
 * Author: VLADYMIR
 *
 * Created on 31 de mayo de 2024, 19:02
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP
#define INCREMENTO 5
#include <iostream>
using namespace std;
#include "ArbolBinarioBusqueda.h"
NodoArbol *obtenerRaiz(ArbolBinarioBusqueda);
void dibujar(NodoArbol *,int espacios);
int alturaABB(NodoArbol *);
int maximoInt(int a, int b);
void balanceo(ArbolBinarioBusqueda &ABB);
int absoluto(int);
void balanceoArreglo(ArbolBinarioBusqueda &ABB);
void postOrdenR(ArbolBinarioBusqueda);
void enOrdenR(ArbolBinarioBusqueda);
void enPreOrden(NodoArbol *raiz);
#endif /* FUNCIONES_HPP */

