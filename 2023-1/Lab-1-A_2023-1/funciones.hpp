/* 
 * File:   funciones.hpp
 * Author: VLADYMIR
 *
 * Created on 30 de marzo de 2024, 19:48
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP
#include <iostream>
#include <cmath>
#define M 4
#define N 5

void mejorSolucion(int camiones[M],int paquetes[N]);
void cargaBase(int *arr,int num,int base);
int calcularDiferencia(int *arr,int camiones[M],int paquetes[N],int *optimo);
void escribirSolucion(int *arr);
#endif /* FUNCIONES_HPP */

